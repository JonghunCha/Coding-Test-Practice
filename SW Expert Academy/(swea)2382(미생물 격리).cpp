/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�ܼ� �ùķ��̼� ������.

������ ���ǿ� ���� ũ�� 3���� ��Ʈ�� ��������.

1. �̻��� �̵�(board_copy�� ����)
2. ������ ���� ó��(2�� �̻��� ������ ���� ������ �����ش�)
3. board_copy���� board�� �ű��

�ڵ带 ���� ���� ������ �� ���� ���̴�.
*/
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int dx[5] = { 0, -1, 1, 0, 0 }, dy[5] = { 0, 0, 0, -1, 1 };

int main(void) {
	int T, N, M, K, x, y, num, direction, num_temp, direction_temp, size, num_max, answer;
	vector<pair<int, int>> board[100][100], board_copy[100][100];

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		//�Է°� ���� �� ���� �ʱ�ȭ
		scanf("%d %d %d", &N, &M, &K);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				board[a][b].clear();
				board_copy[a][b].clear();
			}
		}
		for (int a = 0; a < K; a++) {
			scanf("%d %d %d %d", &x, &y, &num, &direction);
			board[x][y].push_back(make_pair(num, direction));
		}

		for (int time = 0; time < M; time++) {
			//�̻��� �̵�
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < N; b++) {
					if (board[a][b].size() > 0) {
						num = board[a][b][0].first;
						direction = board[a][b][0].second;
						x = a + dx[direction];
						y = b + dy[direction];
						if (x == 0 || y == 0 || x == N - 1 || y == N - 1) {	//��ǰ ������ ������ ���
							if (direction == 1)	direction = 2;
							else if (direction == 2)	direction = 1;
							else if (direction == 3)	direction = 4;
							else if (direction == 4)	direction = 3;
							board_copy[x][y].push_back(make_pair(num / 2, direction));
						}
						else {	//�� �� ���
							board_copy[x][y].push_back(make_pair(num, direction));
						}
						board[a][b].erase(board[a][b].begin());
					}
				}
			}
			//������ ���� ó��
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < N; b++) {
					if (board_copy[a][b].size() > 1) {
						num = 0;
						size = board_copy[a][b].size();
						num_max = 0;
						for (int c = 0; c < size; c++) {
							num_temp = board_copy[a][b][c].first;
							direction_temp = board_copy[a][b][c].second;
							num += num_temp;
							if (num_temp > num_max) {
								num_max = num_temp;
								direction = direction_temp;
							}
						}
						for (int c = 0; c < size; c++) {
							board_copy[a][b].pop_back();
						}
						board_copy[a][b].push_back(make_pair(num, direction));
					}
				}
			}
			//board_copy���� board�� �ű��
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < N; b++) {
					if (!board_copy[a][b].empty()) {
						num = board_copy[a][b][0].first;
						direction = board_copy[a][b][0].second;
						board[a][b].push_back(make_pair(num, direction));
						board_copy[a][b].pop_back();
					}
				}
			}
		}

		answer = 0;
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (!board[a][b].empty())	answer += board[a][b][0].first;
			}
		}
		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}