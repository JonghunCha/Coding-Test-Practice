/*
���� ��ũ : https://www.acmicpc.net/problem/17136
����Ž���� ���� �ذ��� �� �ִ� ������.
�����̸� �ּ������� ����ϱ� ���ؼ� ū �����̸� ���� ���� ���� �����̴� ���� ���°� �����ϴ�.
���� ĭ�� �ϳ��ϳ� ���Ǹ� �ش� ĭ�� ���� �� ���������� ������ �ִ��� ���簢������ Ž���� �ϸ� �ȴ�.
�׷��� ���� ������� ã�Ƴ� ��� ĭ�� 3*3�� �������� 3*3�� ���°��� �ּ��� �ƴ� ���� ��쵵 �߻��Ѵ�.
1 1 1 1
1 1 1 1
1 1 1
1 1
���� ���� ��� 3*3 1��� 1*1 4���� ����ϴ� ���� 2*2 3��� 1*1 1���� ����ϴ� �ͺ��� �� ���� �����̸� ����Ѵ�.
�̷��� ���ܸ� ��Ƴ��� ���� ū �����̺��� �������� Ž���ϵ�, ū �����̸� ����ϴ� ���� �׺��� ���� �����̸� ����ϴ� ������ ��� ����� �� �ֵ��� �Ͽ���.
*/
#include <iostream>
using namespace std;

int answer = 25;

void Get_Answer(int map[10][10], int size1, int size2, int size3, int size4, int size5, int num);
bool Check_Map(const int map[10][10], int size, int row, int col);

int main(void) {
	int map[10][10], num = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)	num++;
		}
	}

	Get_Answer(map, 5, 5, 5, 5, 5, num);

	if (answer == 25)	cout << -1;
	else	cout << answer;

	return 0;
}
//map�� ���� �����̷� �������� ���� �κ��� 1, �����̷� ������ �κа� ������ �ȵǴ� �κ��� 0���� ǥ��
//size1~5�� ���� ũ�⺰�� ���� �������� ����, num�� ����� �� 1ĭ�� ������ �ǹ�
void Get_Answer(int map[10][10], int size1, int size2, int size3, int size4, int size5, int num) {
	int attached;
	//����� �� ĭ�� ������ �� ���� �����̸� ����ߴ��� ����ϰ� answer���� ��, �ֽ�ȭ �Ѵ�
	if (num == 0) {
		attached = 25 - size1 - size2 - size3 - size4 - size5;
		if (attached < answer)	answer = attached;
		return;
	}
	//����� �� ĭ�� ���� ���
	else {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				//1�� ĭ�� �߰��ϰ� �� ��
				if (map[i][j] == 1) {
					//5*5�����̸� ���� �� �ִ��� Ȯ��
					if (size5 > 0 && Check_Map(map, 5, i, j)) {
						//5*5�� ���� ���
						size5--;
						for (int a = i; a < i + 5; a++) {
							for (int b = j; b < j + 5; b++) {
								map[a][b] = 0;
							}
						}
						Get_Answer(map, size1, size2, size3, size4, size5, num - 25);
						//5*5�� ���� �� ������ ���� �ʴ� ���
						size5++;
						for (int a = i; a < i + 5; a++) {
							for (int b = j; b < j + 5; b++) {
								map[a][b] = 1;
							}
						}
					}
					//4*4�����̸� ���� �� �ִ��� Ȯ��
					if (size4 > 0 && Check_Map(map, 4, i, j)) {
						//4*4�� ���� ���
						size4--;
						for (int a = i; a < i + 4; a++) {
							for (int b = j; b < j + 4; b++) {
								map[a][b] = 0;
							}
						}
						Get_Answer(map, size1, size2, size3, size4, size5, num - 16);
						//4*4�� ���� �� ������ ���� �ʴ� ���
						size4++;
						for (int a = i; a < i + 4; a++) {
							for (int b = j; b < j + 4; b++) {
								map[a][b] = 1;
							}
						}
					}
					//3*3�����̸� ���� �� �ִ��� Ȯ��
					if (size3 > 0 && Check_Map(map, 3, i, j)) {
						//3*3�� ���� ���
						size3--;
						for (int a = i; a < i + 3; a++) {
							for (int b = j; b < j + 3; b++) {
								map[a][b] = 0;
							}
						}
						Get_Answer(map, size1, size2, size3, size4, size5, num - 9);
						//3*3�� ���� �� ������ ���� �ʴ� ���
						size3++;
						for (int a = i; a < i + 3; a++) {
							for (int b = j; b < j + 3; b++) {
								map[a][b] = 1;
							}
						}
					}
					//2*2�����̸� ���� �� �ִ��� Ȯ��
					if (size2 > 0 && Check_Map(map, 2, i, j)) {
						//2*2�� ���� ���
						size2--;
						for (int a = i; a < i + 2; a++) {
							for (int b = j; b < j + 2; b++) {
								map[a][b] = 0;
							}
						}
						Get_Answer(map, size1, size2, size3, size4, size5, num - 4);
						//2*2�� ���� �� ������ ���� �ʴ� ���
						size2++;
						for (int a = i; a < i + 2; a++) {
							for (int b = j; b < j + 2; b++) {
								map[a][b] = 1;
							}
						}
					}
					//1*1�����̸� ���� �� �ִ��� Ȯ��
					if (size1 > 0) {
						//1*1�� ���� ���
						size1--;
						map[i][j] = 0;
						Get_Answer(map, size1, size2, size3, size4, size5, num - 1);
						//1*1�� ���� �� ������ ���� �ʴ� ���
						size1++;
						map[i][j] = 1;
					}
					return;
				}
			}
		}
		return;
	}
}
//row, col������ ���� ���� �� ���������� ������ sizeũ���� ���簢���� ��� ����� �� ĭ���� Ȯ���ϴ� �Լ�
bool Check_Map(const int map[10][10], int size, int row, int col) {
	if (size + row > 10 || size + col > 10)	return false;
	else {
		for (int i = row; i < row + size; i++) {
			for (int j = col; j < col + size; j++) {
				if (map[i][j] == 0)	return false;
			}
		}
		return true;
	}
}