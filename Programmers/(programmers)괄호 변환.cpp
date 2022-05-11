/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/60058
문자열 처리에 관한 단순 구현 문제다.

문제에서 주어진 규칙에 따라 입력값을 올바른 괄호 문자열로 변환해주면 된다.
*/
#include <string>
#include <vector>

using namespace std;

bool is_correct(string str);
string recursion(string w);

string solution(string p) {
    string answer = "";

    answer = recursion(p);

    return answer;
}
//str이 올바른 괄호 문자열이면 true, 아니면 false반환
bool is_correct(string str) {
    int num1 = 0, num2 = 0;
    for (int a = 0; a < str.size(); a++) {
        if (str[a] == '(')   num1++;
        else    num2++;
        if (num1 < num2) return false;
    }
    return true;
}
//균형잡힌 괄호 문자열 w를 규칙에 따라 올바른 괄호 문자열로 변환하여 반환
string recursion(string w) {
    //빈 문자열일 경우 바로 반환
    if (w.size() == 0)   return w;

    int num1 = 0, num2 = 0;
    string u, v, ret;

    for (int a = 0; a < w.size(); a++) {
        if (w[a] == '(')   num1++;
        else    num2++;
        //더이상 나눌 수 없는 균형잡힌 괄호 문자열 u와 나머지 v를 계산
        if (num1 == num2) {
            for (int b = 0; b < num1 + num2; b++)    u.push_back(w[b]);
            for (int b = num1 + num2; b < w.size(); b++) v.push_back(w[b]);

            if (is_correct(u)) {    //u가 올바른 괄호 문자열이라면 v에 대해 재귀 호출하고 합친 것을 반환
                ret = u + recursion(v);
                return ret;
            }
            else {  //u가 올바른 괄호 문자열이 아닌 경우 규칙에 따라 변환하고 반환
                ret.push_back('(');
                ret += recursion(v);
                ret.push_back(')');
                for (int b = 1; b < u.size() - 1; b++) {
                    if (u[b] == '(') ret.push_back(')');
                    else    ret.push_back('(');
                }

                return ret;
            }

            break;
        }
    }
    return ret;
}