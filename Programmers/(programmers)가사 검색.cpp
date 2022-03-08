/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/60060
���� Ž������ �ذ��� �� �ִ� ������.

���� �ܾ�� �˻� Ű���尡 ���� �ִ� 100,000�̱⿡ ���� Ž���� �ð� �ʰ��� �ɸ���.

���� ���縦 �ܾ� ���� ������������, ���̰� ���ٸ� ���������� ������ �Ѵ�.

�׷� ���� �˻� Ű���� ������ ���� �ش� Ű����� ��Ī�Ǵ� �ܾ�� �� ���� �տ� ��ġ�� ���� �ε���, ���� �ڿ� ��ġ�� ���� �ε����� ���Ѵ�.

�츮�� �˰����ϴ� Ű����� ��Ī�Ǵ� �ܾ��� ������ ������ ���� ���� ���� �ε��� - ���� �ε����� �ȴ�.

����, Ű���忡�� ?�� ���λ�� ���� ��츦 ó���ϱ� ���� words_reverse������ ����� �־���.

�� ���� ���̵� �����ϰ� �Ʒ� �ڵ带 ���� ���� ���ذ� �� ���̴�.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//�ܾ ������ ��������, ���̰� ���ٸ� ���������� ������ �ϴ� �Լ�
bool compare(string s1, string s2) {
    if (s1.size() == s2.size()) {
        return s1 < s2;
    }
    return s1.size() < s2.size();
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<string> words_reverse;
    string str_temp, q;
    int left, right, middle, index_left, index_right;
    //words�� reverse���� ����
    for (int a = 0; a < words.size(); a++) {
        str_temp.clear();
        for (int b = words[a].size() - 1; b >= 0; b--)   str_temp.push_back(words[a][b]);
        words_reverse.push_back(str_temp);
    }
    //�ܾ���� ����
    sort(words.begin(), words.end(), compare);
    sort(words_reverse.begin(), words_reverse.end(), compare);
    //�� �˻� Ű���忡 ���� ��Ī�Ǵ� �ܾ��� ���� ���ϱ�
    for (int a = 0; a < queries.size(); a++) {
        if (queries[a][0] == '?') { //words_reverse�� ����ϴ� ���
            q.clear();
            for (int b = queries[a].size() - 1; b >= 0; b--) q.push_back(queries[a][b]);
            //���� Ű����� ��Ī�Ǵ� �ܾ��� ���� ���ʿ� ��ġ�� ���� �ε����� ���Ѵ�
            left = 0;
            right = words_reverse.size() - 1;
            while (left <= right) {
                middle = (left + right) / 2;
                if (q.size() < words_reverse[middle].size()) {  //Ű������ ���̰� middle�� ���̺��� ���� ���
                    right = middle - 1;
                }
                else if (q.size() > words_reverse[middle].size()) { //Ű������ ���̰� middle�� ���̺��� ū ���
                    left = middle + 1;
                }
                else {  //Ű������ ���̿� middle�� ���̰� ���� ���
                    for (int b = 0; b < q.size(); b++) {    //�� ���ڸ� ��
                        if (q[b] == '?') {  //'?'�� ���� ��� �ش� �ܾ�� ��Ī�� �ȴ�. ���� �� ���ʿ� ��Ī�Ǵ� �ܾ �ִ��� Ž��
                            right = middle - 1;
                            break;
                        }
                        else {
                            if (q[b] > words_reverse[middle][b]) {  //Ű���尡 middle���� ���������� �����ʿ� ��ġ�� ���
                                left = middle + 1;
                                break;
                            }
                            else if (q[b] < words_reverse[middle][b]) { //Ű���尡 middle���� ���������� ���ʿ� ��ġ�� ���
                                right = middle - 1;
                                break;
                            }
                        }
                    }
                }
            }
            index_left = left;
            //Ű����� ��Ī�Ǵ� �ܾ��� ���� �����ʿ� ��ġ�� ���� �ε��� ���ϱ�
            left = 0;
            right = words_reverse.size() - 1;
            while (left <= right) {
                middle = (left + right) / 2;
                if (q.size() < words_reverse[middle].size()) {
                    right = middle - 1;
                }
                else if (q.size() > words_reverse[middle].size()) {
                    left = middle + 1;
                }
                else {
                    for (int b = 0; b < q.size(); b++) {    //���� ������ ���� ���ϴ� �Ͱ� �ٸ� ������ �κ�(����Ž�� ��� ������ Ž��)
                        if (q[b] == '?') {
                            left = middle + 1;
                            break;
                        }
                        else {
                            if (q[b] > words_reverse[middle][b]) {
                                left = middle + 1;
                                break;
                            }
                            else if (q[b] < words_reverse[middle][b]) {
                                right = middle - 1;
                                break;
                            }
                        }
                    }
                }
            }
            index_right = left;
        }
        else {  //words�� ����ϴ� ���(�������� ���� ������ �ڵ�)
            q.clear();
            q = queries[a];

            left = 0;
            right = words.size() - 1;
            while (left <= right) {
                middle = (left + right) / 2;
                if (q.size() < words[middle].size()) {
                    right = middle - 1;
                }
                else if (q.size() > words[middle].size()) {
                    left = middle + 1;
                }
                else {
                    for (int b = 0; b < q.size(); b++) {
                        if (q[b] == '?') {
                            right = middle - 1;
                            break;
                        }
                        else {
                            if (q[b] > words[middle][b]) {
                                left = middle + 1;
                                break;
                            }
                            else if (q[b] < words[middle][b]) {
                                right = middle - 1;
                                break;
                            }
                        }
                    }
                }
            }
            index_left = left;

            left = 0;
            right = words.size() - 1;
            while (left <= right) {
                middle = (left + right) / 2;
                if (q.size() < words[middle].size()) {
                    right = middle - 1;
                }
                else if (q.size() > words[middle].size()) {
                    left = middle + 1;
                }
                else {
                    for (int b = 0; b < q.size(); b++) {
                        if (q[b] == '?') {
                            left = middle + 1;
                            break;
                        }
                        else {
                            if (q[b] > words[middle][b]) {
                                left = middle + 1;
                                break;
                            }
                            else if (q[b] < words[middle][b]) {
                                right = middle - 1;
                                break;
                            }
                        }
                    }
                }
            }
            index_right = left;
        }

        answer.push_back(index_right - index_left);
    }

    return answer;
}