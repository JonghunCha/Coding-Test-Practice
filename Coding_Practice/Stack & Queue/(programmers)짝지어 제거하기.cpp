/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/12973
������ �̿��Ͽ� �ذ��� �� �ִ�.

�ڵ带 ���� ���� ������ �� ���� ���̴�.
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> __stack;

    for (int a = 0; a < s.size(); a++) {
        if (!__stack.empty() && __stack.top() == s[a])   __stack.pop(); //������ ������� �ʰ� ������ top�� ���� ���ڰ� ������ ������ �� ����
        else    __stack.push(s[a]); //������ �� ���� ��쿡 ���ÿ� �߰�
    }

    if (__stack.empty()) return 1;
    else    return 0;
}