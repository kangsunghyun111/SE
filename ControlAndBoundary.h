#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "ShoppingSite.h"
using namespace std;

class SignupUI;
class Signup;

class SignupUI
{
private:
	string name;
	string ssn;
	string id;
	string pw;
public:
	Signup* signup;
	SignupUI() {};
	SignupUI(ifstream& in_fp, Signup* signup);
	~SignupUI() {};
	void createNewMember(ifstream& in_fp);
	void printSignupMessage(ofstream& out_fp);
};

class Signup
{
private:
	ShoppingSite* shoppingSite;
public:
	SignupUI* signupUI;
	Signup() {};
	Signup(ifstream& in_fp, ShoppingSite* shoppingSite);
	~Signup() {};
	void addNewMember(string name, string ssn, string id, string pw);
};


SignupUI::SignupUI(ifstream& in_fp, Signup* signup) {
	this->signup = signup;
	createNewMember(in_fp);
}
void SignupUI::createNewMember(ifstream& in_fp) {
	string name, ssn, id, pw;
	in_fp >> name >> ssn >> id >> pw;
	this->name = name;
	this->ssn = ssn;
	this->id = id;
	this->pw = pw;
	cout << "1.1 È¸¿ø°¡ÀÔ\n> ";
	cout << name << ' ' << ssn << ' ' << id << ' ' << pw << "\n";
	this->signup->addNewMember(name, ssn, id, pw);
}
void SignupUI::printSignupMessage(ofstream& out_fp) {
	out_fp << "1.1 È¸¿ø°¡ÀÔ\n> ";
	out_fp << name << ' ' << ssn << ' ' << id << ' ' << pw << "\n";
}


Signup::Signup(ifstream& in_fp, ShoppingSite* shoppingSite) {
	this->shoppingSite = shoppingSite;
	this->signupUI = new SignupUI(in_fp, this);
}
void Signup::addNewMember(string name, string ssn, string id, string pw) {
	this->shoppingSite->addNewMember(name, ssn, id, pw);
}


class MembershipWithdrawlUI;
class MembershipWithdrawl;

class MembershipWithdrawlUI
{
private:
	string memberId;
public:
	MembershipWithdrawl* membershipWithdrawl;
	MembershipWithdrawlUI(){};
	MembershipWithdrawlUI(MembershipWithdrawl* membershipWithdrawl);
	~MembershipWithdrawlUI(){};
	void doMemberWithdraw();
	void printWithdrawMessage(ofstream& out_fp);
};

class MembershipWithdrawl
{
private:
	ShoppingSite* shoppingSite;
public:
	MembershipWithdrawlUI* membershipWithdrawlUI;
	MembershipWithdrawl(){};
	MembershipWithdrawl(ShoppingSite* shoppingSite);
	~MembershipWithdrawl(){};
	string doMemberWithdraw();
};


MembershipWithdrawlUI::MembershipWithdrawlUI(MembershipWithdrawl* membershipWithdrawl) {
	this->membershipWithdrawl = membershipWithdrawl;
	doMemberWithdraw();
}

void MembershipWithdrawlUI::doMemberWithdraw() {
	cout << "1.2 È¸¿øÅ»Åð\n> ";
	this->memberId = this->membershipWithdrawl->doMemberWithdraw();
	cout << memberId << "\n";
}
void MembershipWithdrawlUI::printWithdrawMessage(ofstream& out_fp) {
	out_fp << "1.2 È¸¿øÅ»Åð\n> ";
	out_fp << memberId << "\n";
}


MembershipWithdrawl::MembershipWithdrawl(ShoppingSite* shoppingSite) {
	this->shoppingSite = shoppingSite;
	this->membershipWithdrawlUI = new MembershipWithdrawlUI(this);
}

string MembershipWithdrawl::doMemberWithdraw() {
	string memberId = this->shoppingSite->deleteMember();
	return memberId;
}


class LoginUI;
class Login;

class LoginUI
{
private:
	string id;
	string pw;
	bool result;
public:
	Login* login;
	LoginUI(){};
	LoginUI(ifstream& in_fp, Login* login);
	~LoginUI(){};
	void enterLoginInfo(ifstream& in_fp);
	void printLoginMessage(ofstream& out_fp);
};

class Login
{
private:
	ShoppingSite* shoppingSite;
public:
	LoginUI* loginUI;
	Login(){};
	Login(ifstream& in_fp, ShoppingSite* shoppingSite);
	~Login(){};
	bool passLoginInfo(string id, string pw);
};


LoginUI::LoginUI(ifstream& in_fp, Login* login){
	this->login = login;
	enterLoginInfo(in_fp);
}

void LoginUI::enterLoginInfo(ifstream& in_fp) {
	string id, pw;
	in_fp >> id >> pw;
	this->id = id;
	this->pw = pw;
	cout << "2.1 ·Î±×ÀÎ\n> ";
	cout << id << ' ' << pw << "\n";
	result = this->login->passLoginInfo(id, pw);
}
void LoginUI::printLoginMessage(ofstream& out_fp) {
	out_fp << "2.1 ·Î±×ÀÎ\n> ";
	if(result)
		out_fp << id << ' ' << pw << "\n";
}


Login::Login(ifstream& in_fp, ShoppingSite* shoppingSite){
	this->shoppingSite = shoppingSite;
	this->loginUI = new LoginUI(in_fp, this);
}

bool Login::passLoginInfo(string id, string pw) {
	return this->shoppingSite->checkLoginInfo(id, pw);
}


class LogoutUI;
class Logout;

class LogoutUI
{
private:
	string memberId;
public:
	Logout* logout;
	LogoutUI(){};
	LogoutUI(Logout* logout);
	~LogoutUI(){};
	void doLogout();
	void printLogoutMessage(ofstream& out_fp);
};

class Logout
{
private:
	ShoppingSite* shoppingSite;
public:
	LogoutUI* logoutUI;
	Logout(){};
	Logout(ShoppingSite* shoppingSite);
	~Logout(){};
	string doLogout();
};


LogoutUI::LogoutUI(Logout* logout){
	this->logout = logout;
	doLogout();
}

void LogoutUI::doLogout() {
	cout << "2.2 ·Î±×¾Æ¿ô\n> ";
	this->memberId = this->logout->doLogout();
	cout << memberId << "\n";
}
void LogoutUI::printLogoutMessage(ofstream& out_fp) {
	out_fp << "2.2 ·Î±×¾Æ¿ô\n> ";
	out_fp << memberId << "\n";
}


Logout::Logout(ShoppingSite* shoppingSite){
	this->shoppingSite = shoppingSite;
	this->logoutUI = new LogoutUI(this);
}

string Logout::doLogout() {
	string memberId = this->shoppingSite->doLogout();
	return memberId;
}