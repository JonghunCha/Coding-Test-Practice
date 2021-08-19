/*
������ ���� C++ ���α׷����� OOP �ܰ躰 ������Ʈ 3�ܰ踦 ������ �ڵ��Դϴ�.
3�ܰ迡���� 2�ܰ迡�� ������ Ŭ������ ���� ���� �����ڸ� �߰��Ͽ���.
*/
#include <iostream>
#include <cstring>
using namespace std;

void Make_Account(void);
void Deposit_Money(void);
void Withdraw_Money(void);
void Print_All_Account(void);

class Account {
private:
	int account_id;
	int balance;
	char* name;
public:
	Account(int _account_id, int _balance, char* _name)
		:account_id(_account_id), balance(_balance) {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}
	Account(const Account& copy)
		:account_id(copy.account_id), balance(copy.balance) {
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}
	int get_account_id(void) {
		return account_id;
	}
	void deposit(int money) {
		balance += money;
	}
	void withdraw(int money) {
		balance -= money;
	}
	void print_acount_info(void) {
		cout << "����ID : " << account_id << endl;
		cout << "�� �� : " << name << endl;
		cout << "�� �� : " << balance << endl;
	}
	~Account() {
		delete[]name;
	}
};

Account* account[100];
int customer_num = 0;

int main(void) {
	int option;
	while (1) {
		cout << "-----Menu-----" << endl;
		cout << "1. ���°���" << endl << "2. �Ա�" << endl << "3. ���" << endl << "4. �������� ��ü ���" << endl << "5. ���α׷� ����" << endl << "���� : ";
		cin >> option;
		cout << endl;
		if (option == 5)	break;
		else if (option == 1) {
			Make_Account();
		}
		else if (option == 2) {
			Deposit_Money();
		}
		else if (option == 3) {
			Withdraw_Money();
		}
		else if (option == 4) {
			Print_All_Account();
		}
		else {
			cout << "�߸��� �Է��Դϴ�!!" << endl;
		}
	}

	return 0;
}

void Make_Account(void) {
	int id, balance;
	char name[100];

	cout << "����ID : ";
	cin >> id;
	cout << "�� �� : ";
	cin >> name;
	cout << "�Ա޾� : ";
	cin >> balance;
	cout << endl;

	account[customer_num++] = new Account(id, balance, name);
}

void Deposit_Money(void) {
	int id, money;
	cout << "����ID : ";
	cin >> id;
	cout << "�Աݾ� : ";
	cin >> money;
	for (int i = 0; i < customer_num; i++) {
		if (account[i]->get_account_id() == id) {
			account[i]->deposit(money);
			break;
		}
	}
}

void Withdraw_Money(void) {
	int id, money;
	cout << "����ID : ";
	cin >> id;
	cout << "��ݾ� : ";
	cin >> money;
	for (int i = 0; i < customer_num; i++) {
		if (account[i]->get_account_id() == id) {
			account[i]->withdraw(money);
			break;
		}
	}
}
void Print_All_Account(void) {
	for (int i = 0; i < customer_num; i++) {
		account[i]->print_acount_info();
	}
}