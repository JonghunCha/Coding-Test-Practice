/*
문제 링크 : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRUN9KfZ8DFAUo
단순한 완전탐색 문제다.

회전을 통해 구할 수 있는 모든 수를 구한다. 여기서 중복은 제거해야하기 때문에 set을 이용하였다.

모든 수를 구하고 나면 K번째로 큰 수를 출력하면 된다.
*/
#include <iostream>
#include <set>
#include <string>

using namespace std;

int convert16to10(string str);

int main(int argc, char** argv)
{
	int T, N, K, count = 0, answer;
	set<string> __set;
	string input;
	string temp;
	
	cin >> T;
	
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 set초기화
		cin >> N >> K;
		cin >> input;
		while (!__set.empty())	__set.erase(__set.begin());
		//생성가능한 수를 구한 뒤 set에 넣는다
		for (int a = 0; a < input.size(); a++) {
			while (!temp.empty())	temp.pop_back();
			for (int b = 0; b < (N / 4); b++) {
				temp.push_back(input[(a + b) % N]);
			}
			if (__set.find(temp) == __set.end()) {	
				__set.insert(temp);
			}
		}
		//K번째 큰 수를 10진수로 변환한 뒤 출력
		count = 0;
		for (set<string>::iterator itr = __set.begin(); itr != __set.end(); itr++) {
			if (count == __set.size() - K) {
				answer = convert16to10(*itr);
				cout << '#' << test_case << ' ' << answer << endl;
				break;
			}
			else	count++;
		}
	}
	return 0;
}
//16진수 string을 10진수 int로 변환
int convert16to10(string str) {
	int ret = 0, temp = 1;

	for (int a = str.size() - 1; a >= 0; a--) {
		if (str[a] >= '0' && str[a] <= '9') {
			ret += temp * (int)(str[a] - '0');
		}
		else {
			ret += temp * (int)(str[a] - 'A' + 10);
		}
		temp *= 16;
	}
	return ret;
}