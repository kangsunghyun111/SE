#pragma once
#include <iostream>
#include <string>
#include "Member.h"
using namespace std;

class MemberCollection
{
private:
	int numberOfMember;
	Member* head;
	Member* tail;
public:
	MemberCollection();
	~MemberCollection();
	bool findMember(string id, string pw);
	void addNewMember(string name, string ssn, string id, string pw);
	void deleteMember(string id);

	
};

MemberCollection::MemberCollection()
{
	numberOfMember = 0;
	this->head = NULL;
	this->tail = NULL;
}

MemberCollection::~MemberCollection()
{
}

void MemberCollection::addNewMember(string name, string ssn, string id, string pw) {
	Member *newMember = new Member(name, ssn, id, pw);
	numberOfMember++;
	if (head == NULL) {
		head = newMember;
		tail = newMember;
	}
	else {
		newMember->setPrevMember(tail);
		tail->setNextMember(newMember);
		tail = newMember;
	}
}

void MemberCollection::deleteMember(string id) {
	Member* temp = head;
	
	do {
		if (temp->getId() == id)
			break;
		temp = temp->getNextMember();
	} while (temp != NULL);

	if (numberOfMember == 1) {
		head = NULL;
	}
	else {
		if (temp == head) {
			head = head->getNextMember();
			head->setPrevMember(NULL);
		}
		else if (temp == tail) {
			tail = tail->getPrevMember();
			tail->setNextMember(NULL);
		}
		else {
			temp->getPrevMember()->setNextMember(temp->getNextMember());
			temp->getNextMember()->setPrevMember(temp->getPrevMember());
		}
	}

	numberOfMember--;
	delete temp;
}

bool MemberCollection::findMember(string id, string pw) {
	string memberId;
	string memberPw;
	Member* temp = head;
	if (head == NULL) {
		return false;
	}
	else {
		do {
			memberId = temp->getId();
			memberPw = temp->getPw();
			if (memberId == id && memberPw == pw) {
				return true;
			}
			temp = temp->getNextMember();
		} while (temp != NULL);

		return false;
	}
}