/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/17681
��Ʈ ������ ���� �ذ��� �� �ִ� ������.

�켱 ��ü ������ | ������ ���� ���Ѵ�.

�׷� ���� �� �ٿ� �ش��ϴ� ���� n��° �ڸ��� 1�� ���õ� ���� & ������ ���� Ư�� ��ǥ�� ������ �ƴ��� �˾Ƴ��� �ȴ�.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int my_pow(int times);

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<int> entire_map;
    vector<string> answer;
    string temp;
    int power_of_2;
    //��ü ������ �� �� �� int�� ���
    for (int a = 0; a < n; a++) {
        entire_map.push_back(arr1[a] | arr2[a]);
    }
    //��ǥ �ϳ��ϳ��� ���� ������ �� �������� & ������ ���� �˾Ƴ���
    for (int a = 0; a < n; a++) {
        temp.clear();
        for (int b = n - 1; b >= 0; b--) {
            power_of_2 = my_pow(b);

            if (entire_map[a] & power_of_2)  temp.push_back('#');
            else    temp.push_back(' ');
        }
        answer.push_back(temp);
    }

    return answer;
}
//2�� times�� ���� ���� ����
int my_pow(int times) {
    if (times == 0)  return 1;

    int ret = 1;
    for (int a = 0; a < times; a++) {
        ret *= 2;
    }

    return ret;
}