/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�ܼ� ���� ������.

���� ���ǿ� ���� ������ �Ѵٸ� ���� �ذ��� �� �ֱ⿡ ���ٸ� ������ ���� �ʴ´�.
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
		//�Է°� ���� �� ���� �ʱ�ȭ
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
			if (rotate[a][0] == 1) {	//1�� ��ϸ� ȸ���ϴ� ���
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
			else if (rotate[a][0] == 2) {	//2�� ��ϸ� ȸ���ϴ� ���
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
			else if (rotate[a][0] == 3) {	//3�� ��ϸ� ȸ���ϴ� ���
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
			else {	//4�� ��ϸ� ȸ���ϴ� ���
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
//index��° ��ϸ� ȸ���Ͽ� ���� ���� �ִ� �κ��� ��ġ ����
void rotation(int head[5], int index, int direction) {
	if (direction == 1)	head[index] = (head[index] + 7) % 8;
	else	head[index] = (head[index] + 1) % 8;
}