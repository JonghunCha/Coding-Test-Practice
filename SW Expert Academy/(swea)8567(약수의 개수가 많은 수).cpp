/*
���� ��ũ : https://swexpertacademy.com/main/main.do
DP�� �ذ��� �� �ִ� ������.

N�� ������ �ִ� 100,000 �̱⿡ 1���� 100,000������ ��츦 �̸� �� ����ϰ� N�� ������ �� ������ �ٷιٷ� ������ָ� �ȴ�.

�޸������̼��� ���� �迭�� 2�� �ξ��µ�, answer[a]�� N�� a�϶� ���䰪��, nums[a]�� a�� ����� ������ �����Ѵ�.

100,000������ ��� �� a�� ���ؼ�, a�� ����� ������ answer[a - 1]�� ����� �������� ���ų� ���ٸ� answer[a]�� a�� �ȴ�. �� �ݴ��� ��� answer[a]�� answer[a - 1]�� ����.

�Ʒ� �ڵ带 ���� ���� ������ �� ���� ���̴�.
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
		for (int b = 2; b * b <= a; b++) {	//����� ������ ã�� ����(�ð� ���⵵�� ���̱� ���� b�� ������ a�� ���ų� ���� �������� �ݺ�)
			if (a % b == 0) {
				if (a == b * b)	count++;	//a�� b�� ������ ��ġ�ϴ� ��쿣 ����� b �ϳ�
				else	count += 2;	//a�� b�� ������ ��ġ���� �ʴ� ��쿣 ����� b, (a / b) ��
			}
		}
		nums[a] = count;
		if (count >= nums[answer[a - 1]])	answer[a] = a;	//���� a�� ����� ������ count�� a �̸��� ������ ��� �������� ũ�ų� ������ answer[a] = a
		else	answer[a] = answer[a - 1];	//�ݴ��� ��� ����� ������ ���� ���� ���� answer[a - 1]
	}

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &N);
		printf("#%d %d\n", test_case, answer[N]);
	}
	return 0;
}