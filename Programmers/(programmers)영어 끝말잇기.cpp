/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/12981
�ߺ��� ���� ó���� �� �� �ִ��� ���� ������.

�������� ���õ� �����ձ��� �꿡 ���� Ż���ڸ� �����ϸ� �ȴ�.

�� �� �ߺ��� �ܾ ���� ó���� c++�� set�� �̿��Ͽ���.
*/
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    string prev;

    prev.push_back(words[0][0]);
    for (int a = 0; a < words.size(); a++) {
        //���� �ܾ��� ù ������ �� �ܾ��� ���� ����, �ߺ��� �ܾ �ƴϸ�, �� ������ �ܾ �ƴ� �� ���������� ����
        if (words[a][0] == prev[prev.size() - 1] && s.find(words[a]) == s.end() && words[a].size() > 1) {
            s.insert(words[a]);
            prev = words[a];
        }
        else {  //���� �ش����� �ʴ� ��� answer�� ���ϰ� break
            answer.push_back((a % n) + 1);
            answer.push_back((a / n) + 1);
            break;
        }
    }
    //Ż���ڰ� �߻����� ���� ���
    if (answer.size() == 0)  answer = { 0, 0 };

    return answer;
}