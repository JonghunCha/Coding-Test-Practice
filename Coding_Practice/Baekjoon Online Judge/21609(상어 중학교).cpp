/*
문제 링크 : https://www.acmicpc.net/problem/21609
문제에서 제시한 상황을 잘 구현할 수 있는지 묻는 문제다.

대부분 단순 구현 부분이지만 가장 큰 블록 그룹을 찾는 부분은 완전 탐색을 통해 구해야한다.

블록 그룹에는 일반 블록이 적어도 하나 있어야 한다.

또, 블록 그룹의 기준 블록은 일반 블록중 행의 번호가 가장 작은 블록, 그러한 블록이 여러개면 열의 번호가 가장 작은 블록이라 한다.

따라서 가장 큰 블록 그룹을 찾기 위해선 일반 블록이 위치한 곳을 시작점으로 잡고 인접한 방향에 같은 색의 일반 블록 혹은 무지개 블록이 있는지 확인해 나가면 된다.

가장 큰 블록만 찾고 나면 나머지 부분은 간단하게 해결할 수 있다.
*/
#include <iostream>
using namespace std;

int block_num, rainbow_num, block_x, block_y;	//가장 큰 블록 그룹의 정보를 담는 변수
int temp_block_num, temp_rainbow_num, temp_block_x, temp_block_y;	//현재 탐색중인 블록 그룹의 정보를 담는 변수
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void Search_Largest_Group(int N, int board[20][20], int group[20][20]);
void Search_Near(int N, int board[20][20], int x, int y, int group[20][20], int group_color);

int main(void) {
	int N, M, board[20][20], group[20][20], answer = 0, group_num, gravity_index;
	int board_for_rotate[20][20];
	//입력값 저장
	cin >> N; cin >> M;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			cin >> board[a][b];
		}
	}

	while (1) {
		Search_Largest_Group(N, board, group);
		if (block_x == -1)	break;	//블록 그룹이 없다면 종료
		//1단계(가장 큰 블록 제거)
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				group[a][b] = 0;
			}
		}
		Search_Near(N, board, block_x, block_y, group, board[block_x][block_y]);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (group[a][b] == 1)	board[a][b] = 9;	//빈 칸은 9로 표시하였다
			}
		}
		//2단계(제거한 블록으로부터 점수 획득)
		answer += block_num * block_num;
		//3단계(중력 작용)
		for (int a = 0; a < N; a++) {
			gravity_index = N - 1;
			for (int b = N - 1; b >= 0; b--) {
				if (board[b][a] == -1)	gravity_index = b - 1;
				else if (board[b][a] >= 0 && board[b][a] < 9 && b == gravity_index)	gravity_index = b - 1;
				else if (board[b][a] >= 0 && board[b][a] < 9 && b != gravity_index) {
					board[gravity_index][a] = board[b][a];
					board[b][a] = 9;
					gravity_index--;
				}
			}
		}
		//4단계(90도 반시계 회전)
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				board_for_rotate[a][b] = board[b][N - a - 1];
			}
		}
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				board[a][b] = board_for_rotate[a][b];
			}
		}
		//5단계(중력 작용)
		for (int a = 0; a < N; a++) {
			gravity_index = N - 1;
			for (int b = N - 1; b >= 0; b--) {
				if (board[b][a] == -1)	gravity_index = b - 1;
				else if (board[b][a] >= 0 && board[b][a] < 9 && b == gravity_index)	gravity_index = b - 1;
				else if (board[b][a] >= 0 && board[b][a] < 9 && b != gravity_index) {
					board[gravity_index][a] = board[b][a];
					board[b][a] = 9;
					gravity_index--;
				}
			}
		}
	}
	cout << answer;

	return 0;
}
//가장 큰 블록 그룹을 찾는 함수
void Search_Largest_Group(int N, int board[20][20], int group[20][20]) {
	block_num = 0;
	rainbow_num = 0;
	block_x = -1;
	block_y = -1;
	bool is_search_complete;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			//일반 블록이 존재하는 경우 해당 블록을 기준으로 그룹을 탐색
			if (board[a][b] > 0 && board[a][b] < 9) {
				temp_block_num = 0;
				temp_rainbow_num = 0;
				temp_block_x = 30;
				temp_block_y = 30;
				for (int c = 0; c < N; c++) {
					for (int d = 0; d < N; d++) {
						group[c][d] = 0;
					}
				}
				Search_Near(N, board, a, b, group, board[a][b]);
				is_search_complete = false;
				//그룹이 형성되었다면 해당 그룹의 기준 블록의 좌표를 찾아낸다
				for (int c = 0; c < N; c++) {
					for (int d = 0; d < N; d++) {
						if (group[c][d] == 1 && board[c][d] != 0) {
							temp_block_x = c;
							temp_block_y = d;
							is_search_complete = true;
							break;
						}
					}
					if (is_search_complete)	break;
				}
				//가장 큰 블록 그룹을 조건에 따라 갱신
				if ((temp_block_num > 1 && temp_block_num > block_num)
					|| (temp_block_num == block_num && temp_rainbow_num > rainbow_num)
					|| (temp_block_num == block_num && temp_rainbow_num == rainbow_num && temp_block_x > block_x)
					|| (temp_block_num == block_num && temp_rainbow_num == rainbow_num && temp_block_x == block_x && temp_block_y > block_y)) {
					block_num = temp_block_num;
					rainbow_num = temp_rainbow_num;
					block_x = temp_block_x;
					block_y = temp_block_y;
				}
			}
		}
	}
}
//x, y좌표의 인접한 블록을 확인하고 같은 그룹이면 확장해 나가는 함수
void Search_Near(int N, int board[20][20], int x, int y, int group[20][20], int group_color) {
	int nx, ny;
	if (board[x][y] == 0) {
		temp_rainbow_num++;
	}
	group[x][y] = 1;
	temp_block_num++;
	for (int a = 0; a < 4; a++) {
		nx = x + dx[a];
		ny = y + dy[a];
		//인접한 4방향 중 아직 그룹에 속하지 않았으며 일반 블록 혹은 무지개 블록인 것들을 그룹에 추가
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && group[nx][ny] == 0 && (board[nx][ny] == 0 || board[nx][ny] == group_color)) {
			Search_Near(N, board, nx, ny, group, group_color);
		}
	}
}