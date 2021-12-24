/*
문제 링크 : https://leetcode.com/problems/01-matrix/
이 문제같은 경우 BFS로 해결할 수도 있고 DP로도 해결할 수 있다.

BFS로는 해결을 했었는데 DP로 해결을 못해서 discuss를 찾아보다 깔끔한 정리가 있어서 따라 작성해보았다.

우선 DP는 기존에 계산된 정보를 통해 원하는 값을 계산하는 알고리즘이다. 그러나 이 문제같은 경우 동서남북 4 방향의 정보가 전부 계산되었다고 장담할 수 있는 방법이 없다.

동서남북 4 방향의 정보를 전부 이용하며 각 방향의 정보가 이미 계산되었음을 보장하기 위한 방법은 아래와 같다.

1. 왼쪽 위에서부터 아래쪽 오른쪽으로 훑으며 matrix를 업데이트 한다.(이 경우 북쪽, 서쪽 방향의 정보를 이용하며 해당 방향의 정보는 이미 계산되었음이 보장된다)
2. 1번 과정이 끝나면 아래쪽 오른쪽에서부터 왼쪽 위로 훓으며 남쪽 동쪽의 정보를 이용한 값과 1에서 구한 값을 비교하여 더 작은것을 취한다.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int height = mat.size(), width = mat[0].size(), top, bottom, left, right;
        //왼쪽 위에서 오른쪽 아래 방향으로 matrix업데이트
        for (int a = 0; a < height; a++) {
            for (int b = 0; b < width; b++) {
                if (mat[a][b] == 0)  continue;
                top = 10000, left = 10000;
                if (a - 1 >= 0)  top = mat[a - 1][b];
                if (b - 1 >= 0)  left = mat[a][b - 1];
                mat[a][b] = min(top, left) + 1;
            }
        }
        //오른쪽 아래에서 왼쪽 위 방향으로 탐색을하며 업데이트는 위에서 구한 값과 비교하여 더 작은 값을 취한다.
        for (int a = height - 1; a >= 0; a--) {
            for (int b = width - 1; b >= 0; b--) {
                if (mat[a][b] == 0)  continue;
                bottom = 10000, right = 10000;
                if (a + 1 < height)  bottom = mat[a + 1][b];
                if (b + 1 < width)   right = mat[a][b + 1];
                mat[a][b] = min(mat[a][b], min(bottom, right) + 1);
            }
        }
        return mat;
    }
};