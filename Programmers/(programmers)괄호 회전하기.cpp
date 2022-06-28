/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/76502
모든 회전에 대해 올바른 괄호 문자열인지 확인하면 된다.

올바른 괄호 문자열이 되기 위한 규칙은 아래와 같다.

1. 왼쪽부터 오른쪽으로 순차적으로 살핀다.
2. 괄호가 열리는 경우의 위치는 상관이 없으며, 해당 괄호의 종류의 카운트를 1만큼 올린다.
3. 괄호가 닫히는 경우 2가지 제한이 있다
  3 - 1. 닫히는 괄호가 오기 전 열려있는 괄호가 1개 이상이어야 한다.
  3 - 2. 직전의 괄호가 다른 종류의 열리는 괄호가 아니어야 한다.
*/
#include <string>
#include <vector>

using namespace std;

bool is_correct(string s, int start);

int solution(string s) {
    int answer = 0, start = -1;

    for (int a = 0; a < s.size(); a++) {
        start++;
        if (is_correct(s, start)) answer++;
    }

    return answer;
}

bool is_correct(string s, int start) {
    int large = 0, medium = 0, small = 0, length = s.size();
    char prev;

    //총 괄호 수가 홀수인 경우 처리
    if (length % 2 == 1) return false;
    //시작 괄호가 닫히는 경우 처리
    if (s[start] == ']' || s[start] == '}' || s[start] == ')')   return false;

    for (int a = start; a < s.size(); a++) {
        if (s[a] == '[') {  //대괄호 열리는 경우
            large++;
            prev = '[';
        }
        else if (s[a] == '{') { //중괄호 열리는 경우
            medium++;
            prev = '{';
        }
        else if (s[a] == '(') { //소괄호 열리는 경우
            small++;
            prev = '(';
        }
        else if (s[a] == ']') { //대괄호 닫히는 경우
            if (prev != '{' && prev != '(' && large > 0) {
                large--;
                prev = ']';
            }
            else    return false;
        }
        else if (s[a] == '}') { //중괄호 닫히는 경우
            if (prev != '[' && prev != '(' && medium > 0) {
                medium--;
                prev = '}';
            }
            else    return false;
        }
        else {  //소괄호 닫히는 경우
            if (prev != '[' && prev != '{' && small > 0) {
                small--;
                prev = ')';
            }
            else    return false;
        }
    }
    //위와 마찬가지
    for (int a = 0; a < start; a++) {
        if (s[a] == '[') {
            large++;
            prev = '[';
        }
        else if (s[a] == '{') {
            medium++;
            prev = '{';
        }
        else if (s[a] == '(') {
            small++;
            prev = '(';
        }
        else if (s[a] == ']') {
            if (prev != '{' && prev != '(' && large > 0) {
                large--;
                prev = ']';
            }
            else    return false;
        }
        else if (s[a] == '}') {
            if (prev != '[' && prev != '(' && medium > 0) {
                medium--;
                prev = '}';
            }
            else    return false;
        }
        else {
            if (prev != '[' && prev != '{' && small > 0) {
                small--;
                prev = ')';
            }
            else    return false;
        }
    }

    return true;
}