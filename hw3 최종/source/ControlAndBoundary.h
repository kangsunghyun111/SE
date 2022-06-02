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

class SearchProductUI;
class SearchProduct;

class SearchProductUI {
private:
	string productName;
	Product* curProduct;
public:
	SearchProduct* searchProduct;
	SearchProductUI() {};
	SearchProductUI(SearchProduct* searchProduct);
	~SearchProductUI() {};
	void inputProductName(ifstream& in_fp);
	void printProductList(ofstream& out_fp);
};

class SearchProduct {
private:
	ShoppingSite* shoppingSite;
public:
	SearchProductUI* searchProductUI;
	SearchProduct() {};
	SearchProduct(ShoppingSite* shoppingSite);
	~SearchProduct() {};
	Product* getProductInfo(string productName);
};

SearchProductUI::SearchProductUI(SearchProduct* searchProduct) {
	this->searchProduct = searchProduct;
}

void SearchProductUI::inputProductName(ifstream& in_fp) {
	string productName;
	in_fp >> productName;
	this->productName = productName;
	this->curProduct = this->searchProduct->getProductInfo(productName);
}
void SearchProductUI::printProductList(ofstream& out_fp) {
	if (curProduct) {
		cout << "4.1 상품 정보 검색\n >";
		cout << curProduct->getProductName() << "  " << curProduct->getSellerID() << "  " << curProduct->getCompanyName() << "  " << curProduct->getPrice()
			<< "  " << curProduct->getCount() << "  " << curProduct->getAvgSatisfaction() << "\n";
		out_fp << "4.1 상품 정보 검색\n> ";
		out_fp << curProduct->getProductName() << "  " << curProduct->getSellerID() << "  " << curProduct->getCompanyName() << "  " << curProduct->getPrice()
			<< "  " << curProduct->getCount() << "  " << curProduct->getAvgSatisfaction() << "\n";
	}
}

SearchProduct::SearchProduct(ShoppingSite* shoppingSite){
	this->shoppingSite = shoppingSite;
	this->searchProductUI = new SearchProductUI(this);
}
Product* SearchProduct::getProductInfo(string productName) {
	return this->shoppingSite->getProductInfo(productName);
}

class ProductPurchase;
class ProductPurchaseUI;

class ProductPurchaseUI {
private:
	Product* curProduct;
public:
	ProductPurchase* productPurchase;
	ProductPurchaseUI() {};
	ProductPurchaseUI(ProductPurchase* productPurchase);
	~ProductPurchaseUI() {};
	void doProductPurchase();
	void printPurchase(ofstream& out_fp);
};

class ProductPurchase {
private:
	ShoppingSite* shoppingSite;
public:
	ProductPurchaseUI* productPurchaseUI;
	ProductPurchase() {};
	ProductPurchase(ShoppingSite* shoppingSite);
	~ProductPurchase() {};
	Product* productPurchase();
};

ProductPurchaseUI::ProductPurchaseUI(ProductPurchase* productPurchase) {
	this->productPurchase = productPurchase;
	doProductPurchase();
}
void ProductPurchaseUI::doProductPurchase() {
	cout << "4.2 상품 구매\n>";
	curProduct = this->productPurchase->productPurchase();
	if (curProduct && curProduct->getCount() >= 0){
		cout << curProduct->getSellerID() << " " << curProduct->getProductName() << " \n";
	}
}
void ProductPurchaseUI::printPurchase(ofstream& out_fp) {
	out_fp << "4.2 상품 구매\n>";
	out_fp << curProduct->getSellerID() << " " << curProduct->getProductName() << " \n";
	
}
Product* ProductPurchase::productPurchase() {
	Product* temp;
	temp = this->shoppingSite->getCurrentProduct();
	if (temp && temp->getCount() > 0) {
		temp->minusCount();
		temp->setAvgSatisfaction();
	
		if (!this->shoppingSite->checkBuyer()) {
			this->shoppingSite->addNewbuyer();
			this->shoppingSite->purchaseProduct();
		}
		else {
			this->shoppingSite->purchaseProduct();
		}
	}
	return temp;
}
ProductPurchase::ProductPurchase(ShoppingSite* shoppingSite) {
	this->shoppingSite = shoppingSite;
	this->productPurchaseUI = new ProductPurchaseUI(this);
}

class PurchaseList;
class PurchaseListUI;

class PurchaseListUI {
public:
	PurchaseList* purchaseList;
	PurchaseListUI() {};
	PurchaseListUI(PurchaseList* purchaseList);
	~PurchaseListUI() {};
	void showPurhcaseList();
};
class PurchaseList {
private:
	ShoppingSite* shoppingSite;
public:
	PurchaseListUI* purchaseListUI;
	PurchaseList() {};
	PurchaseList(ShoppingSite* shoppingSite);
	~PurchaseList() {};
	void purchaseList();
	void showBuyList();
};

PurchaseListUI::PurchaseListUI(PurchaseList* purchaseList) {
	this->purchaseList = purchaseList;
	showPurhcaseList();
}
void PurchaseListUI::showPurhcaseList() {
	this->purchaseList->purchaseList();
}


PurchaseList::PurchaseList(ShoppingSite* shoppingSite) {
	this->shoppingSite = shoppingSite;
	this->purchaseListUI = new PurchaseListUI(this);
}
void PurchaseList::purchaseList() {
	this->shoppingSite->checkBuyer();
	if (this->shoppingSite->getCurrentBuyer()) {
		cout << "4.3 상품 구매 내역 조회\n>";
		this->shoppingSite->purchaseList();
	}
}

class SatisfactionUI;
class Satisfaction;

class SatisfationUI {
private:
	float satisfactionScore;
	string productName;
	string sellerId;
	Product* curProduct;
public:
	Satisfaction* satisfation;
	SatisfationUI() {};
	SatisfationUI(Satisfaction* satisfation);
	~SatisfationUI() {};
	void evaluateSatisfaction(ifstream& in_fp);
	void printSatisfaction(ofstream& out_fp);
	
};
class Satisfaction {
private:
	ShoppingSite* shoppingSite;
public:
	SatisfationUI* satisfactionUI;
	Satisfaction() {};
	Satisfaction(ShoppingSite* shoppingSite);
	~Satisfaction() {};
	Product* getProductInfo(string productName);
	void evaluateSatisfaction(string productName, float satisfaction);
};

void SatisfationUI::evaluateSatisfaction(ifstream& in_fp) {
	float satisfaction;
	string productName;
	in_fp >> productName >> satisfaction;
	this->satisfactionScore = satisfaction;
	this->productName = productName;
	this->curProduct = this->satisfation->getProductInfo(productName);
	this->satisfation->evaluateSatisfaction(productName, satisfaction);
}

void SatisfationUI::printSatisfaction(ofstream& out_fp) {
	out_fp << "4.4 상품 구매만족도 평가\n> ";
	out_fp << curProduct->getSellerID() << " " << curProduct->getProductName() << " " << satisfactionScore << "\n";
}

SatisfationUI::SatisfationUI(Satisfaction* satisfation) {
	this->satisfation = satisfation;
}



Satisfaction::Satisfaction(ShoppingSite* shoppingSite) {
	this->shoppingSite = shoppingSite;
	this->satisfactionUI = new SatisfationUI(this);
}

void Satisfaction::evaluateSatisfaction(string productName, float satisfaction) {
	Product* temp;
	temp = this->shoppingSite->getProductInfo(productName);
	if (temp)
	{
		this->shoppingSite->evaluateSatisfaction(satisfaction);
		cout << "4.4 상품 구매만족도 평가\n> ";
		cout << temp->getSellerID() << " " << temp->getProductName() << " " << satisfaction << "\n";
	}

}

Product* Satisfaction::getProductInfo(string productName) {
	return this->shoppingSite->getProductInfo(productName);
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
	int countSold;
	float satisfaction;
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
	void addNewProduct(string productName, string companyName, int price, int count , int countSold, float satisfaction);
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
	this->countSold = 0;
	this->satisfaction = 0;
	cout << "3.1 판매 의류 등록\n";
	cout << "> " << productName << ' ' << companyName << ' ' << price << ' ' << count << "\n";
	this->enrollProduct->addNewProduct(productName, companyName, count,countSold, price,satisfaction);
}
void EnrollProductUI::printEnrollProductMessage(ofstream& out_fp) {
	out_fp << "3.1 판매 의류 등록\n";
	out_fp << "> " << productName << ' ' << companyName << ' ' << price << ' ' << count << "\n";
}


EnrollProduct::EnrollProduct(ShoppingSite* shoppingSite) {
	this->shoppingSite = shoppingSite;
	this->enrollProductUI = new EnrollProductUI(this);
}
void EnrollProduct::addNewProduct(string productName, string companyName, int price, int count, int countSold , float satisfaction) {
	this->shoppingSite->addNewProduct(productName, companyName, price, count, countSold, satisfaction);
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
class ShowSalesStatisticUI;
class ShowSalesStatistic;

class ShowSalesStatisticUI
{
private:
	string productName;
	int priceSum;
	float avgSatisfaction;
public:
	ShowSalesStatistic* showSalesStatistic;
	ShowSalesStatisticUI() {};
	ShowSalesStatisticUI(ShowSalesStatistic* showSalesStatistic);
	~ShowSalesStatisticUI() {};
	void printSalesStatisticMessage(ofstream& out_fp);
};

class ShowSalesStatistic
{
private:
	ShoppingSite* shoppingSite;
public:
	ShowSalesStatisticUI* showSalesStatisticUI;
	ShowSalesStatistic() {};
	ShowSalesStatistic(ShoppingSite* shoppingSite);
	~ShowSalesStatistic() {};
	ProductList* getSalesStatistic();
};


ShowSalesStatisticUI::ShowSalesStatisticUI(ShowSalesStatistic* showSalesStatistic) {
	this->showSalesStatistic = showSalesStatistic;
}

void ShowSalesStatisticUI::printSalesStatisticMessage(ofstream& out_fp) {
	cout << "5.1 판매 상품 통계\n";
	out_fp << "5.1 판매 상품 통계\n";
	ProductList* p;
	p = this->showSalesStatistic->getSalesStatistic();
	if (p->getHead() == NULL) {
		cout << "판매 상품 없음!\n";
		out_fp << "판매 상품 없음!\n";
	}
	else {
		Product* temp = p->getHead();
		do {
			this->productName = temp->getProductName();
			this->priceSum = (temp->getCountSold() * temp->getPrice());
			this->avgSatisfaction = temp->getAvgSatisfaction();
			cout << "> " << productName << " " << priceSum << " " << avgSatisfaction << "\n";
			out_fp << "> " << productName << ' ' << priceSum << " " << avgSatisfaction << "\n";
			temp = temp->getNextProduct();
		} while (temp != NULL);
		delete p;
	}
}

ShowSalesStatistic::ShowSalesStatistic(ShoppingSite* shoppingSite) {
	this->shoppingSite = shoppingSite;
	this->showSalesStatisticUI = new ShowSalesStatisticUI(this);
}

ProductList* ShowSalesStatistic::getSalesStatistic() {
	return this->shoppingSite->getSalesStatistic();
}
