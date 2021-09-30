/*
문제 링크 : https://www.acmicpc.net/problem/13460
완전 탐색으로 해결 할 수 있는 문제다.

다만 문제 조건에서 빨간 공이 먼저 빠지더라도 파란 공도 빠지면 실패한 경우이니 이 부분만 예외 처리 잘 하면 된다.
*/
#include <iostream>
using namespace std;

bool Make_Combination(int N, int M, char board[10][10], int direction[11], int step, int index);
bool Try_Game(int N, int M, char board[10][10], int direction[11], int step);

int main(void) {
	int N, M;
	char board[10][10];
	//0 = 아직 결정 안됨, 1 = 위로 기울이기, 2 = 오른쪽으로 기울이기, 3 = 아래로 기울기기, 4 = 왼쪽으로 기울이기
	int direction[11];
	//입력값 저장
	cin >> N; cin >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	//움직임의 횟수가 1~10까지 조합을 탐색한다
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j <= 10; j++) direction[j] = 0;
		if (Make_Combination(N, M, board, direction, i, 1)) {
			cout << i;
			return 0;
		}
	}

	cout << -1;
	return 0;
}
//step번 만큼 이동한다고 할 때 가능한 모든 조합에 대해 Try_Game호출
bool Make_Combination(int N, int M, char board[10][10], int direction[12], int step, int index) {
	if (index > step) {
		if (Try_Game(N, M, board, direction, step))	return true;
		return false;
	}
	direction[index] = 1;
	if (Make_Combination(N, M, board, direction, step, index + 1))	return true;
	direction[index] = 2;
	if (Make_Combination(N, M, board, direction, step, index + 1))	return true;
	direction[index] = 3;
	if (Make_Combination(N, M, board, direction, step, index + 1))	return true;
	direction[index] = 4;
	if (Make_Combination(N, M, board, direction, step, index + 1))	return true;
	return false;
}
//방향과 이동 횟수가 정해졌을 때 조건에 맞게 성공하는지 실패하는지 반환
bool Try_Game(int N, int M, char board[10][10], int direction[12], int step) {
	char board_copy[10][10];
	int temp, flag;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board_copy[i][j] = board[i][j];
		}
	}
	//flag가 0이면 빨간공이 빠져 나가지 못한 상태이고, 1이면 빠져 나간 상태
	flag = 0;
	for (int i = 1; i <= step; i++) {
		//위로 기울이는 경우
		if (direction[i] == 1) {
			for (int a = 1; a < N - 1; a++) {
				for (int b = 1; b < M - 1; b++) {
					if (board_copy[a][b] == 'R') {
						temp = a;
						while (1) {
							if (board_copy[temp - 1][b] == '#' || board_copy[temp - 1][b] == 'B') {
								board_copy[a][b] = '.';
								board_copy[temp][b] = 'R';
								break;
							}
							else if (board_copy[temp - 1][b] == '.')	temp--;
							else {
								flag = 1;
								board_copy[a][b] = '.';
								break;
							}
						}
					}
					else if (board_copy[a][b] == 'B') {
						temp = a;
						while (1) {
							if (board_copy[temp - 1][b] == '#' || board_copy[temp - 1][b] == 'R') {
								board_copy[a][b] = '.';
								board_copy[temp][b] = 'B';
								break;
							}
							else if (board_copy[temp - 1][b] == '.')	temp--;
							else return false;
						}
					}
				}
			}
		}
		//오른쪽으로 기울이는 경우
		else if (direction[i] == 2) {
			for (int a = 1; a < N - 1; a++){
				for (int b = M - 2; b > 0; b--) {
					if (board_copy[a][b] == 'R') {
						temp = b;
						while (1) {
							if (board_copy[a][temp + 1] == '#' || board_copy[a][temp + 1] == 'B') {
								board_copy[a][b] = '.';
								board_copy[a][temp] = 'R';
								break;
							}
							else if (board_copy[a][temp + 1] == '.')	temp++;
							else {
								flag = 1;
								board_copy[a][b] = '.';
								break;
							}
						}
					}
					if (board_copy[a][b] == 'B') {
						temp = b;
						while (1) {
							if (board_copy[a][temp + 1] == '#' || board_copy[a][temp + 1] == 'R') {
								board_copy[a][b] = '.';
								board_copy[a][temp] = 'B';
								break;
							}
							else if (board_copy[a][temp + 1] == '.')	temp++;
							else return false;
						}
					}
				}
			}
		}
		//아래로 기울이는 경우
		else if (direction[i] == 3) {
			for (int a = N - 2; a > 0; a--) {
				for (int b = 1; b < M - 1; b++) {
					if (board_copy[a][b] == 'R') {
						temp = a;
						while (1) {
							if (board_copy[temp + 1][b] == '#' || board_copy[temp + 1][b] == 'B') {
								board_copy[a][b] = '.';
								board_copy[temp][b] = 'R';
								break;
							}
							else if (board_copy[temp + 1][b] == '.')	temp++;
							else {
								flag = 1;
								board_copy[a][b] = '.';
								break;
							}
						}
					}
					if (board_copy[a][b] == 'B') {
						temp = a;
						while (1) {
							if (board_copy[temp + 1][b] == '#' || board_copy[temp + 1][b] == 'R') {
								board_copy[a][b] = '.';
								board_copy[temp][b] = 'B';
								break;
							}
							else if (board_copy[temp + 1][b] == '.')	temp++;
							else return false;
						}
					}
				}
			}
		}
		//왼쪽으로 기울이는 경우
		else {
			for (int a = 1; a < N - 1; a++) {
				for (int b = 1; b < M - 1; b++) {
					if (board_copy[a][b] == 'R') {
						temp = b;
						while (1) {
							if (board_copy[a][temp - 1] == '#' || board_copy[a][temp - 1] == 'B') {
								board_copy[a][b] = '.';
								board_copy[a][temp] = 'R';
								break;
							}
							else if (board_copy[a][temp - 1] == '.')	temp--;
							else {
								flag = 1;
								board_copy[a][b] = '.';
								break;
							}
						}
					}
					if (board_copy[a][b] == 'B') {
						temp = b;
						while (1) {
							if (board_copy[a][temp - 1] == '#' || board_copy[a][temp - 1] == 'R') {
								board_copy[a][b] = '.';
								board_copy[a][temp] = 'B';
								break;
							}
							else if (board_copy[a][temp - 1] == '.')	temp--;
							else return false;
						}
					}
				}
			}
		}
	}
	if (flag == 1)	return true;
	return false;
}