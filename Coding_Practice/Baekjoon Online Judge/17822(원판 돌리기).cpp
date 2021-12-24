/*
���� ��ũ : https://www.acmicpc.net/problem/17822
�ܼ� ���� �����̴�.

�������� ������ ������ �� ���� ������ �ϸ� Ǯ �� �ִ� �����̴�.
*/
#include <iostream>
using namespace std;

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

void Do_Rotate(int N, int M, int nums[51][51], int x, int d, int k);
void Erase_Nighbor(int N, int M, int nums[51][51]);

int main(void) {
	int N, M, T, nums[51][51], rotate[51][3], answer = 0;
	//�Է°� ����
	cin >> N; cin >> M; cin >> T;
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= M; b++) {
			cin >> nums[a][b];
		}
	}
	for (int a = 1; a <= T; a++) {
		cin >> rotate[a][0];
		cin >> rotate[a][1];
		cin >> rotate[a][2];
	}
	//ȸ�� �ǽ�
	for (int a = 1; a <= T; a++)	Do_Rotate(N, M, nums, rotate[a][0], rotate[a][1], rotate[a][2]);
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= M; b++) {
			answer += nums[a][b];
		}
	}
	cout << answer;

	return 0;
}

void Do_Rotate(int N, int M, int nums[51][51], int x, int d, int k) {
	int temp[51];
	for (int a = 1; a <= N; a++) {
		//x�� ����� ���Ǹ� ȸ��
		if (a % x == 0) {
			//�ð� ����
			if (d == 0) {
				for (int b = 1; b <= M; b++) {
					if (b - k < 1)		temp[b] = nums[a][M + b - k];
					else	temp[b] = nums[a][b - k];
				}
			}
			//�ݽð� ����
			else {
				for (int b = 1; b <= M; b++) {
					if (b + k > M)	temp[b] = nums[a][b + k - M];
					else	temp[b] = nums[a][b + k];
				}
			}
			for (int b = 1; b <= M; b++)	nums[a][b] = temp[b];
		}
	}
	Erase_Nighbor(N, M, nums);
}

void Erase_Nighbor(int N, int M, int nums[51][51]) {
	int target[51][51], i, j;
	double mean, sum, count = 0;
	bool target_exist = false;
	//�����ϸ鼭 ���� �� Ž��
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= M; b++) {
			target[a][b] = 0;
			if (nums[a][b] != 0) {
				for (int c = 0; c < 4; c++) {
					i = a + di[c];
					j = b + dj[c];
					if (j == 0)	j = M;
					else if (j == M + 1)	j = 1;
					if (i >= 1 && i <= N && j >= 1 && j <= M) {
						if (nums[a][b] == nums[i][j]) {
							target[a][b] = 1;
							break;
						}
					}
				}
			}
		}
	}
	//�����ϸ鼭 ���� �� ����
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= M; b++) {
			if (target[a][b] == 1) {
				nums[a][b] = 0;
				target_exist = true;
			}
		}
	}
	//�����ϸ鼭 ���� ���� ���� ��� ��հ� ���ϰ� ��� ���ϱ�
	if (!target_exist) {
		sum = 0;
		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= M; b++) {
				if (nums[a][b] != 0) {
					sum += nums[a][b];
					count++;
				}
			}
		}
		mean = sum / count;
		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= M; b++) {
				if (nums[a][b] > mean && nums[a][b] != 0)	nums[a][b]--;
				else if (nums[a][b] < mean && nums[a][b] != 0)	nums[a][b]++;
			}
		}
	}
}