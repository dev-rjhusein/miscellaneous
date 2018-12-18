#include "Employee.h"


//Default Constructor
Employee::Employee() {
	empNumber = 0;
	empFirstName = "";
	empLastName = "";
	empYearsOfService = 0;
}

//Overloaded Constructor
Employee::Employee(int empNum, std::string first, std::string last, int years) {
	empNumber = empNum;
	empFirstName = first;
	empLastName = last;
	empYearsOfService = years;
}

//Mutators
void Employee::setEmpNumber(int empNum) {
	empNumber = empNum;
}
void Employee::setEmpFirstName(std::string empFirst) {
	empFirstName = empFirst;
}
void Employee::setEmpLastName(std::string empLast) {
	empLastName = empLast;
}
void Employee::setEmpYears(int empYears) {
	empYearsOfService = empYears;
}

//Accessors
int Employee::getEmpNumber() {
	return empNumber;
}
std::string Employee::getEmpFirstName() {
	return empFirstName;
}
std::string Employee::getEmpLastName() {
	return empLastName;
}
int Employee::getEmpYears() {
	return empYearsOfService;
}