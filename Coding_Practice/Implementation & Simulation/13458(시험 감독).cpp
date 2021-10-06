/*
문제 링크 : https://www.acmicpc.net/problem/13458
단순 구현 문제로 굉장히 쉽고 간단한 문제다.

그러나 한 가지 고려해야 하는 점이 있다. 바로 자료형의 크기이다.

코딩 문제를 풀다보면 종종 나오는 함정중 하나인데, 정답 혹은 중간 과정의 값이 int형이 나타낼 수 있는 범위를 넘어서는 것이다.

이러한 경우 overflow혹은 underflow가 발생하여 실제 의도한 값이 아닌 다른 값이 메모리에 올라가게 된다.

이 문제도 정답이 int 범위를 벗어날 수 있기에 long long을 사용해 주어야 테스트 통과가 된다.
*/
#include <iostream>
using namespace std;

int main(void) {
	//정답이 int를 벗어날 수 있기에 long long으로 선언
	long long answer = 0;
	int N, B, C, temp;
	int* A;
	cin >> N;
	//배열 동적 할당
	A = new int[N + 1];
	//입력값 저장
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	cin >> B; cin >> C;
	//모든 고시장에 대하여
	for (int i = 1; i <= N; i++) {
		//고시장 인원이 총 감독이 감독할 수 있는 인원보다 작거나 같으면 감독은 1명만 필요
		if (A[i] <= B)	answer++;
		//감독이 2명 이상 필요한 경우 총 감독이 맡을 수 있는 인원을 제외하고 나머지 인원을 부 감독이 맡을 수 있는 인원으로 나눔(이 때 딱 맞아 떨어지지 않는 경우 1명 추가)
		else {
			temp = A[i] - B;
			answer++;
			answer += temp / C;
			if (temp % C > 0)	answer++;
		}
	}

	cout << answer;
	//동적 할당한 배열 해제
	delete []A;

	return 0;
}