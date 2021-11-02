/*
���� ��ũ : https://leetcode.com/problems/house-robber/
Dynamic Programming���� �ذ��� �� �ִ� ������.

���� n�� �ִٰ� ��������.

�׷� �츮�� n��° ���� �ʹ� ���� �׷��� ���� ��� �߿��� �� ���� �̵��� ���� �� �ִ� ���� �����ϸ� �ȴ�.

�� Answer(N) = max(Answer(N-2) + nums[N], Answer(N-1))�̶�� ��ȭ���� �����ȴ�.

�Ʒ� �ڵ�� �װ��� ������ ���̴�.
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) return nums[0];    //��ü ���� ������ 1���̸� �� ���� ��ȯ
        int dp[100];    //dp[n]�� n��° ������ �������Ѵٰ� ���� ���� ���� ��
        for (int a = 0; a < 100; a++)    dp[a] = -1;
        dp[0] = nums[0]; 
        dp[1] = max(nums[0], nums[1]);
        return DP(nums, dp, nums.size() - 1);
    }

    int DP(vector<int>& nums, int dp[100], int index) {
        if (dp[index] != -1) return dp[index];  //�̹� ���� �����̸� �ٷ� ��ȯ
        dp[index] = max(DP(nums, dp, index - 2) + nums[index], DP(nums, dp, index - 1));    //������ ����� ��ȭ��
        return dp[index];
    }
};