/*
문제 링크 : https://www.acmicpc.net/problem/9935
문자열 처리 문제이긴 하나 string을 스택처럼 사용한다는 점에서 스택문제로 분류하였다.

주어진 문자열을 answer에 하나씩 집어 넣는다.

만약 집어넣는 문자가 폭발 문자열의 마지막 문자라면, answer의 뒷 부분(폭발 문자열 길이만큼)과 폭발 문자열을 비교한다.

만약 둘이 같다면 폭발 문자열을 answer에서 pop()하고 그렇지 않다면 계속 진행을 한다.
*/
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(void) {
	string input, boom, answer;
	int n;
	//입력값 저장 및 변수 초기화
	answer.reserve(1000000);
	cin >> input >> boom;
	n = boom.size();

	for (int a = 0; a < input.size(); a++) {
		//answer에 문자를 하나씩 넣는다
		answer.push_back(input[a]);
		//만약 해당 루프에서 넣은 문자가 폭발 문자열의 맨 마지막 문자이고 answer의 길이가 폭발 문자열과 같거나 크면 폭발 문자열이 만들어졌는지 비교
		if (input[a] == boom[n - 1] && answer.size() >= n && answer.substr(answer.size() - n, n).compare(boom) == 0) {
			for (int a = 0; a < n; a++)	answer.pop_back();
		}
	}

	if (answer.size() == 0)	cout << "FRULA" << endl;
	else	cout << answer << endl;

	return 0;
}