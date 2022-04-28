/*
문제 링크 : https://swexpertacademy.com/main/main.do
완전 탐색 문제다.

약품 처리하는 층의 갯수를 하나씩 늘리며 가능한 모든 경우에 대해 품질 통과를 하는지 검사한다.

만약 검사 기준을 통과하는 경우가 나오면 뒷 부분은 종료하고 정답을 출력하면 된다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

bool is_end;

void make_combination(int D, int W, int K, int info[13][20], int change[13][2], int index, int change_num, int curr_change_num);
bool is_pass(int D, int W, int K, int info[13][20], int change[13][2]);

int main(void) {
	int T, D, W, K, info[13][20], change[13][2];

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		//입력값 저장 및 변수 초기화
		scanf("%d %d %d", &D, &W, &K);
		for (int a = 0; a < D; a++) {
			for (int b = 0; b < W; b++) {
				scanf("%d", &info[a][b]);
			}
		}
		is_end = false;
		//가능한 모든 경우에 대해 탐색(약품 처리를 최소로 사용하는 것부터 최대로 사용하는 것의 순으로 탐색)
		for (int a = 0; a <= D; a++) {
			memset(change, 0, sizeof(int) * 26);
			make_combination(D, W, K, info, change, 0, a, 0);
			if (is_end) {
				printf("#%d %d\n", test_case, a);
				break;
			}
		}
	}

	return 0;
}

void make_combination(int D, int W, int K, int info[13][20], int change[13][2], int index, int change_num, int curr_change_num) {
	if (is_end)	return;
	if (change_num == curr_change_num || index == D) {
		if (curr_change_num != change_num)	return;
		else {
			if(is_pass(D, W, K, info, change))	is_end = true;
		}
		return;
	}

	//index번째 층에 약품 처리를 하며 0으로 설정하는 경우
	change[index][0] = 1;
	change[index][1] = 0;
	make_combination(D, W, K, info, change, index + 1, change_num, curr_change_num + 1);
	//index번째 층에 약품 처리를 하며 1으로 설정하는 경우
	change[index][1] = 1;
	make_combination(D, W, K, info, change, index + 1, change_num, curr_change_num + 1);
	//index번째 층에 약품 처리를 하지 않는 경우
	change[index][0] = 0;
	change[index][1] = 0;
	make_combination(D, W, K, info, change, index + 1, change_num, curr_change_num);
}

bool is_pass(int D, int W, int K, int info[13][20], int change[13][2]) {
	int info_copy[13][20], curr_character, count;
	bool possible;

	//info_copy에 기존 info정보 복사
	for (int a = 0; a < D; a++) {
		for (int b = 0; b < W; b++) {
			info_copy[a][b] = info[a][b];
		}
	}
	//약품 투입
	for (int a = 0; a < D; a++) {
		if (change[a][0] == 1) {
			for (int b = 0; b < W; b++) {
				info_copy[a][b] = change[a][1];
			}
		}
	}
	//각 열에 대해 pass확인
	for (int a = 0; a < W; a++) {
		curr_character = info_copy[0][a];
		count = 1;
		possible = false;
		if (count >= K)	continue;
		for (int b = 1; b < D; b++) {
			if (info_copy[b][a] == curr_character)	count++;
			else {
				curr_character = info_copy[b][a];
				count = 1;
			}

			if (count >= K) {
				possible = true;
				break;
			}
		}
		//만약 통과하지 못하는 열이 있다면 바로 false 반환
		if (!possible)	return false;
	}
	return true;
}