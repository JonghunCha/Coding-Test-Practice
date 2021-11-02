/*
���� ��ũ : https://leetcode.com/problems/climbing-stairs/
���� �⺻���� ������ Dynamic Programming ������.

�Ʒ� �ڵ常 ���� �ݹ� ������ �� ���� ���̴�.
*/
class Solution {
public:
    int climbStairs(int n) {
        int dp[46];
        for (int a = 0; a < 46; a++) dp[a] = -1;
        dp[1] = 1;
        dp[2] = 2;
        return Get_Answer(n, dp);
    }

    int Get_Answer(int n, int dp[46]) {
        if (dp[n] != -1) return dp[n];
        dp[n] = Get_Answer(n - 1, dp) + Get_Answer(n - 2, dp);
        return dp[n];
    }
};