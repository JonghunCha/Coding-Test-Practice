/*
���� ��ũ : https://leetcode.com/problems/edit-distance/
DP�� �ذ��� �� �ִ�.

dp[a][b]�� word1�� a��° �ε���, word2�� b��° �ε������͸� ���Ͽ��� ���� ���� ���� �ǹ��Ѵ�.

word1[a] == word2[b]��� ��� ���굵 �� �ʿ䰡 ���⿡ a + 1�� b + 1���� ������ ���� ��ġ�Ѵ�.

���� ��ġ���� �ʴ� ��� ������ 3���� ���� �� ���� ���� ���� �����ϸ� �ȴ�. 
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size(), dp[501][501], min, temp;

        for (int a = 0; a <= len1; a++)  dp[a][len2] = len1 - a;    //word2�� �������� ���
        for (int a = 0; a <= len2; a++)  dp[len1][a] = len2 - a;    //word1�� �������� ���

        for (int a = len1 - 1; a >= 0; a--) {
            for (int b = len2 - 1; b >= 0; b--) {
                if (word1[a] == word2[b])    dp[a][b] = dp[a + 1][b + 1];   //�� ���ڰ� ���ٴ� ���� ��� ���굵 �ʿ� ���ٴ� �ǹ�
                else {
                    min = dp[a][b + 1] + 1; //���ڸ� �����ϴ� ���(word2�� ��Ī�Ǵ� ���ڸ� �����Ͽ��⿡ b + 1)
                    temp = dp[a + 1][b] + 1;    //���ڸ� �����ϴ� ���(word1�� ���ڸ� �����Ͽ��⿡ a + 1)
                    if (temp < min)  min = temp;
                    temp = dp[a + 1][b + 1] + 1;    //���ڸ� ��ü�ϴ� ���(word1�� ���ڸ� word2�� �ٲپ� �־��⿡ a�� b��� +1)
                    if (temp < min)  min = temp;
                    dp[a][b] = min;
                }
            }
        }

        return dp[0][0];
    }
};