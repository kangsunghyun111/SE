#pragma once
#include <iostream>
#include <string>
#include "Product.h"
using namespace std;

class ProductList {
private:
    int numberOfProduct;
    Product *head;
    Product *tail;
public:
    ProductList();
    ~ProductList();

    Product* getHead();
    Product* getTail();
    void addNewProduct(string sellerID, string productName, string companyName, int count, int countSold, int price , float satisfaction);
    Product* findProduct(string productName);
    
};

ProductList::ProductList()
{
    numberOfProduct = 0;
    this -> head = NULL;
    this -> tail = NULL;
}

ProductList::~ProductList()
{
    
}

Product* ProductList::getHead()
{
    return this->head;
}

Product* ProductList::getTail()
{
    return this->tail;
}


void ProductList::addNewProduct(string sellerID, string productName, string companyName, int count, int countSold, int price , float satisfaction){
    Product* newProduct = new Product(sellerID, productName, companyName, count , countSold, price, satisfaction);
    numberOfProduct++;
    if(head == NULL){
        head = newProduct;
        tail = newProduct;
    }
    else{
        newProduct->setPrevProduct(tail);
        tail->setNextProduct(newProduct);
        tail = newProduct;
    }
}

Product* ProductList::findProduct(string productName){
    string name;
    Product* temp = head;
    if (head == NULL)
    {
        return NULL;
    }
    else{
        do{
            name = temp->getProductName();
            if(name == productName){
                return temp;
            }
            temp = temp->getNextProduct();
        }while(temp != NULL);
        
        return NULL;
    }
}

