/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/1835
�ܼ��� ���� Ž�� ������.

�켱 ������ �����ϰ� �� �� �ִ� ��� ����� ���� �����.

�׷� ���� �� ����� ���� ���� ������ ��� �����ϴ��� Ȯ���ϰ�, �����Ѵٸ� answer�� 1�� �÷��ش�.
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
    //���� �ʱ�ȭ
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
    if (index == 8) {   //8���� ��ġ�� ��� ���´ٸ� ������ �����ϴ��� Ȯ��
        if (is_correct_case(n, data, selected, friends)) {
            answer++;
        }
        return;
    }

    for (int a = 0; a < 8; a++) {   //���� �ڸ��� ���õ��� ���� ����� index��°�� �����
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
        //a��° ������ ģ�� �θ��� ��ġ�� �ľ�
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
        //gap_need�� ���ǿ� ���õ� �� ���� ����, gap_real�� ���� �� ���� ����
        gap_need = (int)(data[a][4] - 48);
        gap_real = max(pos1, pos2) - min(pos1, pos2) - 1;
        //4��° ���ڿ� ���� ó��
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