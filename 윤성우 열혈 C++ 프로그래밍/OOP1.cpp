#include <iostream>
#include <cstring>

using namespace std;

typedef struct{
	int account_id;
	char name[100];
	int balance;
}Account;

Account account_info[100];
int custom_num = 0;

void make_account(void);		//���°���
void deposit(void);				//�Ա�
void withdraw(void);			//���
void print_all_account(void);	//�������� ��ü ���

int main(void) {
	int option;
	while (1) {
		cout << "-----Menu-----" << endl;
		cout << "1. ���°���" << endl << "2. �Ա�" << endl << "3. ���" << endl << "4. �������� ��ü ���" << endl << "5. ���α׷� ����" << endl<<"���� : ";
		cin >> option;
		cout << endl;
		if (option == 5)	break;
		else if (option == 1) {
			make_account();
		}
		else if (option == 2) {
			deposit();
		}
		else if (option == 3) {
			withdraw();
		}
		else if (option == 4) {
			print_all_account();
		}
	}
	return 0;
}

void make_account(void) {
	int id, money;
	char name[100];
	cout << "����ID : ";
	cin >> id;
	cout << "�� �� : ";
	cin >> name;
	cout << "�Ա޾� : ";
	cin >> money;
	cout << endl;
	account_info[custom_num].account_id = id;
	strcpy(account_info[custom_num].name, name);
	account_info[custom_num].balance = money;
	custom_num++;
}

void deposit(void) {
	int id, money;
	cout << "����ID : ";
	cin >> id;
	cout << "�Աݾ� : ";
	cin >> money;
	for (int i = 0; i < custom_num; i++) {
		if (account_info[i].account_id == id) {
			account_info[i].balance += money;
			break;
		}
	}
	cout << "�ԱݿϷ�" << endl << endl;
}

void withdraw(void) {
	int id, money;
	cout << "����ID : ";
	cin >> id;
	cout << "��ݾ� : ";
	cin >> money;
	for (int i = 0; i < custom_num; i++) {
		if (account_info[i].account_id == id) {
			account_info[i].balance -= money;
			break;
		}
	}
	cout << "��ݿϷ�" << endl << endl;
}

void print_all_account(void) {
	for (int i = 0; i < custom_num; i++) {
		cout << "����ID : " << account_info[i].account_id << endl;
		cout << "�� �� : " << account_info[i].name << endl;
		cout << "�� �� : " << account_info[i].balance << endl << endl;
	}
}