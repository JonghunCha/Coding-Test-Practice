/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/49995
투 포인터 문제의 일종이다.

다만 이 문제의 경우 고려해야할 포인터 m이 하나 더 있으므로 실질적으로 쓰리 포인터 문제라 생각할 수 있다.

우선 m을 0~N-2번 바구니까지 순회를 시킨다.

그런 다음 첫째 아들과 둘째 아들이 받을 수 있는 과자 수의 최댓값을 구한다.(첫째 아들 : 0번 ~ m번, 둘째 아들 : m+1번 ~ N-1번)

이제 두 아들 중 더 많이 받은 아들의 바구니를 하나씩 빼는 동작을 두 아들이 받은 쿠키의 수가 같거나, l과 r값이 유효한 값이 아닐때 까지 반복한다.

두 아들이 받은 쿠키의 수가 같은 경우 answer가 최댓값을 가지도록 갱신한다.
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0, l, m, r, sum1, sum2;

    for (m = 0; m < cookie.size() - 1; m++) {
        l = 0;
        r = cookie.size() - 1;
        sum1 = 0;   //첫째 아들이 받은 쿠키의 수
        sum2 = 0;   //둘째 아들이 받은 쿠키의 수
        //각 아들이 받을 수 있는 쿠키의 최대갯수 계산
        for (int a = 0; a <= m; a++) {  
            sum1 += cookie[a];
        }
        for (int a = m + 1; a < cookie.size(); a++) {
            sum2 += cookie[a];
        }

        while (sum1 != sum2 && l <= m && r >= m + 1) {
            if (sum1 > sum2) {  //첫 번째 아들의 쿠키가 더 많다면 첫 번째 아들의 맨 왼쪽 바구니를 뺀다
                sum1 -= cookie[l];
                l++;
            }
            else {  //두 번째 아들의 쿠키가 더 많다면 두 번째 아들의 맨 오른쪽 바구니를 뺀다
                sum2 -= cookie[r];
                r--;
            }
        }
        //두 아들의 쿠키수가 같은 경우 answer를 최댓값으로 갱신
        if (sum1 == sum2 && sum1 > answer) {
            answer = sum1;
        }
    }

    return answer;
}