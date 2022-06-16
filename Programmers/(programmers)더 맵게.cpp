/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42626
heap으로 해결할 수 있는 문제다.

먼저 주어진 배열을 정렬하여 최소힙을 구성한다.

그런 다음 가장 작은 값 2개를 heap에서 제거한 뒤 새로 계산한 값을 최소힙에 넣는 과정을 반복한다.

이 과정에서 최소힙의 루트 노드가 K이상이면 while을 종료하고 빠져 나온다.
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

    while (scoville.size() >= 2) {  //최소 2개의 수가 있어야 진행 가능
        if (scoville[0] >= K) { //가장 작은 값이 K이상인 경우 while 종료
            is_possible = true;
            break;
        }

        //문제에 주어진 새로운 값 계산 및 힙에서 값 제거 및 추가
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
//최소힙에서 루트 노드를 제거하는 함수
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
//최소힙에 새로운 값을 넣는 함수
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