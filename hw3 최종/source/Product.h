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
    int countSold;
    int price;
    int satisfaction;
    float avgSatisfaction;

public:
    Product();
    Product(string sellerID, string productName, string companyName, int count,int countSold ,int price, float satisfaction);
    ~Product();

    Product* getPrevProduct();
    Product* getNextProduct();

    string getSellerID();
    string getProductName();
    string getCompanyName();

    void setCountSold(int countSold);
    int getCount();
    int getCountSold();
    int getPrice();
    float getAvgSatisfaction();
    float getSatisfaction();

    void plusCountSold();
    void minusCount();
    void setSatisfaction(int score);
    void setPrevProduct(Product* productPointer);
    void setNextProduct(Product* productPointer);
    void setAvgSatisfaction();
};

Product::Product()
{

}

Product::Product(string sellerID, string productName, string companyName, int count, int countSold, int price, float satisfaction)
{
    this->sellerID = sellerID;
    this->productName = productName;
    this->companyName = companyName;
    this->count = count;
    this->countSold = countSold;
    this->price = price;
    this->avgSatisfaction = satisfaction;
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
    return this->avgSatisfaction;
}


void Product::minusCount()
{
    this->count--;
    this->countSold++;
}

void Product::setSatisfaction(int score)
{
    this->satisfaction += score;
}
void Product::setAvgSatisfaction()
{
    if (this->countSold != 0) {
        this->avgSatisfaction = (float)this->satisfaction / (float)this->countSold;
    }
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
void Product::setCountSold(int countSold)
{
    this->countSold = countSold;
}
float Product::getSatisfaction()
{
    return this->satisfaction;
}
