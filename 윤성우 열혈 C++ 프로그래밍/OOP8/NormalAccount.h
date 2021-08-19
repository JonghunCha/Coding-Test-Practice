/*
NormalAccount Ŭ������ ���� �� ����(Ŭ������ ũ�Ⱑ �۾� ����� ���� ������ ���� ������ �ʾ���)
*/
#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "Account.h"

class NormalAccount :public Account {
private:
	int roi;
public:
	NormalAccount(int _account_id, int _balance, char* _name, int _roi)
		:Account(_account_id, _balance, _name), roi(_roi) {}
	virtual void deposit(int money);
};

void NormalAccount::deposit(int money) {
	Account::deposit(money);
	Account::deposit(money * (roi / 100.0));
}
#endif