/*
문제 링크 : https://swexpertacademy.com/main/main.do
이분 탐색으로 해결해야 하는 문제다.

최소 시간은 0, 최대 시간은 10^18이다. 따라서 완전 탐색이 아닌 이분 탐색으로 정답을 도출해야 시간초과에 걸리지 않는다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int T, N, M, tk[100000];
	long long answer, left, right, mid, sum;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &N, &M);
		for (int a = 0; a < N; a++) {
			scanf("%d", &tk[a]);
		}

		answer = 1000000000000000000;
		left = 1;
		right = 1000000000000000000;
		while (left <= right) {
			mid = (left + right) / 2;
			sum = 0;
			//mid만큼의 시간을 썻을 때 몇명의 입국심사를 마칠 수 있는지 계산
			for (int a = 0; a < N; a++) {
				sum += mid / tk[a];
			}
			
			if (sum >= M) {	//sum이 M보다 크거나 같다면 시간을 줄일 수 있는 여지가 있다
				answer = min(answer, mid);
				right = mid - 1;
			}
			else {	//sum이 M보다 작다면 시간을 더 늘려줘야 한다
				left = mid + 1;
			}
		}

		printf("#%d %lld\n", test_case, answer);
	}

	return 0;
}