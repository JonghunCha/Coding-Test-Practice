/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���� ��ü�� �ſ� ���� ������.

x��ǥ�� ������ ���̴� (1+2....+x)�̴�.

���� a�� x - 1�� ��ǥ b�� x��ǥ�� ���̴� ���̶� ���� �� x = b - a���� �� �� �ִ�.

�̸� �̿��Ͽ� x��ǥ�� ������̿��� b��ŭ ���ָ� K���� ���� �� �ִ�.

�׷��� �ð������� ��������.

�Է��� 100000���̰� ��µ� 100000���� �ؾ��ϱ� ������ c++�� cin, cout�� ����ϸ� �ð����ѿ� �ɷȴ�.

c�� scanf�� printf�� ����ϴ� �ð����� ���� ��� �Ǿ���.
*/
#include <iostream>
#include <cstdio>

using namespace std;

int answer[10001];

int main(int argc, char** argv)
{
	int T, a, b, x, length;
	
	answer[0] = 0;
	for (int a = 1; a <= 10000; a++) {
		answer[a] = answer[a - 1] + a;
	}

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &a, &b);
		x = b - a;
		printf("#%d %d\n", test_case, answer[x] - b);
	}
	return 0;
}