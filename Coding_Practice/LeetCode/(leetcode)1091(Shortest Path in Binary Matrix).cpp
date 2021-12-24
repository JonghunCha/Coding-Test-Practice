/*
���� ��ũ : https://leetcode.com/problems/shortest-path-in-binary-matrix/
BFS�� �ذ��� �� �ִ� ������.

0, 0���� �����ؼ� �̵��� �� �ִ� ������ queue�� �ִ´�.

�׷� ���� queue���� �ϳ��� pop()�ϸ� �湮���� ���� ������ ������ ����ؼ� queue�� �־��ش�.

���� n-1, n-1�� �����Ѵٸ� �ִ� ��θ� ���� ���̰�, queue�� �� ���°� �� ������ n-1, n-1�� �������� ���ϸ� -1�� ��ȯ�Ѵ�.
*/
class Solution {
public:
    int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int answer = 300;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1; //���ۺ��� 0�� �ƴ� ��� -1 ��ȯ
        queue<tuple<int, int, int>> q;  
        int n = grid.size(), x, y, count, nx, ny;
        q.push(make_tuple(0, 0, 1));    //�������� queue�� ����
        grid[0][0] = 1; //0, 0�� �湮�Ͽ��⿡ 1�� ����

        while (!q.empty()) {
            x = get<0>(q.front());
            y = get<1>(q.front());
            count = get<2>(q.front());
            if (x == n - 1 && y == n - 1) {  //��ǥ������ ������ ��� while�� ����
                answer = count;
                break;
            }
            q.pop();
            for (int a = 0; a < 8; a++) {   //������ �ٸ����� BFS�� Ž��
                nx = x + dx[a];
                ny = y + dy[a];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    q.push(make_tuple(nx, ny, count + 1));
                    grid[nx][ny] = 1;
                }
            }
        }

        if (answer == 300)   return -1;
        else    return answer;
    }
};