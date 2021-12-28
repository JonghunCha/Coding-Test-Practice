/*
���� ��ũ : https://swexpertacademy.com/main/main.do
����Ž������ �ذ��� �� �ִ� ������.

������ �ִ� 4���� ����߸� �� �ְ� ���� �ִ� 12�̴�. ���� 12^4 = �� 2������ ������ �� Ž���ϰ� �� �� ���� ������ ���� ����� ���� ���ϸ� �ȴ�.
*/
#include <iostream>

using namespace std;

int answer;

//index ��°�� ������ ����߸� ��ġ�� ���ϰ�, N���� ������ ���� ��� ���Ͽ��ٸ� Bread_Start�� ȣ��
void Get_Answer(int N, int W, int H, int board[15][12], int order[4], int index);
//N���� ������ ���ʷ� ����Ʈ����. ����Ʈ�� �� ������ �μ��� Bread_Spread�Լ��� ȣ���ϰ�, ���� �ڿ� Drop_Brick�� ȣ���Ͽ� ������ �Ʒ��� ����Ʈ����
void Break_Start(int N, int W, int H, int board[15][12], int order[4]);
//x, y ��ġ�� ������ �μ��� ���� 1���� ū �����̸� �ֺ��� ������ ���ؼ��� Bread_Spread�� ȣ��
void Break_Spread(int W, int H, int nboard[15][12], int x, int y);
//��� ������ �μ� �� �������� �Ʒ��� ����Ʈ���� �Լ�
void Drop_Brick(int W, int H, int nboard[15][12]);

int main(int argc, char** argv)
{
	int T, N, W, H, board[15][12], order[4];
	
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ����
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
	if (index == N) {	//N�� ������ ����Ʈ�� ��ġ�� �� ���� ���
		Break_Start(N, W, H, board, order);
		return;
	}

	for (int a = 0; a < W; a++) {	//index��°�� ������ ��� ��ġ���� ����Ʈ���� ���Ѵ�
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
	//N���� ������ ����Ʈ���� ������ �μ��� �� �μ� �ڿ� �Ʒ��� ����Ʈ����
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < H; b++) {
			if (nboard[b][order[a]] != 0) {
				Break_Spread(W, H, nboard, b, order[a]);
				Drop_Brick(W, H, nboard);
				break;
			}
		}
	}
	//�����ִ� ������ ���� ����ϰ� ���� ���� ���Ҵٸ� answer ����
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

	nboard[x][y] = 0;	//������ �μ��� 0���� �����
	for (int a = 1; a < num; a++) {	//num�� 2 �̻��� ��� ��ó�� ������ ������ �꿡 ���� �μ���
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