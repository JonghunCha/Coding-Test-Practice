/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/12980
문제 해결 방법만 생각해내면 굉장히 쉽게 구현할 수 있는 문제다.

N까지 가는데 점프를 최소화 하기 위해선 가능한 최대로 순간이동을 사용해야 한다.

또한 순간이동으로 도착하는 곳의 좌표는 항상 짝수이다.

따라서 N이 홀수라면 마지막 1칸은 점프로 이동하고 나머지는 순간이동으로 이동하는 방법이 가장 점프를 적게 사용하는 방법이다.
*/
#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    while (n > 0) {
        if (n % 2 == 1)  ans++; //n이 홀수라면 1칸은 점프로 이동
        n /= 2; //n이 짝수인 경우 항상 순간이동으로 도착
    }

    return ans;
}