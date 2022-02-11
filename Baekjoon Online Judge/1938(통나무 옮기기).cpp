/*
문제 링크 : https://www.acmicpc.net/problem/1938
BFS를 이용하여 해결할 수 있는 문제다.

통나무의 중심점을 기준으로하여 초기 상태의 통나무가 최종 목표 상태의 통나무가 될 때까지 BFS를 통해 탐색을 하면 된다.

코드를 보면 쉽게 이해할 수 있을 것이다.
*/
#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

//각각 위, 아래, 왼쪽, 오른쪽, 회전 이동을 할 수 있는지를 반환하는 함수
bool can_move_U(int N, char land[50][50], int x, int y, int state);
bool can_move_D(int N, char land[50][50], int x, int y, int state);
bool can_move_L(int N, char land[50][50], int x, int y, int state);
bool can_move_R(int N, char land[50][50], int x, int y, int state);
bool can_move_T(int N, char land[50][50], int x, int y, int state);

int main(void) {
	//입력값 저장
	int N;
	char land[50][50];

	scanf("%d", &N);
	for (int a = 0; a < N; a++) {
		scanf("%s", land[a]);
	}

	//B와 E인 곳의 위치 파악
	int B[3][2], E[3][2], b_num = 0, e_num = 0;

	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (land[a][b] == 'B') {
				B[b_num][0] = a;
				B[b_num][1] = b;
				b_num++;
			}
			else if (land[a][b] == 'E') {
				E[e_num][0] = a;
				E[e_num][1] = b;
				e_num++;
			}
		}
	}

	//통나무의 중심범의 위치와 가로로 놓였는지 세로로 놓였는지 계산(초기와 목적지 모두), 상태는 0이면 가로 1이면 세로
	int curr_x, curr_y, curr_state, dst_x, dst_y, dst_state;

	curr_x = B[1][0];
	curr_y = B[1][1];
	if (B[1][0] == B[0][0])	curr_state = 0;
	else	curr_state = 1;
	dst_x = E[1][0];
	dst_y = E[1][1];
	if (E[1][0] == E[0][0])	dst_state = 0;
	else	dst_state = 1;

	//BFS를 통해서 목적지까지 가장 짧은 경우를 찾는다
	bool visited[50][50][2];	//visited[a][b][c]가 false인 경우는 a, b좌표에 c상태로 방문한 적이 없음을 의미(true는 그 반대)
	queue<tuple<int, int, int, int>> q;
	int move_num = 0, new_state, answer = 0;

	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			visited[a][b][0] = false;
			visited[a][b][1] = false;
		}
	}

	q.push(make_tuple(curr_x, curr_y, curr_state, move_num));	//초기 시작지점을 큐에 삽입
	visited[curr_x][curr_y][curr_state] = true;
	while (!q.empty()) {
		curr_x = get<0>(q.front());
		curr_y = get<1>(q.front());
		curr_state = get<2>(q.front());
		move_num = get<3>(q.front());
		q.pop();

		//만약 도착지점에 왔다면 정답을 기록하고 종료
		if (curr_x == dst_x && curr_y == dst_y && curr_state == dst_state) {
			answer = move_num;
			break;
		}

		//위로 이동가능한 경우 큐에 move_num을 1 높여서 삽입
		if (can_move_U(N, land, curr_x, curr_y, curr_state) && visited[curr_x - 1][curr_y][curr_state] == false) {
			visited[curr_x - 1][curr_y][curr_state] = true;
			q.push(make_tuple(curr_x - 1, curr_y, curr_state, move_num + 1));
		}
		//아래로 이동가능한 경우 큐에 move_num을 1 높여서 삽입
		if (can_move_D(N, land, curr_x, curr_y, curr_state) && visited[curr_x + 1][curr_y][curr_state] == false) {
			visited[curr_x + 1][curr_y][curr_state] = true;
			q.push(make_tuple(curr_x + 1, curr_y, curr_state, move_num + 1));
		}
		//왼쪽으로 이동가능한 경우 큐에 move_num을 1 높여서 삽입
		if (can_move_L(N, land, curr_x, curr_y, curr_state) && visited[curr_x][curr_y - 1][curr_state] == false){
			visited[curr_x][curr_y - 1][curr_state] = true;
			q.push(make_tuple(curr_x, curr_y - 1, curr_state, move_num + 1));
		}
		//오른쪽으로 이동가능한 경우 큐에 move_num을 1 높여서 삽입
		if (can_move_R(N, land, curr_x, curr_y, curr_state) && visited[curr_x][curr_y + 1][curr_state] == false) {
			visited[curr_x][curr_y + 1][curr_state] = true;
			q.push(make_tuple(curr_x, curr_y + 1, curr_state, move_num + 1));
		}
		//회전을 할 수 있는 경우 큐에 move_num을 1 높여서 삽입
		if (can_move_T(N, land, curr_x, curr_y, curr_state)) {
			if (curr_state == 0)	new_state = 1;
			else	new_state = 0;
			
			if (visited[curr_x][curr_y][new_state] == false) {
				visited[curr_x][curr_y][new_state] = true;
				q.push(make_tuple(curr_x, curr_y, new_state, move_num + 1));
			}
		}
	}

	printf("%d\n", answer);

	return 0;
}

bool can_move_U(int N, char land[50][50], int x, int y, int state) {
	int nx[3], ny[3];

	if (state == 0) {
		nx[0] = x - 1; nx[1] = x - 1; nx[2] = x - 1;
		ny[0] = y - 1; ny[1] = y; ny[2] = y + 1;
	}
	else {
		nx[0] = x - 2; nx[1] = x - 1; nx[2] = x;
		ny[0] = y; ny[1] = y; ny[2] = y;
	}

	for (int a = 0; a < 3; a++) {
		if (nx[a] < 0 || nx[a] >= N || ny[a] < 0 || ny[a] >= N || land[nx[a]][ny[a]] == '1')	return false;
	}

	return true;
}

bool can_move_D(int N, char land[50][50], int x, int y, int state) {
	int nx[3], ny[3];

	if (state == 0) {
		nx[0] = x + 1; nx[1] = x + 1; nx[2] = x + 1;
		ny[0] = y - 1; ny[1] = y; ny[2] = y + 1;
	}
	else {
		nx[0] = x; nx[1] = x + 1; nx[2] = x + 2;
		ny[0] = y; ny[1] = y; ny[2] = y;
	}

	for (int a = 0; a < 3; a++) {
		if (nx[a] < 0 || nx[a] >= N || ny[a] < 0 || ny[a] >= N || land[nx[a]][ny[a]] == '1')	return false;
	}

	return true;
}

bool can_move_L(int N, char land[50][50], int x, int y, int state) {
	int nx[3], ny[3];

	if (state == 0) {
		nx[0] = x; nx[1] = x; nx[2] = x;
		ny[0] = y - 2; ny[1] = y - 1; ny[2] = y;
	}
	else {
		nx[0] = x - 1; nx[1] = x; nx[2] = x + 1;
		ny[0] = y - 1; ny[1] = y - 1; ny[2] = y - 1;
	}

	for (int a = 0; a < 3; a++) {
		if (nx[a] < 0 || nx[a] >= N || ny[a] < 0 || ny[a] >= N || land[nx[a]][ny[a]] == '1')	return false;
	}

	return true;
}

bool can_move_R(int N, char land[50][50], int x, int y, int state) {
	int nx[3], ny[3];

	if (state == 0) {
		nx[0] = x; nx[1] = x; nx[2] = x;
		ny[0] = y; ny[1] = y + 1; ny[2] = y + 2;
	}
	else {
		nx[0] = x - 1; nx[1] = x; nx[2] = x + 1;
		ny[0] = y + 1; ny[1] = y + 1; ny[2] = y + 1;
	}

	for (int a = 0; a < 3; a++) {
		if (nx[a] < 0 || nx[a] >= N || ny[a] < 0 || ny[a] >= N || land[nx[a]][ny[a]] == '1')	return false;
	}

	return true;
}

bool can_move_T(int N, char land[50][50], int x, int y, int state) {
	for (int a = x - 1; a <= x + 1; a++) {
		for (int b = y - 1; b <= y + 1; b++) {
			if (a < 0 || a >= N || b < 0 || b >= N || land[a][b] == '1')	return false;
		}
	}
	return true;
}