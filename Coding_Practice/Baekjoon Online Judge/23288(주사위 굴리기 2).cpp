/*
���� ��ũ : https://www.acmicpc.net/problem/23288
�ܼ� ������ DFS�� ��ģ ������.

�켱 ������ ���ǿ� ���� �ֻ����� ������.

�׷� ���� DFS�� ���� ���� �ֻ����� ��ġ�� ���� ���� ���� ���� ���� ĭ�� ������ ���Ѵ�.

answer�� ���� ������ ���Ѵ�.

�� ������ K���ϸ� �ȴ�.
*/
#include <iostream>

using namespace std;

int N, M, K;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 }; 

void move(int& x, int& y, int& direction, int dice[4][3]);
int DFS(int x, int y, int board[20][20], int visited[20][20]);

int main(void) {
	//direction 0 = ��, 1 = ��, 2 = ��, 3 = ��
	int board[20][20], direction = 0, dice[4][3], visited[20][20], answer = 0, x = 0, y = 0;
	//�Է°� ���� �� ���� �ʱ�ȭ
	cin >> N >> M >> K;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < M; b++) {
			cin >> board[a][b];
		}
	}
	dice[0][1] = 2;
	dice[1][0] = 4;
	dice[1][1] = 1;
	dice[1][2] = 3;
	dice[2][1] = 5;
	dice[3][1] = 6;
	//K���� �̵�
	for (int a = 0; a < K; a++) {
		move(x, y, direction, dice);	//�ֻ����� direction�������� ������, �ֻ����� ������ ����
		for (int b = 0; b < N; b++) {	//visited�� DFS���� �湮�� ������ ��ŷ�ϴ� ������ �� �湮�ÿ� 0, �湮�ÿ� 1�� ����
			for (int c = 0; c < M; c++) {
				visited[b][c] = 0;
			}
		}
		answer += DFS(x, y, board, visited) * board[x][y];
		if (dice[3][1] > board[x][y]) {			//�ֻ����� �ٴڸ��� x, y�� ������ Ŭ ��� �̵����� �ð���� 90�� ȸ��
			direction = (direction + 1) % 4;
		}
		else if (dice[3][1] < board[x][y]) {	//�ݴ��� ��� �̵����� �ݽð���� 90�� ȸ��
			if (direction == 0)	direction = 3;
			else	direction--;
		}
	}
	cout << answer << endl;

	return 0;
}
//�ֻ����� direction�������� ������ �ֻ����� ������ ����
void move(int& x, int& y, int& direction, int dice[4][3]) {
	int temp;
	if (direction == 0) {
		if (y + 1 == M) {
			direction = 2;
			move(x, y, direction, dice);
		}
		else {
			y++;
			temp = dice[1][0];
			dice[1][0] = dice[3][1];
			dice[3][1] = dice[1][2];
			dice[1][2] = dice[1][1];
			dice[1][1] = temp;
		}
	}
	else if (direction == 1) {
		if (x + 1 == N) {
			direction = 3;
			move(x, y, direction, dice);
		}
		else {
			x++;
			temp = dice[0][1];
			dice[0][1] = dice[3][1];
			dice[3][1] = dice[2][1];
			dice[2][1] = dice[1][1];
			dice[1][1] = temp;
		}
	}
	else if (direction == 2) {
		if (y - 1 == -1) {
			direction = 0;
			move(x, y, direction, dice);
		}
		else {
			y--;
			temp = dice[1][2];
			dice[1][2] = dice[3][1];
			dice[3][1] = dice[1][0];
			dice[1][0] = dice[1][1];
			dice[1][1] = temp;
		}
	}
	else {
		if (x - 1 == -1) {
			direction = 1;
			move(x, y, direction, dice);
		}
		else {
			x--;
			temp = dice[2][1];
			dice[2][1] = dice[3][1];
			dice[3][1] = dice[0][1];
			dice[0][1] = dice[1][1];
			dice[1][1] = temp;
		}
	}
	return;
}
//������ ĭ�� ���Ǹ� board[x][y]�� ����Ǿ� �ְ� ���� ���� ���� ĭ�� ���� ��ȯ
int DFS(int x, int y, int board[20][20], int visited[20][20]) {
	int ret = 1, nx, ny;
	visited[x][y] = 1;

	for (int a = 0; a < 4; a++) {
		nx = x + dx[a];
		ny = y + dy[a];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == 0 && board[nx][ny] == board[x][y]) {
			ret += DFS(nx, ny, board, visited);
		}
	}

	return ret;
}