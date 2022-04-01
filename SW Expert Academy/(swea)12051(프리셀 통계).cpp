/*
문제 링크 : https://swexpertacademy.com/main/main.do

가장 중요한 것은 Pd를 만족하기 위해 오늘 한 게임수 D가 최소 몇 번인지가 중요하다.

이는 100과 Pd사이의 최대 공약수를 구한 뒤 100에서 최대 공약수를 나눈 값이다.

이외는 승률이 0, 100퍼센트와 같은 예외 사항만 처리하면 된다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int get_count(int a, int b);

int main(int argc, char** argv)
{
	int T, Pd, Pg, count;
	long long N;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%lld %d %d", &N, &Pd, &Pg);

		if (Pd == 0) {
			if (Pg == 100)	printf("#%d Broken\n", test_case);
			else	printf("#%d Possible\n", test_case);
		}
		else if (Pd == 100) {
			if (Pg == 0)	printf("#%d Broken\n", test_case);
			else	printf("#%d Possible\n", test_case);
		}
		else {
			count = get_count(100, Pd);
			if(Pg == 100 || Pg == 0 || count > N)	printf("#%d Broken\n", test_case);
			else	printf("#%d Possible\n", test_case);
		}

	}
	return 0;
}

int get_count(int a, int b) {
	if (a % b == 0)	return 100 / b;
	else return get_count(max(a - b, b), min(a - b, b));
}