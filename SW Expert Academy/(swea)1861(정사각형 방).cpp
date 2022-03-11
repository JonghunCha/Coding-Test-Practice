/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�ܼ��� ����Ž�� ������.

��� ������ ������������ ��� �������� ���ϴ� ���� ã���� ���� Ž���ϸ� �ȴ�.

���� ������ ������ ������ ���� �ʰڴ�.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int room[1000][1000];

int main(int argc, char** argv)
{
	int T, N, answer1, answer2, count, x, y, nx, ny;
	bool can_move;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ����
		scanf("%d", &N);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				scanf("%d", &room[a][b]);
			}
		}

		answer1 = 1000000;
		answer2 = 0;
		//��� ������ ���������� ��� ������ ����
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				x = a;
				y = b;
				count = 1;
				can_move = false;

				while (1) {
					can_move = false;
					for (int c = 0; c < 4; c++) {
						nx = x + dx[c];
						ny = y + dy[c];
						if (nx >= 0 && nx < N && ny >= 0 && ny < N && room[nx][ny] == room[x][y] + 1) {
							x = nx;
							y = ny;
							count++;
							can_move = true;
							break;
						}
					}

					if (!can_move) {
						if (answer2 < count) {
							answer1 = room[a][b];
							answer2 = count;
						}
						else if (answer2 == count)	answer1 = min(answer1, room[a][b]);
						break;
					}
				}
			}
		}

		printf("#%d %d %d\n", test_case, answer1, answer2);
	}
	return 0;
}