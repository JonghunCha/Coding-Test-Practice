/*
문제 링크 : https://swexpertacademy.com/main/main.do
단순한 완전 탐색 문제다.

board의 상태를 일일히 확인하고 상태에 맞는 출력을 해주면 된다.
*/
#include <cstdio>

using namespace std;

bool is_A_won(char board[4][4], char A);
bool is_draw(char board[4][4]);

int main(int argc, char** argv)
{
	int T;
	char board[4][4];
	
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장
		getchar();
		for (int a = 0; a < 4; a++) {
			for (int b = 0; b < 4; b++) {
				scanf("%c", &board[a][b]);
			}
			getchar();
		}
		//각 케이스에 따라 출력
		if (is_A_won(board, 'X')) {
			printf("#%d X won\n", test_case);
		}
		else if (is_A_won(board, 'O')) {
			printf("#%d O won\n", test_case);
		}
		else if (is_draw(board)) {
			printf("#%d Draw\n", test_case);
		}
		else {
			printf("#%d Game has not completed\n", test_case);
		}
	}
	return 0;
}
//현재 board의 상태가 A가 이긴 것인지 확인
bool is_A_won(char board[4][4], char A) {
	bool is_end;
	//가로로 연속해서 A혹은 'T'로만 이루어 졌는지 확인
	for (int a = 0; a < 4; a++) {
		is_end = true;
		for (int b = 0; b < 4; b++) {
			if (board[a][b] != A && board[a][b] != 'T') {
				is_end = false;
				break;
			}
		}
		if (is_end)		return true;
	}
	//세로로 연속해서 A혹은 'T'로만 이루어 졌는지 확인
	for (int a = 0; a < 4; a++) {
		is_end = true;
		for (int b = 0; b < 4; b++) {
			if (board[b][a] != A && board[b][a] != 'T') {
				is_end = false;
				break;
			}
		}
		if (is_end)		return true;
	}
	//오른쪽 아래로 향하는 대각선에서 연속해서 A혹은 'T'로만 이루어 졌는지 확인
	is_end = true;
	for (int a = 0; a < 4; a++) {
		if (board[a][a] != A && board[a][a] != 'T') {
			is_end = false;
			break;
		}
	}
	if (is_end)	return true;
	//오른쪽 위로 향하는 대각선에서 연속해서 A혹은 'T'로만 이루어 졌는지 확인
	is_end = true;
	for (int a = 0; a < 4; a++) {
		if (board[a][3 - a] != A && board[a][3 - a] != 'T') {
			is_end = false;
			break;
		}
	}
	if (is_end)	return true;

	return false;
}
//X와 O가 비긴 상태인지 확인
bool is_draw(char board[4][4]) {
	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 4; b++) {
			if (board[a][b] == '.') {
				return false;
			}
		}
	}

	return true;
}