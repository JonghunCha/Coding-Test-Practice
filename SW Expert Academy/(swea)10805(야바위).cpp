/*
문제 링크 : https://swexpertacademy.com/main/main.do
Q번의 위치 바꾸기중 a번째 상황때 가능한 공의 위치를 배열에 표시해 줌으로써 해결할 수 있다.

코드를 보면 쉽게 이해할 수 있을 것이다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
	int T, N, Q, curr_ball_index, A, B, answer;
	bool insert_A, insert_B, used_trick[1000001];

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 변수 초기화
		scanf("%d %d", &N, &Q);
		memset(used_trick, false, sizeof(bool) * (N + 1));
		//N이 1인 경우 예외 처리
		if (N == 1) {
			printf("#%d 1\n", test_case);
			continue;
		}
		//curr_ball_index는 현재까지 속임수를 사용하지 않았을 때 공의 위치이고, used_trick[a]는 속임수를 썻을 때 현재 a번의 위치에 공이 있을 수 있는지를 나타낸다
		curr_ball_index = 1;
		used_trick[2] = true;;
		for (int a = 0; a < Q; a++) {
			scanf("%d %d", &A, &B);
			
			insert_A = false;
			insert_B = false;
			if (used_trick[A])	insert_B = true;	//A번째에 공이 있을 수 있다는 것은 이번 턴의 위치 바꾸기로 인해 B번에도 공이 갈 수 있음
			if (used_trick[B])	insert_A = true;	//위와 마찬가지
			used_trick[A] = false;
			used_trick[B] = false;
			if (insert_A)	used_trick[A] = true;
			if (insert_B)	used_trick[B] = true;

			//속임수를 안쓸 때의 공의 위치 갱신
			if (A == curr_ball_index)	curr_ball_index = B;
			else if (B == curr_ball_index)	curr_ball_index = A;
			//현재 단계에서 속임수를 쓴다고 할 때 위치를 used_trick에 표시
			if (curr_ball_index == 1) {
				used_trick[2] = true;;
			}
			else if (curr_ball_index == N) {
				used_trick[N - 1] = true;
			}
			else {
				used_trick[curr_ball_index - 1] = true;
				used_trick[curr_ball_index + 1] = true;
			}
		}
		//정답계산 및 출력
		answer = 0;
		for (int a = 1; a <= N; a++) {
			if (used_trick[a])	answer++;
		}
		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}