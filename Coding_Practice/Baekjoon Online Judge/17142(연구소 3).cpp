/*
문제 링크 : https://www.acmicpc.net/problem/17142
BFS를 이용한 완전 탐색으로 해결할 수 있는 문제다.

우선 활성 바이러스 M개를 선택해야 한다.

선택된 M개의 바이러스좌표를 Queue에 넣는다.

그런 다음 Queue에서 하나씩 pop하며 주변 칸에 바이러스를 확산 시키고 새롭게 확산 된 바이러스를 Queue에 넣어준다.

이 과정을 Queue가 빌때까지 반복하면 확산 과정은 끝난 것이다.

여기서 연구소 전체에 바이러스가 확산 되었는지 아닌지를 판단하여 정답을 구하면 된다.
*/
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int answer = 100000;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void Make_Combination(int N, int M, int lab[50][50], int selected, int x, int y);
void Spread(int N, int lab[50][50]);
bool Is_All_Spread(int N, int lab[50][50]);

int main(void) {
	int N, M, lab[50][50];
	//입력값 저장
	cin >> N; cin >> M;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			cin >> lab[a][b];
		}
	}
	//M개의 조합을 만들고 확산 시뮬레이션
	Make_Combination(N, M, lab, 0, 0, 0);
	if (answer == 100000)	cout << -1;
	else	cout << answer;

	return 0;
}

void Make_Combination(int N, int M, int lab[50][50], int selected, int x, int y) {
	//M개의 활성 바이러스를 고른 경우 확산 실시
	if (selected == M) {
		Spread(N, lab);
		return;
	}
	//활성 바이러스를 하나씩 고른다
	for (int a = y; a < N; a++) {
		if (lab[x][a] == 2) {
			lab[x][a] = 3;
			if (a == N - 1 && x != N - 1)	Make_Combination(N, M, lab, selected + 1, x + 1, 0);
			else	Make_Combination(N, M, lab, selected + 1, x, a + 1);
			lab[x][a] = 2;
		}
	}
	for (int a = x + 1; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (lab[a][b] == 2) {
				lab[a][b] = 3;
				if (b == N - 1 && a != N - 1)	Make_Combination(N, M, lab, selected + 1, a + 1, 0);
				else	Make_Combination(N, M, lab, selected + 1, a, b + 1);
				lab[a][b] = 2;
			}
		}
	}
}

void Spread(int N, int lab[50][50]) {
	//바이러스의 좌표를 저장하는 큐
	queue<pair<int, int>> q;
	int lab_copy[50][50];	//벽은 -10000, 초기 활성 바이러스는 0, 비활성 바이러스는 -1, 빈칸은 -100으로 초기화
	int count = 0, x, y;
	bool flag = true;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (lab[a][b] == 0)		lab_copy[a][b] = -100;
			else if (lab[a][b] == 1)	lab_copy[a][b] = -10000;
			else if (lab[a][b] == 2)	lab_copy[a][b] = -1;
			else	lab_copy[a][b] = 0;
		}
	}
	//초기 활성 바이러스 큐에 추가
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (lab_copy[a][b] == 0)	q.emplace(a, b);
		}
	}
	//만약 처음부터 빈칸이 없다면 정답은 0
	if (Is_All_Spread(N, lab_copy)) {
		answer = 0;
		return;
	}
	while (!q.empty()) {
		int x, y;
		int nx, ny;
		x = q.front().first;
		y = q.front().second;
		q.pop();
		//큐에서 뽑아낸 좌표의 4방향을 살핌
		for (int a = 0; a < 4; a++) {
			nx = x + dx[a];
			ny = y + dy[a];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				//빈 공간이거나 비활성 바이러스가 있는 곳이라면 확산 시킨다
				if (lab_copy[nx][ny] == -100 || lab_copy[nx][ny] == -1) {
					lab_copy[nx][ny] = lab_copy[x][y] + 1;
					//최소 시간 갱신
					if (lab_copy[nx][ny] > count && lab[nx][ny] == 0)	count = lab_copy[nx][ny];
					//새롭게 확산된 바이러스의 좌표 큐에 추가
					q.emplace(nx, ny);
				}
			}
		}
	}
	//모든 빈 칸에 바이러스가 확산된 경우 정답 갱신
	if (Is_All_Spread(N, lab_copy)) {
		if (count < answer)	answer = count;
	}
}
//연구실에 바이러스가 확산되지 않은 곳이 있는지 확인
bool Is_All_Spread(int N, int lab[50][50]) {
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (lab[a][b] == -100)	return false;
		}
	}
	return true;
}