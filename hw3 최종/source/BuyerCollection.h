#pragma once
#include <iostream>
#include <string>
#include "Buyer.h"
using namespace std;

class BuyerCollection {
private:
    int numberOfBuyer;
    Buyer* head;
    Buyer* tail;
public:
    BuyerCollection();
    ~BuyerCollection();
    Buyer* addBuyer(string id);
    Buyer* findBuyer(string id);

};

BuyerCollection::BuyerCollection() {
    numberOfBuyer = 0;
    this->head = NULL;
    this->tail = NULL;
}
BuyerCollection::~BuyerCollection() {

}
Buyer* BuyerCollection::addBuyer(string id) {
    Buyer* newBuyer = new Buyer(id);
    numberOfBuyer++;
    if (head == NULL) {
        head = newBuyer;
        tail = newBuyer;
    }
    else {
        newBuyer->setPrevBuyer(tail);
        tail->setNextBuyer(newBuyer);
        tail = newBuyer;
    }
    return tail;
}
Buyer* BuyerCollection::findBuyer(string id) {
    string buyerId;
    Buyer* temp = head;
    if (head == NULL) {
        return NULL;
    }
    else {
        do {
            buyerId = temp->getId();
            if (buyerId == id) {
                return temp;
            }
            temp = temp->getNextBuyer();
        } while (temp != NULL);

        return NULL;
    }
}