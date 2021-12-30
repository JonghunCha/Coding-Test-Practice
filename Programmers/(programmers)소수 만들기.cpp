/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/12977
����Ž���� �̿��Ͽ� �ذ��� �� �ִ� ������.

nums���� ���� �ٸ� 3���� ���ڸ� ���� ��� ��쿡 ���� �ش� ���ڵ��� ���� �Ҽ����� �ƴ����� �Ǻ��ϸ� �ȴ�.

3���� ���� �ٸ� ���� 3�� for������ ������ �� �ִ�.

�Ҽ��� 2���� �����ؼ� ������ �ش� ������ �۰ų� ���� ������ �������� �� �������� 0�� ��찡 ���� ���̴�.
*/
#include <vector>
#include <iostream>
using namespace std;

bool is_prime(int n);

int solution(vector<int> nums) {
    int answer = 0;
    //���� �ٸ� �� ���� ���ڸ� ���� �� ���� �Ҽ����� �Ǻ�
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
    //�������� �ϳ��� 0�� ��� �Ҽ��� �ƴϸ�, ��� 0�� �ƴ϶�� �Ҽ��̴�
    for (int a = 2; a * a <= n; a++) {
        if (n % a == 0)  return false;
    }
    return true;
}