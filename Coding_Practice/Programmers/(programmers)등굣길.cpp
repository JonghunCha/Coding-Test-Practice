/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42898
DP로 쉽게 해결할 수 있는 문제다.

dp[a][b]는 a, b좌표에 도달할 수 있는 경로의 갯수를 의미한다.

따라서 초기 dp는 1,1 좌표는 1, 물에 잠긴 지역은 0이된다.

또한 이동 방향은 오른쪽 혹은 아래쪽이기에 dp[a][b] = (dp[a-1][b] + dp[a][b-1])를 만족한다.

이를 이용한 코드는 아래와 같다.
*/
#include <string>
#include <vector>

using namespace std;

int DP(int x, int y, int dp[101][101]);

int solution(int m, int n, vector<vector<int>> puddles) {
    int dp[101][101];
    //초기 dp값 설정
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= m; b++) {
            dp[a][b] = -1;
        }
    }
    dp[1][1] = 1;   //시작 지점은 1
    for (int a = 0; a < puddles.size(); a++) {  //물에 잠긴 지역은 0
        dp[puddles[a][1]][puddles[a][0]] = 0;
    }

    DP(n, m, dp);   //학교의 좌표에 대해 dp값 계산

    return dp[n][m];
}

int DP(int x, int y, int dp[101][101]) {
    if (dp[x][y] != -1)  return dp[x][y];

    int ret = 0;
    if (x > 1)   ret += DP(x - 1, y, dp);   //위쪽에서 올 수 있는 경우
    if (y > 1)   ret += DP(x, y - 1, dp);   //왼쪽에서 올 수 있는 경우

    dp[x][y] = ret % 1000000007;
    return dp[x][y];
}