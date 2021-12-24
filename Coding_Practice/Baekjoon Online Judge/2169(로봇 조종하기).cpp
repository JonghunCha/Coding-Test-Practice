/*
문제 링크 : https://www.acmicpc.net/problem/2169
dp로 해결할 수 있는 문제다.

로봇은 위 왼쪽 오른쪽으로만 이동할 수 있다.

따라서 dp는 위에서 오는 경우, 왼쪽에서 오는 경우, 오른쪽에서 오는 경우에서 가장 큰 값을 저장하도록 구현하면 된다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int board[1001][1001], dp[1001][1001], left[1001], right[1001];

int main(void) {
	int N, M, temp;
	//입력값 저장 및 변수 초기화
	scanf("%d %d", &N, &M);
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= M; b++) {
			scanf("%d", &board[a][b]);
			dp[a][b] = -1;
		}
	}
	//가장 윗줄은 이동방향이 오른쪽밖에 안되기에 dp값을 바로 계산
	temp = 0;
	for (int a = 1; a <= M; a++) {
		temp += board[1][a];
		dp[1][a] = temp;
	}
	//두 번째 줄부터 dp값을 하나씩 계산
	for (int a = 2; a <= N; a++) {
		for (int b = 1; b <= M; b++) {	//left와 right에는 위에서 아래로 이동한 경우의 가치를 초기값으로 가진다
			left[b] = dp[a - 1][b] + board[a][b];
			right[b] = left[b];
		}
		for (int b = 2; b <= M; b++) {	//오른쪽으로 이동하는 경우
			if (left[b] < left[b - 1] + board[a][b])	left[b] = left[b - 1] + board[a][b];	//위에서 온 경우보다 왼쪽에서 왔을 때 가치가 더 큰 경우 값 변경
		}
		for (int b = M - 1; b >= 1; b--) {	//왼쪽으로 이동하는 경우
			if (right[b] < right[b + 1] + board[a][b])	right[b] = right[b + 1] + board[a][b];	//위에서 온 경우보다 오른쪽에서 왔을 때 가치가 더 큰 경우 값 변경
		}
		for (int b = 1; b <= M; b++) {	//왼쪽에서 온 경우, 오른쪽에서 온 경우 중 더 높은 가치를 저장
			dp[a][b] = max(left[b], right[b]);
		}
	}

	printf("%d\n", dp[N][M]);

	return 0;
}