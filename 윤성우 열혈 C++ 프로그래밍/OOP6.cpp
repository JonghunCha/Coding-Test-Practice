/*
������ ���� C++ ���α׷����� OOP �ܰ躰 ������Ʈ 6�ܰ踦 ������ �ڵ��Դϴ�.
6�ܰ迡���� ���ο� ����� �߰��Ѵ�.
������ ���¸� �����Ͽ� �Ա��� �ϸ� ���ڰ� �߻��Ѵ�. �� �� ���¸��� �������� ���̰� �ִ�.
6�ܰ迡���� NormalAccount�� HighCreditAccount��� ���� �߰��Ѵ�. 
�̵��� ���� ���뿹�ݰ��¿� �ſ�ŷڰ��¸� �ǹ��ϸ� �� ���̿��� ������ ���̰� �ִ�.
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
	virtual void deposit(int money);
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
	: account_id(copy.account_id), balance(copy.balance) {
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

Account::~Account() {
	delete[]name;
}

/*
NormalAccount Ŭ������ Account Ŭ������ ��ӹ�����, ���뿹�ݰ��¸� �ǹ��Ѵ�.
�Աݽ� ������ ����ؼ� ���ڸ� �����ϵ��� deposit �Լ��� �����Ѵ�
*/
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

/*
HighCreditAccount Ŭ������ NormalAccount Ŭ������ ��ӹ�����, �ſ�ŷڰ��¸� �ǹ��Ѵ�.
�ſ�ŷڰ��´� �ſ��޺��� �⺻������ �߰����� ������ �ٴ´�.
*/
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
	void MakeNormalAccount(void);
	void MakeHighCreditAccount(void);
	void Deposit_Money(void);
	void Withdraw_Money(void);
	void Print_All_Account(void) const;
	~AccountHandler();
};

AccountHandler::AccountHandler()
	:customer_num(0) {}

void AccountHandler::Make_Account(void) {
	int option;
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cout << "���� : ";
	cin >> option;
	if (option == 1)	MakeNormalAccount();
	else	MakeHighCreditAccount();
}

void AccountHandler::MakeNormalAccount(void) {
	int id, balance, roi;
	char name[100];

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�� �� : "; cin >> name;
	cout << "�Ա޾� : "; cin >> balance;
	cout << "������ : "; cin >> roi;
	cout << endl;

	account[customer_num++] = new NormalAccount(id, balance, name, roi);
}

void AccountHandler::MakeHighCreditAccount(void) {
	int id, balance, roi, credit_option;
	char name[100];

	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�� �� : "; cin >> name;
	cout << "�Ա޾� : "; cin >> balance;
	cout << "������ : "; cin >> roi;
	cout << "�ſ���(1toA, 2toB, 3toC) : "; cin >> credit_option;
	cout << endl;

	if(credit_option == 1)			account[customer_num++] = new HighCreditAccount(id, balance, name, roi, 7);
	else if(credit_option == 2)		account[customer_num++] = new HighCreditAccount(id, balance, name, roi, 4);
	else							account[customer_num++] = new HighCreditAccount(id, balance, name, roi, 2);
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
	cout << "��ݾ� : ";
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