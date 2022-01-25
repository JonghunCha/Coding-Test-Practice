/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/17684
map�� �̿��Ͽ� ������ ������ �� �ִ����� ���� ������.

������ �׶� �׶� �÷������� ���ڿ� ���̰� �ִ밡 �ǵ��� ���ִ� ���� �ܾ��� �ε����� ������ ������ �ȴ�.
*/
#include <string>
#include <vector>
#include <map>
#include <utility>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dic;
    string str;
    int index;
    //���̰� 1�� �ܾ� ������ �ֱ�
    dic.insert(make_pair("A", 1));
    dic.insert(make_pair("B", 2));
    dic.insert(make_pair("C", 3));
    dic.insert(make_pair("D", 4));
    dic.insert(make_pair("E", 5));
    dic.insert(make_pair("F", 6));
    dic.insert(make_pair("G", 7));
    dic.insert(make_pair("H", 8));
    dic.insert(make_pair("I", 9));
    dic.insert(make_pair("J", 10));
    dic.insert(make_pair("K", 11));
    dic.insert(make_pair("L", 12));
    dic.insert(make_pair("M", 13));
    dic.insert(make_pair("N", 14));
    dic.insert(make_pair("O", 15));
    dic.insert(make_pair("P", 16));
    dic.insert(make_pair("Q", 17));
    dic.insert(make_pair("R", 18));
    dic.insert(make_pair("S", 19));
    dic.insert(make_pair("T", 20));
    dic.insert(make_pair("U", 21));
    dic.insert(make_pair("V", 22));
    dic.insert(make_pair("W", 23));
    dic.insert(make_pair("X", 24));
    dic.insert(make_pair("Y", 25));
    dic.insert(make_pair("Z", 26));
    //msg�� �����԰� ���ÿ� ������ ���ǿ� ���� ������ ���ο� �ܾ �߰�
    for (int a = 0; a < msg.size();) {
        str.clear();
        str.push_back(msg[a++]);
        while (dic.find(str) != dic.end()) {    //str�� ������ ���� �ܾ��� ������ str�� �ϳ��� �÷��ش�
            index = dic.find(str)->second;
            str.push_back(msg[a++]);
        }
        answer.push_back(index);    //������ �����ϴ� �ִ� ������ str�� �ε����� answer�� �߰�
        dic.insert(make_pair(str, dic.size() + 1)); //������ �������� �ʴ� ù str�� ������ �߰�
        a--;    //������ ���� str�� ã�� ���� �÷ȴ� �ε����� �ٽ� �ϳ� ���߾� �ش�
    }

    return answer;
}