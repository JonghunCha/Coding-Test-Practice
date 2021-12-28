/*
문제 링크 : https://www.acmicpc.net/problem/17135
완전탐색을 통해 해결할 수 있는 문제다.
궁수의 위치에 따라 결과가 달라질 수 있는 게임이기에 가능한 모든 궁수위치의 조합에 대해 일일히 계산하면 된다.
*/
#include <iostream>
using namespace std;

int answer = 0;

void Get_Answer(const int N, const int M, const int D, const int map[15][15]);
void Play_Game(const int N, const int M, const int D, const int map[15][15], const int arrange[15]);
bool Is_Game_Over(const int N, const int M, const int map[15][15]);

int main(void) {
	int N, M, D;
	int map[15][15];

	cin >> N; cin >> M; cin >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	Get_Answer(N, M, D, map);
	cout << answer;
	return 0;
}
//모든 궁수의 조합에 대해 Play_Game함수를 호출하여 가장 많은 적을 죽이는 조합을 찾는다.
void Get_Answer(const int N, const int M, const int D, const int map[15][15]) {
	int arrange[15];	//궁수의 위치를 나타내는 배열(0이면 빈 자리, 1이면 궁수가 있는 자리)
	for (int i = 0; i < M - 2; i++) {
		for (int j = i + 1; j < M - 1; j++) {
			for (int k = j + 1; k < M; k++) {
				for (int m = 0; m < M; m++)	arrange[m] = 0;
				arrange[i] = 1;
				arrange[j] = 1;
				arrange[k] = 1;
				Play_Game(N, M, D, map, arrange);
			}
		}
	}
}
//주어진 궁수 위치에따라 게임을 진행하는 함수
void Play_Game(const int N, const int M, const int D, const int map[15][15], const int arrange[15]) {
	int removed_enemy = 0, step, flag, distance, target[3][2];	//target은 각 궁수가 제거하는 적의 위치를 나타낸다
	int map_copy[15][15];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map_copy[i][j] = map[i][j];
		}
	}
	
	while (1) {
		step = 0;	//step은 이번 턴에 궁수들이 몇명의 적을 죽일 수 있는지를 의미한다
		if (Is_Game_Over(N, M, map_copy)) {
			if (removed_enemy > answer)	answer = removed_enemy;
			return;
		}
		
		for (int i = 0; i < M; i++) {
			//각 궁수에 대해서
			if (arrange[i] == 1) {
				flag = 0;
				//가장 가까운 적부터 찾는다
				for (int j = 1; j <= D; j++) {
					//그중에서 가장 왼쪽의 적부터 찾는다
					for (int k = 0; k < M; k++) {
						for (int m = N - 1; m >= 0; m--) {
							if (i > k)	distance = N - m + i - k;
							else	distance = N - m + k - i;
							//길이가 일치하며 적이 있는 곳이라면 target으로 지정하고 step을 더해준다
							if (distance == j && map_copy[m][k] == 1) {
								target[step][0] = m;
								target[step][1] = k;
								step++;
								flag = 1;
								break;
							}
						}
						if (flag == 1)	break;
					}
					if (flag == 1)	break;
				}
			}
		}
		//3명의 궁수가 적을 다 맞추는 경우
		if (step == 3) {
			//궁수들의 타겟이 모두 일치하는 경우
			if (target[0][0] == target[1][0] && target[0][1] == target[1][1] && target[0][0] == target[2][0] && target[0][1] == target[2][1]) {
				removed_enemy++;
				map_copy[target[0][0]][target[0][1]] = 0;
			}
			//둘만 일치하는 경우
			else if ((target[0][0] == target[1][0] && target[0][1] == target[1][1]) && (target[0][0] != target[2][0] || target[0][1] != target[2][1])) {
				removed_enemy += 2;
				map_copy[target[0][0]][target[0][1]] = 0;
				map_copy[target[2][0]][target[2][1]] = 0;
			}
			else if ((target[0][0] != target[1][0] || target[0][1] != target[1][1]) && (target[0][0] == target[2][0] && target[0][1] == target[2][1])) {
				removed_enemy += 2;
				map_copy[target[0][0]][target[0][1]] = 0;
				map_copy[target[1][0]][target[1][1]] = 0;
			}
			else if ((target[0][0] != target[1][0] || target[0][1] != target[1][1]) && (target[1][0] == target[2][0] && target[1][1] == target[2][1])) {
				removed_enemy += 2;
				map_copy[target[0][0]][target[0][1]] = 0;
				map_copy[target[1][0]][target[1][1]] = 0;
			}
			//모두 다른 경우
			else {
				removed_enemy += 3;
				map_copy[target[0][0]][target[0][1]] = 0;
				map_copy[target[1][0]][target[1][1]] = 0;
				map_copy[target[2][0]][target[2][1]] = 0;
			}
		}
		//3명의 궁수 중 2명만 적을 맞출 수 있는 경우
		else if (step == 2) {
			if (target[0][0] == target[1][0] && target[0][1] == target[1][1]) {
				removed_enemy++;
				map_copy[target[0][0]][target[0][1]] = 0;
			}
			else {
				removed_enemy += 2;
				map_copy[target[0][0]][target[0][1]] = 0;
				map_copy[target[1][0]][target[1][1]] = 0;
			}
		}
		//3명의 궁수 중 2명만 적을 맞출 수 있는 경우
		else if (step == 1) {
			removed_enemy++;
			map_copy[target[0][0]][target[0][1]] = 0;
		}
		//적을 제거했으니 다음 턴을 위해 맵을 이동시킨다
		for (int i = N - 1; i > 0; i--) {
			for (int j = 0; j < M; j++) {
				map_copy[i][j] = map_copy[i - 1][j];
			}
		}
		for (int i = 0; i < M; i++)	map_copy[0][i] = 0;
	}
}
//게임이 끝났는지 확인하는 함수
bool Is_Game_Over(const int N, const int M, const int map[15][15]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1)	return false;
		}
	}
	return true;
}