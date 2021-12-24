/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/12973
스택을 이용하여 해결할 수 있다.

코드를 보면 쉽게 이해할 수 있을 것이다.
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> __stack;

    for (int a = 0; a < s.size(); a++) {
        if (!__stack.empty() && __stack.top() == s[a])   __stack.pop(); //스택이 비어있지 않고 스택의 top과 현재 문자가 같으면 제거할 수 있음
        else    __stack.push(s[a]); //제거할 수 없는 경우에 스택에 추가
    }

    if (__stack.empty()) return 1;
    else    return 0;
}