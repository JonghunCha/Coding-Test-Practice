/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42895
dynamic programming으로 해결할 수 있는 문제다.

예를 들어 dp[a]는 N을 a번 사용했을 때 나올 수 있는 수들의 set이라고 가정할 때 N을 4번 사용하여 만들 수 있는 수들은 아래와 같다.

1. NNNN
2. dp[3] (+, -, *, /) dp[1]
3. dp[2] (+, -, *, /) dp[2]
4. dp[1] (+, -, *, /) dp[3]

따라서 dp[1]부터 dp[8]까지 구하며 타겟 number가 계산되는 경우 a값을 반환하면 된다.
*/
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    int temp;
    unordered_set<int> dp[9];

    if (N == number) return 1;

    dp[1].insert(N);
    //dp값 계산
    for (int a = 2; a <= 8; a++) {
        //단순히 N을 a번 이어 붙이는 경우
        temp = N;
        for (int b = 1; b < a; b++) {
            temp *= 10;
            temp += N;
        }
        dp[a].insert(temp);
        //위의 주석에서 언급한 가능한 모든 경우를 dp[a] set에 넣기
        for (int b = 1; b < a; b++) {
            for (unordered_set<int>::iterator itr1 = dp[a - b].begin(); itr1 != dp[a - b].end(); itr1++) {
                for (unordered_set<int>::iterator itr2 = dp[b].begin(); itr2 != dp[b].end(); itr2++) {
                    temp = (*itr1) + (*itr2);
                    if (dp[a].find(temp) == dp[a].end()) dp[a].insert(temp);
                    temp = (*itr1) - (*itr2);
                    if (dp[a].find(temp) == dp[a].end()) dp[a].insert(temp);
                    temp = (*itr1) * (*itr2);
                    if (dp[a].find(temp) == dp[a].end()) dp[a].insert(temp);
                    if (*itr2 != 0) {
                        temp = (*itr1) / (*itr2);
                        if (dp[a].find(temp) == dp[a].end()) dp[a].insert(temp);
                    }
                }
            }
        }
        //타겟 number가 존재한다면 a 반환
        if (dp[a].find(number) != dp[a].end())   return a;
    }

    return -1;
}
