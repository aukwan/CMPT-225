/*
 * CharList.cpp
 * 
 * Class Description: Doubly-linked list of characters
 * 
 * Author: Austin Kwan
 * Date: 6/2/2019
 */
#include <iostream>
#include "CharList.h"

using namespace std;

bool CharList::empty() { // is the list empty?
    return header->next == trailer;
}

int CharList::size() const { // the number of elements in the list
    CLNode* current= header->next;
    int size = 0;
    while (current != trailer) {
        current = current->next;
        size++;
    }
    return size;
}

void CharList::insert(char c) { // inserts the character c at the front of the list
    add(header->next, c);
}

void CharList::append(char c) { // inserts the character c at the back of the list
    add(trailer, c);
}

void CharList::insert(char c, char d) {  // inserts c immediately before the first occurance of d, or at the end of the list if d does not occur.
    if (empty()) {
        append(c);
        return;
    }
    CLNode* current = new CLNode;
    current = header->next;
    while (current != trailer) {
        if (current->data == d) {
            add(current, c);
            return;
        }
        current = current->next;
    }
    add(trailer, c);
}

void CharList::append(char c, char d) { // inserts c immediately after the first occurance of d, or at the end of the list if d does not occur.
    if (empty()) {
        append(c);
        return;
    }
    CLNode* current = header->next;
    while (current != trailer) {
        if (current->data == d) {
            add(current->next, c);
            return;
        }
        current = current->next;
    }
    add(trailer, c);
}

void CharList::insert(char c, char d, int n) { // inserts c immediately before the nth occurance of d, or at the end of the list if d does not occur n times.
    if (empty()) {
        append(c);
        return;
    }
    CLNode* current = header->next;
    int counter = 0;
    while (current != trailer) {
        if (current->data == d) {
            counter++;
            if (counter == n) {
                add(current, c);
                return;
            }
        }
        current = current->next;
    }
    add(trailer, c);
}
void CharList::append(char c, char d, int n) { // inserts c immediately after the nth occurance of d, or at the end of the list if d does not occur n times.
    if (empty()) {
        append(c);
        return;
    }
    CLNode* current = header->next;
    int counter = 0;
    while (current != trailer) {
        if (current->data == d) {
            counter++;
            if (counter == n) {
                add(current->next, c);
                return;
            }
        }
        current = current->next;
    }
    add(trailer, c);
}

void CharList::remove(char c) { // delete the first occurance of character c. Do nothing if c does not occur.
    CLNode* current = header->next;
    while (current->next != trailer) {
        if (current->data == c) {
            remove(current);
            return;
        }
        current = current->next;
    }
}

void CharList::remove(char c, int n) { // delete the nth occurance of c. Do nothing if c does not occur n times.
   CLNode* current = header->next;
   int counter = 0;
    while (current->next != trailer) {
        if (current->data == c) {
            counter++;
            if (counter == n) {
                remove(current);
                return;
            }
        }
        current = current->next;
    }
}

string CharList::toString() { // return the list as a string.
    string res = "";
    if (empty()) {
      return res;
    }
    CLNode* current = header->next;
    while (current != trailer) {
        res += current->data;
        current = current->next;
    }
    return res;
}

CharList::CharList(string s) { // constructor. Initializes the list to the contents of the string.
    header = new CLNode;
    trailer = new CLNode;
    header->next = trailer;
    trailer->prev = header;
    for (int i=0; i < s.size(); i++) {
        append(s[i]);
    }
}

CharList::~CharList() { // destructor. Returns all memory in the list.
    CLNode* current = header->next;
    while (current != trailer) {
        current = current->next;
        delete current->prev;
    }
    delete current;
    delete header;
    delete trailer;
}

void CharList::add(CLNode* v, const Elem& e) {
    CLNode* newnode = new CLNode;
    newnode->data = e;
    newnode->next = v;
    newnode->prev = v->prev;
    v->prev->next = newnode;
    v->prev = newnode;
}

void CharList::remove(CLNode* v) {
    CLNode* prev = v->prev;
    CLNode* next = v->next;
    prev->next = next;
    next->prev = prev;
    delete v;
}