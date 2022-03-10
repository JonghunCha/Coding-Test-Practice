/*
문제 링크 : https://swexpertacademy.com/main/main.do
단순한 완전 탐색 문제다.

타일 전체에 대해 살피며 부서진 타일을 매꿀 수 있다면 계속 매꿔 나간다.

만약 부서진 타일인 지점이 있는데 2 * 2 타일로 매꾸지 못한다면 실패한 케이스이고 모든 부서진 타일에 대해 2 * 2 타일로 덮을 수 있다면 성공한 케이스이다.
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