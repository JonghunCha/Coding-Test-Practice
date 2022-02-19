/*
���� ��ũ : https://swexpertacademy.com/main/main.do
����Ž�� ������.

������ ��� ������ ����� �ּ� �ִ밪�� �������ָ� �ȴ�.
*/
#include <cstdio>
#include <cstring>
using namespace std;

void swap_two(char input[10], char str[10], int idx1, int idx2);
int string_to_int(char str[10]);

int main(int argc, char** argv)
{
	int T, answer_max, answer_min, temp;
	char input[10], str[10];

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ���� �ʱ�ȭ
		scanf("%s", input);
		answer_max = -1;
		answer_min = 1000000000;
		for (int a = 0; a < 10; a++)	str[a] = 0;
		//�ƹ��͵� �ٲ��� ���� ���� �� Ȯ��
		temp = string_to_int(input);
		if (temp > answer_max)	answer_max = temp;
		if (temp < answer_min)	answer_min = temp;
		//a��° ���� b��° ���� �ٲ㰡�� �ּ� �ִ밪 ����
		for (int a = 0; a < strlen(input) - 1; a++) {
			for (int b = a + 1; b < strlen(input); b++) {
				swap_two(input, str, a, b);
				if (str[0] == '0')	continue;
				temp = string_to_int(str);
				if (temp > answer_max)	answer_max = temp;
				if (temp < answer_min)	answer_min = temp;
			}
		}

		printf("#%d %d %d\n", test_case, answer_min, answer_max);
	}
	return 0;
}
//idx1�� ���� idx2�� ���� �ٲ� ���� str�� �����ϴ� �Լ�
void swap_two(char input[10], char str[10], int idx1, int idx2) {
	for (int a = 0; a < strlen(input); a++) {
		if (a != idx1 && a != idx2) {
			str[a] = input[a];
		}
	}
	str[idx1] = input[idx2];
	str[idx2] = input[idx1];
}
//string to int ��ȯ �Լ�
int string_to_int(char str[10]) {
	int ret = 0, temp = 1;
	for (int a = strlen(str) - 1; a >= 0; a--) {
		ret += (int)(str[a] - '0') * temp;
		temp *= 10;
	}

	return ret;
}