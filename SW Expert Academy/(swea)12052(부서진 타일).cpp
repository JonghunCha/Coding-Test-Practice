/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�ܼ��� ���� Ž�� ������.

Ÿ�� ��ü�� ���� ���Ǹ� �μ��� Ÿ���� �Ų� �� �ִٸ� ��� �Ų� ������.

���� �μ��� Ÿ���� ������ �ִµ� 2 * 2 Ÿ�Ϸ� �Ų��� ���Ѵٸ� ������ ���̽��̰� ��� �μ��� Ÿ�Ͽ� ���� 2 * 2 Ÿ�Ϸ� ���� �� �ִٸ� ������ ���̽��̴�.
*/
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int T, N, M;
	char board[50][50];
	bool possible;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &N, &M);
		getchar();
		for (int a = 0; a < N; a++) {
			scanf("%s", board[a]);
		}
		possible = true;

		for (int a = 0; a < N; a++) {
			for (int b = 0; b < M; b++) {
				if (board[a][b] == '#') {
					if (a + 1 < N && b + 1 < M && board[a + 1][b] == '#' && board[a][b + 1] == '#' && board[a + 1][b + 1] == '#') {
						board[a][b] = '.';
						board[a + 1][b] = '.';
						board[a][b + 1] = '.';
						board[a + 1][b + 1] = '.';
					}
					else {
						printf("#%d NO\n", test_case);
						possible = false;
						break;
					}
				}
			}
			if (!possible)	break;
		}

		if (possible)	printf("#%d YES\n", test_case);
		else	continue;
	}
	return 0;
}