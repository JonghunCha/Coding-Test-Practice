/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/12982
난이도 1짜리 문제라 쉬운 문제다.

d를 정렬하고 신청금액이 낮은 요청부터 처리해야 가장 많은 부서의 요청을 처리할 수 있다.
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    sort(d.begin(), d.end());

    for (int a = 0; a < d.size(); a++) {
        if (budget >= d[a]) {
            answer++;
            budget -= d[a];
        }
        else {
            break;
        }
    }

    return answer;
}