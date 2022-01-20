/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/17682
���ڿ� �Ľ̸� �ϰ� ���� �������� ���� �ذ��� �� �ִ� ������.
*/
#include <string>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0, score[3], num[3], idx_num = 0, idx_bonus = 0, idx_option = -1;
    char bonus[3], option[3];
    //num, bonus, option�� dartResult�� ����, ���ʽ�, �ɼ��� �ǹ�
    for (int a = 0; a < 3; a++) {
        num[a] = 0;
        bonus[a] = 0;
        option[a] = 0;
    }
    //3���� ����, ���ʽ�, �ɼ����� ���ڿ� �Ľ�
    for (int a = 0; a < dartResult.size();) {
        if (a + 1 != dartResult.size() && dartResult[a] == '1' && dartResult[a + 1] == '0') {
            num[idx_num++] = 10;
            idx_option++;
            a += 2;
        }
        else if (dartResult[a] >= '0' && dartResult[a] <= '9') {
            num[idx_num++] = (int)(dartResult[a] - '0');
            idx_option++;
            a++;
        }
        else if (dartResult[a] == 'S' || dartResult[a] == 'D' || dartResult[a] == 'T') {
            bonus[idx_bonus++] = dartResult[a];
            a++;
        }
        else {
            option[idx_option] = dartResult[a];
            a++;
        }
    }
    //������ ������ ���
    int temp;
    for (int a = 0; a < 3; a++) {
        temp = num[a];
        if (bonus[a] == 'S') {
            score[a] = temp;
        }
        else if (bonus[a] == 'D') {
            score[a] = temp * temp;
        }
        else {
            score[a] = temp * temp * temp;
        }

        if (option[a] == '*') {
            score[a] = 2 * score[a];
            if (a >= 1) {
                score[a - 1] = 2 * score[a - 1];
            }
        }
        else if (option[a] == '#') {
            score[a] = -score[a];
        }
    }
    //3���� ������ ���ϰ� ��ȯ
    answer = score[0] + score[1] + score[2];
    return answer;
}