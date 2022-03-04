/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/60057
문자열 처리 문제다.

자를 수 있는 모든 단위에 대해 압축된 문자열을 구하고 가장 작은 것의 길이를 갱신하면 된다.

특별한 알고리즘이 필요한건 아니라 설명은 생략하겠다.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void make_new_s(string& s, string& new_s, int token_size);
void int_to_string(int n, string& str);

int solution(string s) {
    int answer = 1001;
    string new_s;
    //가능한 모든 단위에 대해 압축된 문자열 new_s를 구하고 가장 짧은 것의 길이 갱신
    for (int a = 1; a <= s.size() / 2; a++) {
        new_s.clear();
        make_new_s(s, new_s, a);
        if (new_s.size() < answer)   answer = new_s.size();
    }

    if (answer == 1001)  answer = s.size();

    return answer;
}
//token_size만큼 잘라서 압축된 문자열을 new_s에 저장하는 함수
void make_new_s(string& s, string& new_s, int token_size) {
    int count = 1;
    string count_str;
    string token;
    bool is_end = false;
    //첫 토큰 지정
    for (int a = 0; a < token_size; a++)  token.push_back(s[a]);
    //s문자열을 토큰 길이만큼 탐색하며 압축을 실시
    for (int a = token_size; a < s.size(); a += token_size) {
        if (s.compare(a, token_size, token) == 0) { //압축이 되는 경우
            count++;
        }
        else {  //현재 토큰으로 압축할 수 있는 부분을 지난 경우
            if (count != 1) {   //count가 2개 이상이라면 해당 값을 압축 문자열에 넣어주어야 함
                int_to_string(count, count_str);
                new_s += count_str;
            }
            new_s += token; //현재 토큰을 압축 문자열에 넣어준다
            count = 1;

            if (a >= s.size() - token_size + 1) {   //만약 새로운 토큰을 만들 길이가 안되면 나머지 부분을 new_s에 넣고 끝났음을 표시
                for (int b = a; b < s.size(); b++)   new_s.push_back(s[b]);
                is_end = true;
                break;
            }
            else {  //새로운 토큰을 만들고 탐색 진행
                token.clear();
                for (int b = 0; b < token_size; b++) token.push_back(s[a + b]);
            }
        }
    }
    //위의 순환문은 끝났으나 아직 new_s에 저장되지 않은 토큰 정보 저장
    if (!is_end) {  
        if (count != 1) {
            int_to_string(count, count_str);
            new_s += count_str;
        }
        new_s += token;
    }
}
//int를 string으로 바꾸어 주는 함수
void int_to_string(int n, string& str) {
    int length;
    char c;

    str.clear();
    if (n >= 1000)   length = 4;
    else if (n >= 100)   length = 3;
    else if (n >= 10)    length = 2;
    else    length = 1;

    while (length > 0) {
        if (length == 4) {
            c = (n / 1000) + 48;
            n = n % 1000;
        }
        else if (length == 3) {
            c = (n / 100) + 48;
            n = n % 100;
        }
        else if (length == 2) {
            c = (n / 10) + 48;
            n = n % 10;
        }
        else {
            c = n + 48;
        }

        str.push_back(c);
        length--;
    }
}