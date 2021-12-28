/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42586
프로그래머스에서는 스택/큐 문항으로 분류되어 있지만, 스택 큐를 이용하지 않아도 쉽게 해결할 수 있는 문제다.

따라서 아래에 큐를 이용한 방법과 주어진 입력 벡터로만 해결한 방법 두 가지를 제시한다.
*/

//큐를 이용한 방법
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int, int>> curr_progresses;
    int count, n_progresses, n_speeds;
    //큐에 progresses와 speeds를 pair로 집어넣는다.
    for (int a = 0; a < progresses.size(); a++)  curr_progresses.push(make_pair(progresses[a], speeds[a]));
    //모든 배포가 끝날때까지 반복
    while (!curr_progresses.empty()) {
        count = 0;
        //모든 progresses를 각자의 speeds만큼 더해준다.
        for (int a = 0; a < curr_progresses.size(); a++) {
            n_progresses = curr_progresses.front().first += curr_progresses.front().second;
            n_speeds = curr_progresses.front().second;
            curr_progresses.pop();
            curr_progresses.push(make_pair(n_progresses, n_speeds));
        }
        //앞에서부터 살피며 모든 작업이 끝난 progress는 배포한다.
        while (!curr_progresses.empty() && curr_progresses.front().first >= 100) {
            curr_progresses.pop();
            count++;
        }
        //해당날짜에 배포가 있는 경우 answer에 추가
        if (count != 0)  answer.push_back(count);
    }

    return answer;
}

//주어진 자료만 이용하는 경우
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int index = 0, count;   //index는 배포가 진행되지 않은 첫 번째 작업의 위치를 가르킨다
    //모든 작업이 배포될 때까지 반복
    while (index < progresses.size()) {
        count = 0;
        for (int a = index; a < progresses.size(); a++)  progresses[a] += speeds[a];    //배포되지 않은 모든 작업의 진행도를 각자의 speeds에 맞게 더해준다
        for (int a = index; a < progresses.size(); a++) {   //배포가 가능한 작업의 갯수를 카운트
            if (progresses[a] >= 100)    count++;
            else    break;
        }
        //배포가 가능한 작업이 있다면 그 갯수를 answer에 넣고, index를 그만큼 올려준다.
        if (count != 0) {
            answer.push_back(count);
            index += count;
        }
    }

    return answer;
}