/*
문제 링크 : https://www.acmicpc.net/problem/14503
단순 구현 문제다.

문제에서 제시한 로봇 청소기의 동작 방식대로 움직이도록 구현하면 된다.
*/
#include <iostream>
using namespace std;

int main(void) {
	int N, M, r, c, d, answer = 0;
	int map[50][50];
	//입력값 저장
	cin >> N; cin >> M;
	cin >> r; cin >> c; cin >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	//로봇 청소기가 종료조건을 만날 때까지 계속 진행
	while (1) {
		//현재 좌표가 아직 청소를 안했다면 청소를 하고 그 지역을 청소했다고 마킹
		if (map[r][c] == 0) {
			answer++;
			map[r][c] = 2;
		}
		//현재 바로보는 방향이 북쪽일 때
		if (d == 0) {
			if (map[r][c - 1] == 0) {
				c--;
				d = 3;
			}
			else if (map[r + 1][c] == 0) {
				r++;
				d = 2;
			}
			else if (map[r][c + 1] == 0) {
				c++;
				d = 1;
			}
			else if (map[r - 1][c] == 0)	r--;
			else if (map[r + 1][c] != 1)	r++;
			else	break;
		}
		//현재 바로보는 방향이 동쪽일 때
		else if (d == 1) {
			if (map[r - 1][c] == 0) {
				r--;
				d = 0;
			}
			else if (map[r][c - 1] == 0) {
				c--;
				d = 3;
			}
			else if (map[r + 1][c] == 0) {
				r++;
				d = 2;
			}
			else if (map[r][c + 1] == 0)	c++;
			else if (map[r][c - 1] != 1)	c--;
			else	break;
		}
		//현재 바로보는 방향이 남쪽일 때
		else if (d == 2) {
			if (map[r][c + 1] == 0) {
				c++;
				d = 1;
			}
			else if (map[r - 1][c] == 0) {
				r--;
				d = 0;
			}
			else if (map[r][c - 1] == 0) {
				c--;
				d = 3;
			}
			else if (map[r + 1][c] == 0)	r++;
			else if (map[r - 1][c] != 1)	r--;
			else	break;
		}
		//현재 바로보는 방향이 서쪽일 때
		else {
			if (map[r + 1][c] == 0) {
				r++;
				d = 2;
			}
			else if (map[r][c + 1] == 0) {
				c++;
				d = 1;
			}
			else if (map[r - 1][c] == 0) {
				r--;
				d = 0;
			}
			else if (map[r][c - 1] == 0)	c--;
			else if (map[r][c + 1] != 1)	c++;
			else	break;
		}
	}

	cout << answer;
	return 0;
}