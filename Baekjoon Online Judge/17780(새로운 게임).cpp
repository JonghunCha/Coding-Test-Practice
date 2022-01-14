/*
문제 링크 : https://www.acmicpc.net/problem/17780
단순한 구현 문제다.

문제의 조건대로 구현만 하면 되는 문제라 설명은 생략하겠다.
*/
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

int N, K, board[13][13], horse[11][3];
vector<vector<vector<pair<int, int>>>> game_info;

void move_horse(int x, int y);
void move_to_white(int x, int y, int nx, int ny);
void move_to_red(int x, int y, int nx, int ny);

int main(void) {
	//입력값 저장 및 변수 초기화
	scanf("%d %d", &N, &K);
	for (int a = 1; a <= N; a++) {	//체스판 정보 입력
		for (int b = 1; b <= N; b++) {
			scanf("%d", &board[a][b]);
		}
	}

	for (int a = 1; a <= K; a++) {	//말 정보 입력
		scanf("%d %d %d", &horse[a][0], &horse[a][1], &horse[a][2]);
	}

	//각 칸에 놓여있는 말 정보 계산
	game_info.resize(N + 1);
	for (int a = 0; a <= N; a++) {
		game_info[a].resize(N + 1);
	}
	for (int a = 1; a <= K; a++) {
		game_info[horse[a][0]][horse[a][1]].push_back(make_pair(a, horse[a][2]));
	}

	int turn_num = 1;
	bool is_end = false;

	while (turn_num <= 1000) {
		//1번~K번살피며 해당 말이 가장 바닥에 있는 경우 이동
		for (int a = 1; a <= K; a++) {
			if (game_info[horse[a][0]][horse[a][1]][0].first == a) {
				move_horse(horse[a][0], horse[a][1]);
			}
		}
		//만약 4개 이상 쌓인 지점이 있으면 종료
		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= N; b++) {
				if (game_info[a][b].size() >= 4) {
					is_end = true;
				}
			}
		}
		if (is_end)	break;

		turn_num++;
	}

	if (turn_num > 1000)	printf("-1\n");
	else	printf("%d\n", turn_num);

	return 0;
}

void move_horse(int x, int y) {
	int nx, ny, direction;

	direction = game_info[x][y][0].second;
	nx = x + dx[direction];
	ny = y + dy[direction];

	if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && board[nx][ny] != 2) {
		if (board[nx][ny] == 0) {	//만약 이동하려는 지점이 흰 칸인 경우
			move_to_white(x, y, nx, ny);
		}
		else {	//이동하려는 지점이 빨간 칸인 경우
			move_to_red(x, y, nx, ny);
		}
	}
	else {	//이동하려는 지점이 파란 칸이거나 체스판을 벗어나는 경우
		if (direction == 1)	direction = 2;
		else if (direction == 2)	direction = 1;
		else if (direction == 3)	direction = 4;
		else	direction = 3;

		game_info[x][y][0].second = direction;
		horse[game_info[x][y][0].first][2] = direction;
		nx = x + dx[direction];
		ny = y + dy[direction];
		//방향을 바꾼 뒤 이동 가능하다면 이동, 불가능하면 아무것도 안함
		if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && board[nx][ny] == 0) {
			move_to_white(x, y, nx, ny);
		}
		else if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && board[nx][ny] == 1) {
			move_to_red(x, y, nx, ny);
		}
	}
}

void move_to_white(int x, int y, int nx, int ny) {
	for (int a = 0; a < game_info[x][y].size(); a++) {
		game_info[nx][ny].push_back(make_pair(game_info[x][y][a].first, game_info[x][y][a].second));
		horse[game_info[x][y][a].first][0] = nx;
		horse[game_info[x][y][a].first][1] = ny;
	}
	game_info[x][y].clear();
}

void move_to_red(int x, int y, int nx, int ny) {
	for (int a = game_info[x][y].size() - 1; a >= 0; a--) {
		game_info[nx][ny].push_back(make_pair(game_info[x][y][a].first, game_info[x][y][a].second));
		horse[game_info[x][y][a].first][0] = nx;
		horse[game_info[x][y][a].first][1] = ny;
	}
	game_info[x][y].clear();
}