/*
문제 링크 : https://swexpertacademy.com/main/main.do
모든 점이 동시에 원점에 있기 위해선 초기의 점들과 원점사이의 거리가 모두 짝수이거나 홀수이어야 한다.
(i번째까지의 이동에서 모든 점은 똑같은 횟수만큼 움직여야 하는데 만약 어떤 점은 원점까지의 거리가 짝수고, 어떤 점은 홀수라면 동시에 원점에 도달할 수 없기 때문)

따라서 위의 조건을 통해 정답이 -1인 경우를 먼저 걸러낼 수 있다.

이제 정확히 몇 번의 이동을 통해 모든 점을 동시에 원점으로 만드느냐인데, 이는 초기에 원점과의 거리가 가장 먼 점이 중요하다.

i번째까지의 움직임 횟수는 가장 먼 점의 거리보다 커야하며, 그 차이는 짝수여야한다.
(이미 원점에 도달한 이후 남은 움직임을 채우고 다시 원점으로 오기위해선 짝수이어야 함)

아래 코드를 보면 쉽게 이해할 수 있을 것이다.
*/
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int T, N, location[10][2];
	long long distance[10], dist, max_dist, sum;
	bool is_possible;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장
		scanf("%d", &N);
		max_dist = -1;
		for (int a = 0; a < N; a++) {
			scanf("%d %d", &location[a][0], &location[a][1]);
			//각 점과 원점사이의 거리를 구한다
			dist = 0;
			if (location[a][0] > 0)	dist += location[a][0];
			else	dist -= location[a][0];
			if (location[a][1] > 0)	dist += location[a][1];
			else	dist -= location[a][1];
			distance[a] = dist;
			//원점과 가장 먼 점 사이의 거리를 구한다
			if (dist > max_dist)	max_dist = dist;
		}
		//모든 점과 원점사이의 거리가 모두 홀수 혹은 짝수인 경우만 다음 단계로 진행
		is_possible = true;
		for (int a = 1; a < N; a++) {
			if ((distance[0] % 2) != (distance[a] % 2)) {
				printf("#%d -1\n", test_case);
				is_possible = false;
				break;
			}
		}
		if (!is_possible)	continue;
		//i번째까지의 이동이 max_dist보다 크며 그 차이가 짝수인 경우 정답 출력
		sum = 0;
		for (int a = 0; a <= 100000; a++) {
			sum += a;

			if (sum >= max_dist && (sum - max_dist) % 2 == 0) {
				printf("#%d %d\n", test_case, a);
				break;
			}
		}
	}
	return 0;
}