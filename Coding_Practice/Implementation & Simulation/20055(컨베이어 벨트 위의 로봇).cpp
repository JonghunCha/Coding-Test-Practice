/*
���� ��ũ : https://www.acmicpc.net/problem/20055
�ܼ� ���� ������.

�����̾��� �� ĭ�� �迭�� ������ �� �ø��� ��ġ�� ������ ��ġ ������ ������Ʈ �ϸ� �������� �־��� ������ �����ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int main(void) {
	//A[n][0]�� n�� ĭ�� ������, A[n][1]�� �κ��� ���� �� 1, ���� �� 0�� ����
	int N, K, A[201][2], start, end, count = 0, zero_count = 0, cur, next;
	//�Է°� ����
	cin >> N; cin >> K;
	for (int a = 1; a <= 2 * N; a++) {
		cin >> A[a][0];
		A[a][1] = 0;
	}
	//start�� �ø��� ��ġ, end�� ������ ��ġ�� ��ȣ
	start = 1;
	end = N;

	while (1) {
		count++;
		//1�ܰ�
		A[end][1] = 0;
		start--;
		end--;
		if (start < 1)	start = 2 * N;
		if (end < 1)	end = 2 * N;
		A[end][1] = 0;
		//2�ܰ�
		cur = end;
		while (cur != start) {
			if (A[cur][1] == 1) {
				next = cur + 1;
				if (next > 2 * N)	next = 1;
				if (A[next][0] > 0 && A[next][1] == 0) {
					A[cur][1] = 0;
					A[next][1] = 1;
					A[next][0]--;
					if (A[next][0] == 0)	zero_count++;
				}
			}
			if (cur == 1)	cur = 2 * N;
			else	cur--;
		}
		//3�ܰ�
		if (A[start][0] > 0) {
			A[start][0]--;
			if (A[start][0] == 0)	zero_count++;
			A[start][1] = 1;
		}
		//4�ܰ�
		if (zero_count >= K)	break;
	}
	cout << count;

	return 0;
}