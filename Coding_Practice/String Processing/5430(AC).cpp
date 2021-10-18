/*
문제 링크 : https://www.acmicpc.net/problem/5430
문자열 파싱을 요구하는 문제다.

문제에서 제시된 2가지 함수 R과 D는 각각 숫자 배열을 뒤집는 함수, 맨 앞의 숫자를 지우는 함수이다.

그러나 R함수를 구현하기 위해 실제로 배열을 일일히 뒤집는 것은 매우 비효율적이다. 이를 해결하기 위해 배열은 그래도 두고 앞과 뒤의 표시만 바꿔주었다.

또한 위와 같이 구현을 하면 D함수에 의해 배열의 앞에서도 삭제가 일어나고 뒤에서도 삭제가 일어난다.
따라서 이러한 동작방식에 적합한 덱(deque)를 사용하였다.
*/
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void) {
	int T, N, index;
	string funtion, nums, temp;
	deque<string> dq;
	bool reverse, is_end;
	funtion.reserve(100001);
	nums.reserve(100001);
	//입력값 저장
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> funtion;
		cin >> N;
		cin >> nums;
		while (dq.size() > 0)	dq.pop_back();	//덱을 비워준다
		//입력 string에서 숫자에 해당되는 string만 덱에 채워준다
		for (int b = 0; b < nums.size(); b++) {
			if (nums[b] == '[' || nums[b] == ',') {
				index = 0;
				while (temp.size() > 0)	temp.pop_back();
				for (int c = b + 1; c < nums.size(); c++) {
					if (nums[c] != ',' && nums[c] != ']')	temp += nums[c];
					else	break;
				}
				if(temp.size() > 0)		dq.emplace_back(temp);
			}
		}
		reverse = false;	//reverse는 R함수에 의해 바뀌며 초기에는 false
		is_end = false;		//is_end는 에러가 난 경우 true가 된다
		for (int b = 0; b < funtion.size(); b++) {
			if (funtion[b] == 'R')	reverse = !reverse;
			else {
				if (!reverse && dq.size() > 0) {
					dq.erase(dq.begin());
				}
				else if (reverse && dq.size() > 0) {
					dq.erase(dq.end() - 1);
				}
				else {
					cout << "error" << endl;
					is_end = true;
					break;
				}
			}
		}
		//양식에 맞춰 정답을 출력
		if (!is_end) {
			cout << "[";
			if (!reverse) {
				for (int b = 0; b < dq.size(); b++) {
					cout << dq[b];
					if (b != dq.size() - 1)	cout << ",";
				}
			}
			else {
				for (int b = dq.size() - 1; b >= 0; b--) {
					cout << dq[b];
					if (b != 0)	cout << ",";
				}
			}
			cout << "]" << endl;
		}
	}
	return 0;
}