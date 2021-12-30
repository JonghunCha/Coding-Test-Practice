/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/12977
완전탐색을 이용하여 해결할 수 있는 문제다.

nums에서 서로 다른 3개의 숫자를 고르는 모든 경우에 대해 해당 숫자들의 합이 소수인지 아닌지를 판별하면 된다.

3개의 서로 다른 수는 3중 for문으로 선택할 수 있다.

소수는 2부터 시작해서 제곱이 해당 수보다 작거나 같은 수까지 나누었을 때 나머지가 0인 경우가 없눈 수이다.
*/
#include <vector>
#include <iostream>
using namespace std;

bool is_prime(int n);

int solution(vector<int> nums) {
    int answer = 0;
    //서로 다른 세 개의 숫자를 고르고 그 합을 소수인지 판별
    for (int a = 0; a <= nums.size() - 3; a++) {
        for (int b = a + 1; b <= nums.size() - 2; b++) {
            for (int c = b + 1; c <= nums.size() - 1; c++) {
                if (is_prime(nums[a] + nums[b] + nums[c]))   answer++;
            }
        }
    }

    return answer;
}

bool is_prime(int n) {
    //나머지가 하나라도 0인 경우 소수가 아니며, 모두 0이 아니라면 소수이다
    for (int a = 2; a * a <= n; a++) {
        if (n % a == 0)  return false;
    }
    return true;
}