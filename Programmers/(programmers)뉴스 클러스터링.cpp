/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/17677
map을 이용하여 해결할 수 있는 문제다.

문제의 조건에 따라 str1과 str2의 유효한 단어쌍을 각각 map에 <string, int> (단어와 해당 단어의 출현 횟수)로 저장한다.

그런 다음 교집합과 합집합에 해당하는 map을 생성하고 자카드 유사도를 계산하면 된다.
*/
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

void make_map(map<string, int>& map, string str);

int solution(string str1, string str2) {
    int answer = 0, value;
    string key;

    map<string, int> map_1, map_2, union_map, intersection_map;
    //str1과 str2를 map으로 변환
    make_map(map_1, str1);
    make_map(map_2, str2);
    //교집합 생성
    for (map<string, int>::iterator itr = map_1.begin(); itr != map_1.end(); itr++) {
        key = (*itr).first;
        value = (*itr).second;
        if (map_2[key]) {
            intersection_map[key] = min(value, map_2[key]);
        }
    }
    //합집합 생성
    for (map<string, int>::iterator itr = map_2.begin(); itr != map_2.end(); itr++) {
        key = (*itr).first;
        value = (*itr).second;
        union_map[key] = value;
    }
    for (map<string, int>::iterator itr = map_1.begin(); itr != map_1.end(); itr++) {
        key = (*itr).first;
        value = (*itr).second;
        if (union_map[key]) {
            union_map[key] = max(value, union_map[key]);
        }
        else {
            union_map[key] = value;
        }
    }
    //유사도 계산 및 정답 출력
    double similarity;
    int intersection_num = 0, union_num = 0;

    for (map<string, int>::iterator itr = union_map.begin(); itr != union_map.end(); itr++) {
        union_num += (*itr).second;
    }
    for (map<string, int>::iterator itr = intersection_map.begin(); itr != intersection_map.end(); itr++) {
        intersection_num += (*itr).second;
    }

    if (union_num == 0)  return 65536;  //합집합이 공집합인 경우

    similarity = (double)(intersection_num) / (double)(union_num);
    answer = (int)(similarity * 65536);

    return answer;
}
//str에서 두 글자씩 끊어 map에 넣어주는 함수
void make_map(map<string, int>& map, string str) {
    bool is_correct_word;
    string temp;

    for (int a = 0; a < str.size() - 1; a++) {
        temp = str.substr(a, 2);
        is_correct_word = true;

        for (int b = 0; b < 2; b++) {
            if (temp[b] >= 'A' && temp[b] <= 'Z') { //대문자는 소문자로 통일
                temp[b] += 32;
            }
            else if (temp[b] < 'a' || temp[b] > 'z') {  //유효한 문자가 아닌 경우 map에 넣지 않는다
                is_correct_word = false;
            }
        }

        if (is_correct_word) {
            if (map[temp]) {
                map[temp]++;
            }
            else {
                map[temp] = 1;
            }
        }
    }
}