/*
문제 링크 : https://www.acmicpc.net/problem/17406
완전 탐색으로 해결할 수 있는 문제다.
주어진 회전 연산 정보 K개의 순서를 조합하여 모든 경우에 대해 계산하고 가장 작은 값을 출력하면 된다.
*/
#include <iostream>
using namespace std;

int answer = 100000000;

void Make_Combination(int N, int M, int K, const int arr[51][51], const int K_info[6][3], int combination[6], int step);
void Calculate(int N, int M, int K, const int arr[51][51], const int K_info[6][3], int combination[6]);
void Do_Rotate(int arr[51][51], int r, int c, int s);

int main(void) {
	int N, M, K;
	int arr[51][51], K_info[6][3], combination[6];	//combination은 회전 연산의 순서 조합이다
	//입력값 저장
	cin >> N; cin >> M; cin >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> K_info[i][0]; cin >> K_info[i][1]; cin >> K_info[i][2];
	}
	//순서 조합을 -1로 초기화 후 Make_Combination 호출
	for (int i = 0; i < K; i++)	combination[i] = -1;
	Make_Combination(N, M, K, arr, K_info, combination, 0);
	cout << answer;

	return 0;
}

void Make_Combination(int N, int M, int K, const int arr[51][51], const int K_info[6][3], int combination[6], int step) {
	//step이 K라는 것은 조합이 완성 되었다는 것
	if (step == K) {
		Calculate(N, M, K, arr, K_info, combination);
	}
	//이번 단계의 회전 연산이 조합의 어느 곳에 위치할 것인지 결정 후 다음 단계 호출
	else {
		for (int i = 0; i < K; i++) {
			if (combination[i] == -1) {
				combination[i] = step;
				Make_Combination(N, M, K, arr, K_info, combination, step + 1);
				combination[i] = -1;
			}
		}
	}
}

void Calculate(int N, int M, int K, const int arr[51][51], const int K_info[6][3], int combination[6]) {
	int arr_copy[51][51], min = 100000000, sum;
	//배열이 회전하면 값이 변하는데 입력받은 배열은 기억해야 하기에 복사본을 생성
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			arr_copy[i][j] = arr[i][j];
		}
	}
	//정해진 K개의 회전 연산에 대해 차례대로 회전
	for (int i = 0; i < K; i++) {
		Do_Rotate(arr_copy, K_info[combination[i]][0], K_info[combination[i]][1], K_info[combination[i]][2]);
	}
	//회전이 완료된 배열의 값 계산
	for (int i = 1; i <= N; i++) {
		sum = 0;
		for (int j = 1; j <= M; j++) {
			sum += arr_copy[i][j];
		}
		if (sum < min)	min = sum;
	}

	if (answer > min)	answer = min;
}

void Do_Rotate(int arr[51][51], int r, int c, int s) {
	int temp_prev, temp_now;
	for (int i = 1; i <= s; i++) {
		temp_prev = -1;
		temp_now = -1;
		//윗쪽 회전
		for (int j = c + i; j > c - i; j--) {
			if (j == c + i)	temp_now = arr[r - i][j];
			arr[r - i][j] = arr[r - i][j - 1];
		}
		temp_prev = temp_now;
		//오른쪽 회전
		for (int j = r + i; j > r - i; j--) {
			if (j == r - i + 1)	arr[j][c + i] = temp_prev;
			else {
				if (j == r + i)	temp_now = arr[j][c + i];
				arr[j][c + i] = arr[j - 1][c + i];
			}
		}
		temp_prev = temp_now;
		//아래쪽 회전
		for (int j = c - i; j < c + i; j++) {
			if (j == c + i - 1)	arr[r + i][j] = temp_prev;
			else {
				if (j == c - i)	temp_now = arr[r + i][j];
				arr[r + i][j] = arr[r + i][j + 1];
			}
		}
		temp_prev = temp_now;
		//왼쪽 회전
		for (int j = r - i; j < r + i; j++) {
			if (j == r + i - 1)	arr[j][c - i] = temp_prev;
			else	arr[j][c - i] = arr[j + 1][c - i];
		}
	}
}