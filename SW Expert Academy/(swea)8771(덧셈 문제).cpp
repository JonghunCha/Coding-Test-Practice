/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���̵� 4��� �ϱ⿡�� ������ ���� ������.

�ᱹ �ּڰ�, �ִ��� ���� �ϳ����� ���� ������ (N - 2)���� ���� �� �ִ� ����� ���� (N - 2) * (B - A) + 1�̴�.

������ (N - 2)���� ��� A�� �ϴ� ������ (N - 2)���� ��� B�� �ϴ� ��� ���̿� �ִ� ��� ���� (N - 2)���� ������ ���� �� �ִ� ���̴�.

�Ʒ� �ڵ带 ���� ���� ������ �� ���� ���̴�.
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

		if (A > B || (N == 1 && A != B)) {	//�ּڰ��� �ִ񰪺��� ũ�ų�, N�� 1�ε�, A�� B�� �ٸ� ���� 0���
			printf("#%lld 0\n", test_case);
			continue;
		}
		else {	//�̿��� ���
			answer = (B - A) * (N - 2) + 1;
			printf("#%lld %lld\n", test_case, answer);
		}
	}
	return 0;
}