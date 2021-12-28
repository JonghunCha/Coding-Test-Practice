/*
문제 링크 : https://swexpertacademy.com/main/main.do
결과는 패턴에 따라 정해져 있는 문제다.

N을 1씩 높여가며 결과가 어떻게 달라지는지 몇 가지 경우만 테스트 해보면 쉽게 패턴을 알 수 있다.

N이 1일 때는 Bob이 무조건 이긴다.

그 다음부터 4번은 Alice, 4번은 Bob, 4*4번은 Alice, 4*4번은 Bob이 이기는 패턴으로 진행이 된다.
*/
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int T;
	long long N, count, temp, curr;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%lld", &N);
		if (N == 1) {
			printf("#%d Bob\n", test_case);
			continue;
		}
		//count는 현재 탐색중인 번호를 의미, temp는 현재 패턴이 몇 번 연속인지, curr는 현재 패턴이 Alice인지 Bob인지를 저장
		count = 1;
		temp = 4;
		curr = 0;

		while (1) {
			if (N > count && N <= count + temp) {	//만약 N이 현재 탐색중인 패턴이라면 정답 출력
				if (curr == 0)	printf("#%d Alice\n", test_case);
				else	printf("#%d Bob\n", test_case);
				break;
			}
			else {
				if (curr == 0) {	//현재 패턴이 Alice인 경우 다음 패턴은 Bob이고 연속되는 수인 temp는 같다
					count += temp;
					curr = 1;
				}
				else {	//현재 패턴이 Bob인 경우 다음 패턴은 Alice이고 temp는 4배가 된다
					count += temp;
					curr = 0;
					temp *= 4;
				}
			}
		}
	}
	return 0;
}