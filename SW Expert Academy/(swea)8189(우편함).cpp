/*
���� ��ũ : https://swexpertacademy.com/main/main.do
ť�� �̿��ϸ� �Ǵ� ������.

�׷��� ������ �𸣰����� �⺻ ����� ���̺귯�� �̿ܿ��� �ٸ� ���̺귯���� ������� ���ϰ� �ؼ� �迭�� ť��� �����ϰ� Ǯ����.

���� ��ü�� �����ؼ� �ڵ常 ���� ���� ������ �� ���� ���̴�.
*/
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int T, N, A, B, letters[100], answer[100], left, right, num;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ���� �ʱ�ȭ
		scanf("%d %d %d", &N, &A, &B);
		for (int a = 0; a < N; a++)	scanf("%d", &letters[a]);
		left = 0;	//���� �����Կ� �ִ� ���� �� ���� ���� ������ ��
		right = 0;	//���� �����Կ� �ִ� ���� �� ���� �ʰ� ������ ��

		//�ð��� �ִ� 2000���� ����
		for (int a = letters[0]; a <= 2000; a++) {
			if (left == N)	break;	//��� ������ �� ������ ����
			if (right + 1 < N && letters[right + 1] <= a)	right++;	//�ð� a�� �� �����ϴ� ������ �ִٸ� �ش� ������ �ε����� right�� ����
			//������ A�� �̻� ���̰ų� ���� ������ ������ B�ð� �̻� ������ ���� �б�
			if (right - left + 1 >= A || a - letters[left] >= B) {
				if ((right - left + 1) % 2 == 0)	num = (right - left + 1) / 2;
				else	num = ((right - left + 1) / 2) + 1;

				for (int b = left; b < left + num; b++) {
					answer[b] = a;
				}
				left = left + num;
			}
		}

		printf("#%d ", test_case);
		for (int a = 0; a < N; a++)	printf("%d ", answer[a]);
		printf("\n");
	}
	return 0;
}