/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/1836
경로는 최대 한 번만 꺽을 수 있기에 완전 탐색 문제로 해결할 수 있다.

우선 board상의 쌍의 좌표를 cordinates에 저장해주었다(cordinates의 크기는 최대 26-알파벳 대문자이기 때문)

그런 다음 while문을 반복하며 알파벳이 빠른 부분부터 제거할 수 있는지 확인하고 제거가 가능하다면 제거를 한다.

만약 타일이 남아있지만 제거할 타일이 없다면 IMPOSSIBLE을 반환한다.
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool is_possible(int m, int n, vector<string>& board, vector<vector<int>>& cordinates, int index);

string solution(int m, int n, vector<string> board) {
    int entire_set = 0, deleted_set = 0;    //각각 board상의 타일 쌍 갯수와 현재까지 지워진 타일 쌍의 갯수를 의미
    string answer = "";
    vector<vector<int>> cordinates(26);
    //entire_set및 cordinates설정
    for (int a = 0; a < m; a++) {
        for (int b = 0; b < n; b++) {
            if (board[a][b] >= 'A' && board[a][b] <= 'Z') {
                entire_set++;
                cordinates[board[a][b] - 'A'].push_back(a);
                cordinates[board[a][b] - 'A'].push_back(b);
            }
        }
    }
    entire_set /= 2;
    //isChanged는 해당 루프에서 제거된 타일이 있느냐를 의미, deleted는 이미 지워진 타일임을 나타내기 위해 사용
    bool isChanged = true;
    int deleted[26];

    for (int a = 0; a < 26; a++) {
        deleted[a] = 0;
    }

    while (isChanged) {
        isChanged = false;
        for (int a = 0; a < 26; a++) {
            if (deleted[a] == 0 && cordinates[a].size() > 0 && is_possible(m, n, board, cordinates, a)) {
                answer.push_back(a + 'A');
                board[cordinates[a][0]][cordinates[a][1]] = '.';
                board[cordinates[a][2]][cordinates[a][3]] = '.';
                isChanged = true;
                deleted_set++;
                deleted[a] = 1;
                break;
            }
        }
    }

    if (entire_set == deleted_set) {    //전부 다 지워졌다면 answer반환
        return answer;
    }
    else {  //다 지우지 못한 경우 IMPOSSIBLE반환
        return "IMPOSSIBLE";
    }
}

bool is_possible(int m, int n, vector<string>& board, vector<vector<int>>& cordinates, int index) {
    int x1 = cordinates[index][0], y1 = cordinates[index][1], x2 = cordinates[index][2], y2 = cordinates[index][3];
    bool ret;

    if (x1 == x2) { //같은 행인 경우 열만 확인
        if (y1 < y2) {
            for (int a = y1 + 1; a <= y2 - 1; a++)    if (board[x1][a] != '.') return false;
            return true;
        }
        else {
            for (int a = y2 + 1; a <= y1 - 1; a++)    if (board[x1][a] != '.') return false;
            return true;
        }
    }
    else if (y1 == y2) {    //같은 열인 경우 행만 확인
        if (x1 < x2) {
            for (int a = x1 + 1; a <= x2 - 1; a++)    if (board[a][y1] != '.') return false;
            return true;
        }
        else {
            for (int a = x2 + 1; a <= x1 - 1; a++)    if (board[a][y1] != '.') return false;
            return true;
        }
    }
    else {  //열과 행이 다른 경우 상대적 위치에 따라 한 번 꺽어서 도달할 수 있는지 확인
        ret = true;
        if (x1 > x2 && y1 > y2) {
            for (int a = x1 - 1; a >= x2; a--)   if (board[a][y1] != '.') ret = false;
            for (int a = y1 - 1; a >= y2 + 1; a--)   if (board[x2][a] != '.') ret = false;
            if (ret) return true;
            ret = true;
            for (int a = y1 - 1; a >= y2; a--)   if (board[x1][a] != '.') ret = false;
            for (int a = x1 - 1; a >= x2 + 1; a--)   if (board[a][y2] != '.') ret = false;
            if (ret) return true;
            else    return false;
        }
        else if (x1 < x2 && y1 > y2) {
            for (int a = x1 + 1; a <= x2; a++)   if (board[a][y1] != '.') ret = false;
            for (int a = y1 - 1; a >= y2 + 1; a--)   if (board[x2][a] != '.') ret = false;
            if (ret) return true;
            ret = true;
            for (int a = y1 - 1; a >= y2; a--)   if (board[x1][a] != '.') ret = false;
            for (int a = x1 + 1; a <= x2 - 1; a++)   if (board[a][y2] != '.') ret = false;
            if (ret) return true;
            else    return false;
        }
        else if (x1 > x2 && y1 < y2) {
            for (int a = y1 + 1; a <= y2; a++)   if (board[x1][a] != '.') ret = false;
            for (int a = x1 - 1; a >= x2 + 1; a--)   if (board[a][y2] != '.') ret = false;
            if (ret) return true;
            ret = true;
            for (int a = x1 - 1; a >= x2; a--)   if (board[a][y1] != '.') ret = false;
            for (int a = y1 + 1; a <= y2 - 1; a++)   if (board[x2][a] != '.') ret = false;
            if (ret) return true;
            else    return false;
        }
        else {
            for (int a = y1 + 1; a <= y2; a++)   if (board[x1][a] != '.') ret = false;
            for (int a = x1 + 1; a <= x2 - 1; a++)   if (board[a][y2] != '.') ret = false;
            if (ret) return true;
            ret = true;
            for (int a = x1 + 1; a <= x2; a++)   if (board[a][y1] != '.') ret = false;
            for (int a = y1 + 1; a <= y2 - 1; a++)   if (board[x2][a] != '.') ret = false;
            if (ret) return true;
            else    return false;
        }
    }
}