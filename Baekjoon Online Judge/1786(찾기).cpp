/*
문제 링크 : https://www.acmicpc.net/problem/1786
문자열 검색 알고리즘인 KMP를 이용하는 문제다.

KMP알고리즘을 제대로 이해하고 있다면 해결하는데 큰 문제는 없을 것이다.

KMP알고리즘에 대한 자세한 설명은 인터넷에 많은 자료가 있다.

추가로 공백을 입력받기 위해 getline을 사용하였다.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> Get_Pi(string P);	//KMP알고리즘의 prefix == suffix가 될 수 있는 부분 문자열중 가장 긴 것의 길이를 계산
vector<int> KMP(string T, string P);	//KMP알고리즘을 이용하여 정답도출

int main(void) {
	string T, P;
	vector<int> answer;
	//입력값 저장
	getline(cin, T);
	getline(cin, P);
	answer = KMP(T, P);
	cout << answer.size() << endl;
	for (int a = 0; a < answer.size(); a++)	cout << answer[a] << ' ';

	return 0;
}

vector<int> Get_Pi(string P) {
	vector<int> ret(P.size(), 0);
	int index = 0, psize = P.size();
	for (int a = 1; a < psize; a++) {
		while (index > 0 && P[a] != P[index])	index = ret[index - 1];
		if (P[a] == P[index])	ret[a] = ++index;
	}
	return ret;
}

vector<int> KMP(string T, string P) {
	vector<int> ret;
	vector<int> pi = Get_Pi(P);
	int index = 0, tsize = T.size(), psize = P.size();
	for (int a = 0; a < tsize; a++) {
		while (index > 0 && T[a] != P[index])	index = pi[index - 1];
		if (T[a] == P[index]) {
			if (index == psize - 1) {
				ret.emplace_back(a - psize + 2);	//문제에서 문자열의 index가 1부터 시작하기에 + 1을 해준다
				index = pi[index];
			}
			else	index++;
		}
	}
	return ret;
}