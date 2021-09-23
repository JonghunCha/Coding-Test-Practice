/*
���� ��ũ : https://www.acmicpc.net/problem/15683
���� Ž������ �ذ��� �� �ִ�.

��ü �繫���� Ž���ϸ� cctv�� �ִ� ��ġ�� �ľ��� ��, cctv���� ������ �� �ִ� ������ ��� ���տ� ���� �ùķ��̼��� ������ ��, ���� �簢���밡 ���� ���� �����ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int answer = 100;

void Get_Answer(int N, int M, const int map[8][8], int direction[8][8][4], int step);
void Calculate(int N, int M, const int map[8][8], int direction[8][8][4]);

int main(void) {
	//direction�� x, y��ǥ���� �������Ͽ� ���� cctv�� �����ϴ��� ���ϴ����� �ǹ�(0=��,1=��,2=��,3=��)
	int N, M, map[8][8], direction[8][8][4];
	//�Է°� ����
	cin >> N; cin >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	//direction �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				direction[i][j][k] = 0;
			}
		}
	}

	Get_Answer(N, M, map, direction, 0);

	cout << answer;
	return 0;
}

void Get_Answer(int N, int M, const int map[8][8], int direction[8][8][4], int step) {
	//step�� N*M�̶�� ���� ��ü cctv�� ���� ���� ������ �Ϸ�Ǿ����� �ǹ�
	if (step == N * M) {
		Calculate(N, M, map, direction);
		return;
	}
	int x = step / M, y = step % M;
	//�ش� ������ ������̰ų� ���̶�� ���⼳���� �ʿ� ����
	if (map[x][y] == 0 || map[x][y] == 6) {
		Get_Answer(N, M, map, direction, step + 1);
	}
	//1�� cctv�� ��� 4���� ���� ���� ����
	else if (map[x][y] == 1) {
		direction[x][y][0] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][0] = 0;
		direction[x][y][1] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][1] = 0;
		direction[x][y][2] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][2] = 0;
		direction[x][y][3] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][3] = 0;
	}
	//2�� cctv�� ��� 2���� ���� ���� ����
	else if (map[x][y] == 2) {
		direction[x][y][0] = 1;
		direction[x][y][2] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][0] = 0;
		direction[x][y][2] = 0;
		direction[x][y][1] = 1;
		direction[x][y][3] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][1] = 0;
		direction[x][y][3] = 0;
	}
	//3�� cctv�� ��� 4���� ���� ���� ����
	else if (map[x][y] == 3) {
		direction[x][y][0] = 1;
		direction[x][y][1] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][0] = 0;
		direction[x][y][2] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][1] = 0;
		direction[x][y][3] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][2] = 0;
		direction[x][y][0] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][0] = 0;
		direction[x][y][3] = 0;
	}
	//4�� cctv�� ��� 4���� ���� ���� ����
	else if (map[x][y] == 4) {
		direction[x][y][0] = 1;
		direction[x][y][1] = 1;
		direction[x][y][2] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][2] = 0;
		direction[x][y][3] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][1] = 0;
		direction[x][y][2] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][0] = 0;
		direction[x][y][1] = 1;
		Get_Answer(N, M, map, direction, step + 1);
		direction[x][y][1] = 0;
		direction[x][y][2] = 0;
		direction[x][y][3] = 0;
	}
	//5�� cctv�� ��� ��� �������� ����
	else if (map[x][y] == 5) {
		direction[x][y][0] = 1;
		direction[x][y][1] = 1;
		direction[x][y][2] = 1;
		direction[x][y][3] = 1;
		Get_Answer(N, M, map, direction, step + 1);
	}
}

void Calculate(int N, int M, const int map[8][8], int direction[8][8][4]) {
	int __map[8][8], num_zero = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			__map[i][j] = map[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//���� ������ ���
			if (direction[i][j][0]) {
				for (int a = i; a >= 0; a--) {
					if (__map[a][j] == 6)	break;
					else if (__map[a][j] == 0) {
						__map[a][j] = 7;
					}
					else	continue;
				}
			}
			//���� ������ ���
			if (direction[i][j][1]) {
				for (int a = j; a < M; a++) {
					if (__map[i][a] == 6)	break;
					else if (__map[i][a] == 0) {
						__map[i][a] = 7;
					}
					else	continue;
				}
			}
			//���� ������ ���
			if (direction[i][j][2]) {
				for (int a = i; a < N; a++) {
					if (__map[a][j] == 6)	break;
					else if (__map[a][j] == 0) {
						__map[a][j] = 7;
					}
					else	continue;
				}
			}
			//���� ������ ���
			if (direction[i][j][3]) {
				for (int a = j; a >= 0; a--) {
					if (__map[i][a] == 6)	break;
					else if (__map[i][a] == 0) {
						__map[i][a] = 7;
					}
					else	continue;
				}
			}
		}
	}
	//�� ���� ī����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (__map[i][j] == 0)	num_zero++;
		}
	}
	//�� ������ �ּڰ� ����
	if (num_zero < answer)	answer = num_zero;
}