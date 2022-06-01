#pragma once

#include <iostream>
#include <string>

class Product
{
private:
	Product* prevProduct;
	Product* nextProduct;

	string sellerID;
	string productName;
	string companyName;
	int count;
	int countSold = 0;
	int price;
	int satisfaction = 0;
public:
	Product();
	Product(string sellerID, string productName, string companyName, int price, int count);
	~Product();
	string getSellerID();
	string getProductName();
	string getCompanyName();
	int getCount();
	int getCountSold();
	int getPrice();
	float getAvgSatisfaction();
	void minusCount();
	void setSatisfaction(int satisfaction);

	void setPrevProduct(Product* productPointer);
	void setNextProduct(Product* productPointer);
	Product* getPrevProduct();
	Product* getNextProduct();
};

Product::Product()
{

}

Product::Product(string sellerID, string productName, string companyName, int price, int count)
{
	this->sellerID = sellerID;
	this->productName = productName;
	this->companyName = companyName;
	this->price = price;
	this->count = count;
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

int Product::getCountSold()
{
	return this->countSold;
}

int Product::getPrice()
{
	return this->price;
}

float Product::getAvgSatisfaction()
{
	return float(this->satisfaction/this->countSold);
}

void Product::minusCount()
{
	this->count--;
	this->countSold++;
}

void Product::setSatisfaction(int satisfaction)
{
	this->satisfaction+=satisfaction;
}

void Product::setPrevProduct(Product* productPointer) {
	this->prevProduct = productPointer;
}

void Product::setNextProduct(Product* productPointer) {
	this->nextProduct = productPointer;
}

Product* Product::getPrevProduct() {
	return this->prevProduct;
}

Product* Product::getNextProduct() {
	return this->nextProduct;
}

