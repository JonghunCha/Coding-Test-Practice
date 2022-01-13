/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�̺� Ž������ �ذ��ؾ� �ϴ� ������.

�ּ� �ð��� 0, �ִ� �ð��� 10^18�̴�. ���� ���� Ž���� �ƴ� �̺� Ž������ ������ �����ؾ� �ð��ʰ��� �ɸ��� �ʴ´�.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int T, N, M, tk[100000];
	long long answer, left, right, mid, sum;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &N, &M);
		for (int a = 0; a < N; a++) {
			scanf("%d", &tk[a]);
		}

		answer = 1000000000000000000;
		left = 1;
		right = 1000000000000000000;
		while (left <= right) {
			mid = (left + right) / 2;
			sum = 0;
			//mid��ŭ�� �ð��� ���� �� ����� �Ա��ɻ縦 ��ĥ �� �ִ��� ���
			for (int a = 0; a < N; a++) {
				sum += mid / tk[a];
			}
			
			if (sum >= M) {	//sum�� M���� ũ�ų� ���ٸ� �ð��� ���� �� �ִ� ������ �ִ�
				answer = min(answer, mid);
				right = mid - 1;
			}
			else {	//sum�� M���� �۴ٸ� �ð��� �� �÷���� �Ѵ�
				left = mid + 1;
			}
		}

		printf("#%d %lld\n", test_case, answer);
	}

	return 0;
}