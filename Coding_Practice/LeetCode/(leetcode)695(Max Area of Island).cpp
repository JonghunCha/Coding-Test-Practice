/*
문제 링크 : https://leetcode.com/problems/max-area-of-island/
DFS로 해결할 수 있는 문제다.

grid의 전체 영역을 탐색하다 1인 부분이 발견되면 인접한 4 방향을 탐색한다.

탐색한 부분이 또 1인경우 해당 장소에서 인접한 방향으로 탐색을 진행한다.(더 이상 1인 지역이 없을때까지)
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
        grid[x][y] = 0; //탐색을 마친 지역은 0으로 만들어 다시 탐색하는 일이 없도록 한다
        for (int a = 0; a < 4; a++) {
            nx = x + dx[a];
            ny = y + dy[a];
            if (nx >= 0 && nx < height && ny >= 0 && ny < width && grid[nx][ny] == 1)    ret += Search_Near(grid, nx, ny, height, width);
        }
        return ret;
    }
};