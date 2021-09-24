/*
문제 링크 : https://www.acmicpc.net/problem/15684
완전 탐색으로 해결할 수 있다.

추가하는 가로선의 최대 개수는 3개이다. 따라서 가로선을 추가하지 않는 경우, 1개 추가하는 경우, 2개 추가하는 경우, 3개 추가하는 경우, 총 4가지 경우를 순서대로 완전 탐색하며 문제의 조건을 만족하는 방법이 있는지 확인하면 된다.
*/
#include <iostream>
using namespace std;

int Get_Answer(int N, int H, int connected[31][11], int step, int select);
bool Simulate(int N, int H, int connected[31][11]);

int main(void) {
	int N, M, H, connected[31][11], x, y, temp;
	//입력값 저장
	cin >> N; cin >> M; cin >> H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			connected[i][j] = 0;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> x; cin >> y;
		connected[x][y] = 1;
	}
	//가로선을 0개~3개까지 추가하며 조건을 만족하는 방법이 있는지 확인
	for (int i = 0; i <= 3; i++) {
		temp = Get_Answer(N, H, connected, i, 0);
		if (temp != -1) {
			cout << temp;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
//step은 가로선을 몇 개 추가하기로 했는지를 의미, select는 현재까지 몇 개의 가로선을 추가했는지를 의미
int Get_Answer(int N, int H, int connected[31][11], int step, int select) {
	//가로선을 4개 이상 사용하는 경우는 없다
	if (step > 3)	return -1;
	//문제의 조건을 만족한 경우 step 반환
	if (step == select && Simulate(N, H, connected))	return step; 
	//가로선을 다 추가했지만 문제의 조건을 만족하지 못한 경우
	if (step == select && !Simulate(N, H, connected))	return -1;
	//가로선을 추가할 수 있는 모든 조합 생성
	int ret = -1, temp;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (connected[i][j] == 0) {
				if (j == 1 && connected[i][j + 1] == 0) {
					connected[i][j] = 1;
					temp = Get_Answer(N, H, connected, step, select + 1);
					if (temp > ret)	ret = temp;
					connected[i][j] = 0;
				}
				else if (j != 1 && connected[i][j - 1] == 0 && connected[i][j + 1] == 0) {
					connected[i][j] = 1;
					temp = Get_Answer(N, H, connected, step, select + 1);
					if (temp > ret)	ret = temp;
					connected[i][j] = 0;
				}
			}
		}
	}
	return ret;
}
//i번 세로선의 결과가 i번이 나오는지 확인
bool Simulate(int N, int H, int connected[31][11]) {
	int row, col;
	//모든 세로선에 대해 시뮬레이션
	for (int i = 1; i <= N; i++) {
		col = i;
		row = 1;
		while (1) {
			//사다리 끝까지 내려갔고 현재 col이 i번인 경우 통과
			if (row == H + 1 && col == i)	break;
			//그렇지 않은 경우 false 반환
			if (row == H + 1 && col != i)	return false;
			//주변의 사다리에 따라 col 이동
			if (col == 1) {
				if (connected[row][1] == 1)		col = 2;
			}
			else {
				if (connected[row][col - 1] == 1)	col = col - 1;
				else if (connected[row][col] == 1)	col = col + 1;
			}
			row++;
		}
	}
	return true;
}