/*
AccountHandler Ŭ������ ���� ����
*/
#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler {
private:
	BoundCheckArray<Account*> account;
	int customer_num;
public:
	AccountHandler();
	void Make_Account(void);
	void MakeNormalAccount(void);
	void MakeHighCreditAccount(void);
	void Deposit_Money(void);
	void Withdraw_Money(void);
	void Print_All_Account(void) const;
	~AccountHandler();
};
#endif