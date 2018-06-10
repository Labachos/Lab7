#include "Packge.h"

Packge::Packge()
{
	this->Product::prodType = 2;
	cout << "constracted Packge." << endl;
    cout << "enter the num of products in the packge:" << endl;
	int numOfProducts;
	cin >> numOfProducts;
	cout << "enter the num of the colors in the packge:" << endl;
	cin >> this->numOfColors;
	for (int i = 1; i <= numOfProducts; i++)
	{
		cout << "enter the(" << i << ") product name:" << endl;
		string name;
		getline(cin, name);
		this->productsNames.push_back(name);
	}
	this->calculatePrice(1);
	cout << "*****************************" << endl;
}

void Packge::calculatePrice(int factor)
{
	//cout << "enter the factor:" << endl;
	//cin >> factor;
	this->price = ((this->Product::getPrice() * 2) * this->productsNames.size() + float(this->numOfColors) / 3);
}
void Packge::print()const
{
	this->Product::print();
	cout << "the products that you have in the packge are:" << endl;
	for (int i = 0; i<this->productsNames.size(); i++)
		cout << "(" << i + 1 << ")" << this->productsNames[i] << endl;
	cout << "the num of colors you have on the packge is: " << this->numOfColors << endl;
	cout << "the item type: " << Product::prodType << endl;
	cout << "*****************************" << endl;

}
