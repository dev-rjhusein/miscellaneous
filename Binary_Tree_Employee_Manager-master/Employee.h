#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>

class Employee {
private:
	int empNumber;
	std::string empFirstName;
	std::string empLastName;
	int empYearsOfService;

public:
	//Constructor(s)
	Employee();
	Employee(int, std::string, std::string, int);

	//Copy Constructor
	Employee(const Employee &obj) {
		empNumber = obj.empNumber;
		empFirstName = obj.empFirstName;
		empLastName = obj.empLastName;
		empYearsOfService = obj.empYearsOfService;
	}

	//Mutators
	void setEmpNumber(int);
	void setEmpLastName(std::string);
	void setEmpFirstName(std::string);
	void setEmpYears(int);
	
	//Accessors
	int getEmpNumber();
    std::string getEmpFirstName();
	std::string getEmpLastName();
	int getEmpYears();

	//Overloaded Operators
	friend std::ostream& operator<< (std::ostream&, Employee&);
	bool operator > (Employee&);
	bool operator < (Employee&);
	bool operator == (Employee&);
	Employee operator = (Employee&);

};



#endif
