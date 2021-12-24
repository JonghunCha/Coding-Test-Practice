/*
문제 링크 : https://www.acmicpc.net/problem/19237
단순 구현 문제다.

주어진 조건에 따라 구현만 하면 된다.(구현 난이도도 어렵지 않다)
*/
#include <iostream>
using namespace std;

int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };

int main(void) {
	int N, M, k, map[20][20][2], map_copy[20][20][2], shark[401][3], shark_info[401][5][5], count = 0, shark_num;
	int nx, ny, temp;
	bool find_empty;
	//입력값 저장 + map_copy는 상어가 이동과정에서 서로 잡아먹는 것을 구현하기 위한 것
	cin >> N; cin >> M; cin >> k;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			cin >> map[a][b][0];
			map_copy[a][b][0] = map[a][b][0];
			if (map[a][b][0] != 0) {
				shark[map[a][b][0]][0] = a;
				shark[map[a][b][0]][1] = b;
				map[a][b][1] = k;
				map_copy[a][b][1] = k;
			}
			else {
				map[a][b][1] = 0;
				map_copy[a][b][1] = 0;
			}
		}
	}
	for (int a = 1; a <= M; a++)	cin >> shark[a][2];
	for (int a = 1; a <= M; a++) {
		for (int b = 1; b <= 4; b++) {
			for (int c = 1; c <= 4; c++) {
				cin >> shark_info[a][b][c];
			}
		}
	}
	//최대 1000번 반복하며, 남은 상어 수가 1이 되면 종료
	shark_num = M;
	while (count <= 1000) {
		if (shark_num == 1)	break;
		for (int a = 1; a <= M; a++) {
			find_empty = false;	//상어가 빈 공간을 찾았는지 나타냄(못찾은 경우 자신이 냄새를 뿌린 곳 탐색)
			if (shark[a][0] != -1) {	//죽은 상어가 아니라면
				//인접한 방향을 우선순위에 따라 빈 공간인지 탐색
				for (int b = 1; b <= 4; b++) {
					nx = shark[a][0] + dx[shark_info[a][shark[a][2]][b]];
					ny = shark[a][1] + dy[shark_info[a][shark[a][2]][b]];
					if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny][0] == 0) {
						temp = map_copy[nx][ny][0];
						//이동과정에서 이미 그 자리에 다른 상어가 들어와 있는 경우 크기 비교하여 1마리만 살린다
						if (temp != 0 && a < temp) {
							shark[temp][0] = -1;
							shark_num--;
							map_copy[nx][ny][0] = a;
							shark[a][0] = nx;
							shark[a][1] = ny;
							shark[a][2] = shark_info[a][shark[a][2]][b];
							find_empty = true;
							break;
						}
						else if (temp != 0 && a > temp) {
							shark[a][0] = -1;
							shark_num--;
							find_empty = true;
							break;
						}
						else {
							map_copy[nx][ny][0] = a;
							shark[a][0] = nx;
							shark[a][1] = ny;
							shark[a][2] = shark_info[a][shark[a][2]][b];
							find_empty = true;
							break;
						}
					}
				}
				//인접한 곳에 빈 공간이 없는 경우 자신의 냄새를 찾아서 이동
				if (!find_empty) {
					for (int b = 1; b <= 4; b++) {
						nx = shark[a][0] + dx[shark_info[a][shark[a][2]][b]];
						ny = shark[a][1] + dy[shark_info[a][shark[a][2]][b]];
						if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny][0] == a) {
							shark[a][0] = nx;
							shark[a][1] = ny;
							shark[a][2] = shark_info[a][shark[a][2]][b];
							break;
						}
					}
				}
			}
		}
		//k값을 업데이트
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (map_copy[a][b][1] == 1) {
					map_copy[a][b][0] = 0;
					map_copy[a][b][1] = 0;
				}
				else if (map_copy[a][b][1] > 1) {
					map_copy[a][b][1]--;
				}
			}
		}
		//이동한 상어 위치의 공간 정보 업데이트
		for (int a = 1; a <= M; a++) {
			if (shark[a][0] != -1) {
				map_copy[shark[a][0]][shark[a][1]][0] = a;
				map_copy[shark[a][0]][shark[a][1]][1] = k;
			}
		}
		//map에다가 map_copy를 복사
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				map[a][b][0] = map_copy[a][b][0];
				map[a][b][1] = map_copy[a][b][1];
			}
		}
		count++;
	}
	if (count > 1000)	cout << -1;
	else	cout << count;

	return 0;
}