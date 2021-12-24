/*
문제 링크 : https://leetcode.com/problems/flood-fill/
DFS로 해결할 수 있는 문제다.

예외 사항으로는 주어진 시작 좌표의 색과 새로운 색이 같은 경우인데, 이 경우엔 처음 image와 달라지는 것이 없기에 아무것도 하지 않는다.

그 외에는 주어진 좌표부터 인접한 4방향에 대해 기존의 색깔이 같은지 확인하고 같다면 그 방향의 좌표에서도 똑같이 4방향에 대해 Spread를 호출한다.
*/
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int nx, ny, width = image[0].size(), height = image.size(), currColor = image[sr][sc];
        if (currColor != newColor)   Spread(image, sr, sc, currColor, newColor, width, height);
        return image;
    }

    void Spread(vector<vector<int>>& image, int r, int c, int currColor, int newColor, int width, int height) {
        int nx, ny;
        image[r][c] = newColor;
        for (int a = 0; a < 4; a++) {
            nx = r + dx[a];
            ny = c + dy[a];
            //해당 좌표가 image내부에 있고, 색깔이 기존 시작 좌표의 색깔과 같은 경우에 Spread 호출
            if (nx >= 0 && nx < height && ny >= 0 && ny < width && image[nx][ny] == currColor) {
                Spread(image, nx, ny, currColor, newColor, width, height);
            }
        }
    }

};