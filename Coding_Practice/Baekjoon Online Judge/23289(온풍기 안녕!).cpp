/*
���� ��ũ : https://www.acmicpc.net/problem/23289
�ܼ� ���� �����̴�.

�׷��� ���� ������ ������ �����ؼ� �ڵ尡 ���� ��� �ϴ�.
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
	//room�� �� ĭ�� �µ� ����, room_copy�� step1������ �ٶ��� ���޵� ���� ������ step2������ �µ� ������ �ϰ� ������ ���� ���
	//walls�� �� ĭ�� �� �� �� �� ������ ���� ������ ����
	int room[21][21], room_copy[21][21], walls[21][21][4], temp, answer = 0, x, y, direction;
	vector<tuple<int, int, int>> machine;	//��ǳ���� ��ǥ �� ���� ����
	vector<tuple<int, int>> check;	//�˻��ؾ��� ĭ�� ��ǥ ����
	bool check_end;
	//�Է°� ���� �� ���� �ʱ�ȭ
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
	//�ִ� 100�� �ݺ�
	while (answer < 101) {
		//��� ��ǳ�⿡ ���� step1�Լ��� ȣ�������ν� �ٶ��� ����Ŵ
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
		//stpe2�� ȣ�������ν� �µ� ����
		for (int a = 1; a <= R; a++) {
			for (int b = 1; b <= C; b++) {
				room_copy[a][b] = 0;
			}
		}
		step2(room, walls, room_copy);
		//�ٱ����� ĭ �µ� 1�� ����
		for (int a = 1; a <= R; a++) {
			for (int b = 1; b <= C; b++) {
				if (a == 1 || a == R || b == 1 || b == C) {
					if (room[a][b] >= 1)	room[a][b]--;
				}
			}
		}
		//���ݸ� �Ա�
		answer++;
		//�˻��� ĭ ��ΰ� K�̻��̸� ����
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
//�� ���⿡ ���� ���ǹ��� ���� �����Ͽ����� �ּ��� ������ ���� �ۼ��Ͽ���
void step1(int room[21][21], int walls[21][21][4], int room_copy[21][21], int x, int y, int direction) {
	int curr = 4;
	if (direction == 1) {	//��ǳ�� ������ ������ ��
		room[x][++y] += 5;	//������ ���� ������ ĭ�� �µ� 5 ���
		room_copy[x][y] = 1;	//�ٶ��� ������ ������ ǥ��
		while (curr > 0) {
			y++;
			if (y > C)	return;	//���� ��� ��� ����

			for (int a = 1; a <= R; a++) {
				if (room_copy[a][y - 1] == 1) {	//�ٶ��� ������ ĭ�� �߰�
					if (a - 1 >= 1 && walls[a][y - 1][0] == 0 && walls[a - 1][y][3] == 0 && room_copy[a - 1][y] == 0) {	//�밢�� ���� �ٶ��� �� �� ���� ��
						room[a - 1][y] += curr;
						room_copy[a - 1][y] = 1;
					}
					if (a + 1 <= R && walls[a][y - 1][2] == 0 && walls[a + 1][y][3] == 0 && room_copy[a + 1][y] == 0) {	//�밢�� �Ʒ��� �ٶ��� �� �� ���� ��
						room[a + 1][y] += curr;
						room_copy[a + 1][y] = 1;
					}
					if (walls[a][y][3] == 0 && room_copy[a][y] == 0) {	//���������� �ٶ��� �� �� ���� ��
						room[a][y] += curr;
						room_copy[a][y] = 1;
					}
				}
			}
			curr--;	//���� �ٶ��� �µ� ����
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
//������ ������ ���� ������ ������ ���� ĭ���� ���� �µ���� �µ��� ����
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