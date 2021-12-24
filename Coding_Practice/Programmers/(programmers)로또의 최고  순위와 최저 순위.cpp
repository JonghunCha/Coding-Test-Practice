/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/77484
단순한 구현 문제다.

우선 맞춘 번호의 갯수와 0으로 표시된 갯수를 구한다.

최고 순위는 0으로 표시된 수를 모두 맞췄을 때이고, 최저 순위는 0으로 표시된 수를 모두 틀렸을 경우이다.
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int correct_num = 0, zero_num = 0;
    //lottos와 win_nums를 비교하며 correct_num과 zero_num을 구한다.
    for (int a = 0; a < 6; a++) {
        if (lottos[a] == 0) {
            zero_num++;
            continue;
        }
        for (int b = 0; b < 6; b++) {
            if (lottos[a] == win_nums[b])    correct_num++;
        }
    }
    //최고 순위 계산
    if (correct_num + zero_num < 2)  answer.push_back(6);
    else    answer.push_back(7 - (correct_num + zero_num));
    //최저 순위 계산
    if (correct_num < 2) answer.push_back(6);
    else    answer.push_back(7 - correct_num);

    return answer;
}