/*
문제 링크 : https://leetcode.com/problems/longest-increasing-subsequence/
DP로 해결할 수 있는 문제다.

dp[n]은 n번째 수가 subsequence의 시작일 때 최대 길이를 저장하도록 하면 된다.
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), dp[n], max, temp, ret = 0;

        for (int a = 0; a < n; a++)  dp[a] = -1;
        for (int a = n - 1; a >= 0; a--) {  //끝에서부터 dp계산
            max = 0;
            //a번째 수보다 큰 숫자부터 시작하는 subsequence중 가장 긴 것을 선택
            for (int b = a + 1; b < n; b++) {
                if (nums[b] > nums[a]) {    
                    temp = dp[b];
                    if (temp > max)  max = temp;
                }
            }
            dp[a] = max + 1;
            if (dp[a] > ret) ret = dp[a];
        }

        return ret;
    }
};