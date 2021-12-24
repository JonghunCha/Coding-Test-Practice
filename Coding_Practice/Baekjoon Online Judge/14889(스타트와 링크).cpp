/*
���� ��ũ : https://www.acmicpc.net/problem/14889
���� Ž������ �ذ��� �� �ִ�.

���� �ݹ����� ������ ��� ������ ����� �׿� ���ؼ� �ɷ�ġ�� ���� ���Ͽ� �ּڰ��� �����ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int answer = 100000;

void Make_Team(int N, int S[20][20], int team1[10], int team2[10], int team1_num, int team2_num, int step);
void Calculate(int N, int S[20][20], int team1[10], int team2[10]);

int main(void) {
	int N, S[20][20], team1[10], team2[10];
	//�Է°� ����
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}
	Make_Team(N, S, team1, team2, 0, 0, 0);
	cout << answer;

	return 0;
}

void Make_Team(int N, int S[20][20], int team1[10], int team2[10], int team1_num, int team2_num, int step) {
	//��� ������ �� �з��� �Ǹ� �ɷ�ġ�� ���
	if (step == N) {
		Calculate(N, S, team1, team2);
		return;
	}
	if (team1_num < N / 2) {
		team1[team1_num] = step;
		Make_Team(N, S, team1, team2, team1_num + 1, team2_num, step + 1);
	}
	if (team2_num < N / 2) {
		team2[team2_num] = step;
		Make_Team(N, S, team1, team2, team1_num, team2_num + 1, step + 1);
	}
}

void Calculate(int N, int S[20][20], int team1[10], int team2[10]) {
	int team1_sum = 0, team2_sum = 0, diff;
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			team1_sum += S[team1[i]][team1[j]];
		}
	}
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			team2_sum += S[team2[i]][team2[j]];
		}
	}
	if (team1_sum > team2_sum) {
		diff = team1_sum - team2_sum;
		if (diff < answer)	answer = diff;
	}
	else {
		diff = team2_sum - team1_sum;
		if (diff < answer)	answer = diff;
	}
}