/*
문제 링크 : https://leetcode.com/problems/edit-distance/
DP로 해결할 수 있다.

dp[a][b]는 word1의 a번째 인덱스, word2의 b번째 인덱스부터를 비교하였을 때의 정답 값을 의미한다.

word1[a] == word2[b]라면 어떠한 연산도 할 필요가 없기에 a + 1과 b + 1부터 시작한 값과 일치한다.

만약 일치하지 않는 경우 연산의 3가지 종류 중 가장 작은 값을 선택하면 된다. 
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size(), dp[501][501], min, temp;

        for (int a = 0; a <= len1; a++)  dp[a][len2] = len1 - a;    //word2의 마지막인 경우
        for (int a = 0; a <= len2; a++)  dp[len1][a] = len2 - a;    //word1의 마지막인 경우

        for (int a = len1 - 1; a >= 0; a--) {
            for (int b = len2 - 1; b >= 0; b--) {
                if (word1[a] == word2[b])    dp[a][b] = dp[a + 1][b + 1];   //두 문자가 같다는 것은 어떠한 연산도 필요 없다는 의미
                else {
                    min = dp[a][b + 1] + 1; //문자를 삽입하는 경우(word2와 매칭되는 문자를 삽입하였기에 b + 1)
                    temp = dp[a + 1][b] + 1;    //문자를 삭제하는 경우(word1의 문자를 삭제하였기에 a + 1)
                    if (temp < min)  min = temp;
                    temp = dp[a + 1][b + 1] + 1;    //문자를 대체하는 경우(word1의 문자를 word2로 바꾸어 주었기에 a와 b모두 +1)
                    if (temp < min)  min = temp;
                    dp[a][b] = min;
                }
            }
        }

        return dp[0][0];
    }
};