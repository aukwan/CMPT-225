/*
 * Patient.cpp
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author:Austin Kwan
 * Date:1/9/2019
 */

// You can add #include statements if you wish.
#include <iostream>
#include <string>
#include "Patient.h"
#include <locale>

// Default Constructor
// Description: Create a patient with a care card number of "0000000000". 
// Postcondition: All data members set to "To be entered", 
//                except the care card number which is set to "0000000000".       
Patient::Patient() {
	
// You need to complete this method.
	name="To be entered";
	address="To be entered";
	phone="To be entered";
	email="To be entered";
	careCard="0000000000";
}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard) {
	
// You need to complete this method.
	name="To be entered";
	address="To be entered";
	phone="To be entered";
	email="To be entered";
	careCard=(aCareCard.length() != 10) ? "0000000000" : aCareCard;
}

// Getters and setters -> You need to implement these methods.

// Description: Return patient's name.
string Patient::getName() const {
	return name;
}

// Description: Return patient's address.
string Patient::getAddress() const {
	return address;
}

// Description: Return patient's phone number.
string Patient::getPhone() const {
	return phone;
}

// Description: Return patient's email.
string Patient::getEmail() const {
	return email;
}

// Description: Return patient's care card number.
string Patient::getCareCard() const {
	return careCard;
}

// Description: Set the patient's name.
void Patient::setName(const string aName) {
	name=aName;
}

// Description: Set the patient's address.
void Patient::setAddress(const string anAddress) {
	address=anAddress;
}

// Description: Set the patient's phone number.
void Patient::setPhone(const string aPhone) {
	phone=aPhone;
}

// Description: Set the patient's email.
void Patient::setEmail(const string anEmail) {
	email=anEmail;
}

// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient & rhs) {
	
	// Compare both Patient objects
	if (this->careCard == rhs.getCareCard() ) 
		return true;
	else 
		return false;
	
} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card 
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs) {
	
	// Compare both Patient objects
	if (this->careCard > rhs.getCareCard() ) 
		return true;
	else 
		return false;
	
} // end of operator >


// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Patient & p) {
	
// You need to complete this method.   
	os << p.getCareCard() << " - Patient: " << p.getName() << ", " << p.getAddress() << ", " << p.getPhone() << ", " << p.getEmail() << endl;     
	return os;

} // end of operator<<

// end of Patient.cpp