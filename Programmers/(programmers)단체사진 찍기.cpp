/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/1835
단순한 완전 탐색 문제다.

우선 조건을 무시하고 설 수 있는 모든 경우의 수를 만든다.

그런 다음 각 경우의 수에 대해 조건을 모두 만족하는지 확인하고, 만족한다면 answer를 1씩 늘려준다.
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int answer;

void make_combination(int n, vector<string>& data, int selected[8], int visited[8], int index, char friends[8]);
bool is_correct_case(int n, vector<string>& data, int selected[8], char friends[8]);

int solution(int n, vector<string> data) {
    int selected[8], visited[8];
    char friends[8];
    //변수 초기화
    for (int a = 0; a < 8; a++) {
        selected[a] = -1;
        visited[a] = 0;
    }

    answer = 0;
    friends[0] = 'A';
    friends[1] = 'C';
    friends[2] = 'F';
    friends[3] = 'J';
    friends[4] = 'M';   
    friends[5] = 'N';
    friends[6] = 'R';
    friends[7] = 'T';
    make_combination(n, data, selected, visited, 0, friends);

    return answer;
}

void make_combination(int n, vector<string>& data, int selected[8], int visited[8], int index, char friends[8]) {
    if (index == 8) {   //8명의 배치를 모두 끝냈다면 조건을 만족하는지 확인
        if (is_correct_case(n, data, selected, friends)) {
            answer++;
        }
        return;
    }

    for (int a = 0; a < 8; a++) {   //아직 자리가 선택되지 않은 프렌즈를 index번째에 세운다
        if (visited[a] == 0) {
            selected[index] = a;
            visited[a] = 1;
            make_combination(n, data, selected, visited, index + 1, friends);
            visited[a] = 0;
            selected[index] = -1;
        }
    }
}

bool is_correct_case(int n, vector<string>& data, int selected[8], char friends[8]) {
    int pos1, pos2, gap_need, gap_real;
    
    for (int a = 0; a < n; a++) {
        //a번째 조건의 친구 두명의 위치를 파악
        for (int b = 0; b < 8; b++) {
            if (friends[b] == data[a][0])   pos1 = b;
            if (friends[b] == data[a][2])   pos2 = b;
        }
        for (int b = 0; b < 8; b++) {
            if (selected[b] == pos1) {
                pos1 = b;
                break;
            }
        }
        for (int b = 0; b < 8; b++) {
            if (selected[b] == pos2) {
                pos2 = b;
                break;
            }
        }
        //gap_need는 조건에 제시된 둘 간의 간격, gap_real은 실제 둘 간의 간격
        gap_need = (int)(data[a][4] - 48);
        gap_real = max(pos1, pos2) - min(pos1, pos2) - 1;
        //4번째 글자에 따라 처리
        if (data[a][3] == '=') {
            if (gap_real != gap_need)    return false;
        }
        else if (data[a][3] == '>') {
            if (gap_real <= gap_need)    return false;
        }
        else {
            if (gap_real >= gap_need)    return false;
        }
    }

    return true;
}