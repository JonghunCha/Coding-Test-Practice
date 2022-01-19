/*
문제 링크 : https://swexpertacademy.com/main/main.do
사용할 수 있는 알파벳의 갯수가 a개일 때, b자리 문자열의 갯수는 a^b개이다.

이를 이용하면 쉽게 해결할 수 있는 문제다.
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
		//입력값 저장(char배열로 받은 입력값 string에 저장) + 정렬
		scanf("%s %lld", input, &N);
		str.clear();
		for (int a = 0; a < strlen(input); a++) {
			str.push_back(input[a]);
		}
		sort(str.begin(), str.end());
		//정답의 길이가 몇 자리인지 계산
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
		//정답의 맨 앞 문자부터 하나씩 알아낸다
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
		//string인 answer를 char 배열로 바꾸고 정답 출력
		for (int a = 0; a < answer.size(); a++) {
			answer_in_char[a] = answer[a];
		}
		answer_in_char[answer.size()] = 0;

		printf("#%d %s\n", test_case, answer_in_char);
	}
	return 0;
}
//n의 times승을 반환
long long myPow(int n, int times) {
	long long ret = 1;

	if (n == 1)	return ret;

	for (int a = 0; a < times; a++) {
		ret *= n;
	}

	return ret;
}