/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���� ������ 20�ۼ�Ʈ�� Ǯ��ôµ� ����¶����� 20�ۼ�Ʈ�� �� ���� ������ ���� ��������.

�ܼ��� �� ������ ���ÿ� ���� �ð��� ���ϴ� ������ ���ǹ� �� ���� ���� Ǯ �� �ִ�.

�Ʒ� �ڵ常 ���� ���� ������ �� ���� ���̴�.
*/
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int T, A, B, C, D, bulb_first_start, bulb_first_end, bulb_second_start, bulb_second_end;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d %d %d", &A, &B, &C, &D);
		//�������� ������ ���߿� ���� ������ ����
		if (A <= C) {
			bulb_first_start = A;
			bulb_first_end = B;
			bulb_second_start = C;
			bulb_second_end = D;
		}
		else {
			bulb_first_start = C;
			bulb_first_end = D;
			bulb_second_start = A;
			bulb_second_end = B;
		}

		if (bulb_first_end < bulb_second_start) {	//���� ���� ������ ���� ������ �� ��° ������ ������ ���� ���
			printf("#%d 0\n", test_case);
		}
		else if (bulb_second_end < bulb_first_end) {	//�ι�° ������ ���� �ð��� ���� ���� ���� �ð��� ���Ե� ��
			printf("#%d %d\n", test_case, bulb_second_end - bulb_second_start);
		}
		else {	//�Ϻθ� ��ġ�� ���
			printf("#%d %d\n", test_case, bulb_first_end - bulb_second_start);
		}
	}
	return 0;
}