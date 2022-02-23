/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�κ������� �ذ��ؾ� �ϴ� ������.

��� ������ ���� ������ ǰ���� �ľ��ϱ⿣ �ð��� �ʹ� ���� �ɸ���.

�Ʒ� �ڵ带 ���� �κ����� ���� ���� �ذ��� �� ������ �� �� �ִ�.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int sum[100001][4];

int main(int argc, char** argv)
{
	int T, N, Q, input, L, R;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ���� �ʱ�ȭ
		scanf("%d %d", &N, &Q);
		memset(sum, 0, sizeof(int) * 100001 * 4);
		//�κ����� ��� sum[a][1]�� a��° �ε������� ���� 1�� ǰ���� ���� �ǹ�
		for (int a = 1; a <= N; a++) {
			scanf("%d", &input);
			sum[a][1] = sum[a - 1][1];
			sum[a][2] = sum[a - 1][2];
			sum[a][3] = sum[a - 1][3];
			if (input == 1)	sum[a][1]++;
			else if (input == 2)	sum[a][2]++;
			else	sum[a][3]++;
		}
		//�κ����� �̿��� ���� ���
		printf("#%d\n", test_case);
		for (int a = 1; a <= Q; a++) {
			scanf("%d %d", &L, &R);
			printf("%d %d %d\n", sum[R][1] - sum[L - 1][1], sum[R][2] - sum[L - 1][2], sum[R][3] - sum[L - 1][3]);
		}
	}
	return 0;
}