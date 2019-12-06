/*
 * Event.h
 *
 * Class Description: Models an event (arrival or departure)
 * Class Invariant: Must be of type arrival or departure.
 * Created on: 2/12/2019
 * Author: Austin Kwan
 */

#pragma once 
#include <iostream>

using namespace std;

typedef enum etype { arrival, departure } EventType;


// Desc:  Represents a simulation event
class Event {
    private:
	    EventType type;
	    int time;
	    int length;

    public:
	    // Description: Default Constructor
	    // Postconditions: Constructs an Event with type=arrival, time=0, and length=0
	    Event();

	    // Description: Parametrized constructor for departure event
	    // Postconditions: Constructs an Event with type=departure and time=inputTime
	    Event(int inputTime);
	
	    // Description: Parametrized constructor with type, time, and length
	    // Postconditions: Constructs an Event with type=inputType, time=inputTime, and lenght=inputLength
    	    Event(EventType inputType, int inputTime, int inputLength);

	    // Getters and Setters:
	
	    // Description: Returns the type of the event
	    EventType getType() const;

	    // Description: Returns the time of the event
	    int getTime() const;

	    // Description: Returns the length of the event
	    int getLength() const;
	
	    // Description: Set the type of the event
	    // Preconditons: Type is either arrival or departure
    	    void setType(const EventType inputType);

	    // Description: Set the time of the event
	    void setTime(const int inputTime);
	
	    // Description: Set the length of the event
	    void setLength(const int inputLength);

      	    // Desc:  Comparators
      	    // Comparing "this" event time with "r" event time
      	    bool operator<(const Event &r) const { return this->time < r.getTime() ; };
      	    bool operator>(const Event &r) const { return this->time > r.getTime() ; };
      	    bool operator<=(const Event &r) const { return this->time <= r.getTime() ; };
      	    bool operator>=(const Event &r) const { return this->time >= r.getTime() ; };

}; // Event

