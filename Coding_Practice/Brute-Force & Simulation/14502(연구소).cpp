/*
���� ��ũ : https://www.acmicpc.net/problem/14502
���� Ž������ �ذ��� �� �ִ� ������.

�� ������ 3���� ���� ����� ��� ���տ� ���� ���̷����� ������ ��Ȳ�� ������ �� ���� ���� ������ ���� ��츦 �����ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int answer = 0;

void Make_Combination(int N, int M, int map[8][8], int step);
void Try_Simulation(int N, int M, int map[8][8]);
void Check_Near(int N, int M, int map[8][8], int x, int y);

int main(void) {
	int N, M, map[8][8];
	//�Է°� ����
	cin >> N; cin >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	//3���� ���� ����� ��� ���տ� ���� �ùķ��̼�
	Make_Combination(N, M, map, 0);
	cout << answer;
	return 0;
}

void Make_Combination(int N, int M, int map[8][8], int step) {
	if (step == 3) {
		Try_Simulation(N, M, map);
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 3;
				Make_Combination(N, M, map, step + 1);
				map[i][j] = 0;
			}
		}
	}
}

void Try_Simulation(int N, int M, int map[8][8]) {
	int _map[8][8], safe_num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			_map[i][j] = map[i][j];
		}
	}
	//���̷����� �ִٸ� ��ó�� �� ������ ���������� �Ѵ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (_map[i][j] == 2) {
				Check_Near(N, M, _map, i, j);
			}
		}
	}
	//���̷����� �� ���� �� ���� ������ ũ�� ���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (_map[i][j] == 0)	safe_num++;
		}
	}
	if (safe_num > answer)	answer = safe_num;
}

void Check_Near(int N, int M, int map[8][8], int x, int y) {
	//���̷����� �ִ� ĭ ���� Ȯ��
	if (x != 0 && map[x - 1][y] == 0) {
		map[x - 1][y] = 2;
		Check_Near(N, M, map, x - 1, y);
	}
	//���̷����� �ִ� ĭ ������ Ȯ��
	if (y != M - 1 && map[x][y + 1] == 0) {
		map[x][y + 1] = 2;
		Check_Near(N, M, map, x, y + 1);
	}
	//���̷����� �ִ� ĭ �Ʒ��� Ȯ��
	if (x != N - 1 && map[x + 1][y] == 0) {
		map[x + 1][y] = 2;
		Check_Near(N, M, map, x + 1, y);
	}
	//���̷����� �ִ� ĭ ���� Ȯ��
	if (y != 0 && map[x][y - 1] == 0) {
		map[x][y - 1] = 2;
		Check_Near(N, M, map, x, y - 1);
	}
}