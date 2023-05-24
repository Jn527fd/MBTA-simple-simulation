* Project 1: Metro Simulator
* CS 15
* README
* Jesus G Naranjo
* 07.06.2022 


Compile/run:
     - Compile using
            make MetroSim
     - run executable with
            ./MetroSim stationsFile passFile [commands]

Program Purpose: 
    This homework assignment handles the simulation of a running train that
accommodates passengers that board at a certain station and depart at their 
destinations. Overall the purpose is to design and create an implementation
to modularize code and work with documented libraries, in this way this 
program uses vectors of structs and queues to manipulate data. 

Acknowledgements: 
    Thank you, to professor Martin who helped me start to figure out the 
while loops of Metrosim.cpp and fellow classmate aliyu who helped me understand 
vectors through its use within PassengerQueue.cpp.

Files: 

main.cpp:
    Driver file for MetroSim, PassengerQueue, and Passenger classes. Contains
    main() function, reads in files, and executes the simulation.
     
MetroSim.h:
    Interface of MetroSim class. Declares the public and private functions and 
    member variables of the MetroSim class.

MetroSim.cpp:
    Implementation of MetroSim class. Includes key functions allowing the user
    to interact with a metro simulation. Deals with passengers going on/off 
    the train. Functions include: default constructor, destructor, 
    initialize_stations, printTrain, printMap, obtainInstructions,
    exeInstructions, initialize_train, addPassenger, metroMove, board,
    unboard, nextStationInd, printOutput, readStations, findDirections, 
    readInstructions.
    Also includes struct definitions: instruction, station, train.

PassengerQueue.h:
    Interface of PassengerQueue class used to declare public and 
    private functions add memeber variables of the passengerqueue class

PassengerQueue.cpp:
    interface of PassengerQueue class. Contains definitions of key 
    functions that allow the user interact with and modify Queue,
    Functions include: default constructor, destructor, front, back,
    dequeue, enqueue, print, createPassenger.

Passenger.h:
    Interface of Passenger class which contains definitions of struct 
    Passenger.    

Passenger.cpp:
    implementation of the Passenger class, contains the function 
    print().

stations.txt:
    A file Listing example station names.

test_commands.txt:
    sample list of commands that you could give to the simulator

outputs.txt
    The output file used for unit testing. Contains a sample output from my
    most recent test. 

Makefile:
    File containing instructions for compiling and linking to create
    an executable file.

README: 
    This file.

Data Structures:
     The data structures used in this program were vectors and queues, 
in using vectors size can be changed dynamically. This become very helpful 
as data does not need to be copied from one array to another. Vectors also 
have order elements which makes access to elements located at middle location 
easier compared to linked lists. One major disadvantage to using vectors is
that memory changes dynamically which mean that vectors consume more memory.

     Queues use FIFO, an advantage to using queues are that it is easier 
to access and modify the elements at the end of the queue. Elements
in the queue are ordered and the size does not have to be allocated beforehand 
like arrays or linked lists. One disadvantage is that elements not at the end 
are more difficult to access or use, queues functions to enqueue and dequeue 
which makes it harder for middle elements to be altered.

Testing:
        First i started by writing the print function for the Passenger class 
and testing it with different inputs while seeing the printed result within 
the terminal. After that i worked on PassengerQueue class functions testing 
them as listed on the coding spec. I started with front where i enqueued three 
elements that all had there own person with arrival and departure stops. Then i
called the front functions and printed the results and visually checked if the 
outcome on the terminal was expected. I repeated this process with all of the 
following functions: dequeue(), enqueue(), size(), and print(). I also create a
edge case for dequeue() to test what would happen if the user tried to dequeue 
a already empty vector and in this i found that it cause a error so i 
implemented a throw error declaring that you can not dequeue a already empty 
vector. 

        For the second part of the project i did not unit test each individual
functions instead i created a separate extra cpp file and a output file
to verify that the simulation worked by going through where passengers got off
the train manually through going through the outputs and comparing it to the 
commands from "test_commands.txt". Additionally i created a cpp file named 
unit-test#2.cpp which i used to test that stations were being read correctly 
, the printing of passengers on the train and lastly the command unit 
which was used to see if the vector was the correct size depending on the 
amount of commands read form the file test_commands.txt. 

Part that you found most difficult:
    The most difficult part so far was the testing of the Passenger and 
PassengerQueue class because i was not able to use assert() correctly without 
bring up an error while running the unit_test command within terminal. 

    From the second part the most difficult part was creating a vector for 
the passengers present at a station and then move them into the train.
Additionally I had trouble recording to outputs.txt.This was not a problem with 
my printOutput function but a issue with where I was calling it. I had 
printOutput as a member function of the MetroSim class and the input for the 
file name was being provided in main(). I created a member variable outputFile 
to hold the name of the output file and ofstream object outputObject to send  
records to. 
