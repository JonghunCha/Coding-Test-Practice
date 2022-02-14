/*
문제 링크 : https://swexpertacademy.com/main/main.do
문자열 처리 문제이다.

우선 ~로 인해 반복되는 부분을 제거한 나머지를 하나의 vector에 저장하였다.

그런 다음 해당 벡터가 신종폭탄 (FFMCM 혹은 FCMF)로만 이루어져 있다면 DETECTED!를, 아니라면 NOTHING!을 출력하였다.
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int T, inputlen, curr_state, index;
	char input[140];
	vector<char> bomb;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%s", input);
		inputlen = strlen(input);
		curr_state = 0;
		bomb.clear();
		//~부분을 제거(curr_state가 0이면 신종폭탄의 시작부분, 1이라면 1번 신종폭탄의 FF직후, 2라면 1번 신종폭탄의 MCM부분 직후, 3이라면 2번 신종폭탄의 FC직후를 의미)
		for (index = 0; index < inputlen;) {
			if (curr_state == 0) {
				if (index < inputlen - 4 && input[index] == 'F' && input[index + 1] == 'F') {
					curr_state = 1;
					index += 2;
					bomb.push_back('F');
					bomb.push_back('F');
				}
				else if (index < inputlen - 3 && input[index] == 'F' && input[index + 1] == 'C') {
					curr_state = 3;
					index += 2;
					bomb.push_back('F');
					bomb.push_back('C');
				}
				else
				{
					break;
				}
			}
			else if (curr_state == 1) {
				if (input[index] == 'F') {
					index++;
					continue;
				}
				else if (index < inputlen - 2 && input[index] == 'M' && input[index + 1] == 'C' && input[index + 2] == 'M') {
					curr_state = 2;
					index += 3;
					bomb.push_back('M');
					bomb.push_back('C');
					bomb.push_back('M');
				}
				else {
					break;
				}
			}
			else if (curr_state == 2) {
				if (input[index] == 'M') {
					index++;
					continue;
				}
				else if (index < inputlen - 4 && input[index] == 'F' && input[index + 1] == 'F') {
					curr_state = 1;
					index += 2;
					bomb.push_back('F');
					bomb.push_back('F');
				}
				else if (index < inputlen - 3 && input[index] == 'F' && input[index + 1] == 'C') {
					curr_state = 3;
					index += 2;
					bomb.push_back('F');
					bomb.push_back('C');
				}
				else {
					break;
				}
			}
			else if (curr_state == 3) {
				if (input[index] == 'C') {
					index++;
					continue;
				}
				else if (index < inputlen - 1 && input[index] == 'M' && input[index + 1] == 'F') {
					curr_state = 0;
					index += 2;
					bomb.push_back('M');
					bomb.push_back('F');
				}
				else {
					break;
				}
			}
		}
		//bomb벡터가 신종폭탄으로만 이루어져 있는지 확인
		for (index = 0; index < bomb.size();) {
			if (bomb[index] == 'F' && bomb[index + 1] == 'F' && bomb[index + 2] == 'M' && bomb[index + 3] == 'C' && bomb[index + 4] == 'M')	index += 5;
			else if (bomb[index] == 'F' && bomb[index + 1] == 'C' && bomb[index + 2] == 'M' && bomb[index + 3] == 'F')	index += 4;
			else	break;
		}

		if (index == bomb.size())	printf("#%d DETECTED!\n", test_case);
		else	printf("#%d NOTHING!\n", test_case);
	}
	return 0;
}