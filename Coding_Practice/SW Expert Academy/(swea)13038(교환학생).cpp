/*
문제 링크 : https://swexpertacademy.com/main/main.do
단순 시뮬레이션 문제다.

코드를 보면 쉽게 이해할 수 있을 것이다.

N % weekclass가 0인지 아닌지로 나눈 이유는 아래와 같다.

만약 나머지가 없는 경우 N / weekclass중 몇일은 개강일이 언제인지에 따라 정답에 포함되지 않는 요일을 가질 수 있다. 따라서 (N - 1) / weekclass를 통해 그러한 문제를 잡았다.

반대로 나머지가 있는 경우 N / weekclass는 온전히 정답에 포함되어야만 하는 기간이기에 상관이 없다.
*/
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int T, N, A[7], remain, weekclass, answer, temp;

	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 변수 초기화
		cin >> N;
		weekclass = 0;
		answer = 1000000;
		for (int a = 0; a < 7; a++) {
			cin >> A[a];
			if (A[a] == 1)	weekclass++;
		}

		if (N % weekclass == 0) {	//들어야하는 강의 수가 한주에 들을 수 있는 강의수로 나머지 없이 나누어지는 경우
			for (int a = 0; a < 7; a++) {	//개강일이 일요일부터~토요일까지인 경우
				temp = ((N - 1) / weekclass) * 7;
				remain = weekclass;

				for (int b = a; b < a + 7; b++) {
					temp++;
					if (A[b % 7] == 1)	remain--;
					if (remain == 0) {
						if (temp < answer)	answer = temp;
						break;
					}
				}
			}
		}
		else {	//들어야하는 강의 수가 한주에 들을 수 있는 강의수로 나누었을 때 나머지가 있는 경우
			for (int a = 0; a < 7; a++) {	
				temp = (N / weekclass) * 7;
				remain = N % weekclass;
				for (int b = a; b < a + 7; b++) {
					temp++;
					if (A[b % 7] == 1)	remain--;
					if (remain == 0) {
						if (temp < answer)	answer = temp;
						break;
					}
				}
			}
		}

		cout << '#' << test_case << ' ' << answer << endl;
	}
	return 0;
}