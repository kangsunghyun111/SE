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

	void addNewProduct(string sellerId, string productName, string companyName, int count, int price);
	void showProductListOnSale(string sellerId);
	void showProductListOnSold(string sellerId);
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


void ShoppingSite::addNewProduct(string sellerId, string productName, string companyName, int count, int price) {
	ownedProductList.addNewProduct(sellerId, productName, companyName, count, price);
}

void ShoppingSite::showProductListOnSale(string sellerId) {

}

void ShoppingSite::showProductListOnSold(string sellerId) {

}