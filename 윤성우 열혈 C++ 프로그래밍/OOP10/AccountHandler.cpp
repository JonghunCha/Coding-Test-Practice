/*
AccountHandler 클래스의 정의 파일
*/
#include <iostream>
#include <cstring>
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"
using namespace std;

AccountHandler::AccountHandler()
	:customer_num(0) {}

void AccountHandler::Make_Account(void) {
	int option;
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택 : ";
	cin >> option;
	if (option == 1)	MakeNormalAccount();
	else	MakeHighCreditAccount();
}

void AccountHandler::MakeNormalAccount(void) {
	int id, balance, roi;
	String name;

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "이 름 : "; cin >> name;
	cout << "입급액 : "; cin >> balance;
	cout << "이자율 : "; cin >> roi;
	cout << endl;

	account[customer_num++] = new NormalAccount(id, balance, name, roi);
}

void AccountHandler::MakeHighCreditAccount(void) {
	int id, balance, roi, credit_option;
	String name;

	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "이 름 : "; cin >> name;
	cout << "입급액 : "; cin >> balance;
	cout << "이자율 : "; cin >> roi;
	cout << "신용등급(1toA, 2toB, 3toC) : "; cin >> credit_option;
	cout << endl;

	if (credit_option == 1)			account[customer_num++] = new HighCreditAccount(id, balance, name, roi, 7);
	else if (credit_option == 2)		account[customer_num++] = new HighCreditAccount(id, balance, name, roi, 4);
	else							account[customer_num++] = new HighCreditAccount(id, balance, name, roi, 2);
}

void AccountHandler::Deposit_Money(void) {
	int id, money;
	cout << "계좌ID : ";
	cin >> id;
	cout << "입금액 : ";
	cin >> money;
	for (int i = 0; i < customer_num; i++) {
		if (account[i]->get_account_id() == id) {
			account[i]->deposit(money);
			break;
		}
	}
}

void AccountHandler::Withdraw_Money(void) {
	int id, money;
	cout << "계좌ID : ";
	cin >> id;
	cout << "출금액 : ";
	cin >> money;
	for (int i = 0; i < customer_num; i++) {
		if (account[i]->get_account_id() == id) {
			account[i]->withdraw(money);
			break;
		}
	}
}

void AccountHandler::Print_All_Account(void) const {
	for (int i = 0; i < customer_num; i++) {
		account[i]->print_acount_info();
	}
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < customer_num; i++) {
		delete account[i];
	}
}