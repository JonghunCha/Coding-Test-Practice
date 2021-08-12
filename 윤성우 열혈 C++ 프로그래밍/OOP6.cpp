/*
윤성우 열혈 C++ 프로그래밍의 OOP 단계별 프로젝트 6단계를 구현한 코드입니다.
6단계에서는 새로운 기능을 추가한다.
실제로 계좌를 개설하여 입금을 하면 이자가 발생한다. 또 각 계좌마다 이자율에 차이가 있다.
6단계에서는 NormalAccount와 HighCreditAccount라는 것을 추가한다. 
이들은 각각 보통예금계좌와 신용신뢰계좌를 의미하며 둘 사이에는 이자의 차이가 있다.
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
	cout << "계좌ID : " << account_id << endl;
	cout << "이 름 : " << name << endl;
	cout << "잔 액 : " << balance << endl;
}

Account::~Account() {
	delete[]name;
}

/*
NormalAccount 클래스는 Account 클래스를 상속받으며, 보통예금계좌를 의미한다.
입금시 이율을 고려해서 이자를 지급하도록 deposit 함수를 수정한다
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
HighCreditAccount 클래스는 NormalAccount 클래스를 상속받으며, 신용신뢰계좌를 의미한다.
신용신뢰계좌는 신용등급별로 기본이율에 추가적인 이율이 붙는다.
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
	void MakeNormalAccount(void);
	void MakeHighCreditAccount(void);
};

AccountHandler::AccountHandler()
	:customer_num(0) {}

void AccountHandler::Make_Account(void) {
	int option;
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택 : ";
	cin >> option;
	if (option == 1)	MakeNormalAccount();
	else	MakeHighCreditAccount();
}

void AccountHandler::MakeNormalAccount(void) {
	int id, balance, roi;
	char name[100];

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "이 름 : "; cin >> name;
	cout << "입급액 : "; cin >> balance;
	cout << "이자율 : "; cin >> roi;
	cout << endl;

	account[customer_num++] = new NormalAccount(id, balance, name, roi);
}

void AccountHandler::MakeHighCreditAccount(void) {
	int id, balance, roi, credit_option;
	char name[100];

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "이 름 : "; cin >> name;
	cout << "입급액 : "; cin >> balance;
	cout << "이자율 : "; cin >> roi;
	cout << "신용등급(1toA, 2toB, 3toC) : "; cin >> credit_option;
	cout << endl;

	if(credit_option == 1)			account[customer_num++] = new HighCreditAccount(id, balance, name, roi, 7);
	else if(credit_option == 2)		account[customer_num++] = new HighCreditAccount(id, balance, name, roi, 4);
	else							account[customer_num++] = new HighCreditAccount(id, balance, name, roi, 2);
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