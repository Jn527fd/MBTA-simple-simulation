#include "MetroSim.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void test0_stations();
void test0_print_train();
void test0_command_line();

int main(){
        test0_stations();
        test0_print_train();
        test0_command_line();
}

/* test0_stations
*    Purpose: to see if the stations are index correctly
*    Parameters: none
*    Returns: None 
*/
void test0_stations()
{
        ifstream in;
        in.open("stations.txt")
        
        readStations(in);
        
        if(allStations[2].location != "Riverway") {
                cerr << "3rd station should be Riverway" << endl;
                
        }
        
        if (allStations[4].stopNum != 4) {
                cerr << "4th station's id shoudl be 4" << endl;
        }
}

/* test0_stations
*    Purpose: test the function that tests the printing of the train
*    Parameters: none
*    Returns: None 
*/
void test0_stations()
{
        addPassenger(1,5);
        addPassenger(1,4);
        addPassenger(1,7);
        
        board(1);
        
        printTrain();
        
        cout << "should print" <<  "[1, 1->5][2, 1->4][3, 1->7]" << endl;
                
}

/* test0_command_line
*    Purpose: test the size of the vector that holds passengers at certain
*             stations
*    Parameters: none
*    Returns: None 
*/
void test0_command_line()
{

    //temporarily changed command file to output the
    // file name each time it changes and see if it
    // matched the expected file name at that particular time
    // where command_testing.txt is a small file
    // of possible commands        
    MetroSim instance("stations.txt", "outputs.txt", "test01_commands.txt", 3);
        
    directionType = instance.findDirections();
    instance.readStations();
    instance.initialize_train();
        
    if (directionType == "user") { 
        instance.userMove();
            
    } else {
        cerr << "Read in file" << endl;
        instance.readInstructions();
    }

    if((allStations[0].atStation).size() != 1){
            cerr << "P 1 4 not exectued properly" << endl;
            
    } 
    
    if ((allStations[1].allStations).size() != 2) {
            cerr << " P 2 3 amd p 2 8 not executed properly" << endl;
    }

}