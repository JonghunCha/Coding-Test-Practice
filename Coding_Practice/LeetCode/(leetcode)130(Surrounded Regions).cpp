/*
문제 링크 : https://leetcode.com/problems/surrounded-regions/
DFS로 해결할 수 있는 문제다.

바깥라인의 'O'와 연결된 'O'는 뒤집지 않고 그렇지 않은 경우 뒤집어야 한다.

따라서 바깥쪽 'O'에 대해 DFS로 인접한 지역에 'O'가 있는지 탐색하여 해당하는 'O'들은 임시로 'T'로 바꾸어 주었다.

모든 탐색이 끝나면 'T'들은 'O'로 바꾸고, 'O'들은 'X'로 바꾸면 된다.
*/
class Solution {
public:
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size(), nx, ny;
        for (int a = 0; a < m; a++) {   //왼쪽, 오른쪽 변의 'O'와 연결된 'O'확인
            if (board[a][0] == 'O')  Search_Near(board, a, 0);
            if (board[a][n - 1] == 'O')  Search_Near(board, a, n - 1);
        }
        for (int a = 0; a < n; a++) {   //위쪽, 아래쪽 변의 'O'와 연결된 'O'확인
            if (board[0][a] == 'O')  Search_Near(board, 0, a);
            if (board[m - 1][a] == 'O')  Search_Near(board, m - 1, a);
        }
        //탐색이 끝난 후 출력 형식에 맞게 수정
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