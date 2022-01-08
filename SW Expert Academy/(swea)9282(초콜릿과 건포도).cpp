/*
���� ��ũ : https://swexpertacademy.com/main/main.do
DP�� �ذ��� �� �ִ� ������. �׷��� DP�� ����Ͽ��� ���� �ð� �ʰ��� ���� �������� ���� �Ϻ� �������� ����ȭ�Ͽ� ����Ͽ���.

�켱 �������� ��ġ�� ������ �ִ� ���� �ƴϱ⿡ ������ ��� ��츦 �˾Ƴ��� �Ѵ�.

�� ��� �ߺ��� ����� ���� ����µ� �̸� DP�� �ذ��Ͽ���.
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[50][50][50][50], prefix_sum[50][50];	//dp�� ���̳��� ���α׷����� ����, prefix_sum�� �������� ���� ����

int DP(int chocolate[50][50], int x1, int y1, int x2, int y2);

int main(int argc, char** argv)
{
	int T, N, M, chocolate[50][50], temp, answer;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ����
		scanf("%d %d", &N, &M);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < M; b++) {
				scanf("%d", &chocolate[a][b]);
			}
		}
		//������ ���
		for (int a = 0; a < N; a++) {
			temp = 0;
			for (int b = 0; b < M; b++) {
				temp += chocolate[a][b];
				prefix_sum[a][b] = temp;
			}
		}
		//dp �ʱ�ȭ
		memset(dp, -1, sizeof(dp));
		//DP�Լ� ȣ��
		answer = DP(chocolate, 0, 0, N - 1, M - 1);
		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}
//x1, y1�� DP���� ���Ϸ��� ���簢���� ���� ���� ��ǥ, x2, y2�� ������ �Ʒ� ��ǥ�� �ǹ�
int DP(int chocolate[50][50], int x1, int y1, int x2, int y2) {
	if (dp[x1][y1][x2][y2] != -1)	return dp[x1][y1][x2][y2];
	//���� 1*1�� �����̸� �ڸ� �ʿ䰡 ���⿡ 0 ��ȯ
	if (x1 == x2 && y1 == y2) {
		dp[x1][y1][x2][y2] = 0;
		return 0;
	}

	int ret = 999999999, temp, basic = 0;
	//�������� ���ؼ� ���� ���簢���� �ڸ� �� ��� ��� ���
	for (int a = x1; a <= x2; a++) {
		if (y1 == 0)	basic += prefix_sum[a][y2];
		else	basic += prefix_sum[a][y2] - prefix_sum[a][y1 - 1];
	}
	//��� �߶�� ���� �ּ� ����� ����� DP ��͸� ���� ���
	for (int a = x1 + 1; a <= x2; a++) {
		ret = min(ret, DP(chocolate, x1, y1, a - 1, y2) + DP(chocolate, a, y1, x2, y2) + basic);
	}
	for (int a = y1 + 1; a <= y2; a++) {
		ret = min(ret, DP(chocolate, x1, y1, x2, a - 1) + DP(chocolate, x1, a, x2, y2) + basic);
	}

	dp[x1][y1][x2][y2] = ret;
	return ret;
}