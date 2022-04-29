/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���� Ž������ �ذ��� �� �ִ� ������.

������ ���� ���� �ִ� ī��� ��� ���ʴ�� (���� �Ʒ�), (������ �Ʒ�), (������ ��), (���� ��)�� �����Ͽ� ó�� ī��� �� �� �ִ� ��� ��쿡 ���� ����Ͽ���.

�ڵ带 ���� ���� ������ �� �ִ�.
*/
#include <cstdio>
#include <algorithm>
#include <unordered_set>
using namespace std;

int dx[4] = { 1, 1, -1, -1 }, dy[4] = { -1, 1, 1, -1 };
int get_max_path(int N, int board[20][20], int x, int y, int max_sum, int max_len_1, int max_len_2);

int main() {
	int T, N, board[20][20], answer, count;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		//�Է°� ���� �� ���� �ʱ�ȭ
		scanf("%d", &N);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				scanf("%d", &board[a][b]);
			}
		}
		answer = 0;
		//���������� ������ ��� (a, b)��ǥ�� ���� ���� Ž��
		for (int a = 0; a < N - 2; a++) {
			for (int b = 1; b < N - 1; b++) {
				count = get_max_path(N, board, a, b, N - a - 1, b, N -b - 1);
				if (count > answer)	answer = count;
			}
		}

		if (answer == 0)	answer = -1;
		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}

int get_max_path(int N, int board[20][20], int x, int y, int max_sum, int max_len_1, int max_len_2) {
	int ret = 0, nx, ny;
	unordered_set<int> s;
	bool flag;
	//a�� (���� �Ʒ�, ������ ��)�� ������ �Ÿ�, b�� (������ �Ʒ�, ���� ��)�� ������ �Ÿ��� �ǹ�
	for (int a = 1; a <= max_len_1; a++) {	
		for (int b = 1; b <= min(max_len_2, max_sum - a); b++) {
			s.clear();
			nx = x;
			ny = y;
			flag = true;
			//���� �Ʒ� ���� ����
			for (int count = 1; count <= a; count++) {
				nx += dx[0];
				ny += dy[0];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N && s.find(board[nx][ny]) == s.end()){	//�̹� ������ ī��� ���� ������ ����Ʈ�� �ƴ� ��� set�� �߰�
					s.insert(board[nx][ny]);
				}
				else {	//��ǥ�� ����ų� ���� ������ ����Ʈ�� ��� ����
					flag = false;
					break;
				}
			}
			if (!flag)	continue;
			//������ �Ʒ� ���� ����
			for (int count = 1; count <= b; count++) {
				nx += dx[1];
				ny += dy[1];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N && s.find(board[nx][ny]) == s.end()) {
					s.insert(board[nx][ny]);
				}
				else {
					flag = false;
					break;
				}
			}
			if (!flag)	continue;
			//������ �� ���� ����
			for (int count = 1; count <= a; count++) {
				nx += dx[2];
				ny += dy[2];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N && s.find(board[nx][ny]) == s.end()) {
					s.insert(board[nx][ny]);
				}
				else {
					flag = false;
					break;
				}
			}
			if (!flag)	continue;
			//���� �� ���� ����
			for (int count = 1; count <= b; count++) {
				nx += dx[3];
				ny += dy[3];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N && s.find(board[nx][ny]) == s.end()) {
					s.insert(board[nx][ny]);
				}
				else {
					flag = false;
					break;
				}
			}
			if (!flag)	continue;

			if (s.size() > ret)	ret = s.size();
		}
	}

	return ret;
}