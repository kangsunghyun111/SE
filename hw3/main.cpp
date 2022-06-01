#include <iostream>
#include <fstream>
#include <string>
#include "ShoppingSite.h"
#include "ProductList.h"

using namespace std;

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수선언
void doTask();
void Signup();                   
void MembershipWithdrawal();    
void Login();                    
void Logout();                 

void SearchProduct();
void PurchaseProduct(); 
void ShowBuyList();
void EvaluateSatisfaction();
void program_exit();
void Enroll();
// 변수 선언
ifstream in_fp;
ofstream out_fp;

ShoppingSite shoppingSite;

int main() {
    in_fp.open(INPUT_FILE_NAME);
    out_fp.open(OUTPUT_FILE_NAME);


    doTask();

    in_fp.close();
    out_fp.close();
    return 0;
}

void doTask()
{ 
    int menu_level_1 = 0, menu_level_2 = 0; int is_program_exit = 0;
    while (!is_program_exit) {
        string str;
        in_fp >> menu_level_1 >> menu_level_2;
        cout << menu_level_1 << menu_level_2 << "\n";

        switch (menu_level_1) {
        case 1: {
            switch (menu_level_2) {
            case 1: {
                Signup();
                break;
            }
            case 2: {
                MembershipWithdrawal();
                break;
            }
            default:
                break;
            }
            break;
        }
        case 2: {
            switch (menu_level_2) {
            case 1: {
                Login();
                break;
            }
            case 2: {
                Logout();
                break;
            }
            default:
                break;
            }
            break;
        }
        case 3: {
            switch (menu_level_2) {
            case 1: {
                Enroll();
                break;
            }
            default:
                break;
            }
            break;
        }
    
        case 4: {
            switch (menu_level_2) {
            case 1: {
                SearchProduct();
                break;
            }
            case 2: {
                PurchaseProduct();
                break;
            }
            case 3: {
                ShowBuyList();
                break;
            }
            case 4: {
                EvaluateSatisfaction();
                break;
            }
            default:
                break;
            }
            break;
        }
        case 6: {
            switch (menu_level_2) {
            case 1: {
                program_exit();
                is_program_exit = 1;
                break;
            }
            default:
                break;
            }
            break;
        }
        default:
            break;
        }
        }
}

void program_exit() {
    out_fp << "6.1 종료\n" ;
}

void Signup() {
    string name, ssn, id, pw;
    in_fp >> name >> ssn >> id >> pw;
    cout << name << ssn << id << pw << "\n";

    shoppingSite.addNewMember(name, ssn, id, pw);

    out_fp << "1.1 회원가입‘\n> ";
    out_fp << name << ' ' << ssn << ' ' << id << ' ' << pw << "\n";
}

void MembershipWithdrawal() {
    string memberId;
    memberId = shoppingSite.deleteMember();
    cout << memberId << "\n";

    out_fp << "1.2 회원탈퇴\n> ";
    out_fp << memberId << "\n";
}

void Login() {
    string id, pw;
    in_fp >> id >> pw;
    cout << id << pw << "\n";

    bool result = shoppingSite.checkLoginInfo(id, pw);
    
    out_fp << "2.1 로그인\n> ";
    out_fp << id << ' ' << pw << "\n";

}

void Logout() {
    string memberId;
    memberId = shoppingSite.doLogout();
    cout << memberId << "\n";

    out_fp << "2.2 로그아웃\n> ";
    out_fp << memberId << "\n";
}
void Enroll() {
    string sellerId, productName, companyName;
    int price, count;
    in_fp >> productName >> companyName >> price >> count;
    shoppingSite.addNewProduct(productName, companyName, price, count);
    cout << productName << " " << companyName << " " << price << " " << count ;
    out_fp << "3.1 판매 의류 등록\n> ";
    out_fp << productName << " " << companyName << " " << price << " " << count << "\n";

}
 void SearchProduct(){
    string productName;
    Product* curProduct;
    in_fp >> productName;
    
    curProduct = shoppingSite.getProductInfo(productName);
    if(curProduct){
        out_fp << "4.1 상품 정보 검색\n> ";
        cout << curProduct->getProductName() <<"  " << curProduct->getSellerID() << "  " << curProduct->getCompanyName() << "  " << curProduct->getPrice() 
            << "  " << curProduct->getCount() << "  " << curProduct->getAvgSatisfaction() << "\n";
    }
    else{
        out_fp << "4.1 상품 정보 검색\n> ";
        cout << "상품명이 일치하는 상품이 존재하지 않습니다." << "\n";
    }
}

 void PurchaseProduct() {
     Product* curProduct;
     curProduct = shoppingSite.getCurrentProduct();
     if (curProduct && curProduct->getCount() > 0) {
         curProduct->minusCount();
         if (!shoppingSite.checkBuyer()) { // 처음 구매하는 사람이면
             shoppingSite.addNewbuyer();
             shoppingSite.checkBuyer();
             shoppingSite.purchaseProduct();
             out_fp << "4.2 상품 구매\n> ";
             cout << curProduct->getSellerID() << " " << curProduct->getProductName() << "\n";
         }
         else {
             shoppingSite.purchaseProduct();
             out_fp << "4.2 상품 구매\n> ";
             cout << curProduct->getSellerID() << " " << curProduct->getProductName() << "\n";
         }
     }
     else {
         out_fp << "4.2 상품 구매\n> ";
         cout << "상품이 없습니다." << "\n";
     }
 }
 
 void ShowBuyList() {
     out_fp << "4.3 상품 구매 내역 조회\n> ";
     if(shoppingSite.checkBuyer()) // 구매한적이 있으면
     { 
        Buyer* curBuyer = shoppingSite.getCurrentBuyer();
        curBuyer->showBuyList();
     }
     else {
         cout << "You have never purchased." << "\n";
     }
     
 }
 void EvaluateSatisfaction()
 {
     int score;
     string productName;
     Product* curProduct;
    
     in_fp >> productName >> score;
     curProduct = shoppingSite.getProductInfo(productName);
     if (curProduct)
     {
         curProduct->setSatisfaction(score);
         out_fp << "4.4 상품 구매만족도 평가\n> ";
         cout << curProduct->getSellerID() << " " << curProduct->getProductName() << " " << score << "\n" ;
 
     }
 }