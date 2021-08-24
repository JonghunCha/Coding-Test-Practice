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
	//Account(int _account_id, int _balance, char* _name);	//이제 name에 char* 대신 String이 사용됨
	//Account(const Account& copy);							//클래스 내에 동적 할당이 없기에 얕은복사 깊은복사 걱정할 필요 없음
	//Account& operator=(const Account& ref);				//클래스 내에 동적 할당이 없기에 얕은복사 깊은복사 걱정할 필요 없음
	int get_account_id(void) const;
	virtual void deposit(int money);
	void withdraw(int money);
	void print_acount_info(void) const;
	//~Account();											//클래스 내에 동적 할당이 없기에 소멸자를 굳이 정의할 필요 없음
};
#endif