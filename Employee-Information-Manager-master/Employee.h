#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
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

};



#endif
