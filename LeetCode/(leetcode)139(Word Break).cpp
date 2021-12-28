/*
���� ��ũ : https://leetcode.com/problems/word-break/
DP�� �ذ��� �� �ִ� ������.

dp[n]���� n��° index���� ������ ���ڿ��� wordDict�� ���ڵ�� ��Ȯ�� ���� �� �ִٸ� 1, ���ٸ� 0, ������ �ʾҴٸ� -1�� �����Ѵ�.
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), dp[n];
        //dp�ʱ�ȭ
        for (int a = 0; a < n; a++)  dp[a] = -1;

        return DP(s, wordDict, dp, 0);
    }

    bool DP(string s, vector<string>& wordDict, int* dp, int index) {
        int n = s.size();
        if (index == n || dp[index] == 1)  return true; //index�� n�̶�� ���� s���ڿ��� ������ wordDIct�� �ɰ��� ������ �ǹ�
        if (dp[index] == 0)  return false;
        //��� wordDict�� ���� s�� index��°���� �������� �� ��ġ�� ���ڿ��� �ִ��� Ȯ��
        for (int a = 0; a < wordDict.size(); a++) {
            if (index + wordDict[a].size() <= n) {
                if (s.substr(index, wordDict[a].size()).compare(wordDict[a]) == 0 && DP(s, wordDict, dp, index + wordDict[a].size())) {
                    dp[index] = 1;
                    return true;
                }
            }
        }
        dp[index] = 0;
        return false;
    }
};