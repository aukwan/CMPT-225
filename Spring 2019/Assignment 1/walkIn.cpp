/*
 *walkIn.cpp
 *
 *
 * Class Description: Models a walk-in clinic patient system.
 *
 *Author:Austin Kwan
 *Date:1/9/2019
 */

#include <iostream>
#include "Patient.h"
#include "List.h"

using namespace std;

// Add a new patient to the system
void add(List& newpatient) {
	string input;
	cout << "Please enter a 10-digit care card number:" << endl;
	cin >> input;
	Patient newp = Patient(input);
	bool check= newpatient.insert(newp);
	if (!check) {
		cout << "Patient is already in the system." << endl;
	} else {
		cout << " New patient added." << endl;
		newpatient.printList();
	}
}

// Remove a patient from the system
void remove(List& removepatients) {
	string input;
	cout << "Enter the 10-digit care card of the patient you wish to remove:" << endl;
	cin >> input;
	Patient oldp = Patient(input);
	bool check = removepatients.remove(oldp);
	if (!check) {
		cout << "Patient is not in the system." << endl;
	} else {
		cout << "Patient is now removed." << endl;
		removepatients.printList();
	}
}

// Updating/Changing a patient's info
void update(List& patients) {
	string input;
	cout << "Enter the 10-digit care card number of the patient:" << endl;
	cin >> input;
	Patient find = Patient(input);
	Patient* findp = patients.search(find);
	if (findp==NULL) {
		cout << "Patient is not in the system." << endl;
	} else {
		bool edit= false;
		while (not edit) {
			char select;
			string newinfo;
			cout << "What needs to be changed?" << endl;
			cout << "N for Name, E for Email, P for Phone, A for Address, or X to finish editing" << endl;
			cin >> select;
			cin.ignore();
			switch (select) {
				case 'N' :
					cout << "Enter the new name." << endl;
					getline(cin, newinfo);
					findp->setName(newinfo);
					break;
				case 'E' :
					cout << "Enter the new email." << endl;
					cin >> newinfo;
					findp->setEmail(newinfo);
					break;
				case 'P' :
					cout << "Enter the new phone number." << endl;
					getline(cin, newinfo);
					findp->setPhone(newinfo);
					break;
				case 'A' :
					cout << "Enter the new address." << endl;
					getline(cin, newinfo);
					findp->setAddress(newinfo);
					break;
				case 'X' :
					cout << "The info has been updated: ";
					cout << findp;
					edit = true;
					break;
				default:
					cout << "That is not an option, please try again" << endl;
			}
		}
	}
}

// Checking if a patient is in the system or not
void search(List& patients) {
	string input;
	cout << "Enter the 10-digit care card number you are looking for:" << endl;
	cin >> input;
	Patient find= Patient(input);
	Patient* findp= patients.search(find);
	if (findp==NULL) {
		cout << "This patient is not in the system." << endl;
	} else {
		cout << "This patient is in the system." << endl;
	}
}

// Displaying all patients in the system
void printAll(List& patients) {
	if (patients.getElementCount() == 0) {
		cout << "There are no patients in the system." << endl;
	} else {
		cout << "List of all patients: " << endl;
    patients.printList();
	}
}

int main() {

	List patients = List();
	bool finish = false;
	char input;
	cout << " Welcome to Walk-In Clinic System! " << endl;
	while (not finish) {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Options:" << endl;
		cout << "To add a new patient, please enter: N" << endl;
		cout << "To remove a patient from the system, please enter: R" << endl;
		cout << "To update the info of a patient, please enter: U" << endl;
		cout << "Checking if a patient is in the system, please enter: S" << endl;
		cout << "To see all patients in the system, please enter: A" << endl;
		cout << "To exit, please enter: E" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cin >> input;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;   
		
		switch(input) {
			case 'N' : add(patients); break;
			case 'R' : remove(patients); break;
			case 'U' : update(patients); break;
			case 'S' : search(patients); break;
			case 'A' : printAll(patients); break;
			case 'E' : cout << "Thank you for using Walk-In Clinic System! Bye!" << endl; finish= true; break;
			default: cout << "That is not an option, please try again." << endl;
		}
	}
	return 0;
}