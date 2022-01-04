/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/1843#
DP로 해결할 수 있는 문제다.

문제의 수식은 결국 왼쪽 피연산자, 연산자(+혹은 -), 오른쪽 피연산자로 나눌 수 있다.

따라서 피연산자 갯수가 4개인 수식의 경우 최댓값은 아래와 같이 생각할 수 있다.

1. 가운데 연산자가 + 인 경우
1-1. 0번째 피연산자 + (1~3번째 연산의 최댓값)
1-2. (0~1번째 연산의 최댓값) + (2~3번째 연산의 최댓값)
1-3. (0~2번째 연산의 최댓값) + 3번째 피연산자
2. 가운데 연산자가 - 인 경우
2-1. 0번째 피연산자 - (1~3번째 연산의 최솟값)
2-2. (0~1번째 연산의 최댓값) - (2~3번째 연산의 최솟값)
2-3. (0~2번째 연산의 최댓값) - 3번째 피연산자

위의 규칙을 점화식으로 생각하여 dp로 해결하면 된다.
*/
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

//dp_max[a][b]는 a번째 피연산자부터 b번째 피연산자까지의 연산 최댓값
//dp_min[a][b]는 a번째 피연산자부터 b번째 피연산자까지의 연산 최솟값을 저장
int dp_max[101][101], dp_min[101][101]; 
vector<int> nums;
vector<char> operators;

int strToint(string str);
int DP_MAX(int start, int end);
int DP_MIN(int start, int end);

int solution(vector<string> arr)
{
    //입력 string을 피연산자와 연산자로 나누어 각각 nums와 operators에 담는다
    for (int a = 0; a < arr.size(); a++) {
        if (a % 2 == 0) {
            nums.push_back(strToint(arr[a]));
        }
        else {
            if (arr[a].compare("+") == 0)    operators.push_back('+');
            else    operators.push_back('-');
        }
    }
    //dp배열의 초기화
    for (int a = 0; a < nums.size(); a++) {
        for (int b = 0; b < nums.size(); b++) {
            dp_max[a][b] = -1000000;
            dp_min[a][b] = 1000000;
        }
    }

    return DP_MAX(0, nums.size() - 1);
}
//주어진 string을 int형으로 바꾸는 함수
int strToint(string str) {
    int ret = 0, temp = 1;

    for (int a = str.size() - 1; a >= 0; a--) {
        ret += (int)(str[a] - '0') * temp;
        temp *= 10;
    }

    return ret;
}
//start부터 end까지 연산의 최댓값 계산
int DP_MAX(int start, int end) {
    //이미 계산된 경우 바로 반환
    if (dp_max[start][end] != -1000000)  return dp_max[start][end];
    //end와 start가 같은 경우 start번째 피연산자 자신을 의미
    if (end == start) {
        dp_max[start][end] = nums[start];
        return dp_max[start][end];
    }
    //end가 start보다 1크다면 점화식 필요없이 계산값은 정해져 있음
    if (end - start == 1) {
        if (operators[start] == '+') {
            dp_max[start][end] = nums[start] + nums[end];
        }
        else {
            dp_max[start][end] = nums[start] - nums[end];
        }
        return dp_max[start][end];
    }
    //맨 위 주석의 점화식을 구현한 부분
    for (int a = 0; a < end - start; a++) {
        if (operators[start + a] == '+') {  //연산자가 + 인 경우
            dp_max[start][end] = max(dp_max[start][end], DP_MAX(start, start + a) + DP_MAX(start + a + 1, end));
        }
        else {  //연산자가 - 인 경우
            dp_max[start][end] = max(dp_max[start][end], DP_MAX(start, start + a) - DP_MIN(start + a + 1, end));
        }
    }
    return dp_max[start][end];
}
//DP_MAX와 비슷하게 동작(최댓값을 구하는 부분을 최솟값 구하는 부분으로 바뀌었다는 차이만 있음)
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