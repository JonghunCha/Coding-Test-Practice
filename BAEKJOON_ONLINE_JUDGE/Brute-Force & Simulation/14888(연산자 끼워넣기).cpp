/*
문제 링크 : https://www.acmicpc.net/problem/14888
완전 탐색으로 해결 할 수 있다.

주어진 연산자들을 조합하여 생길 수 있는 모든 수식에 대해서 계산을 수행하고 최댓값 최솟값을 갱신하면 된다.
*/
#include <iostream>
using namespace std;

int Max = -1000000001;
int Min = 1000000001;

void Make_Combination(int N, int A[11], int op[4], int combination[10], int step);
void Calculate(int N, int A[11], int combination[10]);

int main(void) {
	int N, A[11], op[4], combination[10];
	//입력값 저장
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> A[i];
	for (int i = 0; i < 4; i++)	cin >> op[i];
	//모든 조합에 대해 계산 실시
	for (int i = 0; i < N - 1; i++)	combination[i] = -1;
	Make_Combination(N, A, op, combination, 0);
	cout << Max << endl;
	cout << Min << endl;

	return 0;
}

void Make_Combination(int N, int A[11], int op[4], int combination[10], int step) {
	//수식이 완성되면 계산 실시
	if (step == N - 1) {
		Calculate(N, A, combination);
		return;
	}
	//'+'연산자가 남아 있는 경우
	if (op[0] > 0) {
		combination[step] = 0;
		op[0]--;
		Make_Combination(N, A, op, combination, step + 1);
		op[0]++;
		combination[step] = -1;
	}
	//'-'연산자가 남아 있는 경우
	if (op[1] > 0) {
		combination[step] = 1;
		op[1]--;
		Make_Combination(N, A, op, combination, step + 1);
		op[1]++;
		combination[step] = -1;
	}
	//'*'연산자가 남아 있는 경우
	if (op[2] > 0) {
		combination[step] = 2;
		op[2]--;
		Make_Combination(N, A, op, combination, step + 1);
		op[2]++;
		combination[step] = -1;
	}
	//'/'연산자가 남아 있는 경우
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