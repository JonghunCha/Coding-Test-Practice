/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/86971
완전 탐색으로 해결할 수 있는 문제다.

첫 번째 단계로 모든 전선들을 하나씩 끊는 방법으로 완전 탐색을 진행한다.

두 번째 세부 단계로(전선을 끊은 후) 하나의 전력망 네트워크에 몇 개의 송전탑이 있는지를 확인해야 한다.

이 부분은 BFS를 통해 하나의 네트워크에 몇 개의 송전탑이 있는지를 알아낼 수 있다.

이제 두 전력망 네트워크 사이의 송전탑 갯수 차이를 계산하고 첫 번째 완전탐색을 진행하며 최솟값을 갱신하면 된다.
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int answer = 100;

int get_diff(int n, int connected[101][101]);

int solution(int n, vector<vector<int>> wires) {
    int connected[101][101], diff;
    //송전탑 사이의 연결을 저장하는 connected 초기화
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            connected[a][b] = 0;
        }
    }
    //서로 연결된 송전탑의 connected를 1로 설정
    for (int a = 0; a < wires.size(); a++) {
        connected[wires[a][0]][wires[a][1]] = 1;
        connected[wires[a][1]][wires[a][0]] = 1;
    }
    //모든 전선에 대해 해당 전선을 끊었을 때 송전탑 갯수의 차이를 계산하고 정답은 최솟값으로 유지
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (connected[a][b] == 1) {
                connected[a][b] = 0;
                connected[b][a] = 0;
                diff = get_diff(n, connected);
                if (diff < answer)   answer = diff;
                connected[a][b] = 1;
                connected[b][a] = 1;
            }
        }
    }

    return answer;
}

int get_diff(int n, int connected[101][101]) {
    int visited[101], num = 0;
    queue<int> q;
    //해당 송전탑에 방문했는지 나타내는 visited 초기화
    for (int a = 1; a <= n; a++) visited[a] = 0;
    //1번 송전탑이 속한 네트워크 탑색
    q.push(1);
    visited[1] = 1;
    //같은 네트워크의 모든 송전탑을 탐색할 때까지 반복
    while (!q.empty()) {
        num++;
        for (int a = 1; a <= n; a++) {
            //현재 송전탑과 연결되어 있으며 아직 방문하지 않은 송전탑을 큐에 추가
            if (connected[q.front()][a] == 1 && visited[a] == 0) {  
                q.push(a);
                visited[a] = 1;
            }
        }
        q.pop();
    }

    return max(n - (2 * num), (2 * num) - n);
}