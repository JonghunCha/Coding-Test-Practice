/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/64061
스택 사용에 대해 묻는 문제로 난이도가 낮은 문제다.

크레인이 뽑는 순서대로 스택에 넣어주다, 스택의 top과 새로 넣는 인형이 같다면 정답을 갱신하고 스택에 1번 pop()하면 된다.
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
            if (board[b][moves[a] - 1] != 0) {  //인형을 발견한 경우
                curr_doll = board[b][moves[a] - 1];
                if (!basket.empty() && basket.top() == curr_doll) { //만약 현재 인형과 직전에 스택에 들어간 인형이 같은 경우
                    answer += 2;
                    basket.pop();
                }
                else {  //이외의 경우
                    basket.push(curr_doll);
                }
                board[b][moves[a] - 1] = 0;
                break;
            }
        }
    }

    return answer;
}