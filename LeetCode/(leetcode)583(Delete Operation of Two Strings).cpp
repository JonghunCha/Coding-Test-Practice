/*
���� ��ũ : https://leetcode.com/problems/delete-operation-for-two-strings/
DP�� �ذ��� �� �ִ� ������.

�������� �䱸�ϴ� ���� �ּ����� ���ڸ� ���� word1�� word2�� ���������� �ϴ� ���ε�, �̴� word1�� word2�� LCS(Logest Common Subsequence)�� ���ϰ� LCS�� ���Ե��� �ʴ� 
�κе��� �����ϴ� �Ͱ� ����.

����, LCS�� ���̸� ���ϰ� word1�� word2�� ���̿��� �� ���� ���� �ȴ�.
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size(), dp[501][501]; //dp[a][b]�� word1�� a��° �ε���, word2�� b��° �ε��� ������ �͵鸸 ���Ͽ��� �� LCS�� ���̸� ����
        //dp�ʱ�ȭ
        for (int a = 0; a <= len1; a++) {
            for (int b = 0; b <= len2; b++) {
                dp[a][b] = -1;
            }
        }
        //LCS�� ���ϴ� ����
        for (int a = len1; a >= 0; a--) {
            for (int b = len2; b >= 0; b--) {
                if (a == len1 || b == len2)  dp[a][b] = 0;  //�� �� �ϳ��� ���̰� 0�� ��
                else if (word1[a] == word2[b])   dp[a][b] = dp[a + 1][b + 1] + 1;   //���� ���� ���ڸ� dp[a][b]�� ���� �ܰ��� dp���� 1�� ���� ���� �ȴ�.
                else    dp[a][b] = max(dp[a + 1][b], dp[a][b + 1]); //���� ���� �ٸ��ٸ� word1���� �� ĭ ����, word2���� �� ĭ ������ ���� ���Ͽ� ū ���� ���Ѵ�.
            }
        }
        //LCS�κ��� ������ �������� ���� ��ȯ
        return (len1 + len2 - 2 * dp[0][0]);
    }
};