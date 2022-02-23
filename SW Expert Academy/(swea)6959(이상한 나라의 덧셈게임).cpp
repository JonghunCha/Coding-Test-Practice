/*
문제 링크 : https://swexpertacademy.com/main/main.do
게임이 끝나는 조건까지 몇 회의 턴이 필요한지만 구하면 쉽게 해결할 수 있다.

한 턴에 일어날 수 있는 경우는 아래와 같은 2가지 경우이다.
1. 두 수를 더했는데 10보다 작아서 자릿수만 하나 줄어들고, 전체 합은 유지되는 경우
2. 두 수를 더했는데 10보다 커서 자릿수는 변하지 않고, 전체 합만 9 낮아지는 경우

따라서, 게임이 끝나기 위해선 자릿수를 줄이는 1번 동작을 (수의 길이 - 1)만큼, 전체 합을 줄이는 2번 동작을 전체 합이 10미만이 될때까지 반복하여야 한다.

게임이 끝나는 횟수를 알면 정답은 2로 나누었을 때 나머지가 있는 경우와 없는 경우로 쉽게 구별할 수 있다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
	int T, sum, turns;
	char input[1001];

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%s", input);
		sum = 0;
		//모든 수의 합을 구한다
		for (int a = 0; a < strlen(input); a++) {
			if (input[a] >= '0' && input[a] <= '9') {
				sum += (int)(input[a] - '0');
			}
		}
		
		turns = strlen(input) - 1;	//위에서 설명한 1번 과정의 횟수 계산
		while (sum >= 10) {	//위에서 설명한 2번 과정의 횟수 계산
			sum -= 9;
			turns++;
		}

		if (turns % 2 == 0)	printf("#%d B\n", test_case);
		else	printf("#%d A\n", test_case);
	}
	return 0;
}