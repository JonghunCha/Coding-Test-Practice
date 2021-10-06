/*
문제 링크 : https://www.acmicpc.net/problem/14499
별다른 설명이 필요 없는 단순 구현문제다.
*/
#include <iostream>
using namespace std;

int main(void) {
	int N, M, x, y, K, map[20][20], commands[1000], dice[7], temp;
	//입력값 저장
	cin >> N; cin >> M; cin >> x; cin >> y; cin >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++)	cin >> commands[i];
	//주사위 0으로 초기화(dice의 index에 따라 1 = 위, 2 = 북, 3 = 동, 4 = 서, 5 = 남, 6 = 아래면을 의미)
	for (int i = 1; i < 7; i++)	dice[i] = 0;
	for (int i = 0; i < K; i++) {
		//동쪽으로 굴리는 경우
		if (commands[i] == 1) {
			//굴릴수 없으면 무시하고 다음 command 수행
			if (y == M - 1)	continue;
			//바닥이 0이 아닌 경우
			if (map[x][y + 1] != 0) {
				temp = dice[1];
				dice[1] = dice[4];
				dice[3] = temp;
				dice[4] = dice[6];
				dice[6] = map[x][y + 1];
				map[x][++y] = 0;
			}
			//바닥이 0인 경우
			else {
				map[x][++y] = dice[3];
				temp = dice[1];
				dice[1] = dice[4];
				dice[3] = temp;
				dice[4] = dice[6];
				dice[6] = map[x][y];
			}
		}
		//서쪽으로 굴리는 경우
		else if (commands[i] == 2) {
			if (y == 0)	continue;

			if (map[x][y - 1] != 0) {
				temp = dice[1];
				dice[1] = dice[3];
				dice[3] = dice[6];
				dice[4] = temp;
				dice[6] = map[x][y - 1];
				map[x][--y] = 0;
			}
			else {
				map[x][--y] = dice[4];
				temp = dice[1];
				dice[1] = dice[3];
				dice[3] = dice[6];
				dice[4] = temp;
				dice[6] = map[x][y];
			}
		}
		//북쪽으로 굴리는 경우
		else if (commands[i] == 3) {
			if (x == 0)	continue;

			if (map[x - 1][y] != 0) {
				temp = dice[1];
				dice[1] = dice[5];
				dice[2] = temp;
				dice[5] = dice[6];
				dice[6] = map[x - 1][y];
				map[--x][y] = 0;
			}
			else {
				map[--x][y] = dice[2];
				temp = dice[1];
				dice[1] = dice[5];
				dice[2] = temp;
				dice[5] = dice[6];
				dice[6] = map[x][y];
			}
		}
		//남쪽으로 굴리는 경우
		else {
			if (x == N - 1)	continue;

			if (map[x + 1][y] != 0) {
				temp = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[6];
				dice[5] = temp;
				dice[6] = map[x + 1][y];
				map[++x][y] = 0;
			}
			else {
				map[++x][y] = dice[5];
				temp = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[6];
				dice[5] = temp;
				dice[6] = map[x][y];
			}
		}
		cout << dice[1] << endl;
	}

	return 0;
}