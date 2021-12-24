/*
문제 링크 : https://www.acmicpc.net/problem/14500
단순 구현 문제다.

모든 모양의 테트로미노를 주어진 종이 위를 전체 탐색하며 가장 큰 숫자를 갱신하면 된다.
*/
#include <iostream>
using namespace std;

int main(void) {
	int N, M, answer = 0, temp;
	//입력값 저장
	cin >> N; cin >> M;
	int** board = new int* [N];
	for (int i = 0; i < N; i++) {
		board[i] = new int[M];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	//case1-1
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= M - 4; j++) {
			temp = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
			if (temp > answer)	answer = temp;
		}
	}
	//case1-2
	for (int i = 0; i <= N - 4; i++) {
		for (int j = 0; j < M; j++) {
			temp = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j];
			if (temp > answer)	answer = temp;
		}
	}
	//case2
	for (int i = 0; i <= N - 2; i++) {
		for (int j = 0; j <= M - 2; j++) {
			temp = board[i][j] + board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1];
			if (temp > answer)	answer = temp;
		}
	}
	//case3-1
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 2; j++) {
			temp = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j + 1];
			if (temp > answer)	answer = temp;
		}
	}
	//case3-2
	for (int i = 0; i <= N - 2; i++) {
		for (int j = 0; j <= M - 3; j++) {
			temp = board[i][j] + board[i + 1][j] + board[i][j + 1] + board[i][j + 2];
			if (temp > answer)	answer = temp;
		}
	}
	//case3-3
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 2; j++) {
			temp = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1];
			if (temp > answer)	answer = temp;
		}
	}
	//case3-4
	for (int i = 0; i <= N - 2; i++) {
		for (int j = 0; j <= M - 3; j++) {
			temp = board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2] + board[i][j + 2];
			if (temp > answer)	answer = temp;
		}
	}
	//case3-5
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 2; j++) {
			temp = board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j] + board[i + 2][j + 1];
			if (temp > answer)	answer = temp;
		}
	}
	//case3-6
	for (int i = 0; i <= N - 2; i++) {
		for (int j = 0; j <= M - 3; j++) {
			temp = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2];
			if (temp > answer)	answer = temp;
		}
	}
	//case3-7
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 2; j++) {
			temp = board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 2][j];
			if (temp > answer)	answer = temp;
		}
	}
	//case3-8
	for (int i = 0; i <= N - 2; i++) {
		for (int j = 0; j <= M - 3; j++) {
			temp = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2];
			if (temp > answer)	answer = temp;
		}
	}
	//case4-1
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 2; j++) {
			temp = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1];
			if (temp > answer)	answer = temp;
		}
	}
	//case4-2
	for (int i = 0; i <= N - 2; i++) {
		for (int j = 0; j <= M - 3; j++) {
			temp = board[i + 1][j] + board[i + 1][j + 1] + board[i][j + 1] + board[i][j + 2];
			if (temp > answer)	answer = temp;
		}
	}
	//case4-3
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 2; j++) {
			temp = board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j];
			if (temp > answer)	answer = temp;
		}
	}
	//case4-4
	for (int i = 0; i <= N - 2; i++) {
		for (int j = 0; j <= M - 3; j++) {
			temp = board[i][j] + board[i + 1][j + 1] + board[i][j + 1] + board[i + 1][j + 2];
			if (temp > answer)	answer = temp;
		}
	}
	//case5-1
	for (int i = 0; i <= N - 2; i++) {
		for (int j = 0; j <= M - 3; j++) {
			temp = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1];
			if (temp > answer)	answer = temp;
		}
	}
	//case5-2
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 2; j++) {
			temp = board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1];
			if (temp > answer)	answer = temp;
		}
	}
	//case5-3
	for (int i = 0; i <= N - 2; i++) {
		for (int j = 0; j <= M - 3; j++) {
			temp = board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2];
			if (temp > answer)	answer = temp;
		}
	}
	//case5-4
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 2; j++) {
			temp = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1];
			if (temp > answer)	answer = temp;
		}
	}

	cout << answer;
	//동적 할당 해제
	for (int i = 0; i < N; i++) {
		delete []board[i];
	}
	delete []board;
	return 0;
}