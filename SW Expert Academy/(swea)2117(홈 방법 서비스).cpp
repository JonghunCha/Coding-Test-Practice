/*
문제 링크 : https://swexpertacademy.com/main/main.do
완전 탐색으로 해결할 수 있는 문제다.

서비스의 중앙 위치를 가능한 모든 좌표에 대해, K의 크기를 가능한 모든 경우에 대해 탐색하면 된다.
*/
#include <cstdio>
#include <cmath>
using namespace std;

int main(void) {
	int T, N, M, cityinfo[20][20], answer, cost, house_num;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		//입력값 저장
		scanf("%d %d", &N, &M);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				scanf("%d", &cityinfo[a][b]);
			}
		}
		//완전 탐색
		answer = 0;
		for (int a = 0; a < N; a++) {	
			for (int b = 0; b < N; b++) {
				for (int K = 1; K <= 40; K++) {
					cost = (K * K) + ((K - 1) * (K - 1));
					house_num = 0;
					for (int x = 0; x < N; x++) {
						for (int y = 0; y < N; y++) {
							if (cityinfo[x][y] == 1 && (abs(a - x) + abs(b - y)) <= K - 1)	house_num++;
						}
					}
					if (cost <= (house_num * M) && house_num > answer)	answer = house_num;
				}
			}
		}

		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}