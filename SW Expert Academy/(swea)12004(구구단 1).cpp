/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���̵� 4 ������ Ǯ���� �Ǽ��� ���̵� 3�� Ǭ ������.

�ʹ� ������ �ø��� ���� ����ϴ� �ϴ� Ǯ������ �ø��� �ϵ��� �Ͽ���.

���ٸ� ������ ���� �ʰڴ�.
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