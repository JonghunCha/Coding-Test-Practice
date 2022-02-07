/*
문제 링크 : https://swexpertacademy.com/main/main.do
DP로 해결할 수 있는 문제다.

N의 범위가 최대 100,000 이기에 1부터 100,000까지의 경우를 미리 다 계산하고 N이 들어왔을 때 정답을 바로바로 출력해주면 된다.

메모이제이션을 위한 배열을 2개 두었는데, answer[a]는 N이 a일때 정답값을, nums[a]는 a의 약수의 갯수를 저장한다.

100,000이하의 모든 수 a에 대해서, a의 약수의 갯수가 answer[a - 1]의 약수의 갯수보다 많거나 같다면 answer[a]는 a가 된다. 그 반대의 경우 answer[a]는 answer[a - 1]과 같다.

아래 코드를 보면 쉽게 이해할 수 있을 것이다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int answer[100001], nums[100001];

int main(int argc, char** argv)
{
	int T, N, count;
	scanf("%d", &T);

	memset(answer, -1, sizeof(int) * 100001);
	memset(nums, -1, sizeof(int) * 100001);

	answer[1] = 1;
	answer[2] = 2;
	nums[1] = 0;
	nums[2] = 0;
	for (int a = 3; a <= 100000; a++) {
		count = 0;
		for (int b = 2; b * b <= a; b++) {	//약수의 갯수를 찾는 과정(시간 복잡도를 줄이기 위해 b의 제곱이 a와 같거나 작을 때까지만 반복)
			if (a % b == 0) {
				if (a == b * b)	count++;	//a가 b의 제곱과 일치하는 경우엔 약수가 b 하나
				else	count += 2;	//a가 b의 제곱과 일치하지 않는 경우엔 약수가 b, (a / b) 둘
			}
		}
		nums[a] = count;
		if (count >= nums[answer[a - 1]])	answer[a] = a;	//만약 a의 약수의 갯수인 count가 a 미만의 수들의 약수 갯수보다 크거나 같으면 answer[a] = a
		else	answer[a] = answer[a - 1];	//반대의 경우 약수의 갯수가 가장 많은 수는 answer[a - 1]
	}

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &N);
		printf("#%d %d\n", test_case, answer[N]);
	}
	return 0;
}