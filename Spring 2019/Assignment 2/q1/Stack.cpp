/*
 * Stack.cpp
 *
 * Class Description: Implementation of an int sequence with push/pop in a LIFO order
 * Class Invariant: next is either a pointer to another node or NULL
 * Date: 1/23/2019
 * Author: Austin Kwan
 */
#include "Stack.h"

#include <cstddef>

using namespace std;

// Desc:  Constructor
// Post:  Stack is empty
Stack::Stack(): head(NULL), tail(NULL) {}

// Desc:  Destructor
// Post:  Delete the stack and free the memeory used.
Stack::~Stack() {
	StackNode* current=head;
	StackNode* next;
	while (current!=NULL) {
		next=current->next;
		delete current;
		current=next;
	}
}

// Desc:  Insert element x to the top of the stack.
// Post:  Tail is updated with element x.
void Stack::push(int x)	{
	StackNode* newnode= new StackNode;
	newnode->data=x;
	newnode->next= NULL;
	if (tail) {
		tail->next= newnode;
		tail= newnode;
	} else {
		head=newnode;
		tail=newnode;
	}
}

// Desc:  Remove and return element at the top of the stack.
//  Pre:  Stack is not empty.
// Post:  Tail is updated with the element before tail.
int Stack::pop() {
	if(head) {
		
		int ret=tail->data;
  		if(head->next==NULL) {
    			ret=head->data;
    			head=NULL;
    			return ret;
    		}
		StackNode* oldtail=tail;
		StackNode* current=head;
  		StackNode* next=head->next;
		while(next->next!=NULL) {
			current=next;
    			next=next->next;
		}
		current->next=NULL;
  		tail=current;
		delete oldtail;
		return ret;
	}
}
	
// Desc:  Return the topmost element of the stack.
//  Pre:  Stack is not empty.
// Post:  Return the topmost element of the stack without removing it.	
int Stack::peek() const {
	if (head) {
		return tail->data;
	}
}

bool Stack::isEmpty() const {
	return (head==NULL);
}

