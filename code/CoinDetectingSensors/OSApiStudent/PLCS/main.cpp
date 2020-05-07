#include <osapi/Thread.hpp>
#include <time.h>
#include <stdlib.h>
#include "Car.hpp"
#include "EntryGuard.hpp"
#include "ExitGuard.hpp"
#include <iostream>

int main()
{
    srand(time(NULL));
    EntryGuard eg;
    ExitGuard ex;
    int antalCars;

    std::cout << "Indtast antal biler: "; 
    std::cin >> antalCars;
    Car *cars[antalCars];
    osapi::Thread *threads[antalCars];

    for(int i = 0; i < antalCars; i++)
    {
        cars[i] = new Car(i, &eg, &ex);
        threads[i] = new osapi::Thread(cars[i]);
    }

    osapi::Thread g1(&eg);
    osapi::Thread g2(&ex);

    g1.start();
    g2.start();

    for(int i = 0; i < antalCars; i++)
    {
        threads[i]->start();
    }

    for(int i = 0; i < antalCars; i++)
    {
        threads[i]->join();
    }

    g1.join();
    g2.join();

    delete[] cars;
    delete[] threads;
}