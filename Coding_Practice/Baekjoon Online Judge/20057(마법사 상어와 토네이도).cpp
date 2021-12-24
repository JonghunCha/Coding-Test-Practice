/*
문제 링크 : https://www.acmicpc.net/problem/20057
단순 구현 문제다.

토네이도가 이동하는 방향의 규칙만 파악하면 구현하기 쉽다.

토네이도의 이동 규칙은 아래와 같다.

1. 왼쪽으로 n칸
2. 아래쪽으로 n칸
3. 오른쪽으로 n+1칸
4. 위쪽으로 n+1칸
....

토네이도는 위와 같이 왼쪽 아래쪽을 n칸 지나간 후에 오른쪽 위쪽으로는 n+1칸을 지난다. 그런 다음 왼쪽 아래쪽을 지날 땐 n+2칸을 지난다.

이러한 움직임이 (1,1)좌표에 닿을 때까지 반복하며 모래를 이동시켜주면 된다.
*/
#include <iostream>
using namespace std;

double percentage[9] = { 1.0, 1.0, 7.0, 7.0, 2.0, 2.0, 10.0, 10.0, 5.0 };
int dx_0[9] = { -1, 1, -1, 1, -2, 2, -1, 1, 0 };
int dy_0[9] = { 0, 0, -1, -1, -1, -1, -2, -2, -3 };
int dx_1[9] = { 0, 0, 1, 1, 1, 1, 2, 2, 3 };
int dy_1[9] = { -1, 1, -1, 1, -2, 2, -1, 1, 0 };
int dx_2[9] = { 1, -1, 1, -1, 2, -2, 1, -1, 0 };
int dy_2[9] = { 0, 0, 1, 1, 1, 1, 2, 2, 3 };
int dx_3[9] = { 0, 0, -1, -1, -1, -1, -2, -2, -3 };
int dy_3[9] = { 1, -1, 1, -1, 2, -2, 1, -1, 0 };

int main(void) {
	int N, answer = 0, x, y, direction, step, nx, ny;	//direction 0 = 왼쪽, 1 = 아래쪽, 2 = 오른쪽, 3 = 위쪽. step은 현재 방향으로 몇 번을 이동하는지 의미
	int** map;
	double moving_sand;	//움직여야할 모래의 값을 double형 실수로 나타낸 것(실제 움직이는 모래양과는 차이 있을 수 있음)
	int moved_sand;		//실제로 움직인 모래의 양으로 알파로 표시된 지역에 이동할 모래 양을 구하기 위해 사용됨
	bool flag = true;
	//입력값 저장
	cin >> N;
	map = new int*[N];
	for (int a = 0; a < N; a++) {
		map[a] = new int[N];
	}
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			cin >> map[a][b];
		}
	}
	//초기 상태 설정
	x = N / 2;
	y = N / 2;
	direction = 0;
	step = 1;
	while (flag) {
		for (int a = 0; a < step; a++) {
			//왼쪽으로 움직이는 경우
			if (direction == 0) {
				moved_sand = 0;
				for (int b = 0; b < 9; b++) {
					nx = x + dx_0[b];
					ny = y + dy_0[b];
					moving_sand = (double)map[x][y - 1] * percentage[b] / 100.0;	//움직여야할 모래 양
					moved_sand += (int)moving_sand;	//소수점을 버리고 실제로 움직이는 양
					if (nx >= 0 && nx < N && ny >= 0 && ny < N)		map[nx][ny] += (int)moving_sand;	//격자판 안에 있는 경우
					else	answer += (int)moving_sand;	//격자판 밖으로 밀려나는 경우
				}
				nx = x;
				ny = y - 2;
				if (nx >= 0 && nx < N && ny >= 0 && ny < N)	map[nx][ny] += map[x][y - 1] - moved_sand;
				else	answer += map[x][y - 1] - moved_sand;
				map[x][y - 1] = 0;
				y--;
			}
			//아래쪽으로 움직이는 경우
			else if (direction == 1) {
				moved_sand = 0;
				for (int b = 0; b < 9; b++) {
					nx = x + dx_1[b];
					ny = y + dy_1[b];
					moving_sand = (double)map[x + 1][y] * percentage[b] / 100.0;
					moved_sand += (int)moving_sand;
					if (nx >= 0 && nx < N && ny >= 0 && ny < N)		map[nx][ny] += (int)moving_sand;
					else	answer += (int)moving_sand;
				}
				nx = x + 2;
				ny = y;
				if (nx >= 0 && nx < N && ny >= 0 && ny < N)	map[nx][ny] += map[x + 1][y] - moved_sand;
				else	answer += map[x + 1][y] - moved_sand;
				map[x + 1][y] = 0;
				x++;
			}
			//오른쪽으로 움직이는 경우
			else if (direction == 2) {
				moved_sand = 0;
				for (int b = 0; b < 9; b++) {
					nx = x + dx_2[b];
					ny = y + dy_2[b];
					moving_sand = (double)map[x][y + 1] * percentage[b] / 100.0;
					moved_sand += (int)moving_sand;
					if (nx >= 0 && nx < N && ny >= 0 && ny < N)		map[nx][ny] += (int)moving_sand;
					else	answer += (int)moving_sand;
				}
				nx = x;
				ny = y + 2;
				if (nx >= 0 && nx < N && ny >= 0 && ny < N)	map[nx][ny] += map[x][y + 1] - moved_sand;
				else	answer += map[x][y + 1] - moved_sand;
				map[x][y + 1] = 0;
				y++;
			}
			//위쪽으로 움직이는 경우
			else {
				moved_sand = 0;
				for (int b = 0; b < 9; b++) {
					nx = x + dx_3[b];
					ny = y + dy_3[b];
					moving_sand = (double)map[x - 1][y] * percentage[b] / 100.0;
					moved_sand += (int)moving_sand;
					if (nx >= 0 && nx < N && ny >= 0 && ny < N)		map[nx][ny] += (int)moving_sand;
					else	answer += (int)moving_sand;
				}
				nx = x - 2;
				ny = y;
				if (nx >= 0 && nx < N && ny >= 0 && ny < N)	map[nx][ny] += map[x - 1][y] - moved_sand;
				else	answer += map[x - 1][y] - moved_sand;
				map[x - 1][y] = 0;
				x--;
			}
			if (x == 0 && y == 0) {
				flag = false;
				break;
			}
		}
		//방향 전환 및 이동 거리 갱신
		if (direction == 0)	direction = 1;
		else if (direction == 1) {
			direction = 2;
			step++;
		}
		else if (direction == 2)	direction = 3;
		else {
			direction = 0;
			step++;
		}
	}

	cout << answer;
	//동적 할당 해제
	for (int a = 0; a < N; a++) {
		delete[]map[a];
	}
	delete[]map;

	return 0;
}