/*
문제 링크 : https://www.acmicpc.net/problem/16236
BFS의 원리를 이용한 완전 탐색으로 해결할 수 있는 문제다.

문제의 조건의 핵심은 아래 2가지와 같다.
1. 먹을 수 있는 물고기가 있다면, 가장 가까운 것을 먹는다.
2. 거리가 가까운 물고기가 2마리 이상이라면 가장 위의 물고리를 고르고, 그것 마저 겹친다면 가장 왼쪽의 물고기를 고른다.

위 두가지를 구현하기 위해 상어의 위치에서 이동하는 횟수에 따라 stage를 나누었다.

stage가 0일때는 상어의 최초 위치에서 1만큼 이동할 수 있는 공간을 탐색하고
stage가 n일때는 상어의 최초 위치에서 n+1만큼 이동한 공간을 탐색한다.

즉, stage가 올라감에 따라 상어의 이동 거리가 늘어나고 그 과정에서 먹을 수 있는 물고기를 발견하면,
시간을 추가하고 상어의 위치를 옮긴후 다시 반복하는 식으로 구현하면 된다.
*/
#include <iostream>
using namespace std;

int answer = 0, shark_x, shark_y, shark_size = 2, eat = 0;

bool Find_Fish(int N, int map[20][20], int visit[20][20]);

int main(void) {
	int N, map[20][20], visit[20][20];
	//입력값 저장
	cin >> N;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			cin >> map[a][b];
			if (map[a][b] == 9) {
				shark_x = a;
				shark_y = b;
			}
		}
	}
	//한 번의 루프에서 상어는 다음 먹이를 결정하고 위치를 갱신한 후 다음 루프를 실행한다
	//만약 다음 먹이를 찾지 못하면 while문을 종료한다
	while (1) {
		//visit은 각 stage에서 상어의 동선을 기록한다
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				visit[a][b] = -1;
			}
		}
		visit[shark_x][shark_y] = 0;
		//먹이를 찾지 못하면 종료
		if (!Find_Fish(N, map, visit))	break;
	}
	cout << answer;
	return 0;
}

bool Find_Fish(int N, int map[20][20], int visit[20][20]) {
	int stage = 0;
	bool flag = true;	//flag는 while문의 한 루프에서 유의미한 변동(상어가 움직이거나 먹이를 찾는 경우)의 유무를 의미
	while (flag) {
		flag = false;
		//현재 탐색 구역이 방문한 적 없고, 이전 stage에서 방문한 지역과 인접한 경우를 찾는다
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				//북쪽에 이전 stage에서 방문한 구역이 있는 경우
				if (a != 0 && visit[a - 1][b] == stage && visit[a][b] == -1) {
					//만약 상어가 먹을 수 있는 물고기가 있을 때
					if (map[a][b] > 0 && map[a][b] < shark_size) {
						answer += stage + 1;
						eat++;
						if (eat == shark_size) {
							shark_size++;
							eat = 0;
						}
						map[shark_x][shark_y] = 0;
						map[a][b] = 9;
						shark_x = a;
						shark_y = b;
						return true;
					}
					//상어가 이동할 수 있을 때
					else if (map[a][b] == 0 || map[a][b] == shark_size) {
						visit[a][b] = stage + 1;
						flag = true;
					}
				}
				//서쪽에 이전 stage에서 방문한 구역이 있는 경우
				if (b != 0 && visit[a][b - 1] == stage && visit[a][b] == -1) {
					if (map[a][b] > 0 && map[a][b] < shark_size) {
						answer += stage + 1;
						eat++;
						if (eat == shark_size) {
							shark_size++;
							eat = 0;
						}
						map[shark_x][shark_y] = 0;
						map[a][b] = 9;
						shark_x = a;
						shark_y = b;
						return true;
					}
					else if (map[a][b] == 0 || map[a][b] == shark_size) {
						visit[a][b] = stage + 1;
						flag = true;
					}
				}
				//남쪽에 이전 stage에서 방문한 구역이 있는 경우
				if (a != N - 1 && visit[a + 1][b] == stage && visit[a][b] == -1) {
					if (map[a][b] > 0 && map[a][b] < shark_size) {
						answer += stage + 1;
						eat++;
						if (eat == shark_size) {
							shark_size++;
							eat = 0;
						}
						map[shark_x][shark_y] = 0;
						map[a][b] = 9;
						shark_x = a;
						shark_y = b;
						return true;
					}
					else if (map[a][b] == 0 || map[a][b] == shark_size) {
						visit[a][b] = stage + 1;
						flag = true;
					}
				}
				//동쪽에 이전 stage에서 방문한 구역이 있는 경우
				if (b != N - 1 && visit[a][b + 1] == stage && visit[a][b] == -1) {
					if (map[a][b] > 0 && map[a][b] < shark_size) {
						answer += stage + 1;
						eat++;
						if (eat == shark_size) {
							shark_size++;
							eat = 0;
						}
						map[shark_x][shark_y] = 0;
						map[a][b] = 9;
						shark_x = a;
						shark_y = b;
						return true;
					}
					else if (map[a][b] == 0 || map[a][b] == shark_size) {
						visit[a][b] = stage + 1;
						flag = true;
					}
				}
			}
		}
		stage++;
	}
	return false;
}