/*
문제 링크 : https://swexpertacademy.com/main/main.do
간단한 구현 문제인데 코드가 길어지다보니 아무것도 아닌데서 실수해서 57분정도 걸린 문제.

코드 길어질 때 집중해서 놓치는 부분 없도록 집중.
*/
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int dx[5] = { 0, 0, 1, 0, -1 };
int dy[5] = { 0, -1, 0, 1, 0 };

int main(int argc, char** argv)
{
	int T, M, A, move1[100], move2[100], BC_info[8][4], x1, y1, x2, y2, answer, max1, max2, temp, num1, num2;
	bool can_charge1[8], can_charge2[8], check;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장
		scanf("%d %d", &M, &A);
		for (int a = 0; a < M; a++) {
			scanf("%d", &move1[a]);
		}
		for (int a = 0; a < M; a++) {
			scanf("%d", &move2[a]);
		}
		for (int a = 0; a < A; a++) {
			scanf("%d %d %d %d", &BC_info[a][0], &BC_info[a][1], &BC_info[a][2], &BC_info[a][3]);
		}

		answer = 0;
		//초기 상태의 값 계산
		x1 = 1;
		y1 = 1;
		x2 = 10;
		y2 = 10;
		max1 = 0;
		num1 = 0;
		num2 = 0;
		memset(can_charge1, false, sizeof(bool) * 8);
		memset(can_charge2, false, sizeof(bool) * 8);
		for (int a = 0; a < A; a++) {
			if (abs(BC_info[a][0] - x1) + abs(BC_info[a][1] - y1) <= BC_info[a][2]) {
				can_charge1[a] = true;
				num1++;
			}
			if (abs(BC_info[a][0] - x2) + abs(BC_info[a][1] - y2) <= BC_info[a][2]) {
				can_charge2[a] = true;
				num2++;
			}
		}

		if (num1 == 0) {
			for (int a = 0; a < A; a++) {
				if (can_charge2[a] && BC_info[a][3] > max1)	max1 = BC_info[a][3];
			}
		}
		else if (num2 == 0) {
			for (int a = 0; a < A; a++) {
				if (can_charge1[a] && BC_info[a][3] > max1)	max1 = BC_info[a][3];
			}
		}
		else {
			for (int a = 0; a < A; a++) {
				if (can_charge1[a]) {
					max2 = 0;
					temp = BC_info[a][3];
					check = false;
					if (can_charge2[a]) {
						can_charge2[a] = false;
						check = true;
					}
					for (int b = 0; b < A; b++) {
						if (can_charge2[b] && BC_info[b][3] > max2)	max2 = BC_info[b][3];
					}
					if (temp + max2 > max1)	max1 = temp + max2;

					can_charge2[a] = check;
				}
			}
		}
		answer += max1;
		//각 위치에서 최대 충전량 계산
		for (int a = 0; a < M; a++) {
			x1 = x1 + dx[move1[a]];
			y1 = y1 + dy[move1[a]];
			x2 = x2 + dx[move2[a]];
			y2 = y2 + dy[move2[a]];
			max1 = 0;
			num1 = 0;
			num2 = 0;
			memset(can_charge1, false, sizeof(bool) * 8);
			memset(can_charge2, false, sizeof(bool) * 8);
			for (int a = 0; a < A; a++) {
				if (abs(BC_info[a][0] - x1) + abs(BC_info[a][1] - y1) <= BC_info[a][2]) {
					can_charge1[a] = true;
					num1++;
				}
				if (abs(BC_info[a][0] - x2) + abs(BC_info[a][1] - y2) <= BC_info[a][2]) {
					can_charge2[a] = true;
					num2++;
				}
			}

			if (num1 == 0) {
				for (int a = 0; a < A; a++) {
					if (can_charge2[a] && BC_info[a][3] > max1)	max1 = BC_info[a][3];
				}
			}
			else if (num2 == 0) {
				for (int a = 0; a < A; a++) {
					if (can_charge1[a] && BC_info[a][3] > max1)	max1 = BC_info[a][3];
				}
			}
			else {
				for (int a = 0; a < A; a++) {
					if (can_charge1[a]) {
						max2 = 0;
						temp = BC_info[a][3];
						check = false;
						if (can_charge2[a]) {
							can_charge2[a] = false;
							check = true;
						}
						for (int b = 0; b < A; b++) {
							if (can_charge2[b] && BC_info[b][3] > max2)	max2 = BC_info[b][3];
						}
						if (temp + max2 > max1)	max1 = temp + max2;

						can_charge2[a] = check;
					}
				}
			}
			answer += max1;
		}

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}