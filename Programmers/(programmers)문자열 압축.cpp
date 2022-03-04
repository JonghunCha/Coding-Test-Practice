/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/60057
���ڿ� ó�� ������.

�ڸ� �� �ִ� ��� ������ ���� ����� ���ڿ��� ���ϰ� ���� ���� ���� ���̸� �����ϸ� �ȴ�.

Ư���� �˰����� �ʿ��Ѱ� �ƴ϶� ������ �����ϰڴ�.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void make_new_s(string& s, string& new_s, int token_size);
void int_to_string(int n, string& str);

int solution(string s) {
    int answer = 1001;
    string new_s;
    //������ ��� ������ ���� ����� ���ڿ� new_s�� ���ϰ� ���� ª�� ���� ���� ����
    for (int a = 1; a <= s.size() / 2; a++) {
        new_s.clear();
        make_new_s(s, new_s, a);
        if (new_s.size() < answer)   answer = new_s.size();
    }

    if (answer == 1001)  answer = s.size();

    return answer;
}
//token_size��ŭ �߶� ����� ���ڿ��� new_s�� �����ϴ� �Լ�
void make_new_s(string& s, string& new_s, int token_size) {
    int count = 1;
    string count_str;
    string token;
    bool is_end = false;
    //ù ��ū ����
    for (int a = 0; a < token_size; a++)  token.push_back(s[a]);
    //s���ڿ��� ��ū ���̸�ŭ Ž���ϸ� ������ �ǽ�
    for (int a = token_size; a < s.size(); a += token_size) {
        if (s.compare(a, token_size, token) == 0) { //������ �Ǵ� ���
            count++;
        }
        else {  //���� ��ū���� ������ �� �ִ� �κ��� ���� ���
            if (count != 1) {   //count�� 2�� �̻��̶�� �ش� ���� ���� ���ڿ��� �־��־�� ��
                int_to_string(count, count_str);
                new_s += count_str;
            }
            new_s += token; //���� ��ū�� ���� ���ڿ��� �־��ش�
            count = 1;

            if (a >= s.size() - token_size + 1) {   //���� ���ο� ��ū�� ���� ���̰� �ȵǸ� ������ �κ��� new_s�� �ְ� �������� ǥ��
                for (int b = a; b < s.size(); b++)   new_s.push_back(s[b]);
                is_end = true;
                break;
            }
            else {  //���ο� ��ū�� ����� Ž�� ����
                token.clear();
                for (int b = 0; b < token_size; b++) token.push_back(s[a + b]);
            }
        }
    }
    //���� ��ȯ���� �������� ���� new_s�� ������� ���� ��ū ���� ����
    if (!is_end) {  
        if (count != 1) {
            int_to_string(count, count_str);
            new_s += count_str;
        }
        new_s += token;
    }
}
//int�� string���� �ٲپ� �ִ� �Լ�
void int_to_string(int n, string& str) {
    int length;
    char c;

    str.clear();
    if (n >= 1000)   length = 4;
    else if (n >= 100)   length = 3;
    else if (n >= 10)    length = 2;
    else    length = 1;

    while (length > 0) {
        if (length == 4) {
            c = (n / 1000) + 48;
            n = n % 1000;
        }
        else if (length == 3) {
            c = (n / 100) + 48;
            n = n % 100;
        }
        else if (length == 2) {
            c = (n / 10) + 48;
            n = n % 10;
        }
        else {
            c = n + 48;
        }

        str.push_back(c);
        length--;
    }
}