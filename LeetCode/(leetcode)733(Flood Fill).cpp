/*
���� ��ũ : https://leetcode.com/problems/flood-fill/
DFS�� �ذ��� �� �ִ� ������.

���� �������δ� �־��� ���� ��ǥ�� ���� ���ο� ���� ���� ����ε�, �� ��쿣 ó�� image�� �޶����� ���� ���⿡ �ƹ��͵� ���� �ʴ´�.

�� �ܿ��� �־��� ��ǥ���� ������ 4���⿡ ���� ������ ������ ������ Ȯ���ϰ� ���ٸ� �� ������ ��ǥ������ �Ȱ��� 4���⿡ ���� Spread�� ȣ���Ѵ�.
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
            //�ش� ��ǥ�� image���ο� �ְ�, ������ ���� ���� ��ǥ�� ����� ���� ��쿡 Spread ȣ��
            if (nx >= 0 && nx < height && ny >= 0 && ny < width && image[nx][ny] == currColor) {
                Spread(image, nx, ny, currColor, newColor, width, height);
            }
        }
    }

};