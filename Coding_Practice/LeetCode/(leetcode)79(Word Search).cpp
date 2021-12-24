/*
문제 링크 : https://leetcode.com/problems/word-search/
DFS를 통해 해결할 수 있다.

우선 board에서 word[0]과 같은 칸을 찾는다.

그런 다음 해당 칸에서 인접한 칸 중에 word[1]과 같은 칸이 있는지 찾는다.

위 과정을 통해 word의 모든 문자를 찾아 냈다면 true를 반환하고, 중간에 한 문자라도 찾지 못한다면 false를 반환한다.

아래 코드를 보면 쉽게 이해할 수 있을 것이다.
*/
class Solution {
public:
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    bool exist(vector<vector<char>>& board, string word) {
        for (int a = 0; a < board.size(); a++) {
            for (int b = 0; b < board[0].size(); b++) {
                if (board[a][b] == word[0]) {   //word[0]과 같은 칸에서 시작
                    board[a][b] = '0';  //재방문을 방지하기 위해 board[a][b]를 word에 포함되지 않는 문자로 수정
                    if (Get_Answer(board, word, 1, a, b))   return true;
                    board[a][b] = word[0];
                }
            }
        }
        return false;
    }

    bool Get_Answer(vector<vector<char>>& board, string word, int index, int x, int y) {
        if (index >= word.size())    return true;   //word의 모든 문자를 찾았다는 의미로 true 반환
        int nx, ny;
        for (int a = 0; a < 4; a++) {   //인접한 4방향을 모두 살핀다
            nx = x + dx[a];
            ny = y + dy[a];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] == word[index]) {
                board[nx][ny] = '0';
                if (Get_Answer(board, word, index + 1, nx, ny)) return true;
                board[nx][ny] = word[index];
            }
        }
        return false;
    }
};