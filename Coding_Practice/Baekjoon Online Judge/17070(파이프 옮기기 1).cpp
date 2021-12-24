/*
문제 링크 : https://www.acmicpc.net/problem/17070
완전탐색을 통해 해결할 수 있는 문제다.
(1,2)지점의 파이프가 집 안에서 갈 수 있는 모든 경우의 수를 탐색하며 (N, N)을 지날 때 카운팅을 하면 된다.
*/
#include <iostream>
using namespace std;

int answer = 0;

void Get_Answer(const int N, const int map[17][17], int r, int c, int direction);	

int main(void) {
	int N, map[17][17];	//map은 집의 상태를 저장
	//입력값 저장
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	Get_Answer(N, map, 1, 2, 0);
	cout << answer;

	return 0;
}
//r,c는 각각 현재 파이프의 위치를 의미하고, direction은 파이프가 어떻게 놓여있는가를 의미한다.
//direction이 0이면 가로, 1이면 세로, 2이면 대각선으로 놓여 있음을 의미한다.
void Get_Answer(const int N, const int map[17][17], int r, int c, int direction) {
	if (r == N && c == N) {
		answer++;
		return;
	}
	else {
		if (direction == 0) {
			if (c + 1 <= N && map[r][c + 1] == 0)	Get_Answer(N, map, r, c + 1, 0);
			if (c + 1 <= N && r + 1 <= N && map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0)	Get_Answer(N, map, r + 1, c + 1, 2);
		}
		else if (direction == 1) {
			if (r + 1 <= N && map[r + 1][c] == 0)	Get_Answer(N, map, r + 1, c, 1);
			if (r + 1 <= N && c + 1 <= N && map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0)	Get_Answer(N, map, r + 1, c + 1, 2);
		}
		else {
			if (c + 1 <= N && map[r][c + 1] == 0)	Get_Answer(N, map, r, c + 1, 0);
			if (r + 1 <= N && map[r + 1][c] == 0)	Get_Answer(N, map, r + 1, c, 1);
			if (c + 1 <= N && r + 1 <= N && map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0)	Get_Answer(N, map, r + 1, c + 1, 2);
		}
	}
}