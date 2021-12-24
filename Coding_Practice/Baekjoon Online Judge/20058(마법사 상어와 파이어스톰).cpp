/*
문제 링크 : https://www.acmicpc.net/problem/20058
단순 구현 문제다.

구현해야 할 기능은 아래와 같다.

1. 배열을 회전 시키는 함수
2. 얼음이 있는 인접한 칸이 3개 미만일 경우 얼음의 양을 줄이는 함수
3. 얼음이 연결된 칸의 집합(문제에서는 덩어리라 칭함)을 구하는 함수
*/
#include <iostream>
using namespace std;

int ccount = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int Get_Width(int N);
void Rotate(int board[64][64], int x, int y, int length);
void Update_Ice(int board[64][64], int width);
int Make_Neighbor(int board[64][64], int width);
void Search_Neighbor(int board[64][64], int width, int x, int y, int index);

int main(void) {
	int N, Q, board[64][64], L[1000], width, width_part, answer1 = 0, answer2 = 0, neighbor_num, temp;
	//입력값 저장
	cin >> N; cin >> Q;
	width = Get_Width(N);
	for (int a = 0; a < width; a++) {
		for (int b = 0; b < width; b++) {
			cin >> board[a][b];
		}
	}
	for (int a = 0; a < Q; a++) {
		cin >> L[a];
	}
	//Q번동안 파이어스톰 시전
	for (int a = 0; a < Q; a++) {
		width_part = Get_Width(L[a]);
		//각 부분 격자들을 회전시킨다
		for (int b = 0; b < width; b += width_part) {
			for (int c = 0; c < width; c += width_part) {
				for (int d = 0; d < Get_Width(L[a] - 1); d++) {
					Rotate(board, b + d, c + d, Get_Width(L[a]) - 2 * d);
				}
			}
		}
		//얼음의 양이 줄어들어야 하는 부분 갱신
		Update_Ice(board, width);
	}
	//전체 얼음의 양 계산
	for (int a = 0; a < width; a++) {
		for (int b = 0; b < width; b++) {
			answer1 += board[a][b];
		}
	}
	//board를 각각 덩어리로 나눈다
	neighbor_num = Make_Neighbor(board, width);
	for (int a = 1; a <= neighbor_num; a++) {
		temp = 0;
		for (int b = 0; b < width; b++) {
			for (int c = 0; c < width; c++) {
				if (board[b][c] == a + 100)	temp++;
			}
		}
		if (temp > answer2)	answer2 = temp;
	}
	cout << answer1 << endl << answer2 << endl;

	return 0;
}
//2의 N승을 반환하는 함수
int Get_Width(int N) {
	if (N < 0)	return -1;
	int ret = 1;
	for (int a = 0; a < N; a++) {
		ret = ret * 2;
	}
	return ret;
}
//격자판을 회전시키는 함수
void Rotate(int board[64][64], int x, int y, int length) {
	int temp[4][64];
	for (int a = 0; a < length - 1; a++) {
		temp[0][a] = board[x][y + a];
		temp[1][a] = board[x + a][y + length - 1];
		temp[2][a] = board[x + length - 1][y + length - 1 - a];
		temp[3][a] = board[x + length - 1 - a][y];
	}
	for (int a = 0; a < length - 1; a++) {
		board[x + a][y + length - 1] = temp[0][a];
		board[x + length - 1][y + length - 1 - a] = temp[1][a];
		board[x + length - 1 - a][y] = temp[2][a];
		board[x][y + a] = temp[3][a];
	}
}
//얼음의 양을 줄이는 함수
void Update_Ice(int board[64][64], int width) {
	int count_near, nx, ny, new_board[64][64];
	for (int a = 0; a < width; a++) {
		for (int b = 0; b < width; b++) {
			if (board[a][b] > 0) {
				count_near = 0;
				for (int c = 0; c < 4; c++) {
					nx = a + dx[c];
					ny = b + dy[c];
					if (nx >= 0 && nx < width && ny >= 0 && ny < width && board[nx][ny] > 0)	count_near++;
				}
				if (count_near >= 3)	new_board[a][b] = board[a][b];
				else	new_board[a][b] = board[a][b] - 1;
			}
			else	new_board[a][b] = board[a][b];
		}
	}
	for (int a = 0; a < width; a++) {
		for (int b = 0; b < width; b++) {
			board[a][b] = new_board[a][b];
		}
	}
}
//격자판에서 서로 연결된 얼음의 집합을 구하는 함수
int Make_Neighbor(int board[64][64], int width) {
	int neighbor_num = 0;

	for (int a = 0; a < width; a++) {
		for (int b = 0; b < width; b++) {
			if (board[a][b] > 0 && board[a][b] <= 100) {
				neighbor_num++;
				board[a][b] = 100 + neighbor_num;
				Search_Neighbor(board, width, a, b, neighbor_num);
			}
		}
	}
	return neighbor_num;
}
//x, y가 index번호에 해당하는 집합일 경우 그와 인접한 4방향의 칸 확인
void Search_Neighbor(int board[64][64], int width, int x, int y, int index) {
	int nx, ny;
	for (int a = 0; a < 4; a++) {
		nx = x + dx[a];
		ny = y + dy[a];
		if (nx >= 0 && nx < width && ny >= 0 && ny < width && board[nx][ny] > 0 && board[nx][ny] <= 100) {
			board[nx][ny] = 100 + index;
			Search_Neighbor(board, width, nx, ny, index);
		}
	}
}