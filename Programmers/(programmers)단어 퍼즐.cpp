/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/12983
dp�� �ذ��� �� �ִ� ������.

ó���� ��͸� �̿��� top-down������� Ǯ�����µ� ȿ���� �׽�Ʈ���� �ð��ʰ��� ���ͼ� �ݺ����� �̿��� bottom-up������� �����Ͽ���.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dp[20001];  //dp[a]�� a��° ���ں��� t�� �������� �ϼ��ϴµ� �ʿ��� �ܾ������� �ּ� ������ ����

int DP(vector<string>& strs, string& t, int index);

int solution(vector<string> strs, string t)
{
    bool issame, ispossible;
    //dp�迭 �ʱ�ȭ
    for (int a = 0; a < t.size(); a++) dp[a] = 20001;
    dp[t.size()] = 0;

    for (int a = t.size() - 1; a >= 0; a--) {   //t�� �� �� �ܾ���� bottom-up
        ispossible = false;
        for (int b = 0; b < strs.size(); b++) { //��� �ܾ� ������ ���� 
            if (a + strs[b].size() <= t.size()) {   //�ش� �ܾ� ������ ��밡���� ���
                issame = true;
                for (int c = 0; c < strs[b].size(); c++) {  //�ܾ� ������ a��° �ε������� ������ ���ڰ� ��ġ�ϴ��� Ȯ��
                    if (strs[b][c] != t[a + c]) {
                        issame = false;
                        break;
                    }
                }

                if (issame) {   //���� ��ġ�Ѵٸ� dp�� ����
                    dp[a] = min(dp[a], dp[a + strs[b].size()] + 1);
                }
            }
        }
    }

    if (dp[0] == 20001)  return -1;
    else    return dp[0];
}