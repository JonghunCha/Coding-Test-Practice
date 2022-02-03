/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42889
정렬 문제이다.

우선 stages를 오름차순으로 정렬한다.

그런 다음 stages에 기재된 스테이지에 대해 실패율을 구한 뒤 벡터에 pair<해당 스테이지 번호, 실패율>쌍으로 집어넣어 준다.

위 작업을 마치면 실패율을 저장한 벡터를 문제의 정답에 맞게 실패율이 높은 스테이지부터 내림차순으로, 만약 실패율이 같다면 스테이지 번호가 오름차순이 되도록 정렬한다.

마지막으로 N개의 스테이지 중 실패율이 0이라 위 벡터에 포함 안된 스테이지들을 오름차순으로 정답에 포함시켜주면 된다.

코드를 보면 쉽게 이해할 수 있을 것이다.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;
//벡터를 실패율의 내림차순, 실패율이 같다면 스테이지 번호가 오름차순으 되도록 정렬
bool compare(const pair<int, double> p1, const pair<int, double> p2) {
    if (p1.second == p2.second)   return p1.first < p2.first;
    return p1.second > p2.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> vec;
    int people_num = stages.size(), start, end, size;
    //stages를 오름차순으로 정렬
    sort(stages.begin(), stages.end());
    //stages에 기재된 각 스테이지의 실패율 계산 및 벡터에 저장
    start = 0;
    for (int a = 0; a < people_num; a++) {
        if (stages[a] != stages[start]) {
            vec.push_back(make_pair(stages[start], (double)(a - start) / (double)(people_num - start)));
            start = a;
        }

        if (a == people_num - 1) {
            if (stages[start] == N + 1)   break;
            vec.push_back(make_pair(stages[start], (double)(a - start + 1) / (double)(people_num - start)));
        }
    }
    //벡터를 위의 compare를 통해 정렬하고 answer에 저장
    sort(vec.begin(), vec.end(), compare);
    for (int a = 0; a < vec.size(); a++) {
        answer.push_back(vec[a].first);
    }
    //실패율이 0인 스테이지들을 answer에 추가
    size = answer.size();
    bool is_in;
    for (int a = 1; a <= N; a++) {
        is_in = false;
        for (int b = 0; b < answer.size(); b++) {
            if (answer[b] == a) {
                is_in = true;
                break;
            }
        }
        if (!is_in)  answer.push_back(a);
    }

    return answer;
}