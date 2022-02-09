/*
문제 링크 : https://swexpertacademy.com/main/main.do
다른 난이도 4 문제와 비교하면 굉장히 쉬운 문제다.

쉬운 문제니 별도의 설명은 정리하지 않았다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int T, x1, y1, x2, y2, row, col, big, small;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		row = max(x1, x2) - min(x1, x2);
		col = max(y1, y2) - min(y1, y2);
		big = max(row, col);
		small = min(row, col);

		while (big - small > 1)	small += 2;	//가로와 세로 중 큰 것에 도달할 때까지 작은 것은 의미 없는 이동을 반복

		printf("#%d %d\n", test_case, big + small);
	}
	return 0;
}