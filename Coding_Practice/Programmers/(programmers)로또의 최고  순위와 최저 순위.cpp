/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/77484
�ܼ��� ���� ������.

�켱 ���� ��ȣ�� ������ 0���� ǥ�õ� ������ ���Ѵ�.

�ְ� ������ 0���� ǥ�õ� ���� ��� ������ ���̰�, ���� ������ 0���� ǥ�õ� ���� ��� Ʋ���� ����̴�.
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int correct_num = 0, zero_num = 0;
    //lottos�� win_nums�� ���ϸ� correct_num�� zero_num�� ���Ѵ�.
    for (int a = 0; a < 6; a++) {
        if (lottos[a] == 0) {
            zero_num++;
            continue;
        }
        for (int b = 0; b < 6; b++) {
            if (lottos[a] == win_nums[b])    correct_num++;
        }
    }
    //�ְ� ���� ���
    if (correct_num + zero_num < 2)  answer.push_back(6);
    else    answer.push_back(7 - (correct_num + zero_num));
    //���� ���� ���
    if (correct_num < 2) answer.push_back(6);
    else    answer.push_back(7 - correct_num);

    return answer;
}