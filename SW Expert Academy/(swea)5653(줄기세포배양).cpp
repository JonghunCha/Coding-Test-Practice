/*
문제 링크 : https://swexpertacademy.com/main/main.do
완전 탐색으로 해결할 수 있는 문제다.

문제의 조건에 따르면 배양 용기의 최대 크기는 350 * 350이 넘지 않는다.

따라서 여유있게 400 * 400 * 2 크기의 배열을 선언하였다.(마지막의 0번 인덱스에는 생명력을, 1번 인덱스에는 해당 세포가 생성된 시기를 저장)

문제의 조건에 따라 K시간 동안 활성 상태의 줄기 세포를 근처에 배양한 뒤 마지막에 살아있는 줄기 세포의 수를 구하면 된다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[400][400][2];

int main(void) {
	int T, N, M, K, answer, nx, ny;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		//입력값 저장 및 변수 초기화
		scanf("%d %d %d", &N, &M, &K);
		memset(board, 0, sizeof(int) * 320000);
		for (int a = 175; a < 175 + N; a++) {
			for (int b = 175; b < 175 + M; b++) {
				scanf("%d", &board[a][b][0]);
			}
		}
		
		for (int a = 1; a <= K; a++) {
			for (int x = 1; x <= 398; x++) {
				for (int y = 1; y <= 398; y++) {
					//x, y번째 줄기 세포가 활성 상태인 경우 주변에 배양
					if (board[x][y][0] > 0 && a > board[x][y][0] + board[x][y][1] && a <= board[x][y][1] + 2 * board[x][y][0]) {
						for (int d = 0; d < 4; d++) {
							nx = x + dx[d];
							ny = y + dy[d];
							if (board[nx][ny][0] == 0) {
								board[nx][ny][0] = board[x][y][0];
								board[nx][ny][1] = a;
							}
							else if (board[nx][ny][1] == a) {	//두 개 이상의 줄기 세포가 하나의 셀에 동시 번식하려는 경우로 생명력 수치가 높은 세포가 차지하게 한다
								if (board[x][y][0] > board[nx][ny][0])	board[nx][ny][0] = board[x][y][0];
							}
						}
					}
				}
			}
		}
		//활성, 비활성 상태의 세포 갯수 계산
		answer = 0;
		for (int a = 0; a < 400; a++) {
			for (int b = 0; b < 400; b++) {
				if (board[a][b][0] > 0 && board[a][b][1] + 2 * board[a][b][0] > K)	answer++;
			}
		}

		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}