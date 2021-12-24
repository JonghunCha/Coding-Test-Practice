/*
문제 링크 : https://swexpertacademy.com/main/main.do
중복을 고려한 완전탐색으로 해결할 수 있다.

우선 최대 100개의 문제이고 각 문제는 최대 100점 짜리이다.

따라서 최대 점수는 10000점이고 이는 배열로 충분히 중복 제거를 할 수 있음을 의미한다.

코드에선 bool자료형 10001크기의 배열에 각 점수가 가능하다면 true, 불가능 하다면 false를 저장한다.

이제 한 문제씩 살피며 이전에 나온 점수에 현재 점수를 더한 값이 이미 나온 값이라면 무시, 새로운 값이라면 큐에 저장해뒀다 일괄적으로 bool배열을 수정하는 식으로 구현하면 된다.
*/
#include <cstdio>
#include <queue>
using namespace std;

bool visited[10001];
queue<int> __queue;

int main(int argc, char** argv)
{
	int T, N, score[100], temp, max_score, answer;

	visited[0] = true;	//0점은 항상 존재
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 변수 초기화
		scanf("%d", &N);
		for (int a = 0; a < N; a++)	scanf("%d", &score[a]);
		for (int a = 1; a <= 10000; a++)	visited[a] = false;
		//max_score는 현재까지의 최대 점수를 의미하며, 0점은 항상 존재하기에 answer는 1부터 시작
		max_score = 0;
		answer = 1;
		for (int a = 0; a < N; a++) {	//모든 문제에 대해
			for (int b = 0; b <= max_score; b++) {	//현재까지의 최대 점수까지 살핀다
				//이전 문제들로 b점수가 나올 수 있으며 b + score[a]가 아직 나오지 않은 점수일 때
				if (visited[b] == true && b + score[a] <= 10000 && visited[b + score[a]] == false) {	
					__queue.push(b + score[a]);
				}
			}
			//새롭게 추가된 점수들 반영
			while (!__queue.empty()) {
				if (__queue.front() > max_score)	max_score = __queue.front();	//max_score 계속해서 갱신
				visited[__queue.front()] = true;	//새로운 점수 true로 설정
				answer++;
				__queue.pop();
			}
		}

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}