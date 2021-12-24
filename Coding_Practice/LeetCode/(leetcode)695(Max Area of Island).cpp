/*
���� ��ũ : https://leetcode.com/problems/max-area-of-island/
DFS�� �ذ��� �� �ִ� ������.

grid�� ��ü ������ Ž���ϴ� 1�� �κ��� �߰ߵǸ� ������ 4 ������ Ž���Ѵ�.

Ž���� �κ��� �� 1�ΰ�� �ش� ��ҿ��� ������ �������� Ž���� �����Ѵ�.(�� �̻� 1�� ������ ����������)
*/
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int height = grid.size(), width = grid[0].size(), answer = 0, temp;

        for (int a = 0; a < height; a++) {
            for (int b = 0; b < width; b++) {
                if (grid[a][b] == 1) {
                    temp = Search_Near(grid, a, b, height, width);
                    if (temp > answer)   answer = temp;
                }
            }
        }
        return answer;
    }

    int Search_Near(vector<vector<int>>& grid, int x, int y, int height, int width) {
        int nx, ny, ret = 1;
        grid[x][y] = 0; //Ž���� ��ģ ������ 0���� ����� �ٽ� Ž���ϴ� ���� ������ �Ѵ�
        for (int a = 0; a < 4; a++) {
            nx = x + dx[a];
            ny = y + dy[a];
            if (nx >= 0 && nx < height && ny >= 0 && ny < width && grid[nx][ny] == 1)    ret += Search_Near(grid, nx, ny, height, width);
        }
        return ret;
    }
};