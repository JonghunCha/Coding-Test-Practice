/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/17687
���� ��ȯ�� �� �ٸ� �˸� ���� �ذ��� �� �ִ�.

������ ���ǿ� ���� n������ ���� �� �������� �� ���̰� t*m�� �Ǵ� �κб����� ���� �� Ʃ�갡 ���ؾ� �ϴ� ������ ���ڸ� ���� �����ϸ� �ȴ�.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

char c[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

void int_to_n(int num, int n, string& str);

string solution(int n, int t, int m, int p) {
    int num = 0;
    string answer = "";
    string str;
    //str�� ����� t*m�̻��� �� ������ num�� n�������� �ٲپ� str�� �־��ش�
    while (str.size() <= t * m) {
        int_to_n(num++, n, str);
    }
    //Ʃ�갡 ���ؾ��ϴ� ���ڵ��� ����
    for (int a = 0; a < t; a++) {
        answer.push_back(str[p - 1 + (a * m)]);
    }

    return answer;
}

void int_to_n(int num, int n, string& str) {
    if ((num / n) > 0) {    //num�� n�������� �ٲپ��� �� �ڸ����� 2 �̻��� ���
        int_to_n(num / n, n, str);
        int_to_n(num % n, n, str);
    }
    else {  //�ڸ����� 1�� ��� �ٷ� str�� �ִ´�
        str.push_back(c[num]);
    }
}