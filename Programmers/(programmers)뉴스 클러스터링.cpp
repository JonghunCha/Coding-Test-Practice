/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/17677
map�� �̿��Ͽ� �ذ��� �� �ִ� ������.

������ ���ǿ� ���� str1�� str2�� ��ȿ�� �ܾ���� ���� map�� <string, int> (�ܾ�� �ش� �ܾ��� ���� Ƚ��)�� �����Ѵ�.

�׷� ���� �����հ� �����տ� �ش��ϴ� map�� �����ϰ� ��ī�� ���絵�� ����ϸ� �ȴ�.
*/
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

void make_map(map<string, int>& map, string str);

int solution(string str1, string str2) {
    int answer = 0, value;
    string key;

    map<string, int> map_1, map_2, union_map, intersection_map;
    //str1�� str2�� map���� ��ȯ
    make_map(map_1, str1);
    make_map(map_2, str2);
    //������ ����
    for (map<string, int>::iterator itr = map_1.begin(); itr != map_1.end(); itr++) {
        key = (*itr).first;
        value = (*itr).second;
        if (map_2[key]) {
            intersection_map[key] = min(value, map_2[key]);
        }
    }
    //������ ����
    for (map<string, int>::iterator itr = map_2.begin(); itr != map_2.end(); itr++) {
        key = (*itr).first;
        value = (*itr).second;
        union_map[key] = value;
    }
    for (map<string, int>::iterator itr = map_1.begin(); itr != map_1.end(); itr++) {
        key = (*itr).first;
        value = (*itr).second;
        if (union_map[key]) {
            union_map[key] = max(value, union_map[key]);
        }
        else {
            union_map[key] = value;
        }
    }
    //���絵 ��� �� ���� ���
    double similarity;
    int intersection_num = 0, union_num = 0;

    for (map<string, int>::iterator itr = union_map.begin(); itr != union_map.end(); itr++) {
        union_num += (*itr).second;
    }
    for (map<string, int>::iterator itr = intersection_map.begin(); itr != intersection_map.end(); itr++) {
        intersection_num += (*itr).second;
    }

    if (union_num == 0)  return 65536;  //�������� �������� ���

    similarity = (double)(intersection_num) / (double)(union_num);
    answer = (int)(similarity * 65536);

    return answer;
}
//str���� �� ���ھ� ���� map�� �־��ִ� �Լ�
void make_map(map<string, int>& map, string str) {
    bool is_correct_word;
    string temp;

    for (int a = 0; a < str.size() - 1; a++) {
        temp = str.substr(a, 2);
        is_correct_word = true;

        for (int b = 0; b < 2; b++) {
            if (temp[b] >= 'A' && temp[b] <= 'Z') { //�빮�ڴ� �ҹ��ڷ� ����
                temp[b] += 32;
            }
            else if (temp[b] < 'a' || temp[b] > 'z') {  //��ȿ�� ���ڰ� �ƴ� ��� map�� ���� �ʴ´�
                is_correct_word = false;
            }
        }

        if (is_correct_word) {
            if (map[temp]) {
                map[temp]++;
            }
            else {
                map[temp] = 1;
            }
        }
    }
}