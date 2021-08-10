/*
윤성우 열혈 C++ 프로그래밍의 OOP 단계별 프로젝트 5단계를 구현한 코드입니다.
사실 C++은 객체지향 프로그래밍 언어로, 전역함수를 사용하는 것이 바람직하지 않다.
따라서 4단계까지 전역함수로 구현되어 있던 것을 control 클래스로, 기존의 Account 클래스를 entity 클래스로 만들었다.
또한, 클래스 내부 멤버함수의 정의를 클래스 외부로 빼내어 클래스의 가독성을 높였다.
*/
#include <iostream>
#include <cstring>
using namespace std;

/*
Account 클래스는 Entity 클래스로 고객 계좌의 정보와 관련된 데이터 및 함수를 포함한다.
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
	cout << "계좌ID : " << account_id << endl;
	cout << "이 름 : " << name << endl;
	cout << "잔 액 : " << balance << endl;
}

Account::~Account(){
	delete []name;
}

/*
AccountHandler 클래스는 Control 클래스로 고객 계좌관련해 필요한 실제 기능들(입금, 출금, 계좌개설, 계좌정보 조회 기능을 포함한다)
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

	cout << "계좌ID : ";
	cin >> id;
	cout << "이 름 : ";
	cin >> name;
	cout << "입급액 : ";
	cin >> balance;
	cout << endl;

	account[customer_num++] = new Account(id, balance, name);
}

void AccountHandler::Deposit_Money(void) {
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

void AccountHandler::Withdraw_Money(void) {
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
		cout << "1. 계좌개설" << endl << "2. 입급" << endl << "3. 출금" << endl << "4. 계좌정보 전체 출력" << endl << "5. 프로그램 종료" << endl << "선택 : ";
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
			cout << "잘못된 입력입니다!!" << endl;
		}
	}

	return 0;
}