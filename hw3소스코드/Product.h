#pragma once

#include <iostream>
#include <string>
using namespace std;

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
    Product(string sellerID, string productName, string companyName, int count, int price);
    ~Product();

    Product* getPrevProduct();
    Product* getNextProduct();

    string getSellerID();
    string getProductName();
    string getCompanyName();

    int getCount();
    int getCountSold();
    int getPrice();
    float getAvgSatisfaction();
    
    void minusCount();
    void setSatisfaction(int score);
    void setPrevProduct(Product* productPointer);
    void setNextProduct(Product* productPointer);

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
    this->prevProduct = NULL;
    this->nextProduct = NULL;
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

int Product::getCountSold()
{
    return this->countSold;
}

float Product::getAvgSatisfaction()
{
    if (this->countSold == 0)
        return 0;
    else
        return (this->satisfaction) / (this->countSold);
}

void Product::minusCount()
{
    this->count--;
    this->countSold++;
}

void Product::setSatisfaction(int score)
{
    this->satisfaction = score;
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
