/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���� Ž�� ������.

��ǰ ó���ϴ� ���� ������ �ϳ��� �ø��� ������ ��� ��쿡 ���� ǰ�� ����� �ϴ��� �˻��Ѵ�.

���� �˻� ������ ����ϴ� ��찡 ������ �� �κ��� �����ϰ� ������ ����ϸ� �ȴ�.
*/
#include <cstdio>
#include <cstring>
using namespace std;

bool is_end;

void make_combination(int D, int W, int K, int info[13][20], int change[13][2], int index, int change_num, int curr_change_num);
bool is_pass(int D, int W, int K, int info[13][20], int change[13][2]);

int main(void) {
	int T, D, W, K, info[13][20], change[13][2];

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		//�Է°� ���� �� ���� �ʱ�ȭ
		scanf("%d %d %d", &D, &W, &K);
		for (int a = 0; a < D; a++) {
			for (int b = 0; b < W; b++) {
				scanf("%d", &info[a][b]);
			}
		}
		is_end = false;
		//������ ��� ��쿡 ���� Ž��(��ǰ ó���� �ּҷ� ����ϴ� �ͺ��� �ִ�� ����ϴ� ���� ������ Ž��)
		for (int a = 0; a <= D; a++) {
			memset(change, 0, sizeof(int) * 26);
			make_combination(D, W, K, info, change, 0, a, 0);
			if (is_end) {
				printf("#%d %d\n", test_case, a);
				break;
			}
		}
	}

	return 0;
}

void make_combination(int D, int W, int K, int info[13][20], int change[13][2], int index, int change_num, int curr_change_num) {
	if (is_end)	return;
	if (change_num == curr_change_num || index == D) {
		if (curr_change_num != change_num)	return;
		else {
			if(is_pass(D, W, K, info, change))	is_end = true;
		}
		return;
	}

	//index��° ���� ��ǰ ó���� �ϸ� 0���� �����ϴ� ���
	change[index][0] = 1;
	change[index][1] = 0;
	make_combination(D, W, K, info, change, index + 1, change_num, curr_change_num + 1);
	//index��° ���� ��ǰ ó���� �ϸ� 1���� �����ϴ� ���
	change[index][1] = 1;
	make_combination(D, W, K, info, change, index + 1, change_num, curr_change_num + 1);
	//index��° ���� ��ǰ ó���� ���� �ʴ� ���
	change[index][0] = 0;
	change[index][1] = 0;
	make_combination(D, W, K, info, change, index + 1, change_num, curr_change_num);
}

bool is_pass(int D, int W, int K, int info[13][20], int change[13][2]) {
	int info_copy[13][20], curr_character, count;
	bool possible;

	//info_copy�� ���� info���� ����
	for (int a = 0; a < D; a++) {
		for (int b = 0; b < W; b++) {
			info_copy[a][b] = info[a][b];
		}
	}
	//��ǰ ����
	for (int a = 0; a < D; a++) {
		if (change[a][0] == 1) {
			for (int b = 0; b < W; b++) {
				info_copy[a][b] = change[a][1];
			}
		}
	}
	//�� ���� ���� passȮ��
	for (int a = 0; a < W; a++) {
		curr_character = info_copy[0][a];
		count = 1;
		possible = false;
		if (count >= K)	continue;
		for (int b = 1; b < D; b++) {
			if (info_copy[b][a] == curr_character)	count++;
			else {
				curr_character = info_copy[b][a];
				count = 1;
			}

			if (count >= K) {
				possible = true;
				break;
			}
		}
		//���� ������� ���ϴ� ���� �ִٸ� �ٷ� false ��ȯ
		if (!possible)	return false;
	}
	return true;
}