/*
문제 링크 : https://www.acmicpc.net/problem/11066
DP와 부분 합으로 해결할 수 있는 문제다.

점화식 부분은 쉬워서 아래 코드만 봐도 쉽게 이해할 수 있을 것이다.
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int memo[501][501], partial_sum[501][501], chapter[501];	//memo[a][b]는 a부터 b챕터를 합치는데 드는 최소 비용을, partial_sum[a][b]는 a부터 b챕터까지의 파일 크기의 합을 저장

int DP(int start, int end);

int main(void) {
	int T, K, answer;

	scanf("%d", &T);
	for (int test_case = 0; test_case < T; test_case++) {
		//입력값 저장 및 변수 초기화
		scanf("%d", &K);
		memset(memo, -1, sizeof(int) * 501 * 501);
		memset(partial_sum, 0, sizeof(int) * 501 * 501);

		for (int a = 1; a <= K; a++)	scanf("%d", &chapter[a]);
		//부분 합 계산
		for (int a = 1; a <= K; a++) {
			for (int b = a; b <= K; b++) {
				partial_sum[a][b] = partial_sum[a][b - 1] + chapter[b];
			}
		}
		//DP호출
		answer = DP(1, K);

		printf("%d\n", answer);
	}

	return 0;
}

int DP(int start, int end) {
	if (memo[start][end] != -1)	return memo[start][end];	//이미 계산된 값이면 바로 반환
	
	if (start == end) {	//start==end예외 처리
		memo[start][end] = 0;
	}
	else if (end == start + 1) {	//만약 start와 end가 이어져 있는 경우 최소 비용은 서로 합치는 것
		memo[start][end] = chapter[start] + chapter[end];
	}
	else {	//start와 end사이에 a지점에서 끊어서 합치는 값중 가장 작은 것을 선택
		int minval = 1000000000;
		for (int a = start; a < end; a++)	minval = min(minval, DP(start, a) + DP(a + 1, end) + partial_sum[start][end]);
		memo[start][end] = minval;
	}

	return memo[start][end];
}