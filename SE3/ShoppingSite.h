#pragma once
#include <iostream>
#include <string>
#include "MemberCollection.h"
#include "ProductList.h"
using namespace std;

class ShoppingSite
{
private:
	string currentUserId;
	MemberCollection ownedMemberCollection;

	ProductList ownedProductList;
public:
	ShoppingSite();
	~ShoppingSite();
	void addNewMember(string name, string ssn, string id, string pw);
	bool checkLoginInfo(string id, string pw);
	string doLogout();
	string deleteMember();

	void addNewProduct(string productName, string companyName, int count, int price);
	ProductList* showProductListOnSale();
	ProductList* showProductListOnSold();
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
	currentUserId = "";
	return result;
}


void ShoppingSite::addNewProduct(string productName, string companyName, int count, int price) {
	ownedProductList.addNewProduct(currentUserId, productName, companyName, count, price);
}

ProductList* ShoppingSite::showProductListOnSale() {
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
					ProductListOnSale->addNewProduct(temp->getSellerID(), temp->getProductName(), temp->getCompanyName(), temp->getPrice(), temp->getCount());
				}
			}
			temp = temp->getNextProduct();
		} while (temp != NULL);
	}
	return ProductListOnSale;
}

ProductList* ShoppingSite::showProductListOnSold() {
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
					ProductListOnSold->addNewProduct(temp->getSellerID(), temp->getProductName(), temp->getCompanyName(), temp->getPrice(), temp->getCount());
				}
			}
			temp = temp->getNextProduct();
		} while (temp != NULL);
	}
	return ProductListOnSold;
}