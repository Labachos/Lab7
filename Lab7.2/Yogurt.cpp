#include "Yogurt.h"



Yogurt::Yogurt()
{
	cout << "constracted yogurt." << endl;
	this->Milk_Product::prodType = 2;
	cout << "******************************" << endl;
}


void Yogurt::print() const
{
	cout << "IS A YOGURT" << endl;
	this->Milk_Product::print();
	cout << "********************************************************************************" << endl;
}