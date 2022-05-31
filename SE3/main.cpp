#include <iostream>
#include <fstream>
#include <string>
#include "ShoppingSite.h"
using namespace std;

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void Signup();					// 회원가입
void MembershipWithdrawal();	// 회원탈퇴
void Login();					// 로그인
void Logout();					// 로그아웃

void Enroll();
void ShowProductListOnSale();
void ShowProductListOnSold();
string sellerId;

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
{ // 메뉴 파싱을 위한 level 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0; int is_program_exit = 0;
	while (!is_program_exit) { // 입력파일에서 메뉴 숫자 2개를 읽기
		string str;
		in_fp >> menu_level_1 >> menu_level_2;
		cout << menu_level_1 << menu_level_2 << "\n";

		switch (menu_level_1){
		case 1:{
			switch (menu_level_2){
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
			switch (menu_level_2){
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
			case 2: {
				ShowProductListOnSale();
				break;
			}
			case 3: {
				ShowProductListOnSold();
				break;
			}
			default:
				break;
			}
			break;
		}
		case 6:{
			switch (menu_level_2){
			case 1:{
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
	out_fp << "6.1 종료\n";
}

void Signup() {
	string name, ssn, id, pw;
	in_fp >> name >> ssn >> id >> pw;
	cout << name << ssn << id << pw << "\n";

	shoppingSite.addNewMember(name, ssn, id, pw);

	out_fp << "1.1 회원가입\n> ";
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
	sellerId = id;    //추가
}

void Logout() {
	string memberId;
	memberId = shoppingSite.doLogout();
	cout << memberId << "\n";

	out_fp << "2.2 로그아웃\n> ";
	out_fp << memberId << "\n";
	sellerId = "";     //추가
}

void Enroll() {
	string productName, companyName;
	int price, count;
	in_fp >> productName >> companyName >> price >> count;

	if (sellerId!="") {
		shoppingSite.addNewProduct(sellerId, productName, companyName, price, count);
		out_fp << "3.1 판매 의류 등록\n> ";
		out_fp << productName << " " << companyName << " " << price << " " << count << "\n";
}