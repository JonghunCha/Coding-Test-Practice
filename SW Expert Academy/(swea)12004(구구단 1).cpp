/*
문제 링크 : https://swexpertacademy.com/main/main.do
난이도 4 문제를 풀려다 실수로 난이도 3을 푼 문제다.

너무 쉬워서 올릴까 말까 고민하다 일단 풀었으니 올리긴 하도록 하였다.

별다른 설명은 하지 않겠다.
*/
#include <cstdio>
#include <set>
using namespace std;

int main(int argc, char** argv)
{
	int T, N;
	set<int> nums;

	for (int a = 1; a <= 9; a++) {
		for (int b = 1; b <= 9; b++) {
			if (nums.find(a * b) == nums.end())	nums.insert(a * b);
		}
	}

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &N);
		if (nums.find(N) != nums.end())	printf("#%d Yes\n", test_case);
		else	printf("#%d No\n", test_case);
	}
	return 0;
}