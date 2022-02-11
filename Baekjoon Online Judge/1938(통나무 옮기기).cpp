/*
���� ��ũ : https://www.acmicpc.net/problem/1938
BFS�� �̿��Ͽ� �ذ��� �� �ִ� ������.

�볪���� �߽����� ���������Ͽ� �ʱ� ������ �볪���� ���� ��ǥ ������ �볪���� �� ������ BFS�� ���� Ž���� �ϸ� �ȴ�.

�ڵ带 ���� ���� ������ �� ���� ���̴�.
*/
#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

//���� ��, �Ʒ�, ����, ������, ȸ�� �̵��� �� �� �ִ����� ��ȯ�ϴ� �Լ�
bool can_move_U(int N, char land[50][50], int x, int y, int state);
bool can_move_D(int N, char land[50][50], int x, int y, int state);
bool can_move_L(int N, char land[50][50], int x, int y, int state);
bool can_move_R(int N, char land[50][50], int x, int y, int state);
bool can_move_T(int N, char land[50][50], int x, int y, int state);

int main(void) {
	//�Է°� ����
	int N;
	char land[50][50];

	scanf("%d", &N);
	for (int a = 0; a < N; a++) {
		scanf("%s", land[a]);
	}

	//B�� E�� ���� ��ġ �ľ�
	int B[3][2], E[3][2], b_num = 0, e_num = 0;

	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (land[a][b] == 'B') {
				B[b_num][0] = a;
				B[b_num][1] = b;
				b_num++;
			}
			else if (land[a][b] == 'E') {
				E[e_num][0] = a;
				E[e_num][1] = b;
				e_num++;
			}
		}
	}

	//�볪���� �߽ɹ��� ��ġ�� ���η� �������� ���η� �������� ���(�ʱ�� ������ ���), ���´� 0�̸� ���� 1�̸� ����
	int curr_x, curr_y, curr_state, dst_x, dst_y, dst_state;

	curr_x = B[1][0];
	curr_y = B[1][1];
	if (B[1][0] == B[0][0])	curr_state = 0;
	else	curr_state = 1;
	dst_x = E[1][0];
	dst_y = E[1][1];
	if (E[1][0] == E[0][0])	dst_state = 0;
	else	dst_state = 1;

	//BFS�� ���ؼ� ���������� ���� ª�� ��츦 ã�´�
	bool visited[50][50][2];	//visited[a][b][c]�� false�� ���� a, b��ǥ�� c���·� �湮�� ���� ������ �ǹ�(true�� �� �ݴ�)
	queue<tuple<int, int, int, int>> q;
	int move_num = 0, new_state, answer = 0;

	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			visited[a][b][0] = false;
			visited[a][b][1] = false;
		}
	}

	q.push(make_tuple(curr_x, curr_y, curr_state, move_num));	//�ʱ� ���������� ť�� ����
	visited[curr_x][curr_y][curr_state] = true;
	while (!q.empty()) {
		curr_x = get<0>(q.front());
		curr_y = get<1>(q.front());
		curr_state = get<2>(q.front());
		move_num = get<3>(q.front());
		q.pop();

		//���� ���������� �Դٸ� ������ ����ϰ� ����
		if (curr_x == dst_x && curr_y == dst_y && curr_state == dst_state) {
			answer = move_num;
			break;
		}

		//���� �̵������� ��� ť�� move_num�� 1 ������ ����
		if (can_move_U(N, land, curr_x, curr_y, curr_state) && visited[curr_x - 1][curr_y][curr_state] == false) {
			visited[curr_x - 1][curr_y][curr_state] = true;
			q.push(make_tuple(curr_x - 1, curr_y, curr_state, move_num + 1));
		}
		//�Ʒ��� �̵������� ��� ť�� move_num�� 1 ������ ����
		if (can_move_D(N, land, curr_x, curr_y, curr_state) && visited[curr_x + 1][curr_y][curr_state] == false) {
			visited[curr_x + 1][curr_y][curr_state] = true;
			q.push(make_tuple(curr_x + 1, curr_y, curr_state, move_num + 1));
		}
		//�������� �̵������� ��� ť�� move_num�� 1 ������ ����
		if (can_move_L(N, land, curr_x, curr_y, curr_state) && visited[curr_x][curr_y - 1][curr_state] == false){
			visited[curr_x][curr_y - 1][curr_state] = true;
			q.push(make_tuple(curr_x, curr_y - 1, curr_state, move_num + 1));
		}
		//���������� �̵������� ��� ť�� move_num�� 1 ������ ����
		if (can_move_R(N, land, curr_x, curr_y, curr_state) && visited[curr_x][curr_y + 1][curr_state] == false) {
			visited[curr_x][curr_y + 1][curr_state] = true;
			q.push(make_tuple(curr_x, curr_y + 1, curr_state, move_num + 1));
		}
		//ȸ���� �� �� �ִ� ��� ť�� move_num�� 1 ������ ����
		if (can_move_T(N, land, curr_x, curr_y, curr_state)) {
			if (curr_state == 0)	new_state = 1;
			else	new_state = 0;
			
			if (visited[curr_x][curr_y][new_state] == false) {
				visited[curr_x][curr_y][new_state] = true;
				q.push(make_tuple(curr_x, curr_y, new_state, move_num + 1));
			}
		}
	}

	printf("%d\n", answer);

	return 0;
}

bool can_move_U(int N, char land[50][50], int x, int y, int state) {
	int nx[3], ny[3];

	if (state == 0) {
		nx[0] = x - 1; nx[1] = x - 1; nx[2] = x - 1;
		ny[0] = y - 1; ny[1] = y; ny[2] = y + 1;
	}
	else {
		nx[0] = x - 2; nx[1] = x - 1; nx[2] = x;
		ny[0] = y; ny[1] = y; ny[2] = y;
	}

	for (int a = 0; a < 3; a++) {
		if (nx[a] < 0 || nx[a] >= N || ny[a] < 0 || ny[a] >= N || land[nx[a]][ny[a]] == '1')	return false;
	}

	return true;
}

bool can_move_D(int N, char land[50][50], int x, int y, int state) {
	int nx[3], ny[3];

	if (state == 0) {
		nx[0] = x + 1; nx[1] = x + 1; nx[2] = x + 1;
		ny[0] = y - 1; ny[1] = y; ny[2] = y + 1;
	}
	else {
		nx[0] = x; nx[1] = x + 1; nx[2] = x + 2;
		ny[0] = y; ny[1] = y; ny[2] = y;
	}

	for (int a = 0; a < 3; a++) {
		if (nx[a] < 0 || nx[a] >= N || ny[a] < 0 || ny[a] >= N || land[nx[a]][ny[a]] == '1')	return false;
	}

	return true;
}

bool can_move_L(int N, char land[50][50], int x, int y, int state) {
	int nx[3], ny[3];

	if (state == 0) {
		nx[0] = x; nx[1] = x; nx[2] = x;
		ny[0] = y - 2; ny[1] = y - 1; ny[2] = y;
	}
	else {
		nx[0] = x - 1; nx[1] = x; nx[2] = x + 1;
		ny[0] = y - 1; ny[1] = y - 1; ny[2] = y - 1;
	}

	for (int a = 0; a < 3; a++) {
		if (nx[a] < 0 || nx[a] >= N || ny[a] < 0 || ny[a] >= N || land[nx[a]][ny[a]] == '1')	return false;
	}

	return true;
}

bool can_move_R(int N, char land[50][50], int x, int y, int state) {
	int nx[3], ny[3];

	if (state == 0) {
		nx[0] = x; nx[1] = x; nx[2] = x;
		ny[0] = y; ny[1] = y + 1; ny[2] = y + 2;
	}
	else {
		nx[0] = x - 1; nx[1] = x; nx[2] = x + 1;
		ny[0] = y + 1; ny[1] = y + 1; ny[2] = y + 1;
	}

	for (int a = 0; a < 3; a++) {
		if (nx[a] < 0 || nx[a] >= N || ny[a] < 0 || ny[a] >= N || land[nx[a]][ny[a]] == '1')	return false;
	}

	return true;
}

bool can_move_T(int N, char land[50][50], int x, int y, int state) {
	for (int a = x - 1; a <= x + 1; a++) {
		for (int b = y - 1; b <= y + 1; b++) {
			if (a < 0 || a >= N || b < 0 || b >= N || land[a][b] == '1')	return false;
		}
	}
	return true;
}