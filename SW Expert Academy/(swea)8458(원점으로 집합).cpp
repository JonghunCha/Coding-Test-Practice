/*
���� ��ũ : https://swexpertacademy.com/main/main.do
��� ���� ���ÿ� ������ �ֱ� ���ؼ� �ʱ��� ����� ���������� �Ÿ��� ��� ¦���̰ų� Ȧ���̾�� �Ѵ�.
(i��°������ �̵����� ��� ���� �Ȱ��� Ƚ����ŭ �������� �ϴµ� ���� � ���� ���������� �Ÿ��� ¦����, � ���� Ȧ����� ���ÿ� ������ ������ �� ���� ����)

���� ���� ������ ���� ������ -1�� ��츦 ���� �ɷ��� �� �ִ�.

���� ��Ȯ�� �� ���� �̵��� ���� ��� ���� ���ÿ� �������� ��������ε�, �̴� �ʱ⿡ �������� �Ÿ��� ���� �� ���� �߿��ϴ�.

i��°������ ������ Ƚ���� ���� �� ���� �Ÿ����� Ŀ���ϸ�, �� ���̴� ¦�������Ѵ�.
(�̹� ������ ������ ���� ���� �������� ä��� �ٽ� �������� �������ؼ� ¦���̾�� ��)

�Ʒ� �ڵ带 ���� ���� ������ �� ���� ���̴�.
*/
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int T, N, location[10][2];
	long long distance[10], dist, max_dist, sum;
	bool is_possible;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ����
		scanf("%d", &N);
		max_dist = -1;
		for (int a = 0; a < N; a++) {
			scanf("%d %d", &location[a][0], &location[a][1]);
			//�� ���� ���������� �Ÿ��� ���Ѵ�
			dist = 0;
			if (location[a][0] > 0)	dist += location[a][0];
			else	dist -= location[a][0];
			if (location[a][1] > 0)	dist += location[a][1];
			else	dist -= location[a][1];
			distance[a] = dist;
			//������ ���� �� �� ������ �Ÿ��� ���Ѵ�
			if (dist > max_dist)	max_dist = dist;
		}
		//��� ���� ���������� �Ÿ��� ��� Ȧ�� Ȥ�� ¦���� ��츸 ���� �ܰ�� ����
		is_possible = true;
		for (int a = 1; a < N; a++) {
			if ((distance[0] % 2) != (distance[a] % 2)) {
				printf("#%d -1\n", test_case);
				is_possible = false;
				break;
			}
		}
		if (!is_possible)	continue;
		//i��°������ �̵��� max_dist���� ũ�� �� ���̰� ¦���� ��� ���� ���
		sum = 0;
		for (int a = 0; a <= 100000; a++) {
			sum += a;

			if (sum >= max_dist && (sum - max_dist) % 2 == 0) {
				printf("#%d %d\n", test_case, a);
				break;
			}
		}
	}
	return 0;
}