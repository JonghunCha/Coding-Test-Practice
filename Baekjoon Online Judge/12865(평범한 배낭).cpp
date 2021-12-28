/*
문제 링크 : https://www.acmicpc.net/problem/12865
다이나믹 프로그래밍으로 해결할 수 있는 문제다.

N*K 배열을 만들고 dp[a][b]는 1번부터 a번까지의 물품을 사용하며 무게 제한이 b일 때 가치의 최댓값을 저장한다.
*/
#include <iostream>
using namespace std;

int N, K, W[101], V[101];
int dp[101][100001];

int Get_Answer(int N, int K);

int main(void) {
	//입력값 저장
	cin >> N >> K;
	for (int a = 1; a <= N; a++)	cin >> W[a] >> V[a];
	//dp배열 -1로 초기화
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
	//이미 구한 값이라면 바로 반환
	if (dp[N][K] != -1)	return dp[N][K];
	//1번 물건만 사용하는 경우 처리
	if (N == 1 && W[1] <= K) {
		dp[1][K] = V[1];
		return V[1];
	}
	else if (N == 1 && W[1] > K) {
		dp[1][K] = 0;
		return 0;
	}
	//그 외의 경우
	else {
		val1 = Get_Answer(N - 1, K);	//N번 물건을 사용하지 않는 경우
		if (W[N] <= K) {
			val2 = Get_Answer(N - 1, K - W[N]) + V[N];	//N번 물건을 사용하는 경우
			//둘 중 더 큰 값을 취한다
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