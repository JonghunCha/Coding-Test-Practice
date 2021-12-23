/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/87946
완전 탐색으로 해결할 수 있는 문제다.(모든 던전순회 방법의 경우가 8! = 40320 이기에 시간적으로 충분)

본 코드의 경우 DFS를 이용하여 던전을 도는 모든 조합에 대해 테스트하고 가장 많은 던전을 도는 경우를 answer값으로 지정하였다.
*/
#include <string>
#include <vector>

using namespace std;

int answer = 0;

void DFS(int k, vector<vector<int>>& dungeons, int order[8], int decided_num);

int solution(int k, vector<vector<int>> dungeons) {
    int order[8];   //order[a]에는 a번 던전이 몇 번째에 방문되는지 저장

    for (int a = 0; a < dungeons.size(); a++)    order[a] = -1;
    DFS(k, dungeons, order, 0);

    return answer;
}

void DFS(int k, vector<vector<int>>& dungeons, int order[8], int decided_num) {
    if (decided_num == dungeons.size()) {   //모든 던전의 순서를 정한 경우
        int num = 0, curr_k = k;
        bool can_continue = true;

        for (int a = 0; a < dungeons.size(); a++) {
            for (int b = 0; b < dungeons.size(); b++) {
                if (order[b] == a) {    //b번째 던전이 a번째에 방문되는 경우
                    if (dungeons[b][0] <= curr_k) { //만약 현재 남은 피로도가 최소 필요 피로도보다 크다면 던전을 방문
                        curr_k -= dungeons[b][1];
                        num++;
                    }
                    else {  //그렇지 않은 경우 can_continue를 false로 설정
                        can_continue = false;
                    }
                    break;
                }
            }
            if (!can_continue)   break; //만약 이전 던전을 돌지 못한 경우 for문 종료
        }
        //answer를 최대값으로 갱신
        if (num > answer)    answer = num;
    }

    for (int a = 0; a < dungeons.size(); a++) { //아직 몇 번째로 방문할지 정해지지 않은 던전의 방문 순서 결정
        if (order[a] == -1) {
            order[a] = decided_num;
            DFS(k, dungeons, order, decided_num + 1);
            order[a] = -1;
        }
    }
}