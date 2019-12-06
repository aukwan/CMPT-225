

// Class Invariant:  FIFO order
/*
 * Queue.h
 *
 * Class Description: Queue ADT
 * Class Invariant: FIFO order
 * Created on: 2/12/2019
 * Author: Austin Kwan
 */
/* None of the provided code (basecode) may be modified. */


#pragma once

#include "Node.h"
#include "EmptyDataCollectionException.h"

#include <cstdio>

using namespace std;

template <class T>
class Queue {
    private:


        /* you choose your implementation */
	int elementCount;
      	Node<T>* head;
	Node<T>* tail;
        
    public:

        // Desc: Constructor. (O(1))
        Queue();


        // Desc: Returns true if Queue is empty. (O(1))
        bool isEmpty() const;

   
        // Desc: Inserts x at the "back" of this Queue. (O(1))
        void enqueue(const T& x);

   
        // Desc: Removes the element at the "front". (O(1))
        //  Pre: Queue not empty.
        //       Throws EmptyDataCollectionException if Queue empty.
        void dequeue() throw(EmptyDataCollectionException);
   

        // Desc: Returns the element at the "front". (O(1))
        //  Pre: Queue not empty.
        //       Throws EmptyDataCollectionException if Queue empty.
        // Post: Queue is unchanged.
        T& peek() const throw(EmptyDataCollectionException);  

	
        /* you may add more methods */

	// Description: Destructor
	~Queue();

	// Description: Returns the number of elements in the Queue
	int getElementCount() const;


};


// Desc: Constructor. (O(1))
template <class T>
Queue<T>::Queue() {
	elementCount=0;
	head=NULL;
	tail=NULL;
} // constructor



// Desc: Returns true if Queue is empty. (O(1))
template <class T>
bool Queue<T>::isEmpty() const {
	return this->elementCount==0;
} // isEmpty



// Desc: Inserts x at the "back" of this Queue. (O(1))
template <class T>
void Queue<T>::enqueue(const T& x) {
	Node<T>* newnode= new Node<T>(x);
	if (isEmpty()) {
		this->head=newnode;
		this->tail=newnode;
	} else {
		this->tail->next=newnode;
		this->tail=this->tail->next;
	}
	elementCount++;
} // enqueue



// Desc: Removes the element at the "front". (O(1))
//  Pre: Queue not empty.
//       Throws EmptyDataCollectionException if Queue empty.
template <class T>
void Queue<T>::dequeue() throw(EmptyDataCollectionException) {
	if (isEmpty()) {
		throw EmptyDataCollectionException("Queue is empty");
	} else {
		Node<T>* ToBeRemoved;
		if (getElementCount()==1) {
			ToBeRemoved=this->head;
			this->head=NULL;
			this->tail=NULL;
		} else {
			ToBeRemoved=this->head;
			this->head=this->head->next;
		}
		delete ToBeRemoved;
		ToBeRemoved=NULL;
		elementCount--;
	}
} // dequeue



// Desc: Returns the element at the "front". (O(1))
//  Pre: Queue not empty.
//       Throws EmptyDataCollectionException if Queue empty.
// Post: Queue is unchanged.
template <class T>
T& Queue<T>::peek() const throw(EmptyDataCollectionException) {
	if (isEmpty()) {
		throw EmptyDataCollectionException("Queue is empty");
	} else {
		return head->data;
	}
} // peek

// Description: Destructor
template <class T>
Queue<T>::~Queue() {
	for (int i=0; i<getElementCount(); i++) {
		dequeue();
	}
} // destructor

// Description: Returns the number of elements in the Queue
template <class T>
int Queue<T>::getElementCount() const {
	return this->elementCount;
} // elementCount


