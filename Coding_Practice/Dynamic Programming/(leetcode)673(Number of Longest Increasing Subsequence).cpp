/*
문제 링크 : https://leetcode.com/problems/number-of-longest-increasing-subsequence/
DP로 해결할 수 있다.

(leetcode)300번 문제와 흡사하지만, 300번 문제는 가장 긴 것의 길이를 반환하라 하였다면, 이번 문제는 가장 긴 것의 갯수를 반환해야한다.

따라서 가장 긴 것의 길이를 구하는 파트와, 가장 긴 것의 갯수를 구하는 파트로 나누었다.
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), dp[n][2] = { 0, }, max, temp, longest = 0, answer = 0; //dp[a][0]은 a번째 index에서 시작한 가장 긴 것의 길이, dp[a][1]은 갯수를 의미
        //dp초기화
        for (int a = 0; a < n; a++) {
            dp[a][0] = 0;
            dp[a][1] = 0;
        }
        //모든 index에 대해 dp[a][0]과 dp[a][1]을 계산
        for (int a = n - 1; a >= 0; a--) {
            //먼저 가장 긴 것의 길이를 구한다
            max = 0;
            for (int b = a + 1; b < n; b++) {
                if (nums[b] > nums[a]) {
                    temp = dp[b][0];
                    if (temp > max)  max = temp;
                }
            }
            //똑같은 지역을 다시 탐색하며 가장 긴 것의 갯수가 몇개인지 계산
            for (int b = a + 1; b < n; b++) {
                if (nums[b] > nums[a] && dp[b][0] == max)    dp[a][1] += dp[b][1];
            }
            //dp[a][0]과 dp[a][1]을 설정하고, longest 갱신
            dp[a][0] = max + 1;
            if (dp[a][1] == 0)   dp[a][1]++;
            if (dp[a][0] > longest) longest = dp[a][0];
        }
        //처음부터 살피며 longest와 일치하는 index의 갯수를 다 더한다
        for (int a = 0; a < n; a++) {
            if (dp[a][0] == longest) answer += dp[a][1];
        }

        return answer;
    }
};