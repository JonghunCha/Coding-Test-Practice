/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/17686
���Ŀ� ���õ� �����ε�, �� �� stable sort�� �����ؾ߸� �Ѵ�.

head�� number�� ���� ��� ó�� �Էµ� ������ �����϶�� �Ͽ��µ�, �̸� ���� stable sort�� �ʿ��� ���̴�.

c++�� algorithm��� ������ sort()�� stable_sort()�� �ִµ�, sort�� quick sort�� ������ �Ǿ��ְ�, stable_sort�� merge_sort�� ������ �Ǿ� �ִ�.

�� ������ ��� stable_sort�� ����Ͽ���.

�������� ���ڿ� �Ľ��ε� ���� �ذ��� �� ���� ���̴�.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(const string& str1, const string& str2);   //������ �� �Լ�
void to_lower_character(string& str);   //str�� �빮�ڸ� �ҹ��ڷ� �ٲپ� �ִ� �Լ�
int string_to_int(string& str); //str�� int�� ��ȯ�Ͽ� ��ȯ�ϴ� �Լ�

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), compare);

    return files;
}

bool compare(const string& str1, const string& str2) {
    //head�� ���� ��
    string head1 = "", head2 = "";
    for (int a = 0; a < str1.size(); a++) {
        if (str1[a] < '0' || str1[a] > '9')  head1.push_back(str1[a]);
        else    break;
    }
    for (int a = 0; a < str2.size(); a++) {
        if (str2[a] < '0' || str2[a] > '9')  head2.push_back(str2[a]);
        else    break;
    }
    to_lower_character(head1);
    to_lower_character(head2);
    if (head1.compare(head2) < 0) {
        return true;
    }
    else if (head1.compare(head2) > 0) {
        return false;
    }
    else {
        //head�� ���� ��� number��
        string num_str1 = "", num_str2 = "";
        int number1, number2;
        for (int a = head1.size(); a < str1.size(); a++) {
            if (str1[a] >= '0' && str1[a] <= '9')    num_str1.push_back(str1[a]);
            else    break;
        }
        for (int a = head2.size(); a < str2.size(); a++) {
            if (str2[a] >= '0' && str2[a] <= '9')    num_str2.push_back(str2[a]);
            else    break;
        }
        number1 = string_to_int(num_str1);
        number2 = string_to_int(num_str2);
        return number1 < number2;
    }
}

void to_lower_character(string& str) {
    for (int a = 0; a < str.size(); a++) {
        if (str[a] >= 'A' && str[a] <= 'Z')  str[a] += 32;
    }
}

int string_to_int(string& str) {
    int ret = 0, temp = 1;
    for (int a = str.size() - 1; a >= 0; a--) {
        ret += (int)(str[a] - '0') * temp;
        temp *= 10;
    }

    return ret;
}