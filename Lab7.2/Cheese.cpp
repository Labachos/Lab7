#include "Cheese.h"
#include <iostream>

using namespace std;

Cheese::Cheese()
{
	this->Milk_Product::prodType = 2;
	cout << "Constracted cheese product." << endl;
    cout << "enter the num of extras in the cheese:" << endl;
	cin >> this->numOfExtras;
	this->calculatePrice(1);
	cout << "**************************" << endl;
}

void Cheese::calculatePrice(int factor)
{
	//cout << "enter the factor:" << endl;
	//cin >> factor;
	this->Milk_Product::calculatePrice(factor);
	this->price = this->Milk_Product::getPrice() + float(this->numOfExtras);
}

void Cheese::print() const
{
	cout << "the item type: " << this->Milk_Product::prodType << endl;
	cout << "the num of extras in the cheese: " << this->numOfExtras << endl;
	cout << "**************************" << endl;
}