/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�밢�� ���� �̿��� �� �ִ� ���� �׷��� ���� ��츦 �����ϸ� ���� �ذ��� �� �ִ�.

�밢�� ���� �̿��ϴ� ��찡 ȿ������ ���� ������� x, y�� �������� x, y���� �� �� ũ�ų� ���� ����̴�.

�� �κи� �����ϸ� ���� �ذ��� �� �ִ� ������.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int T, W, H, N, curr_x, curr_y, dst_x, dst_y, answer;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ����
		scanf("%d %d %d", &W, &H, &N);
		answer = 0;
		//�ʱ� ����� ����
		scanf("%d %d", &curr_x, &curr_y);
		//�ٸ� ���������� �̵��ϸ� answer ����
		for (int a = 1; a < N; a++) {
			scanf("%d %d", &dst_x, &dst_y);

			if ((dst_x <= curr_x && dst_y <= curr_y) || (dst_x >= curr_x && dst_y >= curr_y)) {	//�밢�� ���� �̿��ϴ� ���
				answer += max(max(curr_x, dst_x) - min(curr_x, dst_x), max(curr_y, dst_y) - min(curr_y, dst_y));
			}
			else {	//�밢�� ���� �̿����� �ʴ� ���
				answer += max(curr_x, dst_x) - min(curr_x, dst_x);
				answer += max(curr_y, dst_y) - min(curr_y, dst_y);
			}
			curr_x = dst_x;
			curr_y = dst_y;
		}

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}