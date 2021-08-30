/*
Account 클래스의 선언 파일
*/
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account {
private:
	int account_id;
	int balance;
	String name;	//char형 포인터에서 String으로 바꿈
public:
	Account(int _account_id, int _balance, String _name);
	int get_account_id(void) const;
	virtual void deposit(int money);
	void withdraw(int money);
	void print_acount_info(void) const;
};
#endif