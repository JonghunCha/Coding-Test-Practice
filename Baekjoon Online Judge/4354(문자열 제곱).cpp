/*
문제 링크 : https://www.acmicpc.net/problem/4354
KMP알고리즘을 이용하여 해결할 수 있는 문제다.

예를 들어 "abcabc"의 실패함수 값은 "000123"이다. 이는 접미사와 접두사가 3만큼 반복 된다는 것이고, 반복되는 부분을 제외한 부분의 길이는 6 - 3 = 3이다.

즉 "abcabc"는 6 / (6 - 3)만큼 최대로 반복되는 것이다.

그러나 예외 경우가 있다. "abcdabc"의 경우 접두사와 접미사의 길이는 3으로 같다. 그러나 문제의 s = a^n 조건을 위배한다.

이는 length / (length - pi[length - 1])이 정확하게 떨어지는 경우와 그렇지 않은 경우로 나누어 보면 알 수 있다.

위의 식의 나머지가 0인 경우는 s = a^n 조건을 만족하는 경우이고, 나머지가 0이 아닌 경우는 반대의 경우이다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

char input[1000001];
int pi[1000001];

int main(void) {
	int k, length, answer;

	while (1) {
		scanf("%s", input);
		k = 0;
		length = strlen(input);
		
		if (length == 1 && input[0] == '.')	break;
		//pi값 초기화
		for (int a = 0; a < length; a++)	pi[a] = 0;
		//pi값 계산
		for (int a = 1; a < length; a++) {
			while (k > 0 && input[a] != input[k])	k = pi[k - 1];
			if (input[a] == input[k])	pi[a] = ++k;
		}

		if (length % (length - pi[length - 1]) != 0)	answer = 1;	//반복되는 경우가 없다면 답은 1
		else	answer = length / (length - pi[length - 1]);	//반복되는 경우 중복되는 부분을 다 날리고 최대 반복횟수 계산

		printf("%d\n", answer);
	}

	return 0;
}