/*
문제 링크 : https://leetcode.com/problems/unique-paths/
간단한 DP문제다.

board의 각 지역에 도달할 수 있는 유니크한 방법의 갯수를 answer[m][n]에 저장한다.

각 지역은 왼쪽 혹은 위쪽에서만 도달 가능하다고 했다.

따라서 board를 위에서부터 아래로, 왼쪽부터 오른쪽으로 탐색하며 answer를 계산하면 된다.
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int answer[m][n];
        //answer초기화
        for (int a = 0; a < m; a++) {
            for (int b = 0; b < n; b++) {
                answer[a][b] = 0;
            }
        }
        answer[0][0] = 1;
        //위에서 아래로, 왼쪽부터 오른쪽으로 answer계산
        for (int a = 0; a < m; a++) {
            for (int b = 0; b < n; b++) {
                if (a != 0 || b != 0) {
                    if (a != 0)  answer[a][b] += answer[a - 1][b];
                    if (b != 0)  answer[a][b] += answer[a][b - 1];
                }
            }
        }

        return answer[m - 1][n - 1];
    }
};