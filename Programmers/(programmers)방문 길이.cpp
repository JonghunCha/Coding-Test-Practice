/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/49994
좌표 평면의 크기가 작기에 모든 경로에 대해 지나간적이 있는지 나타내는 변수를 두면 쉽게 해결할 수 있다.

또한 편의를 위해 모든 x, y좌표를 5씩 더해주었다.(ex. -5, -5 -> 0, 0)
*/
#include <string>
#include <cstring>
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int visited[11][11][11][11];

int solution(string dirs) {
    int answer = 0, x = 5, y = 5, nx, ny;
    //visited초기화
    memset(visited, 0, 14641);

    for (int a = 0; a < dirs.size(); a++) {
        //각 방향에 따른 다음 좌표 nx, ny 계산
        if (dirs[a] == 'U') {
            nx = x + dx[0];
            ny = y + dy[0];
        }
        else if (dirs[a] == 'D') {
            nx = x + dx[1];
            ny = y + dy[1];
        }
        else if (dirs[a] == 'R') {
            nx = x + dx[2];
            ny = y + dy[2];
        }
        else {
            nx = x + dx[3];
            ny = y + dy[3];
        }
        //만약 유효하지 않은 좌표라면 다음 명령어 수행
        if (nx < 0 || nx > 10 || ny < 0 || ny > 10)  continue;
        //(x, y)와 (nx, ny)사이의 경로를 지나간 적이 없다면 answer++하고, 해당 경로를 지나간 것으로 표시
        if (visited[x][y][nx][ny] == 0) {
            answer++;
            visited[x][y][nx][ny] = 1;
            visited[nx][ny][x][y] = 1;
        }
        //x, y 갱신
        x = nx;
        y = ny;
    }

    return answer;
}