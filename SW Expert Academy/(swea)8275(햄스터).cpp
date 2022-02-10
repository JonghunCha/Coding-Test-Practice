/*
문제 링크 : https://swexpertacademy.com/main/main.do
완전 탐색으로 해결할 수 있는 문제다.

햄스터의 조합이 가능한 경우는 최대 11^6 = 약 177만개이다.

따라서 모든 조합에 대해 문제의 조건을 만족하며 사전순으로 가장 앞에오는 조합을 출력하면 된다.
*/
#include <cstdio>
using namespace std;

bool is_end;
int answer[7], N, X, M, max_hnum;

void DFS(int records[11][3], int nums[7], int index, int hnum);
bool is_correct(int records[11][3], int nums[7]);

int main(int argc, char** argv)
{
	int T, records[10][3], nums[7];

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 변수 초기화
		scanf("%d %d %d", &N, &X, &M);
		for (int a = 1; a <= M; a++) {
			scanf("%d %d %d", &records[a][0], &records[a][1], &records[a][2]);
		}
		max_hnum = 0;
		is_end = false;
		//모든 조합에 대해 탐색
		DFS(records, nums, 1, 0);

		if (!is_end) {	//만약 가능한 경우를 못 찾았다면 -1 출력
			printf("#%d -1\n", test_case);
		}
		else {	//정답 출력
			printf("#%d ", test_case);
			for (int a = 1; a <= N; a++)	printf("%d ", answer[a]);
			printf("\n");
		}
	}
	return 0;
}

void DFS(int records[11][3], int nums[7], int index, int hnum) {
	bool change = false;
	//N개의 방에 햄스터의 수를 다 지정한 경우
	if (index == N + 1) {
		if (is_correct(records, nums) && hnum >= max_hnum) {	//만약 해당 경우가 문제의 조건을 만족하며, 현재까지 최대의 햄스터를 수용하는 경우일 때
			if (hnum > max_hnum) {	//만약 햄스터 수가 더 크다면 정답 교체
				for (int a = 1; a <= N; a++) {
					answer[a] = nums[a];
				}
				max_hnum = hnum;
			}
			else {	//햄스터 수가 같은 경우 사전순으로 앞에 오는 것을 정답으로 선택
				for (int a = 1; a <= N; a++) {
					if (nums[a] < answer[a]) {
						change = true;
						break;
					}
					else if (nums[a] > answer[a]) {
						break;
					}
				}

				if (change) {
					for (int a = 1; a <= N; a++) {
						answer[a] = nums[a];
					}
				}
			}

			is_end = true;
		}
		return;
	}
	//index번째의 방에 햄스터수 지정
	for (int a = 0; a <= X; a++) {
		nums[index] = a;
		DFS(records, nums, index + 1, hnum + a);
	}
}
//문제에 주어진 M개의 기록을 nums조합이 만족하는지 검사
bool is_correct(int records[11][3], int nums[7]) {
	int sum;

	for (int a = 1; a <= M; a++) {
		sum = 0;
		for (int b = records[a][0]; b <= records[a][1]; b++) {
			sum += nums[b];
		}
		if (sum != records[a][2])	return false;
	}

	return true;
}