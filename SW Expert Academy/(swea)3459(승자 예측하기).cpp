/*
���� ��ũ : https://swexpertacademy.com/main/main.do
����� ���Ͽ� ���� ������ �ִ� ������.

N�� 1�� �������� ����� ��� �޶������� �� ���� ��츸 �׽�Ʈ �غ��� ���� ������ �� �� �ִ�.

N�� 1�� ���� Bob�� ������ �̱��.

�� �������� 4���� Alice, 4���� Bob, 4*4���� Alice, 4*4���� Bob�� �̱�� �������� ������ �ȴ�.
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
		//count�� ���� Ž������ ��ȣ�� �ǹ�, temp�� ���� ������ �� �� ��������, curr�� ���� ������ Alice���� Bob������ ����
		count = 1;
		temp = 4;
		curr = 0;

		while (1) {
			if (N > count && N <= count + temp) {	//���� N�� ���� Ž������ �����̶�� ���� ���
				if (curr == 0)	printf("#%d Alice\n", test_case);
				else	printf("#%d Bob\n", test_case);
				break;
			}
			else {
				if (curr == 0) {	//���� ������ Alice�� ��� ���� ������ Bob�̰� ���ӵǴ� ���� temp�� ����
					count += temp;
					curr = 1;
				}
				else {	//���� ������ Bob�� ��� ���� ������ Alice�̰� temp�� 4�谡 �ȴ�
					count += temp;
					curr = 0;
					temp *= 4;
				}
			}
		}
	}
	return 0;
}