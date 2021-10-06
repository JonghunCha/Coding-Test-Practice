/*
문제 링크 : https://www.acmicpc.net/problem/17144
단순 구현(시뮬레이션) 문제이다.

단순히 문제의 조건에 맞게 구현만 하면 쉽게 해결 가능하다.
*/
#include <iostream>
using namespace std;
//확산 방향을 위한 변수
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void spread(int R, int C, int room[51][51]);
void air_cleaner(int R, int C, int room[51][51], int r1, int r2);

int main(void) {
	int R, C, T, room[51][51];
	int cleaner_1 = 0, cleaner_2 = 0, answer = 0;
	//입력값 저장 및 공기 청정기 위치 파악
	cin >> R; cin >> C; cin >> T;
	for (int a = 1; a <= R; a++) {
		for (int b = 1; b <= C; b++) {
			cin >> room[a][b];
			if (room[a][b] == -1 && cleaner_1 == 0)	cleaner_1 = a;
			else if (room[a][b] == -1 && cleaner_1 != 0)	cleaner_2 = a;
		}
	}
	//T초간 시뮬레이션 실시
	for (int a = 0; a < T; a++) {
		spread(R, C, room);
		air_cleaner(R, C, room, cleaner_1, cleaner_2);
	}
	//T초 이후 방 안 미세먼지 파악
	for (int a = 1; a <= R; a++) {
		for (int b = 1; b <= C; b++) {
			if (room[a][b] != -1)	answer += room[a][b];
		}
	}
	cout << answer;
	return 0;
}

void spread(int R, int C, int room[51][51]) {
	//neighbor_num은 각 좌표에서 확산시킬 수 있는 공간의 개수, sum은 주위에서 해당 좌표에 넘어오는 미세먼지의 양을 의미
	int x, y, neighbor_num[51][51], sum[51][51];
	for (int a = 1; a <= R; a++) {
		for (int b = 1; b <= C; b++) {
			//공기청정기가 아닌 모든 위치에 대해 이웃의 수를 파악하고, 주위에서 확산 될 미세먼지 양 계산
			if (room[a][b] != -1) {
				neighbor_num[a][b] = 0;
				sum[a][b] = 0;
				for (int c = 0; c < 4; c++) {
					x = a + dx[c];
					y = b + dy[c];
					if (x >= 1 && x <= R && y >= 1 && y <= C && room[x][y] != -1) {
						neighbor_num[a][b]++;
						sum[a][b] += room[x][y] / 5;
					}
				}
			}
		}
	}
	//미세먼지 확산 실시
	for (int a = 1; a <= R; a++) {
		for (int b = 1; b <= C; b++) {
			if(room[a][b] != -1)	room[a][b] = room[a][b] - (room[a][b] / 5) * neighbor_num[a][b] + sum[a][b];
		}
	}
}

void air_cleaner(int R, int C, int room[51][51], int r1, int r2) {
	//북쪽 공기 청정기 작동
	for (int a = r1 - 1; a >= 2; a--)	room[a][1] = room[a - 1][1];
	for (int a = 1; a <= C - 1; a++)	room[1][a] = room[1][a + 1];
	for (int a = 1; a <= r1 - 1; a++)	room[a][C] = room[a + 1][C];
	for (int a = C; a >= 3; a--)	room[r1][a] = room[r1][a - 1];
	room[r1][2] = 0;
	//남쪽 공기 청정기 작동
	for (int a = r2 + 1; a < R; a++)	room[a][1] = room[a + 1][1];
	for (int a = 1; a <= C - 1; a++)	room[R][a] = room[R][a + 1];
	for (int a = R; a >= r2 + 1; a--)	room[a][C] = room[a - 1][C];
	for (int a = C; a >= 3; a--)	room[r2][a] = room[r2][a - 1];
	room[r2][2] = 0;
}