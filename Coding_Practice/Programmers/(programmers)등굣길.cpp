/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42898
DP�� ���� �ذ��� �� �ִ� ������.

dp[a][b]�� a, b��ǥ�� ������ �� �ִ� ����� ������ �ǹ��Ѵ�.

���� �ʱ� dp�� 1,1 ��ǥ�� 1, ���� ��� ������ 0�̵ȴ�.

���� �̵� ������ ������ Ȥ�� �Ʒ����̱⿡ dp[a][b] = (dp[a-1][b] + dp[a][b-1])�� �����Ѵ�.

�̸� �̿��� �ڵ�� �Ʒ��� ����.
*/
#include <string>
#include <vector>

using namespace std;

int DP(int x, int y, int dp[101][101]);

int solution(int m, int n, vector<vector<int>> puddles) {
    int dp[101][101];
    //�ʱ� dp�� ����
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= m; b++) {
            dp[a][b] = -1;
        }
    }
    dp[1][1] = 1;   //���� ������ 1
    for (int a = 0; a < puddles.size(); a++) {  //���� ��� ������ 0
        dp[puddles[a][1]][puddles[a][0]] = 0;
    }

    DP(n, m, dp);   //�б��� ��ǥ�� ���� dp�� ���

    return dp[n][m];
}

int DP(int x, int y, int dp[101][101]) {
    if (dp[x][y] != -1)  return dp[x][y];

    int ret = 0;
    if (x > 1)   ret += DP(x - 1, y, dp);   //���ʿ��� �� �� �ִ� ���
    if (y > 1)   ret += DP(x, y - 1, dp);   //���ʿ��� �� �� �ִ� ���

    dp[x][y] = ret % 1000000007;
    return dp[x][y];
}