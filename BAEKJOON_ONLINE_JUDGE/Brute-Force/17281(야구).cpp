/*
���� ��ũ : https://www.acmicpc.net/problem/17281
����Ž������ �ذ��� �� �ִ� ������.
������ ���ǿ��� 1�� ������ 4�� Ÿ�ڷ� ������ �Ǿ� �ִ��Ͽ�����, 2��~9�� �������� 4�� Ÿ�ڰ� �ƴ� �ٸ� Ÿ������ �ϴ� ��� ���տ� ���� ����ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int answer = 0;

void Make_Combination(const int N, const int inputs[51][10], int combination[10], int index);
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
	//������ ��� Ÿ�� ���տ� ���� ���
	for (int i = 1; i < 10; i++)	combination[i] = 0;
	combination[4] = 1;

	Make_Combination(N, inputs, combination, 2);

	cout << answer;

	return 0;
}
//DFS�� ���� ��� Ÿ�� ������ ����� Get_Answer�Լ��� ȣ��
//N�� inputs�� ������ �ϼ� �� �� Get_Answer�� ȣ���ϱ� ���� ���޹޴´�
//combination�� Ÿ���� ������ �ǹ��ϰ� index�� �̹� ȣ�⿡�� ��� ������ �ڸ��� �������� �ǹ��Ѵ�
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