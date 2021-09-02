/*
문제 링크 : https://www.acmicpc.net/problem/16637
완전탐색을 통해 해결할 수 있는 문제이다.
모든 괄호의 조합을 만든 뒤 하나하나 계산해보며 최댓값을 구하면 된다.
*/
#include <iostream>
using namespace std;

long long answer = -999999999999;

void Get_Answer(const int N, const int nums[10], const char operators[9], int flag[9], int step);	//정답을 도출하는 함수
void Calculate(const int N, const int nums[10], const char operators[9], int flag[9]);	//괄호의 조합을 마친 후 실질적으로 계산하고 answer값과 비교하는 함수

int main(void) {
	int N, nums[10];	//nums에는 입력값의 정수들을 저장
	char operators[9];	//operators에는 입력값의 연산자들을 저장

	cin >> N;

	//입력 문자열을 연산자와 정수별로 따로 저장
	for (int i = 0; i < N / 2; i++) {
		cin >> nums[i];
		cin >> operators[i];
	}
	cin >> nums[(N / 2)];

	//N의 길이가 1인 경우 예외처리
	if (N == 1) {
		cout << nums[0];
		return 0;
	}

	//N의 길이가 3인 경우 예외처리
	if (N == 3) {
		if (operators[0] == '+')	cout << nums[0] + nums[1];
		else if (operators[0] == '-')	cout << nums[0] - nums[1];
		else cout << nums[0] * nums[1];
		return 0;
	}

	//flag는 각 연산자가 괄호 안에 있는지 없는지를 나타낸다(1이면 괄호 안, 0이면 괄호 밖을 의미)
	int flag[9];
	for (int i = 0; i < N / 2; i++)	flag[i] = 0;

	Get_Answer(N, nums, operators, flag, 0);
	cout << answer;

	return 0;
}

void Get_Answer(const int N, const int nums[10], const char operators[9], int flag[9], int step) {
	if (step == 0) {
		Get_Answer(N, nums, operators, flag, step + 1);
		flag[0] = 1;
		Get_Answer(N, nums, operators, flag, step + 1);
	}
	else if (step == N / 2) {
		Calculate(N, nums, operators, flag);
		return;
	}
	else {
		if (flag[step - 1] == 0) {
			Get_Answer(N, nums, operators, flag, step + 1);
			flag[step] = 1;
			Get_Answer(N, nums, operators, flag, step + 1);
			flag[step] = 0;
		}
		else {
			Get_Answer(N, nums, operators, flag, step + 1);
		}
	}
}

void Calculate(const int N, const int nums[10], const char operators[9], int flag[9]) {
	int new_nums[10];	//new_nums에는 괄호 연산을 먼저 한 후 새롭게 만들어진 숫자 순서를 저장
	char new_operators[9];	//new_operators에는 괄호 연산을 먼저 한 후 남은 연산자들을 순서대로 저장
	int nums_index = 0, operators_index = 0, temp;	//각각 new_nums와 new_operators의 유의미한 값을 가지는 마지막 요소를 가르킴
	int ret = 0;

	//연산자들을 앞에서 부터 살피며 괄호 연산을 먼저 처리하고 괄호가 없는 새로운 연산식을 생성한다
	for (int i = 0; i < N / 2; i++) {
		if (flag[i] == 0) {
			if (i == (N / 2) - 1) {
				new_nums[nums_index++] = nums[i];
				new_nums[nums_index++] = nums[i + 1];
				new_operators[operators_index++] = operators[i];
				break;
			}
			new_nums[nums_index++] = nums[i];
			new_operators[operators_index++] = operators[i];
		}
		else {
			if (operators[i] == '+')	temp = nums[i] + nums[i + 1];
			else if (operators[i] == '-')	temp = nums[i] - nums[i + 1];
			else	temp = nums[i] * nums[i + 1];
			if (i == (N / 2) - 1) {
				new_nums[nums_index++] = temp;
				break;
			}
			new_nums[nums_index++] = temp;
			new_operators[operators_index++] = operators[i + 1];
			i++;
			if (i == (N / 2) - 1)	new_nums[nums_index++] = nums[i + 1];
		}
	}
	//새롭게 만들어진 연산식을 앞에서부터 계산한다
	for (int i = 0; i < operators_index; i++) {
		if (i == 0) {
			if (new_operators[i] == '+')	ret = new_nums[i] + new_nums[i + 1];
			else if (new_operators[i] == '-')	ret = new_nums[i] - new_nums[i + 1];
			else	ret = new_nums[i] * new_nums[i + 1];
		}
		else {
			if (new_operators[i] == '+')	ret = ret + new_nums[i + 1];
			else if (new_operators[i] == '-')	ret = ret - new_nums[i + 1];
			else ret = ret * new_nums[i + 1];
		}
	}
	//최댓값을 계속해서 업데이트 한다
	if (ret > answer)	answer = ret;
}