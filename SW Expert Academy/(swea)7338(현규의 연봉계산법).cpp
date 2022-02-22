/*
문제 링크 : https://swexpertacademy.com/main/main.do
단순한 구현 문제다.

1년을 12개월에서 13개월로 바꾸었을 때의 변환을 묻는 문제이다.

쉬운 문제라 별다른 설명은 넣지 않겠다.
*/
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int T;
	long long Y, M, count, answer_y, answer_m;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%lld %lld", &Y, &M);
		//2016년 12월과 2016년 13월 예외 처리
		if (Y == 2016) {
			printf("#%d 2016 12\n", test_case);
			continue;
		}
		else if (Y == 2017 && M == 1) {
			printf("#%d 2016 13\n", test_case);
			continue;
		}
		//년월 계산 및 출력
		count = ((Y - 2016) * 12) - (12 - M);
		answer_y = 2017 + ((count - 2) / 13);
		answer_m = (count - 1)  % 13;
		if (answer_m == 0)	answer_m = 13;

		printf("#%d %lld %lld\n", test_case, answer_y, answer_m);
	}
	return 0;
}