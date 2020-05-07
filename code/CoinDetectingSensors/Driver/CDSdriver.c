#include <linux/gpio.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/module.h>

#include <linux/interrupt.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/ktime.h>
#include <linux/timekeeping.h>

#define CDS_MAJOR 43
#define CDS_MINOR 0
#define NBR_MINORS 2 // 2 sensors.

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Magnus Hauge Kyneb");
MODULE_DESCRIPTION("Driver for Coin Detecting Sensors (CDS)");

static int devno;
static int gpioNumberSensorOneRising = 22;
static int gpioNumberSensorOneFalling = 23;
static int gpioNumberSensorTwoRising = 24;
static struct cdev CDS_dev;
struct file_operations my_fops;


static DECLARE_WAIT_QUEUE_HEAD(wq);
static int flag = 0;

static irqreturn_t SensorOneRising_interrupt_handler(int irq, void *dev_id);
static irqreturn_t SensorTwoRising_interrupt_handler(int irq, void *dev_id);
static irqreturn_t SensorOneFalling_interrupt_handler(int irq, void *dev_id);

int isr_sensorOneGpio_value;
int isr_sensorTwoGpio_value;

int save_count = 0; 

struct timespec isr_timespec[3];
long saved_times[3];


//! Initial interrupt, coin meets first sensor.
static irqreturn_t SensorOneRising_interrupt_handler(int irq, void *dev_id)
{
// Save urgent information.
  ktime_get_ts(&isr_timespec[0]);
  
  return IRQ_HANDLED;
}

//! Coin meets second sensor. Used to calculate speed.
static irqreturn_t SensorTwoRising_interrupt_handler(int irq, void *dev_id)
{
  ktime_get_ts(&isr_timespec[1]);

  return IRQ_HANDLED;
}

//! Coin leaves first sensor. Used to calculate coin width.
static irqreturn_t SensorOneFalling_interrupt_handler(int irq, void *dev_id)
{
  ktime_get_ts(&isr_timespec[2]);
  
  flag = 1;
  wake_up_interruptible(&wq);
  return IRQ_HANDLED;
}


//! Open. Requests interrupt lines on specified GPIO and connects handlers and triggers.
int CDS_open(struct inode *inode, struct file *filep)
{
  int major, minor;
  major = MAJOR(inode->i_rdev);
  minor = MINOR(inode->i_rdev);
  printk("Opening device with major, minor: %i, %i\n", major, minor);

  if(request_irq(gpio_to_irq(gpioNumberSensorOneRising), SensorOneRising_interrupt_handler, IRQF_TRIGGER_RISING, "CDS_SensorOneRising", NULL) != 0)
  {
    printk(KERN_ALERT "Something went wrong when requesting IRQ for gpio %d\n", gpioNumberSensorOneRising);
    free_irq(gpio_to_irq(gpioNumberSensorOneRising), NULL);
  }
  
   if(request_irq(gpio_to_irq(gpioNumberSensorOneFalling), SensorOneFalling_interrupt_handler, IRQF_TRIGGER_FALLING, "CDS_SensorOneFalling", NULL) != 0)
  {
    printk(KERN_ALERT "Something went wrong when requesting IRQ for gpio %d\n", gpioNumberSensorOneFalling);
    free_irq(gpio_to_irq(gpioNumberSensorOneFalling), NULL);
  }
  
   if(request_irq(gpio_to_irq(gpioNumberSensorTwoRising), SensorTwoRising_interrupt_handler, IRQF_TRIGGER_RISING, "CDS_SensorTwoRising", NULL) != 0)
  {
    printk(KERN_ALERT "Something went wrong when requesting IRQ for gpio %d\n", gpioNumberSensorTwoRising);
    free_irq(gpio_to_irq(gpioNumberSensorOneRising), NULL);
  }

  return 0;
}


//! Close. Frees interrupt lines.
int CDS_release(struct inode *inode, struct file *filep)
{
    int minor, major;

    major = MAJOR(inode->i_rdev);
    minor = MINOR(inode->i_rdev);
    printk("Closing/Releasing device with major, minor: %i, %i\n", major, minor);

    free_irq(gpio_to_irq(gpioNumberSensorOneRising), NULL);
    free_irq(gpio_to_irq(gpioNumberSensorOneFalling), NULL);
	free_irq(gpio_to_irq(gpioNumberSensorTwoRising), NULL);

    return 0;
}



//! Read function. Waits for interrupt caused by coin leaving the first sensor.
//! Calculates relative time between times saved by interrupts and uses copy_to_user to get it to user-space.
//! First time is time between first interrupt and second interrupt.
//! Second time is time between first interrupt and third interrupt.
//! The two times are comma seperated.
ssize_t CDS_read(struct file *filep, char __user *buf, size_t count, loff_t *f_pos)
 {
	 wait_event_interruptible(wq, flag > 0);
   	 flag = 0;
	
	 long relativeTime_sensorTwoRising = isr_timespec[1].tv_nsec - isr_timespec[0].tv_nsec;
	 long relativeTime_sensorOneFalling = isr_timespec[2].tv_nsec - isr_timespec[0].tv_nsec;

     char message_buffer[255];
	 
	
     //! Length of the string we want to return.
     int length = sprintf(message_buffer, "%ld,%ld\n", relativeTime_sensorTwoRising, relativeTime_sensorOneFalling);

     length = length > count ? count : length;

     int err = copy_to_user(buf, message_buffer, length);
     if(err < 0)
         return -1;

     *f_pos += length;

     return length;
 }






//! File operations.
struct file_operations my_fops = {
    .open = CDS_open,
    .release = CDS_release,
    .read = CDS_read,
};



// Initialization.
static int __init CDS_driver_init(void)
{
    int err = 0;

	// Requesting GPIO's and setting direction.
    printk(KERN_ALERT "Requesting gpio number %d\n", gpioNumberSensorOneRising);
    err = gpio_request(gpioNumberSensorOneRising, "CDS_sensorOneRising");
    if (err < 0)
        goto err_exit;

    printk(KERN_ALERT "Sets direction of GPIO %d to in\n", gpioNumberSensorOneRising);
    err = gpio_direction_input(gpioNumberSensorOneRising);
    if (err < 0)
        goto err_free_buf;

    printk(KERN_ALERT "Requesting gpio number %d\n", gpioNumberSensorOneFalling);
    err = gpio_request(gpioNumberSensorOneFalling, "CDS_sensorOneFalling");
    if (err < 0)
        goto err_exit;

    printk(KERN_ALERT "Sets direction of GPIO %d to in\n", gpioNumberSensorOneFalling);
    err = gpio_direction_input(gpioNumberSensorOneFalling);
    if (err < 0)
        goto err_free_buf;
        
    printk(KERN_ALERT "Requesting gpio number %d\n", gpioNumberSensorTwoRising);
    err = gpio_request(gpioNumberSensorTwoRising, "CDS_sensorTwoRising");
    if (err < 0)
        goto err_exit;

    printk(KERN_ALERT "Sets direction of GPIO %d to in\n", gpioNumberSensorTwoRising);
    err = gpio_direction_input(gpioNumberSensorTwoRising);
    if (err < 0)
        goto err_free_buf;

	// Specifying major & minor number.
    printk(KERN_ALERT "Specifying Major and Minor numbers - 43 and 0\n");
    devno = MKDEV(CDS_MAJOR, CDS_MINOR);

	// Allocate device numbers.
    printk(KERN_ALERT "Registering major and minor numbers for 1 device\n");
    err = register_chrdev_region(devno, NBR_MINORS, "CDS driver");
    if (err < 0)
       goto err_free_buf;

	// Initialize character device.
    printk(KERN_ALERT "Initializing cdev\n");
    cdev_init(&CDS_dev, &my_fops); 
    
    printk(KERN_ALERT "Adding cdev\n");
    err = cdev_add(&CDS_dev, devno, 1);
    if (err < 0)
        goto err_dev_unregister;



    return 0;

	// Error handling.
    err_dev_unregister:
        unregister_chrdev_region(devno, NBR_MINORS);

    err_free_buf:
        gpio_free(gpioNumberSensorOneRising);
        gpio_free(gpioNumberSensorOneFalling);
        gpio_free(gpioNumberSensorTwoRising);

    err_exit:
        return err;
}


// Exit.
static void __exit CDS_driver_exit(void)
{
	// Remove driver from kernel.
	printk(KERN_ALERT "Removing driver from kernel\n");
 
	cdev_del(&CDS_dev);

	// Free device numbers.
	printk(KERN_ALERT "Unregister cdev\n");
	unregister_chrdev_region(devno, NBR_MINORS);
  
	printk(KERN_ALERT "Freeing gpio number 16\n");
	gpio_free(gpioNumberSensorOneRising);
	gpio_free(gpioNumberSensorOneFalling);
	gpio_free(gpioNumberSensorTwoRising);
}

module_init(CDS_driver_init);
module_exit(CDS_driver_exit);
