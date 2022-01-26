/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/17685
������ �̿��Ͽ� �ذ��� ������.

�� �ܾ�� (�ٸ� �ܾ�� ���ξ ��ġ�� ���� �� ���� + 1)��ŭ�� �ܾ �ľ� �ڵ��ϼ��� �ȴ�.

�̸� ���� ���ξ ���� ��� ��ġ�� �ܾ ã�� ���� �߿��ѵ�, �̸� ������ ���� �ذ��Ͽ���.

"word"��� �ܾ ���� ��, word�� ���ξ ���� ��� ��ġ�� �ܾ�� word�� �� �ڿ� ��ġ�ǰ� �ȴ�.

���� �ܾ���� ���� ������ ���� �ʿ� ���� �� �ܾ�� 2���� �񱳸����� ������ ����� �� �ִ�.

***�ٸ� Ǯ�̸� ���� Trie�ڷᱸ���� ����Ͽ� Ǯ���µ�, �̸� �̿��ϴ� �͵� ���� ����̶� �����Ѵ�
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int compare(string& str, string& prev, string& next);

int solution(vector<string> words) {
    int answer = 0, n = words.size();
    string empty_str = "";
    //words�� ���������� ����
    sort(words.begin(), words.end());
    //�� �ܾ �ڵ��ϼ��� ���� �Է� �� ���
    for (int a = 0; a < n; a++) {
        if (a == 0)  answer += compare(words[a], empty_str, words[a + 1]);
        else if (a == n - 1) answer += compare(words[a], words[a - 1], empty_str);
        else    answer += compare(words[a], words[a - 1], words[a + 1]);
    }

    return answer;
}

int compare(string& str, string& prev, string& next) {
    int compare_prev = 0, compare_next = 0;
    //���� �ܾ�� �� ���� ���ڰ� ��ġ���� Ȯ��
    if (prev != "") {
        for (int a = 0; a < str.size(); a++) {
            //���� �� �ܾ�� ũ�Ⱑ Ŀ���� �����̰ų�, ���� �ٸ� ������ ��� �ش� �������� �ڵ��ϼ� ����
            if (a >= prev.size() || str[a] != prev[a]) {
                compare_prev = a + 1;
                break;
            }
        }

        if (compare_prev == 0)   compare_prev = str.size();
    }
    //���� �ܾ�� �� ���� ���ڰ� ��ġ���� Ȯ��
    if (next != "") {
        for (int a = 0; a < str.size(); a++) {
            if (a >= next.size() || str[a] != next[a]) {
                compare_next = a + 1;
                break;
            }
        }

        if (compare_next == 0)   compare_next = str.size();
    }
    //�� �� �� ū ���� ��ȯ
    return max(compare_prev, compare_next);
}