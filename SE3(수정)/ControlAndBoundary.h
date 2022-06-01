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
	SignupUI(Signup* signup);
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
	Signup(ShoppingSite* shoppingSite);
	~Signup() {};
	void addNewMember(string name, string ssn, string id, string pw);
};


SignupUI::SignupUI(Signup* signup) {
	this->signup = signup;
}
void SignupUI::createNewMember(ifstream& in_fp) {
	string name, ssn, id, pw;
	in_fp >> name >> ssn >> id >> pw;
	this->name = name;
	this->ssn = ssn;
	this->id = id;
	this->pw = pw;
	cout << "1.1 회원가입\n> ";
	cout << name << ' ' << ssn << ' ' << id << ' ' << pw << "\n";
	this->signup->addNewMember(name, ssn, id, pw);
}
void SignupUI::printSignupMessage(ofstream& out_fp) {
	out_fp << "1.1 회원가입\n> ";
	out_fp << name << ' ' << ssn << ' ' << id << ' ' << pw << "\n";
}


Signup::Signup(ShoppingSite* shoppingSite) {
	this->shoppingSite = shoppingSite;
	this->signupUI = new SignupUI(this);
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
	MembershipWithdrawlUI() {};
	MembershipWithdrawlUI(MembershipWithdrawl* membershipWithdrawl);
	~MembershipWithdrawlUI() {};
	void doMemberWithdraw();
	void printWithdrawMessage(ofstream& out_fp);
};

class MembershipWithdrawl
{
private:
	ShoppingSite* shoppingSite;
public:
	MembershipWithdrawlUI* membershipWithdrawlUI;
	MembershipWithdrawl() {};
	MembershipWithdrawl(ShoppingSite* shoppingSite);
	~MembershipWithdrawl() {};
	string doMemberWithdraw();
};


MembershipWithdrawlUI::MembershipWithdrawlUI(MembershipWithdrawl* membershipWithdrawl) {
	this->membershipWithdrawl = membershipWithdrawl;
	doMemberWithdraw();
}

void MembershipWithdrawlUI::doMemberWithdraw() {
	cout << "1.2 회원탈퇴\n> ";
	this->memberId = this->membershipWithdrawl->doMemberWithdraw();
	cout << memberId << "\n";
}
void MembershipWithdrawlUI::printWithdrawMessage(ofstream& out_fp) {
	out_fp << "1.2 회원탈퇴\n> ";
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
	LoginUI() {};
	LoginUI(Login* login);
	~LoginUI() {};
	void enterLoginInfo(ifstream& in_fp);
	void printLoginMessage(ofstream& out_fp);
};

class Login
{
private:
	ShoppingSite* shoppingSite;
public:
	LoginUI* loginUI;
	Login() {};
	Login(ShoppingSite* shoppingSite);
	~Login() {};
	bool passLoginInfo(string id, string pw);
};


LoginUI::LoginUI(Login* login) {
	this->login = login;
}

void LoginUI::enterLoginInfo(ifstream& in_fp) {
	string id, pw;
	in_fp >> id >> pw;
	this->id = id;
	this->pw = pw;
	cout << "2.1 로그인\n> ";
	cout << id << ' ' << pw << "\n";
	result = this->login->passLoginInfo(id, pw);
}
void LoginUI::printLoginMessage(ofstream& out_fp) {
	out_fp << "2.1 로그인\n> ";
	if (result)
		out_fp << id << ' ' << pw << "\n";
}


Login::Login(ShoppingSite* shoppingSite) {
	this->shoppingSite = shoppingSite;
	this->loginUI = new LoginUI(this);
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
	LogoutUI() {};
	LogoutUI(Logout* logout);
	~LogoutUI() {};
	void doLogout();
	void printLogoutMessage(ofstream& out_fp);
};

class Logout
{
private:
	ShoppingSite* shoppingSite;
public:
	LogoutUI* logoutUI;
	Logout() {};
	Logout(ShoppingSite* shoppingSite);
	~Logout() {};
	string doLogout();
};


LogoutUI::LogoutUI(Logout* logout) {
	this->logout = logout;
	doLogout();
}

void LogoutUI::doLogout() {
	cout << "2.2 로그아웃\n> ";
	this->memberId = this->logout->doLogout();
	cout << memberId << "\n";
}
void LogoutUI::printLogoutMessage(ofstream& out_fp) {
	out_fp << "2.2 로그아웃\n> ";
	out_fp << memberId << "\n";
}


Logout::Logout(ShoppingSite* shoppingSite) {
	this->shoppingSite = shoppingSite;
	this->logoutUI = new LogoutUI(this);
}

string Logout::doLogout() {
	string memberId = this->shoppingSite->doLogout();
	return memberId;
}


class EnrollProductUI;
class EnrollProduct;

class EnrollProductUI
{
private:
	string productName;
	string companyName;
	int price;
	int count;
public:
	EnrollProduct* enrollProduct;
	EnrollProductUI() {};
	EnrollProductUI(EnrollProduct* enrollProduct);
	~EnrollProductUI() {};
	void createNewProduct(ifstream& in_fp);
	void printEnrollProductMessage(ofstream& out_fp);
};

class EnrollProduct
{
private:
	ShoppingSite* shoppingSite;
public:
	EnrollProductUI* enrollProductUI;
	EnrollProduct() {};
	EnrollProduct(ShoppingSite* shoppingSite);
	~EnrollProduct() {};
	void addNewProduct(string productName, string companyName, int price, int count);
};


EnrollProductUI::EnrollProductUI(EnrollProduct* enrollProduct) {
	this->enrollProduct = enrollProduct;
}
void EnrollProductUI::createNewProduct(ifstream& in_fp) {
	string productName, companyName;
	int price, count;
	in_fp >> productName >> companyName >> price >> count;
	this->productName = productName;
	this->companyName = companyName;
	this->price = price;
	this->count = count;
	cout << "3.1 판매 의류 등록\n";
	cout << "> " << productName << ' ' << companyName << ' ' << price << ' ' << count << "\n";
	this->enrollProduct->addNewProduct(productName, companyName, price, count);
}
void EnrollProductUI::printEnrollProductMessage(ofstream& out_fp) {
	out_fp << "3.1 판매 의류 등록\n";
	out_fp << "> " << productName << ' ' << companyName << ' ' << price << ' ' << count << "\n";
}


EnrollProduct::EnrollProduct(ShoppingSite* shoppingSite) {
	this->shoppingSite = shoppingSite;
	this->enrollProductUI = new EnrollProductUI(this);
}
void EnrollProduct::addNewProduct(string productName, string companyName, int price, int count) {
	this->shoppingSite->addNewProduct(productName, companyName, price, count);
}


class ShowProductOnSaleUI;
class ShowProductOnSale;

class ShowProductOnSaleUI
{
private:
	string productName;
	string companyName;
	int price;
	int count;
public:
	ShowProductOnSale* showProductOnSale;
	ShowProductOnSaleUI() {};
	ShowProductOnSaleUI(ShowProductOnSale* showProductOnSale);
	~ShowProductOnSaleUI() {};
	void printProductOnSaleMessage(ofstream& out_fp);
};

class ShowProductOnSale
{
private:
	ShoppingSite* shoppingSite;
public:
	ShowProductOnSaleUI* showProductOnSaleUI;
	ShowProductOnSale() {};
	ShowProductOnSale(ShoppingSite* shoppingSite);
	~ShowProductOnSale() {};
	ProductList* getProductListOnSale();
};


ShowProductOnSaleUI::ShowProductOnSaleUI(ShowProductOnSale* showProductOnSale) {
	this->showProductOnSale = showProductOnSale;
}

void ShowProductOnSaleUI::printProductOnSaleMessage(ofstream& out_fp) {
	cout << "3.2 등록 상품 조회\n";
	out_fp << "3.2 등록 상품 조회\n";
	ProductList* p;
	p = this->showProductOnSale->getProductListOnSale();
	if (p->getHead() == NULL) {
		cout << "등록 상품 없음!\n";
		out_fp << "등록 상품 없음!\n";
	}
	else {
		Product* temp = p->getHead();
		do {
			this->productName = temp->getProductName();
			this->companyName = temp->getCompanyName();
			this->price = temp->getPrice();
			this->count = temp->getCount();
			cout << "> " << productName << " " << companyName << " " << price << " " << count << "\n";
			out_fp << "> " << productName << ' ' << companyName << ' ' << price << ' ' << count << "\n";
			temp = temp->getNextProduct();
		} while (temp != NULL);
		delete p;
	}
}

ShowProductOnSale::ShowProductOnSale(ShoppingSite* shoppingSite) {
	this->shoppingSite = shoppingSite;
	this->showProductOnSaleUI = new ShowProductOnSaleUI(this);
}

ProductList* ShowProductOnSale::getProductListOnSale() {
	return this->shoppingSite->getProductListOnSale();	
}

class ShowProductOnSoldUI;
class ShowProductOnSold;

class ShowProductOnSoldUI
{
private:
	string productName;
	string companyName;
	int price;
	int countSold;
	int avgSatisfaction;
public:
	ShowProductOnSold* showProductOnSold;
	ShowProductOnSoldUI() {};
	ShowProductOnSoldUI(ShowProductOnSold* showProductOnSold);
	~ShowProductOnSoldUI() {};
	void printProductOnSoldMessage(ofstream& out_fp);
};

class ShowProductOnSold
{
private:
	ShoppingSite* shoppingSite;
public:
	ShowProductOnSoldUI* showProductOnSoldUI;
	ShowProductOnSold() {};
	ShowProductOnSold(ShoppingSite* shoppingSite);
	~ShowProductOnSold() {};
	ProductList* getProductListOnSold();
};


ShowProductOnSoldUI::ShowProductOnSoldUI(ShowProductOnSold* showProductOnSold) {
	this->showProductOnSold = showProductOnSold;
}

void ShowProductOnSoldUI::printProductOnSoldMessage(ofstream& out_fp) {
	cout << "3.3 판매 완료 상품 조회\n";
	out_fp << "3.3 판매 완료 상품 조회\n";
	ProductList* p;
	p = this->showProductOnSold->getProductListOnSold();
	if (p->getHead() == NULL) {
		cout << "판매 완료 상품 없음!\n";
		out_fp << "판매 완료 상품 없음!\n";
	}
	else {
		Product* temp = p->getHead();
		do {
			this->productName = temp->getProductName();
			this->companyName = temp->getCompanyName();
			this->price = temp->getPrice();
			this->countSold = temp->getCountSold();
			this->avgSatisfaction = temp->getAvgSatisfaction();
			cout << "> " << productName << " " << companyName << " " << price << " " << countSold << " " << avgSatisfaction << "\n";
			out_fp << "> " << productName << ' ' << companyName << ' ' << price << ' ' << countSold << " " << avgSatisfaction << "\n";
			temp = temp->getNextProduct();
		} while (temp != NULL);
		delete p;
	}
}

ShowProductOnSold::ShowProductOnSold(ShoppingSite* shoppingSite) {
	this->shoppingSite = shoppingSite;
	this->showProductOnSoldUI = new ShowProductOnSoldUI(this);
}

ProductList* ShowProductOnSold::getProductListOnSold() {
	return this->shoppingSite->getProductListOnSold();
}