/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/68935
10������ 3�������� ��ȯ�� �� �� �˸� ���� ������.

�Ʒ� �ڵ��� ��� 10������ 3���� string���� ��ȯ �� ������ ���� �ٽ� 10�������� ����Ͽ���.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string tenTothree(int n);

int solution(int n) {
    int answer = 0, temp = 1;
    string str;

    str = tenTothree(n);
    for (int a = 0; a < str.size(); a++) {  //������ ����� 10�������� ���
        answer += (int)(str[a] - '0') * temp;
        temp *= 3;
    }

    return answer;
}

string tenTothree(int n) {
    string ret;
    int temp = 1;
    //temp * 3�� n���� �۰ų� ������ temp ����
    while (n >= 3 * temp) {
        temp *= 3;
    }
    //temp�� ���� �ڸ����� ���� �ڸ��� ��������, 1�� �ڸ��� �Ϸ� �� ������ �ݺ�
    while (temp > 0) {
        if (n >= temp && n < 2 * temp) {    //���� �ڸ����� 2�� ���
            ret.push_back('1');
            n -= temp;
        }
        else if (n >= 2 * temp) {   //���� �ڸ����� 1�� ���
            ret.push_back('2');
            n -= 2 * temp;
        }
        else {  //���� �ڸ����� 0�� ���
            ret.push_back('0');
        }
        
        temp /= 3;  //���� �ڸ����� ��������
    }

    return ret;
}