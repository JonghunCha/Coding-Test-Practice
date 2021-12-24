/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42897#
dp�� �ذ��� �� �ִ� ������.

�ϳ� �����ؾ� �� ���� ������ �������� �����Ǿ� �־�, ù ���� �и� ������ ���� ���� ���ϰ�, ������ ���� �и� ù ���� ���� ���Ѵ�.

����, ���ʿ� ù ���� ���ٰ� ������ �� 1~n��° ���� �� �� �ִ񰪰� ������ ���� ���ٰ� ������ �� 0~n-1��° ���� �� �� �ִ��� ���� ���� �� ���Ͽ���.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000001];    //dp�� a��° ������ �ϴٰ� �� �� ��ĥ �� �ִ� ���� �ִ��� ����

int solution(vector<int> money) {
    int answer = 0;

    //dp�� �ʱ�ȭ
    for (int a = 0; a < money.size(); a++)   dp[a] = -1;

    //������ ���� ���� �ʴ� ���
    dp[0] = money[0];
    dp[1] = max(money[0], money[1]);
    for (int a = 2; a < money.size() - 1; a++) {
        dp[a] = max(dp[a - 2] + money[a], dp[a - 1]);   //a��° ���� �ʹ� ���� ���� �ʴ� ��� �� �� ū ���� ����
    }
    answer = dp[money.size() - 2];

    //dp�� �ʱ�ȭ
    for (int a = 0; a < money.size(); a++)   dp[a] = -1;

    //ù ���� ���� �ʴ� ���
    dp[1] = money[1];
    dp[2] = max(money[1], money[2]);
    for (int a = 3; a < money.size(); a++) {
        dp[a] = max(dp[a - 2] + money[a], dp[a - 1]);
    }
    answer = max(answer, dp[money.size() - 1]);

    return answer;
}