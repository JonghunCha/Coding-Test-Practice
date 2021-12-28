/*
���� ��ũ : https://leetcode.com/problems/01-matrix/
�� �������� ��� BFS�� �ذ��� ���� �ְ� DP�ε� �ذ��� �� �ִ�.

BFS�δ� �ذ��� �߾��µ� DP�� �ذ��� ���ؼ� discuss�� ã�ƺ��� ����� ������ �־ ���� �ۼ��غ��Ҵ�.

�켱 DP�� ������ ���� ������ ���� ���ϴ� ���� ����ϴ� �˰����̴�. �׷��� �� �������� ��� �������� 4 ������ ������ ���� ���Ǿ��ٰ� ����� �� �ִ� ����� ����.

�������� 4 ������ ������ ���� �̿��ϸ� �� ������ ������ �̹� ���Ǿ����� �����ϱ� ���� ����� �Ʒ��� ����.

1. ���� ���������� �Ʒ��� ���������� ������ matrix�� ������Ʈ �Ѵ�.(�� ��� ����, ���� ������ ������ �̿��ϸ� �ش� ������ ������ �̹� ���Ǿ����� ����ȴ�)
2. 1�� ������ ������ �Ʒ��� �����ʿ������� ���� ���� �f���� ���� ������ ������ �̿��� ���� 1���� ���� ���� ���Ͽ� �� �������� ���Ѵ�.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int height = mat.size(), width = mat[0].size(), top, bottom, left, right;
        //���� ������ ������ �Ʒ� �������� matrix������Ʈ
        for (int a = 0; a < height; a++) {
            for (int b = 0; b < width; b++) {
                if (mat[a][b] == 0)  continue;
                top = 10000, left = 10000;
                if (a - 1 >= 0)  top = mat[a - 1][b];
                if (b - 1 >= 0)  left = mat[a][b - 1];
                mat[a][b] = min(top, left) + 1;
            }
        }
        //������ �Ʒ����� ���� �� �������� Ž�����ϸ� ������Ʈ�� ������ ���� ���� ���Ͽ� �� ���� ���� ���Ѵ�.
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