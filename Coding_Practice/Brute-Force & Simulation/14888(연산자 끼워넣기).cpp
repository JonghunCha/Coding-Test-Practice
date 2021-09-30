/*
���� ��ũ : https://www.acmicpc.net/problem/14888
���� Ž������ �ذ� �� �� �ִ�.

�־��� �����ڵ��� �����Ͽ� ���� �� �ִ� ��� ���Ŀ� ���ؼ� ����� �����ϰ� �ִ� �ּڰ��� �����ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int Max = -1000000001;
int Min = 1000000001;

void Make_Combination(int N, int A[11], int op[4], int combination[10], int step);
void Calculate(int N, int A[11], int combination[10]);

int main(void) {
	int N, A[11], op[4], combination[10];
	//�Է°� ����
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> A[i];
	for (int i = 0; i < 4; i++)	cin >> op[i];
	//��� ���տ� ���� ��� �ǽ�
	for (int i = 0; i < N - 1; i++)	combination[i] = -1;
	Make_Combination(N, A, op, combination, 0);
	cout << Max << endl;
	cout << Min << endl;

	return 0;
}

void Make_Combination(int N, int A[11], int op[4], int combination[10], int step) {
	//������ �ϼ��Ǹ� ��� �ǽ�
	if (step == N - 1) {
		Calculate(N, A, combination);
		return;
	}
	//'+'�����ڰ� ���� �ִ� ���
	if (op[0] > 0) {
		combination[step] = 0;
		op[0]--;
		Make_Combination(N, A, op, combination, step + 1);
		op[0]++;
		combination[step] = -1;
	}
	//'-'�����ڰ� ���� �ִ� ���
	if (op[1] > 0) {
		combination[step] = 1;
		op[1]--;
		Make_Combination(N, A, op, combination, step + 1);
		op[1]++;
		combination[step] = -1;
	}
	//'*'�����ڰ� ���� �ִ� ���
	if (op[2] > 0) {
		combination[step] = 2;
		op[2]--;
		Make_Combination(N, A, op, combination, step + 1);
		op[2]++;
		combination[step] = -1;
	}
	//'/'�����ڰ� ���� �ִ� ���
	if (op[3] > 0) {
		combination[step] = 3;
		op[3]--;
		Make_Combination(N, A, op, combination, step + 1);
		op[3]++;
		combination[step] = -1;
	}
}

void Calculate(int N, int A[11], int combination[10]) {
	int answer = A[0];
	for (int i = 0; i < N - 1; i++) {
		if (combination[i] == 0)	answer = answer + A[i + 1];
		else if (combination[i] == 1)	answer = answer - A[i + 1];
		else if (combination[i] == 2)	answer = answer * A[i + 1];
		else	answer = answer / A[i + 1];
	}
	if (answer > Max)	Max = answer;
	if (answer < Min)	Min = answer;
}