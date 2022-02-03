/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42889
���� �����̴�.

�켱 stages�� ������������ �����Ѵ�.

�׷� ���� stages�� ����� ���������� ���� �������� ���� �� ���Ϳ� pair<�ش� �������� ��ȣ, ������>������ ����־� �ش�.

�� �۾��� ��ġ�� �������� ������ ���͸� ������ ���信 �°� �������� ���� ������������ ������������, ���� �������� ���ٸ� �������� ��ȣ�� ���������� �ǵ��� �����Ѵ�.

���������� N���� �������� �� �������� 0�̶� �� ���Ϳ� ���� �ȵ� ������������ ������������ ���信 ���Խ����ָ� �ȴ�.

�ڵ带 ���� ���� ������ �� ���� ���̴�.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;
//���͸� �������� ��������, �������� ���ٸ� �������� ��ȣ�� ���������� �ǵ��� ����
bool compare(const pair<int, double> p1, const pair<int, double> p2) {
    if (p1.second == p2.second)   return p1.first < p2.first;
    return p1.second > p2.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> vec;
    int people_num = stages.size(), start, end, size;
    //stages�� ������������ ����
    sort(stages.begin(), stages.end());
    //stages�� ����� �� ���������� ������ ��� �� ���Ϳ� ����
    start = 0;
    for (int a = 0; a < people_num; a++) {
        if (stages[a] != stages[start]) {
            vec.push_back(make_pair(stages[start], (double)(a - start) / (double)(people_num - start)));
            start = a;
        }

        if (a == people_num - 1) {
            if (stages[start] == N + 1)   break;
            vec.push_back(make_pair(stages[start], (double)(a - start + 1) / (double)(people_num - start)));
        }
    }
    //���͸� ���� compare�� ���� �����ϰ� answer�� ����
    sort(vec.begin(), vec.end(), compare);
    for (int a = 0; a < vec.size(); a++) {
        answer.push_back(vec[a].first);
    }
    //�������� 0�� ������������ answer�� �߰�
    size = answer.size();
    bool is_in;
    for (int a = 1; a <= N; a++) {
        is_in = false;
        for (int b = 0; b < answer.size(); b++) {
            if (answer[b] == a) {
                is_in = true;
                break;
            }
        }
        if (!is_in)  answer.push_back(a);
    }

    return answer;
}