/*
문제 링크 : https://swexpertacademy.com/main/main.do
분할 정복과 메모이제이션을 통해 해결할 수 있는 문제다.

우선 a^a은 a가 홀수냐 짝수냐에 따라 아래와 같이 나눌 수 있다.
1. a가 홀수 : a^a = a^(a/2) * a^(a/2) * a
2. a가 짝수 : a^a = a^(a/2) * a^(a/2)

위를 이용하여 N이 10^6이더라도 20번 정도만 분할하면 a^0 혹은 a^1을 만들수 있다.

또한, 시간제한을 통과하기 위해 각 과정에서 구한 pow값을 answers배열에 저장해주었다.
*/
#include <cstdio>
#include <cstring>

#define M 1000000007
using namespace std;

long long answers[1000001];

long long get_answer(int N);
long long get_pow(int N, int times);

int main(int argc, char** argv)
{
	int T, N;
	long long answer;

	memset(answers, 0, sizeof(long long) * 1000001);
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &N);
		answer = get_answer(N);

		printf("#%d %lld\n", test_case, answer);
	}
	return 0;
}

long long get_answer(int N) {
	long long ret = 0, temp;

	for (int a = 1; a <= N; a++) {
		if (answers[a] != 0) {	//만약 이미 계산한 값인 경우
			ret += answers[a];
		}
		else {	//계산되지 않은 경우 get_pow호출
			temp = get_pow(a, a);
			answers[a] = temp;
			ret += temp;
		}
		ret = ret % M;
	}

	return ret;
}

long long get_pow(int N, int times) {
	if (times == 0)	return 1;
	else if (times == 1)	return N;
	else {	//times가 0또는 1이 될 때까지 계속해서 분할
		long long temp = get_pow(N, times / 2);

		if (times % 2 == 0)	return (temp * temp) % M;
		else	return (((temp * temp) % M) * N) % M;
	}
}