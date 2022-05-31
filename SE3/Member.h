#pragma once
#include <iostream>
#include <string>
using namespace std;

class Member
{
private:
	Member* prevMember;
	Member* nextMember;
	string name;
	string ssn;
	string id;
	string pw;
public:
	Member();
	Member(string name, string ssn, string id, string pw);
	~Member();
	void setPrevMember(Member* memberPointer);
	void setNextMember(Member* memberPointer);
	

	Member* getPrevMember();
	Member* getNextMember();
	string getId();
	string getPw();
};

Member::Member()
{
}

Member::Member(string name, string ssn, string id, string pw) {
	this->prevMember = NULL;
	this->nextMember = NULL;
	this->name = name;
	this->ssn = ssn;
	this->id = id;
	this->pw = pw;
}

Member::~Member()
{
}

void Member::setPrevMember(Member* memberPointer) {
	this->prevMember = memberPointer;
}

void Member::setNextMember(Member* memberPointer) {
	this->nextMember = memberPointer;
}

Member* Member::getPrevMember() {
	return this->prevMember;
}

Member* Member::getNextMember() {
	return this->nextMember;
}

string Member::getId() {
	return this->id;
}

string Member::getPw() {
	return this->pw;
}