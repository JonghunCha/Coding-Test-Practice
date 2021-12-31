/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/12985
�� �����ڰ� ���� ���忡 ��� ��ȣ�� �Ǹ�, ��� ��ȣ�� �� ���� ���������� �����ϸ� ���� ������.

A���� �����ڰ� ���� ���� ���� �� �޴� ��ȣ�� �Ʒ��� ����.
A % 2 == 0	->  A = A / 2;
A % 2 == 1  ->  A = (A + 1) / 2;

���� A���� B���� ������ ���ؼ� �Ʒ��� ������ �����ؾ� �Ѵ�.(A�� B���� �۴ٰ� �� ��)
1. A % 2 == 1
2. A + 1 == B
*/
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b)
{
    int smaller, bigger, answer = 1;

    smaller = min(a, b);
    bigger = max(a, b);

    while (1) {
        if (smaller % 2 == 1 && smaller + 1 == bigger)   break; //������ ������ smaller�� bigger�� ������ ��� while����
        //smaller�� bigger�� ���� ���� ��ȣ ���
        if (smaller % 2 == 0)    smaller /= 2;
        else    smaller = (smaller + 1) / 2;
        if (bigger % 2 == 0)     bigger /= 2;
        else    bigger = (bigger + 1) / 2;
        answer++;
    }

    return answer;
}