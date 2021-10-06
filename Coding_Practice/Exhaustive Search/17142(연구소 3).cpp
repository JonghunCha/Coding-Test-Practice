/*
���� ��ũ : https://www.acmicpc.net/problem/17142
BFS�� �̿��� ���� Ž������ �ذ��� �� �ִ� ������.

�켱 Ȱ�� ���̷��� M���� �����ؾ� �Ѵ�.

���õ� M���� ���̷�����ǥ�� Queue�� �ִ´�.

�׷� ���� Queue���� �ϳ��� pop�ϸ� �ֺ� ĭ�� ���̷����� Ȯ�� ��Ű�� ���Ӱ� Ȯ�� �� ���̷����� Queue�� �־��ش�.

�� ������ Queue�� �������� �ݺ��ϸ� Ȯ�� ������ ���� ���̴�.

���⼭ ������ ��ü�� ���̷����� Ȯ�� �Ǿ����� �ƴ����� �Ǵ��Ͽ� ������ ���ϸ� �ȴ�.
*/
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int answer = 100000;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void Make_Combination(int N, int M, int lab[50][50], int selected, int x, int y);
void Spread(int N, int lab[50][50]);
bool Is_All_Spread(int N, int lab[50][50]);

int main(void) {
	int N, M, lab[50][50];
	//�Է°� ����
	cin >> N; cin >> M;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			cin >> lab[a][b];
		}
	}
	//M���� ������ ����� Ȯ�� �ùķ��̼�
	Make_Combination(N, M, lab, 0, 0, 0);
	if (answer == 100000)	cout << -1;
	else	cout << answer;

	return 0;
}

void Make_Combination(int N, int M, int lab[50][50], int selected, int x, int y) {
	//M���� Ȱ�� ���̷����� �� ��� Ȯ�� �ǽ�
	if (selected == M) {
		Spread(N, lab);
		return;
	}
	//Ȱ�� ���̷����� �ϳ��� ����
	for (int a = y; a < N; a++) {
		if (lab[x][a] == 2) {
			lab[x][a] = 3;
			if (a == N - 1 && x != N - 1)	Make_Combination(N, M, lab, selected + 1, x + 1, 0);
			else	Make_Combination(N, M, lab, selected + 1, x, a + 1);
			lab[x][a] = 2;
		}
	}
	for (int a = x + 1; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (lab[a][b] == 2) {
				lab[a][b] = 3;
				if (b == N - 1 && a != N - 1)	Make_Combination(N, M, lab, selected + 1, a + 1, 0);
				else	Make_Combination(N, M, lab, selected + 1, a, b + 1);
				lab[a][b] = 2;
			}
		}
	}
}

void Spread(int N, int lab[50][50]) {
	//���̷����� ��ǥ�� �����ϴ� ť
	queue<pair<int, int>> q;
	int lab_copy[50][50];	//���� -10000, �ʱ� Ȱ�� ���̷����� 0, ��Ȱ�� ���̷����� -1, ��ĭ�� -100���� �ʱ�ȭ
	int count = 0, x, y;
	bool flag = true;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (lab[a][b] == 0)		lab_copy[a][b] = -100;
			else if (lab[a][b] == 1)	lab_copy[a][b] = -10000;
			else if (lab[a][b] == 2)	lab_copy[a][b] = -1;
			else	lab_copy[a][b] = 0;
		}
	}
	//�ʱ� Ȱ�� ���̷��� ť�� �߰�
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (lab_copy[a][b] == 0)	q.emplace(a, b);
		}
	}
	//���� ó������ ��ĭ�� ���ٸ� ������ 0
	if (Is_All_Spread(N, lab_copy)) {
		answer = 0;
		return;
	}
	while (!q.empty()) {
		int x, y;
		int nx, ny;
		x = q.front().first;
		y = q.front().second;
		q.pop();
		//ť���� �̾Ƴ� ��ǥ�� 4������ ����
		for (int a = 0; a < 4; a++) {
			nx = x + dx[a];
			ny = y + dy[a];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				//�� �����̰ų� ��Ȱ�� ���̷����� �ִ� ���̶�� Ȯ�� ��Ų��
				if (lab_copy[nx][ny] == -100 || lab_copy[nx][ny] == -1) {
					lab_copy[nx][ny] = lab_copy[x][y] + 1;
					//�ּ� �ð� ����
					if (lab_copy[nx][ny] > count && lab[nx][ny] == 0)	count = lab_copy[nx][ny];
					//���Ӱ� Ȯ��� ���̷����� ��ǥ ť�� �߰�
					q.emplace(nx, ny);
				}
			}
		}
	}
	//��� �� ĭ�� ���̷����� Ȯ��� ��� ���� ����
	if (Is_All_Spread(N, lab_copy)) {
		if (count < answer)	answer = count;
	}
}
//�����ǿ� ���̷����� Ȯ����� ���� ���� �ִ��� Ȯ��
bool Is_All_Spread(int N, int lab[50][50]) {
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (lab[a][b] == -100)	return false;
		}
	}
	return true;
}