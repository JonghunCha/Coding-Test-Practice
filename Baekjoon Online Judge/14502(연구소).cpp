/*
문제 링크 : https://www.acmicpc.net/problem/14502
완전 탐색으로 해결할 수 있는 문제다.

빈 공간에 3개의 벽을 세우는 모든 조합에 대해 바이러스가 퍼지는 상황을 구현한 뒤 가장 안정 영역이 넓은 경우를 갱신하면 된다.
*/
#include <iostream>
using namespace std;

int answer = 0;

void Make_Combination(int N, int M, int map[8][8], int step);
void Try_Simulation(int N, int M, int map[8][8]);
void Check_Near(int N, int M, int map[8][8], int x, int y);

int main(void) {
	int N, M, map[8][8];
	//입력값 저장
	cin >> N; cin >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	//3개의 벽을 세우는 모든 조합에 대해 시뮬레이션
	Make_Combination(N, M, map, 0);
	cout << answer;
	return 0;
}

void Make_Combination(int N, int M, int map[8][8], int step) {
	if (step == 3) {
		Try_Simulation(N, M, map);
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 3;
				Make_Combination(N, M, map, step + 1);
				map[i][j] = 0;
			}
		}
	}
}

void Try_Simulation(int N, int M, int map[8][8]) {
	int _map[8][8], safe_num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			_map[i][j] = map[i][j];
		}
	}
	//바이러스가 있다면 근처의 빈 공간에 퍼져나가게 한다
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (_map[i][j] == 2) {
				Check_Near(N, M, _map, i, j);
			}
		}
	}
	//바이러스가 다 퍼진 후 안정 영역의 크기 계산
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (_map[i][j] == 0)	safe_num++;
		}
	}
	if (safe_num > answer)	answer = safe_num;
}

void Check_Near(int N, int M, int map[8][8], int x, int y) {
	//바이러스가 있는 칸 위쪽 확인
	if (x != 0 && map[x - 1][y] == 0) {
		map[x - 1][y] = 2;
		Check_Near(N, M, map, x - 1, y);
	}
	//바이러스가 있는 칸 오른쪽 확인
	if (y != M - 1 && map[x][y + 1] == 0) {
		map[x][y + 1] = 2;
		Check_Near(N, M, map, x, y + 1);
	}
	//바이러스가 있는 칸 아래쪽 확인
	if (x != N - 1 && map[x + 1][y] == 0) {
		map[x + 1][y] = 2;
		Check_Near(N, M, map, x + 1, y);
	}
	//바이러스가 있는 칸 왼쪽 확인
	if (y != 0 && map[x][y - 1] == 0) {
		map[x][y - 1] = 2;
		Check_Near(N, M, map, x, y - 1);
	}
}