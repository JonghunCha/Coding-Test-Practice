/*
���� ��ũ : https://www.acmicpc.net/problem/17070
����Ž���� ���� �ذ��� �� �ִ� ������.
(1,2)������ �������� �� �ȿ��� �� �� �ִ� ��� ����� ���� Ž���ϸ� (N, N)�� ���� �� ī������ �ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int answer = 0;

void Get_Answer(const int N, const int map[17][17], int r, int c, int direction);	

int main(void) {
	int N, map[17][17];	//map�� ���� ���¸� ����
	//�Է°� ����
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	Get_Answer(N, map, 1, 2, 0);
	cout << answer;

	return 0;
}
//r,c�� ���� ���� �������� ��ġ�� �ǹ��ϰ�, direction�� �������� ��� �����ִ°��� �ǹ��Ѵ�.
//direction�� 0�̸� ����, 1�̸� ����, 2�̸� �밢������ ���� ������ �ǹ��Ѵ�.
void Get_Answer(const int N, const int map[17][17], int r, int c, int direction) {
	if (r == N && c == N) {
		answer++;
		return;
	}
	else {
		if (direction == 0) {
			if (c + 1 <= N && map[r][c + 1] == 0)	Get_Answer(N, map, r, c + 1, 0);
			if (c + 1 <= N && r + 1 <= N && map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0)	Get_Answer(N, map, r + 1, c + 1, 2);
		}
		else if (direction == 1) {
			if (r + 1 <= N && map[r + 1][c] == 0)	Get_Answer(N, map, r + 1, c, 1);
			if (r + 1 <= N && c + 1 <= N && map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0)	Get_Answer(N, map, r + 1, c + 1, 2);
		}
		else {
			if (c + 1 <= N && map[r][c + 1] == 0)	Get_Answer(N, map, r, c + 1, 0);
			if (r + 1 <= N && map[r + 1][c] == 0)	Get_Answer(N, map, r + 1, c, 1);
			if (c + 1 <= N && r + 1 <= N && map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0)	Get_Answer(N, map, r + 1, c + 1, 2);
		}
	}
}