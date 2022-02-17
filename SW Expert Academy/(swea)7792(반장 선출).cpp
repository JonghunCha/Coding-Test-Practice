/*
문제 링크 : https://swexpertacademy.com/main/main.do
단순한 문자열 처리 문제다.

각 문자열에 몇 종류의 알파벳이 있는지를 확인하고 가장 많은 알파벳을 가지며 사전순으로 가장 앞서는 문자열의 인덱스를 갱신해 준다.

모든 문자열에 대한 탐색을 마친 뒤 정답을 출력하면 된다.
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
		//입력값 저장 및 변수 초기화
		scanf("%d", &N);
		memset(count, 0, sizeof(int) * 100);
		memset(is_exist, false, sizeof(bool) * 2600);
		max_num = 0;
		max_index = 0;

		for (int a = 0; a < N; a++) {
			getchar();
			scanf("%[^\n]s", names[a]);
		}
		//각 문자열에 대해 가장 다양한 종류의 알파벳을 가지며 사전순으로 앞서는 문자열의 인덱스를 max_index에 저장해준다
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