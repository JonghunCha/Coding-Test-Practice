/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���� Ǯ�� ��ü�� ����� ������, �ð��ʰ��� ������ ��������.

���͸� ����ϸ� �ð��ʰ��� ���� pair�迭�� �̿��Ͽ���.

�켱 D�� �������� ������������ ������ �Ѵ�.

�ʱ� answer�� ���� ū D�� �������� ������ N���� ������ ���� �Ʒ��� ����� ��ģ��.

answer�� ���� �������� ũ�ٸ� answer�� ���� ������ D - T�� ����(�̰��� ���� ���� ���Ŀ� �����ؾ� �� ������ ���� ������ ������� �ذ��� �� ������ �ǹ�)

answer�� ���� �������� �۰ų� ���ٸ� answer���� ���� ������ T�� ����(���� ������ ���� answer���� �ʰ� ������ ������ ������ ������ ���ϴ� ��Ȳ)
*/
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> TD_vec[1000000];
//������ ���� compare �Լ�
bool compare(pair<int, int>& p1, pair<int, int>& p2) {
	if (p1.first > p2.first)	return true;
	else	return false;
}

int main(int argc, char** argv)
{
	int TC, N, T, D, answer;
	
	scanf("%d", &TC);
	for (int test_case = 1; test_case <= TC; ++test_case)
	{
		//�Է°� ����
		scanf("%d", &N);
		for (int a = 0; a < N; a++) {
			scanf("%d %d", &T, &D);
			TD_vec[a].first = D;
			TD_vec[a].second = T;
		}
		//TD_vec�� ������������ ����
		sort(TD_vec, TD_vec + N, compare);
		//������ ������ ������� ���� ����
		answer = TD_vec[0].first;
		for (int a = 0; a < N; a++) {
			if (answer > TD_vec[a].first) {
				answer = TD_vec[a].first - TD_vec[a].second;
			}
			else {
				answer = answer - TD_vec[a].second;
			}
		}

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}