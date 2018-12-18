/* This is the implementation file for the grocery item class */
#include "groceryItem.h"

groceryItem::groceryItem(int tempNumber, string tempName, double tempPrice, bool tempTax) {
	productNumber = tempNumber;
	productName = tempName;
	productPrice = tempPrice;
	productTax = tempTax;
}

void groceryItem::SetProductNumber(int tempNumber) {
	productNumber = tempNumber;

}
void groceryItem::SetProductName(string tempName) {
	productName = tempName;

}
void groceryItem::SetProductPrice(double tempPrice) {
	productPrice = tempPrice;

}
void groceryItem::SetProductTax(bool tempTax) {
	productTax = tempTax;

}

int groceryItem::GetProductNumber() {
	return productNumber;
}
string groceryItem::GetProductName() {
	return productName;
}
double groceryItem::GetProductPrice() {
	return productPrice;
}
bool groceryItem::GetProductTax() {
	return productTax;
}