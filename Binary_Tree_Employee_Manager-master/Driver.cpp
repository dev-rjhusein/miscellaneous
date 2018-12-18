/*This program demonstrates the basic functionality of a template binary search tree, by utilizing the self-define Employee class
as well as an "Employee.txt" import file that consists of arbitrary information of "Employees".
The driver program creates a binary tree of Employee types and populates it with the Employee.txt file.
The user can then add/remove employees and either count or display all employees.
Author: Rami Husein
Date Created: 04/14/2018
Revisions: 1
Course:CISS 350
Week 6
*/
#include <iostream>
#include <fstream>
#include <string>
#include "BinaryTree.h"
#include "Employee.h"

using namespace std;

/* MENU OPTION CONSTANTS */
const int ADD = 1;
const int REMOVE = 2;
const int COUNT = 3;
const int PRINT = 4;
const int QUIT = 0;

/* FUNCTION PROTOTYPES */
void DisplayUserMenu();
int GetUserChoice();

void AddEmployee(BinaryTree<Employee>&);
void RemoveEmployee(BinaryTree<Employee>&);
void CountEmployees(BinaryTree<Employee>&);
void PrintEmployees(BinaryTree<Employee>&);

void ImportEmployees(BinaryTree<Employee>&);
bool ValidateInteger(string);
bool ValidateEmployeeNumber(string);
bool ValidateEmployeeYears(string);
bool ValidateEmployeeName(string);


/* MAIN DRIVER */
int main() {
	BinaryTree<Employee> empTree;

	ImportEmployees(empTree); //uses "Employee.txt" for import

	DisplayUserMenu();
	do {
		
		switch (GetUserChoice()) {
		case ADD:
			AddEmployee(empTree);
			break;
		case REMOVE:
			RemoveEmployee(empTree);
			break;
		case COUNT:
			CountEmployees(empTree);
			break;
		case PRINT:
			PrintEmployees(empTree);
			break;
		case QUIT:
			cout << "Goodbye!";
			return 0;
			break;
		default:
			break;
		}
		DisplayUserMenu();
	} while (GetUserChoice());

	return 0;
}
// Function Definitions
/****************************************************************************************************************
Insert multple newlines to "clear" console
****************************************************************************************************************/
void clearScreen() {
	string(50 , '\n');
}
/****************************************************************************************************************
Display options of driver program
****************************************************************************************************************/
void DisplayUserMenu() {
	cout << "Would you like to:" << endl
		<< ADD << ") Add a new employee." << endl
		<< REMOVE << ") Remove an existing employee." << endl
		<< COUNT << ") Count the number of existing employees." << endl
		<< PRINT << ") Display all existing employees." << endl
		<< QUIT << ") Exit." << endl;
}
/****************************************************************************************************************
Accept user input for menu choice
****************************************************************************************************************/
int GetUserChoice() {

	bool invalidChoice = true;
	string strChoice;
	getline(cin, strChoice);

	while (invalidChoice) {
		invalidChoice = false;
		if (!ValidateInteger(strChoice)) {
			invalidChoice = true;
			cout << "Invalid Entry. Try Again:";
			getline(cin, strChoice);
		}
		else if (stoi(strChoice) < 0 || stoi(strChoice) > 4) {
			invalidChoice = true;
			cout << "Invalid Menu Option. Try Again:";
			getline(cin, strChoice);
		}
	}
	return stoi(strChoice);
}

/****************************************************************************************************************
User insert new employee
****************************************************************************************************************/
void AddEmployee(BinaryTree<Employee>& tree) {

	string number, first, last, years;

	cout << "Enter the employee number:";
	getline(cin, number);
	while (!ValidateEmployeeNumber(number)) {
		cout << "Invalid Number. Try Again: ";
		getline(cin, number);
	}

	cout << "Enter the employee's first name:";
	getline(cin, first);
	while (!ValidateEmployeeName(first)) {
		cout << "Invalid Name. Try Again:";
		getline(cin, first);
	}

	cout << "Enter the employee's last name:";
	getline(cin, last);
	while (!ValidateEmployeeName(last)) {
		cout << "Invalid Name. Try Again:";
		getline(cin, last);
	}

	cout << "Enter the employee's years of service:";
	getline(cin, years);
	while (!ValidateEmployeeYears(years)) {
		cout << "Invalid Entry. Try Again:";
		getline(cin, years);
	}

	Employee tempEmp(stoi(number), first, last, stoi(years));
	tree.insertNode(tempEmp);
}

/****************************************************************************************************************
User remove employee by employee number
****************************************************************************************************************/
void RemoveEmployee(BinaryTree<Employee>& tree) {
	string number;
	cout << "Enter the employee number of the employee you'd like to remove:";
	getline(cin, number);
	while (!ValidateEmployeeNumber(number)) {
		cout << "Invalid Number. Try Again:";
		getline(cin, number);
	}

	Employee tempEmp;
	tempEmp.setEmpNumber(stoi(number));

	tree.remove(tempEmp);
}

/****************************************************************************************************************
Output number of nodes (employees) in tree
****************************************************************************************************************/
void CountEmployees(BinaryTree<Employee> &tree) {
	cout << "There are " << tree.totalNodeCounter(tree.getRoot()) << " employee(s) in the system." << endl;
}

/****************************************************************************************************************
Display all node information (employees)
****************************************************************************************************************/
void PrintEmployees(BinaryTree<Employee> &tree) {
	tree.displayInOrder();
}

/****************************************************************************************************************
Confirm that the arg string is a digit-only integer, return false otherwise
****************************************************************************************************************/
bool ValidateInteger(string strInt) {
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
bool ValidateEmployeeNumber(string empNum) {
	if (ValidateInteger(empNum)) {
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
bool ValidateEmployeeYears(string empYears) {
	if (ValidateInteger(empYears)) {
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
bool ValidateEmployeeName(string empName) {
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
void ImportEmployees(BinaryTree<Employee>& tree) {
	int count = 0;
	string skipData;

	ifstream inFile;
	inFile.open("Employee.txt");
	cout << "Reading employee information from \"Employee.txt\"....\n";

	while (!inFile.eof()) {
		count += 1;
		string empNum, firstName, lastName, empYears;
		inFile >> empNum;

		if (ValidateEmployeeNumber(empNum)) {
			int num = stoi(empNum);
			inFile >> firstName;

			if (ValidateEmployeeName(firstName)) {
				inFile >> lastName;

				if (ValidateEmployeeName(lastName)) {
					inFile >> empYears;

					if (ValidateEmployeeYears(empYears)) {
						int years = stoi(empYears);
						Employee tempEmp(num, firstName, lastName, years);
						tree.insertNode(tempEmp);
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
