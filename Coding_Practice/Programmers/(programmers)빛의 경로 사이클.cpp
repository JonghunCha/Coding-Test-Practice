/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/86052
완전 탐색을 통해 해결할 수 있는 문제다.

각 격자에서는 4방향으로 빛이 이동할 수 있다.

또한 각 격자는 빛이 들어온 방향에 따라 빛이 이동하는 경로는 고정되어 있다.

이 점을 이용하면 독립적인 사이클을 찾을 수 있다.

각 격자마다 4개의 방향에 대해 이동한 적이 있는지를 마킹하는 변수를 두고, 만약 이미 지나갔던 경로라면 해당 경로를 통하는 사이클은 계산이 되었음을 알 수 있다.

따라서 모든 격자의 4가지 방향이 모두 지나간적이 있다면 모든 사이클을 찾았다고 할 수 있다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//index의 순서에 따라 북 동 남 서
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int visited[500][500][4], row = grid.size(), col = grid[0].size();
    int x, y, direction, count;
    //visited[a][b][c]는 a, b격자에서 c방향으로 빛이 이동한적 있는지를 저장
    for (int a = 0; a < row; a++) {
        for (int b = 0; b < col; b++) {
            for (int c = 0; c < 4; c++) {
                visited[a][b][c] = 0;
            }
        }
    }
    //가능한 모든 빛의 이동 경로를 탐색
    for (int a = 0; a < row; a++) {
        for (int b = 0; b < col; b++) {
            for (int c = 0; c < 4; c++) {
                if (visited[a][b][c] == 0) {    //아직 빛이 지나간적 없는 경로만 새로운 사이클의 후보가 될 수 있음
                    count = 0;
                    x = a;
                    y = b;
                    direction = c;
                    while (visited[x][y][direction] == 0) {
                        count++;
                        visited[x][y][direction] = 1;   //빛이 지나간 경로임을 마킹
                        //다음 격자의 x, y좌표 계산
                        x = x + dx[direction];  
                        if (x < 0)   x = row - 1;
                        if (x >= row)    x = 0;
                        if (y < 0)   y = col - 1;
                        if (y >= col)    y = 0;
                        //다음 격자에서의 이동방향 계산
                        if (grid[x][y] == 'L') {
                            if (direction == 0)  direction = 3;
                            else    direction = direction - 1;
                        }
                        else if (grid[x][y] == 'R')  direction = (direction + 1) % 4;
                        //만약 빛이 시작한 경로로 돌아온다면 사이클이 완성되었음을 의미
                        if (x == a && y == b && direction == c) {
                            answer.push_back(count);
                            break;
                        }
                    }
                }
            }
        }
    }
    //오름차순으로 정렬
    sort(answer.begin(), answer.end());

    return answer;
}