/*
문제 링크 : https://swexpertacademy.com/main/main.do
정답 비율이 20퍼센트라 풀어봤는데 입출력때문에 20퍼센트인 것 같을 정도로 쉬운 문제였다.

단순히 두 전구가 동시에 켜진 시간을 구하는 문제로 조건문 몇 개면 쉽게 풀 수 있다.

아래 코드만 봐도 쉽게 이해할 수 있을 것이다.
*/
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int T, A, B, C, D, bulb_first_start, bulb_first_end, bulb_second_start, bulb_second_end;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d %d %d", &A, &B, &C, &D);
		//먼저켜진 전구와 나중에 켜진 전구를 구별
		if (A <= C) {
			bulb_first_start = A;
			bulb_first_end = B;
			bulb_second_start = C;
			bulb_second_end = D;
		}
		else {
			bulb_first_start = C;
			bulb_first_end = D;
			bulb_second_start = A;
			bulb_second_end = B;
		}

		if (bulb_first_end < bulb_second_start) {	//먼저 켜진 전구가 꺼질 때까지 두 번째 전구가 켜지지 않을 경우
			printf("#%d 0\n", test_case);
		}
		else if (bulb_second_end < bulb_first_end) {	//두번째 전구가 켜진 시간이 먼저 켜진 전구 시간에 포함될 때
			printf("#%d %d\n", test_case, bulb_second_end - bulb_second_start);
		}
		else {	//일부만 겹치는 경우
			printf("#%d %d\n", test_case, bulb_first_end - bulb_second_start);
		}
	}
	return 0;
}