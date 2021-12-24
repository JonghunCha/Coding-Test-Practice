/*
문제 링크 : https://leetcode.com/problems/longest-common-subsequence/
DP로 해결할 수 있는 lcs문제다.

dp[a][b]는 text1의 a번째 문자, text2의 b번째 문자까지 사용하였을 때의 lcs길이를 저장한다.

점화식은 아래와 같다.

1. a혹은 b가 0이면 lcs는 항상 0이다.
2. text1[a]와 text2[b]가 같다면 dp[a][b] = dp[a-1][b-1] + 1이 성립한다.
3. text1[a]와 text2[b]가 다르다면 dp[a][b] = max(dp[a-1][b], dp[a][b-1])이 성립한다.
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1001][1001], length1 = text1.size(), length2 = text2.size(), answer = 0;
        //위의 점화식을 구현한 것이 아래와 같다.
        for (int a = 0; a <= length1; a++) {
            for (int b = 0; b <= length2; b++) {
                if (a == 0 || b == 0)    dp[a][b] = 0;  //1번 케이스
                else if (text1[a - 1] == text2[b - 1])    dp[a][b] = dp[a - 1][b - 1] + 1;  //2번 케이스
                else    dp[a][b] = max(dp[a - 1][b], dp[a][b - 1]); //3번 케이스
            }
        }

        return answer;
    }
};