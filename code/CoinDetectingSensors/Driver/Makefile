ifeq ($(KERNELRELEASE),)

KERNELRELEASE=~/sources/rpi-4.19/
PWD:=$(shell pwd)

default:
	$(MAKE) ARCH=arm CROSS_COMPILE=arm-poky-linux-gnueabi- -C $(KERNELRELEASE) M=$(PWD) modules

	
.PHONY: clean
clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions modules.order Module.symvers
	

else

obj-m:= CDSdriver.o
ccflags-y:=-std=gnu99 -Wno-declaration-after-statement -Werror

endif
