/*
문제 링크 : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRQm6qfL0DFAUo
완전탐색으로 해결할 수 있는 문제다.

구슬은 최대 4개를 떨어뜨릴 수 있고 폭은 최대 12이다. 따라서 12^4 = 약 2만번의 조합을 다 탐색하고 그 중 가장 벽돌을 적게 남기는 것을 구하면 된다.
*/
#include <iostream>

using namespace std;

int answer;

//index 번째에 구슬을 떨어뜨릴 위치를 정하고, N개의 구슬에 대해 모두 정하였다면 Bread_Start를 호출
void Get_Answer(int N, int W, int H, int board[15][12], int order[4], int index);
//N개의 구슬을 차례로 떨어트린다. 떨어트린 뒤 벽돌을 부수는 Bread_Spread함수를 호출하고, 끝난 뒤엔 Drop_Brick을 호출하여 벽돌을 아래로 떨어트린다
void Break_Start(int N, int W, int H, int board[15][12], int order[4]);
//x, y 위치의 벽돌을 부수고 만약 1보다 큰 벽돌이면 주변의 벽돌에 대해서도 Bread_Spread를 호출
void Break_Spread(int W, int H, int nboard[15][12], int x, int y);
//모든 벽돌을 부순 뒤 벽돌들을 아래로 떨어트리는 함수
void Drop_Brick(int W, int H, int nboard[15][12]);

int main(int argc, char** argv)
{
	int T, N, W, H, board[15][12], order[4];
	
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장
		cin >> N >> W >> H;
		for (int a = 0; a < H; a++) {
			for (int b = 0; b < W; b++) {
				cin >> board[a][b];
			}
		}
		answer = W * H;
		Get_Answer(N, W, H, board, order, 0);
		cout << '#' << test_case << ' ' << answer << endl;
	}
	return 0;
}

void Get_Answer(int N, int W, int H, int board[15][12], int order[4], int index) {
	if (index == N) {	//N개 구슬을 떨어트릴 위치를 다 정한 경우
		Break_Start(N, W, H, board, order);
		return;
	}

	for (int a = 0; a < W; a++) {	//index번째의 구슬을 어느 위치에서 떨어트릴지 정한다
		order[index] = a;
		Get_Answer(N, W, H, board, order, index + 1);
	}
	return;
}

void Break_Start(int N, int W, int H, int board[15][12], int order[4]) {
	int nboard[15][12], remain_bricks = 0;

	for (int a = 0; a < H; a++) {
		for (int b = 0; b < W; b++) {
			nboard[a][b] = board[a][b];
		}
	}
	//N개의 구슬을 떨어트리며 벽돌을 부수고 다 부순 뒤엔 아래로 떨어트린다
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < H; b++) {
			if (nboard[b][order[a]] != 0) {
				Break_Spread(W, H, nboard, b, order[a]);
				Drop_Brick(W, H, nboard);
				break;
			}
		}
	}
	//남아있는 벽돌의 수를 계산하고 가장 적게 남았다면 answer 갱신
	for (int a = 0; a < H; a++) {
		for (int b = 0; b < W; b++) {
			if (nboard[a][b] != 0)	remain_bricks++;
		}
	}
	if (remain_bricks < answer)	answer = remain_bricks;
	return;
}

void Break_Spread(int W, int H, int nboard[15][12], int x, int y) {
	int num = nboard[x][y];

	nboard[x][y] = 0;	//벽돌을 부수고 0으로 만든다
	for (int a = 1; a < num; a++) {	//num이 2 이상인 경우 근처의 벽돌도 문제의 룰에 따라 부순다
		if (x + a < H) {
			if (nboard[x + a][y] > 1)	Break_Spread(W, H, nboard, x + a, y);
			else	nboard[x + a][y] = 0;
		}
		if (x - a >= 0) {
			if (nboard[x - a][y] > 1)	Break_Spread(W, H, nboard, x - a, y);
			else	nboard[x - a][y] = 0;
		}
		if (y + a < W) {
			if (nboard[x][y + a] > 1)	Break_Spread(W, H, nboard, x, y + a);
			else	nboard[x][y + a] = 0;
		}
		if (y - a >= 0) {
			if (nboard[x][y - a] > 1)	Break_Spread(W, H, nboard, x, y - a);
			else	nboard[x][y - a] = 0;
		}
	}
}

void Drop_Brick(int W, int H, int nboard[15][12]) {
	int index;

	for (int a = 0; a < W; a++) {
		index = H - 1;
		for (int b = H - 1; b >= 0; b--) {
			if (nboard[b][a] != 0 && b == index)	index--;
			else if (nboard[b][a] != 0 && b != index) {
				nboard[index][a] = nboard[b][a];
				nboard[b][a] = 0;
				index--;
			}
		}
	}
}