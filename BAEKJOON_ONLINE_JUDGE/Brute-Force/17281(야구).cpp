/*
���� ��ũ : https://www.acmicpc.net/problem/17281
����Ž������ �ذ��� �� �ִ� ������.
������ ���ǿ��� 1�� ������ 4�� Ÿ�ڷ� ������ �Ǿ� �ִ��Ͽ�����, 2��~9�� �������� 4�� Ÿ�ڰ� �ƴ� �ٸ� Ÿ������ �ϴ� ��� ���տ� ���� ����ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int answer = 0;

void Get_Answer(const int N, const int inputs[51][10], const int combination[10]);

int main(void) {
	//N�� �̴��� ��, inputs�� �� �̴׺� �������� ���, combination�� ������ Ÿ�� ��ġ�� �ǹ�
	int N, inputs[51][10], combination[10];
	//�Է°��� ����
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < 10; j++) {
			cin >> inputs[i][j];
		}
	}
	//������ ��� Ÿ�� ���տ� ���� Get_Answer�Լ� ȣ��
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
	//out�� �� �̴׿��� outī��Ʈ ����, index�� ���� Ÿ��, base�� �� ���̽��� ���ڰ� �ִ��� ������, score�� ��ü ������ �ǹ�
	int out, index = 1, base[4], score = 0;
	//�̴� ���� ���� ������ ����
	for (int i = 1; i <= N; i++) {
		base[1] = 0;
		base[2] = 0;
		base[3] = 0;
		out = 0;
		//outī��Ʈ�� 3�� �Ǳ� ������ �ݺ�
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