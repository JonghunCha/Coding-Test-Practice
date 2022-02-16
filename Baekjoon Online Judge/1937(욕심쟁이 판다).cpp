/*
���� ��ũ : https://www.acmicpc.net/problem/1937
DP�� �ذ��� �� �ִ� ������.

dp[a][b]�� �Ǵٰ� a�� b���� ���� �Ҷ����� ������ ������ �ִ� ���� �����Ѵ�.

��ȭ���� ������ ������ �Ʒ� �ڵ常 ���� ���� ������ �� ���� ���̴�.
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, forest[500][500], dp[500][500];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int DP(int x, int y);

int main(void) {
	int temp, answer = 0;
	//�Է°� ���� �� ���� �ʱ�ȭ
	scanf("%d", &N);
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			scanf("%d", &forest[a][b]);
		}
	}
	memset(dp, -1, sizeof(int) * 500 * 500);
	//��� ������ dp�� ����ϰ� �ִ��� ����
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			temp = DP(a, b);
			if (temp > answer)	answer = temp;
		}
	}

	printf("%d\n", answer);

	return 0;
}

int DP(int x, int y) {
	if (dp[x][y] != -1)	return dp[x][y];	//�̹� ���� �����̸� �ٷ� ��ȯ

	int ret = 1, nx, ny, temp;
	//������ 4������ ������ ���� ��ȿ�� �����̸� �ش� ������ �볪�� ���� x, y���� �۴ٸ� �ش� �������κ��� ���� x, y�� �̵��� ������
	for (int a = 0; a < 4; a++) {
		nx = x + dx[a];
		ny = y + dy[a];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && forest[nx][ny] < forest[x][y]) {
			temp = DP(nx, ny) + 1;
			if (temp > ret)	ret = temp;
		}
	}

	dp[x][y] = ret;
	return ret;
}