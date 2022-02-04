/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���̵�4�� ���� ���� ������.

��ȯ�ϴ� ���� �ּڰ��� �Ƿ��� �� ���� ��ȯ���� 2���� �߸��� ��ġ�� �����ϴ� ���� �ִ�ȭ �ؾ� �Ѵ�.

���� mod�� ����� ���� �ڹٲ� ��ġ�� �ִ� �͵鳢�� ���� ��ȯ�� �Ѵ�. 

�׷� ���� ���� ���������� 3���� ���� �¹����� ���� ������ �ٵ� �� ��� 3���� ������ ��� ���ؼ� 2���� ��ȯ�� �ʿ��ϴ�.

����, ������ (2���� ���� �ٲ� ���� ���� + (3���� ���� �ٲ� ���� ���� * 2) / 3)�̴�.
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int T, N, inputs[1000], count[3][3], answer;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ���� �ʱ�ȭ
		scanf("%d", &N);
		memset(count, 0, sizeof(int) * 9);
		for (int a = 1; a <= N; a++) {
			scanf("%d", &inputs[a]);
			count[a % 3][inputs[a] % 3]++;
		}
		answer = 0;
		//2���� ��ġ�� ���� �ڹٲ� ����� ���� 
		answer += min(count[1][0], count[0][1]);
		answer += min(count[2][0], count[0][2]);
		answer += min(count[1][2], count[2][1]);
		//3���� ��ġ�� ���� �����ִ� ����� ���� ���
		int sum = 0;
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				sum += count[a][b];
			}
		}
		sum = sum - count[0][0] - count[1][1] - count[2][2];
		sum = sum - (2 * answer);

		answer += (2 * sum) / 3;
		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}