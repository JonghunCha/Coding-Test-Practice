/*
���� Ǯ�� : https://swexpertacademy.com/main/main.do
BFS�� �ذ��� �� �ִ� ������.

�� �ð��� �帧�� ���� Ż�ֹ��� �� �� �ִ� ��ġ�� BFS�� ã��, �ش� ������ �湮�ߴٴ� ǥ�ø� �� �� ���� �ð��� �湮���� ���� ������ ������ �� �ִ��� Ȯ���ϸ� �ȴ�.

�ϳ� ����ؾ� �� ���� �������� ��翡 ���� �̵��� �������� �Ұ������� Ȯ���� �� �־�� �Ѵ�.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

void search_near(int N, int M, int board[50][50], bool visited[50][50], bool visited_copy[50][50], int x, int y);

int main(void) {
	int T, N, M, R, C, L, board[50][50], answer;
	bool visited[50][50], visited_copy[50][50];

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		//�Է°� ���� �� ���� �ʱ�ȭ
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < M; b++) {
				scanf("%d", &board[a][b]);
			}
		}
		memset(visited, false, sizeof(bool) * 50 * 50);
		memset(visited_copy, false, sizeof(bool) * 50* 50);

		visited[R][C] = true;
		for (int times = 2; times <= L; times++) {	//�� �ð��� �帧�� ����
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < M; b++) {
					//�̹� �湮�� �����̸� �ش� �������� ������ �������� �̵��������� Ȯ��
					if(board[a][b] > 0 && visited[a][b] == true)	search_near(N, M, board, visited, visited_copy, a, b);
				}
			}
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < M; b++) {
					if (visited_copy[a][b])	visited[a][b] = true;
				}
			}
		}

		answer = 0;
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < M; b++) {
				if (visited[a][b] == true)	answer++;
			}
		}
		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}

void search_near(int N, int M, int board[50][50], bool visited[50][50], bool visited_copy[50][50], int x, int y) {
	int nx, ny;
	//�� ���� ��翡 ���� �̵��� �������� Ȯ��
	if (board[x][y] == 1) {
		nx = x + dx[0];
		ny = y + dy[0];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false && (board[nx][ny] == 1 || board[nx][ny] == 2 || board[nx][ny] == 5 || board[nx][ny] == 6)) {
			visited_copy[nx][ny] = true;
		}
		nx = x + dx[1];
		ny = y + dy[1];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false && (board[nx][ny] == 1 || board[nx][ny] == 3 || board[nx][ny] == 6 || board[nx][ny] == 7)) {
			visited_copy[nx][ny] = true;
		}
		nx = x + dx[2];
		ny = y + dy[2];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false && (board[nx][ny] == 1 || board[nx][ny] == 2 || board[nx][ny] == 4 || board[nx][ny] == 7)) {
			visited_copy[nx][ny] = true;
		}
		nx = x + dx[3];
		ny = y + dy[3];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false && (board[nx][ny] == 1 || board[nx][ny] == 3 || board[nx][ny] == 4 || board[nx][ny] == 5)) {
			visited_copy[nx][ny] = true;
		}
	}
	else if (board[x][y] == 2) {
		nx = x + dx[0];
		ny = y + dy[0];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false && (board[nx][ny] == 1 || board[nx][ny] == 2 || board[nx][ny] == 5 || board[nx][ny] == 6)) {
			visited_copy[nx][ny] = true;
		}
		nx = x + dx[2];
		ny = y + dy[2];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false && (board[nx][ny] == 1 || board[nx][ny] == 2 || board[nx][ny] == 4 || board[nx][ny] == 7)) {
			visited_copy[nx][ny] = true;
		}
	}
	else if (board[x][y] == 3) {
		nx = x + dx[1];
		ny = y + dy[1];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false && (board[nx][ny] == 1 || board[nx][ny] == 3 || board[nx][ny] == 6 || board[nx][ny] == 7)) {
			visited_copy[nx][ny] = true;
		}
		nx = x + dx[3];
		ny = y + dy[3];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false && (board[nx][ny] == 1 || board[nx][ny] == 3 || board[nx][ny] == 4 || board[nx][ny] == 5)) {
			visited_copy[nx][ny] = true;
		}
	}
	else if (board[x][y] == 4) {
		nx = x + dx[0];
		ny = y + dy[0];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false && (board[nx][ny] == 1 || board[nx][ny] == 2 || board[nx][ny] == 5 || board[nx][ny] == 6)) {
			visited_copy[nx][ny] = true;
		}
		nx = x + dx[1];
		ny = y + dy[1];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false && (board[nx][ny] == 1 || board[nx][ny] == 3 || board[nx][ny] == 6 || board[nx][ny] == 7)) {
			visited_copy[nx][ny] = true;
		}
	}
	else if (board[x][y] == 5) {
		nx = x + dx[1];
		ny = y + dy[1];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false && (board[nx][ny] == 1 || board[nx][ny] == 3 || board[nx][ny] == 6 || board[nx][ny] == 7)) {
			visited_copy[nx][ny] = true;
		}
		nx = x + dx[2];
		ny = y + dy[2];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false && (board[nx][ny] == 1 || board[nx][ny] == 2 || board[nx][ny] == 4 || board[nx][ny] == 7)) {
			visited_copy[nx][ny] = true;
		}
	}
	else if (board[x][y] == 6) {
		nx = x + dx[2];
		ny = y + dy[2];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false && (board[nx][ny] == 1 || board[nx][ny] == 2 || board[nx][ny] == 4 || board[nx][ny] == 7)) {
			visited_copy[nx][ny] = true;
		}
		nx = x + dx[3];
		ny = y + dy[3];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false && (board[nx][ny] == 1 || board[nx][ny] == 3 || board[nx][ny] == 4 || board[nx][ny] == 5)) {
			visited_copy[nx][ny] = true;
		}
	}
	else if (board[x][y] == 7) {
		nx = x + dx[3];
		ny = y + dy[3];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false && (board[nx][ny] == 1 || board[nx][ny] == 3 || board[nx][ny] == 4 || board[nx][ny] == 5)) {
			visited_copy[nx][ny] = true;
		}
		nx = x + dx[0];
		ny = y + dy[0];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false && (board[nx][ny] == 1 || board[nx][ny] == 2 || board[nx][ny] == 5 || board[nx][ny] == 6)) {
			visited_copy[nx][ny] = true;
		}
	}
}