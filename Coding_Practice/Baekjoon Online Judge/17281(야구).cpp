/*
문제 링크 : https://www.acmicpc.net/problem/17281
완전탐색으로 해결할 수 있는 문제다.
문제의 조건에서 1번 선수는 4번 타자로 고정이 되어 있다하였으니, 2번~9번 선수들을 4번 타자가 아닌 다른 타순으로 하는 모든 조합에 대해 계산하면 된다.
*/
#include <iostream>
using namespace std;

int answer = 0;

void Make_Combination(const int N, const int inputs[51][10], int combination[10], int index);
void Get_Answer(const int N, const int inputs[51][10], const int combination[10]);

int main(void) {
	//N은 이닝의 수, inputs는 각 이닝별 선수들의 결과, combination은 선수의 타순 배치를 의미
	int N, inputs[51][10], combination[10];
	//입력값을 저장
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < 10; j++) {
			cin >> inputs[i][j];
		}
	}
	//가능한 모든 타순 조합에 대해 계산
	for (int i = 1; i < 10; i++)	combination[i] = 0;
	combination[4] = 1;

	Make_Combination(N, inputs, combination, 2);

	cout << answer;

	return 0;
}
//DFS를 통해 모든 타순 조합을 만들고 Get_Answer함수를 호출
//N과 inputs는 조합이 완성 된 뒤 Get_Answer를 호출하기 위해 전달받는다
//combination은 타순의 조합을 의미하고 index는 이번 호출에서 어느 선수의 자리를 정할지를 의미한다
void Make_Combination(const int N, const int inputs[51][10], int combination[10], int index) {
	if (index == 10) {
		Get_Answer(N, inputs, combination);
	}
	else {
		for (int i = 1; i < 10; i++) {
			if (combination[i] == 0) {
				combination[i] = index;
				Make_Combination(N, inputs, combination, index + 1);
				combination[i] = 0;
			}
		}
	}
}

void Get_Answer(const int N, const int inputs[51][10], const int combination[10]) {
	//out은 각 이닝에서 out카운트 값을, index는 현재 타순, base는 각 베이스에 주자가 있는지 없는지, score는 전체 점수를 의미
	int out, index = 1, base[4], score = 0;
	//이닝 수에 대해 게임을 진행
	for (int i = 1; i <= N; i++) {
		base[1] = 0;
		base[2] = 0;
		base[3] = 0;
		out = 0;
		//out카운트가 3이 되기 전까지 반복
		while (out < 3) {
			if (inputs[i][combination[index]] == 0) {
				out++;
			}
			else if (inputs[i][combination[index]] == 1) {
				if (base[3] == 1) {
					score++;
					base[3] = 0;
				}
				if (base[2] == 1) {
					base[3] = 1;
					base[2] = 0;
				}
				if (base[1] == 1)	base[2] = 1;
				base[1] = 1;
			}
			else if (inputs[i][combination[index]] == 2) {
				if (base[3] == 1) {
					score++;
					base[3] = 0;
				}
				if (base[2] == 1)	score++;
				if (base[1] == 1) {
					base[3] = 1;
					base[1] = 0;
				}
				base[2] = 1;
			}
			else if (inputs[i][combination[index]] == 3) {
				if (base[3] == 1)	score++;
				if (base[2] == 1) {
					score++;
					base[2] = 0;
				}
				if (base[1] == 1) {
					score++;
					base[1] = 0;
				}
				base[3] = 1;
			}
			else {
				if (base[3] == 1) {
					score++;
					base[3] = 0;
				}
				if (base[2] == 1) {
					score++;
					base[2] = 0;
				}
				if (base[1] == 1) {
					score++;
					base[1] = 0;
				}
				score++;
			}

			if (index == 9)	index = 1;
			else index++;
		}
	}

	if (score > answer)	answer = score;
}