/*
문제 링크 : https://swexpertacademy.com/main/main.do
DFS를 이용한 완전 탐색으로 해결할 수 있는 문제다.

가장 먼저 최대 높이의 봉우리의 위치를 저장한다.

그런 다음 각 최대 높이 봉우리를 시작으로 하여 가장 긴 등산로를 구하면 된다.

그런데 한 지점을 최대 K만큼 깎을 수 있다고 하였기에 시작 지점을 제외한 나머지 지역을 0~K만큼 깎았을 경우에 대해 완전 탐색을 진행하면 된다.

가장 긴 등산로를 구하는 것은 DFS를 기반으로 구현하였다.
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

int get_max_length(int N, int K, int board[8][8], int x, int y);
int simulation(int N, int board[8][8], int x, int y, int length);

int main(void) {
	int T, N, K, board[8][8], highest, x, y, answer, curr_length;
	vector<pair<int, int>> highest_coordinate;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		//입력값 저장 및 변수 초기화
		scanf("%d %d", &N, &K);
		highest = 0;
		highest_coordinate.clear();
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				scanf("%d", &board[a][b]);
				if (board[a][b] > highest)	highest = board[a][b];
			}
		}
		//가장 높은 봉우리 벡터에 저장
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (board[a][b] == highest)	highest_coordinate.push_back(make_pair(a, b));
			}
		}
		//모든 가장 높은 봉우리를 시작으로 최대 길이 등산로 구하기
		answer = 0;
		for (int a = 0; a < highest_coordinate.size(); a++) {
			x = highest_coordinate[a].first;
			y = highest_coordinate[a].second;
			curr_length = get_max_length(N, K, board, x, y);
			if (curr_length > answer)	answer = curr_length;
		}

		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}

//시작 지점이 아닌 모든 지점을 0~K만큼 깎은 뒤 DFS기반의 함수 simulation을 통해 최대 등산로를 구한다.
int get_max_length(int N, int K, int board[8][8], int x, int y) {
	int ret = 0, curr_length;

	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (a != x || b != y) {
				for (int c = 0; c <= K; c++) {
					board[a][b] -= c;
					curr_length = simulation(N, board, x, y, 1);
					if (curr_length > ret)	ret = curr_length;
					board[a][b] += c;
				}
			}
		}
	}

	return ret;
}

//x, y지점에서 등산로를 만들 수 있는 모든 지점을 탐색하며 현재까지의 등산로 길이를 length에 저장하여 전달한다.
int simulation(int N, int board[8][8], int x, int y, int length) {
	int nx, ny, ret = 0, curr_length;
	bool is_end = true;

	for (int a = 0; a < 4; a++) {
		nx = x + dx[a];
		ny = y + dy[a];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && board[nx][ny] < board[x][y]) {
			curr_length = simulation(N, board, nx, ny, length + 1);
			is_end = false;
			if (curr_length > ret)	ret = curr_length;
		}
	}
	
	if (is_end)	return length;
	return ret;
}