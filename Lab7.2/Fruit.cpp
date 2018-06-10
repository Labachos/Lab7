#include "Fruit.h"
#include <iostream>

using namespace std;

Fruit::Fruit()
{
	this->Farm_Product::prodType = 2;
	cout << "constracted fruit." << endl;
	cout << "enter the num of sugar (1 to 100 grams):" << endl;
	cin >> this->numOfSugars;
	this->calculatePrice(1);
	cout << "**************************" << endl;
}
void Fruit::calculatePrice(int factor)
{
	//cout << "enter the factor > 0:" << endl;
	//cin >> factor;
	this->Farm_Product::calculatePrice(factor);
	this->price = this->Farm_Product::getPrice() + (this->numOfSugars / 2);
}
void Fruit::print() const
{
	this->Farm_Product::print();
	cout << "The num of suger in the fruit: " << this->numOfSugars << "g" << endl;
	cout << "**************************" << endl;
}