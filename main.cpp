/*
*This is a airline waiting list app, it decides who will be the first to get board
*according to their priority
*
*@Kang Rong
**/
 
#include <iostream>
#include <string>
#include "list.h"
#include "customer.h"

using namespace std;

int main(){
    //initialize the list
    Customer* customer= new Customer();
    List *list = new List(customer);
    //print out the list before sorting
    list->listPrint(customer);
    
    cout<<"------------------------------after sorting-------------------------------"<<endl;
    //sort the list
    list->sort(customer);
    //print out the list after sorting
    list->listPrint(customer);

    //adding new customer
    int n;
    cout<<"Input the number of customers you want to add: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
    Customer* newCustomer=new Customer;
    list->listAdd(customer,newCustomer);
    }
    //after adding all new customers
    list->listPrint(customer);
    
    cout<<"------------------------------sorting again-------------------------------"<<endl;
    //sorting again
    list->sort(customer);
    list->listPrint(customer);
    
    //start boarding(deleting)
    list->startBoarding(customer);
    
    return 0;
}

