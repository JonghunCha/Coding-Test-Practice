/*
���� ��ũ : https://swexpertacademy.com/main/main.do
Q���� ��ġ �ٲٱ��� a��° ��Ȳ�� ������ ���� ��ġ�� �迭�� ǥ���� �����ν� �ذ��� �� �ִ�.

�ڵ带 ���� ���� ������ �� ���� ���̴�.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
	int T, N, Q, curr_ball_index, A, B, answer;
	bool insert_A, insert_B, used_trick[1000001];

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ���� �ʱ�ȭ
		scanf("%d %d", &N, &Q);
		memset(used_trick, false, sizeof(bool) * (N + 1));
		//N�� 1�� ��� ���� ó��
		if (N == 1) {
			printf("#%d 1\n", test_case);
			continue;
		}
		//curr_ball_index�� ������� ���Ӽ��� ������� �ʾ��� �� ���� ��ġ�̰�, used_trick[a]�� ���Ӽ��� ���� �� ���� a���� ��ġ�� ���� ���� �� �ִ����� ��Ÿ����
		curr_ball_index = 1;
		used_trick[2] = true;;
		for (int a = 0; a < Q; a++) {
			scanf("%d %d", &A, &B);
			
			insert_A = false;
			insert_B = false;
			if (used_trick[A])	insert_B = true;	//A��°�� ���� ���� �� �ִٴ� ���� �̹� ���� ��ġ �ٲٱ�� ���� B������ ���� �� �� ����
			if (used_trick[B])	insert_A = true;	//���� ��������
			used_trick[A] = false;
			used_trick[B] = false;
			if (insert_A)	used_trick[A] = true;
			if (insert_B)	used_trick[B] = true;

			//���Ӽ��� �Ⱦ� ���� ���� ��ġ ����
			if (A == curr_ball_index)	curr_ball_index = B;
			else if (B == curr_ball_index)	curr_ball_index = A;
			//���� �ܰ迡�� ���Ӽ��� ���ٰ� �� �� ��ġ�� used_trick�� ǥ��
			if (curr_ball_index == 1) {
				used_trick[2] = true;;
			}
			else if (curr_ball_index == N) {
				used_trick[N - 1] = true;
			}
			else {
				used_trick[curr_ball_index - 1] = true;
				used_trick[curr_ball_index + 1] = true;
			}
		}
		//������ �� ���
		answer = 0;
		for (int a = 1; a <= N; a++) {
			if (used_trick[a])	answer++;
		}
		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}