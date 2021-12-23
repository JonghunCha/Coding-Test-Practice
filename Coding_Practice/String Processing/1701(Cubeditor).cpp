/*
문제 링크 : https://www.acmicpc.net/problem/1701
kmp로 해결할 수 있는 문제다.

다만 접두사와 접미사만 고려하는 것이 아니기에 문자열의 시작이 0번째인 것부터 end - 1번째인 것까지의 fail값을 모두 구한 뒤 가장 큰 값을 고르면 된다.
*/
#include <iostream>
using namespace std;

int fail[5000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//입력값 저장 및 변수 초기화
	string str;
	int start = 0, end, answer = 0, k;

	cin >> str;
	end = str.size() - 1;
	//start가 0부터 end - 1까지의 모든 경우를 계산
	while (start < end) {
		//fail값 초기화 및 공통부분의 갯수를 의미하는 변수 k를 0으로 설정
		for (int a = start; a <= end; a++)	fail[a] = 0;
		k = 0;
		//start + 1부터 end까지 fail값 계산
		for (int a = start + 1; a <= end; a++) {
			while (k > 0 && str[a] != str[k + start])	k = fail[k + start - 1];
			if (str[a] == str[k + start])	fail[a] = ++k;
		}
		//모든 fail값중 가장 큰 값을 answer에 저장
		for (int a = start; a <= end; a++) {
			if (fail[a] > answer)	answer = fail[a];
		}
		start++;
	}
	cout << answer << endl;

	return 0;
}