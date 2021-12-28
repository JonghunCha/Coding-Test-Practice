/*
���� ��ũ : https://www.acmicpc.net/problem/13460
���� Ž������ �ذ� �� �� �ִ� ������.

�ٸ� ���� ���ǿ��� ���� ���� ���� �������� �Ķ� ���� ������ ������ ����̴� �� �κи� ���� ó�� �� �ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

bool Make_Combination(int N, int M, char board[10][10], int direction[11], int step, int index);
bool Try_Game(int N, int M, char board[10][10], int direction[11], int step);

int main(void) {
	int N, M;
	char board[10][10];
	//0 = ���� ���� �ȵ�, 1 = ���� ����̱�, 2 = ���������� ����̱�, 3 = �Ʒ��� �����, 4 = �������� ����̱�
	int direction[11];
	//�Է°� ����
	cin >> N; cin >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	//�������� Ƚ���� 1~10���� ������ Ž���Ѵ�
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j <= 10; j++) direction[j] = 0;
		if (Make_Combination(N, M, board, direction, i, 1)) {
			cout << i;
			return 0;
		}
	}

	cout << -1;
	return 0;
}
//step�� ��ŭ �̵��Ѵٰ� �� �� ������ ��� ���տ� ���� Try_Gameȣ��
bool Make_Combination(int N, int M, char board[10][10], int direction[12], int step, int index) {
	if (index > step) {
		if (Try_Game(N, M, board, direction, step))	return true;
		return false;
	}
	direction[index] = 1;
	if (Make_Combination(N, M, board, direction, step, index + 1))	return true;
	direction[index] = 2;
	if (Make_Combination(N, M, board, direction, step, index + 1))	return true;
	direction[index] = 3;
	if (Make_Combination(N, M, board, direction, step, index + 1))	return true;
	direction[index] = 4;
	if (Make_Combination(N, M, board, direction, step, index + 1))	return true;
	return false;
}
//����� �̵� Ƚ���� �������� �� ���ǿ� �°� �����ϴ��� �����ϴ��� ��ȯ
bool Try_Game(int N, int M, char board[10][10], int direction[12], int step) {
	char board_copy[10][10];
	int temp, flag;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board_copy[i][j] = board[i][j];
		}
	}
	//flag�� 0�̸� �������� ���� ������ ���� �����̰�, 1�̸� ���� ���� ����
	flag = 0;
	for (int i = 1; i <= step; i++) {
		//���� ����̴� ���
		if (direction[i] == 1) {
			for (int a = 1; a < N - 1; a++) {
				for (int b = 1; b < M - 1; b++) {
					if (board_copy[a][b] == 'R') {
						temp = a;
						while (1) {
							if (board_copy[temp - 1][b] == '#' || board_copy[temp - 1][b] == 'B') {
								board_copy[a][b] = '.';
								board_copy[temp][b] = 'R';
								break;
							}
							else if (board_copy[temp - 1][b] == '.')	temp--;
							else {
								flag = 1;
								board_copy[a][b] = '.';
								break;
							}
						}
					}
					else if (board_copy[a][b] == 'B') {
						temp = a;
						while (1) {
							if (board_copy[temp - 1][b] == '#' || board_copy[temp - 1][b] == 'R') {
								board_copy[a][b] = '.';
								board_copy[temp][b] = 'B';
								break;
							}
							else if (board_copy[temp - 1][b] == '.')	temp--;
							else return false;
						}
					}
				}
			}
		}
		//���������� ����̴� ���
		else if (direction[i] == 2) {
			for (int a = 1; a < N - 1; a++){
				for (int b = M - 2; b > 0; b--) {
					if (board_copy[a][b] == 'R') {
						temp = b;
						while (1) {
							if (board_copy[a][temp + 1] == '#' || board_copy[a][temp + 1] == 'B') {
								board_copy[a][b] = '.';
								board_copy[a][temp] = 'R';
								break;
							}
							else if (board_copy[a][temp + 1] == '.')	temp++;
							else {
								flag = 1;
								board_copy[a][b] = '.';
								break;
							}
						}
					}
					if (board_copy[a][b] == 'B') {
						temp = b;
						while (1) {
							if (board_copy[a][temp + 1] == '#' || board_copy[a][temp + 1] == 'R') {
								board_copy[a][b] = '.';
								board_copy[a][temp] = 'B';
								break;
							}
							else if (board_copy[a][temp + 1] == '.')	temp++;
							else return false;
						}
					}
				}
			}
		}
		//�Ʒ��� ����̴� ���
		else if (direction[i] == 3) {
			for (int a = N - 2; a > 0; a--) {
				for (int b = 1; b < M - 1; b++) {
					if (board_copy[a][b] == 'R') {
						temp = a;
						while (1) {
							if (board_copy[temp + 1][b] == '#' || board_copy[temp + 1][b] == 'B') {
								board_copy[a][b] = '.';
								board_copy[temp][b] = 'R';
								break;
							}
							else if (board_copy[temp + 1][b] == '.')	temp++;
							else {
								flag = 1;
								board_copy[a][b] = '.';
								break;
							}
						}
					}
					if (board_copy[a][b] == 'B') {
						temp = a;
						while (1) {
							if (board_copy[temp + 1][b] == '#' || board_copy[temp + 1][b] == 'R') {
								board_copy[a][b] = '.';
								board_copy[temp][b] = 'B';
								break;
							}
							else if (board_copy[temp + 1][b] == '.')	temp++;
							else return false;
						}
					}
				}
			}
		}
		//�������� ����̴� ���
		else {
			for (int a = 1; a < N - 1; a++) {
				for (int b = 1; b < M - 1; b++) {
					if (board_copy[a][b] == 'R') {
						temp = b;
						while (1) {
							if (board_copy[a][temp - 1] == '#' || board_copy[a][temp - 1] == 'B') {
								board_copy[a][b] = '.';
								board_copy[a][temp] = 'R';
								break;
							}
							else if (board_copy[a][temp - 1] == '.')	temp--;
							else {
								flag = 1;
								board_copy[a][b] = '.';
								break;
							}
						}
					}
					if (board_copy[a][b] == 'B') {
						temp = b;
						while (1) {
							if (board_copy[a][temp - 1] == '#' || board_copy[a][temp - 1] == 'R') {
								board_copy[a][b] = '.';
								board_copy[a][temp] = 'B';
								break;
							}
							else if (board_copy[a][temp - 1] == '.')	temp--;
							else return false;
						}
					}
				}
			}
		}
	}
	if (flag == 1)	return true;
	return false;
}