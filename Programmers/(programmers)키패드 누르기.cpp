/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/67256
���̵� 1�� �����̰� ���������� ��� ���� �״�� �ٷ� �ذ��� �� �ִ� ������.

���� ������ ������ ���� �ʰڴ�.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//�� �ε����� ������ ��ȣ�� �ǹ��ϸ� 10�� 11�� ���� *, #�� �ǹ�
int dx[12] = { 3, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3 };
int dy[12] = { 1, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 2 };

int get_dist(int loc1, int loc2);

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10, right = 11, dist_left, dist_right;

    for (int a = 0; a < numbers.size(); a++) {
        if (numbers[a] == 1 || numbers[a] == 4 || numbers[a] == 7) {    //1, 4, 7�� ��� �޼� ���
            answer.push_back('L');
            left = numbers[a];
        }
        else if (numbers[a] == 3 || numbers[a] == 6 || numbers[a] == 9) {   //3, 6, 9�� ��� ������ ���
            answer.push_back('R');
            right = numbers[a];
        }
        else {
            dist_left = get_dist(left, numbers[a]);
            dist_right = get_dist(right, numbers[a]);
            if (dist_left < dist_right) {   //�޼տ��� �� ����� ���
                answer.push_back('L');
                left = numbers[a];
            }
            else if (dist_left > dist_right) {  //�����տ��� �� ����� ���
                answer.push_back('R');
                right = numbers[a];
            }
            else {  //�Ÿ��� ���� ��
                if (hand == "right") {  //������������ ���
                    answer.push_back('R');
                    right = numbers[a];
                }
                else {  //�޼������� ���
                    answer.push_back('L');
                    left = numbers[a];
                }
            }
        }
    }

    return answer;
}
//�� ���������� �Ÿ��� ���ϴ� �Լ�
int get_dist(int loc1, int loc2) {
    int ret = 0;
    ret += max(dx[loc1], dx[loc2]) - min(dx[loc1], dx[loc2]);
    ret += max(dy[loc1], dy[loc2]) - min(dy[loc1], dy[loc2]);
    return ret;
}