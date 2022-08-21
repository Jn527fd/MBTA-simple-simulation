/*
*  COMP 15 project 1 Metro Simulator
*
*  main.cpp
*  Jesus G. Naranjo
*  02.17.2022
*
*  Purpose: Driver file for MetroSim, PassengerQueue, and Passenger classes.
*           Contains main() function, reads in files, and executes the metro
*           simulation.
*
*/

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"
#include "PassengerQueue.h"
#include "Passenger.h"

using namespace std;

int main(int argc, char *argv[])
{
    string command;
    string directionType;

    if (argc < 3 or argc > 4) {
        cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]\n";
        return(1);

    }

    if (argc == 3){
        command = "none";

    } else {
        command = argv[3];
    }

    MetroSim instance(argv[2]);

 
    instance.readStations(argv[1]);
    instance.initialize_train();

    if (argc == 4) {
        instance.readInstructions(command);

    } else {
        instance.userMove();
    }
}
