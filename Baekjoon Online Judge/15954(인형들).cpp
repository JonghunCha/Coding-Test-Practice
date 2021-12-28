/*
문제 링크 : https://www.acmicpc.net/problem/15954
카카오 코드 페스티벌 2018 예선에 나온 문제이다.

수학과 완전탐색이 혼합된 문제로 조건에 맞는 모든 경우에 대해 표준편차를 계산해보면 된다.

수학관련 함수들을 사용할 줄 아는지를 묻는 문제라고 생각한다.
*/
#include <iostream>
#include <math.h>
using namespace std;

double Calculate_K_Dolls(long long doll[500], int start, int len);

int main(void) {
	int N, K, min_index, min_len;
	long long doll[500];
	double min = 1000000000000000, temp = 0;
	//입력값 저장
	cin >> N >> K;
	for (int a = 0; a < N; a++)	cin >> doll[a];
	//가능한 모든 조건에 대해 표준편차를 구함
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
	//a번부터 len길이 만큼의 선호도 합 계산
	for (int a = start; a < start + len; a++) {
		sum += (double)doll[a];
	}
	//선호도의 평균 계산
	mean = sum / len;
	//분산 계산
	for (int a = start; a < start + len; a++) {
		ret += ((double)doll[a] - mean) * ((double)doll[a] - mean);
	}
	ret /= len;
	//표준편차 반환
	return sqrt(ret);
}