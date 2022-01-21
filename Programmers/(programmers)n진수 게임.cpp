/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/17687
진법 변환을 할 줄만 알면 쉽게 해결할 수 있다.

문제의 조건에 따라 n진법의 수를 쭉 나열했을 때 길이가 t*m이 되는 부분까지만 구한 뒤 튜브가 말해야 하는 차례의 문자만 따로 추출하면 된다.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

char c[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

void int_to_n(int num, int n, string& str);

string solution(int n, int t, int m, int p) {
    int num = 0;
    string answer = "";
    string str;
    //str의 사이즈가 t*m이상이 될 때까지 num을 n진법으로 바꾸어 str에 넣어준다
    while (str.size() <= t * m) {
        int_to_n(num++, n, str);
    }
    //튜브가 말해야하는 문자들을 추출
    for (int a = 0; a < t; a++) {
        answer.push_back(str[p - 1 + (a * m)]);
    }

    return answer;
}

void int_to_n(int num, int n, string& str) {
    if ((num / n) > 0) {    //num을 n진법으로 바꾸었을 때 자리수가 2 이상인 경우
        int_to_n(num / n, n, str);
        int_to_n(num % n, n, str);
    }
    else {  //자릿수가 1인 경우 바로 str에 넣는다
        str.push_back(c[num]);
    }
}