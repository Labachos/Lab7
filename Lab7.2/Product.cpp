#include "Product.h"

int Product::products = 100;

Product::Product()
{
	cout << "constracted Base Product." << endl;
	this->prodType = 0;
	this->serialNum = this->products++;
	this->price = 0;

	cout << "enter product row (between 'A' TO 'Z'):" << endl;
	cin >> this->row;

	cout << "enter shelf (between [1,5]):" << endl;
	cin >> this->shelf;
	
	cout << "enter the area (1,2,3):" << endl;
	cin >> this->area;
	
	cout << "enter the amount > 0 in KG:" << endl;
	cin >> this->amount;

	cout << "enter the price > 0 in $:" << endl;
	cin >> this->price;

	cout << "**************************" << endl;
}
void Product::print()const
{
	cout << "The serial number is: " << this->serialNum << endl;
	cout << "The item location is: " << endl;
	cout << "row: " << this->row << endl;
	cout << "shelf: " << this->shelf << endl;
	cout << "The amount of the item: " << this->amount << " KG" << endl;
	cout << "price: " << this->price << " $" << endl;
	cout << "The item type: " << this->prodType << endl;
	if (this->area == 1)
		cout << "The level of your item exposure: " << this->area << " is low a exposure" << endl;
	else if (this->area == 2)
		cout << "The level of your item exposure: " << this->area << " is medaium a exposure" << endl;
	else
		cout << "The level of your item exposure: " << this->area << " is high a exposure" << endl;
	cout << "**************************" << endl;
}

void Product::chageAmount()
{
	int num;
	this->price /= float(this->amount);
    cout << "enter the amount > 0 in KG:" << endl;
	cin >> this->amount;
	this->price *= float(this->amount);
	cout << "**************************" << endl;
}