/*
���� ��ũ : https://leetcode.com/problems/longest-increasing-subsequence/
DP�� �ذ��� �� �ִ� ������.

dp[n]�� n��° ���� subsequence�� ������ �� �ִ� ���̸� �����ϵ��� �ϸ� �ȴ�.
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), dp[n], max, temp, ret = 0;

        for (int a = 0; a < n; a++)  dp[a] = -1;
        for (int a = n - 1; a >= 0; a--) {  //���������� dp���
            max = 0;
            //a��° ������ ū ���ں��� �����ϴ� subsequence�� ���� �� ���� ����
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