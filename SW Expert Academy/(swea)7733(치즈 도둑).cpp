/*
문제 링크 : https://swexpertacademy.com/main/main.do
완전 탐색을 통해 서로 연결된 지역의 갯수를 파악하는 문제다.

서로 인접한 지역은 DFS를 사용하여 찾았다.

어렵지 않은 문제라 코드만 봐도 쉽게 이해할 수 있을 것이다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void search_near(int cheese[100][100], bool visited[100][100], int N, int x, int y, int day);

int main(int argc, char** argv)
{
	int T, N, cheese[100][100], answer, group_num;
	bool visited[100][100];

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장
		scanf("%d", &N);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				scanf("%d", &cheese[a][b]);
			}
		}

		answer = 0;
		//0일부터 100일 까지 중 덩어리 갯수가 가장 많은 것을 선택
		for (int a = 0; a <= 100; a++) {
			group_num = 0;	//덩어리의 갯수
			memset(visited, false, sizeof(bool) * 100 * 100);
			//모든 좌표중 해당 지점이 현재 날짜보다 크며 방문하지 않은 지역이면 새로운 덩어리
			for (int b = 0; b < N; b++) {
				for (int c = 0; c < N; c++) {
					if (cheese[b][c] > a && visited[b][c] == false) {
						visited[b][c] = true;
						search_near(cheese, visited, N, b, c, a);
						group_num++;
					}
				}
			}
			//현재 날짜의 덩어리 갯수가 더 많은 경우 answer 갱신
			if (group_num > answer)	answer = group_num;
		}

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}
//x, y와 같은 덩어리에 속하는 지역을 모두 방문하였다고 표시
void search_near(int cheese[100][100], bool visited[100][100], int N, int x, int y, int day) {
	int nx, ny;

	for (int a = 0; a < 4; a++) {
		nx = x + dx[a];
		ny = y + dy[a];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && cheese[nx][ny] > day && visited[nx][ny] == false) {
			visited[nx][ny] = true;
			search_near(cheese, visited, N, nx, ny, day);
		}
	}
}