/*
 * PriorityQueue.h
 *
 * Description: Priority Queue
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 * Modified: February 2019
 *
 */



/* None of the provided code (basecode) may be modified. */



#pragma once

#include "Node.h"
#include "EmptyDataCollectionException.h"

#include <cstdio>

using namespace std;


template <class T>
class PriorityQueue {

    private:
        // singly-linked list
        Node<T>* head;
        int len;


        /* You may add private methods to this class */


    public:
        // Desc: Default Constructor. (O(1))
        PriorityQueue();
 

        // Desc: Copy Constructor. (O(N))
        PriorityQueue(const PriorityQueue& rhs);


        // Desc: Destructor. (O(N))
        ~PriorityQueue();


        // Desc: Returns true if Priority Queue empty. (O(1))
        bool isEmpty() const;


        // Desc: Returns length of the Priority Queue. (O(1))
        int getLength() const;


        // Desc: Inserts x in sorted order. (O(N))
        //  Pre: Priority Queue is sorted.
        // Post: Priority Queue remains sorted.
        void enqueue(const T& x);
    

        // Desc: Removes the element with "highest" priority. (O(1))
        //  Pre: Priority Queue not empty.
        //       Throws EmptyDataCollectionException if Priority Queue empty.
        void dequeue() throw(EmptyDataCollectionException);


        // Desc: Returns the element with the "highest" priority. (O(1))
        //  Pre: Priority Queue not empty.
        //       Throws EmptyDataCollectionException if Priority Queue empty.
        // Post: Priority Queue is unchanged.
        T& peek() const throw(EmptyDataCollectionException);

}; // PriorityQueue

// Desc: Default Constructor. (O(1))
template <class T>
PriorityQueue<T>::PriorityQueue() {
	head=new Node<T>();
	head->next=NULL;
	len=0;
}
// Desc: Copy Constructor. (O(N))
template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& rhs) {
	Node<T>* copy=rhs.head;
	while (copy!=NULL) {
		enqueue(copy->data);
		copy=copy->next;
	}
}	

// Desc: Destructor. (O(N))
template <class T>
PriorityQueue<T>::~PriorityQueue() {
	Node<T>* current=head;
	Node<T>* temp;
	while (current!=NULL) {
		temp=current;
		current=current->next;
		delete temp;
	}
	len=0;
}

// Desc: Returns true if Priority Queue empty. (O(1))
template <class T>
bool PriorityQueue<T>::isEmpty() const {
	return getLength()==0;
}

// Desc: Returns length of the Priority Queue. (O(1))
template <class T>
int PriorityQueue<T>::getLength() const {
	return len;
}

// Desc: Inserts x in sorted order. (O(N))
//  Pre: Priority Queue is sorted.
// Post: Priority Queue remains sorted.
template <class T>
void PriorityQueue<T>::enqueue(const T& x) {
	Node<T>* prev;
	Node<T>* next;
	Node<T>* current;
	next=head;
	prev=NULL;
	current=head;
	
	Node<T>* newNode= new Node<T>(x);
	while (next!=NULL) {
		if (next->data.getTime()==newNode->data.getTime()) {
			if (newNode->data.getType()==arrival) {
				prev->next=newNode;
				newNode->next=next;
				len++;

			} else {
				prev=next->next;
				next=next->next;
				prev->next=newNode;
				len++;
			}
		} else if (newNode->data.getTime() < next->data.getTime()) {
			prev->next=newNode;
			newNode->next=next;
			len++;
		} else {
			next->next=newNode;
			newNode->next=next;
			len++;
		}
		prev=next;
		next=next->next;
	}
}
	

// Desc: Removes the element with "highest" priority. (O(1))
//  Pre: Priority Queue not empty.
//       Throws EmptyDataCollectionException if Priority Queue empty.
template <class T>
void PriorityQueue<T>::dequeue() throw(EmptyDataCollectionException) {
	if (isEmpty()) {
		throw EmptyDataCollectionException("Priority Queue is empty");
	} else {
		head=head->next;
		len--;
	}
}

// Desc: Returns the element with the "highest" priority. (O(1))
//  Pre: Priority Queue not empty.
//       Throws EmptyDataCollectionException if Priority Queue empty.
// Post: Priority Queue is unchanged.
template <class T>
T& PriorityQueue<T>::peek() const throw(EmptyDataCollectionException) {
	if (isEmpty()) {
		throw EmptyDataCollectionException("Priority Queue is empty");
	} else {
		return head->data;
	}
}
