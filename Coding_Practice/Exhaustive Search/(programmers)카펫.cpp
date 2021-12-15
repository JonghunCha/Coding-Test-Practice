/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42842
�ܼ��� ���� Ž�� ������.

�־��� ���ѻ��׿� ���� ������ ������ 3 ~ 2500 �����̴�.

���� ������ ���� 2 * (���α��� + ���α���) - 4 �̸� ����� ������ ���� (���α��� - 2) * (���α��� - 2)�̴�.

���� ������ ��� ���α���, ���α��� ���տ� ���� ���� ������ ���� ����� ������ ���� �ùٸ��� ������ ��츦 �����ϸ� �ȴ�.
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    //a�� ����, b�� ���α���
    for (int a = 3; a <= 2500; a++) {
        for (int b = a; b <= 2500; b++) {
            if ((a - 2) * (b - 2) == yellow && 2 * (a + b) - 4 == brown) {
                answer.push_back(b);
                answer.push_back(a);
            }
        }
    }

    return answer;
}