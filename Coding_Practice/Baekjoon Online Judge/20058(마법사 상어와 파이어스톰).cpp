/*
���� ��ũ : https://www.acmicpc.net/problem/20058
�ܼ� ���� ������.

�����ؾ� �� ����� �Ʒ��� ����.

1. �迭�� ȸ�� ��Ű�� �Լ�
2. ������ �ִ� ������ ĭ�� 3�� �̸��� ��� ������ ���� ���̴� �Լ�
3. ������ ����� ĭ�� ����(���������� ����� Ī��)�� ���ϴ� �Լ�
*/
#include <iostream>
using namespace std;

int ccount = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int Get_Width(int N);
void Rotate(int board[64][64], int x, int y, int length);
void Update_Ice(int board[64][64], int width);
int Make_Neighbor(int board[64][64], int width);
void Search_Neighbor(int board[64][64], int width, int x, int y, int index);

int main(void) {
	int N, Q, board[64][64], L[1000], width, width_part, answer1 = 0, answer2 = 0, neighbor_num, temp;
	//�Է°� ����
	cin >> N; cin >> Q;
	width = Get_Width(N);
	for (int a = 0; a < width; a++) {
		for (int b = 0; b < width; b++) {
			cin >> board[a][b];
		}
	}
	for (int a = 0; a < Q; a++) {
		cin >> L[a];
	}
	//Q������ ���̾�� ����
	for (int a = 0; a < Q; a++) {
		width_part = Get_Width(L[a]);
		//�� �κ� ���ڵ��� ȸ����Ų��
		for (int b = 0; b < width; b += width_part) {
			for (int c = 0; c < width; c += width_part) {
				for (int d = 0; d < Get_Width(L[a] - 1); d++) {
					Rotate(board, b + d, c + d, Get_Width(L[a]) - 2 * d);
				}
			}
		}
		//������ ���� �پ���� �ϴ� �κ� ����
		Update_Ice(board, width);
	}
	//��ü ������ �� ���
	for (int a = 0; a < width; a++) {
		for (int b = 0; b < width; b++) {
			answer1 += board[a][b];
		}
	}
	//board�� ���� ����� ������
	neighbor_num = Make_Neighbor(board, width);
	for (int a = 1; a <= neighbor_num; a++) {
		temp = 0;
		for (int b = 0; b < width; b++) {
			for (int c = 0; c < width; c++) {
				if (board[b][c] == a + 100)	temp++;
			}
		}
		if (temp > answer2)	answer2 = temp;
	}
	cout << answer1 << endl << answer2 << endl;

	return 0;
}
//2�� N���� ��ȯ�ϴ� �Լ�
int Get_Width(int N) {
	if (N < 0)	return -1;
	int ret = 1;
	for (int a = 0; a < N; a++) {
		ret = ret * 2;
	}
	return ret;
}
//�������� ȸ����Ű�� �Լ�
void Rotate(int board[64][64], int x, int y, int length) {
	int temp[4][64];
	for (int a = 0; a < length - 1; a++) {
		temp[0][a] = board[x][y + a];
		temp[1][a] = board[x + a][y + length - 1];
		temp[2][a] = board[x + length - 1][y + length - 1 - a];
		temp[3][a] = board[x + length - 1 - a][y];
	}
	for (int a = 0; a < length - 1; a++) {
		board[x + a][y + length - 1] = temp[0][a];
		board[x + length - 1][y + length - 1 - a] = temp[1][a];
		board[x + length - 1 - a][y] = temp[2][a];
		board[x][y + a] = temp[3][a];
	}
}
//������ ���� ���̴� �Լ�
void Update_Ice(int board[64][64], int width) {
	int count_near, nx, ny, new_board[64][64];
	for (int a = 0; a < width; a++) {
		for (int b = 0; b < width; b++) {
			if (board[a][b] > 0) {
				count_near = 0;
				for (int c = 0; c < 4; c++) {
					nx = a + dx[c];
					ny = b + dy[c];
					if (nx >= 0 && nx < width && ny >= 0 && ny < width && board[nx][ny] > 0)	count_near++;
				}
				if (count_near >= 3)	new_board[a][b] = board[a][b];
				else	new_board[a][b] = board[a][b] - 1;
			}
			else	new_board[a][b] = board[a][b];
		}
	}
	for (int a = 0; a < width; a++) {
		for (int b = 0; b < width; b++) {
			board[a][b] = new_board[a][b];
		}
	}
}
//�����ǿ��� ���� ����� ������ ������ ���ϴ� �Լ�
int Make_Neighbor(int board[64][64], int width) {
	int neighbor_num = 0;

	for (int a = 0; a < width; a++) {
		for (int b = 0; b < width; b++) {
			if (board[a][b] > 0 && board[a][b] <= 100) {
				neighbor_num++;
				board[a][b] = 100 + neighbor_num;
				Search_Neighbor(board, width, a, b, neighbor_num);
			}
		}
	}
	return neighbor_num;
}
//x, y�� index��ȣ�� �ش��ϴ� ������ ��� �׿� ������ 4������ ĭ Ȯ��
void Search_Neighbor(int board[64][64], int width, int x, int y, int index) {
	int nx, ny;
	for (int a = 0; a < 4; a++) {
		nx = x + dx[a];
		ny = y + dy[a];
		if (nx >= 0 && nx < width && ny >= 0 && ny < width && board[nx][ny] > 0 && board[nx][ny] <= 100) {
			board[nx][ny] = 100 + index;
			Search_Neighbor(board, width, nx, ny, index);
		}
	}
}