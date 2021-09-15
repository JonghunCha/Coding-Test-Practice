/*
���� ��ũ : https://www.acmicpc.net/problem/14501
Dynamic Programming���� �ذ��� �� �ִ� ������.

��ü ������ "n������ ����� �����Ѵٰ� ���� �� ���� �� �ִ� �ִ� ����" �̶�� ���� ������ ������. ��ȭ���� �Ʒ��� ����.

answer(i) = max(answer(i+1), answer(i+T[i]) + P[i]))

answer(i)�� i��° �Ϻ��� ����� ������ �� ���� �� �ִ� �ִ� ������ �ǹ��ϰ�, i��° ��¥�� ����� ��� ���� ���� �ʴ� ��쿡�� �� ū ������ �����ϵ��� �Ѵ�.
*/
#include <iostream>
using namespace std;

int N, T[16], P[16], DP[16];

int Get_Answer(int date);

int main(void) {
	//�Է°� ����
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i]; cin >> P[i];
		DP[i] = -1;
	}
	//1������ �����ϴ� ��� �ִ� ������ ���Ѵ�
	cout << Get_Answer(1);
	return 0;
}

int Get_Answer(int date) {
	int ret1, ret2;
	if (date == N + 1)	return 0;
	//����� �Ұ����� ��찡 ���õ��� �ʵ��� ������ -999999�� ��ȯ
	if (date > N + 1)	return -999999;
	if (DP[date] != -1)	return DP[date];
	ret1 = Get_Answer(date + 1);	//date��¥�� ����� ���� �ʴ� ���
	ret2 = Get_Answer(date + T[date]) + P[date];	//date��¥�� ����� �޴� ���
	if (ret1 > ret2) {
		DP[date] = ret1;
		return ret1;
	}
	else {
		DP[date] = ret2;
		return ret2;
	}
}