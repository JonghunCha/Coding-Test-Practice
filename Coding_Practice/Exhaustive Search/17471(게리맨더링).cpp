/*
문제 링크 : https://www.acmicpc.net/problem/17471
기본적으로 완전 탐색을 통해 해결할 수 있으며, 예외 처리를 위해 그래프 탐색을 할 필요가 있다.

구역은 최대 10개이며 선거구는 2개이므로 10개의 구역을 2개의 선거구로 나누는 모든 경우에 대해 조합을 구한다.

그런 다음 무작위로 나누어진 2개의 선거구가 문제의 조건을 만족하는지 확인해야 한다.

문제의 선거구 선정에 대한 조건은 아래와 같이 2가지가 있다.
1. 선거구는 구역을 적어도 하나를 포함해야 한다.
2. 한 선거구에 포함되있는 구역은 모두 연결되어 있어야 한다.

따라서 모든 조합에서 위 두가지 경우를 제외한 뒤, 인원수의 차이가 최소가 되는 경우를 계산하면 된다.
*/
#include <iostream>
using namespace std;

int answer = 100000000;

void Make_Combination(int N, int population[11], int neighbor[11][11], int zone_one[10], int zone_two[10], int one_index, int two_index, int step);
bool Is_Possible(int N, int neighbor[11][11], int zone_one[10], int zone_two[10], int one_index, int two_index);
bool Find_Path(int neighbor[11][11], int zone[10], int zone_length, int v1, int v2);
void Calculate(int N, int population[11], int zone_one[10], int zone_two[10], int one_index, int two_index);

int main(void) {
	int N, population[11], neighbor[11][11];	//입력을 받기 위한 저장소
	int zone_one[10], zone_two[10];				//각각 선거구1, 2를 의미하며 지역의 번호를 저장
	int temp1, temp2;
	//입력값 저장(neighbor의 경우 이웃인 경우 1을, 아닌 경우 -1을 저장)
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> population[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			neighbor[i][j] = -1;
		}
	}
	for (int i = 1; i <= N; i++) {
		cin >> temp1;
		for (int j = 1; j <= temp1; j++) {
			cin >> temp2;
			neighbor[i][temp2] = 1;
		}
	}
	//모든 조합을 만드는 함수 호출
	Make_Combination(N, population, neighbor, zone_one, zone_two, 0, 0, 1);
	
	if (answer == 100000000)	cout << -1;
	else	cout << answer;

	return 0;
}

void Make_Combination(int N, int population[11], int neighbor[11][11], int zone_one[10], int zone_two[10], int one_index, int two_index, int step) {
	//step이 N+1이라는 것은 선거구 조합이 끝났다는 것
	if (step == N + 1) {
		//Is_Possible함수를 통해 문제의 조건을 만족하는지 확인 한 후 인원수 차이를 계산
		if (Is_Possible(N, neighbor, zone_one, zone_two, one_index, two_index))	Calculate(N, population, zone_one, zone_two, one_index, two_index);
		return;
	}
	//이번 단계의 지역을 선거구 1에 넣는 경우
	zone_one[one_index] = step;
	Make_Combination(N, population, neighbor, zone_one, zone_two, one_index + 1, two_index, step + 1);
	//이번 단계의 지역을 선거구 2에 넣는 경우
	zone_two[two_index] = step;
	Make_Combination(N, population, neighbor, zone_one, zone_two, one_index, two_index + 1, step + 1);
}
//조합이 문제의 조건을 만족하는지 확인하는 함수
bool Is_Possible(int N, int neighbor[11][11], int zone_one[10], int zone_two[10], int one_index, int two_index) {
	bool flag;
	//선거구에 할당 된 지역이 하나도 없는 경우 false 반환
	if (one_index == 0 || two_index == 0)	return false;
	//선거구에 할당 된 지역이 1개라면 서로 연결 유무 확인할 필요 없음
	if (one_index != 1) {
		for (int i = 0; i < one_index; i++) {
			for (int j = 0; j < one_index; j++) {
				//1번 선거구의 모든 지역이 상호 연결되어 있는지 확인
				if(!Find_Path(neighbor, zone_one, one_index, zone_one[i], zone_one[j]))		return false;
			}
		}
	}
	if (two_index != 1) {
		for (int i = 0; i < two_index; i++) {
			for (int j = 0; j < two_index; j++) {
				if (!Find_Path(neighbor, zone_two, two_index, zone_two[i], zone_two[j]))	return false;
			}
		}
	}
	return true;
}
//지역구 내 서로 다른 두 지역이 연결되어 있는지 확인하는 함수
bool Find_Path(int neighbor[11][11], int zone[10], int zone_length, int v1, int v2) {
	//stack은 그래프 탐색에서 다음번에 검사할 node를 저장, memory는 이미 검사한 지역인지 아닌지를 저장(1이면 검사한 지역, 0이면 아직 검사하지 않은 지역)
	int stack[11], stack_size = 1, memory[11];
	for (int i = 1; i < 11; i++)	memory[i] = 0;
	//v1과 v2가 같은 경우 바로 true 반환
	if (v1 == v2)	return true;
	
	stack[1] = v1;
	memory[v1] = 1;
	int now;
	while (stack_size > 0) {
		now = stack[stack_size--];
		if (neighbor[now][v2] == 1)	return true;
		for (int i = 0; i < zone_length; i++) {
			if (neighbor[now][zone[i]] == 1 && memory[zone[i]] == 0) {
				stack[++stack_size] = zone[i];
				memory[zone[i]] = 1;
			}
		}
	}
	return false;
}
//두 지역구간의 인원차이를 확인하는 함수
void Calculate(int N, int population[11], int zone_one[10], int zone_two[10], int one_index, int two_index) {
	int sum1 = 0, sum2 = 0, result;
	for (int i = 0; i < one_index; i++)	sum1 += population[zone_one[i]];
	for (int i = 0; i < two_index; i++)	sum2 += population[zone_two[i]];
	if (sum1 > sum2)	result = sum1 - sum2;
	else	result = sum2 - sum1;
	if (result < answer)	answer = result;
}