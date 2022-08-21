/* COMP 15 project 1 Metro Simulator
*
*  Passenger.cpp
*  Jesus G. Naranjo
*  06.26.2022
*
*  Purpose: implimentation of the passenger class, funciton allow the user to
*           to prin the passengers and their information
*
*/
#include <iostream>
#include <string>
#include "Passenger.h"

/*
 * Remember to write a complete function contract here!
 */
void Passenger::print(std::ostream &output)
{
        output << "[" << id << ", " << from << "->" << to << "]";
}
