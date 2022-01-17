/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/64061
���� ��뿡 ���� ���� ������ ���̵��� ���� ������.

ũ������ �̴� ������� ���ÿ� �־��ִ�, ������ top�� ���� �ִ� ������ ���ٸ� ������ �����ϰ� ���ÿ� 1�� pop()�ϸ� �ȴ�.
*/
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, curr_doll;
    stack<int> basket;

    for (int a = 0; a < moves.size(); a++) {
        for (int b = 0; b < board.size(); b++) {
            if (board[b][moves[a] - 1] != 0) {  //������ �߰��� ���
                curr_doll = board[b][moves[a] - 1];
                if (!basket.empty() && basket.top() == curr_doll) { //���� ���� ������ ������ ���ÿ� �� ������ ���� ���
                    answer += 2;
                    basket.pop();
                }
                else {  //�̿��� ���
                    basket.push(curr_doll);
                }
                board[b][moves[a] - 1] = 0;
                break;
            }
        }
    }

    return answer;
}