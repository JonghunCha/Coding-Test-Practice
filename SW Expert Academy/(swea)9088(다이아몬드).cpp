/*
문제 링크 : https://swexpertacademy.com/main/main.do
정렬을 통해 쉽게 해결할 수 있는 문제다.

우선 다이아몬드의 크기가 오름차순이 되도록 정렬을 한다.

그런 다음 모든 다이아몬드에 대해 해당 다이아몬드가 묶음에서 가장 작은 다이아몬드일 때 최대 몇 개의 다이아몬드를 같은 묶음으로 둘 수 있는지 계산하며 정답을 갱신하면 된다.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int T, N, K, size, answer = 0, num, curr;
	vector<int> v;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 다이아몬드 정렬
		scanf("%d %d", &N, &K);
		v.clear();
		for (int a = 0; a < N; a++) {
			scanf("%d", &size);
			v.push_back(size);
		}
		sort(v.begin(), v.end());

		//모든 다이아몬드에 대해 가능한 최대 묶음 파악
		answer = 0;
		for (int a = 0; a < N; a++) {
			num = 1;
			curr = v[a];
			for (int b = a + 1; b < N; b++) {
				if (v[b] <= curr + K)	num++;
				else	break;
			}

			if (num > answer)	answer = num;
		}

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}