/*
문제 링크 : https://swexpertacademy.com/main/main.do
큐를 이용하면 되는 문제다.

그러나 왜인지 모르겠지만 기본 입출력 라이브러리 이외에는 다른 라이브러리를 사용하지 못하게 해서 배열을 큐라고 생각하고 풀었다.

문제 자체는 간단해서 코드만 봐도 쉽게 이해할 수 있을 것이다.
*/
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int T, N, A, B, letters[100], answer[100], left, right, num;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 변수 초기화
		scanf("%d %d %d", &N, &A, &B);
		for (int a = 0; a < N; a++)	scanf("%d", &letters[a]);
		left = 0;	//현재 우편함에 있는 편지 중 가장 일찍 도착한 것
		right = 0;	//현재 우편함에 있는 편지 중 가장 늦게 도착한 것

		//시간은 최대 2000까지 가능
		for (int a = letters[0]; a <= 2000; a++) {
			if (left == N)	break;	//모든 편지를 다 읽으면 종료
			if (right + 1 < N && letters[right + 1] <= a)	right++;	//시간 a일 때 도착하는 편지가 있다면 해당 편지의 인덱스를 right로 설정
			//편지가 A개 이상 쌓이거나 가장 오래된 편지가 B시간 이상 지나면 절반 읽기
			if (right - left + 1 >= A || a - letters[left] >= B) {
				if ((right - left + 1) % 2 == 0)	num = (right - left + 1) / 2;
				else	num = ((right - left + 1) / 2) + 1;

				for (int b = left; b < left + num; b++) {
					answer[b] = a;
				}
				left = left + num;
			}
		}

		printf("#%d ", test_case);
		for (int a = 0; a < N; a++)	printf("%d ", answer[a]);
		printf("\n");
	}
	return 0;
}