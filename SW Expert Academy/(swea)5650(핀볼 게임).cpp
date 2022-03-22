/*
문제 링크 : https://swexpertacademy.com/main/main.do
단순 구현 문제다.

문제에 주어진 조건대로 구현만 하면 쉽게 해결할 수 있는 문제이다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };	//북, 동 , 남, 서
int dy[4] = { 0, 1, 0, -1 };
int wormhole[5][4];

int get_score(int N, int x, int y, int direction, int board[100][100]);

int main(int argc, char** argv)
{
	int T, N, board[100][100], max_score, score, idx;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 변수 초기화
		scanf("%d", &N);
		memset(wormhole, -1, sizeof(int) * 20);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				scanf("%d", &board[a][b]);
				if (board[a][b] >= 6 && board[a][b] <= 10) {
					idx = board[a][b] - 6;
					if (wormhole[idx][0] > -1) {
						wormhole[idx][2] = a;
						wormhole[idx][3] = b;
					}
					else {
						wormhole[idx][0] = a;
						wormhole[idx][1] = b;
					}
				}
			}
		}
		//가능한 모든 경우에 대해 시뮬레이션
		max_score = 0;
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (board[a][b] == 0) {
					for (int c = 0; c < 4; c++) {
						score = get_score(N, a, b, c, board);
						if (max_score < score)	max_score = score;
					}
				}
			}
		}

		printf("#%d %d\n", test_case, max_score);
	}
	return 0;
}

int get_score(int N, int x, int y, int direction, int board[100][100]) {
	int nx = x, ny = y, score = 0, idx;
	while (1) {
		nx = nx + dx[direction];
		ny = ny + dy[direction];

		if (nx == x && ny == y) {	//시작위치로 온 경우
			return score;
		}
		else if (nx < 0 || nx >= N || ny < 0 || ny >= N) {	//벽에 부딫힌 경우
			score++;
			direction = (direction + 2) % 4;
		}
		else if (board[nx][ny] == -1) {	//블랙홀
			return score;
		}
		else if (board[nx][ny] >= 6 && board[nx][ny] <= 10) {	//웜홀
			idx = board[nx][ny] - 6;

			if (wormhole[idx][0] == nx && wormhole[idx][1] == ny) {
				nx = wormhole[idx][2];
				ny = wormhole[idx][3];
			}
			else {
				nx = wormhole[idx][0];
				ny = wormhole[idx][1];
			}
		}
		else if (board[nx][ny] == 1) {	//1번 블록
			score++;
			switch (direction) {
			case 0:
				direction = 2;
				break;
			case 1:
				direction = 3;
				break;
			case 2:
				direction = 1;
				break;
			case 3:
				direction = 0;
				break;
			}
		}
		else if (board[nx][ny] == 2) {	//2번 블록
			score++;
			switch (direction) {
			case 0:
				direction = 1;
				break;
			case 1:
				direction = 3;
				break;
			case 2:
				direction = 0;
				break;
			case 3:
				direction = 2;
				break;
			}
		}
		else if (board[nx][ny] == 3) {	//3번 블록
			score++;
			switch (direction) {
			case 0:
				direction = 3;
				break;
			case 1:
				direction = 2;
				break;
			case 2:
				direction = 0;
				break;
			case 3:
				direction = 1;
				break;
			}
		}
		else if (board[nx][ny] == 4) {	//4번 블록
			score++;
			switch (direction) {
			case 0:
				direction = 2;
				break;
			case 1:
				direction = 0;
				break;
			case 2:
				direction = 3;
				break;
			case 3:
				direction = 1;
				break;
			}
		}
		else if (board[nx][ny] == 5) {	//5번 블록
			score++;
			direction = (direction + 2) % 4;
		}
	}
}