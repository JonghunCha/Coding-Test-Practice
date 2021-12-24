/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42576
Hash�� �ٷ��� �ƴ��� ���� ������.

���� �������� ����� unordered_map�� ���� �ִ´�. �̶� key�� string���� �������� �̸�, value�� int�� ���������� ���� �����Ѵ�.

�׷� ���� �������� ����� Ž���ϸ� �̸��� ��Ī�Ǵ� key�� value���� 1�� �����.

�������� value�� 1�� �̸��� �������� ���� �����̴�.
*/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    //������ ��� m�� insert
    for (int a = 0; a < participant.size(); a++) {
        if (m.find(participant[a]) != m.end())   m[participant[a]]++;
        else    m.insert(make_pair(participant[a], 1));
    }
    //������ ��ܿ��� ������ ����� value�ϳ��� ����
    for (int a = 0; a < completion.size(); a++) {
        m[completion[a]]--;
    }
    //m�� ��ȸ�ϸ� value���� 1�� ����� �̸� ��ȯ
    for (unordered_map<string, int>::iterator itr = m.begin(); itr != m.end(); itr++) {
        if (itr->second == 1)  return itr->first;
    }
}