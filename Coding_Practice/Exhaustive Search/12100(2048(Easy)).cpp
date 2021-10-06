/*
문제 링크 : https://www.acmicpc.net/problem/12100
완전 탐색으로 해결 할 수 있는 문제다.

한번에 결정 할 수 있는 방법은 동, 서, 남, 북 4가지 이다. 그리고 이러한 결정을 최대 5번 한다고 하였으니 모든 경우의 수는 4^5 = 1024가지이다.

1024가지의 경우에 대해서 직접 게임을 시뮬레이션 해보고 가장 큰 블록이 무엇인지 구하면 된다.
*/
#include <iostream>
using namespace std;

int answer = 0;

void Make_Combination(int N, int board[20][20], int combination[5], int step);
void Calculate(int N, int board[20][20], int combination[5]);

int main(void) {
	int N, board[20][20], combination[5];
	//입력값 저장
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	//모든 조합을 만들고 시뮬레이션 하는 함수 호출
	Make_Combination(N, board, combination, 0);
	cout << answer;

	return 0;
}

void Make_Combination(int N, int board[20][20], int combination[5], int step) {
	//조합이 완성된다면 실제로 이동을 실시
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
	//총 5번의 방향에 대해
	for (int i = 0; i < 5; i++) {
		//북쪽으로 합치는 경우
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
		//동쪽으로 합치는 경우
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
		//남쪽으로 합치는 경우
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
		//서쪽으로 합치는 경우
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
		//가장 큰 값을 갱신
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (board_copy[a][b] > answer)	answer = board_copy[a][b];
			}
		}
	}
}