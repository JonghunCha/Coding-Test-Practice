/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/64064
DFS와 정렬 그리고 set을 이용하여 해결하였다.

먼저 DFS로 banned_id와 매칭되는 user_id의 모든 조합을 찾는다. 이를 vector<string> 형식의 변수에 저장한다.

그런 다음 위에서 구한 벡터를 사전순으로 정렬한 뒤, set에 넣어준다.

set의 특성을 통해 DFS에서 순서만 바뀌고 내용은 똑같은 중복을 처리할 수 있다.
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
    if (index == banned_id.size()) {    //모든 banned_id에 매칭되는 user_id조합을 찾은 경우
        vector<string> temp = str_vec;  
        //정렬한 뒤 해당 벡터가 set에 들어있는지 확인(없는 경우 set에 넣어주고, 중복인 경우 무시)
        sort(temp.begin(), temp.end(), compare);
        if (s.find(temp) == s.end()) {
            s.insert(temp);
        }
        return;
    }

    //index번째 banned_id와 매칭되는 user_id를 찾는다
    //재귀를 통해 DFS진행
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