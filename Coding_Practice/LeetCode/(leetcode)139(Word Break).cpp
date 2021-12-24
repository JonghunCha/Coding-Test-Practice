/*
문제 링크 : https://leetcode.com/problems/word-break/
DP로 해결할 수 있는 문제다.

dp[n]에는 n번째 index부터 시작한 문자열이 wordDict의 문자들로 정확히 나뉠 수 있다면 1, 없다면 0, 계산되지 않았다면 -1을 저장한다.
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), dp[n];
        //dp초기화
        for (int a = 0; a < n; a++)  dp[a] = -1;

        return DP(s, wordDict, dp, 0);
    }

    bool DP(string s, vector<string>& wordDict, int* dp, int index) {
        int n = s.size();
        if (index == n || dp[index] == 1)  return true; //index가 n이라는 것은 s문자열의 끝까지 wordDIct로 쪼갤수 있음을 의미
        if (dp[index] == 0)  return false;
        //모든 wordDict에 대해 s의 index번째부터 시작했을 때 겹치는 문자열이 있는지 확인
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