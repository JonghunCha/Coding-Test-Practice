/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42894#
완전 탐색으로 해결할 수 있는 문제다.

문제의 블록 제거 조건에 대한 설명이 조금 부족하지만 12가지 모양의 블록에서 2개의 칸을 추가해서 제거할 수 있는 경우만 제거 가능하다고 풀었더니 해결되었다.

우선 12개의 블록 중 제거할 수 있는 블록은 5개이다. 나머지는 어떠한 경우에도 제거할 수 없다.

따라서 5개의 블록에 대해서 빈 칸을 채울 수 있는 경우 해당 블록을 제거한다.

위 과정을 더 이상 제거할 블록이 없을 때까지 반복하면 된다.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer;
bool can_eliminate(vector<vector<int>>& board); //board에서 제거할 블록이 있다면 제거하고 true를, 없다면 false반환

int solution(vector<vector<int>> board) {
    answer = 0;

    while (1) {
        if (!can_eliminate(board))   break;
    }

    return answer;
}

bool can_eliminate(vector<vector<int>>& board) {
    int width = board[0].size(), height = board.size(), val;
    //문제의 1-4블록, 2-2블록을 제거할 수 있는지 확인
    for (int a = 0; a < width; a++) {
        if (board[0][a] != 0 || board[1][a] != 0)    continue;

        for (int b = 0; b < height; b++) {
            if (board[b][a] != 0) {
                val = board[b][a];
                if (a + 1 < width && board[b][a + 1] == val && board[b - 1][a + 1] == val && board[b - 2][a + 1] == val) {  //1-4블록 제거
                    board[b][a] = 0;
                    board[b][a + 1] = 0;
                    board[b - 1][a + 1] = 0;
                    board[b - 2][a + 1] = 0;
                    answer++;
                    return true;
                }
                else if (a - 1 >= 0 && board[b][a - 1] == val && board[b - 1][a - 1] == val && board[b - 2][a - 1] == val) {    //2-2블록 제거
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
    //문제의 1-3블록, 2-3블록을 제거할 수 있는지 확인
    for (int a = 0; a < width - 1; a++) {
        if (board[0][a] != 0 || board[0][a + 1] != 0)    continue;

        for (int b = 0; b < height; b++) {
            if (board[b][a] != 0 && board[b][a + 1] != 0) {
                val = board[b][a];
                if (a + 2 < width && board[b][a + 1] == val && board[b][a + 2] == val && board[b - 1][a + 2] == val) {  //2-3블록 제거
                    board[b][a] = 0;
                    board[b][a + 1] = 0;
                    board[b][a + 2] = 0;
                    board[b - 1][a + 2] = 0;
                    answer++;
                    return true;
                }
                else if (a - 1 >= 0 && board[b - 1][a - 1] == val && board[b][a - 1] == val && board[b][a + 1] == val) {    //1-3블록 제거
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
    //문제의 3-1블록을 제거할 수 있는지 확인
    for (int a = 0; a < width - 2; a++) {
        if (board[0][a] != 0 || board[0][a + 2] != 0)    continue;

        for (int b = 0; b < height; b++) {
            if (board[b][a] != 0 && board[b][a + 2] != 0) {
                val = board[b][a];
                if (board[b - 1][a + 1] == val && board[b][a + 1] == val && board[b][a + 2] == val) {   //3-1블록 제거
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