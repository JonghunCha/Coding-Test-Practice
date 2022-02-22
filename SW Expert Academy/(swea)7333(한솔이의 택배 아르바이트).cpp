/*
문제 링크 : https://swexpertacademy.com/main/main.do
투 포인터로 해결할 수 있는 문제다.

우선 박스들을 오름차순으로 정렬한다.

그런 다음 포인터 하나는 가장 가벼운 박스, 다른 하나는 가장 무거운 박스를 가르키도록 한다.

운반하는 횟수를 최대로 하기 위해선 한 번에 운반하는 박스의 수가 가능한 적어야 한다.

따라서 가장 무거운 박스 하나를 고르고, 해당 박스를 가장 위에 둘 때 현수가 무게를 50이상이라고 착각하도록 가장 가벼운 박스를 채워 넣는 작업을 모든 박스를 옮길 때까지 반복하면 된다.

아래 코드를 보면 이해가 쉬울 것이다.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int T, N, box, ptr1, ptr2, answer, box_needed;
	vector<int> boxes;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 정렬
		scanf("%d", &N);
		boxes.clear();
		for (int a = 0; a < N; a++) {
			scanf("%d", &box);
			boxes.push_back(box);
		}
		sort(boxes.begin(), boxes.end());
		//포인터 두 개를 가장 왼쪽, 오른쪽에 둔다
		ptr1 = 0;
		ptr2 = N - 1;
		answer = 0;
		while (ptr1 <= ptr2) {
			//남은 박스들로 50kg을 맞출 수 없는 경우로, 이전에 결정된 운반 조합에 포함시켜야 됨
			if (boxes[ptr2] * (ptr2 - ptr1 + 1) < 50)	break;

			if (boxes[ptr2] >= 50) {	//만약 가장 무거운 박스가 50kg이상일 경우 해당 박스만 운반
				answer++;
				ptr2--;
			}
			else {	//가장 무거운 박스를 맨 위에 둘 때 몇 개의 박스가 있어야 하는지 계산 + 가벼운 박스의 포인터 높여주기
				box_needed = 2;
				while (1) {
					if (boxes[ptr2] * box_needed >= 50)	break;
					box_needed++;
				}

				answer++;
				ptr2--;
				ptr1 += box_needed - 1;
			}
		}

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}