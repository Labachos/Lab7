#pragma once
#include "Product.h"

class Milk_Product : public Product
{
private:
	string name;
	int numOfColors;
	float percentOfBodyFat;
	float price;
protected:
	int prodType;
public:
	float getPrice()const { return this->price; }
	void print() const;
	void calculatePrice(int factor);
	Milk_Product();
	virtual ~Milk_Product() {}
};
