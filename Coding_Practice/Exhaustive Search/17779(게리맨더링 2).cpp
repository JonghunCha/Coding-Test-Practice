/*
문제 링크 : https://www.acmicpc.net/problem/17779
완전 탐색으로 해결할 수 있는 문제다.

x, y, d1, d2의 조합에 따라 선거구를 나눈 결과가 달라진다.

따라서 조건에 부합하는 x, y, d1, d2의 조합에 따라 선거구를 나누고 인구가 가장 많은 선거구와 가장 적은 선거구의 인구 차이를 비교하면 된다.
*/
#include <iostream>
using namespace std;

int sum[6];
int answer = 1000000;

void Divide_District(int N, int A[21][21], int District[21][21], int x, int y, int d1, int d2);

int main(void) {
	int N, A[21][21], District[21][21], population_Max, population_Min;
	//입력값 저장
	cin >> N;
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			cin >> A[a][b];
		}
	}
	//가능한 x, y, d1, d2조합에 대해 선거구를 나눔
	for (int a = 2; a <= N - 1; a++) {
		for (int b = 2; b <= N - 1; b++) {
			for (int c = 1; c <= N / 2; c++) {
				for (int d = 1; d <= N / 2; d++) {
					if (a + c + d <= N && b - c >= 1 && b + d <= N) {
						population_Max = 0;
						population_Min = 1000000;
						sum[1] = 0;
						sum[2] = 0;
						sum[3] = 0;
						sum[4] = 0;
						sum[5] = 0;
						Divide_District(N, A, District, a, b, c, d);
						for (int e = 1; e <= 5; e++) {
							if (sum[e] > population_Max)	population_Max = sum[e];
							if (sum[e] < population_Min)	population_Min = sum[e];
						}
						if (population_Max - population_Min < answer)	answer = population_Max - population_Min;
					}
				}
			}
		}
	}
	cout << answer;
	return 0;
}

void Divide_District(int N, int A[21][21], int District[21][21], int x, int y, int d1, int d2) {
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			District[a][b] = 0;
		}
	}
	//5번 선거구
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			if (b - a <= y - x && a + b >= x + y && a - b <= x - y + 2 * d1 && a + b <= x + y + 2 * d2) {
				District[a][b] = 5;
				sum[5] += A[a][b];
			}
		}
	}
	//나머지 선거구
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			if (a < x + d1 && b <= y && District[a][b] == 0) {
				District[a][b] = 1;
				sum[1] += A[a][b];
			}
			else if (a <= x + d2 && b >= y && District[a][b] == 0) {
				District[a][b] = 2;
				sum[2] += A[a][b];
			}
			else if (a >= x + d1 && b < y - d1 + d2 && District[a][b] == 0) {
				District[a][b] = 3;
				sum[3] += A[a][b];
			}
			else if (a > x + d2 && b >= y - d1 + d2 && District[a][b] == 0) {
				District[a][b] = 4;
				sum[4] += A[a][b];
			}
		}
	}
}