#pragma once

#include "Member.h"
#include "Product.h"
#include <list>
using namespace std;
class Seller: public Member
{
private:
	list<string> productListOnSale;
	list<string> productListOnSold;

public:
	void addProductListOnSale(string productName);
	void addProductListOnSold(string productName);
	void printProductListOnSale();
	void printProductListOnSold();
};

void Seller::addProductListOnSale(string productName)
{
	this->productListOnSale.push_back(productName);
}

void Seller::addProductListOnSold(string productName)
{
	this->productListOnSold.push_back(productName);
}

void Seller::printProductListOnSale()
{
	for (string ptr : productListOnSale) {
		
	}
}

void Seller::printProductListOnSold()
{
	
}
