/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/77485
설명할 것이 없다.

단순히 문제에 주어진 조건에 따라 회전하고 최솟값을 추출하면 된다.
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int board[101][101], min, x1, x2, y1, y2, temp1, temp2;
    queue<int> q;
    //board값 초기화
    for (int a = 1; a <= rows; a++) {
        for (int b = 1; b <= columns; b++) {
            board[a][b] = (a - 1) * columns + b;
        }
    }
    //회전 실행
    for (int a = 0; a < queries.size(); a++) {
        min = 10001;
        x1 = queries[a][0];
        y1 = queries[a][1];
        x2 = queries[a][2];
        y2 = queries[a][3];
        //북, 동, 남, 서 순서로 각 수를 queue에 넣기
        for (int b = y1; b <= y2 - 1; b++)   q.push(board[x1][b]);
        for (int b = x1; b <= x2 - 1; b++)   q.push(board[b][y2]);
        for (int b = y2; b >= y1 + 1; b--)   q.push(board[x2][b]);
        for (int b = x2; b >= x1 + 1; b--)   q.push(board[b][y1]);
        //한 칸씩 이동한 상태로 queue에서 값 빼서 넣기(회전) 및 최솟값 갱신
        for (int b = y1 + 1; b <= y2; b++) {
            board[x1][b] = q.front();
            if (q.front() < min) min = q.front();
            q.pop();
        }
        for (int b = x1 + 1; b <= x2; b++) {
            board[b][y2] = q.front();
            if (q.front() < min) min = q.front();
            q.pop();
        }
        for (int b = y2 - 1; b >= y1; b--) {
            board[x2][b] = q.front();
            if (q.front() < min) min = q.front();
            q.pop();
        }
        for (int b = x2 - 1; b >= x1; b--) {
            board[b][y1] = q.front();
            if (q.front() < min) min = q.front();
            q.pop();
        }

        answer.push_back(min);
    }

    return answer;
}