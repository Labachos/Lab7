#pragma once
#include "Farm_product.h"

class Fruit : public Farm_Product
{
private:
	float numOfSugars;
	float price;
public:
	void print() const override;
	void calculatePrice(int factor) override final;
	Fruit();
	virtual ~Fruit() {}
};