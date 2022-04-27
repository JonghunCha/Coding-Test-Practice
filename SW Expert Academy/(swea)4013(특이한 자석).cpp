/*
문제 링크 : https://swexpertacademy.com/main/main.do
단순 구현 문제다.

문제 조건에 따라 구현만 한다면 쉽게 해결할 수 있기에 별다른 설명은 하지 않는다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

void rotation(int head[5], int index, int direction);

int main(int argc, char** argv)
{
	int T, K, info[5][8], head[5], rotate[20][2], answer;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 변수 초기화
		scanf("%d", &K);
		for (int a = 1; a <= 4; a++) {
			for (int b = 0; b < 8; b++) {
				scanf("%d", &info[a][b]);
			}
		}
		for (int a = 0; a < K; a++) {
			scanf("%d %d", &rotate[a][0], &rotate[a][1]);
		}

		memset(head, 0, sizeof(int) * 5);
		for (int a = 0; a < K; a++) {
			if (rotate[a][0] == 1) {	//1번 톱니를 회전하는 경우
				if (info[1][(head[1] + 2) % 8] != info[2][(head[2] + 6) % 8]) {
					if (info[2][(head[2] + 2) % 8] != info[3][(head[3] + 6) % 8]) {
						if (info[3][(head[3] + 2) % 8] != info[4][(head[4] + 6) % 8]) {
							rotation(head, 4, -rotate[a][1]);
						}
						rotation(head, 3, rotate[a][1]);
					}
					rotation(head, 2, -rotate[a][1]);
				}
				rotation(head, 1, rotate[a][1]);
			}
			else if (rotate[a][0] == 2) {	//2번 톱니를 회전하는 경우
				if (info[1][(head[1] + 2) % 8] != info[2][(head[2] + 6) % 8]) {
					rotation(head, 1, -rotate[a][1]);
				}
				if (info[2][(head[2] + 2) % 8] != info[3][(head[3] + 6) % 8]) {
					if (info[3][(head[3] + 2) % 8] != info[4][(head[4] + 6) % 8]) {
						rotation(head, 4, rotate[a][1]);
					}
					rotation(head, 3, -rotate[a][1]);
				}
				rotation(head, 2, rotate[a][1]);
			}
			else if (rotate[a][0] == 3) {	//3번 톱니를 회전하는 경우
				if (info[2][(head[2] + 2) % 8] != info[3][(head[3] + 6) % 8]) {
					if (info[1][(head[1] + 2) % 8] != info[2][(head[2] + 6) % 8]) {
						rotation(head, 1, rotate[a][1]);
					}
					rotation(head, 2, -rotate[a][1]);
				}
				if (info[3][(head[3] + 2) % 8] != info[4][(head[4] + 6) % 8]) {
					rotation(head, 4, -rotate[a][1]);
				}
				rotation(head, 3, rotate[a][1]);
			}
			else {	//4번 톱니를 회전하는 경우
				if (info[3][(head[3] + 2) % 8] != info[4][(head[4] + 6) % 8]) {
					if (info[2][(head[2] + 2) % 8] != info[3][(head[3] + 6) % 8]) {
						if (info[1][(head[1] + 2) % 8] != info[2][(head[2] + 6) % 8]) {
							rotation(head, 1, -rotate[a][1]);
						}
						rotation(head, 2, rotate[a][1]);
					}
					rotation(head, 3, -rotate[a][1]);
				}
				rotation(head, 4, rotate[a][1]);
			}
		}

		answer = 0;

		if (info[1][head[1]] == 1)	answer += 1;
		if (info[2][head[2]] == 1)	answer += 2;
		if (info[3][head[3]] == 1)	answer += 4;
		if (info[4][head[4]] == 1)	answer += 8;

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}
//index번째 톱니를 회전하여 가장 위에 있는 부분의 위치 갱신
void rotation(int head[5], int index, int direction) {
	if (direction == 1)	head[index] = (head[index] + 7) % 8;
	else	head[index] = (head[index] + 1) % 8;
}