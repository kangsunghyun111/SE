#pragma once

#include <iostream>
#include <string>
#include "Seller.h"
class Product
{
private:
	string sellerID;
	string productName;
	string companyName;
	int count;
	int countSold = 0;
	int price;
	int satisfaction = 0;
public:
	Product();
	Product(string sellerID, string productName, string companyName, int count, int price);
	~Product();
	string getSellerID();
	string getProductName();
	string getCompanyName();
	int getCount();
	int getPrice();
	int getAvgSatisfaction();
	void minusCount();
	void setSatisfaction();
};

Product::Product()
{

}

Product::Product(string sellerID, string productName, string companyName, int count, int price)
{
	this->sellerID = sellerID;
	this->productName = productName;
	this->companyName = companyName;
	this->count = count;
	this->price = price;
}

Product::~Product()
{

}

string Product::getSellerID()
{
	return this->sellerID;
}

string Product::getProductName()
{
	return this->productName;
}

string Product::getCompanyName()
{
	return this->companyName;
}

int Product::getCount()
{
	return this->count;
}

int Product::getPrice()
{
	return this->price;
}

int Product::getAvgSatisfaction()
{
	return this->satisfaction/this->countSold;
}

void Product::minusCount()
{
	this->count--;
	this->countSold++;
}

void Product::setSatisfaction()
{
	this->satisfaction++;
}



