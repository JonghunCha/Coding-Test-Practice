/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/68645
2���� �迭�� ������ ä��⸦ ������ �� answer�� ���ϸ� ���� �ذ��� �� �ִ�.

�ﰢ���� ä�� �� ������ �� 3������ ������, �� ���� ��ȯ���� �����ؾ��ϴ� ������ ���� 1�� �پ���.

���� ��� n�� 4�� �� ù 4���� �Ʒ��� �̵�, �� ���� 3���� ���������� �̵�, �� ���� 2���� ����, �� ���� 1���� �Ʒ��� �̵��Ѵ�.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int triangle[1001][1001], index = 1, total = (n * (n + 1)) / 2;
    int x = 0, y = 1, direction = 1, length = n;
   
    while (index <= total) {
        for (int a = 1; a <= length; a++) { //length��ŭ ����
            if (direction == 1) {   //�Ʒ��� �̵��ϴ� ���
                x++;
            }
            else if (direction == 2) {  //���������� �̵��ϴ� ���
                y++;
            }
            else {  //���� �̵��ϴ� ���
                x--;
                y--;
            }
            triangle[x][y] = index++;
        }
        //���� ��ȯ
        if (direction == 1)  direction = 2;
        else if (direction == 2) direction = 3;
        else    direction = 1;
        length--;
    }
    //2���� �迭�� ���� answer�� �Ű��ش�
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= a; b++) {
            answer.push_back(triangle[a][b]);
        }
    }

    return answer;
}