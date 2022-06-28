/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/76502
��� ȸ���� ���� �ùٸ� ��ȣ ���ڿ����� Ȯ���ϸ� �ȴ�.

�ùٸ� ��ȣ ���ڿ��� �Ǳ� ���� ��Ģ�� �Ʒ��� ����.

1. ���ʺ��� ���������� ���������� ���ɴ�.
2. ��ȣ�� ������ ����� ��ġ�� ����� ������, �ش� ��ȣ�� ������ ī��Ʈ�� 1��ŭ �ø���.
3. ��ȣ�� ������ ��� 2���� ������ �ִ�
  3 - 1. ������ ��ȣ�� ���� �� �����ִ� ��ȣ�� 1�� �̻��̾�� �Ѵ�.
  3 - 2. ������ ��ȣ�� �ٸ� ������ ������ ��ȣ�� �ƴϾ�� �Ѵ�.
*/
#include <string>
#include <vector>

using namespace std;

bool is_correct(string s, int start);

int solution(string s) {
    int answer = 0, start = -1;

    for (int a = 0; a < s.size(); a++) {
        start++;
        if (is_correct(s, start)) answer++;
    }

    return answer;
}

bool is_correct(string s, int start) {
    int large = 0, medium = 0, small = 0, length = s.size();
    char prev;

    //�� ��ȣ ���� Ȧ���� ��� ó��
    if (length % 2 == 1) return false;
    //���� ��ȣ�� ������ ��� ó��
    if (s[start] == ']' || s[start] == '}' || s[start] == ')')   return false;

    for (int a = start; a < s.size(); a++) {
        if (s[a] == '[') {  //���ȣ ������ ���
            large++;
            prev = '[';
        }
        else if (s[a] == '{') { //�߰�ȣ ������ ���
            medium++;
            prev = '{';
        }
        else if (s[a] == '(') { //�Ұ�ȣ ������ ���
            small++;
            prev = '(';
        }
        else if (s[a] == ']') { //���ȣ ������ ���
            if (prev != '{' && prev != '(' && large > 0) {
                large--;
                prev = ']';
            }
            else    return false;
        }
        else if (s[a] == '}') { //�߰�ȣ ������ ���
            if (prev != '[' && prev != '(' && medium > 0) {
                medium--;
                prev = '}';
            }
            else    return false;
        }
        else {  //�Ұ�ȣ ������ ���
            if (prev != '[' && prev != '{' && small > 0) {
                small--;
                prev = ')';
            }
            else    return false;
        }
    }
    //���� ��������
    for (int a = 0; a < start; a++) {
        if (s[a] == '[') {
            large++;
            prev = '[';
        }
        else if (s[a] == '{') {
            medium++;
            prev = '{';
        }
        else if (s[a] == '(') {
            small++;
            prev = '(';
        }
        else if (s[a] == ']') {
            if (prev != '{' && prev != '(' && large > 0) {
                large--;
                prev = ']';
            }
            else    return false;
        }
        else if (s[a] == '}') {
            if (prev != '[' && prev != '(' && medium > 0) {
                medium--;
                prev = '}';
            }
            else    return false;
        }
        else {
            if (prev != '[' && prev != '{' && small > 0) {
                small--;
                prev = ')';
            }
            else    return false;
        }
    }

    return true;
}