/*
 * SimApp.cpp
 *
 * Description: Simulation of events
 * Created on: 2/12/2019
 * Author: Austin Kwan
 */
#include "Queue.h"
#include "Event.h"
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"

#include <iostream>

using namespace std;

#include <sstream>


int sum=0;

// Processes an arrival event
bool processArrival(Event* arrivalEvent, PriorityQueue<Event> pQueue, Queue<Event> bankline) {
	int departureTime=0;
  	bool tellerAvailable=true;
  	Event* customer=new Event();
  
  	bankline.dequeue();
  
  	customer->setTime(arrivalEvent->getTime());
  	customer->setType(arrivalEvent->getType());
  	customer->setLength(arrivalEvent->getLength());
  
	if (bankline.isEmpty() && tellerAvailable) {
		departureTime=arrivalEvent->getTime()+arrivalEvent->getLength();
		Event* departureEvent= new Event();
    		departureEvent= new Event(departureTime);
		bankline.enqueue(*departureEvent);
		tellerAvailable=false;
    		cout << "Processing an arrival event at time: " << arrivalEvent->getTime() << endl;
    		return true;
	} else {
		bankline.enqueue(*customer);
	}
}

//Processes a departure event
bool processDeparture(Event* departureEvent, PriorityQueue<Event> pQueue, Queue<Event> bankline) {
	bool tellerAvailable;
  	Event* customer=new Event();
  	Event* newDepartureEvent= new Event();
  
  	int departureTime, currentTime, transactionTime=0;
  	currentTime=departureEvent->getTime();
  	transactionTime=departureEvent->getLength();
  
  	pQueue.dequeue();
  	if (!bankline.isEmpty()) {
    		*customer=bankline.peek();
    		sum=sum+currentTime-customer->getTime();
    		pQueue.dequeue();
    		departureTime=currentTime+transactionTime;
    		newDepartureEvent->setTime(departureTime);
    		newDepartureEvent->setType(departure);
    		pQueue.enqueue(*newDepartureEvent);
    		tellerAvailable=false;
    		cout << "Processing a departure event at time: " << departureEvent->getTime() << endl;
  	} else {
    		tellerAvailable=true;
  	}
  	return tellerAvailable;
}

void simulate() {
  Queue<Event>* bankline= new Queue<Event>();
  PriorityQueue<Event>* pQueue= new PriorityQueue<Event>();
  Event* object= new Event();
  
  string aLine;
  
  int time, length, CustomerCount=0, sum=0;
  int currentTime=0;
  
  bool tellerAvailable=true;
  
  while (getline(cin, aLine)) {
    stringstream ss(aLine);
    ss >> time >> length;
    object->setType(arrival);
    object->setTime(time);
    object->setLength(length);
    
    CustomerCount++;
    
    pQueue->enqueue(*object);
  }
  
  while (!pQueue->isEmpty()) {
    Event* newEvent= new Event();
    *newEvent= pQueue->peek();
    
    currentTime= newEvent->getTime();
    
    
    if (newEvent->getType()==arrival) {
      processArrival(newEvent, *pQueue, *bankline);
    } else {
      processDeparture(newEvent, *pQueue, *bankline);
    }
  }
  // Print Statistics
  cout << "Simulation Ends" << endl;
  cout << endl;
  cout << "Final Statistics: " << endl;
  cout << "    Total number of people processed:  " << CustomerCount << endl;
  cout << "    Average amount of time spent waiting: " << (float)sum/(float)CustomerCount << endl;
}
	
int main () {
	cout << "Simulation Begins" << endl;
	simulate();
	return 0;
} // main

