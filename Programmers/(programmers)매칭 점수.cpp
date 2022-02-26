/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42894#
���� Ž������ �ذ��� �� �ִ� ������.

������ ��� ���� ���ǿ� ���� ������ ���� ���������� 12���� ����� ��Ͽ��� 2���� ĭ�� �߰��ؼ� ������ �� �ִ� ��츸 ���� �����ϴٰ� Ǯ������ �ذ�Ǿ���.

�켱 12���� ��� �� ������ �� �ִ� ����� 5���̴�. �������� ��� ��쿡�� ������ �� ����.

���� 5���� ��Ͽ� ���ؼ� �� ĭ�� ä�� �� �ִ� ��� �ش� ����� �����Ѵ�.

�� ������ �� �̻� ������ ����� ���� ������ �ݺ��ϸ� �ȴ�.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer;
bool can_eliminate(vector<vector<int>>& board); //board���� ������ ����� �ִٸ� �����ϰ� true��, ���ٸ� false��ȯ

int solution(vector<vector<int>> board) {
    answer = 0;

    while (1) {
        if (!can_eliminate(board))   break;
    }

    return answer;
}

bool can_eliminate(vector<vector<int>>& board) {
    int width = board[0].size(), height = board.size(), val;
    //������ 1-4���, 2-2����� ������ �� �ִ��� Ȯ��
    for (int a = 0; a < width; a++) {
        if (board[0][a] != 0 || board[1][a] != 0)    continue;

        for (int b = 0; b < height; b++) {
            if (board[b][a] != 0) {
                val = board[b][a];
                if (a + 1 < width && board[b][a + 1] == val && board[b - 1][a + 1] == val && board[b - 2][a + 1] == val) {  //1-4��� ����
                    board[b][a] = 0;
                    board[b][a + 1] = 0;
                    board[b - 1][a + 1] = 0;
                    board[b - 2][a + 1] = 0;
                    answer++;
                    return true;
                }
                else if (a - 1 >= 0 && board[b][a - 1] == val && board[b - 1][a - 1] == val && board[b - 2][a - 1] == val) {    //2-2��� ����
                    board[b][a] = 0;
                    board[b][a - 1] = 0;
                    board[b - 1][a - 1] = 0;
                    board[b - 2][a - 1] = 0;
                    answer++;
                    return true;
                }
                break;
            }
        }
    }
    //������ 1-3���, 2-3����� ������ �� �ִ��� Ȯ��
    for (int a = 0; a < width - 1; a++) {
        if (board[0][a] != 0 || board[0][a + 1] != 0)    continue;

        for (int b = 0; b < height; b++) {
            if (board[b][a] != 0 && board[b][a + 1] != 0) {
                val = board[b][a];
                if (a + 2 < width && board[b][a + 1] == val && board[b][a + 2] == val && board[b - 1][a + 2] == val) {  //2-3��� ����
                    board[b][a] = 0;
                    board[b][a + 1] = 0;
                    board[b][a + 2] = 0;
                    board[b - 1][a + 2] = 0;
                    answer++;
                    return true;
                }
                else if (a - 1 >= 0 && board[b - 1][a - 1] == val && board[b][a - 1] == val && board[b][a + 1] == val) {    //1-3��� ����
                    board[b][a] = 0;
                    board[b - 1][a - 1] = 0;
                    board[b][a - 1] = 0;
                    board[b][a + 1] = 0;
                    answer++;
                    return true;
                }
                break;

            }
            else if ((board[b][a] != 0 && board[b][a + 1] == 0) || (board[b][a] == 0 && board[b][a + 1] != 0)) {
                break;
            }
        }
    }
    //������ 3-1����� ������ �� �ִ��� Ȯ��
    for (int a = 0; a < width - 2; a++) {
        if (board[0][a] != 0 || board[0][a + 2] != 0)    continue;

        for (int b = 0; b < height; b++) {
            if (board[b][a] != 0 && board[b][a + 2] != 0) {
                val = board[b][a];
                if (board[b - 1][a + 1] == val && board[b][a + 1] == val && board[b][a + 2] == val) {   //3-1��� ����
                    board[b - 1][a + 1] = 0;
                    board[b][a] = 0;
                    board[b][a + 1] = 0;
                    board[b][a + 2] = 0;
                    answer++;
                    return true;
                }
                break;
            }
            else if ((board[b][a] != 0 && board[b][a + 2] == 0) || (board[b][a] == 0 && board[b][a + 2] != 0)) {
                break;
            }
        }
    }

    return false;
}