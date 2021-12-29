/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/86491
������ ���� ������ Ǯ�� ���� ����� ������.

�־��� sizes�� �� ���ҿ��� ū ���� 0��° �ε�����, ���� ���� 1��° �ε����� ������ �Ͽ���.

�׷� ���� 0��° �ε����� ���� ū ���� 1��° �ε����� ���� ū ���� ���ϸ� �����̴�.
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int temp, max_w = 0, max_h = 0;

    for (int a = 0; a < sizes.size(); a++) {
        if (sizes[a][0] < sizes[a][1]) {
            temp = sizes[a][0];
            sizes[a][0] = sizes[a][1];
            sizes[a][1] = temp;
        }
    }

    for (int a = 0; a < sizes.size(); a++) {
        if (sizes[a][0] > max_w) max_w = sizes[a][0];
        if (sizes[a][1] > max_h) max_h = sizes[a][1];
    }

    return max_w * max_h;
}