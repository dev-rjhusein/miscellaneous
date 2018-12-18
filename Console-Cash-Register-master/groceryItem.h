/* This is a header file for the grocery item class */
#pragma once
#ifndef GROCERYITEM_H
#define GROCERYITEM_H

#include <string>
#include <iostream>

using namespace std;

class groceryItem {
public:
	groceryItem(int, string, double, bool);
	void SetProductNumber(int);
	void SetProductName(string);
	void SetProductPrice(double);
	void SetProductTax(bool);

	int GetProductNumber();
	string GetProductName();
	double GetProductPrice();
	bool GetProductTax();

private:
	int productNumber;
	string productName;
	double productPrice;
	bool productTax;
};


#endif

