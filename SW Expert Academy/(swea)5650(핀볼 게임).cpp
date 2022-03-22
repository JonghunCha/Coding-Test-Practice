/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�ܼ� ���� ������.

������ �־��� ���Ǵ�� ������ �ϸ� ���� �ذ��� �� �ִ� �����̴�.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };	//��, �� , ��, ��
int dy[4] = { 0, 1, 0, -1 };
int wormhole[5][4];

int get_score(int N, int x, int y, int direction, int board[100][100]);

int main(int argc, char** argv)
{
	int T, N, board[100][100], max_score, score, idx;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ���� �ʱ�ȭ
		scanf("%d", &N);
		memset(wormhole, -1, sizeof(int) * 20);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				scanf("%d", &board[a][b]);
				if (board[a][b] >= 6 && board[a][b] <= 10) {
					idx = board[a][b] - 6;
					if (wormhole[idx][0] > -1) {
						wormhole[idx][2] = a;
						wormhole[idx][3] = b;
					}
					else {
						wormhole[idx][0] = a;
						wormhole[idx][1] = b;
					}
				}
			}
		}
		//������ ��� ��쿡 ���� �ùķ��̼�
		max_score = 0;
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (board[a][b] == 0) {
					for (int c = 0; c < 4; c++) {
						score = get_score(N, a, b, c, board);
						if (max_score < score)	max_score = score;
					}
				}
			}
		}

		printf("#%d %d\n", test_case, max_score);
	}
	return 0;
}

int get_score(int N, int x, int y, int direction, int board[100][100]) {
	int nx = x, ny = y, score = 0, idx;
	while (1) {
		nx = nx + dx[direction];
		ny = ny + dy[direction];

		if (nx == x && ny == y) {	//������ġ�� �� ���
			return score;
		}
		else if (nx < 0 || nx >= N || ny < 0 || ny >= N) {	//���� �΋H�� ���
			score++;
			direction = (direction + 2) % 4;
		}
		else if (board[nx][ny] == -1) {	//��Ȧ
			return score;
		}
		else if (board[nx][ny] >= 6 && board[nx][ny] <= 10) {	//��Ȧ
			idx = board[nx][ny] - 6;

			if (wormhole[idx][0] == nx && wormhole[idx][1] == ny) {
				nx = wormhole[idx][2];
				ny = wormhole[idx][3];
			}
			else {
				nx = wormhole[idx][0];
				ny = wormhole[idx][1];
			}
		}
		else if (board[nx][ny] == 1) {	//1�� ���
			score++;
			switch (direction) {
			case 0:
				direction = 2;
				break;
			case 1:
				direction = 3;
				break;
			case 2:
				direction = 1;
				break;
			case 3:
				direction = 0;
				break;
			}
		}
		else if (board[nx][ny] == 2) {	//2�� ���
			score++;
			switch (direction) {
			case 0:
				direction = 1;
				break;
			case 1:
				direction = 3;
				break;
			case 2:
				direction = 0;
				break;
			case 3:
				direction = 2;
				break;
			}
		}
		else if (board[nx][ny] == 3) {	//3�� ���
			score++;
			switch (direction) {
			case 0:
				direction = 3;
				break;
			case 1:
				direction = 2;
				break;
			case 2:
				direction = 0;
				break;
			case 3:
				direction = 1;
				break;
			}
		}
		else if (board[nx][ny] == 4) {	//4�� ���
			score++;
			switch (direction) {
			case 0:
				direction = 2;
				break;
			case 1:
				direction = 0;
				break;
			case 2:
				direction = 3;
				break;
			case 3:
				direction = 1;
				break;
			}
		}
		else if (board[nx][ny] == 5) {	//5�� ���
			score++;
			direction = (direction + 2) % 4;
		}
	}
}