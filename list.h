#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include "customer.h"
using namespace std;

class List{
public:
    //initialization of customers using linked list
    List(Customer* &node){
        //same Status but paid different fares
        node=NULL;
        node=newCustomer("John",500,7,"waiting",node);
        node=newCustomer("Max",200,6,"waiting",node);
        node=newCustomer("Mark",300,7,"waiting",node);
        // same Status and paid the same fare
        node=newCustomer("Luke",200,6,"waiting",node);
        node=newCustomer("Matt",200,6,"waiting",node);
        
        node=newCustomer("Julie",200,1,"waiting",node);
        node=newCustomer("Judy",800,2,"waiting",node);
        node=newCustomer("Lucy",900,3,"waiting",node);
        node=newCustomer("Johnson",200,4,"waiting",node);
        node=newCustomer("Jeff",200,5,"waiting",node);
        
    }
    //creating a new customer
    Customer* newCustomer(string newName, int newFare, int NewConnectingFlight, string newStatus, Customer* newNext);
    
    //adding a new customer at the front
    void listAdd(Customer* &node, Customer* newNode);
    
    //sorting
    void sort(Customer* &node);
    
    //the length of the list
    int listLength(Customer* node);
    
    //delete a customer
    void listDelete(Customer* &node);
    
    //start boarding
    void startBoarding(Customer* &node);
    
    //printQueue
    void listPrint(Customer* p);
    
    
    
};


#endif
