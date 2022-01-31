/*
문제 링크 : https://swexpertacademy.com/main/main.do
일종의 투 포인터와 유사한 문제라 생각한다.

소와 말 간의 거리가 최소인 경우와 그런 경우가 총 몇 가지인지를 파악해야한다.

따라서 현재까지 알아낸 최소 거리보다 더 큰 경우의 비교는 하지 않아도 된다.

이를 위해 소들의 위치 말들의 위치를 정렬을 해주었다.

그런 다음 포인터를 두 개 두어 소와 말의 거리를 비교하며 가장 짧은 거리와 그러한 경우의 카운트를 갱신해주었다.

포인터를 어떻게 조작하였는지는 아래 코드를 보면 쉽게 이해할 수 있을 것이다.
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int cow[500000], horse[500000];

int main(int argc, char** argv)
{
	int T, N, M, c1, c2, dist, count, idx1, idx2;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 정렬
		scanf("%d %d", &N, &M);
		scanf("%d %d", &c1, &c2);
		for (int a = 0; a < N; a++)	scanf("%d", &cow[a]);
		for (int a = 0; a < M; a++)	scanf("%d", &horse[a]);
		sort(cow, cow + N);
		sort(horse, horse + M);
		//idx1은 현재 비교하는 소의 인덱스, idx2는 말의 인덱스를 의미
		dist = 1000000000;
		count = 0;
		idx1 = 0;
		idx2 = 0;
		while (idx1 != N && idx2 != M) {	
			if (cow[idx1] > horse[idx2]) {	//소의 위치가 말의 위치보다 큰 경우
				if (cow[idx1] - horse[idx2] < dist) {	//현재 쌍이 가장 짧은 거리인 경우 dist를 갱신하고 count를 1로 설정
					dist = cow[idx1] - horse[idx2];
					count = 1;
				}
				else if (cow[idx1] - horse[idx2] == dist) {	//현재 쌍이 지금까지 발견한 가장 짧은 거리와 같다면 count를 1 높인다
					count++;
				}

				idx2++;	//말의 위치가 소의 위치보다 작기 때문에 말의 인덱스를 늘려 더 짧은 거리의 쌍이 있는지 탐색
			}
			else {	//위와 반대의 경우(기능은 같음)
				if (horse[idx2] - cow[idx1] < dist) {
					dist = horse[idx2] - cow[idx1];
					count = 1;
				}
				else if (horse[idx2] - cow[idx1] == dist) {
					count++;
				}

				idx1++;
			}
		}

		printf("#%d %d %d\n", test_case, dist + max(c1, c2) - min(c1, c2), count);
	}
	return 0;
}