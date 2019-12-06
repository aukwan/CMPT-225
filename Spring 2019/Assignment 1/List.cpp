/*
 * List.cpp
 *
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - List length will stay equal to or less than MAX_ELEMENTS
 *
 *Author:Austin Kwan
 *Date:1/9/2019
 */

#include <iostream>
#include "List.h"

using namespace std;

// Default constructor
List::List() : elementCount(0), capacity(List::MAX_ELEMENTS) {}

// Description: Returns the total element count currently stored in List.
int List::getElementCount() const {
	return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and elementCount has been incremented.   
bool List::insert(const Patient& newElement) {
	// Checks if # of elements exceeds max capacity or not
	if (elementCount < capacity) {
    elementCount=elementCount+1; 
		for (int i=0; i<getElementCount(); i++) {
			if (elements[i]==newElement) {
				return false;
			}
		}
		elements[elementCount-1]=newElement;
		return true;
	}
	return false;
}

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
bool List::remove( const Patient& toBeRemoved ) {
	// Search for element to be removed
	for (int i=0; i<getElementCount(); i++) {
		if (elements[i]==toBeRemoved) {
			for (int j=i+1; j<getElementCount(); j++) {
				elements[j-1]=elements[j];
			}
			elementCount--;
			return true;
		}
	}
	return false;
}

// Description: Remove all elements.
void List::removeAll() {
	elementCount=0;
}
	

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target) {
	for (int i=0; i<getElementCount(); i++){
		if (elements[i]==target) {
			return &elements[i];
		}
	}
	return NULL;
}

// Description: Prints all elements stored in List.
void List::printList() {
	for (int i=0; i<getElementCount(); i++) {
		cout << elements[i];
	}
}

//end of List.cpp