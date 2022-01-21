/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/17679
완전탐색으로 해결하면 되는 문제다.

코드를 보면 쉽게 이해할 수 있을 것이다.
*/
#include <string>
#include <vector>

using namespace std;

int answer;

bool remove(int m, int n, vector<string>& board);

int solution(int m, int n, vector<string> board) {
    answer = 0;
    //제거되는 블록이 있는 경우까지 반복
    bool is_removed = remove(m, n, board);
    while (is_removed) {
        is_removed = remove(m, n, board);
    }

    return answer;
}

bool remove(int m, int n, vector<string>& board) {
    int removed_block[30][30];
    bool is_removed = false;
    //제거될 블록을 나타내는 removed_block 초기화
    for (int a = 0; a < m; a++) {
        for (int b = 0; b < n; b++) {
            removed_block[a][b] = 0;
        }
    }
    //지워지는 좌표 표시
    for (int a = 0; a < m - 1; a++) {
        for (int b = 0; b < n - 1; b++) {
            if (board[a][b] != 0 && board[a][b] == board[a + 1][b] && board[a][b] == board[a][b + 1] && board[a][b] == board[a + 1][b + 1]) {
                removed_block[a][b] = 1;
                removed_block[a][b + 1] = 1;
                removed_block[a + 1][b] = 1;
                removed_block[a + 1][b + 1] = 1;
            }
        }
    }
    //board에서 지워지는 블록을 0으로 설정 + answer값 높여주기
    for (int a = 0; a < m; a++) {
        for (int b = 0; b < n; b++) {
            if (removed_block[a][b] == 1) {
                board[a][b] = 0;
                answer++;
                is_removed = true;
            }
        }
    }
    //지워져서 빈 블록을 위에서 땡겨서 채운다
    for (int a = 0; a < n; a++) {
        for (int b = m - 1; b >= 0; b--) {
            if (board[b][a] == 0) {
                for (int c = b - 1; c >= 0; c--) {
                    if (board[c][a] != 0) {
                        board[b][a] = board[c][a];
                        board[c][a] = 0;
                        break;
                    }
                }
            }
        }
    }

    return is_removed;
}