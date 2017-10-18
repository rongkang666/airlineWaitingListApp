#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
using namespace std;

class Customer{
    string name;//customer name
    int fare;//ticket fare
    int connectingFlight;//priority as a number
    string status;//customer status-waiting or boarding
 
public:
    
    Customer *next;//pointer to the next customer

    //set customer name
    void setName(string name_);
    //get name
    string getName();
    //set fare
    void setFare(int fare_);
    //get fare
    int getFare();
    //set connectingFlight number
    void setConnectingFlight(int connectingFlight_);
    //get connectingFlight number
    int getConnectingFlight();
    //set status
    void setStatus(string status_);
    //get status
    string getStatus();
};


#endif
