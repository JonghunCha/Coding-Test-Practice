/*
���� ��ũ : https://swexpertacademy.com/main/main.do
��� ��쿡 ����� ���� ���������� �ƴ� ���� �߿��ϴ�.

Ư�� ������ ���̰� h�� ��, �ش� ������ ���� ��� ���� �� ��ο� h���� ū ������ ������ �ִٸ� �ش� ������ ���� �� ����. ������ �Ʒ��� ����.

h�� ����� ���ؼ� ���� Ȥ�� ���η� ���ʱ⸦ h�� �����ϰ� ������ �Ѵ�.

�̷��� ��� ���� Ȥ�� ���� �� �� �� ���� h���� ���� �ܵ� ���� �� ����.

���� ��� ������ ���� ���� ���ǿ� �ش��ϴ� ��찡 �ִ��� Ȯ���� ���־���.
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
				//���� �ٿ� �� ū ������ �ܵ� �ִٸ� row�� false�� ����
				for (int c = 0; c < M; c++) {
					if (garden[a][c] > garden[a][b]) {
						row = false;
						break;
					}
				}
				//���� �ٿ� �� ū ������ �ܵ� �ִٸ� col�� false�� ����
				for (int c = 0; c < N; c++) {
					if (garden[c][b] > garden[a][b]) {
						col = false;
						break;
					}
				}
				//���ο� ���� ��ο� �� ���� �ܵ� �ִٸ� ���� �� ���� ����
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