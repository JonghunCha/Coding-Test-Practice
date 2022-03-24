/*
문제 링크 : https://swexpertacademy.com/main/main.do
문제 난이도는 어렵지 않았다. 

그러나 시뮬레이션 코드는 항상 길어져서 디버깅이 힘들기 때문에 항상 기능별로 모듈화 시켜 디버깅이 용이하게 해야겠다.
*/
#include <cstdio>
using namespace std;

int main(void) {
	int T, N, X, board[20][20], answer = 0, height, num;
	bool flag;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		//입력값 저장
		scanf("%d %d", &N, &X);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				scanf("%d", &board[a][b]);
			}
		}
		//가로 경우의 수 체크
		answer = 0;
		for (int a = 0; a < N; a++) {
			height = board[a][0];
			num = 1;
			for (int b = 1; b < N;) {	
				flag = true;
				if (board[a][b] == height) {	//높이가 같다면 높이를 유지하며 갯수 카운트만 늘려준다
					num++;
					b++;
				}
				else if (board[a][b] == height + 1) {	//현재까지의 높이보다 1 큰 경우
					if (num >= X) {	//이전까지 연속된 구간이 X보다 크가면 연결 가능
						height = board[a][b];
						num = 1;
						b++;
					}
					else {	//그렇지 않은 경우 
						flag = false;
						break;
					}
				}
				else if (board[a][b] == height - 1) {	//현재까지의 높이보다 1 작은 경우
					if (b + X > N) {	//만약 남은 구간이 X보다 작다면 연결 불가
						flag = false;
						break;
					}
					for (int c = b; c < b + X; c++) {	//다음 X개의 구간이 같은 높이인지 검사
						if (board[a][c] != height - 1) {
							flag = false;
							break;
						}
					}
					if (!flag)	break;	
					height = board[a][b];
					num = 0;
					b += X;
				}
				else {	//높이차이가 2 이상인 경우 항상 불가능
					flag = false;
					break;
				}
			}
			if (flag)	answer++;
		}
		//세로 경우의 수 체크
		for (int a = 0; a < N; a++) {
			height = board[0][a];
			num = 1;
			flag = true;
			for (int b = 1; b < N;) {
				if (board[b][a] == height) {
					num++;
					b++;
				}
				else if (board[b][a] == height + 1) {
					if (num >= X) {
						height = board[b][a];
						num = 1;
						b++;
					}
					else {
						flag = false;
						break;
					}
				}
				else if (board[b][a] == height - 1) {
					if (b + X > N) {
						flag = false;
						break;
					}
					for (int c = b; c < b + X; c++) {
						if (board[c][a] != height - 1) {
							flag = false;
							break;
						}
					}
					if (!flag)	break;
					height = board[b][a];
					num = 0;
					b += X;
				}
				else {
					flag = false;
					break;
				}
			}
			if (flag)	answer++;
		}

		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}