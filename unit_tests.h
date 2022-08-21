#include "Passenger.h"
#include "PassengerQueue.h"

#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* test_print_Passenger
*    Purpose: test passenger class's print()
*    Parameters: None 
*    Returns: None 
*/
void test_print_Passenger()
{
    std::cout << "***** Testing print()#1 *****" << std::endl;
        
    Passenger newPass(1,2,3);
    newPass.print(std::cout);
        
    Passenger newPass2(4,5,64);
    newPass2.print(std::cout);
    std::cout << std::endl;
}

/* test0_front_PassengerQueue 
*    Purpose: test enqueue()
*    Parameters: None 
*    Returns: None 
*    Notes: Also tests print() and enqueue()
*/
void test0_front_PassengerQueue()
{
    std::cout << "***** Testing front() *****" << std::endl;
    
    PassengerQueue instanceOne;
    Passenger newPass(8,2,10);
    //Passenger newPass2(2,3,4);
   // Passenger newPass3(3,4,5);
    instanceOne.enqueue(newPass);
    //instanceOne.enqueue(newPass2);
    //instanceOne.enqueue(newPass3);

    instanceOne.front().print(std::cout);
    std::cout << std::endl;
}

/* 
*    Purpose: test dequeue() 
*    Parameters: None 
*    Returns: None 
*/
void test0_dequeue_PassengerQueue()
{
    std::cout << "***** Testing dequeue() *****" << std::endl;
    
    PassengerQueue instanceOne;
    Passenger newPass(1,2,3);
    Passenger newPass2(2,3,4);
    Passenger newPass3(3,4,5);
    instanceOne.enqueue(newPass);
    instanceOne.enqueue(newPass2);
    instanceOne.enqueue(newPass3);
    
    std::cout << "Original: ";
    instanceOne.print(std::cout);
    std::cout << std::endl;

    instanceOne.dequeue();
    
    std::cout << "Dequeued once: ";
    instanceOne.print(std::cout);
    std::cout << std::endl;
        
    instanceOne.dequeue();
    
    std::cout << "Dequeued twice: ";
    instanceOne.print(std::cout);
    std::cout << std::endl;

}

/* test0_enqueue_PassengerQueue
*    Purpose: test enqueue()
*    Parameters: None 
*    Returns: None 
*    Notes: Also tests print()
*/
void test0_enqueue_PassengerQueue()
{
    std::cout << "***** Testing enqueue() *****" << std::endl;
    
    PassengerQueue instanceOne;
    
    std::cout << "Original: " << std::endl;
    instanceOne.print(std::cout); 

    std::cout << "The following should print below: [1, 2->3][2, 3->4]" 
    << std::endl;
    
    Passenger newPass(1,2,3);
    Passenger newPass2(2,3,4);
    instanceOne.enqueue(newPass);
    instanceOne.enqueue(newPass2);
    
    std::cout << "enqueued:" ;
    instanceOne.print(std::cout);
    std::cout << std::endl;
}

/* test0_size_PassengerQueue
*    Purpose: test size()
*    Parameters: None 
*    Returns: None 
*    Note: also tests print(), enqueue(), dequeue().
*/
void test0_size_PassengerQueue()
{
    std::cout << "***** Testing size() *****" << std::endl;
        
    PassengerQueue instanceOne;
    Passenger newPass(1,2,3);
    Passenger newPass2(4,6,4);
    Passenger newPass3(3,4,5);
    
    instanceOne.enqueue(newPass);
    instanceOne.enqueue(newPass2);
    instanceOne.enqueue(newPass3);
    
    std::cout << "Original: ";
    instanceOne.print(std::cout);
   
    
    std::cout << "; Size is " << instanceOne.size() << std::endl;

    instanceOne.dequeue();
    std::cout << "Dequeued once: ";
    instanceOne.print(std::cout);
    std::cout << "; Size is " << instanceOne.size() << std::endl;
    std::cout << std::endl;
        
}

/* test0_print_PassengerQueue
*    Purpose: test the print function in PassengerQueue class 
*    Parameters: None 
*    Returns: None 
*/
void test0_print_PassengerQueue()
{
    std::cout << "***** Testing print()#2 *****" << std::endl;
        
    PassengerQueue instanceOne;
    Passenger newPass(1,2,3);
    instanceOne.enqueue(newPass);
    instanceOne.print(std::cout);
        
}

/* edgecase0_dequeue_PassengerQueue
*    Purpose: test the outcome of trying to dequeue a empty list
*    Parameters: None 
*    Returns: None 
*
*/
void edgecase0_dequeue_PassengerQueue()
{
    std::cout << "***** Testing dequeue() *****" << std::endl;
    
    PassengerQueue instanceOne;
    
    std::cout << "Original: ";
    instanceOne.print(std::cout);
    std::cout << std::endl;

    instanceOne.dequeue();
    
    std::cout << "Dequeued once: ";
    instanceOne.print(std::cout);
    std::cout << std::endl;
        
}