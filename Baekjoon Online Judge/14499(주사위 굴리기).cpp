/*
���� ��ũ : https://www.acmicpc.net/problem/14499
���ٸ� ������ �ʿ� ���� �ܼ� ����������.
*/
#include <iostream>
using namespace std;

int main(void) {
	int N, M, x, y, K, map[20][20], commands[1000], dice[7], temp;
	//�Է°� ����
	cin >> N; cin >> M; cin >> x; cin >> y; cin >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++)	cin >> commands[i];
	//�ֻ��� 0���� �ʱ�ȭ(dice�� index�� ���� 1 = ��, 2 = ��, 3 = ��, 4 = ��, 5 = ��, 6 = �Ʒ����� �ǹ�)
	for (int i = 1; i < 7; i++)	dice[i] = 0;
	for (int i = 0; i < K; i++) {
		//�������� ������ ���
		if (commands[i] == 1) {
			//������ ������ �����ϰ� ���� command ����
			if (y == M - 1)	continue;
			//�ٴ��� 0�� �ƴ� ���
			if (map[x][y + 1] != 0) {
				temp = dice[1];
				dice[1] = dice[4];
				dice[3] = temp;
				dice[4] = dice[6];
				dice[6] = map[x][y + 1];
				map[x][++y] = 0;
			}
			//�ٴ��� 0�� ���
			else {
				map[x][++y] = dice[3];
				temp = dice[1];
				dice[1] = dice[4];
				dice[3] = temp;
				dice[4] = dice[6];
				dice[6] = map[x][y];
			}
		}
		//�������� ������ ���
		else if (commands[i] == 2) {
			if (y == 0)	continue;

			if (map[x][y - 1] != 0) {
				temp = dice[1];
				dice[1] = dice[3];
				dice[3] = dice[6];
				dice[4] = temp;
				dice[6] = map[x][y - 1];
				map[x][--y] = 0;
			}
			else {
				map[x][--y] = dice[4];
				temp = dice[1];
				dice[1] = dice[3];
				dice[3] = dice[6];
				dice[4] = temp;
				dice[6] = map[x][y];
			}
		}
		//�������� ������ ���
		else if (commands[i] == 3) {
			if (x == 0)	continue;

			if (map[x - 1][y] != 0) {
				temp = dice[1];
				dice[1] = dice[5];
				dice[2] = temp;
				dice[5] = dice[6];
				dice[6] = map[x - 1][y];
				map[--x][y] = 0;
			}
			else {
				map[--x][y] = dice[2];
				temp = dice[1];
				dice[1] = dice[5];
				dice[2] = temp;
				dice[5] = dice[6];
				dice[6] = map[x][y];
			}
		}
		//�������� ������ ���
		else {
			if (x == N - 1)	continue;

			if (map[x + 1][y] != 0) {
				temp = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[6];
				dice[5] = temp;
				dice[6] = map[x + 1][y];
				map[++x][y] = 0;
			}
			else {
				map[++x][y] = dice[5];
				temp = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[6];
				dice[5] = temp;
				dice[6] = map[x][y];
			}
		}
		cout << dice[1] << endl;
	}

	return 0;
}