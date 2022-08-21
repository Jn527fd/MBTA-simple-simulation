#########################################################
#             PROJECT 1: MetroSim Makefile             #
#########################################################

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 

INClUDES = $(shell echo *.h)
EXECS    = Metrosim

# ***TODO***
# Metrosim rule - you need to fill in the linking command,
# add any new dependencies, and add target rules for 
# Passenger.o, MetroSim.o, main.o, and any new dependencies.
# Please use the rules provided below for PassengerQueue.o as an example for
# what to do.
# If you add other classes, you'll have to add their .o files as dependencies here.
# Don't forget:  the clang++ command must be indented with a TAB character
# and be all on one line.
MetroSim: main.o MetroSim.o PassengerQueue.o Passenger.o
	$(CXX) $(CXXFLAGS) -o MetroSim main.o MetroSim.o PassengerQueue.o Passenger.o

# ***TODO***
# Write rules for any other .o files.
# You can base them on the PassengerQueue.o rule.
# Every .cpp file that is part of your program should have a .o rule.

# This rule builds PassengerQueue.o
PassengerQueue.o: PassengerQueue.cpp PassengerQueue.h Passenger.h 
	$(CXX) $(CXXFLAGS) -c PassengerQueue.cpp

main.o: main.cpp MetroSim.h
	$(CXX) $(CXXFLAGS) -c main.cpp
	
MetroSim.o: MetroSim.cpp MetroSim.h PassengerQueue.h
	$(CXX) $(CXXFLAGS) -c MetroSim.cpp

# ***TODO***
# The below rule will be used by unit_test.
# Please add any other .o files that are needed by PassengerQueue,
# and any other .o files you wish to test. 
unit_test: unit_test_driver.o PassengerQueue.o Passenger.o
	$(CXX) $(CXXFLAGS) unit_test_driver.o PassengerQueue.o Passenger.o

# remove executables, object code, and temporary files from the current folder 
# -- the executable created by unit_test is called a.out
clean: 
	rm *.o *~ a.out
