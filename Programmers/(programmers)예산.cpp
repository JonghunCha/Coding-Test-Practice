/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/12982
���̵� 1¥�� ������ ���� ������.

d�� �����ϰ� ��û�ݾ��� ���� ��û���� ó���ؾ� ���� ���� �μ��� ��û�� ó���� �� �ִ�.
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    sort(d.begin(), d.end());

    for (int a = 0; a < d.size(); a++) {
        if (budget >= d[a]) {
            answer++;
            budget -= d[a];
        }
        else {
            break;
        }
    }

    return answer;
}