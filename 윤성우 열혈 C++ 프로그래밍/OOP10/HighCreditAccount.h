/*
HighCreditAccount 클래스의 선언 및 정의(클래스의 크기가 작아 선언과 정의 파일을 굳이 나누지 않았음)
*/
#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "NormalAccount.h"
#include "String.h"

class HighCreditAccount :public NormalAccount {
private:
	int credit_rating;
public:
	HighCreditAccount(int _account_id, int _balance, String _name, int _roi, int _credit_rating)
		:NormalAccount(_account_id, _balance, _name, _roi), credit_rating(_credit_rating) {}
	virtual void deposit(int money);
};

void HighCreditAccount::deposit(int money) {
	NormalAccount::deposit(money);
	Account::deposit(money * (credit_rating / 100.0));
}
#endif