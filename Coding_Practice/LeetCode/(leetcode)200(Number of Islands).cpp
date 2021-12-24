/*
���� ��ũ : https://leetcode.com/problems/number-of-islands/
DFS�� �ذ��� �� �ִ� ������.

grid�� ���Ǹ� ���� ������ ������ ���� ������ 1 �÷��ش�.

�׷� ���� �ش� ������ 4������ ���Ǹ� ���� ���� ������ �ִٸ� '0'���� �ٲ��ش�.

�� ������ ���� ������ �� �ȳ��� ������ �ݺ��ϸ� �ȴ�.
*/
class Solution {
public:
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    int island_num = 0;

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        //grid�� ��� �������� ���ο� �������� �ִ��� Ȯ��
        for (int a = 0; a < m; a++) {
            for (int b = 0; b < n; b++) {
                if (grid[a][b] == '1') {
                    island_num++;
                    grid[a][b] = '0';
                    Search_Near(grid, a, b, m, n);
                }
            }
        }

        return island_num;
    }
    //x, y������ ���� ���� Ȯ�� �Ǿ��� �� ȣ��Ǹ�, ��ó�� ���� ���� ������ Ž���ϸ� '0'���� �ٲ��ش�
    void Search_Near(vector<vector<char>>& grid, int x, int y, int m, int n) {
        int nx, ny;
        for (int a = 0; a < 4; a++) {
            nx = x + dx[a];
            ny = y + dy[a];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                grid[nx][ny] = '0';
                Search_Near(grid, nx, ny, m, n);
            }
        }
    }
};