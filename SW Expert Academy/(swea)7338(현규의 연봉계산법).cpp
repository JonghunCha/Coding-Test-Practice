/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�ܼ��� ���� ������.

1���� 12�������� 13������ �ٲپ��� ���� ��ȯ�� ���� �����̴�.

���� ������ ���ٸ� ������ ���� �ʰڴ�.
*/
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int T;
	long long Y, M, count, answer_y, answer_m;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%lld %lld", &Y, &M);
		//2016�� 12���� 2016�� 13�� ���� ó��
		if (Y == 2016) {
			printf("#%d 2016 12\n", test_case);
			continue;
		}
		else if (Y == 2017 && M == 1) {
			printf("#%d 2016 13\n", test_case);
			continue;
		}
		//��� ��� �� ���
		count = ((Y - 2016) * 12) - (12 - M);
		answer_y = 2017 + ((count - 2) / 13);
		answer_m = (count - 1)  % 13;
		if (answer_m == 0)	answer_m = 13;

		printf("#%d %lld %lld\n", test_case, answer_y, answer_m);
	}
	return 0;
}