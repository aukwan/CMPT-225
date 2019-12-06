/*
 * Event.cpp
 *
 * Class Description: Models an event(arrival or departure)
 * Class Invariant: Must be of type arrival or departure
 * Created on: 2/12/2019
 * Author: Austin Kwan
 */
#include "Event.h"

using namespace std;

// Description: Default Constructor
// Postconditions: Constructs an empty Event with type=arrival, time=0, and length=0
Event::Event() {
	this->type=arrival;
	this->time=0;
	this->length=0;
}

// Description: Parametrized constructor for departure event
// Postconditions: Constructs an Event with type=departure and time=inputTime
Event::Event(int inputTime) {
	this->type=departure;
	this->time=inputTime;
	this->length=0;
}

// Description: Parametrized constructor with type, time, and length
// Postconditions: Constructs an Event with type=inputType, time=inputTime, and lenght=inputLength
Event::Event(EventType inputType, int inputTime, int inputLength) {
	this->type=inputType;
	this->time=inputTime;
	this->length=inputLength;
}

// Getters and Setters:

// Description: Returns the type of the event
EventType Event::getType() const {
	return this->type;
}

// Description: Returns the time of the event
int Event::getTime() const {
	return this->time;
}

// Description: Returns the length of the event
int Event::getLength() const {
	return this->length;
}


// Description: Set the type of the event
// Preconditons: Type is either arrival or departure
void Event::setType(const EventType inputType) {
	if (inputType!=arrival && inputType!=departure) {
		this->type=arrival;
	} else {
		this->type=inputType;
	}
} 

// Description: Set the time of the event
void Event::setTime(const int inputTime) {
	if(inputTime<0) {
		this->time=0;
	} else {
		this->time=inputTime;
	}
}

// Description: Set the length of the event
void Event::setLength(const int inputLength) {
	if(inputLength<0) {
		this->length=0;
	} else {
		this->length=inputLength;
	}
}
