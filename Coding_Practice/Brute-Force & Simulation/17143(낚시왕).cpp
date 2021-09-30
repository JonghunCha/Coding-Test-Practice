/*
���� ��ũ : https://www.acmicpc.net/problem/17143
�ܼ� ���� ������.

������ ���� 1�� ���ĺ��ʹ� �� ���� ������ ��ĥ �� �ְ� �̷��� ��� ū �� ���� �� ��� �Դ´ٰ� �Ѵ�.

�̸� �����ϱ� ���ؼ� �� �̵��� �� �� ������ map�� �ϳ� �� ����� �� �ϳ��� �̵� ��Ű�� 
���� ��ġ�� ��� ū �� ���� �� ��� �Ե��� �Ͽ���.
*/
#include <iostream>
using namespace std;

void Move_Shark(int R, int C, int*** map);

int main(void) {
	int R, C, M, r, c, s, d, z, answer = 0;
	int*** map;
	//�Է°� ����
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
	//map�� ��� ���� ����
	for (int a = 0; a < M; a++) {
		cin >> r; cin >> c; cin >> s; cin >> d; cin >> z;
		map[r][c][0] = s;
		map[r][c][1] = d;
		map[r][c][2] = z;
	}
	//�� ���� ���������� ��������
	for (int a = 1; a <= C; a++) {
		for (int b = 1; b <= R; b++) {
			//���� ����� �� ����, answer�� ��� ũ�⸸ŭ ���Ѵ�
			if (map[b][a][0] != -1) {
				answer += map[b][a][2];
				map[b][a][0] = -1; map[b][a][1] = -1; map[b][a][2] = -1;
				break;
			}
		}
		//��� �̵� �ǽ�
		Move_Shark(R, C, map);
	}
	cout << answer;

	//���� �Ҵ� ����
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
	//�� �̵���Ű�� ���� ����� map_copy�� �Ҵ�ް� �ʱ�ȭ
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
	//��� ������ �̵� ��Ų��
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
				//�̵� ��Ų �ڸ��� �̹� �ٸ� �� �̵��� ���
				if (map_copy[x][y][0] != -1) {
					if (size > map_copy[x][y][2]) {
						map_copy[x][y][0] = speed;
						map_copy[x][y][1] = direction;
						map_copy[x][y][2] = size;
					}
				}
				//�̵� ��Ų �ڸ��� ����ִ� ���
				else {
					map_copy[x][y][0] = speed;
					map_copy[x][y][1] = direction;
					map_copy[x][y][2] = size;
				}
			}
		}
	}
	//���� �Ҵ� ����
	for (int a = 0; a <= R; a++) {
		for (int b = 0; b <= C; b++) {
			for (int c = 0; c < 3; c++) {
				map[a][b][c] = map_copy[a][b][c];
			}
		}
	}
}