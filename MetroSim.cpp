``/*
*  COMP 15 project #1 Metro Simulator
*
*  MetroSim.cpp
*
*  Implementation of MetroSim class, functions allowing the user
*  to create, print, add passengers, execute instructions, and interact with
*  the metro simulation.
*
*  Jesus Naranjo
*  07.06.2022
*/
#include "MetroSim.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/* Default Constructor
*    Purpose: initialize MetroSim class and opens output file
*    Parameters: string stations   - file with station names
*                string outputs    - file to print output to
*                string directions - file with directions to control the
*                                    simulation
*                int args          - number of arguments the user provides
*    Returns: None
*/
MetroSim::MetroSim(string stations, string outputs, string directions, int args)
{
    outputFile = outputs;
    stationsFile = stations;
    directionsFile = directions;
    numArgs = args;
    outputObject.open(outputFile);
    
    if(outputObject.fail()) {
        cerr << "Error: could not open file " << outputFile << endl;
        exit(EXIT_FAILURE);
    }
}

/* Destructor
*    Purpose: recycles memory in MetroSim class and closes output file
*    Parameters: None
*    Returns: None
*/
MetroSim::~MetroSim()
{
    outputObject.close();
}

/* initialize_stations
*    Purpose: creates a station and push into vector allStations
*    Parameters: string newStationName - name of new station
*    Returns: None
*/
void MetroSim::initialize_stations(string newStationName)
{
    station newStation;
    newStation.location = newStationName;
    newStation.stopNum = numOfStats;
    vector<Passenger> newP;
    newStation.atStation = newP;

    if (allStations.size() == 0) {
        newStation.train_present = true;
    } else {
        newStation.train_present = false;
    }

    allStations.push_back(newStation);
    numOfStats++;
}

/* initialize_train
*    Purpose: builds the size of PassengerQueue vector
*    Parameters: None
*    Returns: None
*/
void MetroSim::initialize_train()
{
    theTrain.onBoard.resize(allStations.size());
}

/* readInStations
*    Purpose: set station names according to file
*    Parameters: None
*    Returns: None
*/
void MetroSim::readStations()
{
    ifstream in;
    in.open(stationsFile);

    if (not in.is_open()) {
      cerr << "Error: could not open file " << stationsFile << endl;
      exit(EXIT_FAILURE);
    }

    string newStationName;

    for (int i = 0; getline(in, newStationName); i++ ) {
        initialize_stations(newStationName);
    }

    in.close();
}

/* readInstructions
*    Purpose: read the given by a file and exits if no commands
*    Parameters: None
*    Returns: None
*/
void MetroSim::readInstructions()
{
    ifstream infile;
    infile.open(directionsFile);
    
    
    string command;
    
    printTrain(cout);
    printMap(cout);
    cout << "Command? "; 
    
    while(getline(infile, command, '\n')){
        
        distinguish_file_commands(command);
    }
    
    if (infile.fail()) {
        cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
        exit(EXIT_SUCCESS);
    }
    
    infile.close();
    
}

/* distinguish_file_commands
*    Purpose: execute commands for file commands
*    Parameters: string command
*    Returns: None
*/
void MetroSim::distinguish_file_commands(string command){
        if (command[0] == 'p') {
            stringstream split(command);
            string letter;
            split >> letter;
            split >> letter;
             
            int from = stoi(letter);
            
            split >> letter;
            int to = stoi(letter);
            
            addPassenger(from, to);
            printTrain(cout);
            printMap(cout);
              
        } else if (command == "m m") {
                metroMove();
                printTrain(cout);
                printMap(cout);
                
        } else if (command == "m f"){ 
            cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
                exit(EXIT_SUCCESS);
        }
        cout << "Command? "; 
}
    
/* distinguish_commands
*    Purpose: execute commands for user inputs 
*    Parameters: ifstream
*    Returns: None
*/
void MetroSim::distinguish_user_commands(istream &input){
    string letter;
    while(input >> letter) { 
        if (letter == "p") { 
            int from;
            int to;
            input >> from;
            input >> to;
            
            addPassenger(from, to);
            
        } else if (letter == "m") {
            input >> letter;
            if (letter == "m"){ 
                metroMove();
                
        } else if (letter == "f"){ 
            cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
                exit(EXIT_SUCCESS);
        }
    }
        
        printTrain(cout);
        printMap(cout);
         // Update the simulation
        cout << "Command? ";    
    }
    cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
    exit(EXIT_SUCCESS);
}

/* userMove
*    Purpose: completes the commands by the user
*    Parameters: None
*    Returns: None
*/
void MetroSim::userMove()
{
    printTrain(cout);
    printMap(cout);
    cout << "Command? ";
    
    distinguish_user_commands(cin);
}


/* nextStationInd
*    Purpose: provide the index of the next station
*    Parameters: int currentInd - index refers to current station
*    Returns: int - index of the next station
*/
int MetroSim::nextStationInd(int currentInd)
{
    int nextInd = currentInd + 1;;
    int totalStations = allStations.size();

    if (nextInd > totalStations - 1) {
        nextInd = 0;
    } 
    
    return nextInd;
}

/* printTrain
*    Purpose: print out the train and its passengers
*    Parameters: ostream &output - reference to object
*    Returns: None
*/
void MetroSim::printTrain(ostream &output)
{
    output << "Passengers on the train: {";
    int size = theTrain.onBoard.size();

    for (int i = 0; i < size; i++) {
        theTrain.onBoard.at(i).print(output);
    }

    output << "}" << endl;
}

/* printMap
*    Purpose: print out map of stations and passengers in queue
*    Parameters: ostream &output - reference to object
*    Returns: None
*/
void MetroSim::printMap(ostream &output)
{
    int stationSize = allStations.size();


    for (int i = 0; i < stationSize; i++) {

        if (allStations.at(i).train_present == true) {
            output << "TRAIN: ";

        } else {
            output << "       ";
        }

        output << "[" << allStations.at(i).stopNum
               << "] " << allStations.at(i).location
               << " {";

        int queueSize = allStations.at(i).atStation.size();

        for (int j = 0; j < queueSize; j++) {
            allStations.at(i).atStation.at(j).print(cout);
        }

        output << "}"
               << endl;
    }
}

/* addPassenger
*    Purpose: add a passenger to a station
*    Parameters: int addFrom - passenger's boarding station
*                int addTo - passenger's destination
*    Returns: None
*/
void MetroSim::addPassenger(int addFrom, int addTo)
{
    int currStop = addFrom;
    Passenger newPass(nextId, addFrom, addTo);
    allStations.at(currStop).atStation.push_back(newPass);
    nextId++;
}

/* metroMove
*    Purpose: move the metro, passengers leave station and enter train
*    Parameters: None
*    Returns: None
*/
void MetroSim::metroMove()
{
    int trainAtStation = theTrain.currStation;

    board(trainAtStation);

    //moves the train
    allStations.at(trainAtStation).train_present = false;
    theTrain.currStation = nextStationInd(trainAtStation);
    allStations.at(theTrain.currStation).train_present = true;
    trainAtStation = theTrain.currStation;

    unboard(trainAtStation);
}

/* board
*    Purpose: get Passengers from current station onto train's PassengerQueue
*    Parameters: int station - index of next stop
*    Returns: None
*/
void MetroSim::board(int station)
{
    int stationQueueSize = allStations.at(station).atStation.size();

    //go through each passenger at the station
    for (int j = 0; j < stationQueueSize; j++) {
        Passenger embarking = allStations.at(station).atStation.at(j);
        int destination = embarking.to;
        //add them to the correct passengerqueue
        theTrain.onBoard.at(destination).enqueue(embarking);
    }

    //removes passengers when boarded
    for (int i = 0; i < stationQueueSize; i++) {
        allStations.at(station).atStation.pop_back();
    }

}

/* unboard
*    Purpose: remove passengers from the station passengerqueue
*    Parameters: int station - index of the drop station
*    Returns: None
*/
void MetroSim::unboard(int station)
{
    bool Gone = false;
    while (Gone == false) {
        //number of passengers getting off the train
        int carSize = theTrain.onBoard.at(station).size();

        if (carSize > 0) {

            for (int i = 0; i < carSize; i++) {
                int id = theTrain.onBoard.at(station).front().id;
                string stationName = allStations.at(station).location;
                theTrain.onBoard.at(station).dequeue();
                printOutput(id, stationName);
            }
        }
        Gone = true;
    }
}

/* printOutput
*    Purpose: print the passengers that leave the train and at which station
*    Parameters: int id         - id number of the passenger
*                string station - name of the drop off station
*    Returns: None
*/
void MetroSim::printOutput(int id, string station)
{
    outputObject << "Passenger " << id << " left train at station "
                 << station << endl;
}