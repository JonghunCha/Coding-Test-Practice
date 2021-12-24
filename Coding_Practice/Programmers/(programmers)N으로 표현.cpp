/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42895
dynamic programming���� �ذ��� �� �ִ� ������.

���� ��� dp[a]�� N�� a�� ������� �� ���� �� �ִ� ������ set�̶�� ������ �� N�� 4�� ����Ͽ� ���� �� �ִ� ������ �Ʒ��� ����.

1. NNNN
2. dp[3] (+, -, *, /) dp[1]
3. dp[2] (+, -, *, /) dp[2]
4. dp[1] (+, -, *, /) dp[3]

���� dp[1]���� dp[8]���� ���ϸ� Ÿ�� number�� ���Ǵ� ��� a���� ��ȯ�ϸ� �ȴ�.
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
    //dp�� ���
    for (int a = 2; a <= 8; a++) {
        //�ܼ��� N�� a�� �̾� ���̴� ���
        temp = N;
        for (int b = 1; b < a; b++) {
            temp *= 10;
            temp += N;
        }
        dp[a].insert(temp);
        //���� �ּ����� ����� ������ ��� ��츦 dp[a] set�� �ֱ�
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
        //Ÿ�� number�� �����Ѵٸ� a ��ȯ
        if (dp[a].find(number) != dp[a].end())   return a;
    }

    return -1;
}
