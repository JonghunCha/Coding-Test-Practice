/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���� ������ �޸������̼��� ���� �ذ��� �� �ִ� ������.

�켱 a^a�� a�� Ȧ���� ¦���Ŀ� ���� �Ʒ��� ���� ���� �� �ִ�.
1. a�� Ȧ�� : a^a = a^(a/2) * a^(a/2) * a
2. a�� ¦�� : a^a = a^(a/2) * a^(a/2)

���� �̿��Ͽ� N�� 10^6�̴��� 20�� ������ �����ϸ� a^0 Ȥ�� a^1�� ����� �ִ�.

����, �ð������� ����ϱ� ���� �� �������� ���� pow���� answers�迭�� �������־���.
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
		if (answers[a] != 0) {	//���� �̹� ����� ���� ���
			ret += answers[a];
		}
		else {	//������ ���� ��� get_powȣ��
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
	else {	//times�� 0�Ǵ� 1�� �� ������ ����ؼ� ����
		long long temp = get_pow(N, times / 2);

		if (times % 2 == 0)	return (temp * temp) % M;
		else	return (((temp * temp) % M) * N) % M;
	}
}