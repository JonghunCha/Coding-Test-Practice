/*
���� ��ũ : https://www.acmicpc.net/problem/23290
���� �ùķ��̼� ������.

���� ������ ���̵��� ������ ������ �ڵ尡 ������鼭 ����ó���� �� �ϰ� �ڵ忡 ������ �߻����� �ʵ��� �ϴ°� �߿��ϴ�.

���žƴ� �Ǽ� ������ �������� ������ϰ� �� ����..
*/
#include <iostream>
#include <queue>
using namespace std;

int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
//dead_fish�� �� ��ǥ�� ����� ������ ���� �Ⱓ���� ��ȿ���� ����, shark_move�� step3���� ����� �̵������� ����
int M, S, shark_x, shark_y, dead_fish[5][5], shark_move[3], max_dead_fish;
//board_magic�� step1���� ������ ����� ���� ����, board_move�� step2���� �̵��� ����⸦ �ӽ� ����
queue<int> board[5][5], board_magic[5][5], board_move[5][5];

void step1();	//step1(��������)��� board_magic�� ����
void step2();	//step2(����� �̵�)��� board_move�� ���� �� �� �ٽ� board�� ����
void step3();	//step3(����� �̵�)��� board�� ����
void DFS(int move_direction[3], int index, int x, int y);		//step3���� ���� ���� ����⸦ ���ܽ�Ű�� ������ ���
void step4();	//step4(����� ������ ���� ����)
void step5();	//step1���� ����� board_magic�� ������ ����⸦ board�� �̵�

int main(void) {
	int x, y, direction, answer = 0;
	//�Է°� ���� �� ���� �ʱ�ȭ
	cin >> M >> S;
	for (int a = 0; a < M; a++) {
		cin >> x >> y >> direction;
		board[x][y].push(direction);
	}
	cin >> shark_x >> shark_y;
	for (int a = 1; a <= 4; a++) {
		for (int b = 1; b <= 4; b++) {
			dead_fish[a][b] = 0;
		}
	}
	//S�� �ݺ�
	for (int practice_num = 1; practice_num <= S; practice_num++) {
		step1();	
		step2();
		shark_move[0] = 1;
		shark_move[1] = 1;
		shark_move[2] = 1;
		max_dead_fish = -1;
		step3();
		step4();
		step5();
	}
	//���� ������� �� ���
	for (int a = 1; a <= 4; a++) {
		for (int b = 1; b <= 4; b++) {
			while (!board[a][b].empty()) {
				board[a][b].pop();
				answer++;
			}
		}
	}
	cout << answer << endl;

	return 0;
}

void step1() {
	int fish_num, temp;
	//���� ��ǥ�� �ִ� ����⸦ step5���� �����ϱ� ���� board_magic�� ����
	for (int a = 1; a <= 4; a++) {
		for (int b = 1; b <= 4; b++) {
			fish_num = board[a][b].size();
			for (int c = 0; c < fish_num; c++) {
				temp = board[a][b].front();
				board_magic[a][b].push(temp);
				board[a][b].pop();
				board[a][b].push(temp);
			}
		}
	}
	return;
}

void step2() {
	int fish_num, direction, nx, ny;
	bool isMoved;
	//�� �������� �̵���Ų ����� board_move�� �ӽ� ����
	for (int a = 1; a <= 4; a++) {
		for (int b = 1; b <= 4; b++) {
			fish_num = board[a][b].size();
			for (int c = 0; c < fish_num; c++) {
				direction = board[a][b].front();
				isMoved = false;
				for (int d = 0; d < 8; d++) {
					nx = a + dx[direction];
					ny = b + dy[direction];
					if (nx >= 1 && nx <= 4 && ny >= 1 && ny <= 4 && (nx != shark_x || ny != shark_y) && dead_fish[nx][ny] == 0) {
						board[a][b].pop();
						board_move[nx][ny].push(direction);
						isMoved = true;
						break;
					}
					else {
						if (direction == 1)	direction = 8;
						else	direction--;
					}
				}
				if (!isMoved) {
					direction = board[a][b].front();
					board[a][b].pop();
					board_move[a][b].push(direction);
				}
			}
		}
	}
	//board_move�� �ӽ� ����� �������� ������ board�� �̵�
	for (int a = 1; a <= 4; a++) {
		for (int b = 1; b <= 4; b++) {
			while (!board_move[a][b].empty()) {
				board[a][b].push(board_move[a][b].front());
				board_move[a][b].pop();
			}
		}
	}
}

void step3() {
	int move_direction[3];
	//DFS�� ���� ����� �̵� ���� ����
	DFS(move_direction, 0, shark_x, shark_y);
	//�� �̵��� ������ ����� ���ܽ�Ű�� ����� ���� �ʱ�ȭ
	for (int a = 0; a < 3; a++) {
		if (shark_move[a] == 1)	shark_x--;
		else if (shark_move[a] == 2)	shark_y--;
		else if (shark_move[a] == 3)	shark_x++;
		else	shark_y++;

		if (board[shark_x][shark_y].empty())	continue;
		else {
			while (!board[shark_x][shark_y].empty())	board[shark_x][shark_y].pop();
			dead_fish[shark_x][shark_y] = 3;
		}
	}
}

void DFS(int move_direction[3], int index, int x, int y) {
	int dead_fish_num = 0, nx = shark_x, ny = shark_y, visited[5][5];
	//����� �̵� ������ �� ������ ��� �� ������ ����⸦ ���ܽ�Ű���� ����ϰ� ���� ���� ���ܽ�Ű�� ��� shark_move�� max_dead_fish ����
	if (index == 3) {
		for (int a = 1; a <= 4; a++) {
			for (int b = 1; b <= 4; b++) {
				visited[a][b] = 0;
			}
		}
		//�� ���ܽ�Ű�� ����� ���� ���
		for (int a = 0; a < 3; a++) {
			if (move_direction[a] == 1)	nx--;
			else if (move_direction[a] == 2)	ny--;
			else if (move_direction[a] == 3)	nx++;
			else	ny++;

			if (visited[nx][ny] == 0) {
				dead_fish_num += board[nx][ny].size();
				visited[nx][ny] = 1;
			}
		}
		//���� ���� ���ܽ�Ű�� ��� 
		if (dead_fish_num > max_dead_fish) {
			shark_move[0] = move_direction[0];
			shark_move[1] = move_direction[1];
			shark_move[2] = move_direction[2];
			max_dead_fish = dead_fish_num;
		}
		return;
	}
	//����� �̵� ������ �� �������� ���� ��� �������� ���� DFS ����
	if (x - 1 >= 1) {
		move_direction[index] = 1;
		DFS(move_direction, index + 1, x - 1, y);
	}
	if (y - 1 >= 1) {
		move_direction[index] = 2;
		DFS(move_direction, index + 1, x, y - 1);
	}
	if (x + 1 <= 4) {
		move_direction[index] = 3;
		DFS(move_direction, index + 1, x + 1, y);
	}
	if (y + 1 <= 4) {
		move_direction[index] = 4;
		DFS(move_direction, index + 1, x, y + 1);
	}
	return;
}

void step4() {
	//����� ������ 1�� ����
	for (int a = 1; a <= 4; a++) {
		for (int b = 1; b <= 4; b++) {
			if (dead_fish[a][b] > 0)	dead_fish[a][b]--;
		}
	}
	return;
}

void step5() {
	//step1���� ���� board_magic�� ���� ����⸦ board�� �߰�
	for (int a = 1; a <= 4; a++) {
		for (int b = 1; b <= 4; b++) {
			while (!board_magic[a][b].empty()) {
				board[a][b].push(board_magic[a][b].front());
				board_magic[a][b].pop();
			}
		}
	}
	return;
}