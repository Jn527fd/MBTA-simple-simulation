/*
*  COMP 15 Proj1 Metro Simulator
*
*  PassengerQueue.cpp
*  Jesus G Naranjo
*  06.23.2022
*
*  Purpose: Implementation of the PassengerQueue class. Contains definitions of
*           key functions that allow the user to create, add to, remove from,
*           print, and modify passenger queues.
*
*/
#include "PassengerQueue.h"

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

/* front
*    Purpose: returns Passenger at front of the queue
*    Parameters: None
*    Returns: Passenger = Passenger at front of queue
*/
Passenger PassengerQueue::front()
{
    return inLine.front();
}

/* dequeue
*    Purpose: remove first passenger from the front of the queue
*    Parameters: None
*    Returns: None
*/
void PassengerQueue::dequeue()
{
    if (inLine.size() == 0){
            throw runtime_error("Cannot dequeue a empty vector");
    }

    inLine.erase(inLine.begin());
}

/* enqueue
*    Purpose: push given passenger into queue
*    Parameters: const Passenger &passenger - constant reference to a passenger
*    Returns: None
*/
void PassengerQueue::enqueue(const Passenger &passenger)
{
    inLine.push_back(passenger);
}

/* size
*    Purpose: return current size of vector
*    Parameters: None
*    Returns: int = size of vector
*/
int PassengerQueue::size()
{
    return inLine.size();
}

/* print
*    Purpose: print out passenger queue
*    Parameters: ostream &output - reference to ostream object
*    Returns: None
*/
void PassengerQueue::print(ostream &output)
{
    int queueSize = inLine.size();

    for(int i = 0; i < queueSize; i++) {
         inLine.at(i).print(output);
    }
}
