/*
���� ��ũ : https://www.acmicpc.net/problem/16236
BFS�� ������ �̿��� ���� Ž������ �ذ��� �� �ִ� ������.

������ ������ �ٽ��� �Ʒ� 2������ ����.
1. ���� �� �ִ� ����Ⱑ �ִٸ�, ���� ����� ���� �Դ´�.
2. �Ÿ��� ����� ����Ⱑ 2���� �̻��̶�� ���� ���� ������ ����, �װ� ���� ��ģ�ٸ� ���� ������ ����⸦ ����.

�� �ΰ����� �����ϱ� ���� ����� ��ġ���� �̵��ϴ� Ƚ���� ���� stage�� ��������.

stage�� 0�϶��� ����� ���� ��ġ���� 1��ŭ �̵��� �� �ִ� ������ Ž���ϰ�
stage�� n�϶��� ����� ���� ��ġ���� n+1��ŭ �̵��� ������ Ž���Ѵ�.

��, stage�� �ö󰨿� ���� ����� �̵� �Ÿ��� �þ�� �� �������� ���� �� �ִ� ����⸦ �߰��ϸ�,
�ð��� �߰��ϰ� ����� ��ġ�� �ű��� �ٽ� �ݺ��ϴ� ������ �����ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int answer = 0, shark_x, shark_y, shark_size = 2, eat = 0;

bool Find_Fish(int N, int map[20][20], int visit[20][20]);

int main(void) {
	int N, map[20][20], visit[20][20];
	//�Է°� ����
	cin >> N;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			cin >> map[a][b];
			if (map[a][b] == 9) {
				shark_x = a;
				shark_y = b;
			}
		}
	}
	//�� ���� �������� ���� ���� ���̸� �����ϰ� ��ġ�� ������ �� ���� ������ �����Ѵ�
	//���� ���� ���̸� ã�� ���ϸ� while���� �����Ѵ�
	while (1) {
		//visit�� �� stage���� ����� ������ ����Ѵ�
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				visit[a][b] = -1;
			}
		}
		visit[shark_x][shark_y] = 0;
		//���̸� ã�� ���ϸ� ����
		if (!Find_Fish(N, map, visit))	break;
	}
	cout << answer;
	return 0;
}

bool Find_Fish(int N, int map[20][20], int visit[20][20]) {
	int stage = 0;
	bool flag = true;	//flag�� while���� �� �������� ���ǹ��� ����(�� �����̰ų� ���̸� ã�� ���)�� ������ �ǹ�
	while (flag) {
		flag = false;
		//���� Ž�� ������ �湮�� �� ����, ���� stage���� �湮�� ������ ������ ��츦 ã�´�
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				//���ʿ� ���� stage���� �湮�� ������ �ִ� ���
				if (a != 0 && visit[a - 1][b] == stage && visit[a][b] == -1) {
					//���� �� ���� �� �ִ� ����Ⱑ ���� ��
					if (map[a][b] > 0 && map[a][b] < shark_size) {
						answer += stage + 1;
						eat++;
						if (eat == shark_size) {
							shark_size++;
							eat = 0;
						}
						map[shark_x][shark_y] = 0;
						map[a][b] = 9;
						shark_x = a;
						shark_y = b;
						return true;
					}
					//�� �̵��� �� ���� ��
					else if (map[a][b] == 0 || map[a][b] == shark_size) {
						visit[a][b] = stage + 1;
						flag = true;
					}
				}
				//���ʿ� ���� stage���� �湮�� ������ �ִ� ���
				if (b != 0 && visit[a][b - 1] == stage && visit[a][b] == -1) {
					if (map[a][b] > 0 && map[a][b] < shark_size) {
						answer += stage + 1;
						eat++;
						if (eat == shark_size) {
							shark_size++;
							eat = 0;
						}
						map[shark_x][shark_y] = 0;
						map[a][b] = 9;
						shark_x = a;
						shark_y = b;
						return true;
					}
					else if (map[a][b] == 0 || map[a][b] == shark_size) {
						visit[a][b] = stage + 1;
						flag = true;
					}
				}
				//���ʿ� ���� stage���� �湮�� ������ �ִ� ���
				if (a != N - 1 && visit[a + 1][b] == stage && visit[a][b] == -1) {
					if (map[a][b] > 0 && map[a][b] < shark_size) {
						answer += stage + 1;
						eat++;
						if (eat == shark_size) {
							shark_size++;
							eat = 0;
						}
						map[shark_x][shark_y] = 0;
						map[a][b] = 9;
						shark_x = a;
						shark_y = b;
						return true;
					}
					else if (map[a][b] == 0 || map[a][b] == shark_size) {
						visit[a][b] = stage + 1;
						flag = true;
					}
				}
				//���ʿ� ���� stage���� �湮�� ������ �ִ� ���
				if (b != N - 1 && visit[a][b + 1] == stage && visit[a][b] == -1) {
					if (map[a][b] > 0 && map[a][b] < shark_size) {
						answer += stage + 1;
						eat++;
						if (eat == shark_size) {
							shark_size++;
							eat = 0;
						}
						map[shark_x][shark_y] = 0;
						map[a][b] = 9;
						shark_x = a;
						shark_y = b;
						return true;
					}
					else if (map[a][b] == 0 || map[a][b] == shark_size) {
						visit[a][b] = stage + 1;
						flag = true;
					}
				}
			}
		}
		stage++;
	}
	return false;
}