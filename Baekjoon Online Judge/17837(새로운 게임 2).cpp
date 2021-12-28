/*
���� ��ũ : https://www.acmicpc.net/problem/17837
�ܼ� ���� �ùķ��̼� �����̴�.

�� ���� ����ؾ� �� ��Ȳ�� ���� ĭ�� ���� ���� ��ġ�� ����ε�, vector�� �̿��ϸ� �� �κ��� ���� ó���� �� �ִ�.
*/
#include <iostream>
#include <vector>
using namespace std;

bool Game_End = false;
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

void Move_Piece(int N, int board[13][13], int piece[11][3], vector<int> board_piece[13][13], int index, bool first);

int main(void) {
	int N, K, board[13][13], piece[11][3], turn_num = 0;
	vector<int> board_piece[13][13];	//�� ��ǥ�� �ִ� ������ �Ʒ��������� ������� ����
	//�Է°� ����
	cin >> N; cin >> K;
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			cin >> board[a][b];
		}
	}
	for (int a = 1; a <= K; a++) {
		cin >> piece[a][0];
		cin >> piece[a][1];
		cin >> piece[a][2];
		board_piece[piece[a][0]][piece[a][1]].emplace_back(a);
	}
	//�ִ� 1000�ϱ��� ����
	while (turn_num <= 1000) {
		turn_num++;
		for (int a = 1; a <= K; a++) {
			Move_Piece(N, board, piece, board_piece, a, true);
			if (Game_End == true)	break;
		}
		if (Game_End == true)	break;
	}
	if (turn_num == 1001)	cout << -1;
	else	cout << turn_num;

	return 0;
}

void Move_Piece(int N, int board[13][13], int piece[11][3], vector<int> board_piece[13][13], int index, bool first) {
	int x = piece[index][0], y = piece[index][1], direction = piece[index][2];
	int nx = x + dx[direction], ny = y + dy[direction];
	bool flag = false;
	//�̵��Ϸ��� ĭ�� ��� ĭ�� ���
	if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && board[nx][ny] == 0) {
		for (int a = 0; a < board_piece[x][y].size(); a++) {
			//�Ʒ����� ���� ���Ǹ� index�� �ش��ϴ� ���� ã�´�
			if (board_piece[x][y][a] == index)	flag = true;
			if (flag) {
				//�̵��ϴ� ĭ�� vector�� �߰�
				board_piece[nx][ny].emplace_back(board_piece[x][y][a]);
				//���� ��ġ ���� ����
				piece[board_piece[x][y][a]][0] = nx;
				piece[board_piece[x][y][a]][1] = ny;
				//������ ĭ���� ����
				board_piece[x][y].erase(board_piece[x][y].begin() + a);
				a--;
				if (board_piece[nx][ny].size() >= 4) {
					Game_End = true;
					return;
				}
			}
		}
	}
	//�̵��Ϸ��� ĭ�� ������ ĭ�� ���
	else if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && board[nx][ny] == 1) {
		for (int a = board_piece[x][y].size() - 1; a >= 0; a--) {
			//������ ���� ���Ǹ� index�� �ش��ϴ� ������ �ű��
			if (flag == true)	return;
			board_piece[nx][ny].emplace_back(board_piece[x][y][a]);
			piece[board_piece[x][y][a]][0] = nx;
			piece[board_piece[x][y][a]][1] = ny;
			board_piece[x][y].erase(board_piece[x][y].begin() + a);
			if (board_piece[nx][ny].size() >= 4) {
				Game_End = true;
				return;
			}
			if (board_piece[x][y][a] == index)	flag = true;
		}
	}
	//�̵��Ϸ��� ĭ�� �Ķ��� ĭ�� ���
	else {
		//first�� true�� ���� �Ķ��� ���� ó�� �������� �ǹ�. ���� ���� �ٲٰ� Move_Piece�� �ٽ� ȣ��(�� �� first�� false�� ����)
		if (first == true) {
			if (direction == 1)	piece[index][2] = 2;
			else if (direction == 2)	piece[index][2] = 1;
			else if (direction == 3)	piece[index][2] = 4;
			else	piece[index][2] = 3;
			Move_Piece(N, board, piece, board_piece, index, false);
		}
	}
}