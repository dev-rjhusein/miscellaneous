/* This program reads data from a text file in the order of <Employee Number> | <First Name> | <Last Name> | <Years of Service>
It validates the data and only uses valid data to create employee objects and appends them to a linked list.
The program then allows the user to PRINT all the data, COUNT the number of nodes in the list, REMOVE a node based
on a matching employee number, and exit the program. All user input should be validated before calloing any functions.
Author:			Rami Husein
Date Created:	03/13/2018
Revisions:		0
Course: CISS 350
Week 2, Assignment 1
*/

#include "Employee.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//Function Prototypes
bool validateInteger(string);
bool validateEmployeeNumber(string);
bool validateEmployeeYears(string);
bool validateEmployeeName(string);

void setEmployeeInfo(LinkedList&);

//Menu Constants
const int PRINT = 1;
const int COUNT = 2;
const int REMOVE = 3;
const int EXIT = 0;

int main() {
	LinkedList listOfEmployees;			//For storing employee objects

	setEmployeeInfo(listOfEmployees);	//Read data from file

	listOfEmployees.print();			//Display all valid employees

	int choice;

	do {
		//Display the menu
		cout << endl << "Please enter the corresponding number to the choice you'd like to make, then press [Enter]." << endl
			<< PRINT << ") Print information for all employees in the system." << endl
			<< COUNT << ") Display the number of employees in the system." << endl
			<< REMOVE << ") Remove an employee by their employee number." << endl
			<< EXIT << ") Exit the program." << endl;

		string userChoice;
		getline(cin, userChoice);

		while (!validateInteger(userChoice)) {
			cout << "That is not a valid entry. Please enter a single digit, numeric choice from the above menu.\n";
			getline(cin, userChoice);
		}

		choice = stoi(userChoice);		//Convert valid user choice to int for use in switchs statement

		string userRemove;

		switch (stoi(userChoice)) {
		case PRINT:
			cout << string(50, '\n');
			listOfEmployees.print();
			break;

		case COUNT:
			cout << string(50, '\n');
			cout << "There are " << listOfEmployees.count() << " employees in the system." << endl << endl;
			break;

		case REMOVE:
			cout << string(50, '\n');
			listOfEmployees.print();
			cout << "Enter the employee number of the employee you'd like to remove: ";
			getline(cin, userRemove);
			while (!validateEmployeeNumber(userRemove)) {
				cout << "That is not a valid number. Enter a 5 digit, numeric only number: ";
				getline(cin, userRemove);
			}
			while (!listOfEmployees.findNumber(stoi(userRemove))) {
				cout << "That employee number doesn't exist within the system." << endl;
				break;
			}
			listOfEmployees.remove(stoi(userRemove));
			break;

		case EXIT:
			cout << string(50, '\n');
			break;

		default:
			cout << string(50, '\n');
			cout << "You did not make a valid choice. Please enter a valid choice from the menu below: " << endl;
			break;
		}
	} while (choice != EXIT);

	cout << "Program Ended. Goodbye!";



	return 0;
}
// Function Definitions

/****************************************************************************************************************
Confirm that the arg string is a digit-only integer, return false otherwise
****************************************************************************************************************/
bool validateInteger(string strInt) {
	if (strInt.size() == 0) {
		return false;
	}
	for (int i = 0, j = strInt.size(); i < j; i++) {
		if (!(isdigit(strInt[i]))) {
			return false;
		}
	}
	if (stoi(strInt) < 0) {
		return false;
	}
	return true;
}

/****************************************************************************************************************
Confirm that the arg string is an int and only 5 digits, return false otherwise
****************************************************************************************************************/
bool validateEmployeeNumber(string empNum) {
	if (validateInteger(empNum)) {
		if (empNum.size() == 5) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

/****************************************************************************************************************
Confirm that the arg string is an int and is less than 72 (only employ age 18 - 90), return false otherwise
****************************************************************************************************************/
bool validateEmployeeYears(string empYears) {
	if (validateInteger(empYears)) {
		if (stoi(empYears) >= 72) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}

/****************************************************************************************************************
Confirm that the arg string (a name) is only alphabetic and less than 26 chars, return false otherwise
****************************************************************************************************************/
bool validateEmployeeName(string empName) {
	int j = empName.size();
	if (j < 26) {
		for (int i = 0; i < j; i++) {
			if (!(isalpha(empName[i]))) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

/****************************************************************************************************************
Read data from "Employee.txt" and validate it. Create employee objects from only valid information. ConsoleOUT any errors
****************************************************************************************************************/
void setEmployeeInfo(LinkedList &empList) {
	int count = 0;
	string skipData;

	ifstream inFile;
	inFile.open("Employee.txt");
	cout << "Reading employee information from \"Employee.txt\"....\n";

	while (!inFile.eof()) {
		count += 1;
		string empNum, firstName, lastName, empYears;
		inFile >> empNum;

		if (validateEmployeeNumber(empNum)) {
			int num = stoi(empNum);
			inFile >> firstName;

			if (validateEmployeeName(firstName)) {
				inFile >> lastName;

				if (validateEmployeeName(lastName)) {
					inFile >> empYears;

					if (validateEmployeeYears(empYears)) {
						int years = stoi(empYears);
						Employee tempEmp(num, firstName, lastName, years);
						empList.add(tempEmp);
					}
					else {
						cout << "Error - Number of service years for employee " << count << " must be between 0 and 72. Skipping entry...\n";
					}
				}
				else {
					cout << "Error - Employee " << count << "'s last name must be less than 26 characters and only alphabetic. Skipping entry...\n";
					inFile >> skipData;
				}
			}
			else {
				cout << "Error - Employee " << count << "'s first name must be less than 26 characters and only alphabetic. Skipping entry...\n";
				inFile >> skipData;
				inFile >> skipData;
			}
		}
		else {
			cout << "Error - Employee number for employee " << count << " must be exactly 5 numeric digits. Skipping entry...\n";
			inFile >> skipData;
			inFile >> skipData;
			inFile >> skipData;
		}
	}
	inFile.close();
	cout << "\nAll valid employees have been added to the system!\n\n";
}