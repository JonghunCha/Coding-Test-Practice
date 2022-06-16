/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42626
heap���� �ذ��� �� �ִ� ������.

���� �־��� �迭�� �����Ͽ� �ּ����� �����Ѵ�.

�׷� ���� ���� ���� �� 2���� heap���� ������ �� ���� ����� ���� �ּ����� �ִ� ������ �ݺ��Ѵ�.

�� �������� �ּ����� ��Ʈ ��尡 K�̻��̸� while�� �����ϰ� ���� ���´�.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(int a, int b) {
    return a < b;
}

void pop(vector<int>& v);
void push(vector<int>& v, int num);

int solution(vector<int> scoville, int K) {
    int answer = 0, min1, min2, index;
    bool is_possible = false;

    sort(scoville.begin(), scoville.end(), compare);

    while (scoville.size() >= 2) {  //�ּ� 2���� ���� �־�� ���� ����
        if (scoville[0] >= K) { //���� ���� ���� K�̻��� ��� while ����
            is_possible = true;
            break;
        }

        //������ �־��� ���ο� �� ��� �� ������ �� ���� �� �߰�
        answer++;
        min1 = scoville[0];
        pop(scoville);
        min2 = scoville[0];
        pop(scoville);
        push(scoville, min1 + 2 * min2);
    }

    if (scoville[0] >= K)    return answer;
    if (!is_possible)    return -1;
}
//�ּ������� ��Ʈ ��带 �����ϴ� �Լ�
void pop(vector<int>& v) {
    int temp, index = 0, child1, child2, size = v.size() - 1;

    v[0] = v[size];
    v.pop_back();
    while (1) {
        child1 = 2 * index + 1;
        child2 = 2 * index + 2;
        if (child1 < size && child2 < size && v[child1] < v[child2] && v[child1] < v[index]) {
            temp = v[index];
            v[index] = v[child1];
            v[child1] = temp;
            index = child1;
        }
        else if (child1 < size && child2 < size && v[child2] < v[child1] && v[child2] < v[index]) {
            temp = v[index];
            v[index] = v[child2];
            v[child2] = temp;
            index = child2;
        }
        else if (child1 < size && v[child1] < v[index]) {
            temp = v[index];
            v[index] = v[child1];
            v[child1] = temp;
            index = child1;
        }
        else {
            break;
        }
    }
}
//�ּ����� ���ο� ���� �ִ� �Լ�
void push(vector<int>& v, int num) {
    int temp, index = v.size(), parent;

    v.push_back(num);
    while (index >= 0) {
        if (index % 2 == 0)  parent = index / 2 - 1;
        else    parent = index / 2;

        if (v[index] < v[parent]) {
            temp = v[index];
            v[index] = v[parent];
            v[parent] = temp;
            index = parent;
        }
        else {
            break;
        }
    }
}