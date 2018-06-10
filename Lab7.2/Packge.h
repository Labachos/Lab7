#pragma once
#include "Product.h"
#include <iostream>
#include <vector>

class Packge : public Product
{
private:
	vector<string> productsNames;
	int numOfColors;
	float price;
public:
	void print() const override;
	void calculatePrice(int factor) override;
	Packge();
	virtual ~Packge() {}
};
