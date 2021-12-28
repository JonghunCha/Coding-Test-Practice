/*
문제 링크 : https://www.acmicpc.net/problem/17143
단순 구현 문제다.

주의할 점은 1초 이후부터는 상어가 같은 공간에 겹칠 수 있고 이러한 경우 큰 상어가 작은 상어를 잡아 먹는다고 한다.

이를 구현하기 위해서 상어가 이동할 때 빈 공간의 map을 하나 더 만들어 상어를 하나씩 이동 시키고 
만약 겹치는 경우 큰 상어가 작은 상어를 잡아 먹도록 하였다.
*/
#include <iostream>
using namespace std;

void Move_Shark(int R, int C, int*** map);

int main(void) {
	int R, C, M, r, c, s, d, z, answer = 0;
	int*** map;
	//입력값 저장
	cin >> R; cin >> C; cin >> M;
	map = new int** [R + 1];
	for (int a = 0; a <= R; a++) {
		map[a] = new int*[C + 1];
		for (int b = 0; b <= C; b++) {
			map[a][b] = new int[3];
		}
	}
	for (int a = 0; a <= R; a++) {
		for (int b = 0; b <= C; b++) {
			for (int c = 0; c < 3; c++) {
				map[a][b][c] = -1;
			}
		}
	}
	//map에 상어 정보 저장
	for (int a = 0; a < M; a++) {
		cin >> r; cin >> c; cin >> s; cin >> d; cin >> z;
		map[r][c][0] = s;
		map[r][c][1] = d;
		map[r][c][2] = z;
	}
	//각 열을 순차적으로 지나가며
	for (int a = 1; a <= C; a++) {
		for (int b = 1; b <= R; b++) {
			//가장 가까운 상어를 낚고, answer를 상어 크기만큼 더한다
			if (map[b][a][0] != -1) {
				answer += map[b][a][2];
				map[b][a][0] = -1; map[b][a][1] = -1; map[b][a][2] = -1;
				break;
			}
		}
		//상어 이동 실시
		Move_Shark(R, C, map);
	}
	cout << answer;

	//동적 할당 해제
	for (int a = 0; a <= R; a++) {
		for (int b = 0; b <= C; b++) {
			delete[]map[a][b];
		}
	}
	for (int a = 0; a <= R; a++) {
		delete[]map[a];
	}
	delete[]map;

	return 0;
}

void Move_Shark(int R, int C, int*** map) {
	int x, y, speed, direction, size;
	//상어를 이동시키기 위해 빈공간 map_copy를 할당받고 초기화
	int*** map_copy;
	map_copy = new int** [R + 1];
	for (int a = 0; a <= R; a++) {
		map_copy[a] = new int* [C + 1];
		for (int b = 0; b <= C; b++) {
			map_copy[a][b] = new int[3];
		}
	}
	for (int a = 0; a <= R; a++) {
		for (int b = 0; b <= C; b++) {
			for (int c = 0; c < 3; c++) {
				map_copy[a][b][c] = -1;
			}
		}
	}
	//모든 상어들을 이동 시킨다
	for (int a = 1; a <= R; a++) {
		for (int b = 1; b <= C; b++) {
			if (map[a][b][0] != -1) {
				x = a;
				y = b;
				speed = map[a][b][0];
				direction = map[a][b][1];
				size = map[a][b][2];
				for (int c = 1; c <= speed; c++) {
					if (direction == 1) {
						if (x != 1)	x--;
						else {
							direction = 2;
							x++;
						}
					}
					else if (direction == 2) {
						if (x != R)	x++;
						else {
							direction = 1;
							x--;
						}
					}
					else if (direction == 3) {
						if (y != C) y++;
						else {
							direction = 4;
							y--;
						}
					}
					else if (direction == 4) {
						if (y != 1)	y--;
						else {
							direction = 3;
							y++;
						}
					}
				}
				//이동 시킨 자리에 이미 다른 상어가 이동한 경우
				if (map_copy[x][y][0] != -1) {
					if (size > map_copy[x][y][2]) {
						map_copy[x][y][0] = speed;
						map_copy[x][y][1] = direction;
						map_copy[x][y][2] = size;
					}
				}
				//이동 시킨 자리가 비어있는 경우
				else {
					map_copy[x][y][0] = speed;
					map_copy[x][y][1] = direction;
					map_copy[x][y][2] = size;
				}
			}
		}
	}
	//동적 할당 해제
	for (int a = 0; a <= R; a++) {
		for (int b = 0; b <= C; b++) {
			for (int c = 0; c < 3; c++) {
				map[a][b][c] = map_copy[a][b][c];
			}
		}
	}
}