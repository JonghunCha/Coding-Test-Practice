/*
���� ��ũ : https://www.acmicpc.net/problem/5373
�ܼ� ���� �����̴�.

Ǯ�̹��̶�� �� �͵� ����. �׳� ť�긦 �� ȸ���� ��Ű�� �ȴ�. �ٸ� 3���� ť�긦 ȸ�� ��ų �� �迭�� �ε����� ���׹��� ���� �ʵ��� �Ű��� �� ����ϴ� �κ��� �ִ�.
*/
#include <iostream>
using namespace std;

void rotate(char cube[6][3][3], char input[3]);

int main(void) {
	int testcase, n;
	char cube[6][3][3];	//index 0->����, 1->�����ʸ�, 2->�ո�, 3->���ʸ�, 4->�޸�, 5->�Ʒ���
	char input[3];
	//�Է°� ����
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		//�� �׽�Ʈ���̽����� ť�� �ʱ�ȭ
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				cube[0][a][b] = 'w';
				cube[1][a][b] = 'b';
				cube[2][a][b] = 'r';
				cube[3][a][b] = 'g';
				cube[4][a][b] = 'o';
				cube[5][a][b] = 'y';
			}
		}
		//ȸ�� ��� �Է� �ް� ȸ�� �ǽ�
		cin >> n;
		for (int a = 0; a < n; a++) {
			cin >> input;
			rotate(cube, input);
		}

		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				cout << cube[0][a][b];
			}
			cout << endl;
		}
	}

	return 0;
}
//�Լ� ���� �ڵ�� ������ �� �������. �׳� ȸ�� ��Ŀ� ���� ť�긦 ȸ�����ִ� ��� ���̴�.
void rotate(char cube[6][3][3], char input[3]) {
	char temp[3];
	if (input[0] == 'U' && input[1] == '+') {
		temp[0] = cube[4][0][0]; temp[1] = cube[4][0][1]; temp[2] = cube[4][0][2];
		cube[4][0][0] = cube[3][0][0]; cube[4][0][1] = cube[3][0][1]; cube[4][0][2] = cube[3][0][2];
		cube[3][0][0] = cube[2][0][0]; cube[3][0][1] = cube[2][0][1]; cube[3][0][2] = cube[2][0][2];
		cube[2][0][0] = cube[1][0][0]; cube[2][0][1] = cube[1][0][1]; cube[2][0][2] = cube[1][0][2];
		cube[1][0][0] = temp[0]; cube[1][0][1] = temp[1]; cube[1][0][2] = temp[2];
		temp[0] = cube[0][0][0]; temp[1] = cube[0][0][1];
		cube[0][0][0] = cube[0][2][0]; cube[0][2][0] = cube[0][2][2]; cube[0][2][2] = cube[0][0][2]; cube[0][0][2] = temp[0];
		cube[0][0][1] = cube[0][1][0]; cube[0][1][0] = cube[0][2][1]; cube[0][2][1] = cube[0][1][2]; cube[0][1][2] = temp[1];
	}
	else if (input[0] == 'U' && input[1] == '-') {
		temp[0] = cube[1][0][0]; temp[1] = cube[1][0][1]; temp[2] = cube[1][0][2];
		cube[1][0][0] = cube[2][0][0]; cube[1][0][1] = cube[2][0][1]; cube[1][0][2] = cube[2][0][2];
		cube[2][0][0] = cube[3][0][0]; cube[2][0][1] = cube[3][0][1]; cube[2][0][2] = cube[3][0][2];
		cube[3][0][0] = cube[4][0][0]; cube[3][0][1] = cube[4][0][1]; cube[3][0][2] = cube[4][0][2];
		cube[4][0][0] = temp[0]; cube[4][0][1] = temp[1]; cube[4][0][2] = temp[2];
		temp[0] = cube[0][0][0]; temp[1] = cube[0][0][1];
		cube[0][0][0] = cube[0][0][2]; cube[0][0][2] = cube[0][2][2]; cube[0][2][2] = cube[0][2][0]; cube[0][2][0] = temp[0];
		cube[0][0][1] = cube[0][1][2]; cube[0][1][2] = cube[0][2][1]; cube[0][2][1] = cube[0][1][0]; cube[0][1][0] = temp[1];
	}
	else if (input[0] == 'D' && input[1] == '+') {
		temp[0] = cube[1][2][0]; temp[1] = cube[1][2][1]; temp[2] = cube[1][2][2];
		cube[1][2][0] = cube[2][2][0]; cube[1][2][1] = cube[2][2][1]; cube[1][2][2] = cube[2][2][2];
		cube[2][2][0] = cube[3][2][0]; cube[2][2][1] = cube[3][2][1]; cube[2][2][2] = cube[3][2][2];
		cube[3][2][0] = cube[4][2][0]; cube[3][2][1] = cube[4][2][1]; cube[3][2][2] = cube[4][2][2];
		cube[4][2][0] = temp[0]; cube[4][2][1] = temp[1]; cube[4][2][2] = temp[2];
		temp[0] = cube[5][0][0]; temp[1] = cube[5][0][1];
		cube[5][0][0] = cube[5][2][0]; cube[5][2][0] = cube[5][2][2]; cube[5][2][2] = cube[5][0][2]; cube[5][0][2] = temp[0];
		cube[5][0][1] = cube[5][1][0]; cube[5][1][0] = cube[5][2][1]; cube[5][2][1] = cube[5][1][2]; cube[5][1][2] = temp[1];
	}
	else if (input[0] == 'D' && input[1] == '-') {
		temp[0] = cube[4][2][0]; temp[1] = cube[4][2][1]; temp[2] = cube[4][2][2];
		cube[4][2][0] = cube[3][2][0]; cube[4][2][1] = cube[3][2][1]; cube[4][2][2] = cube[3][2][2];
		cube[3][2][0] = cube[2][2][0]; cube[3][2][1] = cube[2][2][1]; cube[3][2][2] = cube[2][2][2];
		cube[2][2][0] = cube[1][2][0]; cube[2][2][1] = cube[1][2][1]; cube[2][2][2] = cube[1][2][2];
		cube[1][2][0] = temp[0]; cube[1][2][1] = temp[1]; cube[1][2][2] = temp[2];
		temp[0] = cube[5][0][0]; temp[1] = cube[5][0][1];
		cube[5][0][0] = cube[5][0][2]; cube[5][0][2] = cube[5][2][2]; cube[5][2][2] = cube[5][2][0]; cube[5][2][0] = temp[0];
		cube[5][0][1] = cube[5][1][2]; cube[5][1][2] = cube[5][2][1]; cube[5][2][1] = cube[5][1][0]; cube[5][1][0] = temp[1];
	}
	else if (input[0] == 'F' && input[1] == '+') {
		temp[0] = cube[0][2][0]; temp[1] = cube[0][2][1]; temp[2] = cube[0][2][2];
		cube[0][2][0] = cube[3][2][2]; cube[0][2][1] = cube[3][1][2]; cube[0][2][2] = cube[3][0][2];
		cube[3][2][2] = cube[5][0][2]; cube[3][1][2] = cube[5][0][1]; cube[3][0][2] = cube[5][0][0];
		cube[5][0][2] = cube[1][0][0]; cube[5][0][1] = cube[1][1][0]; cube[5][0][0] = cube[1][2][0];
		cube[1][0][0] = temp[0]; cube[1][1][0] = temp[1]; cube[1][2][0] = temp[2];
		temp[0] = cube[2][0][0]; temp[1] = cube[2][0][1];
		cube[2][0][0] = cube[2][2][0]; cube[2][2][0] = cube[2][2][2]; cube[2][2][2] = cube[2][0][2]; cube[2][0][2] = temp[0];
		cube[2][0][1] = cube[2][1][0]; cube[2][1][0] = cube[2][2][1]; cube[2][2][1] = cube[2][1][2]; cube[2][1][2] = temp[1];
	}
	else if (input[0] == 'F' && input[1] == '-') {
		temp[0] = cube[3][2][2]; temp[1] = cube[3][1][2]; temp[2] = cube[3][0][2];
		cube[3][2][2] = cube[0][2][0]; cube[3][1][2] = cube[0][2][1]; cube[3][0][2] = cube[0][2][2];
		cube[0][2][0] = cube[1][0][0]; cube[0][2][1] = cube[1][1][0]; cube[0][2][2] = cube[1][2][0];
		cube[1][0][0] = cube[5][0][2]; cube[1][1][0] = cube[5][0][1]; cube[1][2][0] = cube[5][0][0];
		cube[5][0][2] = temp[0]; cube[5][0][1] = temp[1]; cube[5][0][0] = temp[2];
		temp[0] = cube[2][0][0]; temp[1] = cube[2][0][1];
		cube[2][0][0] = cube[2][0][2]; cube[2][0][2] = cube[2][2][2]; cube[2][2][2] = cube[2][2][0]; cube[2][2][0] = temp[0];
		cube[2][0][1] = cube[2][1][2]; cube[2][1][2] = cube[2][2][1]; cube[2][2][1] = cube[2][1][0]; cube[2][1][0] = temp[1];
	}
	else if (input[0] == 'B' && input[1] == '+') {
		temp[0] = cube[0][0][0]; temp[1] = cube[0][0][1]; temp[2] = cube[0][0][2];
		cube[0][0][0] = cube[1][0][2]; cube[0][0][1] = cube[1][1][2]; cube[0][0][2] = cube[1][2][2];
		cube[1][0][2] = cube[5][2][2]; cube[1][1][2] = cube[5][2][1]; cube[1][2][2] = cube[5][2][0];
		cube[5][2][2] = cube[3][2][0]; cube[5][2][1] = cube[3][1][0]; cube[5][2][0] = cube[3][0][0];
		cube[3][2][0] = temp[0]; cube[3][1][0] = temp[1]; cube[3][0][0] = temp[2];
		temp[0] = cube[4][0][0]; temp[1] = cube[4][0][1];
		cube[4][0][0] = cube[4][2][0]; cube[4][2][0] = cube[4][2][2]; cube[4][2][2] = cube[4][0][2]; cube[4][0][2] = temp[0];
		cube[4][0][1] = cube[4][1][0]; cube[4][1][0] = cube[4][2][1]; cube[4][2][1] = cube[4][1][2]; cube[4][1][2] = temp[1];
	}
	else if (input[0] == 'B' && input[1] == '-') {
		temp[0] = cube[0][0][0]; temp[1] = cube[0][0][1]; temp[2] = cube[0][0][2];
		cube[0][0][0] = cube[3][2][0]; cube[0][0][1] = cube[3][1][0]; cube[0][0][2] = cube[3][0][0];
		cube[3][2][0] = cube[5][2][2]; cube[3][1][0] = cube[5][2][1]; cube[3][0][0] = cube[5][2][0];
		cube[5][2][2] = cube[1][0][2]; cube[5][2][1] = cube[1][1][2]; cube[5][2][0] = cube[1][2][2];
		cube[1][0][2] = temp[0]; cube[1][1][2] = temp[1]; cube[1][2][2] = temp[2];
		temp[0] = cube[4][0][0]; temp[1] = cube[4][0][1];
		cube[4][0][0] = cube[4][0][2]; cube[4][0][2] = cube[4][2][2]; cube[4][2][2] = cube[4][2][0]; cube[4][2][0] = temp[0];
		cube[4][0][1] = cube[4][1][2]; cube[4][1][2] = cube[4][2][1]; cube[4][2][1] = cube[4][1][0]; cube[4][1][0] = temp[1];
	}
	else if (input[0] == 'L' && input[1] == '+') {
		temp[0] = cube[0][0][0]; temp[1] = cube[0][1][0]; temp[2] = cube[0][2][0];
		cube[0][0][0] = cube[4][2][2]; cube[0][1][0] = cube[4][1][2]; cube[0][2][0] = cube[4][0][2];
		cube[4][2][2] = cube[5][0][0]; cube[4][1][2] = cube[5][1][0]; cube[4][0][2] = cube[5][2][0];
		cube[5][0][0] = cube[2][0][0]; cube[5][1][0] = cube[2][1][0]; cube[5][2][0] = cube[2][2][0];
		cube[2][0][0] = temp[0]; cube[2][1][0] = temp[1]; cube[2][2][0] = temp[2];
		temp[0] = cube[3][0][0]; temp[1] = cube[3][0][1];
		cube[3][0][0] = cube[3][2][0]; cube[3][2][0] = cube[3][2][2]; cube[3][2][2] = cube[3][0][2]; cube[3][0][2] = temp[0];
		cube[3][0][1] = cube[3][1][0]; cube[3][1][0] = cube[3][2][1]; cube[3][2][1] = cube[3][1][2]; cube[3][1][2] = temp[1];
	}
	else if (input[0] == 'L' && input[1] == '-') {
		temp[0] = cube[0][0][0]; temp[1] = cube[0][1][0]; temp[2] = cube[0][2][0];
		cube[0][0][0] = cube[2][0][0]; cube[0][1][0] = cube[2][1][0]; cube[0][2][0] = cube[2][2][0];
		cube[2][0][0] = cube[5][0][0]; cube[2][1][0] = cube[5][1][0]; cube[2][2][0] = cube[5][2][0];
		cube[5][0][0] = cube[4][2][2]; cube[5][1][0] = cube[4][1][2]; cube[5][2][0] = cube[4][0][2];
		cube[4][2][2] = temp[0]; cube[4][1][2] = temp[1]; cube[4][0][2] = temp[2];
		temp[0] = cube[3][0][0]; temp[1] = cube[3][0][1];
		cube[3][0][0] = cube[3][0][2]; cube[3][0][2] = cube[3][2][2]; cube[3][2][2] = cube[3][2][0]; cube[3][2][0] = temp[0];
		cube[3][0][1] = cube[3][1][2]; cube[3][1][2] = cube[3][2][1]; cube[3][2][1] = cube[3][1][0]; cube[3][1][0] = temp[1];
	}
	else if (input[0] == 'R' && input[1] == '+') {
		temp[0] = cube[0][2][2]; temp[1] = cube[0][1][2]; temp[2] = cube[0][0][2];
		cube[0][2][2] = cube[2][2][2]; cube[0][1][2] = cube[2][1][2]; cube[0][0][2] = cube[2][0][2];
		cube[2][2][2] = cube[5][2][2]; cube[2][1][2] = cube[5][1][2]; cube[2][0][2] = cube[5][0][2];
		cube[5][2][2] = cube[4][0][0]; cube[5][1][2] = cube[4][1][0]; cube[5][0][2] = cube[4][2][0];
		cube[4][0][0] = temp[0]; cube[4][1][0] = temp[1]; cube[4][2][0] = temp[2];
		temp[0] = cube[1][0][0]; temp[1] = cube[1][0][1];
		cube[1][0][0] = cube[1][2][0]; cube[1][2][0] = cube[1][2][2]; cube[1][2][2] = cube[1][0][2]; cube[1][0][2] = temp[0];
		cube[1][0][1] = cube[1][1][0]; cube[1][1][0] = cube[1][2][1]; cube[1][2][1] = cube[1][1][2]; cube[1][1][2] = temp[1];
	}
	else if (input[0] == 'R' && input[1] == '-') {
		temp[0] = cube[0][2][2]; temp[1] = cube[0][1][2]; temp[2] = cube[0][0][2];
		cube[0][2][2] = cube[4][0][0]; cube[0][1][2] = cube[4][1][0]; cube[0][0][2] = cube[4][2][0];
		cube[4][0][0] = cube[5][2][2]; cube[4][1][0] = cube[5][1][2]; cube[4][2][0] = cube[5][0][2];
		cube[5][2][2] = cube[2][2][2]; cube[5][1][2] = cube[2][1][2]; cube[5][0][2] = cube[2][0][2];
		cube[2][2][2] = temp[0]; cube[2][1][2] = temp[1]; cube[2][0][2] = temp[2];
		temp[0] = cube[1][0][0]; temp[1] = cube[1][0][1];
		cube[1][0][0] = cube[1][0][2]; cube[1][0][2] = cube[1][2][2]; cube[1][2][2] = cube[1][2][0]; cube[1][2][0] = temp[0];
		cube[1][0][1] = cube[1][1][2]; cube[1][1][2] = cube[1][2][1]; cube[1][2][1] = cube[1][1][0]; cube[1][1][0] = temp[1];
	}
	else {
		cout << "Invalid Input" << endl;
	}
}