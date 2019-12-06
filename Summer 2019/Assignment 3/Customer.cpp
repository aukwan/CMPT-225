/*
 * Customer.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "Customer.h"
#include <string>
#include <iostream>

using namespace std;

// Default Constructor
Customer::Customer() {
    lastName = "";
    initial = ' ';
    balance = 0;
}

// Augmented Constructor
Customer::Customer(string x, char y, int z) {
    lastName = x;
    initial = y;
    balance = z;
}


// Getters and Setter for balance
string Customer::getName()   {
    return this->lastName;
}

char Customer::getInitial() {
    return this->initial;
}

int Customer::getBalance()  {
    return this->balance;
}

void Customer::setBalance(int amount) {
    this->balance = amount;
}

// Overloaded Comparison Operators
bool Customer::operator<(const Customer& c) const {
    if (lastName < c.lastName) {
      return true;
    } else if (lastName == c.lastName) {
      if (initial < c.initial) {
      return true;
      } else {
        return false;
      }
    }
    return false;
}
bool Customer::operator<=(const Customer& c) const {
    if (lastName < c.lastName) {
      return true;
    } else if (lastName == c.lastName) {
      if (initial < c.initial) {
      return true;
      }
    }
    if ((lastName == c.lastName) && (initial == c.initial)) {
      return true;
    }
    return false;
}
bool Customer::operator>(const Customer& c) const {
    if (lastName > c.lastName) {
      return true;
    } else if (lastName == c.lastName) {
      if (initial > c.initial) {
      return true;
      }
    }
    return false;
}
bool Customer::operator>=(const Customer& c) const {
    if (lastName > c.lastName) {
      return true;
    } else if (lastName == c.lastName) {
      if (initial > c.initial) {
      return true;
      }
    } 
    if ((lastName == c.lastName) && (initial == c.initial)) {
        return true;
    }
    return false;
}
bool Customer::operator==(const Customer& c) const  {
    return (lastName == c.lastName) && (initial == c.initial); 
}
bool Customer::operator!=(const Customer& c) const  {
    return (lastName != c.lastName) || (initial != c.initial);
}

// Printing a Customer object
ostream& operator<<(ostream & os,  Customer & c) {
    os << c.lastName << ", " << c.initial << ". " << "(" << c.balance << ")";
}
