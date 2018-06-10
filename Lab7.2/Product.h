#pragma once
#include<iostream>
#include <string>

using namespace std;

class Product
{
private:
	static int products;
	int serialNum;
	char row;
	int shelf;
	float amount;
	int area;
	float price;
protected:
	int prodType;
public:
	virtual float getPrice() const { return this->price; }
	virtual void calculatePrice(int factor) = 0;
	Product();
	virtual ~Product(void) {}
	void chageAmount();
	virtual void print() const;
};