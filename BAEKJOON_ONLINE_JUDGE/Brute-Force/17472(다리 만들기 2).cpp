/*
문제 링크 : https://www.acmicpc.net/problem/17472
섬사이에 생길 수 있는 다리들의 모든 조합을 완전 탐색을 통해 구한다. 그런 다음 만들어진 다리 조합이 모든 섬을 서로 연결할 수 있는지 확인한다(DFS를 이용한 그래프 탐색).

모든 섬들이 서로 연결 가능 하다면 다리 길이 합의 최소값을 계속해서 업데이트 하면 된다.
*/
#include <iostream>
using namespace std;

int answer = 100;

void Check_Near(int N, int M, int map[10][10], int temp, int row, int col);
void Get_All_Bridge(int N, int M, int map[10][10], int bridge_length[7][7]);
void Make_Combination(int bridge_length[7][7], int connect[7][7], int islands_num, int bridge_num, int step);
bool Is_Connected(int connect[7][7], int islands_num, int island1, int island2);

int main(void) {
	int N, M, map[10][10], islands_num = 0, temp, bridge_length[7][7], connect[7][7], bridge_num = 0;
	//입력값 저장
	cin >> N; cin >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	//temp는 섬의 번호를 부여하기 위해 사용(처음에 2를 사용하는 이유는 기본적으로 모든 섬들을 1로 입력 받기에 구별하기 위해)
	temp = 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				map[i][j] = temp;
				//섬인 구역을 발견한다면 좌, 우, 상, 하에 같은 섬인 구역이 있는지 확인
				Check_Near(N, M, map, temp, i, j);
				temp++;
			}
		}
	}
	//섬의 개수를 파악한다 + 직관성을 높이기 위해 섬의 번호를 1부터 매김
	temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > 0)	map[i][j]--;
			if (map[i][j] > islands_num)	islands_num = map[i][j];
		}
	}
	//각 섬사이의 다리 길이를 저장하는 배열 초기화(100이면 다리가 놓일 수 없는 것)
	for (int i = 1; i <= islands_num; i++) {
		for (int j = 1; j <= islands_num; j++) {
			bridge_length[i][j] = 100;
		}
	}
	//섬 사이 다리길이를 구하는 함수 호출
	Get_All_Bridge(N, M, map, bridge_length);
	//connect는 다리를 놓을 수 없는 경우엔 -1, 놓을 수 있는 경우엔 0으로 초기화
	for (int i = 1; i <= islands_num; i++) {
		for (int j = 1; j <= islands_num; j++) {
			if (bridge_length[i][j] == 100)	connect[i][j] = -1;
			else {
				connect[i][j] = 0;
				bridge_num++;
			}
		}
	}
	bridge_num /= 2;
	//다리의 모든 조합을 구하고 결과값을 계산
	Make_Combination(bridge_length, connect, islands_num, bridge_num, 1);
	if (answer == 100) cout << -1;
	else	cout << answer;

	return 0;
}
//입력값에서 섬인 지역을 발견 했을때 인접한 구역에 같은 섬인 지역이 있는지 탐색
void Check_Near(int N, int M, int map[10][10], int temp, int row, int col) {
	if (row > 0 && map[row - 1][col] == 1){
		map[row - 1][col] = temp;
		Check_Near(N, M, map, temp, row - 1, col);
	}
	if (col < M - 1 && map[row][col + 1] == 1) {
		map[row][col + 1] = temp;
		Check_Near(N, M, map, temp, row, col + 1);
	}
	if (col > 0 && map[row][col - 1] == 1) {
		map[row][col - 1] = temp;
		Check_Near(N, M, map, temp, row, col - 1);
	}
	if (row < N - 1 && map[row + 1][col] == 1) {
		map[row + 1][col] = temp;
		Check_Near(N, M, map, temp, row + 1, col);
	}
}
//두섬 사이에 놓일 수 있는 가장 짧은 다리를 구함
void Get_All_Bridge(int N, int M, int map[10][10], int bridge_length[7][7]) {
	int island1 = 0, island2 = 0, length, flag;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//섬인 지역을 발견
			if (map[i][j] > 0) {
				island1 = map[i][j];
				//위쪽 탐색
				length = 0;
				flag = 0;
				for (int k = i - 1; k >= 0; k--) {
					//같은 섬인 구역이면 탐색 끝
					if (map[k][j] == map[i][j])	break;
					//바다 지역이면 다리 길이++
					else if (map[k][j] == 0)	length++;
					//다른 섬 발견한 경우
					else {
						island2 = map[k][j];
						flag = 1;
						break;
					}
				}
				if (length >= 2 && bridge_length[island1][island2] > length && flag == 1)	bridge_length[island1][island2] = length;
				//오른쪽 탐색
				length = 0;
				flag = 0;
				for (int k = j + 1; k < M; k++) {
					if (map[i][k] == map[i][j])	break;
					else if (map[i][k] == 0)	length++;
					else {
						island2 = map[i][k];
						flag = 1;
						break;
					}
				}
				if (length >= 2 && bridge_length[island1][island2] > length && flag == 1)	bridge_length[island1][island2] = length;
				//아래쪽 탐색
				length = 0;
				flag = 0;
				for (int k = i + 1; k < N; k++) {
					if (map[k][j] == map[i][j])	break;
					else if (map[k][j] == 0)	length++;
					else {
						island2 = map[k][j];
						flag = 1;
						break;
					}
				}
				if (length >= 2 && bridge_length[island1][island2] > length && flag == 1)	bridge_length[island1][island2] = length;
				//왼쪽 탐색
				length = 0;
				flag = 0;
				for (int k = j - 1; k >= 0; k--) {
					if (map[i][k] == map[i][j])	break;
					else if (map[i][k] == 0)	length++;
					else {
						island2 = map[i][k];
						flag = 1;
						break;
					}
				}
				if (length >= 2 && bridge_length[island1][island2] > length && flag == 1)	bridge_length[island1][island2] = length;
			}
		}
	}
}
//모든 다리의 조합을 만들고 결과 값을 계산
void Make_Combination(int bridge_length[7][7], int connect[7][7], int islands_num, int bridge_num, int step) {
	//모든 다리를 놓을 것일지 놓지 않을 것인지 결정 한 후
	if (step == bridge_num + 1) {
		//모든 섬들이 서로 연결되었는지 확인
		for (int i = 1; i <= islands_num; i++) {
			for (int j = i + 1; j <= islands_num; j++) {
				if (!Is_Connected(connect, islands_num, i, j))	return;
			}
		}
		//놓여진 다리의 길이를 구하고 answer갱신
		int length = 0;
		for (int i = 1; i <= islands_num; i++) {
			for (int j = i + 1; j <= islands_num; j++) {
				if (connect[i][j] == 1)	length += bridge_length[i][j];
			}
		}
		if (length < answer)	answer = length;
	}
	for (int i = 1; i <= islands_num; i++) {
		for (int j = i + 1; j <= islands_num; j++) {
			//다리를 놓을 수 있는 경우 발견
			if (connect[i][j] == 0) {
				//놓지 않기로 결정 한 후
				connect[i][j] = -1;
				connect[j][i] = -1;
				Make_Combination(bridge_length, connect, islands_num, bridge_num, step + 1);
				//놓기로 결정 한 후
				connect[i][j] = 1;
				connect[j][i] = 1;
				Make_Combination(bridge_length, connect, islands_num, bridge_num, step + 1);
				connect[i][j] = 0;
				connect[j][i] = 0;
				return;
			}
		}
	}
}
//두 섬이 서로 연결되어 있는지 확인하는 함수
bool Is_Connected(int connect[7][7], int islands_num, int island1, int island2) {
	int stack[7], stack_size = 0, memory[7], now;

	for (int i = 1; i <= islands_num; i++)	memory[i] = 0;
	stack[1] = island1;
	stack_size = 1;
	while (stack_size > 0) {
		now = stack[stack_size--];
		if (connect[now][island2] == 1)	return true;
		for (int i = 1; i <= islands_num; i++) {
			if (connect[now][i] == 1 && memory[i] == 0) {
				memory[i] = 1;
				stack[++stack_size] = i;
			}
		}
	}
	return false;
}