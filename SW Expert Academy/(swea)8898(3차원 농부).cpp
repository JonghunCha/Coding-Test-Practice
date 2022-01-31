/*
���� ��ũ : https://swexpertacademy.com/main/main.do
������ �� �����Ϳ� ������ ������ �����Ѵ�.

�ҿ� �� ���� �Ÿ��� �ּ��� ���� �׷� ��찡 �� �� ���������� �ľ��ؾ��Ѵ�.

���� ������� �˾Ƴ� �ּ� �Ÿ����� �� ū ����� �񱳴� ���� �ʾƵ� �ȴ�.

�̸� ���� �ҵ��� ��ġ ������ ��ġ�� ������ ���־���.

�׷� ���� �����͸� �� �� �ξ� �ҿ� ���� �Ÿ��� ���ϸ� ���� ª�� �Ÿ��� �׷��� ����� ī��Ʈ�� �������־���.

�����͸� ��� �����Ͽ������� �Ʒ� �ڵ带 ���� ���� ������ �� ���� ���̴�.
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int cow[500000], horse[500000];

int main(int argc, char** argv)
{
	int T, N, M, c1, c2, dist, count, idx1, idx2;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ����
		scanf("%d %d", &N, &M);
		scanf("%d %d", &c1, &c2);
		for (int a = 0; a < N; a++)	scanf("%d", &cow[a]);
		for (int a = 0; a < M; a++)	scanf("%d", &horse[a]);
		sort(cow, cow + N);
		sort(horse, horse + M);
		//idx1�� ���� ���ϴ� ���� �ε���, idx2�� ���� �ε����� �ǹ�
		dist = 1000000000;
		count = 0;
		idx1 = 0;
		idx2 = 0;
		while (idx1 != N && idx2 != M) {	
			if (cow[idx1] > horse[idx2]) {	//���� ��ġ�� ���� ��ġ���� ū ���
				if (cow[idx1] - horse[idx2] < dist) {	//���� ���� ���� ª�� �Ÿ��� ��� dist�� �����ϰ� count�� 1�� ����
					dist = cow[idx1] - horse[idx2];
					count = 1;
				}
				else if (cow[idx1] - horse[idx2] == dist) {	//���� ���� ���ݱ��� �߰��� ���� ª�� �Ÿ��� ���ٸ� count�� 1 ���δ�
					count++;
				}

				idx2++;	//���� ��ġ�� ���� ��ġ���� �۱� ������ ���� �ε����� �÷� �� ª�� �Ÿ��� ���� �ִ��� Ž��
			}
			else {	//���� �ݴ��� ���(����� ����)
				if (horse[idx2] - cow[idx1] < dist) {
					dist = horse[idx2] - cow[idx1];
					count = 1;
				}
				else if (horse[idx2] - cow[idx1] == dist) {
					count++;
				}

				idx1++;
			}
		}

		printf("#%d %d %d\n", test_case, dist + max(c1, c2) - min(c1, c2), count);
	}
	return 0;
}