/* This program simulates a cash register scanning and totalling process. It reads data from a text file in the order of:
<product number>, <product-description>, <price>, <tax-eligible symbol>
It validates all data before creating a groveryItem object and adding it to an inventory vector.
It allows a a user to enter a product number, and if found valid, enter a quantity.
If both numbers entered are valid, the corresponding grocery object is used to provide description, price, and tax eligibility.
The information is then printed to a text file and used as a receipt.
Author: Rami Husein
Date Created: 03/09/2018
Revisions: 1
Course: CISS 350
Week 1, Assignment 1*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "groceryItem.h"

using namespace std;

/***********************************************
************ Function Prototypes ***************
***********************************************/
//Read data from text file, validates it, stores valid data to grocery object and then to inventory vector
void ImportInventory(vector<groceryItem>&);

bool CheckProductNumber(string);	//Returns TRUE if product number is only numeric, exactly 5 digits, and not 0

bool CheckDuplicateNumber(vector<groceryItem>, string);		//Returns FALSE if product number already exists

bool CheckProductName(string);		//Returns FALSE if product name is more than 12 characters long

void ValidateProductName(string&);	//Erases any characters after the 12th character in product name

bool CheckProductPrice(string);		//Returns FALSE	if price is anything but digits or a "."

bool CheckProductTax(string);		//Returns TRUE ONLY IF 't' or 'T' is the first char of the tax string

bool CheckForYes(string);			//Returns TRUE if 'y' or 'Y' is the first char of the input string

bool StartAnotherCustomer();		//Returns TRUE if user indicates another customer

bool CheckQuantity(string);			//Returns TRUE if quantity entered is valid

void ScanNewProduct(vector<groceryItem>, int &, int &);		//Gets user input of product number and qty

void ProcessCustomerOrder(vector<groceryItem>);				//Compares user input vs inventory vector and prints accordingly to output file

groceryItem FindProduct(vector<groceryItem>, int);			//Returns a copy of the grocery object being searched for

/* Assign files to be used to a const string for easy change */
const string InventoryFile = "Invent.dat";
const string ReceiptFile = "Receipts.out.txt";

int main() {

	int customerNumber = 1;						//Track customers
	vector <groceryItem> groceryInventory;		//Holds inventory of grocery items
	string loopCheck;							//Used for user input to indicate loop or terminate 

	ImportInventory(groceryInventory);			//Imports the text data from file and construct a vector of grocery objects

	do {
		fstream outFile(ReceiptFile, ios::in | ios::out | ios::ate);		//Open output file

		outFile << "Customer " << customerNumber << endl;		//Write customer number to output file

		ProcessCustomerOrder(groceryInventory);		//Process all customer's grocery items

		customerNumber += 1;			//Increment customer number

		//Ask user to process another customer
		cout << "Check out another customer? Enter 'Y' or 'N'.\n";
		getline(cin, loopCheck);		

	} while (CheckForYes(loopCheck));
	
	return 0;
}

/*************************************************************
****** Import grocery info from file and save to vector ******
**************************************************************/
void ImportInventory(vector<groceryItem>&groceryList) {
	ifstream inFile;
	ofstream outFile;

	//Open necessary files
	inFile.open(InventoryFile);
	outFile.open(ReceiptFile);

	//Iterate through the input file
	while (!(inFile.eof())) {

		string strNum, strName, strPrice, strTax;

		inFile >> strNum;	//Read product number to string
		int productNumber;

		if (CheckProductNumber(strNum) && CheckDuplicateNumber(groceryList, strNum)) {	//Checks for product numebr validity
			productNumber = stoi(strNum);		//Convert product number string to int

			//Read product description, validate it, save it
			inFile >> strName;		
			string productName;
			if (CheckProductName(strName)) {
				productName.append(strName.begin(), strName.end());
			}
			else {
				ValidateProductName(strName);
				productName.append(strName.begin(), strName.end());
			}

			//Read product price, validate it, save it
			inFile >> strPrice;
			double productPrice;
			if (CheckProductPrice(strPrice)) {
				productPrice = stod(strPrice);
			}

			//Read product tax, validate it, save it
			inFile >> strTax;
			bool productTax = false;
			if (CheckProductTax(strTax)) {
				productTax = true;
			}

			//Make a grocery item with the validated input information
			groceryItem tempItem(productNumber, productName, productPrice, productTax);

			//Save the grocery item to the grocery inventory vector
			groceryList.push_back(tempItem);

			// Echo print it to the output file
			outFile << left << setw(8) << productNumber << setw(15) << productName << "\t" << productPrice << "\t" << strTax << endl;
			

		}
		// If the product number isn't valid, print error message to output file
		else {
			if (!CheckProductNumber(strNum)) {
				outFile << "***Inventory Import -- Product Number Invalid -- Change product number \"" << strNum << "\" to 5 numeric digits***";
			}
			else if (!CheckDuplicateNumber(groceryList, strNum)) {
				outFile << "***Inventory Import -- Product Number Invalid -- Product number \"" << strNum << "\" exists in file already***";
			}
			else {
				outFile << "***Inventory Import -- Product Number Invalid -- Reason Unknown***";
			}
			//Skip remaining data from output file (description, price, and tax)
			string skipData;
			inFile >> skipData;
			inFile >> skipData;
			inFile >> skipData;
			outFile << endl;
		}		
	}
	outFile << endl << endl << "---------------------------------------------------------------------------------------" << endl;

	//Close files
	inFile.close();
	outFile.close();
}
/****************************************************************
****** Confirm Product Number is only digits, and 5 digits ******
*****************************************************************/
// Returns TRUE is product number is valid
bool CheckProductNumber(string tempNumber) {
	if (tempNumber.size() == 5) {		//Check length
		for (int i = 0; i < 5; i++) {		
			if (!isdigit(tempNumber[i])) {		// Check digit value
				return false;
			}
		}
		if (stoi(tempNumber) == 0) {	// Check zero value
			return false;
		}
		return true;	//Return true if number is only digits, size of 5, and not a value of zero
	}
	else {
		return false;
	}
}
/**********************************************************
****** Confirm Product Name is no more than 12 chars ******
***********************************************************/
bool CheckProductName(string tempName) {
	if (tempName.size() > 0 && tempName.size() <= 12) {
		return true;
	}
	else {
		return false;
	}
}
/***********************************************************************
******* Confirm Product Price is a double with only digits or '.' ******
************************************************************************/
bool CheckProductPrice(string tempPrice) {
	for (int i = 0, j = tempPrice.size(); i < j; i++) {
		if ((isdigit(tempPrice[i])) || tempPrice[i] == '.') {
		}
		else {
			return false;
		}
	}
	return true;
}
/***************************************************************************
*** Confirm Product Tax (Returns false unless first or only char is 't') ***
****************************************************************************/
bool CheckProductTax(string tempTax) {
	if (tempTax.size() > 0) {
		if (isalpha(tempTax[0])) {
			if (toupper(tempTax[0]) == 'T') {
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
	else {
		return false;
	}
}

/**************************************************************************
***** If Product Name is longer than 12 chars, erase anything past 12 *****
***************************************************************************/
void ValidateProductName(string& tempName) {
	string newName;
	if (tempName.size() > 12) {
		tempName.erase(tempName.begin() + 12, tempName.end());
	}
}


/*************************************************************
****** Return TRUE if product numbers passed is unique *******
**************************************************************/
bool CheckDuplicateNumber(vector<groceryItem>list, string number) {
	for (int i = 0, j = list.size(); i < j; i++) {
		if (list[i].GetProductNumber() == stoi(number)) {	//Check each existing product number and compare
			return false;
		}
	}
	return true;
}

/*****************************************************
****** Return TRUE is quantity entered is valid ******
******************************************************/
bool CheckQuantity(string tempQty) {
	//Confirm only digits
	for (int i = 0, j = tempQty.size(); i < j; i++) {
		if (!isdigit(tempQty[i])) {
			return false;
		}
	}
	//Confirm (0 < qty < 101)
	int qty = stoi(tempQty);
	if (qty < 1 || qty > 100) {
		return false;
	}
	return true;
}

/**************************************************************
****** Return TRUE if first char in string is 'y' or 'Y' ******
***************************************************************/
bool CheckForYes(string checkStr) {
	if (checkStr.size() > 0) {
		if (isalpha(checkStr[0])) {
			if (toupper(checkStr[0]) == 'Y') {
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
	else {
		return false;
	}
}

/*****************************************************************************
****** Return TRUE if customer indicates intent to process new customer ******
******************************************************************************/
bool StartAnotherCustomer() {
	cout << "Check out another customer? Enter 'Y' or 'N'" << endl;
	string strReply;
	getline(cin, strReply);

	//Only check first character
	char charReply = strReply[0];
	if (toupper(charReply) == 'Y') {
		return true;
	}
	else {
		return false;
	}
}

/********************************************************************
****** Changes value ProductNumber(choice) and ProductQty(qty) ******
*********************************************************************/
void ScanNewProduct(vector<groceryItem> groceryList, int & choice, int & qty) {
	cout << "Please enter the 5 digit numeric product number for the grocery item or '0' to cancel: ";
	string newProductNumber;
	getline(cin, newProductNumber);

	if (newProductNumber == "0") {		//Exits scanner process
		choice = stoi(newProductNumber);
	}
	else {
		//Check Product Number validity, loop until correct
		while (!CheckProductNumber(newProductNumber) || CheckDuplicateNumber(groceryList, newProductNumber)) {
			if (!CheckProductNumber(newProductNumber)) {
				cout << "That is not a valid, 5 numeric digit only number. Please try again:" << endl;
				getline(cin, newProductNumber);
			}
			else {
				cout << "That product number doesn't exist in this store. Please try again:" << endl;
				getline(cin, newProductNumber);
			}
		}
		choice = stoi(newProductNumber);	//Save valid product number string to int

		cout << "Please enter the quantity of the item(s) being purchased:";
		string newProductQty;
		getline(cin, newProductQty);

		//Check Product Quantity validty, loop until correct
		while (!CheckQuantity(newProductQty)) {
			cout << "That is not a valid quantity. Please enter a number from 1 to 100: ";
			getline(cin, newProductQty);
		}
		qty = stoi(newProductQty);		//Save valid quantity string to int
	}	
}

/**************************************************************************
****** Returns copy of grocery object searched for by product number ******
***************************************************************************/
groceryItem FindProduct(vector<groceryItem> groceryInventory, int lookupNumber) {
	for (int i = 0, j = groceryInventory.size(); i < j; i++) {
		if (groceryInventory[i].GetProductNumber() == lookupNumber) {
			return groceryInventory[i];
		}
	}
}

/*******************************************************************************
****** Runs ScanNewProduct function and prints to output file accordingly ******
********************************************************************************/
void ProcessCustomerOrder(vector<groceryItem> groceryInventory) {
	string loopCheck;
	double runningSubTotal = 0.0;
	double runningTax = 0.0;
	
	fstream outFile(ReceiptFile, ios::in | ios::out | ios::ate);

	int productChoice;
	int productQty;
	double productSubTotal;

	do {
		ScanNewProduct(groceryInventory, productChoice, productQty);

		if (productChoice == 0) {	//Exit if user doesn't want to scan new item
			break;
		}

		groceryItem *searchItem = new groceryItem(FindProduct(groceryInventory, productChoice));

		productSubTotal = searchItem->GetProductPrice() * productQty;
		runningSubTotal += productSubTotal;


		outFile << left << setw(13) << searchItem->GetProductName() << setw(5) << productQty << "\t" << "@"
			<< "\t" << searchItem->GetProductPrice() << "\t" << fixed << setprecision(2) << productSubTotal;

		if (searchItem->GetProductTax()) {
			runningTax += productSubTotal * .075;
			outFile << "*";
		}
		outFile << endl;
	
		cout << "Scan another item? Enter 'Y' or 'N'.\n";
		getline(cin, loopCheck);
	} while (CheckForYes(loopCheck));
	
	outFile << "\t" << "Subtotal: $" << fixed << setprecision(2) << setfill('0') << runningSubTotal << endl
		<< "\t" << "Tax: $" << fixed << setprecision(2) << setfill('0') << runningTax << endl
		<< "\t" << "Total: $" << fixed << setprecision(2) << setfill('0') << runningSubTotal + runningTax << endl;
	outFile.close();
}