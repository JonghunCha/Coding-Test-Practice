/*
���� ��ũ : https://www.acmicpc.net/problem/17406
���� Ž������ �ذ��� �� �ִ� ������.
�־��� ȸ�� ���� ���� K���� ������ �����Ͽ� ��� ��쿡 ���� ����ϰ� ���� ���� ���� ����ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int answer = 100000000;

void Make_Combination(int N, int M, int K, const int arr[51][51], const int K_info[6][3], int combination[6], int step);
void Calculate(int N, int M, int K, const int arr[51][51], const int K_info[6][3], int combination[6]);
void Do_Rotate(int arr[51][51], int r, int c, int s);

int main(void) {
	int N, M, K;
	int arr[51][51], K_info[6][3], combination[6];	//combination�� ȸ�� ������ ���� �����̴�
	//�Է°� ����
	cin >> N; cin >> M; cin >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> K_info[i][0]; cin >> K_info[i][1]; cin >> K_info[i][2];
	}
	//���� ������ -1�� �ʱ�ȭ �� Make_Combination ȣ��
	for (int i = 0; i < K; i++)	combination[i] = -1;
	Make_Combination(N, M, K, arr, K_info, combination, 0);
	cout << answer;

	return 0;
}

void Make_Combination(int N, int M, int K, const int arr[51][51], const int K_info[6][3], int combination[6], int step) {
	//step�� K��� ���� ������ �ϼ� �Ǿ��ٴ� ��
	if (step == K) {
		Calculate(N, M, K, arr, K_info, combination);
	}
	//�̹� �ܰ��� ȸ�� ������ ������ ��� ���� ��ġ�� ������ ���� �� ���� �ܰ� ȣ��
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
	//�迭�� ȸ���ϸ� ���� ���ϴµ� �Է¹��� �迭�� ����ؾ� �ϱ⿡ ���纻�� ����
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			arr_copy[i][j] = arr[i][j];
		}
	}
	//������ K���� ȸ�� ���꿡 ���� ���ʴ�� ȸ��
	for (int i = 0; i < K; i++) {
		Do_Rotate(arr_copy, K_info[combination[i]][0], K_info[combination[i]][1], K_info[combination[i]][2]);
	}
	//ȸ���� �Ϸ�� �迭�� �� ���
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
		//���� ȸ��
		for (int j = c + i; j > c - i; j--) {
			if (j == c + i)	temp_now = arr[r - i][j];
			arr[r - i][j] = arr[r - i][j - 1];
		}
		temp_prev = temp_now;
		//������ ȸ��
		for (int j = r + i; j > r - i; j--) {
			if (j == r - i + 1)	arr[j][c + i] = temp_prev;
			else {
				if (j == r + i)	temp_now = arr[j][c + i];
				arr[j][c + i] = arr[j - 1][c + i];
			}
		}
		temp_prev = temp_now;
		//�Ʒ��� ȸ��
		for (int j = c - i; j < c + i; j++) {
			if (j == c + i - 1)	arr[r + i][j] = temp_prev;
			else {
				if (j == c - i)	temp_now = arr[r + i][j];
				arr[r + i][j] = arr[r + i][j + 1];
			}
		}
		temp_prev = temp_now;
		//���� ȸ��
		for (int j = r - i; j < r + i; j++) {
			if (j == r + i - 1)	arr[j][c - i] = temp_prev;
			else	arr[j][c - i] = arr[j + 1][c - i];
		}
	}
}