/*
���� ��ũ : https://www.acmicpc.net/problem/17140
�ܼ� ���� �����̳�, ������ �ؾ� �Ѵ�.

���Ŀ��� 2���� ������ �ִµ� ���� ���� ���� Ƚ���� Ŀ���� ��� ������ �ϵ�, ���� Ƚ���� �Ȱ��ٸ� ���� Ŀ���� ������ �����ؾ� �Ѵ�.

�� �������� ���� �� �ִ� ���� �ִ��� 100�̴�.

���� num_count[101]�̶�� ������ �� ���� ���� Ƚ���� ������ �� ���� ���� ��Ģ�� ��Ű���� �迭 ������ �ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int main(void) {
	int R, C, K, A[101][101], answer = 0, num_count[101], row_num = 3, col_num = 3, index, temp;
	//�Է°� ����
	for (int a = 0; a < 101; a++) {
		for (int b = 0; b < 101; b++) {
			A[a][b] = 0;
		}
	}
	cin >> R; cin >> C; cin >> K;
	for (int a = 1; a <= 3; a++) {
		for (int b = 1; b <= 3; b++) {
			cin >> A[a][b];
		}
	}
	//�ִ� 100�ʱ��� �ݺ�
	while (answer <= 100) {
		if (A[R][C] == K)	break;
		//���� ���� ���� ������ ���� ���
		if (row_num >= col_num) {
			for (int a = 1; a <= row_num; a++) {
				//�� ���� ���� Ƚ���� ����
				memset(num_count, 0, 101);
				for (int b = 1; b <= col_num; b++) {
					if (A[a][b] != 0)	num_count[A[a][b]]++;
				}
				for (int b = 1; b < 101; b++)	A[a][b] = 0;
				index = 1;
				//1���� 100���� ���ɴ�
				for (int b = 1; b < 101; b++) {
					//�ִ� 100���� ��� �� ����
					if (index > 100)	break;
					for (int c = 1; c < 101; c++) {
						if (index > 100)	break;
						if (num_count[c] == b) {
							A[a][index++] = c;
							A[a][index++] = num_count[c];
						}
					}
				}
			}
			//col_num ����
			for (int a = 1; a <= row_num; a++) {
				temp = 0;
				for (int b = 1; b < 101; b++) {
					if (A[a][b] == 0)	break;
					temp++;
				}
				if (temp > col_num)	col_num = temp;
			}
		}
		//���� ���� ���� ������ ���� ���
		else {
			for (int a = 1; a <= col_num; a++) {
				memset(num_count, 0, 101);
				for (int b = 1; b <= row_num; b++) {
					if (A[b][a] != 0)	num_count[A[b][a]]++;
				}
				for (int b = 1; b < 101; b++)	A[b][a] = 0;
				index = 1;
				for (int b = 1; b < 101; b++) {
					if (index > 100)	break;
					for (int c = 1; c < 101; c++) {
						if (index > 100)	break;
						if (num_count[c] == b) {
							A[index++][a] = c;
							A[index++][a] = num_count[c];
						}
					}
				}
			}
			for (int a = 1; a <= col_num; a++) {
				temp = 0;
				for (int b = 1; b < 101; b++) {
					if (A[b][a] == 0)	break;
					temp++;
				}
				if (temp > row_num)	row_num = temp;
			}
		}
		answer++;
	}

	if (answer > 100)	cout << -1;
	else	cout << answer;

	return 0;
}