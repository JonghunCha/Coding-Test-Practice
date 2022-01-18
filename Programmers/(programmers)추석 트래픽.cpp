/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/17676
문자열 파싱과 관련된 문제다.

문제에 주어진 각 로그들의 처리 시작 시간과 응답완료 시간을 저장한다.

이 때 편의를 위해 가장 작은 단위인 ms기준으로 저장을 한다.

다음으로 기준이 되는 로그의 end지점에서 1초 이후 이전에 시작한 로그들의 갯수를 세어주면서 완전 탐색을 진행하면 된다.
*/
#include <string>
#include <vector>
#include <tuple>
#include <iostream>
using namespace std;

int string_to_int(string str);

int solution(vector<string> lines) {
    int answer = 0, temp, h, m, s, ss, gaps, gapss, sum;
    vector<int> start, end;
    string str;

    for (int a = 0; a < lines.size(); a++) {
        //로그 문자에서 시, 분, 초, 밀리초에 해당하는 수를 추출
        str = lines[a].substr(11, 100);
        h = string_to_int(str.substr(0, 2));
        m = string_to_int(str.substr(3, 2));
        s = string_to_int(str.substr(6, 2));
        ss = string_to_int(str.substr(9, 3));
        gaps = string_to_int(str.substr(13, 1));
        if (str.size() > 15) {
            gapss = string_to_int(str.substr(15, str.size() - 16));
        }
        else {
            gapss = 0;
        }
        //위에서 구한 시간 정보를 ms기준으로 변환
        sum = 0;
        sum += h * 60 * 60 * 1000;
        sum += m * 60 * 1000;
        sum += s * 1000;
        sum += ss;
        //각 로그의 종료시점, 시작시점을 저장
        end.push_back(sum);
        start.push_back(sum - (gaps * 1000 + gapss) + 1);
    }
    //모든 로그를 기준으로 탐색
    for (int a = 0; a < lines.size(); a++) {
        temp = 1;
        for (int b = a + 1; b < lines.size(); b++) {    //b번 로그가 a번 로그와 겹치는지 확인
            if (end[a] + 999 >= start[b]) {
                temp++;
            }
        }

        if (temp > answer) {
            answer = temp;
        }
    }

    return answer;
}
//string을 int로 변환하는 함수
int string_to_int(string str) {
    int ret = 0, temp = 1;

    for (int a = str.size() - 1; a >= 0; a--) {
        ret += temp * (int)(str[a] - '0');
        temp *= 10;
    }

    return ret;
}