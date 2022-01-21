/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/17679
����Ž������ �ذ��ϸ� �Ǵ� ������.

�ڵ带 ���� ���� ������ �� ���� ���̴�.
*/
#include <string>
#include <vector>

using namespace std;

int answer;

bool remove(int m, int n, vector<string>& board);

int solution(int m, int n, vector<string> board) {
    answer = 0;
    //���ŵǴ� ����� �ִ� ������ �ݺ�
    bool is_removed = remove(m, n, board);
    while (is_removed) {
        is_removed = remove(m, n, board);
    }

    return answer;
}

bool remove(int m, int n, vector<string>& board) {
    int removed_block[30][30];
    bool is_removed = false;
    //���ŵ� ����� ��Ÿ���� removed_block �ʱ�ȭ
    for (int a = 0; a < m; a++) {
        for (int b = 0; b < n; b++) {
            removed_block[a][b] = 0;
        }
    }
    //�������� ��ǥ ǥ��
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
    //board���� �������� ����� 0���� ���� + answer�� �����ֱ�
    for (int a = 0; a < m; a++) {
        for (int b = 0; b < n; b++) {
            if (removed_block[a][b] == 1) {
                board[a][b] = 0;
                answer++;
                is_removed = true;
            }
        }
    }
    //�������� �� ����� ������ ���ܼ� ä���
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