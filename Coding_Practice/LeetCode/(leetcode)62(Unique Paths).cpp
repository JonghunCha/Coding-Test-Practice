/*
���� ��ũ : https://leetcode.com/problems/unique-paths/
������ DP������.

board�� �� ������ ������ �� �ִ� ����ũ�� ����� ������ answer[m][n]�� �����Ѵ�.

�� ������ ���� Ȥ�� ���ʿ����� ���� �����ϴٰ� �ߴ�.

���� board�� ���������� �Ʒ���, ���ʺ��� ���������� Ž���ϸ� answer�� ����ϸ� �ȴ�.
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int answer[m][n];
        //answer�ʱ�ȭ
        for (int a = 0; a < m; a++) {
            for (int b = 0; b < n; b++) {
                answer[a][b] = 0;
            }
        }
        answer[0][0] = 1;
        //������ �Ʒ���, ���ʺ��� ���������� answer���
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