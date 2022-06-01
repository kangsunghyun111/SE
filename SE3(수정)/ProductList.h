#pragma once

#include "Product.h"
using namespace std;

class ProductList
{
private:
	int numberOfProduct;
	Product* head;
	Product* tail;
public:
	ProductList();
	~ProductList();
	Product* findProduct(string productName);
	Product* getHead();
	void addNewProduct(string sellerId, string productName, string companyName, int count, int price);
	void purchaseProduct(string productName);
};

ProductList::ProductList()
{
	numberOfProduct = 0;
	this->head = NULL;
	this->tail = NULL;
}

ProductList::~ProductList()
{
}

Product* ProductList::getHead()
{
	return this->head;
}

void ProductList::addNewProduct(string sellerId, string productName, string companyName, int price, int count)
{
	Product* newProduct = new Product(sellerId,productName,companyName,price,count);
	numberOfProduct++;
	if (head == NULL) {
		head = newProduct;
		tail = newProduct;
	}
	else {
		newProduct->setPrevProduct(tail);
		tail->setNextProduct(newProduct);
		tail = newProduct;
	}
}

Product* ProductList::findProduct(string productName) 
{
	string productName2;
	Product* temp = head;
	if (head == NULL) {
		return NULL;
	}
	else {
		do {
			productName2 = temp->getProductName();
			if (productName == productName2) {
				return temp;
			}
			temp = temp->getNextProduct();
		} while (temp != NULL);

		return NULL;
	}
}

void ProductList::purchaseProduct(string productName)
{
	string productName2;
	Product* temp = head;
	if (head == NULL) {
	}
	else {
		do {
			productName2 = temp->getProductName();
			if (productName == productName2) {
				temp->minusCount();
			}
			temp = temp->getNextProduct();
		} while (temp != NULL);
	}
}