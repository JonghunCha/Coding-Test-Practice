/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/12985
각 참가자가 다음 라운드에 어느 번호가 되며, 어느 번호일 때 서로 만나는지만 생각하면 쉬운 문제다.

A번의 참가자가 다음 라운드 진출 때 받는 번호는 아래와 같다.
A % 2 == 0	->  A = A / 2;
A % 2 == 1  ->  A = (A + 1) / 2;

또한 A번과 B번이 만나기 위해선 아래의 기준을 만족해야 한다.(A가 B보다 작다고 할 때)
1. A % 2 == 1
2. A + 1 == B
*/
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b)
{
    int smaller, bigger, answer = 1;

    smaller = min(a, b);
    bigger = max(a, b);

    while (1) {
        if (smaller % 2 == 1 && smaller + 1 == bigger)   break; //위에서 설명한 smaller와 bigger가 만나는 경우 while종료
        //smaller와 bigger의 다음 라운드 번호 계산
        if (smaller % 2 == 0)    smaller /= 2;
        else    smaller = (smaller + 1) / 2;
        if (bigger % 2 == 0)     bigger /= 2;
        else    bigger = (bigger + 1) / 2;
        answer++;
    }

    return answer;
}