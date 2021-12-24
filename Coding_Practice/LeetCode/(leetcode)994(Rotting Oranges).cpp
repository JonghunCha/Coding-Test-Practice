/*
���� ��ũ : https://leetcode.com/problems/rotting-oranges/
BFS�� ���� �������� ������ �� �� �ִ�.

�Ʒ� �ڵ带 ���� � �ǹ����� �ݹ� ������ �� ���� ���̴�.
*/
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int answer = 0, height = grid.size(), width = grid[0].size(), x, y, nx, ny;
        bool isAllrotten, isAnychange;  //���� ��� �������� �������, ���� �������� ���İ� �Ͼ������ �ǹ�
        queue<pair<int, int>> q;    //���� �������� ��ǥ�� ���� ť

        while (1) {
            isAllrotten = true;
            for (int a = 0; a < height; a++) {
                for (int b = 0; b < width; b++) {
                    if (grid[a][b] == 1) isAllrotten = false;   //���� ���� ���� ������ ����
                    else if (grid[a][b] == 2) { //���� �������� �ִٸ� ť�� �߰�
                        q.push(make_pair(a, b));
                    }
                }
            }
            if (isAllrotten) break; //���� �� ����ٸ� while�� ����

            isAnychange = false;
            while (!q.empty()) {
                x = q.front().first;
                y = q.front().second;
                grid[x][y] = 3; //���� ������ ��湮�� ���� ���� 3���� �ٲ�
                q.pop();    
                for (int a = 0; a < 4; a++) {
                    nx = x + dx[a];
                    ny = y + dy[a];
                    //�αٿ� �̽��� �������� �ִ� ���
                    if (nx >= 0 && nx < height && ny >= 0 && ny < width && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;   
                        isAnychange = true;
                    }
                }
            }
            if (!isAnychange)    return -1; //�ƹ��� ��ȭ�� �����ٸ� ��� ��� ����Ⱑ �Ұ����� ���
            answer++;
        }
        return answer;
    }
};