/*
���� ��ũ : https://leetcode.com/problems/longest-common-subsequence/
DP�� �ذ��� �� �ִ� lcs������.

dp[a][b]�� text1�� a��° ����, text2�� b��° ���ڱ��� ����Ͽ��� ���� lcs���̸� �����Ѵ�.

��ȭ���� �Ʒ��� ����.

1. aȤ�� b�� 0�̸� lcs�� �׻� 0�̴�.
2. text1[a]�� text2[b]�� ���ٸ� dp[a][b] = dp[a-1][b-1] + 1�� �����Ѵ�.
3. text1[a]�� text2[b]�� �ٸ��ٸ� dp[a][b] = max(dp[a-1][b], dp[a][b-1])�� �����Ѵ�.
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1001][1001], length1 = text1.size(), length2 = text2.size(), answer = 0;
        //���� ��ȭ���� ������ ���� �Ʒ��� ����.
        for (int a = 0; a <= length1; a++) {
            for (int b = 0; b <= length2; b++) {
                if (a == 0 || b == 0)    dp[a][b] = 0;  //1�� ���̽�
                else if (text1[a - 1] == text2[b - 1])    dp[a][b] = dp[a - 1][b - 1] + 1;  //2�� ���̽�
                else    dp[a][b] = max(dp[a - 1][b], dp[a][b - 1]); //3�� ���̽�
            }
        }

        return answer;
    }
};