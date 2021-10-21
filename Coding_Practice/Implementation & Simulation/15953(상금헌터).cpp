/*
문제 링크 : https://www.acmicpc.net/problem/15953
카카오 코드 페스티벌 2018 예선에 나온 문제라서 풀어보았다.

아무래도 가장 난이도가 낮은 문제라 그런지 기본적인 조건문만 구현하는 문제이다.
*/
#include <iostream>
using namespace std;

int main(void) {
	int T, input1, input2, answer;

	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> input1 >> input2;
		answer = 0;
		if (input1 == 1)	answer += 5000000;
		else if (input1 > 1 && input1 <= 3)	answer += 3000000;
		else if (input1 > 3 && input1 <= 6)	answer += 2000000;
		else if (input1 > 6 && input1 <= 10)	answer += 500000;
		else if (input1 > 10 && input1 <= 15)	answer += 300000;
		else if (input1 > 15 && input1 <= 21)	answer += 100000;
		if (input2 == 1)	answer += 5120000;
		else if (input2 > 1 && input2 <= 3)	answer += 2560000;
		else if (input2 > 3 && input2 <= 7)	answer += 1280000;
		else if (input2 > 7 && input2 <= 15)	answer += 640000;
		else if (input2 > 15 && input2 <= 31)	answer += 320000;
		cout << answer << endl;
	}
	return 0;
}