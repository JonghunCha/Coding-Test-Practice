/*
문제 링크 : https://www.acmicpc.net/problem/20055
단순 구현 문제다.

컨베이어의 각 칸을 배열에 저장한 뒤 올리는 위치와 내리는 위치 정보를 업데이트 하며 문제에서 주어진 조건을 구현하면 된다.
*/
#include <iostream>
using namespace std;

int main(void) {
	//A[n][0]은 n번 칸의 내구도, A[n][1]은 로봇이 있을 때 1, 없을 때 0을 저장
	int N, K, A[201][2], start, end, count = 0, zero_count = 0, cur, next;
	//입력값 저장
	cin >> N; cin >> K;
	for (int a = 1; a <= 2 * N; a++) {
		cin >> A[a][0];
		A[a][1] = 0;
	}
	//start는 올리는 위치, end는 내리는 위치의 번호
	start = 1;
	end = N;

	while (1) {
		count++;
		//1단계
		A[end][1] = 0;
		start--;
		end--;
		if (start < 1)	start = 2 * N;
		if (end < 1)	end = 2 * N;
		A[end][1] = 0;
		//2단계
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
		//3단계
		if (A[start][0] > 0) {
			A[start][0]--;
			if (A[start][0] == 0)	zero_count++;
			A[start][1] = 1;
		}
		//4단계
		if (zero_count >= K)	break;
	}
	cout << count;

	return 0;
}