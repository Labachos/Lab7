#pragma once
#include "Product.h"

class Farm_Product : public Product
{
private:
	string name;
	int timeOfRipening;
	int numOfSuppliers;
	float price;
protected:
	int prodType;
public:
	Farm_Product();
	float getPrice() const { return this->price; }
	void calculatePrice(int factor) override;
	void print() const override;
	virtual ~Farm_Product() {}
};