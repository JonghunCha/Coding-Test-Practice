/*
윤성우 열혈 C++ 프로그래밍의 OOP 단계별 프로젝트 4단계를 구현한 코드입니다.
4단계에서는 코드의 안정성을 높이기 위해 const를 사용할 수 있는 모든 멤버함수를 const로 수정하였다.
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
	int get_account_id(void) const{
		return account_id;
	}
	void deposit(int money) {
		balance += money;
	}
	void withdraw(int money) {
		balance -= money;
	}
	void print_acount_info(void) const {
		cout << "계좌ID : " << account_id << endl;
		cout << "이 름 : " << name << endl;
		cout << "잔 액 : " << balance << endl;
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
		cout << "1. 계좌개설" << endl << "2. 입급" << endl << "3. 출금" << endl << "4. 계좌정보 전체 출력" << endl << "5. 프로그램 종료" << endl << "선택 : ";
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
			cout << "잘못된 입력입니다!!" << endl;
		}
	}

	return 0;
}

void Make_Account(void) {
	int id, balance;
	char name[100];

	cout << "계좌ID : ";
	cin >> id;
	cout << "이 름 : ";
	cin >> name;
	cout << "입급액 : ";
	cin >> balance;
	cout << endl;

	account[customer_num++] = new Account(id, balance, name);
}

void Deposit_Money(void) {
	int id, money;
	cout << "계좌ID : ";
	cin >> id;
	cout << "입금액 : ";
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
	cout << "계좌ID : ";
	cin >> id;
	cout << "입금액 : ";
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