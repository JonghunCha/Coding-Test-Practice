/*
문제 링크 : https://swexpertacademy.com/main/main.do
완전 탐색으로 해결할 수 있는 문제다.

기준을 가장 위에 있는 카페로 잡고 차례대로 (왼쪽 아래), (오른쪽 아래), (오른쪽 위), (왼쪽 위)로 진행하여 처음 카페로 올 수 있는 모든 경우에 대해 고려하였다.

코드를 보면 쉽게 이해할 수 있다.
*/
#include <cstdio>
#include <algorithm>
#include <unordered_set>
using namespace std;

int dx[4] = { 1, 1, -1, -1 }, dy[4] = { -1, 1, 1, -1 };
int get_max_path(int N, int board[20][20], int x, int y, int max_sum, int max_len_1, int max_len_2);

int main() {
	int T, N, board[20][20], answer, count;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		//입력값 저장 및 변수 초기화
		scanf("%d", &N);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				scanf("%d", &board[a][b]);
			}
		}
		answer = 0;
		//시작점으로 가능한 모든 (a, b)좌표에 대해 완전 탐색
		for (int a = 0; a < N - 2; a++) {
			for (int b = 1; b < N - 1; b++) {
				count = get_max_path(N, board, a, b, N - a - 1, b, N -b - 1);
				if (count > answer)	answer = count;
			}
		}

		if (answer == 0)	answer = -1;
		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}

int get_max_path(int N, int board[20][20], int x, int y, int max_sum, int max_len_1, int max_len_2) {
	int ret = 0, nx, ny;
	unordered_set<int> s;
	bool flag;
	//a는 (왼쪽 아래, 오른쪽 위)로 진행할 거리, b는 (오른쪽 아래, 왼쪽 위)로 진행할 거리를 의미
	for (int a = 1; a <= max_len_1; a++) {	
		for (int b = 1; b <= min(max_len_2, max_sum - a); b++) {
			s.clear();
			nx = x;
			ny = y;
			flag = true;
			//왼쪽 아래 방향 진행
			for (int count = 1; count <= a; count++) {
				nx += dx[0];
				ny += dy[0];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N && s.find(board[nx][ny]) == s.end()){	//이미 지나온 카페와 같은 종류의 디저트가 아닌 경우 set에 추가
					s.insert(board[nx][ny]);
				}
				else {	//좌표를 벗어나거나 같은 종류의 디저트일 경우 실패
					flag = false;
					break;
				}
			}
			if (!flag)	continue;
			//오른쪽 아래 방향 진행
			for (int count = 1; count <= b; count++) {
				nx += dx[1];
				ny += dy[1];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N && s.find(board[nx][ny]) == s.end()) {
					s.insert(board[nx][ny]);
				}
				else {
					flag = false;
					break;
				}
			}
			if (!flag)	continue;
			//오른쪽 위 방향 진행
			for (int count = 1; count <= a; count++) {
				nx += dx[2];
				ny += dy[2];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N && s.find(board[nx][ny]) == s.end()) {
					s.insert(board[nx][ny]);
				}
				else {
					flag = false;
					break;
				}
			}
			if (!flag)	continue;
			//왼쪽 위 방향 진행
			for (int count = 1; count <= b; count++) {
				nx += dx[3];
				ny += dy[3];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N && s.find(board[nx][ny]) == s.end()) {
					s.insert(board[nx][ny]);
				}
				else {
					flag = false;
					break;
				}
			}
			if (!flag)	continue;

			if (s.size() > ret)	ret = s.size();
		}
	}

	return ret;
}