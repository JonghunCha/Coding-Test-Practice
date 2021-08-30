/*
Account 클래스의 정의 파일
*/
#include <iostream>
#include <cstring>
#include "Account.h"
#include "Exception.h"
using namespace std;

Account::Account(int _account_id, int _balance, String _name)
	:account_id(_account_id), balance(_balance) {
	name = _name;
}

int Account::get_account_id(void) const {
	return account_id;
}

void Account::deposit(int money) {
	if (money < 0)	throw MinusException(money);
	balance += money;
}

void Account::withdraw(int money) {
	if (money < 0)	throw MinusException(money);
	if (balance < money)	throw WithdrawException(balance, money);
	balance -= money;
}

void Account::print_acount_info(void) const {
	cout << "계좌ID : " << account_id << endl;
	cout << "이 름 : " << name << endl;
	cout << "잔 액 : " << balance << endl;
}