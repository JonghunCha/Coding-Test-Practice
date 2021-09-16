/*
���� ��ũ : https://www.acmicpc.net/problem/14503
�ܼ� ���� ������.

�������� ������ �κ� û�ұ��� ���� ��Ĵ�� �����̵��� �����ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int main(void) {
	int N, M, r, c, d, answer = 0;
	int map[50][50];
	//�Է°� ����
	cin >> N; cin >> M;
	cin >> r; cin >> c; cin >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	//�κ� û�ұⰡ ���������� ���� ������ ��� ����
	while (1) {
		//���� ��ǥ�� ���� û�Ҹ� ���ߴٸ� û�Ҹ� �ϰ� �� ������ û���ߴٰ� ��ŷ
		if (map[r][c] == 0) {
			answer++;
			map[r][c] = 2;
		}
		//���� �ٷκ��� ������ ������ ��
		if (d == 0) {
			if (map[r][c - 1] == 0) {
				c--;
				d = 3;
			}
			else if (map[r + 1][c] == 0) {
				r++;
				d = 2;
			}
			else if (map[r][c + 1] == 0) {
				c++;
				d = 1;
			}
			else if (map[r - 1][c] == 0)	r--;
			else if (map[r + 1][c] != 1)	r++;
			else	break;
		}
		//���� �ٷκ��� ������ ������ ��
		else if (d == 1) {
			if (map[r - 1][c] == 0) {
				r--;
				d = 0;
			}
			else if (map[r][c - 1] == 0) {
				c--;
				d = 3;
			}
			else if (map[r + 1][c] == 0) {
				r++;
				d = 2;
			}
			else if (map[r][c + 1] == 0)	c++;
			else if (map[r][c - 1] != 1)	c--;
			else	break;
		}
		//���� �ٷκ��� ������ ������ ��
		else if (d == 2) {
			if (map[r][c + 1] == 0) {
				c++;
				d = 1;
			}
			else if (map[r - 1][c] == 0) {
				r--;
				d = 0;
			}
			else if (map[r][c - 1] == 0) {
				c--;
				d = 3;
			}
			else if (map[r + 1][c] == 0)	r++;
			else if (map[r - 1][c] != 1)	r--;
			else	break;
		}
		//���� �ٷκ��� ������ ������ ��
		else {
			if (map[r + 1][c] == 0) {
				r++;
				d = 2;
			}
			else if (map[r][c + 1] == 0) {
				c++;
				d = 1;
			}
			else if (map[r - 1][c] == 0) {
				r--;
				d = 0;
			}
			else if (map[r][c - 1] == 0)	c--;
			else if (map[r][c + 1] != 1)	c++;
			else	break;
		}
	}

	cout << answer;
	return 0;
}