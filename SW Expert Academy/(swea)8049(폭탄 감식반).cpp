/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���ڿ� ó�� �����̴�.

�켱 ~�� ���� �ݺ��Ǵ� �κ��� ������ �������� �ϳ��� vector�� �����Ͽ���.

�׷� ���� �ش� ���Ͱ� ������ź (FFMCM Ȥ�� FCMF)�θ� �̷���� �ִٸ� DETECTED!��, �ƴ϶�� NOTHING!�� ����Ͽ���.
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
		//~�κ��� ����(curr_state�� 0�̸� ������ź�� ���ۺκ�, 1�̶�� 1�� ������ź�� FF����, 2��� 1�� ������ź�� MCM�κ� ����, 3�̶�� 2�� ������ź�� FC���ĸ� �ǹ�)
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
		//bomb���Ͱ� ������ź���θ� �̷���� �ִ��� Ȯ��
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