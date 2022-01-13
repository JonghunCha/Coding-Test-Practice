/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�� ������ ������ ����� �����̴�.

��� �� ���̶�� ���� �ᱹ ���ʿ����� ���� Ŀ����, ���������δ� ���� �۾����� ������ ���� �ǹ� �Ѵ�.

����, ���ʿ��� �� ���� ���� ���� Ŀ������ ����� ���� left, ���������� �� ���� ���� ���� �۾������� ����� ���� right��� ����.

�׷� �ش� ���������� ��� �� ���� ������ left * right��ŭ�� ��찡 ���� �� �ִ�.

�̸� ��ü ������ ���� ����ϸ� ������ ���� �� �ִ�. �ڵ带 ���� ���� ������ �� ���� ���̴�.
*/
#include <cstdio>
using namespace std;

int main(int argc, char** argv)
{
	int T, N, prev, curr, left, right;
	bool is_going_up;	//���� ���¿��� ���̰� ���� �������ٸ� true, �������ٸ� false
	long long answer;
	
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ���� �ʱ�ȭ
		scanf("%d", &N);
		answer = 0;
		left = 0;
		right = 0;
		//ù ��°, �� ��° ���� ���� is_going_up �� left�� �ʱ�ȭ
		scanf("%d", &prev);
		scanf("%d", &curr);

		if (curr > prev) {
			left = 1;
			is_going_up = true;
		}
		else {
			is_going_up = false;
		}
		prev = curr;
		//�� ��° ����� ������ �ݺ�
		for (int a = 2; a < N; a++) {
			scanf("%d", &curr);
			if (curr > prev) {
				if (is_going_up) {
					left++;
				}
				else {
					answer += left * right;	
					left = 1;
					right = 0;
					is_going_up = true;
				}
			}
			else {
				if (is_going_up) {
					right++;
					is_going_up = false;

				}
				else {
					right++;
				}
			}

			prev = curr;
		}

		answer += left * right;	//������ left, right���� ���信 �ݿ�
		printf("#%d %lld\n", test_case, answer);
	}
	return 0;
}