#pragma once
#include "Milk_product.h"
#include "Fruit.h"

class Yogurt : public Milk_Product, public Fruit
{
private:
	float numOfSugars;
	float price;
public:
	Yogurt();
	virtual ~Yogurt() {}
	void print() const override final;
};