/*
11�ܰ迡�� 2���� ���ܻ����� ó���ϱ� ���� �߰��� �����̴�.
*/
#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <iostream>
using namespace std;

class WithdrawException {
private:
	int balance;	//���� �ܾ�
	int req_money;	//��û�� ��ݾ�
public:
	WithdrawException(int _balance, int _req_money)
		:balance(_balance), req_money(_req_money) {}
	void ShowException() const {
		cout << "�ܾ��� �����մϴ�." << endl;
	}
};

class MinusException {
private:
	int req_money;	//��û�� ����� �ݾ�
public:
	MinusException(int _req_money)
		:req_money(_req_money) {}
	void ShowException() const {
		cout << "����ݾ��� 0���� �Ѿ�� �մϴ�." << endl;
	}
};

#endif