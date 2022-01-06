/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/49993
단순한 문자열 비교 문제다.

skill에 들어있지 않는 skill은 순서와 상관이 없다.

따라서 skill_trees에서 skill에 들어 있지 않은 스킬을 다 제거한 문자열을 new_str에 담는다.

마지막으로 skill과 new_str을 비교하여 new_str이 skill의 접두사라면 올바른 스킬 트리이다.
*/
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_set<char> s;
    string new_str;
    //skill에 들어있는 스킬을 unordered_set에 넣는다
    for (int a = 0; a < skill.size(); a++) {
        s.insert(skill[a]);
    }

    for (int a = 0; a < skill_trees.size(); a++) {
        new_str.clear();

        for (int b = 0; b < skill_trees[a].size(); b++) {
            if (s.find(skill_trees[a][b]) != s.end()) { //skill_trees[a]에서 skill에 있는 스킬만 new_str에 넣는다
                new_str.push_back(skill_trees[a][b]);
            }
        }
        //만약 new_str이 skill의 접두사인 경우 answer++
        if (skill.substr(0, new_str.size()).compare(new_str) == 0) {
            answer++;
        }
    }

    return answer;
}