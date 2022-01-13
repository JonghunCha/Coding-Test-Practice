/*
문제 링크 : https://swexpertacademy.com/main/main.do
투 포인터 문제와 비슷한 느낌이다.

우뚝 선 산이라는 것은 결국 왼쪽에서는 점점 커지고, 오른쪽으로는 점점 작아지는 지점의 산을 의미 한다.

따라서, 왼쪽에서 몇 번에 걸쳐 점점 커지는지 계산한 값을 left, 오른쪽으로 몇 번에 걸쳐 점점 작아지는지 계산한 값을 right라고 하자.

그럼 해당 지점에서의 우뚝 선 산의 구간은 left * right만큼의 경우가 있을 수 있다.

이를 전체 구간에 대해 계산하면 정답을 구할 수 있다. 코드를 보면 쉽게 이해할 수 있을 것이다.
*/
#include <cstdio>
using namespace std;

int main(int argc, char** argv)
{
	int T, N, prev, curr, left, right;
	bool is_going_up;	//현재 상태에서 높이가 점점 높아진다면 true, 낮아진다면 false
	long long answer;
	
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 변수 초기화
		scanf("%d", &N);
		answer = 0;
		left = 0;
		right = 0;
		//첫 번째, 두 번째 산을 보고 is_going_up 및 left값 초기화
		scanf("%d", &prev);
		scanf("%d", &curr);

		if (curr > prev) {
			left = 1;
			is_going_up = true;
		}
		else {
			is_going_up = false;
		}
		prev = curr;
		//세 번째 산부터 끝까지 반복
		for (int a = 2; a < N; a++) {
			scanf("%d", &curr);
			if (curr > prev) {
				if (is_going_up) {
					left++;
				}
				else {
					answer += left * right;	
					left = 1;
					right = 0;
					is_going_up = true;
				}
			}
			else {
				if (is_going_up) {
					right++;
					is_going_up = false;

				}
				else {
					right++;
				}
			}

			prev = curr;
		}

		answer += left * right;	//마지막 left, right값을 정답에 반영
		printf("#%d %lld\n", test_case, answer);
	}
	return 0;
}