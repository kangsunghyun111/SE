#include <iostream>
#include <fstream>
#include <string>
#include "ControlAndBoundary.h"
using namespace std;

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
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
				Signup* signup = new Signup(in_fp, &shoppingSite);
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
			switch (menu_level_2){
			case 1: {
				Login* login = new Login(in_fp, &shoppingSite);
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
	cout << "6.1 종료\n";
	out_fp << "6.1 종료\n";
}