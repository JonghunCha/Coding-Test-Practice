/*
문제 링크 : https://swexpertacademy.com/main/main.do
난이도는 4라고 나와있으나 그에 비해 많이 쉬운 문제다.

정말 간단하게 차가 이동할 거리를 말이 끝까지 지나가는데 걸리는 시간으로 나누면 정답이다.
*/
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int T, D, horse_num, horses[2][2];
	double time_max, time_temp;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 말이 끝까지 가는데 걸리는 시간 계산
		time_max = 0;
		scanf("%d %d", &D, &horse_num);
		for (int a = 0; a < horse_num; a++) {
			scanf("%d %d", &horses[a][0], &horses[a][1]);
			time_temp = (double)(D - horses[a][0]) / (double)(horses[a][1]);
			if (time_temp > time_max)	time_max = time_temp;
		}

		printf("#%d %lf\n", test_case, D / time_max);
	}
	return 0;
}