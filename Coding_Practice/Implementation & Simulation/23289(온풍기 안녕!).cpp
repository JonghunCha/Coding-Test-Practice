/*
문제 링크 : https://www.acmicpc.net/problem/23289
단순 구현 문제이다.

그러나 문제 조건이 조금은 복잡해서 코드가 많이 길긴 하다.
*/
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int R, C, K, W;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void step1(int room[21][21], int walls[21][21][4], int room_copy[21][21], int x, int y, int direction);
void step2(int room[21][21], int walls[21][21][4], int room_copy[21][21]);

int main(void) {
	//room은 각 칸의 온도 저장, room_copy는 step1에서는 바람이 전달된 곳의 유무를 step2에서는 온도 조절의 일괄 적용을 위해 사용
	//walls는 각 칸의 북 동 남 서 순으로 벽의 유무를 저장
	int room[21][21], room_copy[21][21], walls[21][21][4], temp, answer = 0, x, y, direction;
	vector<tuple<int, int, int>> machine;	//온풍기의 좌표 및 방향 저장
	vector<tuple<int, int>> check;	//검사해야할 칸의 좌표 저장
	bool check_end;
	//입력값 저장 및 변수 초기화
	cin >> R >> C >> K;
	for (int a = 1; a <= R; a++) {
		for (int b = 1; b <= C; b++) {
			cin >> temp;
			if (temp != 0 && temp != 5)	machine.push_back(make_tuple(a, b, temp));
			else if (temp == 5)	check.push_back(make_tuple(a, b));
			room[a][b] = 0;
			for (int c = 0; c < 4; c++)	walls[a][b][c] = 0;
		}
	}
	cin >> W;
	for (int a = 0; a < W; a++) {
		cin >> x >> y >> direction;
		if (direction == 0) {
			walls[x][y][0] = 1;
			walls[x - 1][y][2] = 1;
		}
		else {
			walls[x][y][1] = 1;
			walls[x][y + 1][3] = 1;
		}
	}
	//최대 100번 반복
	while (answer < 101) {
		//모든 온풍기에 대해 step1함수를 호출함으로써 바람을 일이킴
		for (int a = 0; a < machine.size(); a++) {
			x = get<0>(machine[a]);
			y = get<1>(machine[a]);
			direction = get<2>(machine[a]);
			for (int b = 1; b <= R; b++) {
				for (int c = 1; c <= C; c++) {
					room_copy[b][c] = 0;
				}
			}
			step1(room, walls, room_copy, x, y, direction);
		}
		//stpe2를 호출함으로써 온도 조절
		for (int a = 1; a <= R; a++) {
			for (int b = 1; b <= C; b++) {
				room_copy[a][b] = 0;
			}
		}
		step2(room, walls, room_copy);
		//바깥쪽의 칸 온도 1씩 감소
		for (int a = 1; a <= R; a++) {
			for (int b = 1; b <= C; b++) {
				if (a == 1 || a == R || b == 1 || b == C) {
					if (room[a][b] >= 1)	room[a][b]--;
				}
			}
		}
		//초콜릿 먹기
		answer++;
		//검사할 칸 모두가 K이상이면 종료
		check_end = true;
		for (int a = 0; a < check.size(); a++) {
			x = get<0>(check[a]);
			y = get<1>(check[a]);
			if (room[x][y] < K)	check_end = false;
		}
		if (check_end)	break;
	}

	cout << answer << endl;

	return 0;
}
//각 방향에 따라 조건문을 통해 구현하였으며 주석은 동쪽일 때만 작성하였음
void step1(int room[21][21], int walls[21][21][4], int room_copy[21][21], int x, int y, int direction) {
	int curr = 4;
	if (direction == 1) {	//온풍기 방향이 동쪽일 때
		room[x][++y] += 5;	//방향이 나온 방향의 칸은 온도 5 상승
		room_copy[x][y] = 1;	//바람이 도착한 곳임을 표시
		while (curr > 0) {
			y++;
			if (y > C)	return;	//집을 벗어난 경우 종료

			for (int a = 1; a <= R; a++) {
				if (room_copy[a][y - 1] == 1) {	//바람이 도착한 칸을 발견
					if (a - 1 >= 1 && walls[a][y - 1][0] == 0 && walls[a - 1][y][3] == 0 && room_copy[a - 1][y] == 0) {	//대각선 위로 바람이 갈 수 있을 때
						room[a - 1][y] += curr;
						room_copy[a - 1][y] = 1;
					}
					if (a + 1 <= R && walls[a][y - 1][2] == 0 && walls[a + 1][y][3] == 0 && room_copy[a + 1][y] == 0) {	//대각선 아래로 바람이 갈 수 있을 때
						room[a + 1][y] += curr;
						room_copy[a + 1][y] = 1;
					}
					if (walls[a][y][3] == 0 && room_copy[a][y] == 0) {	//오른쪽으로 바람이 갈 수 있을 때
						room[a][y] += curr;
						room_copy[a][y] = 1;
					}
				}
			}
			curr--;	//다음 바람의 온도 갱신
		}
	}
	else if (direction == 2) {
		room[x][--y] += 5;
		room_copy[x][y] = 1;
		while (curr > 0) {
			y--;
			if (y < 1)	return;

			for (int a = 1; a <= R; a++) {
				if(room_copy[a][y + 1] == 1) {
					if (a - 1 >= 1 && walls[a][y + 1][0] == 0 && walls[a - 1][y][1] == 0 && room_copy[a - 1][y] == 0) {
						room[a - 1][y] += curr;
						room_copy[a - 1][y] = 1;
					}
					if (a + 1 <= R && walls[a][y + 1][2] == 0 && walls[a + 1][y][1] == 0 && room_copy[a + 1][y] == 0) {
						room[a + 1][y] += curr;
						room_copy[a + 1][y] = 1;
					}
					if (walls[a][y][1] == 0 && room_copy[a][y] == 0) {
						room[a][y] += curr;
						room_copy[a][y] = 1;
					}
				}
			}
			curr--;
		}
	}
	else if (direction == 3) {
		room[--x][y] += 5;
		room_copy[x][y] = 1;
		while (curr > 0) {
			x--;
			if (x < 1)	return;

			for (int a = 1; a <= C; a++) {
				if (room_copy[x + 1][a] == 1) {
					if (a - 1 >= 1 && walls[x + 1][a][3] == 0 && walls[x][a - 1][2] == 0 && room_copy[x][a - 1] == 0) {
						room[x][a - 1] += curr;
						room_copy[x][a - 1] = 1;
					}
					if (a + 1 <= C && walls[x + 1][a][1] == 0 && walls[x][a + 1][2] == 0 && room_copy[x][a + 1] == 0) {
						room[x][a + 1] += curr;
						room_copy[x][a + 1] = 1;
					}
					if (walls[x][a][2] == 0 && room_copy[x][a] == 0) {
						room[x][a] += curr;
						room_copy[x][a] = 1;
					}
				}
			}
			curr--;
		}
	}
	else {
		room[++x][y] += 5;
		room_copy[x][y] = 1;
		while (curr > 0) {
			x++;
			if (x > R)	return;

			for (int a = 1; a <= C; a++) {
				if (room_copy[x - 1][a] == 1) {
					if (a - 1 >= 1 && walls[x - 1][a][3] == 0 && walls[x][a - 1][0] == 0 && room_copy[x][a - 1] == 0) {
						room[x][a - 1] += curr;
						room_copy[x][a - 1] = 1;
					}
					if (a + 1 <= C && walls[x - 1][a][1] == 0 && walls[x][a + 1][0] == 0 && room_copy[x][a + 1] == 0) {
						room[x][a + 1] += curr;
						room_copy[x][a + 1] = 1;
					}
					if (walls[x][a][0] == 0 && room_copy[x][a] == 0) {
						room[x][a] += curr;
						room_copy[x][a] = 1;
					}
				}
			}
			curr--;
		}
	}
	return;
}
//벽으로 막히지 않은 인접한 지역이 현재 칸보다 낮은 온도라면 온도를 조절
void step2(int room[21][21], int walls[21][21][4], int room_copy[21][21]) {
	int nx, ny;
	for (int a = 1; a <= R; a++) {
		for (int b = 1; b <= C; b++) {
			for (int c = 0; c < 4; c++) {
				nx = a + dx[c];
				ny = b + dy[c];
				if (nx >= 1 && nx <= R && ny >= 1 && ny <= C && walls[a][b][c] == 0) {
					if (room[a][b] > room[nx][ny]) {
						room_copy[a][b] -= (room[a][b] - room[nx][ny]) / 4;
						room_copy[nx][ny] += (room[a][b] - room[nx][ny]) / 4;
					}
				}
			}
		}
	}

	for (int a = 1; a <= R; a++) {
		for (int b = 1; b <= C; b++) {
			room[a][b] += room_copy[a][b];
		}
	}
	return;
}