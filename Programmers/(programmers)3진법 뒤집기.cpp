/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/68935
10진법을 3진법으로 변환만 할 줄 알면 쉬운 문제다.

아래 코드의 경우 10진법을 3진법 string으로 변환 후 뒤집은 것을 다시 10진법으로 계산하였다.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string tenTothree(int n);

int solution(int n) {
    int answer = 0, temp = 1;
    string str;

    str = tenTothree(n);
    for (int a = 0; a < str.size(); a++) {  //뒤집은 결과를 10진법으로 계산
        answer += (int)(str[a] - '0') * temp;
        temp *= 3;
    }

    return answer;
}

string tenTothree(int n) {
    string ret;
    int temp = 1;
    //temp * 3이 n보다 작거나 같도록 temp 설정
    while (n >= 3 * temp) {
        temp *= 3;
    }
    //temp는 높은 자리에서 낮은 자리로 내려오며, 1의 자리가 완료 될 때까지 반복
    while (temp > 0) {
        if (n >= temp && n < 2 * temp) {    //현재 자리수가 2인 경우
            ret.push_back('1');
            n -= temp;
        }
        else if (n >= 2 * temp) {   //현재 자리수가 1인 경우
            ret.push_back('2');
            n -= 2 * temp;
        }
        else {  //현재 자리수가 0인 경우
            ret.push_back('0');
        }
        
        temp /= 3;  //다음 자리수로 내려간다
    }

    return ret;
}