/*
NormalAccount Ŭ������ ���� �� ����(Ŭ������ ũ�Ⱑ �۾� ����� ���� ������ ���� ������ �ʾ���)
*/
#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "Account.h"
#include "String.h"
#include "Exception.h"

class NormalAccount :public Account {
private:
	int roi;
public:
	NormalAccount(int _account_id, int _balance, String _name, int _roi)
		:Account(_account_id, _balance, _name), roi(_roi) {}
	virtual void deposit(int money);
};

void NormalAccount::deposit(int money) {
	if (money < 0)	throw MinusException(money);
	Account::deposit(money);
	Account::deposit(money * (roi / 100.0));
}
#endif