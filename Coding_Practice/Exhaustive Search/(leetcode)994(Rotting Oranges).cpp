/*
문제 링크 : https://leetcode.com/problems/rotting-oranges/
BFS의 가장 기초적인 문제로 볼 수 있다.

아래 코드를 보면 어떤 의미인지 금방 이해할 수 있을 것이다.
*/
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int answer = 0, height = grid.size(), width = grid[0].size(), x, y, nx, ny;
        bool isAllrotten, isAnychange;  //각각 모든 오렌지가 썩었는지, 썩은 오렌지의 전파가 일어났는지를 의미
        queue<pair<int, int>> q;    //썩은 오렌지의 좌표값 저장 큐

        while (1) {
            isAllrotten = true;
            for (int a = 0; a < height; a++) {
                for (int b = 0; b < width; b++) {
                    if (grid[a][b] == 1) isAllrotten = false;   //아직 썩지 않은 오렌지 존재
                    else if (grid[a][b] == 2) { //썩은 오렌지가 있다면 큐에 추가
                        q.push(make_pair(a, b));
                    }
                }
            }
            if (isAllrotten) break; //전부 다 썩었다면 while문 종료

            isAnychange = false;
            while (!q.empty()) {
                x = q.front().first;
                y = q.front().second;
                grid[x][y] = 3; //썩은 오렌지 재방문을 막기 위해 3으로 바꿈
                q.pop();    
                for (int a = 0; a < 4; a++) {
                    nx = x + dx[a];
                    ny = y + dy[a];
                    //인근에 싱싱한 오렌지가 있는 경우
                    if (nx >= 0 && nx < height && ny >= 0 && ny < width && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;   
                        isAnychange = true;
                    }
                }
            }
            if (!isAnychange)    return -1; //아무런 변화도 없었다면 모두 썩게 만들기가 불가능한 경우
            answer++;
        }
        return answer;
    }
};