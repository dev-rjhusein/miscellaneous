#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H	
#include "Employee.h"
#include <string>

class LinkedList {
private:
	struct Node {
		Employee empObj;
		struct Node *next;
	};
	Node *head;

public:
	//Constructor
	LinkedList();

	//Destructor
	~LinkedList();

	//Methods
	void add(Employee);
	void remove(int);
	int count();
	void print();
	void quit();
	bool findNumber(int);


};

#endif