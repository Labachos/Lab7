#pragma once
#include "Farm_product.h"


class Vegetable : public Farm_Product
{
private:
	int numOfVitamins;
	float price;
public:
	Vegetable();
	void calculatePrice(int factor) override;
	void print() const override;
	virtual ~Vegetable(){}
};