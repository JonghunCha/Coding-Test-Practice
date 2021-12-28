/*
문제 링크 : https://leetcode.com/problems/coin-change/
DP로 해결할 수 있는 문제다.

dp[a]는 amount가 a일 때 정답을 의미한다.

아래 코드를 보면 쉽게 이해할 수 있을 것이다.
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(), dp[10001];
        //coins정렬 및 dp 초기화
        sort(coins.begin(), coins.end());
        for (int a = 0; a <= amount; a++)    dp[a] = 0;

        return DP(coins, amount, dp);
    }

    int DP(vector<int>& coins, int amount, int dp[10001]) {
        int n = coins.size(), min = 20000, temp;
        //이미 계산한 경우 바로 반환
        if (dp[amount] != 0)    return dp[amount];
      
        if (amount == 0) return 0;  //amount가 0인 경우는 코인을 쓸 필요가 없음
        else if (amount < coins[0]) {   //만약 amount가 가장 작은 코인보다 크기가 작다면 항상 -1반환
            dp[amount] = -1;
            return -1;
        }
        else {  //적어도 1개 이상의 코인이 amount보다 작거나 같은 경우
            for (int a = 0; a < n; a++) {
                if (coins[a] <= amount) {
                    temp = DP(coins, amount - coins[a], dp);
                    if (temp != -1) {   //temp가 -1인 경우를 무시하고 min을 갱신
                        temp++;
                        if (temp < min)  min = temp;
                    }
                }
                else    break;
            }

            if (min == 20000)    dp[amount] = -1;   //min이 20000에서 안 바뀐 경우는 해당 amount는 조합할 수 없다는 의미
            else    dp[amount] = min;
            return dp[amount];
        }
    }
};