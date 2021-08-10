/*
������ ���� C++ ���α׷����� OOP �ܰ躰 ������Ʈ 5�ܰ踦 ������ �ڵ��Դϴ�.
��� C++�� ��ü���� ���α׷��� ����, �����Լ��� ����ϴ� ���� �ٶ������� �ʴ�.
���� 4�ܰ���� �����Լ��� �����Ǿ� �ִ� ���� control Ŭ������, ������ Account Ŭ������ entity Ŭ������ �������.
����, Ŭ���� ���� ����Լ��� ���Ǹ� Ŭ���� �ܺη� ������ Ŭ������ �������� ������.
*/
#include <iostream>
#include <cstring>
using namespace std;

/*
Account Ŭ������ Entity Ŭ������ �� ������ ������ ���õ� ������ �� �Լ��� �����Ѵ�.
*/
class Account {
private:
	int account_id;
	int balance;
	char* name;
public:
	Account(int _account_id, int _balance, char* _name);
	Account(const Account& copy);
	int get_account_id(void) const;
	void deposit(int money);
	void withdraw(int money);
	void print_acount_info(void) const;
	~Account();
};

Account::Account(int _account_id, int _balance, char* _name)
	:account_id(_account_id), balance(_balance) {
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

Account::Account(const Account& copy)
	:account_id(copy.account_id), balance(copy.balance) {
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
}
	
int Account::get_account_id(void) const {
	return account_id;
}

void Account::deposit(int money) {
	balance += money;
}

void Account::withdraw(int money) {
	balance -= money;
}

void Account::print_acount_info(void) const {
	cout << "����ID : " << account_id << endl;
	cout << "�� �� : " << name << endl;
	cout << "�� �� : " << balance << endl;
}

Account::~Account(){
	delete []name;
}

/*
AccountHandler Ŭ������ Control Ŭ������ �� ���°����� �ʿ��� ���� ��ɵ�(�Ա�, ���, ���°���, �������� ��ȸ ����� �����Ѵ�)
*/
class AccountHandler {
private:
	Account* account[100];
	int customer_num;
public:
	AccountHandler();
	void Make_Account(void);
	void Deposit_Money(void);
	void Withdraw_Money(void);
	void Print_All_Account(void) const;
	~AccountHandler();
};

AccountHandler::AccountHandler()
	:customer_num(0) {}

void AccountHandler::Make_Account(void) {
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

void AccountHandler::Deposit_Money(void) {
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

void AccountHandler::Withdraw_Money(void) {
	int id, money;
	cout << "����ID : ";
	cin >> id;
	cout << "�Աݾ� : ";
	cin >> money;
	for (int i = 0; i < customer_num; i++) {
		if (account[i]->get_account_id() == id) {
			account[i]->withdraw(money);
			break;
		}
	}
}

void AccountHandler::Print_All_Account(void) const {
	for (int i = 0; i < customer_num; i++) {
		account[i]->print_acount_info();
	}
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < customer_num; i++) {
		delete account[i];
	}
}

int main(void) {
	AccountHandler AH;
	int option;
	while (1) {
		cout << "-----Menu-----" << endl;
		cout << "1. ���°���" << endl << "2. �Ա�" << endl << "3. ���" << endl << "4. �������� ��ü ���" << endl << "5. ���α׷� ����" << endl << "���� : ";
		cin >> option;
		cout << endl;
		if (option == 5)	break;
		else if (option == 1) {
			AH.Make_Account();
		}
		else if (option == 2) {
			AH.Deposit_Money();
		}
		else if (option == 3) {
			AH.Withdraw_Money();
		}
		else if (option == 4) {
			AH.Print_All_Account();
		}
		else {
			cout << "�߸��� �Է��Դϴ�!!" << endl;
		}
	}

	return 0;
}