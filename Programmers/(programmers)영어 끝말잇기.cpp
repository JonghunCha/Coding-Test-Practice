/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/12981
중복에 대한 처리를 할 수 있는지 묻는 문제다.

문제에서 제시된 끝말잇기의 룰에 따라 탈락자를 선정하면 된다.

이 때 중복된 단어에 대한 처리는 c++의 set을 이용하였다.
*/
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    string prev;

    prev.push_back(words[0][0]);
    for (int a = 0; a < words.size(); a++) {
        //현재 단어의 첫 시작이 전 단어의 끝과 같고, 중복된 단어가 아니며, 한 글자인 단어가 아닐 때 정상적으로 진행
        if (words[a][0] == prev[prev.size() - 1] && s.find(words[a]) == s.end() && words[a].size() > 1) {
            s.insert(words[a]);
            prev = words[a];
        }
        else {  //위에 해당하지 않는 경우 answer를 정하고 break
            answer.push_back((a % n) + 1);
            answer.push_back((a / n) + 1);
            break;
        }
    }
    //탈락자가 발생하지 않은 경우
    if (answer.size() == 0)  answer = { 0, 0 };

    return answer;
}