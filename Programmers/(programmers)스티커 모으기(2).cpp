/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/12971
전형적인 DP문제로, 문제의 구체적 조건만 조금 다를뿐 이와 유사한 문제가 많다.

많이 풀어본 문제로 자세한 설명은 적지 않겠다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100000];

int solution(vector<int> sticker)
{
    int answer;

    if (sticker.size() == 1) return sticker[0];
    //마지막 스티커를 사용하지 않는 경우
    dp[0] = sticker[0];
    dp[1] = max(sticker[0], sticker[1]);
    answer = dp[1];
    for (int a = 2; a < sticker.size() - 1; a++) {
        dp[a] = max(dp[a - 2] + sticker[a], dp[a - 1]);
        if (dp[a] > answer)  answer = dp[a];
    }
    //첫 번째 스티커를 사용하지 않는 경우
    dp[1] = sticker[1];
    dp[2] = max(sticker[1], sticker[2]);
    answer = max(answer, dp[2]);
    for (int a = 3; a < sticker.size(); a++) {
        dp[a] = max(dp[a - 2] + sticker[a], dp[a - 1]);
        if (dp[a] > answer)  answer = dp[a];
    }

    return answer;
}