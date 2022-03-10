/*
���� ��ũ : https://swexpertacademy.com/main/main.do
������ ���� ���� �ذ��� �� �ִ� ������.

�켱 ���̾Ƹ���� ũ�Ⱑ ���������� �ǵ��� ������ �Ѵ�.

�׷� ���� ��� ���̾Ƹ�忡 ���� �ش� ���̾Ƹ�尡 �������� ���� ���� ���̾Ƹ���� �� �ִ� �� ���� ���̾Ƹ�带 ���� �������� �� �� �ִ��� ����ϸ� ������ �����ϸ� �ȴ�.
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
		//�Է°� ���� �� ���̾Ƹ�� ����
		scanf("%d %d", &N, &K);
		v.clear();
		for (int a = 0; a < N; a++) {
			scanf("%d", &size);
			v.push_back(size);
		}
		sort(v.begin(), v.end());

		//��� ���̾Ƹ�忡 ���� ������ �ִ� ���� �ľ�
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