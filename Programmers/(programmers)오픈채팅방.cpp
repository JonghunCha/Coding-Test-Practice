/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42888
key-value���� �̿��� ������(map�� �̿��� ����)

key������ ���� ���̵�, value������ �г����� ����Ѵ�.

�г����� �ٲ�� ���� Enter�� �濡 �����ų� Change�� �г����� �ٲ� ���� �Ͼ��.

���� ��� record�� ���Ǹ� �г����� �ٲ�� ��� �ش��ϴ� key-value���� ����Ͽ� �����Ѵ�.

�׷� ���� �ٽ� �� �� ��� record�鿡 ���� �ֽ� �г����� �����Ͽ� answer�� ��ȯ�ϸ� �ȴ�.
*/
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    string id, name;
    bool is_id;
    //record���� ���Ǹ� �г��� ������ ����
    for (int a = 0; a < record.size(); a++) {
        if (record[a].substr(0, 5) == "Enter") {    //ä�ù濡 ���� �� �г��� Ȯ��
            id.clear();
            name.clear();
            is_id = true;
            for (int b = 6; b < record[a].size(); b++) {
                if (record[a][b] == ' ') {
                    is_id = false;
                    continue;
                }
                if (is_id)   id.push_back(record[a][b]);
                else    name.push_back(record[a][b]);
            }

            m[id] = name;
        }
        else if (record[a].substr(0, 6) == "Change") {  //ä�ù� ������ �г����� ������ ���
            id.clear();
            name.clear();
            is_id = true;
            for (int b = 7; b < record[a].size(); b++) {
                if (record[a][b] == ' ') {
                    is_id = false;
                    continue;
                }
                if (is_id)   id.push_back(record[a][b]);
                else    name.push_back(record[a][b]);
            }

            m[id] = name;
        }
    }
    //��� record�鿡 ���� �ֱ��� �г����� ������ answer ��ȯ
    for (int a = 0; a < record.size(); a++) {
        if (record[a].substr(0, 5) == "Enter" || record[a].substr(0, 5) == "Leave") {
            id.clear();
            for (int b = 6; b < record[a].size(); b++) {
                if (record[a][b] != ' ') id.push_back(record[a][b]);
                else    break;
            }

            if (record[a].substr(0, 5) == "Enter")   answer.push_back(m[id] + "���� ���Խ��ϴ�.");
            else    answer.push_back(m[id] + "���� �������ϴ�.");
        }
    }


    return answer;
}