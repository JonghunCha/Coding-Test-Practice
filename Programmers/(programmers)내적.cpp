/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/70128?language=cpp
너무 쉬운 문제라 github에 올릴까 말까 고민했는데 일단 푼 문제이긴 하니 올린 문제다.
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;

    for (int i = 0; i < a.size(); i++) {
        answer += a[i] * b[i];
    }

    return answer;
}