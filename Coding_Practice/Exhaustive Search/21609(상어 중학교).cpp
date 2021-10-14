/*
���� ��ũ : https://www.acmicpc.net/problem/21609
�������� ������ ��Ȳ�� �� ������ �� �ִ��� ���� ������.

��κ� �ܼ� ���� �κ������� ���� ū ��� �׷��� ã�� �κ��� ���� Ž���� ���� ���ؾ��Ѵ�.

��� �׷쿡�� �Ϲ� ����� ��� �ϳ� �־�� �Ѵ�.

��, ��� �׷��� ���� ����� �Ϲ� ����� ���� ��ȣ�� ���� ���� ���, �׷��� ����� �������� ���� ��ȣ�� ���� ���� ����̶� �Ѵ�.

���� ���� ū ��� �׷��� ã�� ���ؼ� �Ϲ� ����� ��ġ�� ���� ���������� ��� ������ ���⿡ ���� ���� �Ϲ� ��� Ȥ�� ������ ����� �ִ��� Ȯ���� ������ �ȴ�.

���� ū ��ϸ� ã�� ���� ������ �κ��� �����ϰ� �ذ��� �� �ִ�.
*/
#include <iostream>
using namespace std;

int block_num, rainbow_num, block_x, block_y;	//���� ū ��� �׷��� ������ ��� ����
int temp_block_num, temp_rainbow_num, temp_block_x, temp_block_y;	//���� Ž������ ��� �׷��� ������ ��� ����
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void Search_Largest_Group(int N, int board[20][20], int group[20][20]);
void Search_Near(int N, int board[20][20], int x, int y, int group[20][20], int group_color);

int main(void) {
	int N, M, board[20][20], group[20][20], answer = 0, group_num, gravity_index;
	int board_for_rotate[20][20];
	//�Է°� ����
	cin >> N; cin >> M;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			cin >> board[a][b];
		}
	}

	while (1) {
		Search_Largest_Group(N, board, group);
		if (block_x == -1)	break;	//��� �׷��� ���ٸ� ����
		//1�ܰ�(���� ū ��� ����)
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				group[a][b] = 0;
			}
		}
		Search_Near(N, board, block_x, block_y, group, board[block_x][block_y]);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (group[a][b] == 1)	board[a][b] = 9;	//�� ĭ�� 9�� ǥ���Ͽ���
			}
		}
		//2�ܰ�(������ ������κ��� ���� ȹ��)
		answer += block_num * block_num;
		//3�ܰ�(�߷� �ۿ�)
		for (int a = 0; a < N; a++) {
			gravity_index = N - 1;
			for (int b = N - 1; b >= 0; b--) {
				if (board[b][a] == -1)	gravity_index = b - 1;
				else if (board[b][a] >= 0 && board[b][a] < 9 && b == gravity_index)	gravity_index = b - 1;
				else if (board[b][a] >= 0 && board[b][a] < 9 && b != gravity_index) {
					board[gravity_index][a] = board[b][a];
					board[b][a] = 9;
					gravity_index--;
				}
			}
		}
		//4�ܰ�(90�� �ݽð� ȸ��)
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				board_for_rotate[a][b] = board[b][N - a - 1];
			}
		}
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				board[a][b] = board_for_rotate[a][b];
			}
		}
		//5�ܰ�(�߷� �ۿ�)
		for (int a = 0; a < N; a++) {
			gravity_index = N - 1;
			for (int b = N - 1; b >= 0; b--) {
				if (board[b][a] == -1)	gravity_index = b - 1;
				else if (board[b][a] >= 0 && board[b][a] < 9 && b == gravity_index)	gravity_index = b - 1;
				else if (board[b][a] >= 0 && board[b][a] < 9 && b != gravity_index) {
					board[gravity_index][a] = board[b][a];
					board[b][a] = 9;
					gravity_index--;
				}
			}
		}
	}
	cout << answer;

	return 0;
}
//���� ū ��� �׷��� ã�� �Լ�
void Search_Largest_Group(int N, int board[20][20], int group[20][20]) {
	block_num = 0;
	rainbow_num = 0;
	block_x = -1;
	block_y = -1;
	bool is_search_complete;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			//�Ϲ� ����� �����ϴ� ��� �ش� ����� �������� �׷��� Ž��
			if (board[a][b] > 0 && board[a][b] < 9) {
				temp_block_num = 0;
				temp_rainbow_num = 0;
				temp_block_x = 30;
				temp_block_y = 30;
				for (int c = 0; c < N; c++) {
					for (int d = 0; d < N; d++) {
						group[c][d] = 0;
					}
				}
				Search_Near(N, board, a, b, group, board[a][b]);
				is_search_complete = false;
				//�׷��� �����Ǿ��ٸ� �ش� �׷��� ���� ����� ��ǥ�� ã�Ƴ���
				for (int c = 0; c < N; c++) {
					for (int d = 0; d < N; d++) {
						if (group[c][d] == 1 && board[c][d] != 0) {
							temp_block_x = c;
							temp_block_y = d;
							is_search_complete = true;
							break;
						}
					}
					if (is_search_complete)	break;
				}
				//���� ū ��� �׷��� ���ǿ� ���� ����
				if ((temp_block_num > 1 && temp_block_num > block_num)
					|| (temp_block_num == block_num && temp_rainbow_num > rainbow_num)
					|| (temp_block_num == block_num && temp_rainbow_num == rainbow_num && temp_block_x > block_x)
					|| (temp_block_num == block_num && temp_rainbow_num == rainbow_num && temp_block_x == block_x && temp_block_y > block_y)) {
					block_num = temp_block_num;
					rainbow_num = temp_rainbow_num;
					block_x = temp_block_x;
					block_y = temp_block_y;
				}
			}
		}
	}
}
//x, y��ǥ�� ������ ����� Ȯ���ϰ� ���� �׷��̸� Ȯ���� ������ �Լ�
void Search_Near(int N, int board[20][20], int x, int y, int group[20][20], int group_color) {
	int nx, ny;
	if (board[x][y] == 0) {
		temp_rainbow_num++;
	}
	group[x][y] = 1;
	temp_block_num++;
	for (int a = 0; a < 4; a++) {
		nx = x + dx[a];
		ny = y + dy[a];
		//������ 4���� �� ���� �׷쿡 ������ �ʾ����� �Ϲ� ��� Ȥ�� ������ ����� �͵��� �׷쿡 �߰�
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && group[nx][ny] == 0 && (board[nx][ny] == 0 || board[nx][ny] == group_color)) {
			Search_Near(N, board, nx, ny, group, group_color);
		}
	}
}