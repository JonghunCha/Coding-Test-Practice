/*
문제 링크 : https://swexpertacademy.com/main/main.do
DP로 해결할 수 있는 문제다. 그러나 DP만 사용하였을 때는 시간 초과가 나서 누적합을 통해 일부 계산과정을 최적화하여 통과하였다.

우선 건포도의 위치에 패턴이 있는 것이 아니기에 가능한 모든 경우를 알아내야 한다.

이 경우 중복된 계산이 많이 생기는데 이를 DP로 해결하였다.
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[50][50][50][50], prefix_sum[50][50];	//dp는 다이나믹 프로그래밍을 위해, prefix_sum은 누적합을 위해 사용됨

int DP(int chocolate[50][50], int x1, int y1, int x2, int y2);

int main(int argc, char** argv)
{
	int T, N, M, chocolate[50][50], temp, answer;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장
		scanf("%d %d", &N, &M);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < M; b++) {
				scanf("%d", &chocolate[a][b]);
			}
		}
		//누적합 계산
		for (int a = 0; a < N; a++) {
			temp = 0;
			for (int b = 0; b < M; b++) {
				temp += chocolate[a][b];
				prefix_sum[a][b] = temp;
			}
		}
		//dp 초기화
		memset(dp, -1, sizeof(dp));
		//DP함수 호출
		answer = DP(chocolate, 0, 0, N - 1, M - 1);
		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}
//x1, y1은 DP값을 구하려는 직사각형의 왼쪽 위의 좌표, x2, y2는 오른쪽 아래 좌표를 의미
int DP(int chocolate[50][50], int x1, int y1, int x2, int y2) {
	if (dp[x1][y1][x2][y2] != -1)	return dp[x1][y1][x2][y2];
	//만약 1*1인 지역이면 자를 필요가 없기에 0 반환
	if (x1 == x2 && y1 == y2) {
		dp[x1][y1][x2][y2] = 0;
		return 0;
	}

	int ret = 999999999, temp, basic = 0;
	//누적합을 통해서 현재 직사각형을 자를 때 드는 비용 계산
	for (int a = x1; a <= x2; a++) {
		if (y1 == 0)	basic += prefix_sum[a][y2];
		else	basic += prefix_sum[a][y2] - prefix_sum[a][y1 - 1];
	}
	//어떻게 잘라야 가장 최소 비용이 드는지 DP 재귀를 통해 계산
	for (int a = x1 + 1; a <= x2; a++) {
		ret = min(ret, DP(chocolate, x1, y1, a - 1, y2) + DP(chocolate, a, y1, x2, y2) + basic);
	}
	for (int a = y1 + 1; a <= y2; a++) {
		ret = min(ret, DP(chocolate, x1, y1, x2, a - 1) + DP(chocolate, x1, a, x2, y2) + basic);
	}

	dp[x1][y1][x2][y2] = ret;
	return ret;
}