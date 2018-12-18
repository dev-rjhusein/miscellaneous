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

//Overloaded Operators
std::ostream& operator<< (std::ostream& strm, Employee& obj) {
	strm << "Employee Number: " << obj.empNumber << std::endl
		<< "Employee Name: " << obj.empFirstName << " " << obj.empLastName << std::endl
		<< "Years of Service: " << obj.empYearsOfService << std::endl << std::endl;
	return strm;
}
bool Employee::operator > (Employee& right) {
	if (empNumber > right.empNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool Employee::operator < (Employee& right) {
	if (empNumber < right.empNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool Employee::operator == (Employee& right) {
	if (empNumber == right.empNumber) {
		return true;
	}
	else {
		return false;
	}
}

Employee Employee::operator= (Employee& right) {
	empNumber = right.empNumber;
	empFirstName = right.empFirstName;
	empLastName = right.empLastName;
	empYearsOfService = right.empYearsOfService;

	return *this;

}