/*
OOP9�� �����Լ�
*/
#include <iostream>
#include <cstring>
#include "AccountHandler.h"
using namespace std;

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