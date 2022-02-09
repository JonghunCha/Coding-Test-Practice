/*
문제 링크 : https://www.acmicpc.net/problem/2437
그리디 알고리즘 문제다.

문제 자체가 쉬워 설명을 생략하겠다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
	int N, inputs[1000], answer;
	//입력값 저장 및 정렬
	scanf("%d", &N);
	for (int a = 0; a < N; a++)	scanf("%d", &inputs[a]);
	sort(inputs, inputs + N);
	//무게가 1인 추가 없는 예외 처리
	if (inputs[0] > 1) {
		printf("1\n");
		return 0;
	}
	
	answer = 1;
	for (int a = 1; a < N; a++) {
		if (answer < inputs[a] - 1) {
			break;
		}
		else {
			answer += inputs[a];
		}
	}

	printf("%d\n", answer + 1);

	return 0;
}