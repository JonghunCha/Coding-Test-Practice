/*
문제 링크 : https://swexpertacademy.com/main/main.do
대각선 길을 이용할 수 있는 경우와 그렇지 않은 경우를 구별하면 쉽게 해결할 수 있다.

대각선 길을 이용하는 경우가 효율적인 경우는 출발지의 x, y가 목적지의 x, y보다 둘 다 크거나 작은 경우이다.

이 부분만 이해하면 쉽게 해결할 수 있는 문제다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int T, W, H, N, curr_x, curr_y, dst_x, dst_y, answer;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장
		scanf("%d %d %d", &W, &H, &N);
		answer = 0;
		//초기 출발지 지정
		scanf("%d %d", &curr_x, &curr_y);
		//다른 목적지들을 이동하며 answer 갱신
		for (int a = 1; a < N; a++) {
			scanf("%d %d", &dst_x, &dst_y);

			if ((dst_x <= curr_x && dst_y <= curr_y) || (dst_x >= curr_x && dst_y >= curr_y)) {	//대각선 길을 이용하는 경우
				answer += max(max(curr_x, dst_x) - min(curr_x, dst_x), max(curr_y, dst_y) - min(curr_y, dst_y));
			}
			else {	//대각선 길을 이용하지 않는 경우
				answer += max(curr_x, dst_x) - min(curr_x, dst_x);
				answer += max(curr_y, dst_y) - min(curr_y, dst_y);
			}
			curr_x = dst_x;
			curr_y = dst_y;
		}

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}