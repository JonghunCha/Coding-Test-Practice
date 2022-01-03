/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/1844
BFS로 해결할 수 있는 문제다.

구해야 하는 값은 최단 거리이다.

따라서 BFS를 통해 이동 거리를 1씩 늘려나가며 목적지에 도달하는 경우 이동한 칸을 반환하면 된다.
*/
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int solution(vector<vector<int>> maps)
{
    int height = maps.size(), width = maps[0].size(), x, y, nx, ny, count;
    bool visited[100][100];
    queue<tuple<int, int, int>> q;
    //방문 여부를 나타내는 변수 초기화
    for (int a = 0; a < height; a++) {
        for (int b = 0; b < width; b++) {
            visited[a][b] = false;
        }
    }
    //시작 지점 큐에 넣기
    visited[0][0] = true;
    q.push(make_tuple(0, 0, 1));
    //더 이상 이동할 공간이 없을 때까지 반복
    while (!q.empty()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        count = get<2>(q.front());
        q.pop();
        //만약 목적지에 도달한 경우 정답 반환
        if (x == height - 1 && y == width - 1)   return count;
        //인접한 4방향에 대해 이동할 수 있는 공간이면 큐에 넣는다
        for (int a = 0; a < 4; a++) {
            nx = x + dx[a];
            ny = y + dy[a];
            if (nx >= 0 && nx < height && ny >= 0 && ny < width && visited[nx][ny] == false && maps[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push(make_tuple(nx, ny, count + 1));
            }
        }
    }

    return -1;
}