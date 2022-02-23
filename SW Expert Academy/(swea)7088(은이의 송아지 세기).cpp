/*
문제 링크 : https://swexpertacademy.com/main/main.do
부분합으로 해결해야 하는 문제다.

모든 구간에 대해 일일히 품종을 파악하기엔 시간이 너무 오래 걸린다.

아래 코드를 보면 부분합을 통해 쉽게 해결할 수 있음을 알 수 있다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int sum[100001][4];

int main(int argc, char** argv)
{
	int T, N, Q, input, L, R;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 변수 초기화
		scanf("%d %d", &N, &Q);
		memset(sum, 0, sizeof(int) * 100001 * 4);
		//부분합을 계산 sum[a][1]은 a번째 인덱스까지 나온 1번 품종의 수를 의미
		for (int a = 1; a <= N; a++) {
			scanf("%d", &input);
			sum[a][1] = sum[a - 1][1];
			sum[a][2] = sum[a - 1][2];
			sum[a][3] = sum[a - 1][3];
			if (input == 1)	sum[a][1]++;
			else if (input == 2)	sum[a][2]++;
			else	sum[a][3]++;
		}
		//부분합을 이용한 정답 출력
		printf("#%d\n", test_case);
		for (int a = 1; a <= Q; a++) {
			scanf("%d %d", &L, &R);
			printf("%d %d %d\n", sum[R][1] - sum[L - 1][1], sum[R][2] - sum[L - 1][2], sum[R][3] - sum[L - 1][3]);
		}
	}
	return 0;
}