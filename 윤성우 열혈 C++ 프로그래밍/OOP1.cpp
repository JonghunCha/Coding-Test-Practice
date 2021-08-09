/*
윤성우 열혈 C++ 프로그래밍의 OOP 단계별 프로젝트 1단계를 구현한 코드입니다.
*/
#include <iostream>
#include <cstring>

using namespace std;

typedef struct{
	int account_id;
	char name[100];
	int balance;
}Account;

Account account_info[100];
int custom_num = 0;

void make_account(void);		//계좌개설
void deposit(void);				//입금
void withdraw(void);			//출금
void print_all_account(void);	//계좌정보 전체 출력

int main(void) {
	int option;
	while (1) {
		cout << "-----Menu-----" << endl;
		cout << "1. 계좌개설" << endl << "2. 입급" << endl << "3. 출금" << endl << "4. 계좌정보 전체 출력" << endl << "5. 프로그램 종료" << endl<<"선택 : ";
		cin >> option;
		cout << endl;
		if (option == 5)	break;
		else if (option == 1) {
			make_account();
		}
		else if (option == 2) {
			deposit();
		}
		else if (option == 3) {
			withdraw();
		}
		else if (option == 4) {
			print_all_account();
		}
	}
	return 0;
}

void make_account(void) {
	int id, money;
	char name[100];
	cout << "계좌ID : ";
	cin >> id;
	cout << "이 름 : ";
	cin >> name;
	cout << "입급액 : ";
	cin >> money;
	cout << endl;
	account_info[custom_num].account_id = id;
	strcpy(account_info[custom_num].name, name);
	account_info[custom_num].balance = money;
	custom_num++;
}

void deposit(void) {
	int id, money;
	cout << "계좌ID : ";
	cin >> id;
	cout << "입금액 : ";
	cin >> money;
	for (int i = 0; i < custom_num; i++) {
		if (account_info[i].account_id == id) {
			account_info[i].balance += money;
			break;
		}
	}
	cout << "입금완료" << endl << endl;
}

void withdraw(void) {
	int id, money;
	cout << "계좌ID : ";
	cin >> id;
	cout << "출금액 : ";
	cin >> money;
	for (int i = 0; i < custom_num; i++) {
		if (account_info[i].account_id == id) {
			account_info[i].balance -= money;
			break;
		}
	}
	cout << "출금완료" << endl << endl;
}

void print_all_account(void) {
	for (int i = 0; i < custom_num; i++) {
		cout << "계좌ID : " << account_info[i].account_id << endl;
		cout << "이 름 : " << account_info[i].name << endl;
		cout << "잔 액 : " << account_info[i].balance << endl << endl;
	}
}