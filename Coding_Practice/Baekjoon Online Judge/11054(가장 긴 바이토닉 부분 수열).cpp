/*
���� ��ũ : https://www.acmicpc.net/problem/11054
Dynamic Programming���� �ذ��� �� �ִ� ������.

�켱 ������ ũ�� �� �κ����� ��������.

k��° ���� �������� ���� ���������� ���� ��, ���ʿ����� k��° ���� ���ԵǸ� ������������ ���� �� ������ ����, �����ʿ����� k��° ���� ���ԵǸ� ������������ ���� �� ������ ���̸� ���Ͽ���.

���������� 1��°���� N��°���� Ž���ϸ� (������ �������� ������ ���� + �������� �������� ������ ���� - 1)�� ���� ū ���� ����ϸ� �ȴ�.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, A[1002], dp_left[1002], dp_right[1002];

int main(void) {
	int temp, answer = 0;
	//�Է°� ���� �� ���� �ʱ�ȭ
	cin >> N;
	for (int a = 1; a <= N; a++) {
		cin >> A[a];
		dp_left[a] = -1;
		dp_right[a] = -1;
	}
	A[0] = 0;
	dp_left[0] = 0;
	A[N + 1] = 0;
	dp_right[N + 1] = 0;
	//a��° ���� ���ʿ��� a��° ���� �����ϸ� ������������ ���� �� ������ ���� �Ǵ�
	for (int a = 1; a <= N; a++) {
		for (int b = a - 1; b >= 0; b--) {
			if (A[b] < A[a]) {
				temp = dp_left[b] + 1;
				if (temp > dp_left[a])	dp_left[a] = temp;
			}
		}
	}
	//a��° ���� �����ʿ��� a��° ���� �����ϸ� ������������ ���� �� ������ ���� �Ǵ�
	for (int a = N; a >= 1; a--) {
		for (int b = a + 1; b <= N + 1; b++) {
			if (A[b] < A[a]) {
				temp = dp_right[b] + 1;
				if (temp > dp_right[a])	dp_right[a] = temp;
			}
		}
	}
	//������� �κ� ������ ���� �� ���� ���
	for (int a = 1; a <= N; a++) {
		temp = dp_left[a] + dp_right[a] - 1;
		if (temp > answer)	answer = temp;
	}
	cout << answer << endl;
	return 0;
}