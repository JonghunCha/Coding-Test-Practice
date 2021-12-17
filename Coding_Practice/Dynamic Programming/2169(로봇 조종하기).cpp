/*
���� ��ũ : https://www.acmicpc.net/problem/2169
dp�� �ذ��� �� �ִ� ������.

�κ��� �� ���� ���������θ� �̵��� �� �ִ�.

���� dp�� ������ ���� ���, ���ʿ��� ���� ���, �����ʿ��� ���� ��쿡�� ���� ū ���� �����ϵ��� �����ϸ� �ȴ�.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int board[1001][1001], dp[1001][1001], left[1001], right[1001];

int main(void) {
	int N, M, temp;
	//�Է°� ���� �� ���� �ʱ�ȭ
	scanf("%d %d", &N, &M);
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= M; b++) {
			scanf("%d", &board[a][b]);
			dp[a][b] = -1;
		}
	}
	//���� ������ �̵������� �����ʹۿ� �ȵǱ⿡ dp���� �ٷ� ���
	temp = 0;
	for (int a = 1; a <= M; a++) {
		temp += board[1][a];
		dp[1][a] = temp;
	}
	//�� ��° �ٺ��� dp���� �ϳ��� ���
	for (int a = 2; a <= N; a++) {
		for (int b = 1; b <= M; b++) {	//left�� right���� ������ �Ʒ��� �̵��� ����� ��ġ�� �ʱⰪ���� ������
			left[b] = dp[a - 1][b] + board[a][b];
			right[b] = left[b];
		}
		for (int b = 2; b <= M; b++) {	//���������� �̵��ϴ� ���
			if (left[b] < left[b - 1] + board[a][b])	left[b] = left[b - 1] + board[a][b];	//������ �� ��캸�� ���ʿ��� ���� �� ��ġ�� �� ū ��� �� ����
		}
		for (int b = M - 1; b >= 1; b--) {	//�������� �̵��ϴ� ���
			if (right[b] < right[b + 1] + board[a][b])	right[b] = right[b + 1] + board[a][b];	//������ �� ��캸�� �����ʿ��� ���� �� ��ġ�� �� ū ��� �� ����
		}
		for (int b = 1; b <= M; b++) {	//���ʿ��� �� ���, �����ʿ��� �� ��� �� �� ���� ��ġ�� ����
			dp[a][b] = max(left[b], right[b]);
		}
	}

	printf("%d\n", dp[N][M]);

	return 0;
}