/*
문제 링크 : https://leetcode.com/problems/delete-operation-for-two-strings/
DP로 해결할 수 있는 문제다.

문제에서 요구하는 것은 최소한의 문자를 빼서 word1과 word2이 같아지도록 하는 것인데, 이는 word1과 word2의 LCS(Logest Common Subsequence)를 구하고 LCS에 포함되지 않는 
부분들을 제거하는 것과 같다.

따라서, LCS의 길이를 구하고 word1과 word2의 길이에서 그 값을 빼면 된다.
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size(), dp[501][501]; //dp[a][b]는 word1의 a번째 인덱스, word2의 b번째 인덱스 이후의 것들만 비교하였을 때 LCS의 길이를 저장
        //dp초기화
        for (int a = 0; a <= len1; a++) {
            for (int b = 0; b <= len2; b++) {
                dp[a][b] = -1;
            }
        }
        //LCS를 구하는 과정
        for (int a = len1; a >= 0; a--) {
            for (int b = len2; b >= 0; b--) {
                if (a == len1 || b == len2)  dp[a][b] = 0;  //둘 중 하나가 길이가 0일 때
                else if (word1[a] == word2[b])   dp[a][b] = dp[a + 1][b + 1] + 1;   //만약 같은 문자면 dp[a][b]는 이전 단계의 dp값에 1을 더한 값이 된다.
                else    dp[a][b] = max(dp[a + 1][b], dp[a][b + 1]); //만약 서로 다르다면 word1에서 한 칸 이전, word2에서 한 칸 이전의 값을 비교하여 큰 값을 취한다.
            }
        }
        //LCS부분을 제외한 나머지의 길이 반환
        return (len1 + len2 - 2 * dp[0][0]);
    }
};