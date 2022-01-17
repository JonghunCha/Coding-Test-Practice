/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/64065
���ڿ� �Ľ�, ����, �ߺ�üũ�� �̿��ϸ� �ذ��� �� �ִ� ������.

���� ���ڿ� �Ľ��� ���� �� ���յ�� ������ �Ѵ�.

�������� ������ ũ�⸦ ������������ ������ �Ѵ�.

���������� ���ĵ� ���տ� �ִ� ���ҵ��� answer�� �ϳ��� �־��ִµ�, �� �� answer�� �̹� �� ���� �ߺ����� ���� ���� �־��ָ� �ȴ�.
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
    //���ڿ� �Ľ�
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
    //allsets�� ������������ ����
    sort(allsets.begin(), allsets.end(), compare);

    //answer�� ���� �ϳ��� �־��ִ� ����(�� �� �ߺ�üũ�� ���� in_answer��� set�� answer�� �̹� �� ���� �ϳ��� �־���)
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
//string�� int�� ��ȯ���ִ� �Լ�
int string_to_int(string str) {
    int ret = 0, temp = 1;

    for (int a = str.size() - 1; a >= 0; a--) {
        ret += temp * (int)(str[a] - '0');
        temp *= 10;
    }

    return ret;
}