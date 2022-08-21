/*
 *  COMP 15 Proj1 Metro Simulator
 *
 *  PassengerQueue.h
 *  Jesus G Naranjo
 *  06.26.2022
 *
 *  Purpose: interface of the PassengerQueue class, functions allow the user
 *           to create, manipulate and inspect the PassengerQueue.
 *
 */
#ifndef _PASSENGERQUEUE_H_
#define _PASSENGERQUEUE_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Passenger.h"
using namespace std;

class PassengerQueue
{
public:
        Passenger front();
        void dequeue();
        void enqueue(const Passenger &passenger);
        int size();
        void print(ostream &output);

private:
        vector<Passenger> inLine;
};
#endif
