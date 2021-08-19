/*
Account 클래스의 선언 파일
*/
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {
private:
	int account_id;
	int balance;
	char* name;
public:
	Account(int _account_id, int _balance, char* _name);
	Account(const Account& copy);
	Account& operator=(const Account& ref);
	int get_account_id(void) const;
	virtual void deposit(int money);
	void withdraw(int money);
	void print_acount_info(void) const;
	~Account();
};
#endif