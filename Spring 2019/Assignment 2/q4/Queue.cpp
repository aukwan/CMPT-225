
#include "Queue.h"


// Desc:  Constructor
Queue::Queue() : size(0), capacity(INITIAL_SIZE), frontindex(0), backindex(0) {
    arr= new int[capacity];
} // constructor

// Desc:  Destructor
Queue::~Queue(){
    delete [] arr;
    }
// Desc:  Inserts element x at the back (O(1))
void Queue::enqueue(int x) {
    if (size==backindex) {
      capacity=capacity*2;
      int *newarr=new int [capacity];
      for (int i=0; i<size; i++) {
        newarr[i]=arr[i];
      }
      delete [] arr;
      arr= newarr;
    }
    arr[backindex] = x;
    backindex = (backindex + 1)%capacity;
    size++;
} // enqueue


// Desc:  Removes the frontmost element (O(1))
//  Pre:  Queue not empty
void Queue::dequeue() {
    if (!isEmpty()) {  
      if ((size)<(capacity/4)) {
        if ((capacity/2)>INITIAL_SIZE) {
          capacity=capacity/2;
          }
        }
      frontindex=(frontindex+1)%capacity;
      size--;
      }      
} // dequeue


// Desc:  Returns a copy of the frontmost element (O(1))
//  Pre:  Queue not empty
int Queue::peek() const {
    return arr[frontindex];
} // top


// Desc:  Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const {
    return size == 0;
} // isempty
