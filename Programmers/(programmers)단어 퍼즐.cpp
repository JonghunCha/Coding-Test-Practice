/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/12983
dp로 해결할 수 있는 문제다.

처음엔 재귀를 이용한 top-down방식으로 풀었었는데 효율성 테스트에서 시간초과가 나와서 반복문을 이용한 bottom-up방식으로 수정하였다.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dp[20001];  //dp[a]는 a번째 문자부터 t의 끝까지를 완성하는데 필요한 단어조각의 최소 갯수를 저장

int DP(vector<string>& strs, string& t, int index);

int solution(vector<string> strs, string t)
{
    bool issame, ispossible;
    //dp배열 초기화
    for (int a = 0; a < t.size(); a++) dp[a] = 20001;
    dp[t.size()] = 0;

    for (int a = t.size() - 1; a >= 0; a--) {   //t의 맨 뒤 단어부터 bottom-up
        ispossible = false;
        for (int b = 0; b < strs.size(); b++) { //모든 단어 조각에 대해 
            if (a + strs[b].size() <= t.size()) {   //해당 단어 조각이 사용가능한 경우
                issame = true;
                for (int c = 0; c < strs[b].size(); c++) {  //단어 조각과 a번째 인덱스부터 시작한 문자가 일치하는지 확인
                    if (strs[b][c] != t[a + c]) {
                        issame = false;
                        break;
                    }
                }

                if (issame) {   //만약 일치한다면 dp값 갱신
                    dp[a] = min(dp[a], dp[a + strs[b].size()] + 1);
                }
            }
        }
    }

    if (dp[0] == 20001)  return -1;
    else    return dp[0];
}