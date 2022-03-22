/*
���� ��ũ : https://www.acmicpc.net/problem/23291
Ư���� �˰����� �ʿ������� ������ �����ϴµ� �ð��� �� �ɸ� ������. 

�ܼ� ���� ������ �� �ٸ� ������ ������ �̷��� ������ ������ ����� ������ �� ���⼺�� Ȯ���ϰ� ��� ���� �ð��ȿ� Ǯ �� ���� ���̴�.

�ش� ������ �ٸ� ������� �ٸ��� x�� ����, y�� ���η� �����Ͽ���
*/
#include <cstdio>
#include <cstring>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void step1(int N, int fish[100][100]);
void step2(int N, int fish[100][100]);
void move_fish(int fish[100][100]);
bool check_end(int N, int K, int fish[100][100]);

int main(void) {
	int N, K, fish[100][100], answer = 0;
	//�Է°� ���� �� ���� �ʱ�ȭ
	scanf("%d %d", &N, &K);
	memset(fish, -1, sizeof(int) * 10000);
	for (int a = 0; a < N; a++) {
		scanf("%d", &fish[99][a]);
	}
	//������ ������ ������ ������ ���� �ݺ�
	while (!check_end(N, K, fish)) {
		answer++;
		step1(N, fish);
		step2(N, fish);
	}

	printf("%d\n", answer);

	return 0;
}
//ù ��° ������ ����� ���� ����
void step1(int N, int fish[100][100]) {
	int xlen = 1, ylen = 1, curr_x = 0, min_val = 10000, nx, ny;

	//1.����Ⱑ ���� ���� ���׿� ����� �߰�
	for (int a = 0; a < N; a++) {
		if (fish[99][a] < min_val)	min_val = fish[99][a];
	}
	for (int a = 0; a < N; a++) {
		if (fish[99][a] == min_val)	fish[99][a]++;
	}

	//2.step1�� ���� �ױ�
	while (xlen + ylen + curr_x <= N) {
		for (int a = 0; a < ylen; a++) {
			for (int b = 0; b < xlen; b++) {
				ny = 99 - xlen + b;
				nx = curr_x + xlen + a;
				fish[ny][nx] = fish[99 - a][curr_x + b];
				fish[99 - a][curr_x + b] = -1;
			}
		}

		curr_x += xlen;
		if (xlen == ylen)	ylen++;
		else	xlen++;
	}

	//3.����� �� ����
	move_fish(fish);

	//4.���� ��ġ��
	curr_x = 0;

	for (int a = 0; a < 100; a++) {
		for (int b = 99; b >= 0; b--) {
			if (fish[b][a] != -1) {
				fish[99][curr_x++] = fish[b][a];
				if(b != 99)	fish[b][a] = -1;
			}
		}
	}
}
//�� ��° ������ ����� ���� ����
void step2(int N, int fish[100][100]) {
	int xlen = N / 2, ylen = 1, curr_x = 0, nx, ny;

	//1.step2�� ���� �ױ�
	for(int time = 0; time < 2; time++){
		for (int a = 0; a < ylen; a++) {
			for (int b = 0; b < xlen; b++) {
				ny = 99 - (2 * ylen) + a + 1;
				nx = curr_x + (2 * xlen) - b - 1;
				fish[ny][nx] = fish[99 - a][curr_x + b];
				fish[99 - a][curr_x + b] = -1;
			}
		}

		curr_x += xlen;
		xlen = xlen / 2;
		ylen = ylen * 2;
	}

	//2.����� �� ����
	move_fish(fish);

	//3.���� ��ġ��
	curr_x = 0;

	for (int a = 0; a < 100; a++) {
		for (int b = 99; b >= 0; b--) {
			if (fish[b][a] != -1) {
				fish[99][curr_x++] = fish[b][a];
				if (b != 99)	fish[b][a] = -1;
			}
		}
	}
}
//����� ����
void move_fish(int fish[100][100]) {
	int move_num[100][100], nx, ny;
	memset(move_num, 0, sizeof(int) * 10000);

	for (int a = 0; a < 100; a++) {
		for (int b = 0; b < 100; b++) {
			if (fish[a][b] != -1) {
				for (int c = 0; c < 4; c++) {
					ny = a + dy[c];
					nx = b + dx[c];
					if (nx >= 0 && nx < 100 && ny >= 0 && ny < 100 && fish[ny][nx] != -1 && fish[ny][nx] < fish[a][b]) {
						move_num[ny][nx] += (fish[a][b] - fish[ny][nx]) / 5;
						move_num[a][b] -= (fish[a][b] - fish[ny][nx]) / 5;
					}
				}
			}
		}
	}

	for (int a = 0; a < 100; a++) {
		for (int b = 0; b < 100; b++) {
			fish[a][b] += move_num[a][b];
		}
	}
}
//������ ������ �����ϴ��� Ȯ��
bool check_end(int N, int K, int fish[100][100]) {
	int max_num = 0, min_num = 10000;

	for (int a = 0; a < N; a++) {
		if (fish[99][a] > max_num)	max_num = fish[99][a];
		if (fish[99][a] < min_num)	min_num = fish[99][a];
	}

	if (max_num - min_num <= K)	return true;
	else	return false;
}