#pragma once
#include <iostream>
#include <string>
#include "MemberCollection.h"
#include "BuyerCollection.h"
#include "ProductList.h"
using namespace std;

class ShoppingSite
{
private:
	string currentUserId;
	MemberCollection ownedMemberCollection;
	BuyerCollection ownedBuyerCollection;
	ProductList ownedProductList;
	Product* currentProduct;
	Buyer* currentBuyer;
public:
	
	ShoppingSite();
	~ShoppingSite();
	void addNewMember(string name, string ssn, string id, string pw);
	bool checkLoginInfo(string id, string pw);
	string doLogout();
	string deleteMember();
	void addNewProduct(string productName, string companyName, int count, int countSold, int price, float satisfaction);
	Product* getCurrentProduct();
	Product* getProductInfo(string productName);
	void addNewBuyer();
	bool checkBuyer();
	void purchaseProduct();
	void purchaseList();
	void evaluateSatisfaction(float satisfaction);
	Buyer* getCurrentBuyer();
	ProductList* getProductListOnSale();
	ProductList* getProductListOnSold();
	ProductList* getSalesStatistic();
};

ShoppingSite::ShoppingSite()
{
	currentUserId = "";
}

ShoppingSite::~ShoppingSite()
{
}

void ShoppingSite::addNewMember(string name, string ssn, string id, string pw) {
	ownedMemberCollection.addNewMember(name, ssn, id, pw);
}


string ShoppingSite::deleteMember() {
	string result = currentUserId;
	ownedMemberCollection.deleteMember(currentUserId);
	currentUserId = "";
	return result;
}

bool ShoppingSite::checkLoginInfo(string id, string pw) {
	bool result;
	result = ownedMemberCollection.findMember(id, pw);
	if (result == true) {
		currentUserId = id;
	}
	return result;
}

string ShoppingSite::doLogout() {
	string result = currentUserId;
	currentBuyer = nullptr;
	currentProduct = nullptr;
	currentUserId = "";
	return result;
}

void ShoppingSite::addNewProduct( string productName, string companyName, int count, int countSold, int price ,float satisfaction)
{
	ownedProductList.addNewProduct(this->currentUserId , productName, companyName, count,countSold, price ,satisfaction);
}

Product* ShoppingSite::getProductInfo(string productName) {
	this->currentProduct = ownedProductList.findProduct(productName);
	if (this->currentProduct)
		return this->currentProduct;
	else
		return NULL;
}




Product* ShoppingSite::getCurrentProduct()
{
	return this->currentProduct;
}

void ShoppingSite::addNewBuyer() {
	currentBuyer=ownedBuyerCollection.addBuyer(this->currentUserId);
}

bool ShoppingSite::checkBuyer() {
	Buyer* temp;
	temp = ownedBuyerCollection.findBuyer(this->currentUserId);
	if(temp)
	{
		currentBuyer = temp;
		return true;
	}
	return false;
}

void ShoppingSite::purchaseProduct() {
	this->currentBuyer->purchaseProduct(currentProduct);
}
void ShoppingSite::purchaseList()
{
	this->currentBuyer->showBuyList();
}
void ShoppingSite::evaluateSatisfaction(float satisfaction)
{
	this->currentProduct->setSatisfaction(satisfaction);
	this->currentProduct->setAvgSatisfaction();
}
Buyer* ShoppingSite::getCurrentBuyer() {
	return this->currentBuyer;
}
ProductList* ShoppingSite::getProductListOnSale() {
	ProductList* ProductListOnSale = new ProductList();
	string sellerId;
	Product* temp = ownedProductList.getHead();
	if (ownedProductList.getHead() == NULL) {
		return NULL;
	}
	else {
		do {
			sellerId = temp->getSellerID();
			if (currentUserId == sellerId) {
				if (temp->getCount() > 0) {
					ProductListOnSale->addNewProduct(temp->getSellerID(), temp->getProductName(), temp->getCompanyName(),  temp->getCount(), temp->getCountSold() , temp->getPrice() ,temp->getAvgSatisfaction());
				}
			}
			temp = temp->getNextProduct();
		} while (temp != NULL);
	}
	return ProductListOnSale;
	delete ProductListOnSale;
}

ProductList* ShoppingSite::getProductListOnSold() {
	ProductList* ProductListOnSold = new ProductList();
	string sellerId;
	Product* temp = ownedProductList.getHead();
	if (ownedProductList.getHead() == NULL) {
		return NULL;
	}
	else {
		do {
			sellerId = temp->getSellerID();
			if (currentUserId == sellerId) {
				if (temp->getCountSold() > 0) {
					ProductListOnSold->addNewProduct(temp->getSellerID(), temp->getProductName(), temp->getCompanyName(), temp->getCount() ,temp->getCountSold() , temp->getPrice(), temp->getAvgSatisfaction());
				}
			}
			temp = temp->getNextProduct();
		} while (temp != NULL);
	}
	return ProductListOnSold;
	delete ProductListOnSold;
}
ProductList* ShoppingSite::getSalesStatistic() {
	ProductList* ProductListOnSold = new ProductList();
	string sellerId;
	Product* temp = ownedProductList.getHead();
	if (ownedProductList.getHead() == NULL) {
		return NULL;
	}
	else {
		do {
			sellerId = temp->getSellerID();
			if (currentUserId == sellerId) {
				if (temp->getCountSold() > 0) {
					ProductListOnSold->addNewProduct(temp->getSellerID(), temp->getProductName(), temp->getCompanyName(),  temp->getCount(), temp->getCountSold(), temp->getPrice() ,temp->getAvgSatisfaction());
					ProductListOnSold->getTail()->setCountSold(temp->getCountSold());
					ProductListOnSold->getTail()->setSatisfaction(temp->getSatisfaction());
				}
			}
			temp = temp->getNextProduct();
		} while (temp != NULL);
	}
	return ProductListOnSold;
	delete ProductListOnSold;
}