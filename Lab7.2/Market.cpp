#include "Market.h"
#include<iostream>
#include "Vegetable.h"
#include <string>

using namespace std;

Market::Market()
{
	this->price = 0;
	cout << "Market constracted." << endl;
	cout << "enter store name:" << endl;
	getline(cin, this->storeName);
	cout << "enter store factor:" << endl;
	cin >> this->storeFactor;
	cout << "**************************" << endl;
}



void Market::chageFactor()
{
	cout << "enter a new factor:";
	cin >> this->storeFactor;
	cout << endl;
	this->calculatePrice();
	cout << "**************************" << endl;
}

void Market::print() const
{
	cout << "The store Name is : " << this->storeName << endl;
	cout << "The store factor is: " << this->storeFactor << endl;
	cout << "The store num of products is: " << this->products.size() << endl;
	if (this->products.size() > 0)
	{
		cout << "The products:" << endl;
		cout << "**************************" << endl;
		for (int i = 0; i < products.size(); ++i)
		{
			cout << "the (" << i + 1 << ") product:" << endl;
			products[i]->print();
		}
	}
	cout << "The store all products price is: " << this->price << endl;
	cout << "**************************" << endl;
}

void Market::menu()
{
	int choice;
	while (1)
	{

		cout << "MENU :" << endl;
		cout << "******" << endl;
		cout << "1) Print all products" << endl;
		cout << "2) Calculate price" << endl;
		cout << "3) Add a product" << endl;
		cout << "4) Change the factor" << endl;
		cout << "5) EXIT" << endl;
		cout << "******" << endl;
		cout << "Your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			this->print();
			break;
		case 2:
			cout << "******" << endl;
			this->calculatePrice();
			cout << "The price was calculated succefully!" << endl;
			cout << "******" << endl;
			break;
		case 3:
			cout << "******" << endl;
			this->addProduct();
			cout << "******" << endl;
			break;
		case 4:
			cout << "******" << endl;
			this->chageFactor();
			cout << "******" << endl;
			break;
		case 5:
			cout << "******" << endl;
			cout << "GoodBye" << endl;
			return;
		default:
			cout << "Please try again\n";
		}
	}
	cout << "**************************" << endl;
}

void Market::addProduct()
{
	cout << "Type of Products : " << endl;
	cout << "1) Farm product" << endl;
	cout << "2) Milk product" << endl;
	cout << "3) Package product" << endl;
	cout << "4) Fruit product" << endl;
	cout << "5) Vegetable product" << endl;
	cout << "6) Cheese product" << endl;
	int choice;
	cout << "enter your choice: ";
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
		this->products.push_back(new Farm_Product());
		break;
	case 2:
		this->products.push_back(new Milk_Product());
		break;
	case 3:
		this->products.push_back(new Packge());
		break;
	case 4:
		this->products.push_back(new Fruit());
		break;
	case 5:
		this->products.push_back(new Vegetable());
		break;
	case 6:
		this->products.push_back(new Cheese());
		break;
	default:
		cout << "Please try again." << endl;
		return;
	}
	//this->calculatePrice();
	//cout << "**************************" << endl;
}

void Market::calculatePrice()
{
	this->price = 0;
	for (int i = 0; i < this->products.size(); ++i)
	{
		this->products[i]->calculatePrice(this->storeFactor);
		this->price += this->products[i]->getPrice();
	}
}