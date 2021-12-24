/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42587
큐를 이용하면 쉽게 해결할 수 있는 문제다.

우선 현재 대기목록의 index과 priority를 큐에 순서대로 넣는다.

그런 다음 location에 해당하는 프린트를 실행할 때까지 아래를 반복한다.

1. 큐의 front의 priority가 가장 크다면 프린트를 한다. 이 때 location과 index가 같다면 count를 반환한다.
2. 뒤 쪽에 우선순위가 더 큰 문서가 있다면 pop()한 뒤에 다시 push()한다.
*/
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<tuple<int, int>> q;
    int highest, count = 0, priority, index;    //higest는 가장 높은 우선순위의 값을 의미
    //큐에 문서들 넣기
    for (int a = 0; a < priorities.size(); a++) {
        q.push(make_tuple(a, priorities[a]));
    }
    //location을 출력할 때까지 반복
    while (!q.empty()) {
        //가장 높은 우선순위 번호 찾기
        highest = 0;
        for (int a = 0; a < priorities.size(); a++) {
            if (priorities[a] > highest) highest = priorities[a];
        }
        //현재 큐의 front에 있는 문서를 처리
        index = get<0>(q.front());
        priority = get<1>(q.front());
        if (priority == highest) {  //우선순위가 가장 높다면 프린트
            count++;
            if (index == location)   return count;  //원하는 location의 문서라면 바로 count반환
            else {  //만약 location의 문서가 아니라면 priority를 0으로 설정하고 큐에서 제거
                priorities[index] = 0;
                q.pop();
            }
        }
        else {  //우선순위가 가장 높지 않다면 큐의 맨 뒤로 이동
            q.pop();
            q.push(make_tuple(index, priority));
        }
    }

    return count;
}