/*
���� ��ũ : https://www.acmicpc.net/problem/12100
���� Ž������ �ذ� �� �� �ִ� ������.

�ѹ��� ���� �� �� �ִ� ����� ��, ��, ��, �� 4���� �̴�. �׸��� �̷��� ������ �ִ� 5�� �Ѵٰ� �Ͽ����� ��� ����� ���� 4^5 = 1024�����̴�.

1024������ ��쿡 ���ؼ� ���� ������ �ùķ��̼� �غ��� ���� ū ����� �������� ���ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int answer = 0;

void Make_Combination(int N, int board[20][20], int combination[5], int step);
void Calculate(int N, int board[20][20], int combination[5]);

int main(void) {
	int N, board[20][20], combination[5];
	//�Է°� ����
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	//��� ������ ����� �ùķ��̼� �ϴ� �Լ� ȣ��
	Make_Combination(N, board, combination, 0);
	cout << answer;

	return 0;
}

void Make_Combination(int N, int board[20][20], int combination[5], int step) {
	//������ �ϼ��ȴٸ� ������ �̵��� �ǽ�
	if (step == 5) {
		Calculate(N, board, combination);
		return;
	}
	combination[step] = 1;
	Make_Combination(N, board, combination, step + 1);
	combination[step] = 2;
	Make_Combination(N, board, combination, step + 1);
	combination[step] = 3;
	Make_Combination(N, board, combination, step + 1);
	combination[step] = 4;
	Make_Combination(N, board, combination, step + 1);
}

void Calculate(int N, int board[20][20], int combination[5]) {
	int board_copy[20][20], now, prev, index;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board_copy[i][j] = board[i][j];
		}
	}
	//�� 5���� ���⿡ ����
	for (int i = 0; i < 5; i++) {
		//�������� ��ġ�� ���
		if (combination[i] == 1) {
			for (int a = 0; a < N; a++) {
				prev = -1;
				index = 0;
				for (int b = 0; b < N; b++) {
					now = board_copy[b][a];
					if (now == 0)	continue;
					else if (prev == -1)	prev = now;
					else if (now == prev) {
						board_copy[index++][a] = now * 2;
						prev = -1;
					}
					else {
						board_copy[index++][a] = prev;
						prev = now;
					}
				}
				if (prev != -1)	board_copy[index++][a] = prev;
				for (int b = index; b < N; b++)		board_copy[b][a] = 0;
			}
		}
		//�������� ��ġ�� ���
		else if (combination[i] == 2) {
			for (int a = 0; a < N; a++) {
				prev = -1;
				index = N - 1;
				for (int b = N - 1; b >= 0; b--) {
					now = board_copy[a][b];
					if (now == 0)	continue;
					else if (prev == -1)	prev = now;
					else if (now == prev) {
						board_copy[a][index--] = now * 2;
						prev = -1;
					}
					else {
						board_copy[a][index--] = prev;
						prev = now;
					}
				}
				if (prev != -1)	board_copy[a][index--] = prev;
				for (int b = index; b >= 0; b--)	board_copy[a][b] = 0;
			}
		}
		//�������� ��ġ�� ���
		else if (combination[i] == 3) {
			for (int a = 0; a < N; a++) {
				prev = -1;
				index = N - 1;
				for (int b = N - 1; b >= 0; b--) {
					now = board_copy[b][a];
					if (now == 0)	continue;
					else if (prev == -1)	prev = now;
					else if (now == prev) {
						board_copy[index--][a] = now * 2;
						prev = -1;
					}
					else {
						board_copy[index--][a] = prev;
						prev = now;
					}
				}
				if (prev != -1)	board_copy[index--][a] = prev;
				for (int b = index; b >= 0; b--)	board_copy[b][a] = 0;
			}
		}
		//�������� ��ġ�� ���
		else {
			for (int a = 0; a < N; a++) {
				prev = -1;
				index = 0;
				for (int b = 0; b < N; b++) {
					now = board_copy[a][b];
					if (now == 0)	continue;
					else if (prev == -1)	prev = now;
					else if (now == prev) {
						board_copy[a][index++] = now * 2;
						prev = -1;
					}
					else {
						board_copy[a][index++] = prev;
						prev = now;
					}
				}
				if (prev != -1)	board_copy[a][index++] = prev;
				for (int b = index; b < N; b++)		board_copy[a][b] = 0;
			}
		}
		//���� ū ���� ����
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (board_copy[a][b] > answer)	answer = board_copy[a][b];
			}
		}
	}
}