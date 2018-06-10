#include "Vegetable.h"
#include <iostream>

Vegetable::Vegetable()
{
	this->Farm_Product::prodType = 1;
	cout << "constracted vagetable product." << endl;
	cout << "enter the num of the vitamins in the vegetable:" << endl;
	cin >> this->numOfVitamins;
	this->calculatePrice(1);
	cout << "*********************************" << endl;
}

void Vegetable::calculatePrice(int factor)
{
	//cout << "enter the factor:" << endl;
	//cin >> factor;
	this->Farm_Product::calculatePrice(factor);
	this->price = this->Farm_Product::getPrice() + (float)(this->numOfVitamins * 2);
}
void Vegetable::print() const
{
	this->Farm_Product::print();
	cout << "the num of the vitamins is: " << this->numOfVitamins << endl;
	cout << "*********************************" << endl;
}