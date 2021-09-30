/*
���� ��ũ : https://www.acmicpc.net/problem/16234
���� Ž������ �ذ��� �� �ִ� ������.

�� ������ ������ ã�� ���� �ٽ��̴�.

��ü ������ Ž���ϸ� ������ ������ ������ ������ �����̸� ������ �δ´�.

���� ���տ� �߰��� ������ �̿� ���� ���� ���� �����̶�� ���տ� �߰��ϴ� ������� Ž���ϸ� �ȴ�.

���� ��ü�� ����� �ʴ�. �׷��� �ð����⵵�� �� �����ؼ� �����ؾ� ����� �ȴ�.
*/
#include <iostream>
using namespace std;

void check_near(int N, int L, int R, int** map, int** check, int union_index, int x, int y, int union_population[2501], int union_num[2501]);

int main(void) {
	int N, L, R, count = 0, union_index, union_population[2501], union_num[2501];
	//�Է°� ����
	cin >> N; cin >> L; cin >> R;
	int** map = new int* [N];
	int** check = new int* [N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
		check[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	//�α� �̵��� ���������� �ݺ�
	while (1) {
		//check�� �� ������ ���� ��ȣ�� �����ϸ� ó���� 0���� �ʱ�ȭ
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				check[i][j] = 0;
			}
		}
		//union_index�� ������ ��ȣ�� �ǹ�
		union_index = 1;
		//population�� num�� ���� �ش� ������ �α��� ����, ������ ������ �ǹ�
		for (int i = 1; i < 2500; i++) {
			union_population[i] = 0;
			union_num[i] = 0;
		}
		//��ü ������ ���Ǹ� ���� ������ �������� ������ ��� ���ο� �������� �����ϰ� ��ó�� Ž��
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] == 0) {
					check_near(N, L, R, map, check, union_index, i, j, union_population, union_num);
					union_index++;
				}
			}
		}
		//��� ���� ���� �ٸ� �����̶�� ���� �α� �̵��� �Ͼ�� ������ �ǹ�
		if (union_index == N * N + 1)	break;
		//�α� �̵� �ǽ�
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				map[a][b] = union_population[check[a][b]] / union_num[check[a][b]];
			}
		}
		count++;
	}
	cout << count;
	//���� �Ҵ� ����
	for (int i = 0; i < N; i++) {
		delete[]map[i];
		delete[]check[i];
	}
	delete[]map;
	delete[]check;

	return 0;
}

void check_near(int N, int L, int R, int** map, int** check, int union_index, int x, int y, int union_population[2501], int union_num[2501]) {
	int temp;
	check[x][y] = union_index;
	union_population[union_index] += map[x][y];
	union_num[union_index]++;
	//���� ��ġ�� ���� Ȯ��
	if (x != 0) {
		temp = map[x][y] - map[x - 1][y];
		if (((temp >= L && temp <= R) || (temp >= -R && temp <= -L)) && check[x-1][y] == 0) {
			check_near(N, L, R, map, check, union_index, x - 1, y, union_population, union_num);
		}
	}
	//���� ��ġ�� ���� Ȯ��
	if (y != 0) {
		temp = map[x][y] - map[x][y - 1];
		if (((temp >= L && temp <= R) || (temp >= -R && temp <= -L)) && check[x][y - 1] == 0) {
			check_near(N, L, R, map, check, union_index, x, y - 1, union_population, union_num);
		}
	}
	//���� ��ġ�� ���� Ȯ��
	if (x != N - 1) {
		temp = map[x][y] - map[x + 1][y];
		if (((temp >= L && temp <= R) || (temp >= -R && temp <= -L)) && check[x + 1][y] == 0) {
			check_near(N, L, R, map, check, union_index, x + 1, y, union_population, union_num);
		}
	}
	//���� ��ġ�� ���� Ȯ��
	if (y != N - 1) {
		temp = map[x][y] - map[x][y + 1];
		if (((temp >= L && temp <= R) || (temp >= -R && temp <= -L)) && check[x][y + 1] == 0) {
			check_near(N, L, R, map, check, union_index, x, y + 1, union_population, union_num);
		}
	}
}