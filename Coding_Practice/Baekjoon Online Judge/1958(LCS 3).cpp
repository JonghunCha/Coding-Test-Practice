/*
문제 링크 : https://www.acmicpc.net/problem/1958
다이나믹프로그래밍을 이용한 문자열 처리 문제다.

Longest Common Subsequence와 Longest Common substring의 차이에 대해 알고 있어야 실수하는 일이 없을 것이다.

Longest Common Subsequence는 연속된 문자열일 필요가 없지만 Longest Common substring은 연속된 문자열이어야 한다.
*/
#include <iostream>
#include <string>
using namespace std;

int dp[101][101][101];	//dp[a][b][c]는 str1, str2, str3에서 각각 a, b, c만큼의 문자열을 사용했을 때 LCS값 저장

void LCS(string& str1, string& str2, string& str3);

int main(void) {
	string str[3];
	//입력값 저장
	cin >> str[0] >> str[1] >> str[2];
	//dp배열 초기화
	for (int a = 0; a <= str[0].size(); a++) {
		for (int b = 0; b <= str[1].size(); b++) {
			for (int c = 0; c <= str[2].size(); c++) {
				dp[a][b][c] = 0;
			}
		}
	}
	LCS(str[0], str[1], str[2]);
	cout << dp[str[0].size()][str[1].size()][str[2].size()];

	return 0;
}

void LCS(string& str1, string& str2, string& str3) {
	int max_num;
	for (int a = 1; a <= str1.size(); a++) {
		for (int b = 1; b <= str2.size(); b++) {
			for (int c = 1; c <= str3.size(); c++) {
				if (str1[a - 1] == str2[b - 1] && str1[a - 1] == str3[c - 1])	dp[a][b][c] = dp[a - 1][b - 1][c - 1] + 1;
				else {
					//str1, str2, str3에서 하나의 문자열만 인덱스 증가
					max_num = max(max(dp[a - 1][b - 1][c], dp[a - 1][b][c - 1]), dp[a][b - 1][c - 1]);
					//str1, str2, str3에서 두개의 문자열 인덱스 증가
					max_num = max(max_num, max(dp[a - 1][b][c], max(dp[a][b - 1][c], dp[a][b][c - 1])));
					dp[a][b][c] = max_num;
				}
			}
		}
	}
}