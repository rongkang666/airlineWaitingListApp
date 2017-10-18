#include <iostream>
#include <string>
#include <stdlib.h>
#include "list.h"
#include "customer.h"

using namespace std;
//creating new customer
Customer* List::newCustomer(string newName, int newFare, int NewConnectingFlight, string newStatus, Customer* newNext){
    Customer* customer=new Customer;
    //set new customer attributes
    customer->setName(newName);
    customer->setFare(newFare);
    customer->setConnectingFlight(NewConnectingFlight);
    customer->setStatus(newStatus);
    customer->next=newNext;
    return customer;
}
//adding customer to the end of the list
void List::listAdd(Customer* &node, Customer* newNode){
    
    string name_;
    int fare_, connectingFlight_;
    
    Customer *endOfList = NULL;
    Customer* tmpNode;
    tmpNode=node;
    
    //set name
    cout<<"Input the information of customer"<<endl;
    cout<<"Customer name: "<<endl;
    cin>>name_;
    
    //set fare
    cout<<"Fare: "<<endl;
    cin>>fare_;
    
    //set connectintflight
    cout<<"Customer connectingFlight (1-7, 1 is first priority, 2 is second priority,..., 7 is the last priority): "<<endl;
    cin>>connectingFlight_;
    
    newNode->setName(name_);
    newNode->setFare(fare_);
    newNode->setConnectingFlight(connectingFlight_);
    newNode->setStatus("waiting");
    newNode->next=NULL;
    
    //treverse the list, and add new node at the end
    while(tmpNode!=NULL){
        if(tmpNode->next==NULL){
            endOfList=tmpNode;
        }
        tmpNode=tmpNode->next;
    }
    endOfList->next=newNode;
}


//sorting customer
void List::sort(Customer* &node){
    Customer* temphead = node;
    int tempConnectingFlight;
    int tempFare;
    string tempname;
    string tempStatus;
    
    int counter = listLength(node);//get the list length
    //go through the whole list
    for (int i=0; i<counter; i++)
    {   //check if node points to null
        while (temphead->next)
        {   //check if the previous customer's priority(number) is lower(higher) than the next one
            if (temphead->getConnectingFlight() > temphead->next->getConnectingFlight())
            {
                //swap their connectingFlight number
                tempConnectingFlight = temphead->getConnectingFlight();
                temphead->setConnectingFlight(temphead->next->getConnectingFlight());
                temphead->next->setConnectingFlight(tempConnectingFlight);
                //swap their name
                tempname = temphead->getName();
                temphead->setName(temphead->next->getName());
                temphead->next->setName(tempname);
                //swap their fare
                tempFare = temphead->getFare();
                temphead->setFare(temphead->next->getFare());
                temphead->next->setFare(tempFare);
                //swap their status
                tempStatus = temphead->getStatus();
                temphead->setStatus(temphead->next->getStatus());
                temphead->next->setStatus(tempStatus);
                
            }
            //if they have same priority
            if(temphead->getConnectingFlight() == temphead->next->getConnectingFlight()){
                //check who pays higher
                if(temphead->getFare() < temphead->next->getFare()){
                    //swap their name
                    tempname = temphead->getName();
                    temphead->setName(temphead->next->getName());
                    temphead->next->setName(tempname);
                    //swap their fare
                    tempFare = temphead->getFare();
                    temphead->setFare(temphead->next->getFare());
                    temphead->next->setFare(tempFare);
                    //swap their status
                    tempStatus = temphead->getStatus();
                    temphead->setStatus(temphead->next->getStatus());
                    temphead->next->setStatus(tempStatus);
                }
                //if they pay the same, anyone can be chosen
                if(temphead->getFare()==temphead->next->getFare()){
                    int r=rand()%2+1;//create a random number (1 or 2)
                    //each time when comapring two same customers, with 50% chance, one of them will be chosen to wait before the other one
                    if(r==1){
                        //swap their name
                        tempname = temphead->getName();
                        temphead->setName(temphead->next->getName());
                        temphead->next->setName(tempname);
                        //swap their fare
                        tempFare = temphead->getFare();
                        temphead->setFare(temphead->next->getFare());
                        temphead->next->setFare(tempFare);
                        //swap their status
                        tempStatus = temphead->getStatus();
                        temphead->setStatus(temphead->next->getStatus());
                        temphead->next->setStatus(tempStatus);
                    }
                }
            }
            //move to the nest node
            temphead = temphead->next;
        }
        temphead = node;//after while loop, assign node to temphead again
    }
}

//measure the list length
int List::listLength(Customer* node){
    int count=0;
    while(node!=NULL){
        count++;
        node=node->next;
    }
    
    return count;
}

//deleting customer
void List::listDelete(Customer* &node){
    Customer *temphead = node;
    node = node->next;   // head is the next element
    delete temphead; // delete the old head
}

//start boarding
void List::startBoarding(Customer* &node){
    int l=listLength(node);//set list length
    for(int i=0;i<l;i++){
        cout<<"Start boarding..."<<endl;
        char c;//for user input
        
        node->setStatus("boarding");//set customer status to boarding
 
        listPrint(node);//print out the current list (status changing)
        
        cout<<"Press 'c' to continue"<<endl;
        cin>>c;
        
        cout<<"Now deleting this boarding customer from list"<<endl;
        
        listDelete(node);//deleting customer whose status is boarding/or the first one in the line
        listPrint(node);//print out the updated list
        
    }
    
}


//printing out the result
void List::listPrint(Customer* p){
    cout<<"Printing queue"<<endl;
    Customer* tempNode=p;
    //traverse the list
    while(tempNode!=NULL){
        cout<<"Customer name: "<<tempNode->getName()<<","<<"Fare: "<<
        tempNode->getFare()<<","<<"ConnectingFlight: "<<tempNode->getConnectingFlight()<<","<<"Status: "<<
        tempNode->getStatus()<<endl;
        tempNode=tempNode->next;
    }
    //end of list
    if(tempNode==NULL){
        cout<<"End of the queue"<<endl;
    }
}
