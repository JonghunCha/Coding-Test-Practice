/*
문제 링크 : https://www.acmicpc.net/problem/1013
단순 구현 문제에 가깝다.

문제에서 말하는 전파들의 패턴은 (100+1+ | 01+)이다.

전파들의 처음부터 끝까지 살피며 순간순간 어떠한 상태인지를 저장해 나가면 해결할 수 있다.

아래 코드에서 mode가 그 상태를 나타내는데 값에 따른 상태는 아래와 같다.
0 : 아직 상태가 정해지지 않았으며 다음 입력값에 따라 상태가 바뀐다.
1 : 100+1+ 에서 첫 번째 1을 입력받은 상태
2 : 01 에서 0을 입력받은 상태
3 : 100+1+ 에서 첫 번째 0을 입력받은 상태
4 : 100+1+ 에서 0+부분에 진입한 상태
5 : 100+1+ 에서 1+부분에 진입한 상태
*/
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int T, mode = 0;
	string input;
	bool correct;
	//입력값 저장
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> input;
		if (input.size() < 2) {
			cout << "NO" << endl;
			continue;
		}
		if (input[0] == '1')	mode = 1;	//첫 문자가 1이면 mode는 1
		else	mode = 2;	//첫 문자가 0이면 mode는 2
		correct = true;
		for (int b = 1; b < input.size(); b++) {
			//mode가 0일 땐 다음 문자의 값에 따라 mode를 1또는 2로 바꿈
			if (mode == 0) {	
				if (input[b] == '1')	mode = 1;
				else	mode = 2;
			}
			//직전에 100+1+의 첫 번째 1에 진입한 것으로 다음 문자는 0이 나와야 올바른 것이고, mode는 3으로 바꿈
			else if (mode == 1) {
				if (input[b] == '1') {
					correct = false;
					break;
				}
				else	mode = 3;
			}
			//직전에 01에 진입한 것으로 다음 문자는 1이 나와야만 올바른 것이고, 01패턴이 끝났음으로 mode는 0으로 바꿈
			else if (mode == 2) {
				if (input[b] == '0') {
					correct = false;
					break;
				}
				else	mode = 0;
			}
			//직전에 100+1+의 0을 받은 것으로 다음 문자는 0이 나와야만 올바른 것이고, 0+에 진입하였기에 mode는 4로 바꿈
			else if (mode == 3) {
				if (input[b] == '1') {
					correct = false;
					break;
				}
				else	mode = 4;
			}
			//0+에 진입한 상태로 0과 1모두 와도 된다. 그러나 1이 온 경우 해당 1이 1+의 마지막 1인지를 확인하여야 한다
			//1+의 마지막 1이라면 mode는 0으로 바꾸고 그렇지 않다면 1+가 진행되어야 하기에 mode는 5로 바꿈
			else if (mode == 4) {
				if (input[b] == '1') {
					if (b + 1 == input.size() || input[b + 1] == '0')	mode = 0;
					else	mode = 5;
				}
			}
			//mode5에서는 4가지 경우가 있을 수 있다.
			//1. 0이 입력되어 01에 진입한 경우
			//2. 1이 입력되었고 해당 1이 100+1+의 첫 번째 1인 경우
			//3. 1이 입력되었고 문자열의 마지막 문자인 경우(즉, 100+1+의 마지막 문자)
			//4. 1이 입력되었고 1+가 진행중인 경우
			else if (mode == 5) {
				if (input[b] == '1') {
					if (b + 2 < input.size() && input[b + 1] == '0' && input[b + 2] == '0')	mode = 1;
					else if (b + 1 == input.size())	mode = 0;
				}
				else	mode = 2;
			}
		}
		//중간에 correct가 바뀌지는 않았지만 전파가 올바른 표현으로 끝나지 않은 경우가 있을 수 있다.
		//이 경우엔 mode가 0이 아닐 것이다.
		if (correct) {
			if (mode == 0)	cout << "YES" << endl;
			else	cout << "NO" << endl;	
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}