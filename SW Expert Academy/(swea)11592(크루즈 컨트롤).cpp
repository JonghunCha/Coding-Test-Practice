/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���̵��� 4��� ���������� �׿� ���� ���� ���� ������.

���� �����ϰ� ���� �̵��� �Ÿ��� ���� ������ �������µ� �ɸ��� �ð����� ������ �����̴�.
*/
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int T, D, horse_num, horses[2][2];
	double time_max, time_temp;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ���� ������ ���µ� �ɸ��� �ð� ���
		time_max = 0;
		scanf("%d %d", &D, &horse_num);
		for (int a = 0; a < horse_num; a++) {
			scanf("%d %d", &horses[a][0], &horses[a][1]);
			time_temp = (double)(D - horses[a][0]) / (double)(horses[a][1]);
			if (time_temp > time_max)	time_max = time_temp;
		}

		printf("#%d %lf\n", test_case, D / time_max);
	}
	return 0;
}