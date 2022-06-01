#include <iostream>
#include <fstream>
#include <string>
#include "ControlAndBoundary.h"

using namespace std;

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수선언
void doTask();
     
void program_exit();

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
                Signup* signup = new Signup(&shoppingSite);
                signup->signupUI->createNewMember(in_fp);
                signup->signupUI->printSignupMessage(out_fp);
                delete signup;
                break;
            }
            case 2: {
                MembershipWithdrawl* membershipWithdrawl = new MembershipWithdrawl(&shoppingSite);
                membershipWithdrawl->membershipWithdrawlUI->printWithdrawMessage(out_fp);
                delete membershipWithdrawl;
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
                Login* login = new Login(&shoppingSite);
                login->loginUI->enterLoginInfo(in_fp);
                login->loginUI->printLoginMessage(out_fp);
                delete login;
                break;
            }
            case 2: {
                Logout* logout = new Logout(&shoppingSite);
                logout->logoutUI->printLogoutMessage(out_fp);
                delete logout;
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
                EnrollProduct* enrollProduct = new EnrollProduct(&shoppingSite);
                enrollProduct->enrollProductUI->createNewProduct(in_fp);
                enrollProduct->enrollProductUI->printEnrollProductMessage(out_fp);
                delete enrollProduct;
                break;
            }
            case 2: {
                ShowProductOnSale* showProductOnSale = new ShowProductOnSale(&shoppingSite);
                showProductOnSale->showProductOnSaleUI->printProductOnSaleMessage(out_fp);
                delete showProductOnSale;
                break;
            }
            case 3: {
                ShowProductOnSold* showProductOnSold = new ShowProductOnSold(&shoppingSite);
                showProductOnSold->showProductOnSoldUI->printProductOnSoldMessage(out_fp);
                delete showProductOnSold;
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
                SearchProduct* searchProduct = new SearchProduct(&shoppingSite);
                searchProduct->searchProductUI->inputProductName(in_fp);
                searchProduct->searchProductUI->printProductList(out_fp);
                delete searchProduct;
                break;
            }
            case 2: {
                ProductPurchase* productPurchase = new ProductPurchase(&shoppingSite);
                productPurchase->productPurchaseUI->printPurchase(out_fp);
                delete productPurchase;
                break;
            }
            case 3: {
                PurchaseList* purchaseList = new PurchaseList(&shoppingSite);
                delete purchaseList;
                break;
            }
            case 4: {
                Satisfaction* satisfaction = new Satisfaction(&shoppingSite);
                satisfaction->satisfactionUI->evaluateSatisfaction(in_fp);
                satisfaction->satisfactionUI->printSatisfaction(out_fp);
                delete satisfaction;
                break;
            }
            default:
                break;
            }
            break;
        }
        case 5: {
            switch (menu_level_2) {
            case 1: {
                ShowSalesStatistic* showSalesStatistic = new ShowSalesStatistic(&shoppingSite);
                showSalesStatistic->showSalesStatisticUI->printSalesStatisticMessage(out_fp);
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
