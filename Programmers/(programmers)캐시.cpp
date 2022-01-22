/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/17680
단순 LRU 캐시를 구현하는 문제다.

캐시의 크기가 최대 30이고, 도시의 개수는 10만개 이기에, vector로 구현해도 시간이 크게 문제되지 않았다.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void to_lower_character(string& str);   //대문자 알파벳을 소문자로 바꾸어주는 함수

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    bool is_hit;
    //cacheSize가 0인 경우 처리
    if (cacheSize == 0)  return 5 * cities.size();
    //대소문자 구분을 하지 않기에 대문자를 소문자로 변환
    for (int a = 0; a < cities.size(); a++) {
        to_lower_character(cities[a]);
    }
    //LRU를 사용하여 모든 도시 탐색
    for (int a = 0; a < cities.size(); a++) {
        //현재 도시가 캐시에 들어있는지 확인
        is_hit = false;
        for (int b = 0; b < cache.size(); b++) {
            if (cache[b] == cities[a]) {  //캐시에 들어있는 경우 해당 도시를 캐시의 맨 뒤로 이동
                is_hit = true;
                cache.erase(cache.begin() + b);
                cache.push_back(cities[a]);
                answer++;
                break;
            }
        }
        //캐시에서 miss가 난 경우
        if (!is_hit) {
            if (cache.size() < cacheSize) {   //아직 캐시가 다 차지 않았다면 캐시의 맨 뒤에 넣는다
                cache.push_back(cities[a]);
                answer += 5;
            }
            else {   //캐시가 꽉 찬 경우 victime을 제거하고 새로운 도시를 캐시의 맨 뒤에 넣는다
                cache.erase(cache.begin());
                cache.push_back(cities[a]);
                answer += 5;
            }
        }
    }

    return answer;
}
//대문자 알파벳을 소문자로 바꾸어주는 함수
void to_lower_character(string& str) {
    for (int a = 0; a < str.size(); a++) {
        if (str[a] >= 'A' && str[a] <= 'Z') {
            str[a] += 32;
        }
    }
}