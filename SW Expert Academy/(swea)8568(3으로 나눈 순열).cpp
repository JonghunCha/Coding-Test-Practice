/*
문제 링크 : https://swexpertacademy.com/main/main.do
난이도4에 비해 쉬운 문제다.

교환하는 값이 최솟값이 되려면 한 번의 교환으로 2개의 잘못된 위치를 수정하는 것을 최대화 해야 한다.

따라서 mod의 결과가 서로 뒤바뀐 위치에 있는 것들끼리 먼저 교환을 한다. 

그런 다음 남은 나머지들은 3개가 서로 맞물려서 섞인 상태일 텐데 이 경우 3개의 오류를 잡기 위해선 2번의 교환이 필요하다.

따라서, 정답은 (2개가 서로 바뀐 것의 갯수 + (3개가 서로 바뀐 것의 갯수 * 2) / 3)이다.
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int T, N, inputs[1000], count[3][3], answer;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 변수 초기화
		scanf("%d", &N);
		memset(count, 0, sizeof(int) * 9);
		for (int a = 1; a <= N; a++) {
			scanf("%d", &inputs[a]);
			count[a % 3][inputs[a] % 3]++;
		}
		answer = 0;
		//2개의 위치가 서로 뒤바뀐 경우의 갯수 
		answer += min(count[1][0], count[0][1]);
		answer += min(count[2][0], count[0][2]);
		answer += min(count[1][2], count[2][1]);
		//3개의 위치가 서로 엉켜있는 경우의 갯수 계산
		int sum = 0;
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				sum += count[a][b];
			}
		}
		sum = sum - count[0][0] - count[1][1] - count[2][2];
		sum = sum - (2 * answer);

		answer += (2 * sum) / 3;
		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}