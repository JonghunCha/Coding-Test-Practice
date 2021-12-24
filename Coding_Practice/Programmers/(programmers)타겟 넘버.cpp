/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/43165
DFS�� �ذ��� �� �ִ� ������.

�ִ� 20���� ���ڰ� �־����� ������ ������ ��ȣ�� ���� ��� ���� Ž���� �ϴ��� 2^20 = 1048576���� ������ Ž���ϸ� �ȴ�.

���� DFS�� ���� �� ������ ��ȣ�� �����ְ�, ��� �������ٸ� ��� �� target�� ��ġ�ϴ��� Ȯ�����־���.
*/
#include <string>
#include <vector>

using namespace std;

void DFS(vector<int>& numbers, int target, int& answer, int signs[20], int index);

int solution(vector<int> numbers, int target) {
    int answer = 0, signs[20];
    //signs�� �� ������ ��ȣ�� �ǹ��ϸ� -1�� �������� ���� ����, 0�� -, 1�� +�� �ǹ�
    for (int a = 0; a < numbers.size(); a++)  signs[a] = -1;
    DFS(numbers, target, answer, signs, 0);

    return answer;
}

void DFS(vector<int>& numbers, int target, int& answer, int signs[20], int index) {
    if (index == numbers.size()) {  //��� ���� ��ȣ�� ������ ��� ����ϰ� target�� �� ��
        int sum = 0;
        for (int a = 0; a < numbers.size(); a++) {
            if (signs[a] == 0)   sum -= numbers[a];
            else    sum += numbers[a];
        }
        if (sum == target)   answer++;
        return;
    }
    //���� index�� ���� -�� ����� ��
    signs[index] = 0;
    DFS(numbers, target, answer, signs, index + 1);
    //���� index�� ���� +�� ����� ��
    signs[index] = 1;
    DFS(numbers, target, answer, signs, index + 1);

    return;
}