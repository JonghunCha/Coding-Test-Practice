/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�ܼ��� ���ڿ� ó�� ������.

�� ���ڿ��� �� ������ ���ĺ��� �ִ����� Ȯ���ϰ� ���� ���� ���ĺ��� ������ ���������� ���� �ռ��� ���ڿ��� �ε����� ������ �ش�.

��� ���ڿ��� ���� Ž���� ��ģ �� ������ ����ϸ� �ȴ�.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
	int T, N, count[100], max_num, max_index, curr_max, alphabet;
	char names[100][21];
	bool is_exist[100][26];

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ���� �ʱ�ȭ
		scanf("%d", &N);
		memset(count, 0, sizeof(int) * 100);
		memset(is_exist, false, sizeof(bool) * 2600);
		max_num = 0;
		max_index = 0;

		for (int a = 0; a < N; a++) {
			getchar();
			scanf("%[^\n]s", names[a]);
		}
		//�� ���ڿ��� ���� ���� �پ��� ������ ���ĺ��� ������ ���������� �ռ��� ���ڿ��� �ε����� max_index�� �������ش�
		for (int a = 0; a < N; a++) {
			curr_max = 0;
			for (int b = 0; b < strlen(names[a]); b++) {
				if (names[a][b] == ' ')	continue;
				alphabet = (int)(names[a][b] - 'A');
				if (is_exist[a][alphabet] == false) {
					is_exist[a][alphabet] = true;
					curr_max++;
				}
			}

			if (curr_max > max_num) {
				max_num = curr_max;
				max_index = a;
			}
			else if (curr_max == max_num) {
				if (strcmp(names[a], names[max_index]) < 0)	max_index = a;
			}
		}

		printf("#%d %s\n", test_case, names[max_index]);
	}
	return 0;
}