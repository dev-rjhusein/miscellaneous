#include "LinkedList.h"
#include <iostream>

/****************************************************************************************************************
List constructor
****************************************************************************************************************/
LinkedList::LinkedList() {
	head = nullptr;
}

/****************************************************************************************************************
List destructor
****************************************************************************************************************/
LinkedList::~LinkedList() {
	Node *currentNode = nullptr;
	Node *nextNode = nullptr;

	currentNode = head;
	if (currentNode != nullptr) {
		nextNode = currentNode->next;
	}

	while (currentNode != nullptr) {
		nextNode = nextNode->next;
		delete currentNode;
		currentNode = nextNode;
	}
}

/****************************************************************************************************************
 Create a node and add an employee object to it
 ****************************************************************************************************************/
void LinkedList::add(Employee newObj) {
	Node *newNode;
	Node *currentNode;

	newNode = new Node;

	
	newNode->empObj.setEmpNumber(newObj.getEmpNumber());
	newNode->empObj.setEmpFirstName(newObj.getEmpFirstName());
	newNode->empObj.setEmpLastName(newObj.getEmpLastName());
	newNode->empObj.setEmpYears(newObj.getEmpYears());

	newNode->next = nullptr;


	if (!head) {
		head = newNode;
	}
	else {
		currentNode = head;
		while (currentNode->next) {
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}
}


/****************************************************************************************************************
Delete an entire node if the emp number of the search employee matches
****************************************************************************************************************/
void LinkedList::remove(int searchNum) {
	Node *previousNode = nullptr;
	Node *currentNode;

	//Exit if no list exists
	if (!head) {
		return;
	}

	//If the first node holds the information to be deleted
	if (head->empObj.getEmpNumber() == searchNum) {
		currentNode = head->next;
		delete head;
		head = currentNode;
	}
	else {
		currentNode = head;

		while (currentNode && currentNode->empObj.getEmpNumber() != searchNum) {
			previousNode = currentNode;
			currentNode = currentNode->next;
		}
		if (currentNode->empObj.getEmpNumber() == searchNum) {
			previousNode->next = currentNode->next;
			delete currentNode;
		}
		else {
			std::cout << "Search content doesn't exist." << std::endl;
		}
	}
}


/****************************************************************************************************************
Traverse through the list, incrementing 'count' by one until the end. Return the 'count'
****************************************************************************************************************/
int LinkedList::count() {
	Node *currentNode;
	int count = 0;

	currentNode = head;

	while (currentNode) {
		count += 1;
		currentNode = currentNode->next;
	}

	return count;

}


/****************************************************************************************************************
Traverse the list, printing each member of each object in each node
****************************************************************************************************************/
void LinkedList::print() {
	Node *currentNode;
	int count = 0;

	if (!head) {
		std::cout << "There are no employees in the system." << std::endl;
	}
	
	currentNode = head;

	while (currentNode) {
		count += 1;
		std::cout << std::endl << count << ")" << std::endl
			<< "Employee Number: " << currentNode->empObj.getEmpNumber() << std::endl
			<< "Employee Name: " << currentNode->empObj.getEmpFirstName() << " " << currentNode->empObj.getEmpLastName() << std::endl
			<< "Years of employee service: " << currentNode->empObj.getEmpYears() << std::endl;

		currentNode = currentNode->next;
	}

	std::cout << "\nEnd of employee list." << std::endl;
}


/****************************************************************************************************************

****************************************************************************************************************/
void LinkedList::quit() {
	
}


/****************************************************************************************************************
Search for a duplicate product number and return true if it exists
****************************************************************************************************************/
bool LinkedList::findNumber(int searchNum) {
	Node *previousNode = nullptr;
	Node *currentNode;

	//Exit if no list exists
	if (!head) {
		return false;
	}

	//If the first node holds the information to be deleted
	if (head->empObj.getEmpNumber() == searchNum) {
		return true;
	}
	else {
		currentNode = head;

		while (currentNode && currentNode->empObj.getEmpNumber() != searchNum) {
			previousNode = currentNode;
			currentNode = currentNode->next;
		}
		if (currentNode->empObj.getEmpNumber() == searchNum) {
			return true;
		}
		else {
			return false;
		}
	}
}
