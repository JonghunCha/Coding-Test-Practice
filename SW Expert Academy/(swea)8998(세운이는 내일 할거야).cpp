/*
문제 링크 : https://swexpertacademy.com/main/main.do
문제 풀이 자체는 어렵지 않으나, 시간초과가 빡빡한 문제였다.

벡터를 사용하면 시간초과가 나서 pair배열을 이용하였다.

우선 D를 기준으로 내림차순으로 정렬을 한다.

초기 answer는 가장 큰 D를 기준으로 잡으며 N개의 과제에 대해 아래의 계산을 거친다.

answer가 현재 과제보다 크다면 answer는 현재 과제의 D - T로 설정(이것은 현재 과제 이후에 제출해야 할 과제는 현재 과제와 영향없이 해결할 수 있음을 의미)

answer가 현재 과제보다 작거나 같다면 answer에서 현재 과제의 T를 뺀다(현재 과제를 현재 answer보다 늦게 끝내면 이후의 과제를 끝내지 못하는 상황)
*/
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> TD_vec[1000000];
//정렬을 위한 compare 함수
bool compare(pair<int, int>& p1, pair<int, int>& p2) {
	if (p1.first > p2.first)	return true;
	else	return false;
}

int main(int argc, char** argv)
{
	int TC, N, T, D, answer;
	
	scanf("%d", &TC);
	for (int test_case = 1; test_case <= TC; ++test_case)
	{
		//입력값 저장
		scanf("%d", &N);
		for (int a = 0; a < N; a++) {
			scanf("%d %d", &T, &D);
			TD_vec[a].first = D;
			TD_vec[a].second = T;
		}
		//TD_vec을 내림차순으로 정렬
		sort(TD_vec, TD_vec + N, compare);
		//위에서 설명한 방식으로 정답 도출
		answer = TD_vec[0].first;
		for (int a = 0; a < N; a++) {
			if (answer > TD_vec[a].first) {
				answer = TD_vec[a].first - TD_vec[a].second;
			}
			else {
				answer = answer - TD_vec[a].second;
			}
		}

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}