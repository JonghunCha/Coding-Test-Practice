/*
11단계에서 2가지 예외사항을 처리하기 위해 추가된 파일이다.
*/
#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <iostream>
using namespace std;

class WithdrawException {
private:
	int balance;	//현재 잔액
	int req_money;	//요청된 출금액
public:
	WithdrawException(int _balance, int _req_money)
		:balance(_balance), req_money(_req_money) {}
	void ShowException() const {
		cout << "잔액이 부족합니다." << endl;
	}
};

class MinusException {
private:
	int req_money;	//요청된 입출금 금액
public:
	MinusException(int _req_money)
		:req_money(_req_money) {}
	void ShowException() const {
		cout << "입출금액은 0원이 넘어야 합니다." << endl;
	}
};

#endif