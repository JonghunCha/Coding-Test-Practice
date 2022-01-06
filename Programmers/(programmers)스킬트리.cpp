/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/49993
�ܼ��� ���ڿ� �� ������.

skill�� ������� �ʴ� skill�� ������ ����� ����.

���� skill_trees���� skill�� ��� ���� ���� ��ų�� �� ������ ���ڿ��� new_str�� ��´�.

���������� skill�� new_str�� ���Ͽ� new_str�� skill�� ���λ��� �ùٸ� ��ų Ʈ���̴�.
*/
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_set<char> s;
    string new_str;
    //skill�� ����ִ� ��ų�� unordered_set�� �ִ´�
    for (int a = 0; a < skill.size(); a++) {
        s.insert(skill[a]);
    }

    for (int a = 0; a < skill_trees.size(); a++) {
        new_str.clear();

        for (int b = 0; b < skill_trees[a].size(); b++) {
            if (s.find(skill_trees[a][b]) != s.end()) { //skill_trees[a]���� skill�� �ִ� ��ų�� new_str�� �ִ´�
                new_str.push_back(skill_trees[a][b]);
            }
        }
        //���� new_str�� skill�� ���λ��� ��� answer++
        if (skill.substr(0, new_str.size()).compare(new_str) == 0) {
            answer++;
        }
    }

    return answer;
}