/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/17681
비트 연산을 통해 해결할 수 있는 문제다.

우선 전체 지도를 | 연산을 통해 구한다.

그런 다음 각 줄에 해당하는 값과 n번째 자리만 1로 세팅된 값의 & 연산을 통해 특정 좌표가 벽인지 아닌지 알아내면 된다.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int my_pow(int times);

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<int> entire_map;
    vector<string> answer;
    string temp;
    int power_of_2;
    //전체 지도의 각 줄 별 int값 계산
    for (int a = 0; a < n; a++) {
        entire_map.push_back(arr1[a] | arr2[a]);
    }
    //좌표 하나하나에 대해 벽인지 빈 공간인지 & 연산을 통해 알아낸다
    for (int a = 0; a < n; a++) {
        temp.clear();
        for (int b = n - 1; b >= 0; b--) {
            power_of_2 = my_pow(b);

            if (entire_map[a] & power_of_2)  temp.push_back('#');
            else    temp.push_back(' ');
        }
        answer.push_back(temp);
    }

    return answer;
}
//2를 times번 곱한 값을 리턴
int my_pow(int times) {
    if (times == 0)  return 1;

    int ret = 1;
    for (int a = 0; a < times; a++) {
        ret *= 2;
    }

    return ret;
}