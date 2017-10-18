#include <iostream>
#include <string>
#include "customer.h"
using namespace std;

//set customer name
void Customer::setName(string name_){
    name=name_;
}
//get name
string Customer::getName(){
    return name;
}
//set fare
void Customer::setFare(int fare_){
    fare=fare_;
}
//get fare
int Customer::getFare(){
    return fare;
}
//set connectingFlight number
void Customer::setConnectingFlight(int connectingFlight_){
    connectingFlight=connectingFlight_;
}
//get connectingFlight number
int Customer::getConnectingFlight(){
    return connectingFlight;
}
//set status
void Customer::setStatus(string status_){
    status=status_;
}
//get status
string Customer::getStatus(){
    return status;
}


