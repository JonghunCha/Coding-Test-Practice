/*
���� ��ũ : https://www.acmicpc.net/problem/1958
���̳������α׷����� �̿��� ���ڿ� ó�� ������.

Longest Common Subsequence�� Longest Common substring�� ���̿� ���� �˰� �־�� �Ǽ��ϴ� ���� ���� ���̴�.

Longest Common Subsequence�� ���ӵ� ���ڿ��� �ʿ䰡 ������ Longest Common substring�� ���ӵ� ���ڿ��̾�� �Ѵ�.
*/
#include <iostream>
#include <string>
using namespace std;

int dp[101][101][101];	//dp[a][b][c]�� str1, str2, str3���� ���� a, b, c��ŭ�� ���ڿ��� ������� �� LCS�� ����

void LCS(string& str1, string& str2, string& str3);

int main(void) {
	string str[3];
	//�Է°� ����
	cin >> str[0] >> str[1] >> str[2];
	//dp�迭 �ʱ�ȭ
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
					//str1, str2, str3���� �ϳ��� ���ڿ��� �ε��� ����
					max_num = max(max(dp[a - 1][b - 1][c], dp[a - 1][b][c - 1]), dp[a][b - 1][c - 1]);
					//str1, str2, str3���� �ΰ��� ���ڿ� �ε��� ����
					max_num = max(max_num, max(dp[a - 1][b][c], max(dp[a][b - 1][c], dp[a][b][c - 1])));
					dp[a][b][c] = max_num;
				}
			}
		}
	}
}