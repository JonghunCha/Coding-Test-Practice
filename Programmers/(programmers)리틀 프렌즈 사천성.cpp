/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/1836
��δ� �ִ� �� ���� ���� �� �ֱ⿡ ���� Ž�� ������ �ذ��� �� �ִ�.

�켱 board���� ���� ��ǥ�� cordinates�� �������־���(cordinates�� ũ��� �ִ� 26-���ĺ� �빮���̱� ����)

�׷� ���� while���� �ݺ��ϸ� ���ĺ��� ���� �κк��� ������ �� �ִ��� Ȯ���ϰ� ���Ű� �����ϴٸ� ���Ÿ� �Ѵ�.

���� Ÿ���� ���������� ������ Ÿ���� ���ٸ� IMPOSSIBLE�� ��ȯ�Ѵ�.
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
    int entire_set = 0, deleted_set = 0;    //���� board���� Ÿ�� �� ������ ������� ������ Ÿ�� ���� ������ �ǹ�
    string answer = "";
    vector<vector<int>> cordinates(26);
    //entire_set�� cordinates����
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
    //isChanged�� �ش� �������� ���ŵ� Ÿ���� �ִ��ĸ� �ǹ�, deleted�� �̹� ������ Ÿ������ ��Ÿ���� ���� ���
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

    if (entire_set == deleted_set) {    //���� �� �������ٸ� answer��ȯ
        return answer;
    }
    else {  //�� ������ ���� ��� IMPOSSIBLE��ȯ
        return "IMPOSSIBLE";
    }
}

bool is_possible(int m, int n, vector<string>& board, vector<vector<int>>& cordinates, int index) {
    int x1 = cordinates[index][0], y1 = cordinates[index][1], x2 = cordinates[index][2], y2 = cordinates[index][3];
    bool ret;

    if (x1 == x2) { //���� ���� ��� ���� Ȯ��
        if (y1 < y2) {
            for (int a = y1 + 1; a <= y2 - 1; a++)    if (board[x1][a] != '.') return false;
            return true;
        }
        else {
            for (int a = y2 + 1; a <= y1 - 1; a++)    if (board[x1][a] != '.') return false;
            return true;
        }
    }
    else if (y1 == y2) {    //���� ���� ��� �ุ Ȯ��
        if (x1 < x2) {
            for (int a = x1 + 1; a <= x2 - 1; a++)    if (board[a][y1] != '.') return false;
            return true;
        }
        else {
            for (int a = x2 + 1; a <= x1 - 1; a++)    if (board[a][y1] != '.') return false;
            return true;
        }
    }
    else {  //���� ���� �ٸ� ��� ����� ��ġ�� ���� �� �� ��� ������ �� �ִ��� Ȯ��
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