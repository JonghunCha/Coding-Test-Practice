/*
���� ��ũ : https://www.acmicpc.net/problem/11066
DP�� �κ� ������ �ذ��� �� �ִ� ������.

��ȭ�� �κ��� ������ �Ʒ� �ڵ常 ���� ���� ������ �� ���� ���̴�.
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int memo[501][501], partial_sum[501][501], chapter[501];	//memo[a][b]�� a���� bé�͸� ��ġ�µ� ��� �ּ� �����, partial_sum[a][b]�� a���� bé�ͱ����� ���� ũ���� ���� ����

int DP(int start, int end);

int main(void) {
	int T, K, answer;

	scanf("%d", &T);
	for (int test_case = 0; test_case < T; test_case++) {
		//�Է°� ���� �� ���� �ʱ�ȭ
		scanf("%d", &K);
		memset(memo, -1, sizeof(int) * 501 * 501);
		memset(partial_sum, 0, sizeof(int) * 501 * 501);

		for (int a = 1; a <= K; a++)	scanf("%d", &chapter[a]);
		//�κ� �� ���
		for (int a = 1; a <= K; a++) {
			for (int b = a; b <= K; b++) {
				partial_sum[a][b] = partial_sum[a][b - 1] + chapter[b];
			}
		}
		//DPȣ��
		answer = DP(1, K);

		printf("%d\n", answer);
	}

	return 0;
}

int DP(int start, int end) {
	if (memo[start][end] != -1)	return memo[start][end];	//�̹� ���� ���̸� �ٷ� ��ȯ
	
	if (start == end) {	//start==end���� ó��
		memo[start][end] = 0;
	}
	else if (end == start + 1) {	//���� start�� end�� �̾��� �ִ� ��� �ּ� ����� ���� ��ġ�� ��
		memo[start][end] = chapter[start] + chapter[end];
	}
	else {	//start�� end���̿� a�������� ��� ��ġ�� ���� ���� ���� ���� ����
		int minval = 1000000000;
		for (int a = start; a < end; a++)	minval = min(minval, DP(start, a) + DP(a + 1, end) + partial_sum[start][end]);
		memo[start][end] = minval;
	}

	return memo[start][end];
}