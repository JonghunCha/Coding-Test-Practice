/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42890
DFS를 이용한 완전탐색으로 해결한 문제다.

우선 DFS를 이용해 만들 수 있는 모든 키의 조합을 만든다.

그런 다음 uniqueness와 minimality를 확인한다.

uniqueness의 경우 모든 row의 쌍 중 서로 똑같은 것이 있다면 false를, 모든 row쌍이 서로 다른 값을 가진다면 true를 반환하는 함수를 통해 확인하였다.

minimality의 경우 사용하는 속성 중 하나를 임의로 제외했을 때 uniqueness를 만족한다면 minimality는 만족하지 못하는 것이고, 사용하는 모든 속성을 하나씩 제외 했을 때 uniqueness를 만족시키지 못하면
minimality를 만족하는 경우이다.
*/
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int answer;

void make_key(bool use_column[8], int col_num, int index, vector<vector<string>>& relation);
bool is_uniqueness(bool use_column[8], vector<vector<string>>& relation);
bool is_minimality(bool use_column[8], vector<vector<string>>& relation);

int solution(vector<vector<string>> relation) {
    int col_num = relation[0].size();
    bool use_column[8];
    //입력값 저장 및 DFS를 이용한 키의 조합 생성
    answer = 0;
    memset(use_column, false, sizeof(bool) * 8);
    make_key(use_column, col_num, 0, relation);

    return answer;
}

void make_key(bool use_column[8], int col_num, int index, vector<vector<string>>& relation) {
    if (index == col_num) { //사용할 속성을 모두 고른 경우 유일성과 최소성 확인하고 정답 갱신
        if (is_uniqueness(use_column, relation) && is_minimality(use_column, relation)) {
            answer++;
        }
        return;
    }
    //index번째 속성을 사용하는 경우와 사용하지 않는 경우로 탐색
    use_column[index] = true;
    make_key(use_column, col_num, index + 1, relation);
    use_column[index] = false;
    make_key(use_column, col_num, index + 1, relation);
}

bool is_uniqueness(bool use_column[8], vector<vector<string>>& relation) {
    int row_num = relation.size(), col_num = relation[0].size(), using_column_num = 0;
    bool unique;
    //사용하는 속성이 0개인 경우 예외 처리
    for (int a = 0; a < col_num; a++) {
        if (use_column[a] == true)   using_column_num++;
    }
    if (using_column_num == 0)   return false;
    //모든 row의 쌍에 대해 서로 다른 값을 가지는 속성이 하나도 없는 경우 false 반환
    for (int a = 0; a < row_num - 1; a++) {
        for (int b = a + 1; b < row_num; b++) {
            unique = false;
            for (int c = 0; c < col_num; c++) {
                if (use_column[c] == true && (relation[a][c] != relation[b][c])) unique = true;
            }
            if (!unique) return false;
        }
    }
    return true;
}

bool is_minimality(bool use_column[8], vector<vector<string>>& relation) {
    int col_num = relation[0].size(), using_column_num = 0;
    bool use_column_copy[8];
    //사용하는 속성이 1개인 경우 최소성 항상 만족
    for (int a = 0; a < col_num; a++) {
        if (use_column[a] == true)   using_column_num++;
    }
    if (using_column_num == 1)   return true;
    //use_column의 변화를 방지하기 위하여 copy본 생성
    for (int a = 0; a < 8; a++)  use_column_copy[a] = use_column[a];
    //사용하는 속성을 하나씩 제외시켰을 때 유일성을 만족한다면 false 반환
    for (int a = 0; a < col_num; a++) {
        if (use_column_copy[a] == true) {
            use_column_copy[a] = false;
            if (is_uniqueness(use_column_copy, relation)) return false;
            use_column_copy[a] = true;
        }
    }
    return true;
}