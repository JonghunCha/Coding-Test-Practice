/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/64065
문자열 파싱, 정렬, 중복체크를 이용하면 해결할 수 있는 문제다.

먼저 문자열 파싱을 통해 각 집합들로 구별을 한다.

다음으로 집합의 크기를 오름차순으로 정렬을 한다.

마지막으로 정렬된 집합에 있는 원소들을 answer에 하나씩 넣어주는데, 이 때 answer에 이미 들어간 수와 중복되지 않은 수를 넣어주면 된다.
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int string_to_int(string str);
bool compare(vector<int>& v1, vector<int>& v2) {
    return v1.size() < v2.size();
}

vector<int> solution(string s) {
    vector<int> answer, temp;
    vector<vector<int>> allsets;
    string str;
    bool in_set;
    //문자열 파싱
    for (int a = 1; a < s.size() - 1; a++) {
        if (s[a] == '{') {
            temp.clear();
            str.clear();
            in_set = true;
        }
        else if (s[a] == '}') {
            temp.push_back(string_to_int(str));
            in_set = false;
            allsets.push_back(temp);
        }
        else if (s[a] == ',') {
            if (in_set) {
                temp.push_back(string_to_int(str));
                str.clear();
            }
        }
        else {
            str.push_back(s[a]);
        }
    }
    //allsets를 오름차순으로 정렬
    sort(allsets.begin(), allsets.end(), compare);

    //answer에 수를 하나씩 넣어주는 과정(이 때 중복체크를 위해 in_answer라는 set에 answer에 이미 들어간 수를 하나씩 넣어줌)
    set<int> in_answer;

    for (int a = 0; a < allsets.size(); a++) {
        for (int b = 0; b < allsets[a].size(); b++) {
            if (in_answer.find(allsets[a][b]) == in_answer.end()) {
                answer.push_back(allsets[a][b]);
                in_answer.insert(allsets[a][b]);
                break;
            }
        }
    }

    return answer;
}
//string을 int로 변환해주는 함수
int string_to_int(string str) {
    int ret = 0, temp = 1;

    for (int a = str.size() - 1; a >= 0; a--) {
        ret += temp * (int)(str[a] - '0');
        temp *= 10;
    }

    return ret;
}