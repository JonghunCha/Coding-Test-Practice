/*
문제 링크 : https://leetcode.com/problems/decode-ways/
DP로 해결할 수 있는 문제다.

문자열의 앞에서부터 끝까지 살피며 각 지점까지 decoding했을 때 몇 가지로 나뉠 수 있는지 계산하면 된다.

아래 코드를 보면 쉽게 이해할 수 있다.
*/
class Solution {
public:
    int numDecodings(string s) {
        int answer = 0, n = s.size(), dp[n];    //dp[n]은 n번째 index까지의 문자열이 decoding되는 방법의 갯수를 저장
        char prev;  //prev는 직전에 나왔던 문자 저장

        for (int a = 0; a < n; a++)  dp[a] = -1;
        //s.size()가 1인 경우
        if (s.size() == 1) {    
            if (s[0] == '0') return 0;
            else    return 1;
        }
        //s.size()가 2이상인 경우(dp[0]과 dp[1]의 초기값을 계산 및 저장)
        if (s[0] == '0') return 0;
        else if (s[0] == '1') { 
            if (s[1] == '0') dp[1] = 1;
            else    dp[1] = 2;
        }
        else if (s[0] == '2') {
            if (s[1] <= '6' && s[1] >= '1') dp[1] = 2;
            else    dp[1] = 1;
        }
        else {
            if (s[1] == '0') return 0;
            dp[1] = 1;
        }
        dp[0] = 1;
        prev = s[1];
        //나머지 부분의 dp 계산
        for (int a = 2; a < n; a++) {
            if (s[a] == '0') {  //'0'문자 앞에는 '1'또는 '2'가 있어야한다
                if (prev != '1' && prev != '2')  return 0;
                else    dp[a] = dp[a - 2];
            }
            else { 
                if (prev == '0') dp[a] = dp[a - 1];
                else if (prev == '1')    dp[a] = dp[a - 1] + dp[a - 2];
                else if (prev == '2') {
                    if (s[a] <= '6') dp[a] = dp[a - 1] + dp[a - 2];
                    else    dp[a] = dp[a - 1];
                }
                else    dp[a] = dp[a - 1];
            }
            prev = s[a];
        }

        return dp[n - 1];
    }
};