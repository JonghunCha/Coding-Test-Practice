/*
문제 링크 : https://swexpertacademy.com/main/main.do
완전 탐색으로 해결할 수 있다.

각 사람이 어떤 계단을 이용하는지에 대한 모든 조합을 고려하고 그 중 가장 최단 시간을 소요하는 경우를 택하면 된다.

코드를 보면 쉽게 이해 가능한 수준의 문제다.
*/
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int answer = 1000;

void make_combination(int N, int room[10][10], int stair[2][3], int combination[10], int index, int people_num);
void calculate(int N, int room[10][10], int stair[2][3], int combination[10]);
bool compare(int a, int b);

int main(int argc, char** argv)
{
	int T, N, room[10][10], stair[2][3], index, combination[10], people_num;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 변수 값 지정
		index = 0;
		people_num = 0;
		scanf("%d", &N);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				scanf("%d", &room[a][b]);
				if (room[a][b] > 1) {
					stair[index][0] = a;
					stair[index][1] = b;
					stair[index++][2] = room[a][b];
				}
				if (room[a][b] == 1)	people_num++;
			}
		}

		answer = 1000;
		make_combination(N, room, stair, combination, 0, people_num);
		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}
//각 사람이 어느 계단을 이용하는지에 대한 모든 조합을 고려하고 시간 계산
void make_combination(int N, int room[10][10], int stair[2][3], int combination[10], int index, int people_num) {
	if (index == people_num) {
		calculate(N, room, stair, combination);
		return;
	}

	combination[index] = 0;
	make_combination(N, room, stair, combination, index + 1, people_num);
	combination[index] = 1;
	make_combination(N, room, stair, combination, index + 1, people_num);
}
//각 조합에 대해 소요 시간 계산
void calculate(int N, int room[10][10], int stair[2][3], int combination[10]) {
	int index = 0;
	vector<int> stair1, stair2;
	queue<int> stair1_arrive, stair1_end, stair2_arrive, stair2_end;
	//각 계단에 사람이 도착하는 시간을 계산하고 오름차순으로 정렬
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (room[a][b] == 1) {
				if (combination[index] == 0)	stair1.push_back(abs(a - stair[0][0]) + abs(b - stair[0][1]));
				else	stair2.push_back(abs(a - stair[1][0]) + abs(b - stair[1][1]));
				index++;
			}
		}
	}
	sort(stair1.begin(), stair1.end(), compare);
	sort(stair2.begin(), stair2.end(), compare);
	//stair1_arrive, stair2_arrive 큐에 사람들이 계단에 도착하는 시간을 저장
	for (int a = 0; a < stair1.size(); a++)	stair1_arrive.push(stair1[a]);
	for (int a = 0; a < stair2.size(); a++)	stair2_arrive.push(stair2[a]);
	//모든 사람이 계단을 통과할 때까지 반복
	for (int count = 1; count <= 1000; count++) {
		while (1) {	//첫 번째 계단을 다 내려온 사람을 큐에서 pop
			if (stair1_end.size() > 0 && stair1_end.front() == count)	stair1_end.pop();
			else	break;
		}
		while (1) {	//두 번째 계단을 다 내려온 사람을 큐에서 pop
			if (stair2_end.size() > 0 && stair2_end.front() == count)	stair2_end.pop();
			else	break;
		}
		while (1) {	//도착한 사람이 1분을 기다렸으며 계단 위에 3명 미만인 경우 계단 내려가기 시작
			if (stair1_arrive.size() > 0 && stair1_arrive.front() < count && stair1_end.size() < 3) {
				stair1_end.push(count + stair[0][2]);
				stair1_arrive.pop();
			}
			else {
				break;
			}
		}	
		while (1) {	//도착한 사람이 1분을 기다렸으며 계단 위에 3명 미만인 경우 계단 내려가기 시작
			if (stair2_arrive.size() > 0 && stair2_arrive.front() < count && stair2_end.size() < 3) {
				stair2_end.push(count + stair[1][2]);
				stair2_arrive.pop();
			}
			else {
				break;
			}
		}
		//모든 사람이 계단을 내려간 경우 끝낸다.
		if (stair1_arrive.size() == 0 && stair1_end.size() == 0 && stair2_arrive.size() == 0 && stair2_end.size() == 0) {
			if (count < answer)	answer = count;
			break;
		}
	}
}

bool compare(int a, int b) {
	return a < b;
}