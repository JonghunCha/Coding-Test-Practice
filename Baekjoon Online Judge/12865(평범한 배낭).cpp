/*
���� ��ũ : https://www.acmicpc.net/problem/12865
���̳��� ���α׷������� �ذ��� �� �ִ� ������.

N*K �迭�� ����� dp[a][b]�� 1������ a�������� ��ǰ�� ����ϸ� ���� ������ b�� �� ��ġ�� �ִ��� �����Ѵ�.
*/
#include <iostream>
using namespace std;

int N, K, W[101], V[101];
int dp[101][100001];

int Get_Answer(int N, int K);

int main(void) {
	//�Է°� ����
	cin >> N >> K;
	for (int a = 1; a <= N; a++)	cin >> W[a] >> V[a];
	//dp�迭 -1�� �ʱ�ȭ
	for (int a = 0; a <= 100; a++) {
		for (int b = 0; b <= 100000; b++) {
			dp[a][b] = -1;
		}
	}
	cout << Get_Answer(N, K);
	return 0;
}

int Get_Answer(int N, int K) {
	int val1, val2;
	//�̹� ���� ���̶�� �ٷ� ��ȯ
	if (dp[N][K] != -1)	return dp[N][K];
	//1�� ���Ǹ� ����ϴ� ��� ó��
	if (N == 1 && W[1] <= K) {
		dp[1][K] = V[1];
		return V[1];
	}
	else if (N == 1 && W[1] > K) {
		dp[1][K] = 0;
		return 0;
	}
	//�� ���� ���
	else {
		val1 = Get_Answer(N - 1, K);	//N�� ������ ������� �ʴ� ���
		if (W[N] <= K) {
			val2 = Get_Answer(N - 1, K - W[N]) + V[N];	//N�� ������ ����ϴ� ���
			//�� �� �� ū ���� ���Ѵ�
			if (val2 > val1) {
				dp[N][K] = val2;
				return val2;
			}
			else {
				dp[N][K] = val1;
				return val1;
			}
		}
		else {
			dp[N][K] = val1;
			return val1;
		}
	}
}