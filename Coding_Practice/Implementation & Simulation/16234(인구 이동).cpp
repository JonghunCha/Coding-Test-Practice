/*
문제 링크 : https://www.acmicpc.net/problem/16234
완전 탐색으로 해결할 수 있는 문제다.

이 문제는 연합을 찾는 것이 핵심이다.

전체 공간을 탐색하며 인접한 지역과 연합이 가능한 조건이면 연합을 맺는다.

새로 연합에 추가된 지역의 이웃 나라가 연합 가능 조건이라면 연합에 추가하는 방식으로 탐색하면 된다.

구현 자체는 어렵지 않다. 그러나 시간복잡도를 잘 생각해서 구현해야 통과가 된다.
*/
#include <iostream>
using namespace std;

void check_near(int N, int L, int R, int** map, int** check, int union_index, int x, int y, int union_population[2501], int union_num[2501]);

int main(void) {
	int N, L, R, count = 0, union_index, union_population[2501], union_num[2501];
	//입력값 저장
	cin >> N; cin >> L; cin >> R;
	int** map = new int* [N];
	int** check = new int* [N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
		check[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	//인구 이동이 끝날때까지 반복
	while (1) {
		//check는 각 지역의 연합 번호를 저장하며 처음엔 0으로 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				check[i][j] = 0;
			}
		}
		//union_index는 연합의 번호를 의미
		union_index = 1;
		//population과 num은 각각 해당 연합의 인구수 총합, 나라의 개수를 의미
		for (int i = 1; i < 2500; i++) {
			union_population[i] = 0;
			union_num[i] = 0;
		}
		//전체 지역을 살피며 아직 연합이 안정해진 나라의 경우 새로운 연합으로 지정하고 근처를 탐색
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] == 0) {
					check_near(N, L, R, map, check, union_index, i, j, union_population, union_num);
					union_index++;
				}
			}
		}
		//모든 나라가 서로 다른 연합이라는 것은 인구 이동이 일어나지 않음을 의미
		if (union_index == N * N + 1)	break;
		//인구 이동 실시
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				map[a][b] = union_population[check[a][b]] / union_num[check[a][b]];
			}
		}
		count++;
	}
	cout << count;
	//동적 할당 해제
	for (int i = 0; i < N; i++) {
		delete[]map[i];
		delete[]check[i];
	}
	delete[]map;
	delete[]check;

	return 0;
}

void check_near(int N, int L, int R, int** map, int** check, int union_index, int x, int y, int union_population[2501], int union_num[2501]) {
	int temp;
	check[x][y] = union_index;
	union_population[union_index] += map[x][y];
	union_num[union_index]++;
	//현재 위치의 북쪽 확인
	if (x != 0) {
		temp = map[x][y] - map[x - 1][y];
		if (((temp >= L && temp <= R) || (temp >= -R && temp <= -L)) && check[x-1][y] == 0) {
			check_near(N, L, R, map, check, union_index, x - 1, y, union_population, union_num);
		}
	}
	//현재 위치의 서쪽 확인
	if (y != 0) {
		temp = map[x][y] - map[x][y - 1];
		if (((temp >= L && temp <= R) || (temp >= -R && temp <= -L)) && check[x][y - 1] == 0) {
			check_near(N, L, R, map, check, union_index, x, y - 1, union_population, union_num);
		}
	}
	//현재 위치의 남쪽 확인
	if (x != N - 1) {
		temp = map[x][y] - map[x + 1][y];
		if (((temp >= L && temp <= R) || (temp >= -R && temp <= -L)) && check[x + 1][y] == 0) {
			check_near(N, L, R, map, check, union_index, x + 1, y, union_population, union_num);
		}
	}
	//현재 위치의 동쪽 확인
	if (y != N - 1) {
		temp = map[x][y] - map[x][y + 1];
		if (((temp >= L && temp <= R) || (temp >= -R && temp <= -L)) && check[x][y + 1] == 0) {
			check_near(N, L, R, map, check, union_index, x, y + 1, union_population, union_num);
		}
	}
}