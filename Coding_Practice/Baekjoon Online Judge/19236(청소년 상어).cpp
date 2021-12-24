/*
���� ��ũ : https://www.acmicpc.net/problem/19236
���� Ž������ �ذ��� �� �ִ� ������.

������ ũ�� 2��Ʈ�� ������.

1. ���� ������⿡ �ִ� ����� �� �ϳ��� ��Ƹ԰� ������ ���� ������� �������� �ٲ۴�.
2. ��ü ����⸦ �̵��Ѵ�.

1~2�� ������ �ݺ��ϴ� �� �� �̻� ����⸦ ������ �� �����ϸ� �ȴ�. 
*/
#include <iostream>
using namespace std;

int answer = 0;

int dx[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

void Move_Shark(int map[4][4], int target_x, int target_y, int score, int fish[17][3]);
void Move_Fish(int map[4][4], int fish_num, int fish[17][3]);

int main(void) {
	int map[4][4], direction, fish[17][3];	//fish�� �� �ε����� ���� ������� ��ǥ��ġ�� ������ �����Ѵ�.(���ܷ� 0�� �ε����� ����� ��ġ�� ���� �ǹ�)
	//�Է°� ����
	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 4; b++) {
			cin >> map[a][b];
			cin >> direction;
			fish[map[a][b]][0] = a;
			fish[map[a][b]][1] = b;
			fish[map[a][b]][2] = direction;
		}
	}
	//����� ��ġ ���� �� ��� �̵� ����
	fish[0][0] = 0;
	fish[0][1] = 0;
	Move_Shark(map, 0, 0, 0, fish);
	cout << answer;

	return 0;
}

void Move_Shark(int map[4][4], int target_x, int target_y, int score, int fish[17][3]) {
	int x = fish[0][0], y = fish[0][1], nx, ny, nd, map_backup[4][4], fish_backup[17][3];
	bool is_end = true;	//�� �� �̻� ��Ƹ��� ����Ⱑ �ִ��� �������� �ǹ�
	//Ÿ�ٿ� �ش��ϴ� ����� �԰� ���� �ø�
	int nscore = score + map[target_x][target_y];
	//Ÿ���� ��ġ�� �� �ű�� ���⵵ ���� + ��� ���� ����⸦ map���� ���ش�
	fish[map[target_x][target_y]][0] = -1;
	fish[map[target_x][target_y]][1] = -1;
	fish[0][0] = target_x;
	fish[0][1] = target_y;
	fish[0][2] = fish[map[target_x][target_y]][2];
	map[x][y] = -1;
	map[target_x][target_y] = 0;
	//����� �̵� �ǽ�
	for (int a = 1; a <= 16; a++) {
		if (fish[a][0] != -1)	Move_Fish(map, a, fish);
	}
	//map�� fish���� ���
	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 4; b++) {
			map_backup[a][b] = map[a][b];
		}
	}
	for (int a = 0; a < 17; a++) {
		for (int b = 0; b < 3; b++) {
			fish_backup[a][b] = fish[a][b];
		}
	}
	//�� �������� ��Ƹ��� ����� �ĺ� Ž��
	nd = fish[0][2];
	//4*4map�̱⿡ ����� �̵� �Ÿ��� �ִ� 3
	for (int a = 1; a <= 3; a++) {
		nx = fish[0][0] + a * dx[nd];
		ny = fish[0][1] + a * dy[nd];
		//��� ���� ����Ⱑ �ִ� ��� �ش� ����⸦ Ÿ������ �Ͽ� Move_Sharkȣ��
		if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && map[nx][ny] > 0) {
			Move_Shark(map, nx, ny, nscore, fish);
			//map�� fish�� ������� �̿��Ͽ� �ٸ� ����� �ĺ��� ���� Move_Sharkȣ�� �غ�
			for (int b = 0; b < 4; b++) {
				for (int c = 0; c < 4; c++) {
					map[b][c] = map_backup[b][c];
				}
			}
			for (int b = 0; b < 17; b++) {
				for (int c = 0; c < 3; c++) {
					fish[b][c] = fish_backup[b][c];
				}
			}
			//����⸦ ��ƸԾ��ٴ� ���� �̹� �Լ����� ���������� �������� �ʾҴٴ� �ǹ�
			is_end = false;
		}
	}
	//���������� �����ϸ� ���� �ִ밪 ����
	if (is_end && nscore > answer)	answer = nscore;
}

void Move_Fish(int map[4][4], int fish_num, int fish[17][3]) {
	int nx, ny, nd = fish[fish_num][2], temp_fish_num, temp_x, temp_y;
	//�ݽð� �������� ���� ȸ��
	for (int a = 0; a < 8; a++) {
		nx = fish[fish_num][0] + dx[nd];
		ny = fish[fish_num][1] + dy[nd];
		//����Ⱑ �̵��Ϸ��� ���� �ٸ� ����Ⱑ �ִ� ���
		if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && map[nx][ny] > 0) {
			temp_fish_num = map[nx][ny];
			temp_x = fish[fish_num][0];
			temp_y = fish[fish_num][1];
			map[nx][ny] = fish_num;
			fish[fish_num][0] = nx;
			fish[fish_num][1] = ny;
			fish[fish_num][2] = nd;
			map[temp_x][temp_y] = temp_fish_num;
			fish[temp_fish_num][0] = temp_x;
			fish[temp_fish_num][1] = temp_y;
			return;
		}
		//����Ⱑ �̵��Ϸ��� ���� �� ������ ���
		else if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && map[nx][ny] == -1) {
			temp_x = fish[fish_num][0];
			temp_y = fish[fish_num][1];
			map[nx][ny] = fish_num;
			fish[fish_num][0] = nx;
			fish[fish_num][1] = ny;
			fish[fish_num][2] = nd;
			map[temp_x][temp_y] = -1;
			return;
		}
		//���� ȸ��
		if (nd == 8)	nd = 1;
		else	nd++;
	}
}