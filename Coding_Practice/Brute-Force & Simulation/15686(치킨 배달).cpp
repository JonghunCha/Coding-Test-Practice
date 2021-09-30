/*
문제 링크 : https://www.acmicpc.net/problem/15686
완전 탐색으로 해결할 수 있는 문제다.

전체 치킨집중 어떠한 치킨집들을 폐업시킬지에 대한 모든 조합을 만들고 치킨 거리의 최솟값을 갱신시키면 된다.
*/
#include <iostream>
using namespace std;

int answer = 1000000;
void Select_M(int N, int map[51][51], int remove_num, int selected_num, int x, int y);
void Get_Minimal_Distance(int N, int map[51][51]);
int Search_Nearest(int N, int map[51][51], int x, int y);

int main(void) {
	int N, M, map[51][51], remove_num, store_num = 0;
	//입력값 저장
	cin >> N; cin >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)	store_num++;
		}
	}
	//remove_num은 폐업시킬 치킨집의 갯수
	remove_num = store_num - M;
	Select_M(N, map, remove_num, 0, 1, 1);
	cout << answer;
	return 0;
}
//selected_num은 폐업시킬 치킨집을 몇 개 골랐는지를 의미
void Select_M(int N, int map[51][51], int remove_num, int selected_num, int x, int y) {
	//폐업시킬 치킨집을 모두 고르면 치킨 거리의 최솟값 계산
	if (remove_num == selected_num) {
		Get_Minimal_Distance(N, map);
		return;
	}
	for (int i = x; i <= N; i++) {
		if (i == x) {
			for (int j = y; j <= N; j++) {
				if (map[i][j] == 2) {
					map[i][j] = 3;
					Select_M(N, map, remove_num, selected_num + 1, i, j);
					map[i][j] = 2;
				}
			}
		}
		else {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] == 2) {
					map[i][j] = 3;
					Select_M(N, map, remove_num, selected_num + 1, i, j);
					map[i][j] = 2;
				}
			}
		}
	}
}
//전체 집에 대해 치킨 거리의 최솟값을 구한다
void Get_Minimal_Distance(int N, int map[51][51]) {
	int distance_sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1) {
				distance_sum += Search_Nearest(N, map, i, j);
			}
		}
	}
	if (distance_sum < answer)	answer = distance_sum;
}
//x,y위치에 있는 집의 치킨 거리 최솟값 반환
int Search_Nearest(int N, int map[51][51], int x, int y) {
	int distance = 10000, temp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 2) {
				temp = 0;
				if (x >= i)	temp += x - i;
				else	temp += i - x;
				if (y >= j)	temp += y - j;
				else	temp += j - y;
				if (temp < distance)	distance = temp;
			}
		}
	}
	return distance;
}