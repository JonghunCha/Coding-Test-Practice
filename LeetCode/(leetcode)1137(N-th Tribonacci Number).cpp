/*
���� ��ũ : https://leetcode.com/problems/n-th-tribonacci-number/
��ǥ���� DP �����̴�. 
*/
class Solution {
public:
    int tribonacci(int n) {
        int memo[40];

        memset(memo, 0, sizeof(int) * 40);
        memo[0] = 0, memo[1] = 1, memo[2] = 1;

        for (int a = 3; a <= n; a++) {
            memo[a] = memo[a - 1] + memo[a - 2] + memo[a - 3];
        }

        return memo[n];
    }
};