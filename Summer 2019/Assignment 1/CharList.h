/*
 * CharList.h
 * 
 * Class Description: Doubly-linked list of characters
 * 
 * Author: Austin Kwan
 * Date: 6/2/2019
 */
#include <string>
#include <iostream>

using namespace std;

typedef char Elem;

class CLNode {
    private:
        Elem data;
        CLNode* next;
        CLNode* prev;

        friend class CharList;
};

class CharList {

    private:
        CLNode* header;
        CLNode* trailer;

    public:
        bool empty(); // is the list empty?

        int size() const; // the number of elements in the list

        void insert(char c); // inserts the character c at the front of the list

        void append(char c); // inserts the character c at the back of the list

        void insert(char c, char d); // inserts c immediately before the first occurance of d, or at the end of the list if d does not occur.

        void append(char c, char d); // inserts c immediately after the first occurance of d, or at the end of the list if d does not occur.

        void insert(char c, char d, int n);// inserts c immediately before the nth occurance of d, or at the end of the list if d does not occur n times.

        void append(char c, char d, int n); // inserts c immediately after the nth occurance of d, or at the end of the list if d does not occur n times.

        void remove(char c); // delete the first occurance of character c. Do nothing if c does not occur.

        void remove(char c, int n); // delete the nth occurance of c. Do nothing if c does not occur n times.

        string toString(); // return the list as a string.

        CharList(string s); // constructor. Initializes the list to the contents of the string.

        ~CharList(); // destructor. Returns all memory in the list.
        
    protected:
        void add(CLNode* v, const Elem& e);

        void remove(CLNode* v);

}; // end of CharList.h