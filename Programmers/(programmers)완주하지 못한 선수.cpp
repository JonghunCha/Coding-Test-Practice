/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42576
Hash를 다룰줄 아는지 묻는 문제다.

먼저 참가자의 명단을 unordered_map에 집어 넣는다. 이때 key는 string으로 참가자의 이름, value는 int로 동명이인의 수를 저장한다.

그런 다음 완주자의 목록을 탐색하며 이름에 매칭되는 key의 value값을 1씩 낮춘다.

마지막에 value가 1인 이름이 완주하지 못한 선수이다.
*/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    //참가자 명단 m에 insert
    for (int a = 0; a < participant.size(); a++) {
        if (m.find(participant[a]) != m.end())   m[participant[a]]++;
        else    m.insert(make_pair(participant[a], 1));
    }
    //참가자 명단에서 완주한 사람의 value하나씩 감소
    for (int a = 0; a < completion.size(); a++) {
        m[completion[a]]--;
    }
    //m을 순회하며 value값이 1인 사람의 이름 반환
    for (unordered_map<string, int>::iterator itr = m.begin(); itr != m.end(); itr++) {
        if (itr->second == 1)  return itr->first;
    }
}