/*
 * Customer.h
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <iostream>

using namespace std;

class Customer {
public:
  // Default Constructor
	Customer();
 
  // Augmented Constructor
	Customer(string,char,int);

  // Getters and Setter for balance
	string getName() ;

	char getInitial() ;

	int getBalance() ;

	void setBalance(int amount);

  // Overloaded Comparison Operators
	bool operator<(const Customer& c) const;
  	bool operator<=(const Customer& c) const;
 	bool operator>(const Customer& c) const;
  	bool operator>=(const Customer& c) const;
  	bool operator==(const Customer& c) const;
  	bool operator!=(const Customer& c) const;
private:
	string lastName;
	char initial;
	int balance;

	friend ostream& operator<<(ostream & os,  Customer & c);

};

#endif /* CUSTOMER_H_ */
