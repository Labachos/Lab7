#include "Milk_Product.h"
#include <iostream>
#include <string>

using namespace std;

Milk_Product::Milk_Product()
{
	this->Product::prodType = 3;
	cout << "Milk Product constractes." << endl;
	this->prodType = 0;
    cout << "enter name: " << endl;
	getchar();
    getline(cin, this->name);
	cout << "enter the num of the colors on the packge ( > 1):" << endl;
	cin >> this->numOfColors;
	cout << "enter the perecent of body fat:( >= 5):" << endl;
	cin >> this->percentOfBodyFat;
	this->calculatePrice(1);
	cout << "**************************" << endl;
}

void Milk_Product::calculatePrice(int factor)
{
	//cout << "enter the factor:" << endl;
	//cin >> factor;
	if (this->prodType>0)
		this->price = (this->Product::getPrice() + (float)this->numOfColors + (float)this->percentOfBodyFat)*(float)this->prodType;
	else
		this->price = (this->Product::getPrice() + (float)this->numOfColors + (float)this->percentOfBodyFat);
}

void Milk_Product::print() const
{
	this->Product::print();
	cout << "Product Name: " << this->name << endl;
	cout << "the num of the coloros on product packge is: " << this->numOfColors << endl;
	cout << "the amount of the body fat perecent: " << this->percentOfBodyFat << endl;
	cout << "the item type: " << this->prodType << endl;
	cout << "**************************" << endl;
}