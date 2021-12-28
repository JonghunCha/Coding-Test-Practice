/*
문제 링크 : https://www.acmicpc.net/problem/17837
단순 구현 시뮬레이션 문제이다.

한 가지 고려해야 할 상황은 같은 칸에 말이 서로 겹치는 경우인데, vector를 이용하면 이 부분을 쉽게 처리할 수 있다.
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
	vector<int> board_piece[13][13];	//각 좌표에 있는 말들을 아래에서부터 순서대로 저장
	//입력값 저장
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
	//최대 1000턴까지 진행
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
	//이동하려는 칸이 흰색 칸인 경우
	if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && board[nx][ny] == 0) {
		for (int a = 0; a < board_piece[x][y].size(); a++) {
			//아래에서 부터 살피며 index에 해당하는 말을 찾는다
			if (board_piece[x][y][a] == index)	flag = true;
			if (flag) {
				//이동하는 칸의 vector에 추가
				board_piece[nx][ny].emplace_back(board_piece[x][y][a]);
				//말의 위치 정보 갱신
				piece[board_piece[x][y][a]][0] = nx;
				piece[board_piece[x][y][a]][1] = ny;
				//기존의 칸에서 제거
				board_piece[x][y].erase(board_piece[x][y].begin() + a);
				a--;
				if (board_piece[nx][ny].size() >= 4) {
					Game_End = true;
					return;
				}
			}
		}
	}
	//이동하려는 칸이 빨간색 칸인 경우
	else if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && board[nx][ny] == 1) {
		for (int a = board_piece[x][y].size() - 1; a >= 0; a--) {
			//위에서 부터 살피며 index에 해당하는 말까지 옮긴다
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
	//이동하려는 칸이 파란색 칸인 경우
	else {
		//first가 true인 것은 파란색 벽을 처음 만났음을 의미. 따라서 방향 바꾸고 Move_Piece를 다시 호출(이 때 first는 false로 지정)
		if (first == true) {
			if (direction == 1)	piece[index][2] = 2;
			else if (direction == 2)	piece[index][2] = 1;
			else if (direction == 3)	piece[index][2] = 4;
			else	piece[index][2] = 3;
			Move_Piece(N, board, piece, board_piece, index, false);
		}
	}
}