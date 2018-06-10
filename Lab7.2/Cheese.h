#pragma once
#include "Milk_Product.h"

class Cheese : public Milk_Product
{
private:
	int numOfExtras;
	float price;
public:
	void print() const override final;
	void calculatePrice(int factor) override final;
	Cheese();
	virtual ~Cheese() {}
};
