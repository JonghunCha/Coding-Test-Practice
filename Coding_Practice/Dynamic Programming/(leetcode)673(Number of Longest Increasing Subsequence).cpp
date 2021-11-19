/*
���� ��ũ : https://leetcode.com/problems/number-of-longest-increasing-subsequence/
DP�� �ذ��� �� �ִ�.

(leetcode)300�� ������ ���������, 300�� ������ ���� �� ���� ���̸� ��ȯ�϶� �Ͽ��ٸ�, �̹� ������ ���� �� ���� ������ ��ȯ�ؾ��Ѵ�.

���� ���� �� ���� ���̸� ���ϴ� ��Ʈ��, ���� �� ���� ������ ���ϴ� ��Ʈ�� ��������.
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), dp[n][2] = { 0, }, max, temp, longest = 0, answer = 0; //dp[a][0]�� a��° index���� ������ ���� �� ���� ����, dp[a][1]�� ������ �ǹ�
        //dp�ʱ�ȭ
        for (int a = 0; a < n; a++) {
            dp[a][0] = 0;
            dp[a][1] = 0;
        }
        //��� index�� ���� dp[a][0]�� dp[a][1]�� ���
        for (int a = n - 1; a >= 0; a--) {
            //���� ���� �� ���� ���̸� ���Ѵ�
            max = 0;
            for (int b = a + 1; b < n; b++) {
                if (nums[b] > nums[a]) {
                    temp = dp[b][0];
                    if (temp > max)  max = temp;
                }
            }
            //�Ȱ��� ������ �ٽ� Ž���ϸ� ���� �� ���� ������ ����� ���
            for (int b = a + 1; b < n; b++) {
                if (nums[b] > nums[a] && dp[b][0] == max)    dp[a][1] += dp[b][1];
            }
            //dp[a][0]�� dp[a][1]�� �����ϰ�, longest ����
            dp[a][0] = max + 1;
            if (dp[a][1] == 0)   dp[a][1]++;
            if (dp[a][0] > longest) longest = dp[a][0];
        }
        //ó������ ���Ǹ� longest�� ��ġ�ϴ� index�� ������ �� ���Ѵ�
        for (int a = 0; a < n; a++) {
            if (dp[a][0] == longest) answer += dp[a][1];
        }

        return answer;
    }
};