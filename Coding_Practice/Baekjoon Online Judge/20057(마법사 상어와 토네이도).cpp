/*
���� ��ũ : https://www.acmicpc.net/problem/20057
�ܼ� ���� ������.

����̵��� �̵��ϴ� ������ ��Ģ�� �ľ��ϸ� �����ϱ� ����.

����̵��� �̵� ��Ģ�� �Ʒ��� ����.

1. �������� nĭ
2. �Ʒ������� nĭ
3. ���������� n+1ĭ
4. �������� n+1ĭ
....

����̵��� ���� ���� ���� �Ʒ����� nĭ ������ �Ŀ� ������ �������δ� n+1ĭ�� ������. �׷� ���� ���� �Ʒ����� ���� �� n+2ĭ�� ������.

�̷��� �������� (1,1)��ǥ�� ���� ������ �ݺ��ϸ� �𷡸� �̵������ָ� �ȴ�.
*/
#include <iostream>
using namespace std;

double percentage[9] = { 1.0, 1.0, 7.0, 7.0, 2.0, 2.0, 10.0, 10.0, 5.0 };
int dx_0[9] = { -1, 1, -1, 1, -2, 2, -1, 1, 0 };
int dy_0[9] = { 0, 0, -1, -1, -1, -1, -2, -2, -3 };
int dx_1[9] = { 0, 0, 1, 1, 1, 1, 2, 2, 3 };
int dy_1[9] = { -1, 1, -1, 1, -2, 2, -1, 1, 0 };
int dx_2[9] = { 1, -1, 1, -1, 2, -2, 1, -1, 0 };
int dy_2[9] = { 0, 0, 1, 1, 1, 1, 2, 2, 3 };
int dx_3[9] = { 0, 0, -1, -1, -1, -1, -2, -2, -3 };
int dy_3[9] = { 1, -1, 1, -1, 2, -2, 1, -1, 0 };

int main(void) {
	int N, answer = 0, x, y, direction, step, nx, ny;	//direction 0 = ����, 1 = �Ʒ���, 2 = ������, 3 = ����. step�� ���� �������� �� ���� �̵��ϴ��� �ǹ�
	int** map;
	double moving_sand;	//���������� ���� ���� double�� �Ǽ��� ��Ÿ�� ��(���� �����̴� �𷡾���� ���� ���� �� ����)
	int moved_sand;		//������ ������ ���� ������ ���ķ� ǥ�õ� ������ �̵��� �� ���� ���ϱ� ���� ����
	bool flag = true;
	//�Է°� ����
	cin >> N;
	map = new int*[N];
	for (int a = 0; a < N; a++) {
		map[a] = new int[N];
	}
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			cin >> map[a][b];
		}
	}
	//�ʱ� ���� ����
	x = N / 2;
	y = N / 2;
	direction = 0;
	step = 1;
	while (flag) {
		for (int a = 0; a < step; a++) {
			//�������� �����̴� ���
			if (direction == 0) {
				moved_sand = 0;
				for (int b = 0; b < 9; b++) {
					nx = x + dx_0[b];
					ny = y + dy_0[b];
					moving_sand = (double)map[x][y - 1] * percentage[b] / 100.0;	//���������� �� ��
					moved_sand += (int)moving_sand;	//�Ҽ����� ������ ������ �����̴� ��
					if (nx >= 0 && nx < N && ny >= 0 && ny < N)		map[nx][ny] += (int)moving_sand;	//������ �ȿ� �ִ� ���
					else	answer += (int)moving_sand;	//������ ������ �з����� ���
				}
				nx = x;
				ny = y - 2;
				if (nx >= 0 && nx < N && ny >= 0 && ny < N)	map[nx][ny] += map[x][y - 1] - moved_sand;
				else	answer += map[x][y - 1] - moved_sand;
				map[x][y - 1] = 0;
				y--;
			}
			//�Ʒ������� �����̴� ���
			else if (direction == 1) {
				moved_sand = 0;
				for (int b = 0; b < 9; b++) {
					nx = x + dx_1[b];
					ny = y + dy_1[b];
					moving_sand = (double)map[x + 1][y] * percentage[b] / 100.0;
					moved_sand += (int)moving_sand;
					if (nx >= 0 && nx < N && ny >= 0 && ny < N)		map[nx][ny] += (int)moving_sand;
					else	answer += (int)moving_sand;
				}
				nx = x + 2;
				ny = y;
				if (nx >= 0 && nx < N && ny >= 0 && ny < N)	map[nx][ny] += map[x + 1][y] - moved_sand;
				else	answer += map[x + 1][y] - moved_sand;
				map[x + 1][y] = 0;
				x++;
			}
			//���������� �����̴� ���
			else if (direction == 2) {
				moved_sand = 0;
				for (int b = 0; b < 9; b++) {
					nx = x + dx_2[b];
					ny = y + dy_2[b];
					moving_sand = (double)map[x][y + 1] * percentage[b] / 100.0;
					moved_sand += (int)moving_sand;
					if (nx >= 0 && nx < N && ny >= 0 && ny < N)		map[nx][ny] += (int)moving_sand;
					else	answer += (int)moving_sand;
				}
				nx = x;
				ny = y + 2;
				if (nx >= 0 && nx < N && ny >= 0 && ny < N)	map[nx][ny] += map[x][y + 1] - moved_sand;
				else	answer += map[x][y + 1] - moved_sand;
				map[x][y + 1] = 0;
				y++;
			}
			//�������� �����̴� ���
			else {
				moved_sand = 0;
				for (int b = 0; b < 9; b++) {
					nx = x + dx_3[b];
					ny = y + dy_3[b];
					moving_sand = (double)map[x - 1][y] * percentage[b] / 100.0;
					moved_sand += (int)moving_sand;
					if (nx >= 0 && nx < N && ny >= 0 && ny < N)		map[nx][ny] += (int)moving_sand;
					else	answer += (int)moving_sand;
				}
				nx = x - 2;
				ny = y;
				if (nx >= 0 && nx < N && ny >= 0 && ny < N)	map[nx][ny] += map[x - 1][y] - moved_sand;
				else	answer += map[x - 1][y] - moved_sand;
				map[x - 1][y] = 0;
				x--;
			}
			if (x == 0 && y == 0) {
				flag = false;
				break;
			}
		}
		//���� ��ȯ �� �̵� �Ÿ� ����
		if (direction == 0)	direction = 1;
		else if (direction == 1) {
			direction = 2;
			step++;
		}
		else if (direction == 2)	direction = 3;
		else {
			direction = 0;
			step++;
		}
	}

	cout << answer;
	//���� �Ҵ� ����
	for (int a = 0; a < N; a++) {
		delete[]map[a];
	}
	delete[]map;

	return 0;
}