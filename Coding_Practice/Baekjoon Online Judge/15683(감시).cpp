/*
문제 링크 : https://www.acmicpc.net/problem/15683
완전 탐색으로 해결할 수 있다.

전체 사무실을 탐색하며 cctv가 있는 위치를 파악한 뒤, cctv들이 감시할 수 있는 방향의 모든 조합에 대해 시뮬레이션을 돌려본 뒤, 가장 사각지대가 적은 값을 갱신하면 된다.
*/
#include <iostream>
using namespace std;

int answer = 100;

void Get_Answer(int N, int M, const int map[8][8], int direction[8][8][4], int step);
void Calculate(int N, int M, const int map[8][8], int direction[8][8][4]);

int main(void) {
	//direction은 x, y좌표에서 동서남북에 대해 cctv가 관찰하는지 안하는지를 의미(0=북,1=동,2=남,3=서)
	int N, M, map[8][8], direction[8][8][4];
	//입력값 저장
	cin >> N; cin >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	//direction 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				direction[i][j][k] = 0;
			}
		}
	}

	Get_Answer(N, M, map, direction, 0);

	cout << answer;
	return 0;
}

void Get_Answer(int N, int M, const int map[8][8], int direction[8][8][4], int step) {
	//step이 N*M이라는 것은 전체 cctv에 대해 방향 설정이 완료되었음을 의미
	if (step == N * M) {
		Calculate(N, M, map, direction);
		return;
	}
	int x = step / M, y = step % M;
	//해당 지역이 빈공간이거나 벽이라면 방향설정할 필요 없음
	if (map[x][y] == 0 || map[x][y] == 6) {
		Get_Answer(N, M, map, direction, step + 1);
	}
	//1번 cctv의 경우 4가지 방향 설정 가능
	else if (map[x][y] == 1) {
		direction[x][y][0] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][0] = 0;
		direction[x][y][1] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][1] = 0;
		direction[x][y][2] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][2] = 0;
		direction[x][y][3] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][3] = 0;
	}
	//2번 cctv의 경우 2가지 방향 설정 가능
	else if (map[x][y] == 2) {
		direction[x][y][0] = 1;
		direction[x][y][2] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][0] = 0;
		direction[x][y][2] = 0;
		direction[x][y][1] = 1;
		direction[x][y][3] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][1] = 0;
		direction[x][y][3] = 0;
	}
	//3번 cctv의 경우 4가지 방향 설정 가능
	else if (map[x][y] == 3) {
		direction[x][y][0] = 1;
		direction[x][y][1] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][0] = 0;
		direction[x][y][2] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][1] = 0;
		direction[x][y][3] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][2] = 0;
		direction[x][y][0] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][0] = 0;
		direction[x][y][3] = 0;
	}
	//4번 cctv의 경우 4가지 방향 설정 가능
	else if (map[x][y] == 4) {
		direction[x][y][0] = 1;
		direction[x][y][1] = 1;
		direction[x][y][2] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][2] = 0;
		direction[x][y][3] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][1] = 0;
		direction[x][y][2] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][0] = 0;
		direction[x][y][1] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][1] = 0;
		direction[x][y][2] = 0;
		direction[x][y][3] = 0;
	}
	//5번 cctv의 경우 모든 방향으로 설정
	else if (map[x][y] == 5) {
		direction[x][y][0] = 1;
		direction[x][y][1] = 1;
		direction[x][y][2] = 1;
		direction[x][y][3] = 1;
		Get_Answer(N, M, map, direction, step + 1);
	}
}

void Calculate(int N, int M, const int map[8][8], int direction[8][8][4]) {
	int __map[8][8], num_zero = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			__map[i][j] = map[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//북쪽 방향일 경우
			if (direction[i][j][0]) {
				for (int a = i; a >= 0; a--) {
					if (__map[a][j] == 6)	break;
					else if (__map[a][j] == 0) {
						__map[a][j] = 7;
					}
					else	continue;
				}
			}
			//동쪽 방향일 경우
			if (direction[i][j][1]) {
				for (int a = j; a < M; a++) {
					if (__map[i][a] == 6)	break;
					else if (__map[i][a] == 0) {
						__map[i][a] = 7;
					}
					else	continue;
				}
			}
			//남쪽 방향일 경우
			if (direction[i][j][2]) {
				for (int a = i; a < N; a++) {
					if (__map[a][j] == 6)	break;
					else if (__map[a][j] == 0) {
						__map[a][j] = 7;
					}
					else	continue;
				}
			}
			//서쪽 방향일 경우
			if (direction[i][j][3]) {
				for (int a = j; a >= 0; a--) {
					if (__map[i][a] == 6)	break;
					else if (__map[i][a] == 0) {
						__map[i][a] = 7;
					}
					else	continue;
				}
			}
		}
	}
	//빈 공간 카운팅
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (__map[i][j] == 0)	num_zero++;
		}
	}
	//빈 공간의 최솟값 갱신
	if (num_zero < answer)	answer = num_zero;
}