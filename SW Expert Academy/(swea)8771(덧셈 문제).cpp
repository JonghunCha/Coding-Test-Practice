/*
문제 링크 : https://swexpertacademy.com/main/main.do
난이도 4라고 하기에도 굉장히 쉬운 문제다.

결국 최솟값, 최댓값의 정수 하나씩을 빼고 나머지 (N - 2)개로 만들 수 있는 경우의 수는 (N - 2) * (B - A) + 1이다.

이유는 (N - 2)개를 모두 A로 하는 경우부터 (N - 2)개를 모두 B로 하는 경우 사이에 있는 모든 수는 (N - 2)개의 정수로 만들 수 있는 수이다.

아래 코드를 보면 쉽게 이해할 수 있을 것이다.
*/
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	long long T, N, A, B, answer;

	scanf("%lld", &T);
	for (long long test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%lld %lld %lld", &N, &A, &B);

		if (A > B || (N == 1 && A != B)) {	//최솟값이 최댓값보다 크거나, N이 1인데, A와 B가 다른 경우는 0출력
			printf("#%lld 0\n", test_case);
			continue;
		}
		else {	//이외의 경우
			answer = (B - A) * (N - 2) + 1;
			printf("#%lld %lld\n", test_case, answer);
		}
	}
	return 0;
}