/* COMP 15 project 1 Metro Simulator
*
*  MetroSim.h
*  Jesus G. Naranjo
*  06.26.2022
*
*  Purpose: interface of the MetroSim class, functions allow the user to
*           to give commands to the train simulator
*
*/
#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"
#include "PassengerQueue.h"

#include <vector>
#include <string>

using namespace std;

class MetroSim
{
public:
        MetroSim(string outputs);
        ~MetroSim();

        
        void initialize_stations(string newStationName);
        void initialize_train();
        void readStations(string stationsFile);
        void readInstructions(string directionsFile);
        void userMove();
        void printTrain(ostream &output);
        void printMap(ostream &output);
        

private:
        struct station {
            string location;
            int stopNum;
            vector<Passenger> atStation;
            bool train_present;
        };

        struct train {
            int currStation = 0;
            vector<PassengerQueue> onBoard;
        };

        vector<station> allStations;
        train theTrain;

        
        void addPassenger(int addFrom, int addTo);
        void metroMove();
        void board(int station);
        void unboard(int station);
        
        void distinguish_user_commands(istream &input);
        void distinguish_file_commands(string command);

        int nextId = 1;
        int numOfStats = 0;
        string outputFile;
        

        ofstream outputObject;
};
#endif
