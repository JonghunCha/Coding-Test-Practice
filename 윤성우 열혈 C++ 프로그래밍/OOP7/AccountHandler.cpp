/*
AccountHandler Ŭ������ ���� ����
*/
#include <iostream>
#include <cstring>
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
using namespace std;

AccountHandler::AccountHandler()
	:customer_num(0) {}

void AccountHandler::Make_Account(void) {
	int option;
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cout << "���� : ";
	cin >> option;
	if (option == 1)	MakeNormalAccount();
	else	MakeHighCreditAccount();
}

void AccountHandler::MakeNormalAccount(void) {
	int id, balance, roi;
	char name[100];

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�� �� : "; cin >> name;
	cout << "�Ա޾� : "; cin >> balance;
	cout << "������ : "; cin >> roi;
	cout << endl;

	account[customer_num++] = new NormalAccount(id, balance, name, roi);
}

void AccountHandler::MakeHighCreditAccount(void) {
	int id, balance, roi, credit_option;
	char name[100];

	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�� �� : "; cin >> name;
	cout << "�Ա޾� : "; cin >> balance;
	cout << "������ : "; cin >> roi;
	cout << "�ſ���(1toA, 2toB, 3toC) : "; cin >> credit_option;
	cout << endl;

	if (credit_option == 1)			account[customer_num++] = new HighCreditAccount(id, balance, name, roi, 7);
	else if (credit_option == 2)		account[customer_num++] = new HighCreditAccount(id, balance, name, roi, 4);
	else							account[customer_num++] = new HighCreditAccount(id, balance, name, roi, 2);
}

void AccountHandler::Deposit_Money(void) {
	int id, money;
	cout << "����ID : ";
	cin >> id;
	cout << "�Աݾ� : ";
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
	cout << "����ID : ";
	cin >> id;
	cout << "�Աݾ� : ";
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