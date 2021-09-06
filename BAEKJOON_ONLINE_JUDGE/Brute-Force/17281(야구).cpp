/*
문제 링크 : https://www.acmicpc.net/problem/17281
완전탐색으로 해결할 수 있는 문제다.
문제의 조건에서 1번 선수는 4번 타자로 고정이 되어 있다하였으니, 2번~9번 선수들을 4번 타자가 아닌 다른 타순으로 하는 모든 조합에 대해 계산하면 된다.
*/
#include <iostream>
using namespace std;

int answer = 0;

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
	//가능한 모든 타순 조합에 대해 Get_Answer함수 호출
	for (int i = 1; i < 10; i++)	combination[i] = 0;
	combination[4] = 1;

	for (int a = 1; a < 10; a++) {
		if (combination[a] == 0) {
			combination[a] = 2;
			for (int b = 1; b < 10; b++) {
				if (combination[b] == 0) {
					combination[b] = 3;
					for (int c = 1; c < 10; c++) {
						if (combination[c] == 0) {
							combination[c] = 4;
							for (int d = 1; d < 10; d++) {
								if (combination[d] == 0) {
									combination[d] = 5;
									for (int e = 1; e < 10; e++) {
										if (combination[e] == 0) {
											combination[e] = 6;
											for (int f = 1; f < 10; f++) {
												if (combination[f] == 0) {
													combination[f] = 7;
													for (int g = 1; g < 10; g++) {
														if (combination[g] == 0) {
															combination[g] = 8;
															for (int h = 1; h < 10; h++) {
																if (combination[h] == 0) {
																	combination[h] = 9;
																	Get_Answer(N, inputs, combination);
																	combination[h] = 0;
																}
															}
															combination[g] = 0;
														}
													}
													combination[f] = 0;
												}
											}
											combination[e] = 0;
										}
									}
									combination[d] = 0;
								}
							}
							combination[c] = 0;
						}
					}
					combination[b] = 0;
				}
			}
			combination[a] = 0;
		}
	}

	cout << answer;

	return 0;
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