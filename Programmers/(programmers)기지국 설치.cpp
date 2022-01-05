/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/12979
������ ���� Ž�� ������ ������ �� �ִ�.

�켱 n�� �ִ� 200,000,000�̱⿡ n�� ������ ���ϴ� ���� �ð����ѿ� �ɸ� ���ɼ��� ����.

���� stations�� ������ ���� ���İ� ���޵��� �ʴ� ������ ���̸� ���ϰ� �߰� ��ġ�ؾߵ� �������� �÷������� �Ѵ�.
*/
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, curr = 0, range;    //curr�� ���� ��� ����Ʈ���� ���İ� Ȯ���� ���޵Ǵ����� ����, range�� ���İ� ���� �ȵǴ� ������ ���̸� ����

    for (int a = 0; a < stations.size(); a++) {
        if (stations[a] - w > curr) {   //a��° �������� ���ĸ� �޴� ù ����Ʈ���� ���� ����Ʈ�� �� �տ� �ִ� ���(�������� �����ؾ��ϴ� ���)
            range = stations[a] - w - curr - 1; //�� ���� ����Ʈ�� ���ĸ� �� �޴��� ���
            answer += (range / (2 * w + 1));    
            if (range % (2 * w + 1) != 0)  answer++;
        }
        curr = stations[a] + w; //a��° ���������� ���������� w��° ����Ʈ������ ���ĸ� ���� ���� �� ����
    }

    if (curr < n) { //������ �������� ���ĸ� �޴� ����Ʈ ������ ����Ʈ�� �����ִ� ���
        range = n - curr;
        answer += (range / (2 * w + 1));
        if (range % (2 * w + 1) != 0)  answer++;
    }

    return answer;
}