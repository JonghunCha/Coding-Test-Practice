/*
문제 링크 : https://www.acmicpc.net/problem/1305
KMP알고리즘을 이용하는 문제다.

반복되는 문자열이 가장 짧은 것의 길이는 현재 전광판의 문자열에서 접두사와 접미사가 최대 길이로 겹치는 것을 제거한 것이다.

접두사와 접미사가 같다는 것은 해당 길이 만큼은 반복되었다는 것이고 우리가 원하는 것은 광고 하나의 길이이기 때문에 반복된 부분을 제거해야하기 때문이다.

kmp알고리즘을 이해한다면 쉬운 문제지만, kmp알고리즘을 모른다면 어려운 문제다.(다음에 꼭 다시 풀어봐야할 문제인듯..)
*/
#include <iostream>
#include <string>
using namespace std;

int pi[1000000];

int main(void) {
	int L, answer = 1, a, b = 0;
	string str;

	cin >> L;
	cin >> str;
	//pi는 a번째 인덱스까지 보았을 때 접두사와 접미사가 일치하는 길이를 저장
	for (a = 0; a < L; a++) {
		pi[a] = 0;
	}
	//pi를 계산(이해가 안된다면 구글링 해보기! 설명 잘해놓은 사이트 많음)
	for (a = 1; a < L; a++) {
		while (b > 0 && str[a] != str[b])	b = pi[b - 1];	
		if (str[a] == str[b])	pi[a] = ++b;	
	}
	cout << L - pi[L - 1] << endl;	//광고 문자는 무한 반복 되기에 pi[L - 1]이 항상 제일 크다

	return 0;
}