/*
문제 링크 : https://www.acmicpc.net/problem/23290
구현 시뮬레이션 문제다.

구현 문제는 난이도가 높지는 않지만 코드가 길어지면서 예외처리를 잘 하고 코드에 오류를 발생하지 않도록 하는게 중요하다.

별거아닌 실수 때문에 오랫동안 디버깅하게 된 문제..
*/
#include <iostream>
#include <queue>
using namespace std;

int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
//dead_fish는 각 좌표에 물고기 냄새가 얼마의 기간동안 유효한지 저장, shark_move는 step3에서 상어의 이동방향을 저장
int M, S, shark_x, shark_y, dead_fish[5][5], shark_move[3], max_dead_fish;
//board_magic은 step1에서 복제한 물고기 들을 저장, board_move는 step2에서 이동한 물고기를 임시 저장
queue<int> board[5][5], board_magic[5][5], board_move[5][5];

void step1();	//step1(복제마법)결과 board_magic에 저장
void step2();	//step2(물고기 이동)결과 board_move에 저장 한 후 다시 board에 복사
void step3();	//step3(상어의 이동)결과 board에 갱신
void DFS(int move_direction[3], int index, int x, int y);		//step3에서 가장 많은 물고기를 제외시키는 움직임 계산
void step4();	//step4(물고기 냄새의 기한 갱신)
void step5();	//step1에서 계산한 board_magic의 복제된 물고기를 board에 이동

int main(void) {
	int x, y, direction, answer = 0;
	//입력값 저장 및 변수 초기화
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
	//S번 반복
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
	//남은 물고기의 수 계산
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
	//현재 좌표에 있는 물고기를 step5에서 복제하기 위해 board_magic에 저장
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
	//각 물고기들을 이동시킨 결과를 board_move에 임시 저장
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
	//board_move에 임시 저장된 물고기들을 원래의 board에 이동
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
	//DFS를 통해 상어의 이동 방향 결정
	DFS(move_direction, 0, shark_x, shark_y);
	//상어가 이동한 지점의 물고기 제외시키고 물고기 냄새 초기화
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
	//상어의 이동 방향이 다 정해진 경우 몇 마리의 물고기를 제외시키는지 계산하고 가장 많이 제외시키는 경우 shark_move와 max_dead_fish 갱신
	if (index == 3) {
		for (int a = 1; a <= 4; a++) {
			for (int b = 1; b <= 4; b++) {
				visited[a][b] = 0;
			}
		}
		//상어가 제외시키는 물고기 갯수 계산
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
		//가장 많이 제외시키는 경우 
		if (dead_fish_num > max_dead_fish) {
			shark_move[0] = move_direction[0];
			shark_move[1] = move_direction[1];
			shark_move[2] = move_direction[2];
			max_dead_fish = dead_fish_num;
		}
		return;
	}
	//상어의 이동 방향이 다 정해지지 않은 경우 사전순에 따라 DFS 진행
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
	//물고기 냄새를 1씩 감소
	for (int a = 1; a <= 4; a++) {
		for (int b = 1; b <= 4; b++) {
			if (dead_fish[a][b] > 0)	dead_fish[a][b]--;
		}
	}
	return;
}

void step5() {
	//step1에서 만든 board_magic의 복제 물고기를 board에 추가
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