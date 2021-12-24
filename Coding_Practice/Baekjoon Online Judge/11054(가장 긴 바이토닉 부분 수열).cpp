/*
문제 링크 : https://www.acmicpc.net/problem/11054
Dynamic Programming으로 해결할 수 있는 문제다.

우선 문제를 크게 두 부분으로 나누었다.

k번째 수를 기준으로 왼쪽 오른쪽으로 나눈 뒤, 왼쪽에서는 k번째 수가 포함되며 오름차순으로 가장 긴 수열의 길이, 오른쪽에서는 k번째 수가 포함되며 내림차순으로 가장 긴 수열의 길이를 구하였다.

마지막으로 1번째부터 N번째까지 탐색하며 (왼쪽의 오름차순 수열의 길이 + 오른쪽의 내림차순 수열의 길이 - 1)이 가장 큰 것을 출력하면 된다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, A[1002], dp_left[1002], dp_right[1002];

int main(void) {
	int temp, answer = 0;
	//입력값 저장 및 변수 초기화
	cin >> N;
	for (int a = 1; a <= N; a++) {
		cin >> A[a];
		dp_left[a] = -1;
		dp_right[a] = -1;
	}
	A[0] = 0;
	dp_left[0] = 0;
	A[N + 1] = 0;
	dp_right[N + 1] = 0;
	//a번째 수의 왼쪽에서 a번째 수를 포함하며 오름차순으로 가장 긴 수열의 길이 판단
	for (int a = 1; a <= N; a++) {
		for (int b = a - 1; b >= 0; b--) {
			if (A[b] < A[a]) {
				temp = dp_left[b] + 1;
				if (temp > dp_left[a])	dp_left[a] = temp;
			}
		}
	}
	//a번째 수의 오른쪽에서 a번째 수를 포함하며 내림차순으로 가장 긴 수열의 길이 판단
	for (int a = N; a >= 1; a--) {
		for (int b = a + 1; b <= N + 1; b++) {
			if (A[b] < A[a]) {
				temp = dp_right[b] + 1;
				if (temp > dp_right[a])	dp_right[a] = temp;
			}
		}
	}
	//바이토닉 부분 수열이 가장 긴 것을 계산
	for (int a = 1; a <= N; a++) {
		temp = dp_left[a] + dp_right[a] - 1;
		if (temp > answer)	answer = temp;
	}
	cout << answer << endl;
	return 0;
}