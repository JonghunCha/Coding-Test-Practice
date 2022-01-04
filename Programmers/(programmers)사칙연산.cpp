/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/1843#
DP�� �ذ��� �� �ִ� ������.

������ ������ �ᱹ ���� �ǿ�����, ������(+Ȥ�� -), ������ �ǿ����ڷ� ���� �� �ִ�.

���� �ǿ����� ������ 4���� ������ ��� �ִ��� �Ʒ��� ���� ������ �� �ִ�.

1. ��� �����ڰ� + �� ���
1-1. 0��° �ǿ����� + (1~3��° ������ �ִ�)
1-2. (0~1��° ������ �ִ�) + (2~3��° ������ �ִ�)
1-3. (0~2��° ������ �ִ�) + 3��° �ǿ�����
2. ��� �����ڰ� - �� ���
2-1. 0��° �ǿ����� - (1~3��° ������ �ּڰ�)
2-2. (0~1��° ������ �ִ�) - (2~3��° ������ �ּڰ�)
2-3. (0~2��° ������ �ִ�) - 3��° �ǿ�����

���� ��Ģ�� ��ȭ������ �����Ͽ� dp�� �ذ��ϸ� �ȴ�.
*/
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

//dp_max[a][b]�� a��° �ǿ����ں��� b��° �ǿ����ڱ����� ���� �ִ�
//dp_min[a][b]�� a��° �ǿ����ں��� b��° �ǿ����ڱ����� ���� �ּڰ��� ����
int dp_max[101][101], dp_min[101][101]; 
vector<int> nums;
vector<char> operators;

int strToint(string str);
int DP_MAX(int start, int end);
int DP_MIN(int start, int end);

int solution(vector<string> arr)
{
    //�Է� string�� �ǿ����ڿ� �����ڷ� ������ ���� nums�� operators�� ��´�
    for (int a = 0; a < arr.size(); a++) {
        if (a % 2 == 0) {
            nums.push_back(strToint(arr[a]));
        }
        else {
            if (arr[a].compare("+") == 0)    operators.push_back('+');
            else    operators.push_back('-');
        }
    }
    //dp�迭�� �ʱ�ȭ
    for (int a = 0; a < nums.size(); a++) {
        for (int b = 0; b < nums.size(); b++) {
            dp_max[a][b] = -1000000;
            dp_min[a][b] = 1000000;
        }
    }

    return DP_MAX(0, nums.size() - 1);
}
//�־��� string�� int������ �ٲٴ� �Լ�
int strToint(string str) {
    int ret = 0, temp = 1;

    for (int a = str.size() - 1; a >= 0; a--) {
        ret += (int)(str[a] - '0') * temp;
        temp *= 10;
    }

    return ret;
}
//start���� end���� ������ �ִ� ���
int DP_MAX(int start, int end) {
    //�̹� ���� ��� �ٷ� ��ȯ
    if (dp_max[start][end] != -1000000)  return dp_max[start][end];
    //end�� start�� ���� ��� start��° �ǿ����� �ڽ��� �ǹ�
    if (end == start) {
        dp_max[start][end] = nums[start];
        return dp_max[start][end];
    }
    //end�� start���� 1ũ�ٸ� ��ȭ�� �ʿ���� ��갪�� ������ ����
    if (end - start == 1) {
        if (operators[start] == '+') {
            dp_max[start][end] = nums[start] + nums[end];
        }
        else {
            dp_max[start][end] = nums[start] - nums[end];
        }
        return dp_max[start][end];
    }
    //�� �� �ּ��� ��ȭ���� ������ �κ�
    for (int a = 0; a < end - start; a++) {
        if (operators[start + a] == '+') {  //�����ڰ� + �� ���
            dp_max[start][end] = max(dp_max[start][end], DP_MAX(start, start + a) + DP_MAX(start + a + 1, end));
        }
        else {  //�����ڰ� - �� ���
            dp_max[start][end] = max(dp_max[start][end], DP_MAX(start, start + a) - DP_MIN(start + a + 1, end));
        }
    }
    return dp_max[start][end];
}
//DP_MAX�� ����ϰ� ����(�ִ��� ���ϴ� �κ��� �ּڰ� ���ϴ� �κ����� �ٲ���ٴ� ���̸� ����)
int DP_MIN(int start, int end) {
    if (dp_min[start][end] != 1000000)   return dp_min[start][end];

    if (end == start) {
        dp_min[start][end] = nums[start];
        return dp_min[start][end];
    }

    if (end - start == 1) {
        if (operators[start] == '+') {
            dp_min[start][end] = nums[start] + nums[end];
        }
        else {
            dp_min[start][end] = nums[start] - nums[end];
        }
        return dp_min[start][end];
    }

    for (int a = 0; a < end - start; a++) {
        if (operators[start + a] == '+') {
            dp_min[start][end] = min(dp_min[start][end], DP_MIN(start, start + a) + DP_MIN(start + a + 1, end));
        }
        else {
            dp_min[start][end] = min(dp_min[start][end], DP_MIN(start, start + a) - DP_MAX(start + a + 1, end));
        }
    }
    return dp_min[start][end];
}