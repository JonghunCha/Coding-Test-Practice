/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���� Ž������ �ذ��� �� �ִ� ������.

������ ���ǿ� ������ ��� ����� �ִ� ũ��� 350 * 350�� ���� �ʴ´�.

���� �����ְ� 400 * 400 * 2 ũ���� �迭�� �����Ͽ���.(�������� 0�� �ε������� �������, 1�� �ε������� �ش� ������ ������ �ñ⸦ ����)

������ ���ǿ� ���� K�ð� ���� Ȱ�� ������ �ٱ� ������ ��ó�� ����� �� �������� ����ִ� �ٱ� ������ ���� ���ϸ� �ȴ�.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[400][400][2];

int main(void) {
	int T, N, M, K, answer, nx, ny;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		//�Է°� ���� �� ���� �ʱ�ȭ
		scanf("%d %d %d", &N, &M, &K);
		memset(board, 0, sizeof(int) * 320000);
		for (int a = 175; a < 175 + N; a++) {
			for (int b = 175; b < 175 + M; b++) {
				scanf("%d", &board[a][b][0]);
			}
		}
		
		for (int a = 1; a <= K; a++) {
			for (int x = 1; x <= 398; x++) {
				for (int y = 1; y <= 398; y++) {
					//x, y��° �ٱ� ������ Ȱ�� ������ ��� �ֺ��� ���
					if (board[x][y][0] > 0 && a > board[x][y][0] + board[x][y][1] && a <= board[x][y][1] + 2 * board[x][y][0]) {
						for (int d = 0; d < 4; d++) {
							nx = x + dx[d];
							ny = y + dy[d];
							if (board[nx][ny][0] == 0) {
								board[nx][ny][0] = board[x][y][0];
								board[nx][ny][1] = a;
							}
							else if (board[nx][ny][1] == a) {	//�� �� �̻��� �ٱ� ������ �ϳ��� ���� ���� �����Ϸ��� ���� ����� ��ġ�� ���� ������ �����ϰ� �Ѵ�
								if (board[x][y][0] > board[nx][ny][0])	board[nx][ny][0] = board[x][y][0];
							}
						}
					}
				}
			}
		}
		//Ȱ��, ��Ȱ�� ������ ���� ���� ���
		answer = 0;
		for (int a = 0; a < 400; a++) {
			for (int b = 0; b < 400; b++) {
				if (board[a][b][0] > 0 && board[a][b][1] + 2 * board[a][b][0] > K)	answer++;
			}
		}

		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}