/*
���� ��ũ : https://swexpertacademy.com/main/main.do
DFS�� �̿��Ͽ� �ذ��� �� �ִ� ������.

�켱 �׷��� �������� ���� ����� ã�� �ش� ����� ���ο� ������ �ְ� ����� ��� ����� �ش� ������ ���� �ִ´�.

�� ������ ��� ����� ��� ������ ���ϵ��� �ݺ��ϸ� �ȴ�.
*/
#include <cstdio>
#include <cstring>
using namespace std;

void search_near(int group[101], int group_num, bool know_each_other[101][101], int N, int index);

int main(int argc, char** argv)
{
	int T, N, M, num1, num2, group[101], group_num;
	bool know_each_other[101][101];

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ���� �ʱ�ȭ
		group_num = 0;
		memset(group, 0, sizeof(int) * 101);
		memset(know_each_other, false, sizeof(bool) * 101 * 101);
		scanf("%d %d", &N, &M);
		for (int a = 0; a < M; a++) {
			scanf("%d %d", &num1, &num2);
			know_each_other[num1][num2] = true;
			know_each_other[num2][num1] = true;
		}
		//��� ����� ������ ���� ������ ���ο� ���� ����� ����� ��� ����ֱ�
		for (int a = 1; a <= N; a++) {
			if (group[a] == 0) {
				group[a] = ++group_num;
				search_near(group, group_num, know_each_other, N, a);
			}
		}

		printf("#%d %d\n", test_case, group_num);
	}
	return 0;
}
//index��° ����� ����� ��� ������� group_num�� �ش��ϴ� ������ �Ҽӽ�Ų��
void search_near(int group[101], int group_num, bool know_each_other[101][101], int N, int index) {
	for (int a = 1; a <= N; a++) {
		if (group[a] == 0 && know_each_other[index][a] == true) {
			group[a] = group_num;
			search_near(group, group_num, know_each_other, N, a);
		}
	}
}