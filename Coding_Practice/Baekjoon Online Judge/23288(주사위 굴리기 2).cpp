/*
문제 링크 : https://www.acmicpc.net/problem/23288
단순 구현과 DFS를 합친 문제다.

우선 문제의 조건에 따라 주사위를 굴린다.

그런 다음 DFS를 통해 현재 주사위의 위치에 적힌 수와 같은 수를 가진 칸의 갯수를 구한다.

answer에 얻은 점수를 더한다.

위 과정을 K번하면 된다.
*/
#include <iostream>

using namespace std;

int N, M, K;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 }; 

void move(int& x, int& y, int& direction, int dice[4][3]);
int DFS(int x, int y, int board[20][20], int visited[20][20]);

int main(void) {
	//direction 0 = 동, 1 = 남, 2 = 서, 3 = 북
	int board[20][20], direction = 0, dice[4][3], visited[20][20], answer = 0, x = 0, y = 0;
	//입력값 저장 및 변수 초기화
	cin >> N >> M >> K;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < M; b++) {
			cin >> board[a][b];
		}
	}
	dice[0][1] = 2;
	dice[1][0] = 4;
	dice[1][1] = 1;
	dice[1][2] = 3;
	dice[2][1] = 5;
	dice[3][1] = 6;
	//K번의 이동
	for (int a = 0; a < K; a++) {
		move(x, y, direction, dice);	//주사위를 direction방향으로 굴리고, 주사위의 정보를 갱신
		for (int b = 0; b < N; b++) {	//visited는 DFS에서 방문한 지역을 마킹하는 변수로 미 방문시엔 0, 방문시엔 1을 저장
			for (int c = 0; c < M; c++) {
				visited[b][c] = 0;
			}
		}
		answer += DFS(x, y, board, visited) * board[x][y];
		if (dice[3][1] > board[x][y]) {			//주사위의 바닥면이 x, y의 수보다 클 경우 이동방향 시계방향 90도 회전
			direction = (direction + 1) % 4;
		}
		else if (dice[3][1] < board[x][y]) {	//반대의 경우 이동방향 반시계방향 90도 회전
			if (direction == 0)	direction = 3;
			else	direction--;
		}
	}
	cout << answer << endl;

	return 0;
}
//주사위를 direction방향으로 굴리고 주사위의 정보를 갱신
void move(int& x, int& y, int& direction, int dice[4][3]) {
	int temp;
	if (direction == 0) {
		if (y + 1 == M) {
			direction = 2;
			move(x, y, direction, dice);
		}
		else {
			y++;
			temp = dice[1][0];
			dice[1][0] = dice[3][1];
			dice[3][1] = dice[1][2];
			dice[1][2] = dice[1][1];
			dice[1][1] = temp;
		}
	}
	else if (direction == 1) {
		if (x + 1 == N) {
			direction = 3;
			move(x, y, direction, dice);
		}
		else {
			x++;
			temp = dice[0][1];
			dice[0][1] = dice[3][1];
			dice[3][1] = dice[2][1];
			dice[2][1] = dice[1][1];
			dice[1][1] = temp;
		}
	}
	else if (direction == 2) {
		if (y - 1 == -1) {
			direction = 0;
			move(x, y, direction, dice);
		}
		else {
			y--;
			temp = dice[1][2];
			dice[1][2] = dice[3][1];
			dice[3][1] = dice[1][0];
			dice[1][0] = dice[1][1];
			dice[1][1] = temp;
		}
	}
	else {
		if (x - 1 == -1) {
			direction = 1;
			move(x, y, direction, dice);
		}
		else {
			x--;
			temp = dice[2][1];
			dice[2][1] = dice[3][1];
			dice[3][1] = dice[0][1];
			dice[0][1] = dice[1][1];
			dice[1][1] = temp;
		}
	}
	return;
}
//인접한 칸을 살피며 board[x][y]와 연결되어 있고 같은 수를 가진 칸의 갯수 반환
int DFS(int x, int y, int board[20][20], int visited[20][20]) {
	int ret = 1, nx, ny;
	visited[x][y] = 1;

	for (int a = 0; a < 4; a++) {
		nx = x + dx[a];
		ny = y + dy[a];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == 0 && board[nx][ny] == board[x][y]) {
			ret += DFS(nx, ny, board, visited);
		}
	}

	return ret;
}