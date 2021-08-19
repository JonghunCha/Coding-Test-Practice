/*
HighCreditAccount Ŭ������ ���� �� ����(Ŭ������ ũ�Ⱑ �۾� ����� ���� ������ ���� ������ �ʾ���)
*/
#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount :public NormalAccount {
private:
	int credit_rating;
public:
	HighCreditAccount(int _account_id, int _balance, char* _name, int _roi, int _credit_rating)
		:NormalAccount(_account_id, _balance, _name, _roi), credit_rating(_credit_rating) {}
	virtual void deposit(int money);
};

void HighCreditAccount::deposit(int money) {
	NormalAccount::deposit(money);
	Account::deposit(money * (credit_rating / 100.0));
}
#endif