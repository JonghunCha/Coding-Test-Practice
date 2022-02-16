/*
문제 링크 : https://www.acmicpc.net/problem/1937
DP로 해결할 수 있는 문제다.

dp[a][b]는 판다가 a행 b열에 도착 할때까지 지나온 지역의 최대 수를 저장한다.

점화식의 개념이 간단해 아래 코드만 봐도 쉽게 이해할 수 있을 것이다.
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
	//입력값 저장 및 변수 초기화
	scanf("%d", &N);
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			scanf("%d", &forest[a][b]);
		}
	}
	memset(dp, -1, sizeof(int) * 500 * 500);
	//모든 지역의 dp를 계산하고 최댓값을 갱신
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
	if (dp[x][y] != -1)	return dp[x][y];	//이미 계산된 지역이면 바로 반환

	int ret = 1, nx, ny, temp;
	//인접한 4방향의 지역에 대해 유효한 지역이며 해당 지역의 대나무 양이 x, y보다 작다면 해당 지역으로부터 현재 x, y로 이동이 가능함
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