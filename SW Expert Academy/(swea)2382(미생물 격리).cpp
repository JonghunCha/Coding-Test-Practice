/*
문제 링크 : https://swexpertacademy.com/main/main.do
단순 시뮬레이션 문제다.

문제의 조건에 따라 크게 3가지 파트로 나누었다.

1. 미생물 이동(board_copy에 저장)
2. 합쳐진 군집 처리(2개 이상의 군집이 모인 지점은 합쳐준다)
3. board_copy내용 board로 옮기기

코드를 보면 쉽게 이해할 수 있을 것이다.
*/
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int dx[5] = { 0, -1, 1, 0, 0 }, dy[5] = { 0, 0, 0, -1, 1 };

int main(void) {
	int T, N, M, K, x, y, num, direction, num_temp, direction_temp, size, num_max, answer;
	vector<pair<int, int>> board[100][100], board_copy[100][100];

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		//입력값 저장 및 변수 초기화
		scanf("%d %d %d", &N, &M, &K);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				board[a][b].clear();
				board_copy[a][b].clear();
			}
		}
		for (int a = 0; a < K; a++) {
			scanf("%d %d %d %d", &x, &y, &num, &direction);
			board[x][y].push_back(make_pair(num, direction));
		}

		for (int time = 0; time < M; time++) {
			//미생물 이동
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < N; b++) {
					if (board[a][b].size() > 0) {
						num = board[a][b][0].first;
						direction = board[a][b][0].second;
						x = a + dx[direction];
						y = b + dy[direction];
						if (x == 0 || y == 0 || x == N - 1 || y == N - 1) {	//약품 구역에 도달한 경우
							if (direction == 1)	direction = 2;
							else if (direction == 2)	direction = 1;
							else if (direction == 3)	direction = 4;
							else if (direction == 4)	direction = 3;
							board_copy[x][y].push_back(make_pair(num / 2, direction));
						}
						else {	//그 외 경우
							board_copy[x][y].push_back(make_pair(num, direction));
						}
						board[a][b].erase(board[a][b].begin());
					}
				}
			}
			//합쳐진 군집 처리
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < N; b++) {
					if (board_copy[a][b].size() > 1) {
						num = 0;
						size = board_copy[a][b].size();
						num_max = 0;
						for (int c = 0; c < size; c++) {
							num_temp = board_copy[a][b][c].first;
							direction_temp = board_copy[a][b][c].second;
							num += num_temp;
							if (num_temp > num_max) {
								num_max = num_temp;
								direction = direction_temp;
							}
						}
						for (int c = 0; c < size; c++) {
							board_copy[a][b].pop_back();
						}
						board_copy[a][b].push_back(make_pair(num, direction));
					}
				}
			}
			//board_copy내용 board로 옮기기
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < N; b++) {
					if (!board_copy[a][b].empty()) {
						num = board_copy[a][b][0].first;
						direction = board_copy[a][b][0].second;
						board[a][b].push_back(make_pair(num, direction));
						board_copy[a][b].pop_back();
					}
				}
			}
		}

		answer = 0;
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (!board[a][b].empty())	answer += board[a][b][0].first;
			}
		}
		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}