/*
문제 링크 : https://swexpertacademy.com/main/main.do
완전 탐색으로 해결할 수 있는 문제다.

우선 가능한 글꼴의 최대 크기는 (W / 가장 긴 단어의 길이)이다.

이 점을 이용하여 글꼴의 최대 크기부터 1까지 낮춰가며 문제의 조건을 만족하는 가장 큰 글꼴의 크기를 찾으면 된다.

이 때, 단어는 현재 row에 추가할 수 있다면 무조건 추가하는 것이 전체 row를 가장 작게 만드는 방법이다.
*/
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
	int T, H, W, N;
	char input_str[1001];
	vector<string> inputs;
	string temp;
	
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장
		scanf("%d %d %d", &H, &W, &N);
		getchar();
		scanf("%[^\n]s", input_str);
		//입력받은 문자열을 각 단어별로 나누어 inputs에 저장
		temp.clear();
		inputs.clear();
		for (int a = 0; a < strlen(input_str); a++) {
			if (input_str[a] == ' ') {
				inputs.push_back(temp);
				temp.clear();
			}
			else {
				temp.push_back(input_str[a]);
			}
		}
		inputs.push_back(temp);
		//가장 긴 단어의 길이 계산
		int longest_len = 0;

		for (int a = 0; a < inputs.size(); a++) {
			if (inputs[a].size() > longest_len) {
				longest_len = inputs[a].size();
			}
		}
		//가장 긴 단어를 기준으로 가능한 최대의 글꼴 크기부터 1씩 낮추어가며 문제의 조건을 만족하는 글꼴의 크기를 찾는다
		int max_row, max_col, row_num, col_num, max_word_size;
		bool ispossible = false;

		max_word_size = W / longest_len;
		for (int a = max_word_size; a >= 1; a--) {
			max_row = H / a;
			max_col = W / a;
			row_num = 1;
			col_num = 0;
			for (int b = 0; b < inputs.size(); b++) {
				if (col_num + inputs[b].size() > max_col) {	//b번째 단어를 추가하면 max_col을 넘어가는 경우 다음 row로 이동
					row_num++;
					col_num = inputs[b].size() + 1;
				}
				else {	//b번째 단어를 추가해도 되는 경우
					col_num += inputs[b].size() + 1;
				}
			}
			//만약 사용한 row수가 사용가능한 max_row보다 작거나 같다면 문제의 조건을 만족
			if (row_num <= max_row) {
				printf("#%d %d\n", test_case, a);
				ispossible = true;
				break;
			}
		}

		if (!ispossible) {
			printf("#%d 0\n", test_case);
		}
	}
	return 0;
}