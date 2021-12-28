/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/42840
����Ž������ �ذ��� �� �ִ� ������.

�� �����ڵ��� ��� ���ϰ� answers�� ���Ͽ� ������ ���� ������ ���� ����� ��, ���� ���� ���� ����� ��ȣ�� answer�� �־��ָ� �ȴ�.
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int one[5] = { 1, 2, 3, 4, 5 };
    int two[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int three[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int correct[3], max = -1;

    correct[0] = 0;
    correct[1] = 0;
    correct[2] = 0;
    //���� ���� ���
    for (int a = 0; a < answers.size(); a++) {
        if (answers[a] == one[a % 5]) correct[0]++;
        if (answers[a] == two[a % 8]) correct[1]++;
        if (answers[a] == three[a % 10])  correct[2]++;
    }
    //���� ���� ���� ����� ���� ����
    for (int a = 0; a < 3; a++) {
        if (correct[a] > max)    max = correct[a];
    }
    //answer�� ���� ���� ����� ��ȣ �ֱ�
    for (int a = 0; a < 3; a++) {
        if (correct[a] == max)   answer.push_back(a + 1);
    }

    return answer;
}