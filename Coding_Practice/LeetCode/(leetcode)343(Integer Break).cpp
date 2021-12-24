/*
문제 링크 : https://leetcode.com/problems/integer-break/
DP로 해결할 수 있는 문제다.

dp[a]는 n이 a일 때의 정답을 저장한다고 가정하자.

아래 코드를 보면 dp[a]를 어떻게 계산하는지 쉽게 이해할 수 있을 것이다.
*/
class Solution {
public:
    int integerBreak(int n) {
        int dp[59], max, temp;
        //dp초기화
        for (int a = 2; a < 59; a++) dp[a] = -1;
        dp[2] = 1;
        //작은 수부터 dp 값 계산
        for (int a = 3; a <= n; a++) {
            max = 0;
            for (int b = 1; b <= a / 2; b++) {  //(a/2)와 같거나 작은 수 b를 고른다
                temp = b * (a - b); //a를 b와 (a-b) 2개로 나누는 경우의 product 값
                if (temp > max)  max = temp;
                temp = b * dp[a - b];   //a를 b와 dp[a-b] 즉 3개 이상의 수로 나누는 경우의 product 값
                if (temp > max)  max = temp;
            }
            dp[a] = max;    //위 계산을 했을 때 가장 큰 값이 dp[a]의 값이 된다.
        }

        return dp[n];
    }
};