/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42897#
dp로 해결할 수 있는 문제다.

하나 생각해야 할 점은 집들이 원형으로 구성되어 있어, 첫 집을 털면 마지막 집을 털지 못하고, 마지막 집을 털면 첫 집을 털지 못한다.

따라서, 애초에 첫 집이 없다고 가정한 뒤 1~n번째 집을 털 때 최댓값과 마지막 집이 없다고 가정한 뒤 0~n-1번째 집을 털 떄 최댓값을 따로 구한 뒤 비교하였다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000001];    //dp는 a번째 집까지 턴다고 할 때 훔칠 수 있는 돈의 최댓값을 저장

int solution(vector<int> money) {
    int answer = 0;

    //dp값 초기화
    for (int a = 0; a < money.size(); a++)   dp[a] = -1;

    //마지막 집을 털지 않는 경우
    dp[0] = money[0];
    dp[1] = max(money[0], money[1]);
    for (int a = 2; a < money.size() - 1; a++) {
        dp[a] = max(dp[a - 2] + money[a], dp[a - 1]);   //a번째 집을 터는 경우와 털지 않는 경우 중 더 큰 값을 저장
    }
    answer = dp[money.size() - 2];

    //dp값 초기화
    for (int a = 0; a < money.size(); a++)   dp[a] = -1;

    //첫 집을 털지 않는 경우
    dp[1] = money[1];
    dp[2] = max(money[1], money[2]);
    for (int a = 3; a < money.size(); a++) {
        dp[a] = max(dp[a - 2] + money[a], dp[a - 1]);
    }
    answer = max(answer, dp[money.size() - 1]);

    return answer;
}