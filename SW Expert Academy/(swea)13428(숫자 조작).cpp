/*
문제 링크 : https://swexpertacademy.com/main/main.do
완전탐색 문제다.

가능한 모든 조합을 만들고 최소 최대값을 갱신해주면 된다.
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
		//입력값 저장 및 변수 초기화
		scanf("%s", input);
		answer_max = -1;
		answer_min = 1000000000;
		for (int a = 0; a < 10; a++)	str[a] = 0;
		//아무것도 바꾸지 않은 것의 수 확인
		temp = string_to_int(input);
		if (temp > answer_max)	answer_max = temp;
		if (temp < answer_min)	answer_min = temp;
		//a번째 수와 b번째 수를 바꿔가며 최소 최대값 갱신
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
//idx1의 수와 idx2의 수를 바꾼 값을 str에 저장하는 함수
void swap_two(char input[10], char str[10], int idx1, int idx2) {
	for (int a = 0; a < strlen(input); a++) {
		if (a != idx1 && a != idx2) {
			str[a] = input[a];
		}
	}
	str[idx1] = input[idx2];
	str[idx2] = input[idx1];
}
//string to int 변환 함수
int string_to_int(char str[10]) {
	int ret = 0, temp = 1;
	for (int a = strlen(str) - 1; a >= 0; a--) {
		ret += (int)(str[a] - '0') * temp;
		temp *= 10;
	}

	return ret;
}