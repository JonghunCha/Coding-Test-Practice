/*
문제 링크 : https://www.acmicpc.net/problem/5052
문자열 비교를 묻는 문제다.

최대 10000개의 전화번호가 입력으로 주어지고 전화번호 목록이 문제에서 말하는 일관성이 있는지를 확인해야 한다.

가장 단순한 방법은 10000개의 전화번호에 대해 자신의 번호가 다른 번호의 접두어인 경우가 있는지 일일히 확인하면 된다.

그러나 이러한 방법으로 문제를 풀 경우 시간초과가 일어난다.

즉 모든 비교를 하지 않는 방법을 사용해야 하는데 이는 정렬을 통해서 가능하다.

만약 모든 번호가 오름차순으로 정렬이 되어 있다고 생각하자.

그렇다면 n번째 번호는 n+1번째 번호나 그 이후의 번호에게만 접두어가 될 수 있다. 또한 n번째 번호가 n+a번째 번호의 접두어라면 반드시 n+1번째 번호의 접두어이기도 하다.

따라서 정렬이 된 상태에서는 n번째와 n+1번째 번호만을 비교하면 된다.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	int T, N;
	string str;
	vector<string> inputs;
	bool is_end;
	inputs.reserve(10000);
	//입력값 저장
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> N;
		for (int b = 0; b < N; b++) {
			cin >> str;
			inputs.emplace_back(str);
		}
		//번호를 오름차순으로 정렬
		sort(inputs.begin(), inputs.end());
		//모든 n번째와 n+1번째의 번호 비교
		is_end = false;
		for (int a = 0; a < inputs.size() - 1; a++) {
			if (inputs[a + 1].compare(0, inputs[a].size(), inputs[a]) == 0) {
				cout << "NO" << endl;
				is_end = true;
				break;
			}
		}
		if (!is_end)	cout << "YES" << endl;
		//다음 테스트 케이스를 위해 벡터 비우기
		while (inputs.size() > 0)	inputs.pop_back();
	}
	return 0;
}