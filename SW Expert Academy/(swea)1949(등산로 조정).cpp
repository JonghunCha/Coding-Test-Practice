/*
���� ��ũ : https://swexpertacademy.com/main/main.do
DFS�� �̿��� ���� Ž������ �ذ��� �� �ִ� ������.

���� ���� �ִ� ������ ���츮�� ��ġ�� �����Ѵ�.

�׷� ���� �� �ִ� ���� ���츮�� �������� �Ͽ� ���� �� ���θ� ���ϸ� �ȴ�.

�׷��� �� ������ �ִ� K��ŭ ���� �� �ִٰ� �Ͽ��⿡ ���� ������ ������ ������ ������ 0~K��ŭ ����� ��쿡 ���� ���� Ž���� �����ϸ� �ȴ�.

���� �� ���θ� ���ϴ� ���� DFS�� ������� �����Ͽ���.
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

int get_max_length(int N, int K, int board[8][8], int x, int y);
int simulation(int N, int board[8][8], int x, int y, int length);

int main(void) {
	int T, N, K, board[8][8], highest, x, y, answer, curr_length;
	vector<pair<int, int>> highest_coordinate;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		//�Է°� ���� �� ���� �ʱ�ȭ
		scanf("%d %d", &N, &K);
		highest = 0;
		highest_coordinate.clear();
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				scanf("%d", &board[a][b]);
				if (board[a][b] > highest)	highest = board[a][b];
			}
		}
		//���� ���� ���츮 ���Ϳ� ����
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (board[a][b] == highest)	highest_coordinate.push_back(make_pair(a, b));
			}
		}
		//��� ���� ���� ���츮�� �������� �ִ� ���� ���� ���ϱ�
		answer = 0;
		for (int a = 0; a < highest_coordinate.size(); a++) {
			x = highest_coordinate[a].first;
			y = highest_coordinate[a].second;
			curr_length = get_max_length(N, K, board, x, y);
			if (curr_length > answer)	answer = curr_length;
		}

		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}

//���� ������ �ƴ� ��� ������ 0~K��ŭ ���� �� DFS����� �Լ� simulation�� ���� �ִ� ���θ� ���Ѵ�.
int get_max_length(int N, int K, int board[8][8], int x, int y) {
	int ret = 0, curr_length;

	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (a != x || b != y) {
				for (int c = 0; c <= K; c++) {
					board[a][b] -= c;
					curr_length = simulation(N, board, x, y, 1);
					if (curr_length > ret)	ret = curr_length;
					board[a][b] += c;
				}
			}
		}
	}

	return ret;
}

//x, y�������� ���θ� ���� �� �ִ� ��� ������ Ž���ϸ� ��������� ���� ���̸� length�� �����Ͽ� �����Ѵ�.
int simulation(int N, int board[8][8], int x, int y, int length) {
	int nx, ny, ret = 0, curr_length;
	bool is_end = true;

	for (int a = 0; a < 4; a++) {
		nx = x + dx[a];
		ny = y + dy[a];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && board[nx][ny] < board[x][y]) {
			curr_length = simulation(N, board, nx, ny, length + 1);
			is_end = false;
			if (curr_length > ret)	ret = curr_length;
		}
	}
	
	if (is_end)	return length;
	return ret;
}