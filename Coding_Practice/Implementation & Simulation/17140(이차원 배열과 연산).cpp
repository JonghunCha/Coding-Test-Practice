/*
문제 링크 : https://www.acmicpc.net/problem/17140
단순 구현 문제이나, 정렬을 해야 한다.

정렬에는 2가지 기준이 있는데 먼저 수의 등장 횟수가 커지는 대로 정렬을 하되, 등장 횟수가 똑같다면 수가 커지는 순으로 정렬해야 한다.

이 문제에서 나올 수 있는 수의 최댓값은 100이다.

따라서 num_count[101]이라는 변수에 각 수의 등장 횟수를 저장한 뒤 위의 정렬 규칙을 지키도록 배열 연산을 하면 된다.
*/
#include <iostream>
using namespace std;

int main(void) {
	int R, C, K, A[101][101], answer = 0, num_count[101], row_num = 3, col_num = 3, index, temp;
	//입력값 저장
	for (int a = 0; a < 101; a++) {
		for (int b = 0; b < 101; b++) {
			A[a][b] = 0;
		}
	}
	cin >> R; cin >> C; cin >> K;
	for (int a = 1; a <= 3; a++) {
		for (int b = 1; b <= 3; b++) {
			cin >> A[a][b];
		}
	}
	//최대 100초까지 반복
	while (answer <= 100) {
		if (A[R][C] == K)	break;
		//행의 수가 열의 수보다 많은 경우
		if (row_num >= col_num) {
			for (int a = 1; a <= row_num; a++) {
				//각 수의 등장 횟수를 저장
				memset(num_count, 0, 101);
				for (int b = 1; b <= col_num; b++) {
					if (A[a][b] != 0)	num_count[A[a][b]]++;
				}
				for (int b = 1; b < 101; b++)	A[a][b] = 0;
				index = 1;
				//1부터 100까지 살핀다
				for (int b = 1; b < 101; b++) {
					//최대 100개의 행과 열 유지
					if (index > 100)	break;
					for (int c = 1; c < 101; c++) {
						if (index > 100)	break;
						if (num_count[c] == b) {
							A[a][index++] = c;
							A[a][index++] = num_count[c];
						}
					}
				}
			}
			//col_num 갱신
			for (int a = 1; a <= row_num; a++) {
				temp = 0;
				for (int b = 1; b < 101; b++) {
					if (A[a][b] == 0)	break;
					temp++;
				}
				if (temp > col_num)	col_num = temp;
			}
		}
		//열의 수가 행의 수보다 많은 경우
		else {
			for (int a = 1; a <= col_num; a++) {
				memset(num_count, 0, 101);
				for (int b = 1; b <= row_num; b++) {
					if (A[b][a] != 0)	num_count[A[b][a]]++;
				}
				for (int b = 1; b < 101; b++)	A[b][a] = 0;
				index = 1;
				for (int b = 1; b < 101; b++) {
					if (index > 100)	break;
					for (int c = 1; c < 101; c++) {
						if (index > 100)	break;
						if (num_count[c] == b) {
							A[index++][a] = c;
							A[index++][a] = num_count[c];
						}
					}
				}
			}
			for (int a = 1; a <= col_num; a++) {
				temp = 0;
				for (int b = 1; b < 101; b++) {
					if (A[b][a] == 0)	break;
					temp++;
				}
				if (temp > row_num)	row_num = temp;
			}
		}
		answer++;
	}

	if (answer > 100)	cout << -1;
	else	cout << answer;

	return 0;
}