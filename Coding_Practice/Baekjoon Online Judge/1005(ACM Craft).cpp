/*
문제 링크 : https://www.acmicpc.net/problem/1005
Dynamic Programming을 이용하여 해결할 수 있는 문제다.

우선 target건물을 짓기 위해서 지어야하는 건물들을 추출한다.

해당 건물들 중 가장 늦게 완성되는 건물을 짓는데 걸리는 시간 + target건물을 짓는데 걸리는 시간이 정답값이다.
*/
#include <iostream>
using namespace std;

int D[1001], build[1001][1001], dp[1001];

int DP(int N, int num);

int main(void) {
	int T, N, K, x, y, target, temp;

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		//입력값 저장 및 변수 초기화
		cin >> N >> K;
		for (int a = 1; a <= N; a++) {	//건물 짓는 순서를 저장하는 build 초기화
			for (int b = 1; b <= N; b++) {
				build[a][b] = 0;
			}
		}
		for (int a = 1; a <= N; a++)	dp[a] = -1;	//a번째 건물을 짓는데 걸리는 최소시간을 저장하는 dp 초기화
		for (int a = 1; a <= N; a++)	cin >> D[a];	//각 건물을 짓는데 걸리는 시간 입력 저장
		for (int a = 1; a <= K; a++) {	//build입력 저장
			cin >> x >> y;
			build[y][x] = 1;
		}
		cin >> target;	//타겟 건물 입력 저장

		DP(N, target);
		cout << dp[target] << endl;
	}
	return 0;
}

int DP(int N, int num) {
	if (dp[num] != -1)	return dp[num];

	int ret = D[num], temp;
	for (int a = 1; a <= N; a++) {	//num을 짓기 위해서 지어야하는 건물 중 가장 늦게 지어지는 건물 + D[num]이 num을 짓는데 걸리는 최소 시간
		if (build[num][a] == 1) {
			temp = D[num] + DP(N, a);
			if (temp > ret)	ret = temp;
		}
	}
	dp[num] = ret;
	return ret;
}