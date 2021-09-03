/*
���� ��ũ : https://www.acmicpc.net/problem/17135
����Ž���� ���� �ذ��� �� �ִ� ������.
�ü��� ��ġ�� ���� ����� �޶��� �� �ִ� �����̱⿡ ������ ��� �ü���ġ�� ���տ� ���� ������ ����ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int answer = 0;

void Get_Answer(const int N, const int M, const int D, const int map[15][15]);
void Play_Game(const int N, const int M, const int D, const int map[15][15], const int arrange[15]);
bool Is_Game_Over(const int N, const int M, const int map[15][15]);

int main(void) {
	int N, M, D;
	int map[15][15];

	cin >> N; cin >> M; cin >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	Get_Answer(N, M, D, map);
	cout << answer;
	return 0;
}
//��� �ü��� ���տ� ���� Play_Game�Լ��� ȣ���Ͽ� ���� ���� ���� ���̴� ������ ã�´�.
void Get_Answer(const int N, const int M, const int D, const int map[15][15]) {
	int arrange[15];	//�ü��� ��ġ�� ��Ÿ���� �迭(0�̸� �� �ڸ�, 1�̸� �ü��� �ִ� �ڸ�)
	for (int i = 0; i < M - 2; i++) {
		for (int j = i + 1; j < M - 1; j++) {
			for (int k = j + 1; k < M; k++) {
				for (int m = 0; m < M; m++)	arrange[m] = 0;
				arrange[i] = 1;
				arrange[j] = 1;
				arrange[k] = 1;
				Play_Game(N, M, D, map, arrange);
			}
		}
	}
}
//�־��� �ü� ��ġ������ ������ �����ϴ� �Լ�
void Play_Game(const int N, const int M, const int D, const int map[15][15], const int arrange[15]) {
	int removed_enemy = 0, step, flag, distance, target[3][2];	//target�� �� �ü��� �����ϴ� ���� ��ġ�� ��Ÿ����
	int map_copy[15][15];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map_copy[i][j] = map[i][j];
		}
	}
	
	while (1) {
		step = 0;	//step�� �̹� �Ͽ� �ü����� ����� ���� ���� �� �ִ����� �ǹ��Ѵ�
		if (Is_Game_Over(N, M, map_copy)) {
			if (removed_enemy > answer)	answer = removed_enemy;
			return;
		}
		
		for (int i = 0; i < M; i++) {
			//�� �ü��� ���ؼ�
			if (arrange[i] == 1) {
				flag = 0;
				//���� ����� ������ ã�´�
				for (int j = 1; j <= D; j++) {
					//���߿��� ���� ������ ������ ã�´�
					for (int k = 0; k < M; k++) {
						for (int m = N - 1; m >= 0; m--) {
							if (i > k)	distance = N - m + i - k;
							else	distance = N - m + k - i;
							//���̰� ��ġ�ϸ� ���� �ִ� ���̶�� target���� �����ϰ� step�� �����ش�
							if (distance == j && map_copy[m][k] == 1) {
								target[step][0] = m;
								target[step][1] = k;
								step++;
								flag = 1;
								break;
							}
						}
						if (flag == 1)	break;
					}
					if (flag == 1)	break;
				}
			}
		}
		//3���� �ü��� ���� �� ���ߴ� ���
		if (step == 3) {
			//�ü����� Ÿ���� ��� ��ġ�ϴ� ���
			if (target[0][0] == target[1][0] && target[0][1] == target[1][1] && target[0][0] == target[2][0] && target[0][1] == target[2][1]) {
				removed_enemy++;
				map_copy[target[0][0]][target[0][1]] = 0;
			}
			//�Ѹ� ��ġ�ϴ� ���
			else if ((target[0][0] == target[1][0] && target[0][1] == target[1][1]) && (target[0][0] != target[2][0] || target[0][1] != target[2][1])) {
				removed_enemy += 2;
				map_copy[target[0][0]][target[0][1]] = 0;
				map_copy[target[2][0]][target[2][1]] = 0;
			}
			else if ((target[0][0] != target[1][0] || target[0][1] != target[1][1]) && (target[0][0] == target[2][0] && target[0][1] == target[2][1])) {
				removed_enemy += 2;
				map_copy[target[0][0]][target[0][1]] = 0;
				map_copy[target[1][0]][target[1][1]] = 0;
			}
			else if ((target[0][0] != target[1][0] || target[0][1] != target[1][1]) && (target[1][0] == target[2][0] && target[1][1] == target[2][1])) {
				removed_enemy += 2;
				map_copy[target[0][0]][target[0][1]] = 0;
				map_copy[target[1][0]][target[1][1]] = 0;
			}
			//��� �ٸ� ���
			else {
				removed_enemy += 3;
				map_copy[target[0][0]][target[0][1]] = 0;
				map_copy[target[1][0]][target[1][1]] = 0;
				map_copy[target[2][0]][target[2][1]] = 0;
			}
		}
		//3���� �ü� �� 2�� ���� ���� �� �ִ� ���
		else if (step == 2) {
			if (target[0][0] == target[1][0] && target[0][1] == target[1][1]) {
				removed_enemy++;
				map_copy[target[0][0]][target[0][1]] = 0;
			}
			else {
				removed_enemy += 2;
				map_copy[target[0][0]][target[0][1]] = 0;
				map_copy[target[1][0]][target[1][1]] = 0;
			}
		}
		//3���� �ü� �� 2�� ���� ���� �� �ִ� ���
		else if (step == 1) {
			removed_enemy++;
			map_copy[target[0][0]][target[0][1]] = 0;
		}
		//���� ���������� ���� ���� ���� ���� �̵���Ų��
		for (int i = N - 1; i > 0; i--) {
			for (int j = 0; j < M; j++) {
				map_copy[i][j] = map_copy[i - 1][j];
			}
		}
		for (int i = 0; i < M; i++)	map_copy[0][i] = 0;
	}
}
//������ �������� Ȯ���ϴ� �Լ�
bool Is_Game_Over(const int N, const int M, const int map[15][15]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1)	return false;
		}
	}
	return true;
}