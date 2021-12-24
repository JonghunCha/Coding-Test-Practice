/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42842
단순한 완전 탐색 문제다.

주어진 제한사항에 의해 정답의 범위는 3 ~ 2500 사이이다.

갈색 격자의 수는 2 * (가로길이 + 세로길이) - 4 이며 노란색 격자의 수는 (가로길이 - 2) * (세로길이 - 2)이다.

따라서 가능한 모든 가로길이, 세로길이 조합에 대해 갈색 격자의 수와 노란색 격자의 수가 올바르게 나오는 경우를 선택하면 된다.
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    //a가 세로, b가 가로길이
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