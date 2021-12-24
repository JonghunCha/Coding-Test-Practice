/*
���� ��ũ : https://www.acmicpc.net/problem/15954
īī�� �ڵ� �佺Ƽ�� 2018 ������ ���� �����̴�.

���а� ����Ž���� ȥ�յ� ������ ���ǿ� �´� ��� ��쿡 ���� ǥ�������� ����غ��� �ȴ�.

���а��� �Լ����� ����� �� �ƴ����� ���� ������� �����Ѵ�.
*/
#include <iostream>
#include <math.h>
using namespace std;

double Calculate_K_Dolls(long long doll[500], int start, int len);

int main(void) {
	int N, K, min_index, min_len;
	long long doll[500];
	double min = 1000000000000000, temp = 0;
	//�Է°� ����
	cin >> N >> K;
	for (int a = 0; a < N; a++)	cin >> doll[a];
	//������ ��� ���ǿ� ���� ǥ�������� ����
	for (int a = 0; a <= N - K; a++) {
		for (int b = 0; b <= N - K; b++) {
			if (a + b + K <= N && (temp = Calculate_K_Dolls(doll, a, K + b)) < min)	min = temp;
		}
	}
	cout<<fixed;
	cout.precision(11);
	cout << min;

	return 0;
}

double Calculate_K_Dolls(long long doll[500], int start, int len) {
	double sum = 0, mean, ret = 0;
	//a������ len���� ��ŭ�� ��ȣ�� �� ���
	for (int a = start; a < start + len; a++) {
		sum += (double)doll[a];
	}
	//��ȣ���� ��� ���
	mean = sum / len;
	//�л� ���
	for (int a = start; a < start + len; a++) {
		ret += ((double)doll[a] - mean) * ((double)doll[a] - mean);
	}
	ret /= len;
	//ǥ������ ��ȯ
	return sqrt(ret);
}