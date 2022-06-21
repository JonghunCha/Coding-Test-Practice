/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42583
큐를 이용하여 다리에 올라가 있는 트럭을 경과 시간 단위로 관리하면 쉽게 해결할 수 있다.
*/
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, index = 1, total_weight = 0;
    queue<pair<int, int>> q;

    //첫 트럭 큐에 넣기
    q.push(make_pair(1, truck_weights[0]));
    total_weight = truck_weights[0];
    while (!q.empty()) {    //모든 트럭이 지날때까지 반복
        answer++;
        //가장 앞의 트럭이 다리를 완전히 지난 경우
        if (q.front().first + bridge_length <= answer) {
            total_weight -= q.front().second;
            q.pop();
        }

        //새로운 트럭이 다리에 올라갈 수 있는 경우
        if (index < truck_weights.size() && total_weight + truck_weights[index] <= weight) {
            q.push(make_pair(answer, truck_weights[index]));
            total_weight += truck_weights[index];
            index++;
        }
    }

    return answer;
}