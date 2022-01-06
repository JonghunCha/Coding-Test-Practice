/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/12971
�������� DP������, ������ ��ü�� ���Ǹ� ���� �ٸ��� �̿� ������ ������ ����.

���� Ǯ� ������ �ڼ��� ������ ���� �ʰڴ�.
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
    //������ ��ƼĿ�� ������� �ʴ� ���
    dp[0] = sticker[0];
    dp[1] = max(sticker[0], sticker[1]);
    answer = dp[1];
    for (int a = 2; a < sticker.size() - 1; a++) {
        dp[a] = max(dp[a - 2] + sticker[a], dp[a - 1]);
        if (dp[a] > answer)  answer = dp[a];
    }
    //ù ��° ��ƼĿ�� ������� �ʴ� ���
    dp[1] = sticker[1];
    dp[2] = max(sticker[1], sticker[2]);
    answer = max(answer, dp[2]);
    for (int a = 3; a < sticker.size(); a++) {
        dp[a] = max(dp[a - 2] + sticker[a], dp[a - 1]);
        if (dp[a] > answer)  answer = dp[a];
    }

    return answer;
}