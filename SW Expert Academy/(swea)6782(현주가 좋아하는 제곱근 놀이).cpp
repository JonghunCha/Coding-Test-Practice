/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�Ǽ����� ������ ������ ĳ������ �����ϸ� ���� �ذ��� �� �ִ�.

�ּ����� �������� N�� 2�� ����� ���ؼ�, ��ȸ�� �� ������ ��Ʈ�� ������ �Ѵ�.

��Ʈ�� ���� ����� ������ ���� ��Ʈ�� ���� �� �ִµ� �̿� ���� �Ǵ��� ĳ������ ���ؼ� �� �� �ִ�.

�Ǽ����� ���������� ����ȯ �Ҷ��� �Ҽ��� �κ��� ��������.

��, ��Ʈ(5)�� �Ǽ����� ������ �ϰ� �̸� �ٽ� ���������� ��ȯ�ϸ� 2��� ���� ������ �ȴ�.(��Ʈ(5)�� 2.xxx�̱� ����)

���� ��Ʈ(9)�� �Ǽ����� �����ϸ� 3.0000�� �ǰ� �̸� ���������� ��ȯ�ص� 3�� �ȴ�.

���� �� ��ȯ�� �� �� ������ ���� ���� N�� ������ ��Ʈ�� ���� �� �ִ� ��Ȳ�̰�, N���� ���� ��� ��Ʈ�� ���� �� ���� ��Ȳ�̴�.
*/
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
	int T, answer;
	long long N, temp_ll;
	double temp_d;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%lld", &N);
		
		answer = 0;
		while (N > 2) {
			temp_d = sqrt(N);
			temp_ll = (long long)temp_d;

			if (temp_ll * temp_ll == N) {	//N�� ��Ʈ�� ������ �� ������ ���
				answer++;
				N = temp_ll;
			}
			else {	//N�� ��Ʈ�� ���� �� ���� ���
				answer += (temp_ll + 1) * (temp_ll + 1) - N;	//��Ʈ�� ���� �� ���� ������ +1�۾��� �ݺ�
				answer++;	//��Ʈ�� �����
				N = temp_ll + 1;
			}
		}

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}