/*
문제 링크 : https://www.acmicpc.net/problem/19236
완전 탐색으로 해결할 수 있는 문제다.

구현은 크게 2파트로 나뉜다.

1. 상어는 진행방향에 있는 물고기 중 하나를 잡아먹고 방향을 먹힌 물고기의 방향으로 바꾼다.
2. 전체 물고기를 이동한다.

1~2번 과정을 반복하다 상어가 더 이상 물고기를 못먹을 때 종료하면 된다. 
*/
#include <iostream>
using namespace std;

int answer = 0;

int dx[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

void Move_Shark(int map[4][4], int target_x, int target_y, int score, int fish[17][3]);
void Move_Fish(int map[4][4], int fish_num, int fish[17][3]);

int main(void) {
	int map[4][4], direction, fish[17][3];	//fish는 각 인덱스에 따라 물고기의 좌표위치와 방향을 저장한다.(예외로 0번 인덱스는 상어의 위치와 방향 의미)
	//입력값 저장
	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 4; b++) {
			cin >> map[a][b];
			cin >> direction;
			fish[map[a][b]][0] = a;
			fish[map[a][b]][1] = b;
			fish[map[a][b]][2] = direction;
		}
	}
	//상어의 위치 저장 및 상어 이동 시작
	fish[0][0] = 0;
	fish[0][1] = 0;
	Move_Shark(map, 0, 0, 0, fish);
	cout << answer;

	return 0;
}

void Move_Shark(int map[4][4], int target_x, int target_y, int score, int fish[17][3]) {
	int x = fish[0][0], y = fish[0][1], nx, ny, nd, map_backup[4][4], fish_backup[17][3];
	bool is_end = true;	//상어가 더 이상 잡아먹을 물고기가 있는지 없는지를 의미
	//타겟에 해당하는 물고기 먹고 점수 올림
	int nscore = score + map[target_x][target_y];
	//타겟의 위치에 상어를 옮기고 방향도 복사 + 잡아 먹힌 물고기를 map에서 없앤다
	fish[map[target_x][target_y]][0] = -1;
	fish[map[target_x][target_y]][1] = -1;
	fish[0][0] = target_x;
	fish[0][1] = target_y;
	fish[0][2] = fish[map[target_x][target_y]][2];
	map[x][y] = -1;
	map[target_x][target_y] = 0;
	//물고기 이동 실시
	for (int a = 1; a <= 16; a++) {
		if (fish[a][0] != -1)	Move_Fish(map, a, fish);
	}
	//map과 fish정보 백업
	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 4; b++) {
			map_backup[a][b] = map[a][b];
		}
	}
	for (int a = 0; a < 17; a++) {
		for (int b = 0; b < 3; b++) {
			fish_backup[a][b] = fish[a][b];
		}
	}
	//상어가 다음으로 잡아먹을 물고기 후보 탐색
	nd = fish[0][2];
	//4*4map이기에 상어의 이동 거리는 최대 3
	for (int a = 1; a <= 3; a++) {
		nx = fish[0][0] + a * dx[nd];
		ny = fish[0][1] + a * dy[nd];
		//잡아 먹을 물고기가 있는 경우 해당 물고기를 타켓으로 하여 Move_Shark호출
		if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && map[nx][ny] > 0) {
			Move_Shark(map, nx, ny, nscore, fish);
			//map과 fish의 백업본을 이용하여 다른 물고기 후보에 대해 Move_Shark호출 준비
			for (int b = 0; b < 4; b++) {
				for (int c = 0; c < 4; c++) {
					map[b][c] = map_backup[b][c];
				}
			}
			for (int b = 0; b < 17; b++) {
				for (int c = 0; c < 3; c++) {
					fish[b][c] = fish_backup[b][c];
				}
			}
			//물고기를 잡아먹었다는 것은 이번 함수에서 종료조건을 만족하지 않았다는 의미
			is_end = false;
		}
	}
	//종료조건을 만족하면 점수 최대값 갱신
	if (is_end && nscore > answer)	answer = nscore;
}

void Move_Fish(int map[4][4], int fish_num, int fish[17][3]) {
	int nx, ny, nd = fish[fish_num][2], temp_fish_num, temp_x, temp_y;
	//반시계 방향으로 방향 회전
	for (int a = 0; a < 8; a++) {
		nx = fish[fish_num][0] + dx[nd];
		ny = fish[fish_num][1] + dy[nd];
		//물고기가 이동하려는 곳에 다른 물고기가 있는 경우
		if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && map[nx][ny] > 0) {
			temp_fish_num = map[nx][ny];
			temp_x = fish[fish_num][0];
			temp_y = fish[fish_num][1];
			map[nx][ny] = fish_num;
			fish[fish_num][0] = nx;
			fish[fish_num][1] = ny;
			fish[fish_num][2] = nd;
			map[temp_x][temp_y] = temp_fish_num;
			fish[temp_fish_num][0] = temp_x;
			fish[temp_fish_num][1] = temp_y;
			return;
		}
		//물고기가 이동하려는 곳이 빈 공간일 경우
		else if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && map[nx][ny] == -1) {
			temp_x = fish[fish_num][0];
			temp_y = fish[fish_num][1];
			map[nx][ny] = fish_num;
			fish[fish_num][0] = nx;
			fish[fish_num][1] = ny;
			fish[fish_num][2] = nd;
			map[temp_x][temp_y] = -1;
			return;
		}
		//방향 회전
		if (nd == 8)	nd = 1;
		else	nd++;
	}
}