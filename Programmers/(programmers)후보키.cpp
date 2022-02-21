/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42890
DFS�� �̿��� ����Ž������ �ذ��� ������.

�켱 DFS�� �̿��� ���� �� �ִ� ��� Ű�� ������ �����.

�׷� ���� uniqueness�� minimality�� Ȯ���Ѵ�.

uniqueness�� ��� ��� row�� �� �� ���� �Ȱ��� ���� �ִٸ� false��, ��� row���� ���� �ٸ� ���� �����ٸ� true�� ��ȯ�ϴ� �Լ��� ���� Ȯ���Ͽ���.

minimality�� ��� ����ϴ� �Ӽ� �� �ϳ��� ���Ƿ� �������� �� uniqueness�� �����Ѵٸ� minimality�� �������� ���ϴ� ���̰�, ����ϴ� ��� �Ӽ��� �ϳ��� ���� ���� �� uniqueness�� ������Ű�� ���ϸ�
minimality�� �����ϴ� ����̴�.
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
    //�Է°� ���� �� DFS�� �̿��� Ű�� ���� ����
    answer = 0;
    memset(use_column, false, sizeof(bool) * 8);
    make_key(use_column, col_num, 0, relation);

    return answer;
}

void make_key(bool use_column[8], int col_num, int index, vector<vector<string>>& relation) {
    if (index == col_num) { //����� �Ӽ��� ��� �� ��� ���ϼ��� �ּҼ� Ȯ���ϰ� ���� ����
        if (is_uniqueness(use_column, relation) && is_minimality(use_column, relation)) {
            answer++;
        }
        return;
    }
    //index��° �Ӽ��� ����ϴ� ���� ������� �ʴ� ���� Ž��
    use_column[index] = true;
    make_key(use_column, col_num, index + 1, relation);
    use_column[index] = false;
    make_key(use_column, col_num, index + 1, relation);
}

bool is_uniqueness(bool use_column[8], vector<vector<string>>& relation) {
    int row_num = relation.size(), col_num = relation[0].size(), using_column_num = 0;
    bool unique;
    //����ϴ� �Ӽ��� 0���� ��� ���� ó��
    for (int a = 0; a < col_num; a++) {
        if (use_column[a] == true)   using_column_num++;
    }
    if (using_column_num == 0)   return false;
    //��� row�� �ֿ� ���� ���� �ٸ� ���� ������ �Ӽ��� �ϳ��� ���� ��� false ��ȯ
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
    //����ϴ� �Ӽ��� 1���� ��� �ּҼ� �׻� ����
    for (int a = 0; a < col_num; a++) {
        if (use_column[a] == true)   using_column_num++;
    }
    if (using_column_num == 1)   return true;
    //use_column�� ��ȭ�� �����ϱ� ���Ͽ� copy�� ����
    for (int a = 0; a < 8; a++)  use_column_copy[a] = use_column[a];
    //����ϴ� �Ӽ��� �ϳ��� ���ܽ����� �� ���ϼ��� �����Ѵٸ� false ��ȯ
    for (int a = 0; a < col_num; a++) {
        if (use_column_copy[a] == true) {
            use_column_copy[a] = false;
            if (is_uniqueness(use_column_copy, relation)) return false;
            use_column_copy[a] = true;
        }
    }
    return true;
}