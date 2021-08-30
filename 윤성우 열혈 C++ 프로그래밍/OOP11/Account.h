/*
Account Ŭ������ ���� ����
*/
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account {
private:
	int account_id;
	int balance;
	String name;	//char�� �����Ϳ��� String���� �ٲ�
public:
	Account(int _account_id, int _balance, String _name);
	int get_account_id(void) const;
	virtual void deposit(int money);
	void withdraw(int money);
	void print_acount_info(void) const;
};
#endif