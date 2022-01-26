/*
문제 링크 : https://swexpertacademy.com/main/main.do
어떠한 경우에 만들수 없는 패턴인지를 아는 것이 중요하다.

특정 지점의 길이가 h일 때, 해당 지점의 가로 행과 세로 열 모두에 h보다 큰 길이의 지역이 있다면 해당 패턴은 만들 수 없다. 이유는 아래와 같다.

h를 만들기 위해선 가로 혹은 세로로 제초기를 h로 설정하고 굴려야 한다.

이러한 경우 가로 혹은 세로 둘 중 한 줄은 h보다 높은 잔디가 있을 수 없다.

따라서 모든 지점에 대해 위의 조건에 해당하는 경우가 있는지 확인을 해주었다.
*/
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int T, N, M, garden[100][100];
	bool row, col, is_end;
	
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &N, &M);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < M; b++) {
				scanf("%d", &garden[a][b]);
			}
		}

		is_end = false;
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < M; b++) {
				row = true;
				col = true;
				//가로 줄에 더 큰 높이의 잔디가 있다면 row를 false로 설정
				for (int c = 0; c < M; c++) {
					if (garden[a][c] > garden[a][b]) {
						row = false;
						break;
					}
				}
				//세로 줄에 더 큰 높이의 잔디가 있다면 col를 false로 설정
				for (int c = 0; c < N; c++) {
					if (garden[c][b] > garden[a][b]) {
						col = false;
						break;
					}
				}
				//가로와 세로 모두에 더 높은 잔디가 있다면 만들 수 없는 패턴
				if (!row && !col) {
					is_end = true;
					break;
				}
			}
			if (is_end)	break;
		}

		if (is_end)	printf("#%d NO\n", test_case);
		else	printf("#%d YES\n", test_case);
	}
	return 0;
}