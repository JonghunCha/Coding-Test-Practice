/*
OOP11의 메인함수
*/
#include <iostream>
#include <cstring>
#include "AccountHandler.h"
using namespace std;

int main(void) {
	AccountHandler AH;
	int option;
	while (1) {
		cout << "-----Menu-----" << endl;
		cout << "1. 계좌개설" << endl << "2. 입급" << endl << "3. 출금" << endl << "4. 계좌정보 전체 출력" << endl << "5. 프로그램 종료" << endl << "선택 : ";
		cin >> option;
		cout << endl;
		if (option == 5)	break;
		else if (option == 1) {
			AH.Make_Account();
		}
		else if (option == 2) {
			AH.Deposit_Money();
		}
		else if (option == 3) {
			AH.Withdraw_Money();
		}
		else if (option == 4) {
			AH.Print_All_Account();
		}
		else {
			cout << "잘못된 입력입니다!!" << endl;
		}
	}

	return 0;
}