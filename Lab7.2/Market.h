#pragma once
#include "Cheese.h"
#include "Farm_Product.h"
#include "Fruit.h"
#include "Milk_Product.h"
#include "Packge.h"
#include "Product.h"
#include "Market.h"
#include <string>
#include <vector>

using namespace std;

class Market
{
private:
	vector<Product*> products;
	string storeName;
	int storeFactor;
	float price;
public:
	void chageFactor();
	void calculatePrice();
	void addProduct();
	void menu();
	void print() const;
	Market();
};