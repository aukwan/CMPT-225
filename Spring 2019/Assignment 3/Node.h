/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list (template)
 *                   Designed and implemented as a non-ADT.
 * Class Invariant: next is either a pointer to another node or NULL
 * Created on: 2/12/2019
 * Author: Austin Kwan
 */
 
#pragma once

#include <cstdio>  // Needed for NULL

using namespace std;


template <class T>
class Node {
    public:
        T data;
	Node<T>* next;

	// Description: Default Constructor
	Node();

	// Description: Constructor with data parameter
	Node(T inputData);

}; // Node

// Description: Default Constructor
template <class T>
Node<T>::Node() {
	next=NULL;
}

// Description: Constructor with data parameter
template <class T>
Node<T>::Node(T inputData) {
	data=inputData;
	next=NULL;
}

