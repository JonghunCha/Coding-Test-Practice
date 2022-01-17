/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/64064
DFS�� ���� �׸��� set�� �̿��Ͽ� �ذ��Ͽ���.

���� DFS�� banned_id�� ��Ī�Ǵ� user_id�� ��� ������ ã�´�. �̸� vector<string> ������ ������ �����Ѵ�.

�׷� ���� ������ ���� ���͸� ���������� ������ ��, set�� �־��ش�.

set�� Ư���� ���� DFS���� ������ �ٲ�� ������ �Ȱ��� �ߺ��� ó���� �� �ִ�.
*/
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

set<vector<string>> s;
vector<string> str_vec;
bool visited[8];

void DFS(vector<string>& user_id, vector<string>& banned_id, int index);
bool compare(string& s1, string& s2);

int solution(vector<string> user_id, vector<string> banned_id) {
    s.clear();
    str_vec.clear();
    for (int a = 0; a < 8; a++)  visited[a] = false;

    DFS(user_id, banned_id, 0);

    return s.size();
}

void DFS(vector<string>& user_id, vector<string>& banned_id, int index) {
    if (index == banned_id.size()) {    //��� banned_id�� ��Ī�Ǵ� user_id������ ã�� ���
        vector<string> temp = str_vec;  
        //������ �� �ش� ���Ͱ� set�� ����ִ��� Ȯ��(���� ��� set�� �־��ְ�, �ߺ��� ��� ����)
        sort(temp.begin(), temp.end(), compare);
        if (s.find(temp) == s.end()) {
            s.insert(temp);
        }
        return;
    }

    //index��° banned_id�� ��Ī�Ǵ� user_id�� ã�´�
    //��͸� ���� DFS����
    bool is_matched;

    for (int a = 0; a < user_id.size(); a++) {
        if (visited[a] == false && user_id[a].size() == banned_id[index].size()) {
            is_matched = true;
            for (int b = 0; b < banned_id[index].size(); b++) {
                if (banned_id[index][b] != '*' && banned_id[index][b] != user_id[a][b]) {
                    is_matched = false;
                    break;
                }
            }

            if (is_matched) {
                str_vec.push_back(user_id[a]);
                visited[a] = true;
                DFS(user_id, banned_id, index + 1);
                visited[a] = false;
                str_vec.pop_back();
            }
        }
    }
}

bool compare(string& s1, string& s2) {
    if (s1.size() == s2.size()) {
        if (s1 < s2) return true;
        else    return false;
    }

    if (s1.size() < s2.size())   return true;
    else    return false;
}