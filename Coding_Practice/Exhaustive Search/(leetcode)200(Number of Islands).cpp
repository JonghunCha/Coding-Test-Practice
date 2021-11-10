/*
문제 링크 : https://leetcode.com/problems/number-of-islands/
DFS로 해결할 수 있는 문제다.

grid를 살피며 섬인 지역이 나오면 섬의 갯수를 1 올려준다.

그런 다음 해당 지역의 4방향을 살피며 만약 섬인 지역이 있다면 '0'으로 바꿔준다.

이 과정을 섬인 지역이 더 안나올 때까지 반복하면 된다.
*/
class Solution {
public:
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    int island_num = 0;

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        //grid의 모든 지역에서 새로운 섬지역이 있는지 확인
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
    //x, y지역이 섬인 것이 확인 되었을 때 호출되며, 근처에 같은 섬인 지역을 탐색하며 '0'으로 바꿔준다
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