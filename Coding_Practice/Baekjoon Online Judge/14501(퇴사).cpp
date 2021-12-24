/*
문제 링크 : https://www.acmicpc.net/problem/14501
Dynamic Programming으로 해결할 수 있는 문제다.

전체 문제를 "n일차에 상담을 시작한다고 했을 때 얻을 수 있는 최대 보상" 이라는 하위 문제로 나눈다. 점화식은 아래와 같다.

answer(i) = max(answer(i+1), answer(i+T[i]) + P[i]))

answer(i)는 i번째 일부터 상담을 시작할 때 얻을 수 있는 최대 보상을 의미하고, i번째 날짜의 상담을 듣는 경우와 듣지 않는 경우에서 더 큰 보상을 선택하도록 한다.
*/
#include <iostream>
using namespace std;

int N, T[16], P[16], DP[16];

int Get_Answer(int date);

int main(void) {
	//입력값 저장
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i]; cin >> P[i];
		DP[i] = -1;
	}
	//1일차에 시작하는 경우 최대 보상을 구한다
	cout << Get_Answer(1);
	return 0;
}

int Get_Answer(int date) {
	int ret1, ret2;
	if (date == N + 1)	return 0;
	//상담이 불가능한 경우가 선택되지 않도록 보상을 -999999로 반환
	if (date > N + 1)	return -999999;
	if (DP[date] != -1)	return DP[date];
	ret1 = Get_Answer(date + 1);	//date날짜의 상담을 받지 않는 경우
	ret2 = Get_Answer(date + T[date]) + P[date];	//date날짜의 상담을 받는 경우
	if (ret1 > ret2) {
		DP[date] = ret1;
		return ret1;
	}
	else {
		DP[date] = ret2;
		return ret2;
	}
}