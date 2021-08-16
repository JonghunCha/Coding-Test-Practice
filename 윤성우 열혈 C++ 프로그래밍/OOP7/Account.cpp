/*
Account Ŭ������ ���� ����
*/
#include <iostream>
#include <cstring>
#include "Account.h"
using namespace std;

Account::Account(int _account_id, int _balance, char* _name)
	:account_id(_account_id), balance(_balance) {
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

Account::Account(const Account& copy)
	: account_id(copy.account_id), balance(copy.balance) {
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
}

int Account::get_account_id(void) const {
	return account_id;
}

void Account::deposit(int money) {
	balance += money;
}

void Account::withdraw(int money) {
	balance -= money;
}

void Account::print_acount_info(void) const {
	cout << "����ID : " << account_id << endl;
	cout << "�� �� : " << name << endl;
	cout << "�� �� : " << balance << endl;
}

Account::~Account() {
	delete[]name;
}
