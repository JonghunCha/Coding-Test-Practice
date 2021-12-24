/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43165
DFS로 해결할 수 있는 문제다.

최대 20개의 숫자가 주어지기 때문에 각각의 부호에 대해 모두 완전 탐색을 하더라도 2^20 = 1048576개의 조합을 탐색하면 된다.

따라서 DFS를 통해 각 숫자의 부호를 정해주고, 모두 정해졌다면 계산 후 target과 일치하는지 확인해주었다.
*/
#include <string>
#include <vector>

using namespace std;

void DFS(vector<int>& numbers, int target, int& answer, int signs[20], int index);

int solution(vector<int> numbers, int target) {
    int answer = 0, signs[20];
    //signs는 각 숫자의 부호를 의미하며 -1은 지정되지 않은 상태, 0은 -, 1은 +를 의미
    for (int a = 0; a < numbers.size(); a++)  signs[a] = -1;
    DFS(numbers, target, answer, signs, 0);

    return answer;
}

void DFS(vector<int>& numbers, int target, int& answer, int signs[20], int index) {
    if (index == numbers.size()) {  //모든 수의 부호가 지정된 경우 계산하고 target과 값 비교
        int sum = 0;
        for (int a = 0; a < numbers.size(); a++) {
            if (signs[a] == 0)   sum -= numbers[a];
            else    sum += numbers[a];
        }
        if (sum == target)   answer++;
        return;
    }
    //현재 index의 수를 -로 계산할 때
    signs[index] = 0;
    DFS(numbers, target, answer, signs, index + 1);
    //현재 index의 수를 +로 계산할 때
    signs[index] = 1;
    DFS(numbers, target, answer, signs, index + 1);

    return;
}