#include "Farm_Product.h"
#include <iostream>

using namespace std;

Farm_Product::Farm_Product()
{
	this->Product::prodType = 1;
	this->prodType = 0;
	cout << "Constracted farm product." << endl;
	cout << "enter name:" << endl;
	getchar();
	getline(cin, this->name);
	cout << "enter the time of ripening (in seasons):" << endl;
	cin >> this->timeOfRipening;
	cout << "eneter the Num of suppliers (bigger than 1):" << endl;
	cin >> this->numOfSuppliers;
	this->calculatePrice(1);
	cout << "**************************" << endl;
}

void Farm_Product::calculatePrice(int factor)
{
	//cout << "enter the factor:" << endl;
	//cin >> factor;
	this->price = (this->Product::getPrice() * 3 * 5 - this->timeOfRipening) + this->numOfSuppliers * 5 + this->prodType;
}

void Farm_Product::print() const
{
	this->Product::print();
	cout << "the item name: " << this->name << endl;
	cout << "the time of item ripening (in seansons) : " << this->timeOfRipening << endl;
	cout << "the num of item suppilers is: " << this->numOfSuppliers << endl;
	cout << "the item type: " << this->prodType << endl;
	cout << "**************************" << endl;
}