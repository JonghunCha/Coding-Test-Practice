/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�κ� ���� �̿��ؾ� �ð��ʰ��� �ɸ��� �ʴ� ������.

������ ���� �κ��� �� �ٸ� ������� ���� ������ �����ϰڴ�.
*/
#include <cstdio>
using namespace std;

long long sum[1000001];

int main(int argc, char** argv)
{
	int T, L, R, count;

	//1000000������ �κ��� ���
	sum[0] = 0;
	for (int a = 1; a <= 1000000; a++) {
		count = 0;
		for (int b = 1; b * b <= a; b++) {
			if (a % b == 0) {
				if (b % 2 == 1)	count += b;
				if (b * b != a && (a / b) % 2 == 1)	count += (a / b);
			}
		}
		sum[a] = sum[a - 1] + count;
	}

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &L, &R);
		
		printf("#%d %lld\n", test_case, sum[R] - sum[L - 1]);
	}
	return 0;
}