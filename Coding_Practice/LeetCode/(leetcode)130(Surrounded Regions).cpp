/*
���� ��ũ : https://leetcode.com/problems/surrounded-regions/
DFS�� �ذ��� �� �ִ� ������.

�ٱ������� 'O'�� ����� 'O'�� ������ �ʰ� �׷��� ���� ��� ������� �Ѵ�.

���� �ٱ��� 'O'�� ���� DFS�� ������ ������ 'O'�� �ִ��� Ž���Ͽ� �ش��ϴ� 'O'���� �ӽ÷� 'T'�� �ٲپ� �־���.

��� Ž���� ������ 'T'���� 'O'�� �ٲٰ�, 'O'���� 'X'�� �ٲٸ� �ȴ�.
*/
class Solution {
public:
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size(), nx, ny;
        for (int a = 0; a < m; a++) {   //����, ������ ���� 'O'�� ����� 'O'Ȯ��
            if (board[a][0] == 'O')  Search_Near(board, a, 0);
            if (board[a][n - 1] == 'O')  Search_Near(board, a, n - 1);
        }
        for (int a = 0; a < n; a++) {   //����, �Ʒ��� ���� 'O'�� ����� 'O'Ȯ��
            if (board[0][a] == 'O')  Search_Near(board, 0, a);
            if (board[m - 1][a] == 'O')  Search_Near(board, m - 1, a);
        }
        //Ž���� ���� �� ��� ���Ŀ� �°� ����
        for (int a = 0; a < m; a++) {   
            for (int b = 0; b < n; b++) {
                if (board[a][b] == 'T')  board[a][b] = 'O';
                else if (board[a][b] == 'O') board[a][b] = 'X';
            }
        }
    }

    void Search_Near(vector<vector<char>>& board, int x, int y) {
        int nx, ny, m = board.size(), n = board[0].size();
        board[x][y] = 'T';  
        for (int a = 0; a < 4; a++) {
            nx = x + dx[a];
            ny = y + dy[a];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O')  Search_Near(board, nx, ny);
        }
    }
};