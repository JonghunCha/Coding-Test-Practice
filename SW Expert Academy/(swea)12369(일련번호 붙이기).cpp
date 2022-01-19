/*
���� ��ũ : https://swexpertacademy.com/main/main.do
����� �� �ִ� ���ĺ��� ������ a���� ��, b�ڸ� ���ڿ��� ������ a^b���̴�.

�̸� �̿��ϸ� ���� �ذ��� �� �ִ� ������.
*/
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

long long myPow(int n, int times);

int main(int argc, char** argv)
{
	int T;
	long long N;
	char input[50], answer_in_char[100];
	string str, answer;

	scanf("%d\n", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ����(char�迭�� ���� �Է°� string�� ����) + ����
		scanf("%s %lld", input, &N);
		str.clear();
		for (int a = 0; a < strlen(input); a++) {
			str.push_back(input[a]);
		}
		sort(str.begin(), str.end());
		//������ ���̰� �� �ڸ����� ���
		unsigned long long near_N = 0, temp = str.size();
		int len = 0;

		for (int a = 1; a <= 100; a++) {
			near_N += temp;
			if (near_N >= N) {
				len = a;
				N -= near_N - temp;
				break;
			}
			temp *= str.size();
		}
		//������ �� �� ���ں��� �ϳ��� �˾Ƴ���
		answer.clear();
		for (int a = len - 1; a >= 0; a--) {
			for (int b = 0; b < str.size(); b++) {
				if (N <= myPow(str.size(), a) * (b + 1)) {
					answer.push_back(str[b]);
					N -= myPow(str.size(), a) * b;
					break;
				}
			}
		}
		//string�� answer�� char �迭�� �ٲٰ� ���� ���
		for (int a = 0; a < answer.size(); a++) {
			answer_in_char[a] = answer[a];
		}
		answer_in_char[answer.size()] = 0;

		printf("#%d %s\n", test_case, answer_in_char);
	}
	return 0;
}
//n�� times���� ��ȯ
long long myPow(int n, int times) {
	long long ret = 1;

	if (n == 1)	return ret;

	for (int a = 0; a < times; a++) {
		ret *= n;
	}

	return ret;
}