/*
���� ��ũ : https://swexpertacademy.com/main/main.do

���� �߿��� ���� Pd�� �����ϱ� ���� ���� �� ���Ӽ� D�� �ּ� �� �������� �߿��ϴ�.

�̴� 100�� Pd������ �ִ� ������� ���� �� 100���� �ִ� ������� ���� ���̴�.

�ܴ̿� �·��� 0, 100�ۼ�Ʈ�� ���� ���� ���׸� ó���ϸ� �ȴ�.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int get_count(int a, int b);

int main(int argc, char** argv)
{
	int T, Pd, Pg, count;
	long long N;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%lld %d %d", &N, &Pd, &Pg);

		if (Pd == 0) {
			if (Pg == 100)	printf("#%d Broken\n", test_case);
			else	printf("#%d Possible\n", test_case);
		}
		else if (Pd == 100) {
			if (Pg == 0)	printf("#%d Broken\n", test_case);
			else	printf("#%d Possible\n", test_case);
		}
		else {
			count = get_count(100, Pd);
			if(Pg == 100 || Pg == 0 || count > N)	printf("#%d Broken\n", test_case);
			else	printf("#%d Possible\n", test_case);
		}

	}
	return 0;
}

int get_count(int a, int b) {
	if (a % b == 0)	return 100 / b;
	else return get_count(max(a - b, b), min(a - b, b));
}