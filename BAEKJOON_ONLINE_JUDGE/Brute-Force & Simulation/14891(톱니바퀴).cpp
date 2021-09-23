/*
���� ��ũ : https://www.acmicpc.net/problem/14891
�ܼ� ���� ������.

���� ���ǿ� ���� ��Ϲ����� ȸ���� �����ϰ� ������ ����ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

void Rotate(char wheels[5][8], int wheel_num, int direction);

int main(void) {
	int K, rotate[100][2], answer = 0;
	char wheels[5][8];
	//������ ������ ȸ���Կ� ���� ���������� ȸ�� �ϴ����� ��Ÿ���� ����(true�� ȸ��, false�� ȸ��x)
	bool connect1, connect2, connect3;
	//�Է°� ����
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> wheels[i][j];
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> rotate[i][0];
		cin >> rotate[i][1];
	}
	//��� ȸ���� ����
	for (int i = 0; i < K; i++) {
		//1�� 2�� ������ ���� �κ� Ȯ��
		if (wheels[1][2] != wheels[2][6])	connect1 = true;
		else	connect1 = false;
		//2�� 3�� ������ ���� �κ� Ȯ��
		if (wheels[2][2] != wheels[3][6])	connect2 = true;
		else	connect2 = false;
		//3�� 4�� ������ ���� �κ� Ȯ��
		if (wheels[3][2] != wheels[4][6])	connect3 = true;
		else	connect3 = false;
		//1�� ������ ȸ���ϴ� ���
		if (rotate[i][0] == 1) {
			Rotate(wheels, 1, rotate[i][1]);
			if (connect1) {
				Rotate(wheels, 2, -rotate[i][1]);
				if (connect2) {
					Rotate(wheels, 3, rotate[i][1]);
					if (connect3) {
						Rotate(wheels, 4, -rotate[i][1]);
					}
				}
			}
		}
		//2�� ������ ȸ���ϴ� ���
		else if (rotate[i][0] == 2) {
			if (connect1)	Rotate(wheels, 1, -rotate[i][1]);
			Rotate(wheels, 2, rotate[i][1]);
			if (connect2) {
				Rotate(wheels, 3, -rotate[i][1]);
				if (connect3) {
					Rotate(wheels, 4, rotate[i][1]);
				}
			}
		}
		//3�� ������ ȸ���ϴ� ���
		else if (rotate[i][0] == 3) {
			if (connect3) Rotate(wheels, 4, -rotate[i][1]);
			Rotate(wheels, 3, rotate[i][1]);
			if (connect2) {
				Rotate(wheels, 2, -rotate[i][1]);
				if (connect1) {
					Rotate(wheels, 1, rotate[i][1]);
				}
			}
		}
		//4�� ������ ȸ���ϴ� ���
		else {
			Rotate(wheels, 4, rotate[i][1]);
			if (connect3) {
				Rotate(wheels, 3, -rotate[i][1]);
				if (connect2) {
					Rotate(wheels, 2, rotate[i][1]);
					if (connect1) {
						Rotate(wheels, 1, -rotate[i][1]);
					}
				}
			}
		}
	}

	if (wheels[1][0] == '1')	answer++;
	if (wheels[2][0] == '1')	answer += 2;
	if (wheels[3][0] == '1')	answer += 4;
	if (wheels[4][0] == '1')	answer += 8;
	cout << answer;
	return 0;
}

void Rotate(char wheels[5][8], int wheel_num, int direction) {
	char temp;
	//�ð���� ȸ��
	if (direction == 1) {
		temp = wheels[wheel_num][7];
		for (int i = 7; i > 0; i--) {
			wheels[wheel_num][i] = wheels[wheel_num][i - 1];
		}
		wheels[wheel_num][0] = temp;
	}
	//�ݽð���� ȸ��
	else {
		temp = wheels[wheel_num][0];
		for (int i = 0; i < 7; i++) {
			wheels[wheel_num][i] = wheels[wheel_num][i + 1];
		}
		wheels[wheel_num][7] = temp;
	}
}