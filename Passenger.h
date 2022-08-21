/* COMP 15 project 1 Metro Simulator
*
*  Passenger.h
*  Jesus G. Naranjo
*  06.26.2022
*
*  Purpose: interface of the passenger class, funciton allow the user to
*           to prin the passengers and their information
*
*/
#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>

struct Passenger
{
        int id, from, to;

        Passenger()
        {
                id   = -1;
                from = -1;
                to   = -1;
        }

        Passenger(int newId, int arrivalStation, int departureStation)
        {
                id   = newId;
                from = arrivalStation;
                to   = departureStation;
        }

        void print(std::ostream &output);

};
#endif
