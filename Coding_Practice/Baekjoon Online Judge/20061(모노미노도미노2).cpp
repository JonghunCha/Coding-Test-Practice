/*
문제 링크 : https://www.acmicpc.net/problem/20061
단순 구현 문제다.

파란 보드와 초록 보드가 서로 독립적으로 동작하고 사실상 빨간보드는 큰 의미가 없기에 쉽게 구현할 수 있다.
*/
#include <iostream>
using namespace std;

int score = 0;

void Blue_Clear(int blue[4][6]);
void Green_Clear(int green[6][4]);
void Blue_Soft(int blue[4][6]);
void Green_Soft(int green[6][4]);

int main(void) {
	int N, t, x, y, blue[4][6], green[6][4], remain_block = 0;
	cin >> N;
	//파란보드 초록보드 초기화
	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 6; b++) {
			blue[a][b] = 0;
			green[b][a] = 0;
		}
	}
	//N번의 입력동안 시뮬레이션
	for (int i = 0; i < N; i++) {
		cin >> t; cin >> x; cin >> y;
		if (t == 1) {
			for (int a = 0; a < 6; a++) {
				if (blue[x][a] == 1) {
					blue[x][a - 1] = 1;
					break;
				}
				else if (a == 5)	blue[x][a] = 1;
			}
			for (int a = 0; a < 6; a++) {
				if (green[a][y] == 1) {
					green[a - 1][y] = 1;
					break;
				}
				else if (a == 5)	green[a][y] = 1;
			}
			Blue_Clear(blue);
			Green_Clear(green);
			Blue_Soft(blue);
			Green_Soft(green);
		}
		else if (t == 2) {
			for (int a = 0; a < 6; a++) {
				if (blue[x][a] == 1) {
					blue[x][a - 1] = 1;
					blue[x][a - 2] = 1;
					break;
				}
				else if (a == 5) {
					blue[x][a] = 1;
					blue[x][a - 1] = 1;
				}
			}
			for (int a = 0; a < 6; a++) {
				if (green[a][y] == 1 || green[a][y + 1] == 1) {
					green[a - 1][y] = 1;
					green[a - 1][y + 1] = 1;
					break;
				}
				else if (a == 5) {
					green[a][y] = 1;
					green[a][y + 1] = 1;
				}
			}
			Blue_Clear(blue);
			Green_Clear(green);
			Blue_Soft(blue);
			Green_Soft(green);
		}
		else {
			for (int a = 0; a < 6; a++) {
				if (blue[x][a] == 1 || blue[x + 1][a] == 1) {
					blue[x][a - 1] = 1;
					blue[x + 1][a - 1] = 1;
					break;
				}
				else if (a == 5) {
					blue[x][a] = 1;
					blue[x + 1][a] = 1;
				}
			}
			for (int a = 0; a < 6; a++) {
				if (green[a][y] == 1) {
					green[a - 1][y] = 1;
					green[a - 2][y] = 1;
					break;
				}
				else if (a == 5) {
					green[a][y] = 1;
					green[a - 1][y] = 1;
				}
			}
			Blue_Clear(blue);
			Green_Clear(green);
			Blue_Soft(blue);
			Green_Soft(green);
		}
	}
	for (int a = 0; a < 6; a++) {
		for (int b = 0; b < 4; b++) {
			if (blue[b][a] == 1)	remain_block++;
			if (green[a][b] == 1)	remain_block++;
		}
	}
	cout << score << endl;
	cout << remain_block << endl;

	return 0;
}
//파란 보드에서 한줄이 블록으로 꽉찬 경우 점수를 올리고 해당 줄을 없앤다
void Blue_Clear(int blue[4][6]) {
	for (int a = 5; a >= 0; a--) {
		if (blue[0][a] == 1 && blue[1][a] == 1 && blue[2][a] == 1 && blue[3][a] == 1) {
			for (int b = a; b > 0; b--) {
				blue[0][b] = blue[0][b - 1];
				blue[1][b] = blue[1][b - 1];
				blue[2][b] = blue[2][b - 1];
				blue[3][b] = blue[3][b - 1];
			}
			blue[0][0] = 0;
			blue[1][0] = 0;
			blue[2][0] = 0;
			blue[3][0] = 0;
			a++;
			score++;
		}
	}
}
//초록 보드에서 한줄이 블록으로 꽉찬 경우 점수를 올리고 해당 줄을 없앤다
void Green_Clear(int green[6][4]) {
	for (int a = 5; a >= 0; a--) {
		if (green[a][0] == 1 && green[a][1] == 1 && green[a][2] == 1 && green[a][3] == 1) {
			for (int b = a; b > 0; b--) {
				green[b][0] = green[b - 1][0];
				green[b][1] = green[b - 1][1];
				green[b][2] = green[b - 1][2];
				green[b][3] = green[b - 1][3];
			}
			green[0][0] = 0;
			green[0][1] = 0;
			green[0][2] = 0;
			green[0][3] = 0;
			a++;
			score++;
		}
	}
}
//파란 보드에서 연한 부분에 블록이 있는 경우 해결
void Blue_Soft(int blue[4][6]) {
	for (int a = 0; a < 2; a++) {
		for (int b = 0; b < 4; b++) {
			if (blue[b][a] == 1) {
				for (int c = 5; c > 0; c--) {
					blue[0][c] = blue[0][c - 1];
					blue[1][c] = blue[1][c - 1];
					blue[2][c] = blue[2][c - 1];
					blue[3][c] = blue[3][c - 1];
				}
				blue[0][0] = 0;
				blue[1][0] = 0;
				blue[2][0] = 0;
				blue[3][0] = 0;
				Blue_Soft(blue);
			}
		}
	}
}
//초록 보드에서 연한 부분에 블록이 있는 경우 해결
void Green_Soft(int green[6][4]) {
	for (int a = 0; a < 2; a++) {
		for (int b = 0; b < 4; b++) {
			if (green[a][b] == 1) {
				for (int c = 5; c > 0; c--) {
					green[c][0] = green[c - 1][0];
					green[c][1] = green[c - 1][1];
					green[c][2] = green[c - 1][2];
					green[c][3] = green[c - 1][3];
				}
				green[0][0] = 0;
				green[0][1] = 0;
				green[0][2] = 0;
				green[0][3] = 0;
				Green_Soft(green);
			}
		}
	}
}