/*
문제 링크 : https://swexpertacademy.com/main/main.do
문제 자체는 매우 쉬운 문제다.

x좌표의 막대의 길이는 (1+2....+x)이다.

따라서 a가 x - 1의 좌표 b가 x좌표의 보이는 길이라 했을 때 x = b - a임을 알 수 있다.

이를 이용하여 x좌표의 막대길이에서 b만큼 빼주면 K값을 구할 수 있다.

그런데 시간제한이 문제였다.

입력이 100000개이고 출력도 100000개를 해야하기 때문에 c++의 cin, cout을 사용하면 시간제한에 걸렸다.

c의 scanf와 printf를 사용하니 시간제한 없이 통과 되었다.
*/
#include <iostream>
#include <cstdio>

using namespace std;

int answer[10001];

int main(int argc, char** argv)
{
	int T, a, b, x, length;
	
	answer[0] = 0;
	for (int a = 1; a <= 10000; a++) {
		answer[a] = answer[a - 1] + a;
	}

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &a, &b);
		x = b - a;
		printf("#%d %d\n", test_case, answer[x] - b);
	}
	return 0;
}