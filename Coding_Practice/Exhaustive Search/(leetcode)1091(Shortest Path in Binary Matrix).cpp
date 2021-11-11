/*
문제 링크 : https://leetcode.com/problems/shortest-path-in-binary-matrix/
BFS로 해결할 수 있는 문제다.

0, 0부터 시작해서 이동할 수 있는 지역을 queue에 넣는다.

그런 다음 queue에서 하나씩 pop()하며 방문하지 않은 인접한 지역을 계속해서 queue에 넣어준다.

만약 n-1, n-1에 도달한다면 최단 경로를 얻은 것이고, queue가 빈 상태가 될 때까지 n-1, n-1에 도달하지 못하면 -1을 반환한다.
*/
class Solution {
public:
    int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int answer = 300;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1; //시작부터 0이 아닌 경우 -1 반환
        queue<tuple<int, int, int>> q;  
        int n = grid.size(), x, y, count, nx, ny;
        q.push(make_tuple(0, 0, 1));    //시작지점 queue에 삽입
        grid[0][0] = 1; //0, 0은 방문하였기에 1로 설정

        while (!q.empty()) {
            x = get<0>(q.front());
            y = get<1>(q.front());
            count = get<2>(q.front());
            if (x == n - 1 && y == n - 1) {  //목표지점에 도달한 경우 while문 종료
                answer = count;
                break;
            }
            q.pop();
            for (int a = 0; a < 8; a++) {   //인접한 다른지역 BFS로 탐색
                nx = x + dx[a];
                ny = y + dy[a];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    q.push(make_tuple(nx, ny, count + 1));
                    grid[nx][ny] = 1;
                }
            }
        }

        if (answer == 300)   return -1;
        else    return answer;
    }
};