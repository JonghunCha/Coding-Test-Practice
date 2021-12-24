/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/43105
DP�� �ذ��� �� �ִ�.

�� row�� ���� ���� �׻� ���� row�� ���� �������� ������ �� �����Ƿ� ������ ������ ����.

�׷��� row�� �糡�� �ƴ� ������ ���� row�� ���� �� ������ �� �� ������ ���� �����ϴ�.

�� ��� ���� ���� ������ ���� �����ϴ� ����� ���İ� ������ ���� �� ū ���� ���� �ȴ�.

�Ʒ� �ڵ带 ���� ���� ������ �� ���� ���̴�.
*/
#include <string>
#include <vector>
#include <utility>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0, n = triangle.size();
    //�ﰢ���� ũ�Ⱑ 1�� ��� �ٷ� ��ȯ
    if (n == 1)  return triangle[0][0];
    //������ �׸��� ���ʺ��� �ش� ������ �����ϴ� ����� �ִ� ���
    for (int a = 1; a < n; a++) {
        for (int b = 0; b <= a; b++) {
            if (b == 0)  triangle[a][b] = triangle[a - 1][b] + triangle[a][b];  //���� ������ ��� ���� row�� ���ʿ����� ���ٰ���
            else if (b == a) triangle[a][b] = triangle[a - 1][b - 1] + triangle[a][b];  //���� �������� ��� ���� row�� �����ʿ����� ���ٰ���
            else triangle[a][b] = max(triangle[a - 1][b - 1], triangle[a - 1][b]) + triangle[a][b]; //��� �ִ� ���
        }
    }
    //���� ū �� ���
    for (int a = 0; a < n; a++) {
        if (triangle[n - 1][a] > answer) answer = triangle[n - 1][a];
    }

    return answer;
}