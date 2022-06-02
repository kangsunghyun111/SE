#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Product.h"

using namespace std;

class Buyer {
private:

	list <Product*> purchaseList;
	Buyer* prevBuyer;
	Buyer* nextBuyer;
	string id;
public:
	void purchaseProduct(Product* product);
	Buyer(string id);
	~Buyer();
	Buyer* getPrevBuyer();
	Buyer* getNextBuyer();
	string getId();
	void setPrevBuyer(Buyer* buyerPointer);
	void setNextBuyer(Buyer* buyerPointer);
	void showBuyList();
};

Buyer::Buyer(string id) {
	Buyer* prevBuyer = NULL;
	Buyer* nextBuyer = NULL;
	this->id = id;
}

Buyer::~Buyer()
{

}
void Buyer::setPrevBuyer(Buyer* buyerPointer) {
	this->prevBuyer = buyerPointer;
}

void Buyer::setNextBuyer(Buyer* buyerPointer) {
	this->nextBuyer = buyerPointer;
}
Buyer* Buyer::getPrevBuyer()
{
	return this->prevBuyer;
}
Buyer* Buyer::getNextBuyer()
{
	return this->nextBuyer;
}
void Buyer::purchaseProduct(Product* product) {
	this->purchaseList.push_back(product);
}
string Buyer::getId() {
	return this->id;
}

void Buyer::showBuyList() {
	list<Product*>::iterator it;
	Product* temp;
	if (*purchaseList.begin() != NULL) {
		for (it = purchaseList.begin(); it != purchaseList.end(); it++)
		{
			temp = *it;
			cout << temp->getSellerID() << " " << temp->getProductName() << " " << temp->getCompanyName() << " " << temp->getPrice() << " " << temp->getCount() << " " << temp->getAvgSatisfaction() << "\n";
		}
	}
}
