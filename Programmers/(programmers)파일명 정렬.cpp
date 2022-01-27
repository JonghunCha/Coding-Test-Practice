/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/17686
정렬에 관련된 문제인데, 그 중 stable sort로 구현해야만 한다.

head와 number가 같은 경우 처음 입력된 순서를 유지하라고 하였는데, 이를 위해 stable sort가 필요한 것이다.

c++의 algorithm헤더 내에는 sort()와 stable_sort()가 있는데, sort는 quick sort로 구현이 되어있고, stable_sort는 merge_sort로 구현이 되어 있다.

이 문제의 경우 stable_sort를 사용하였다.

나머지는 문자열 파싱인데 쉽게 해결할 수 있을 것이다.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(const string& str1, const string& str2);   //정렬의 비교 함수
void to_lower_character(string& str);   //str의 대문자를 소문자로 바꾸어 주는 함수
int string_to_int(string& str); //str을 int로 변환하여 반환하는 함수

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), compare);

    return files;
}

bool compare(const string& str1, const string& str2) {
    //head를 먼저 비교
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
        //head가 같을 경우 number비교
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