/*
 * Stack.h
 *
 * Class Description: Implementation of an int sequence with push/pop in a LIFO order
 * Class Invariant: 
 *	-next is either a pointer to another node or NULL
 *	-items are pushed to the tail and popped from the tail
 * Date: 1/23/2019
 * Author: Austin Kwan
 */
class Stack {

    private:

        // Desc:  Nodes for a singly-linked list
        class StackNode {
            public:
                int data;
                StackNode * next;
        };
        

        // Desc:  head = ptr to the first StackNode (NULL if empty)
        //        tail = ptr to the last StackNode (NULL if empty)
        //  Inv:  Follows the A2 Spec, namely that the implementation 
        //        is a singly-linked list, with insert/remove 
        //        operations at the list's tail.
        StackNode * head;
        StackNode * tail;

    public:

        // Desc:  Constructor
        // Post:  Stack is empty
        Stack();


        // Desc:  Destructor
        // Post:  Delete the stack and free the memeory used.
        ~Stack();


        // Desc:  Insert element x to the top of the stack.
        // Post:  Tail is updated with element x.
        void push(int x);


        // Desc:  Remove and return element at the top of the stack.
        //  Pre:  Stack is not empty.
        // Post:  Tail is updated with the element before tail.
        int pop();


        // Desc:  Return the topmost element of the stack.
        //  Pre:  Stack is not empty.
        // Post:  Return the topmost element of the stack without removing it.
        int peek() const;



        // Desc:  Checks if the stack is empty.
        // Post:  Return true if empty or false if not empty.
        bool isEmpty() const;
};


