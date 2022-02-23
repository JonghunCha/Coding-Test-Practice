/*
���� ��ũ : https://swexpertacademy.com/main/main.do
������ ������ ���Ǳ��� �� ȸ�� ���� �ʿ������� ���ϸ� ���� �ذ��� �� �ִ�.

�� �Ͽ� �Ͼ �� �ִ� ���� �Ʒ��� ���� 2���� ����̴�.
1. �� ���� ���ߴµ� 10���� �۾Ƽ� �ڸ����� �ϳ� �پ���, ��ü ���� �����Ǵ� ���
2. �� ���� ���ߴµ� 10���� Ŀ�� �ڸ����� ������ �ʰ�, ��ü �ո� 9 �������� ���

����, ������ ������ ���ؼ� �ڸ����� ���̴� 1�� ������ (���� ���� - 1)��ŭ, ��ü ���� ���̴� 2�� ������ ��ü ���� 10�̸��� �ɶ����� �ݺ��Ͽ��� �Ѵ�.

������ ������ Ƚ���� �˸� ������ 2�� �������� �� �������� �ִ� ���� ���� ���� ���� ������ �� �ִ�.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
	int T, sum, turns;
	char input[1001];

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%s", input);
		sum = 0;
		//��� ���� ���� ���Ѵ�
		for (int a = 0; a < strlen(input); a++) {
			if (input[a] >= '0' && input[a] <= '9') {
				sum += (int)(input[a] - '0');
			}
		}
		
		turns = strlen(input) - 1;	//������ ������ 1�� ������ Ƚ�� ���
		while (sum >= 10) {	//������ ������ 2�� ������ Ƚ�� ���
			sum -= 9;
			turns++;
		}

		if (turns % 2 == 0)	printf("#%d B\n", test_case);
		else	printf("#%d A\n", test_case);
	}
	return 0;
}