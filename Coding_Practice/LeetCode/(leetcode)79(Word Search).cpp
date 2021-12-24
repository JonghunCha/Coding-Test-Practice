/*
���� ��ũ : https://leetcode.com/problems/word-search/
DFS�� ���� �ذ��� �� �ִ�.

�켱 board���� word[0]�� ���� ĭ�� ã�´�.

�׷� ���� �ش� ĭ���� ������ ĭ �߿� word[1]�� ���� ĭ�� �ִ��� ã�´�.

�� ������ ���� word�� ��� ���ڸ� ã�� �´ٸ� true�� ��ȯ�ϰ�, �߰��� �� ���ڶ� ã�� ���Ѵٸ� false�� ��ȯ�Ѵ�.

�Ʒ� �ڵ带 ���� ���� ������ �� ���� ���̴�.
*/
class Solution {
public:
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    bool exist(vector<vector<char>>& board, string word) {
        for (int a = 0; a < board.size(); a++) {
            for (int b = 0; b < board[0].size(); b++) {
                if (board[a][b] == word[0]) {   //word[0]�� ���� ĭ���� ����
                    board[a][b] = '0';  //��湮�� �����ϱ� ���� board[a][b]�� word�� ���Ե��� �ʴ� ���ڷ� ����
                    if (Get_Answer(board, word, 1, a, b))   return true;
                    board[a][b] = word[0];
                }
            }
        }
        return false;
    }

    bool Get_Answer(vector<vector<char>>& board, string word, int index, int x, int y) {
        if (index >= word.size())    return true;   //word�� ��� ���ڸ� ã�Ҵٴ� �ǹ̷� true ��ȯ
        int nx, ny;
        for (int a = 0; a < 4; a++) {   //������ 4������ ��� ���ɴ�
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