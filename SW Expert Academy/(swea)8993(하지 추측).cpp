/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�ߺ� üũ�� �ϸ� �ذ��� �� �ִ� ������.

N�� ���ǿ� ���� �����ϴ� �̹� ���Դ� ���� �� ������ ������ ������ ����� ���ϴ� ��Ȳ�� �ɸ� ���̴�.

���� set�� �̿��� �ߺ��� N���� ���´ٸ� NO��, while���� ���������� ����ٸ� YES�� ����ϸ� �ȴ�.
*/
#include <cstdio>
#include <set>
using namespace std;

set<unsigned long long> s;

int main(int argc, char** argv)
{
	int T;
	unsigned long long N;
	bool is_possible;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%llu", &N);
		s.clear();
		is_possible = true;
		while (N > 1) {
			if (s.find(N) != s.end()) {	//�ߺ��� ���� ��Ÿ���� NO�� ����ϰ� while ����
				printf("#%d NO\n", test_case);
				is_possible = false;
				break;
			}
			else {	//�ߺ��� ���� �ƴ� ��� set�� �߰�
				s.insert(N); 
			}
			//������ ���ǿ� ���� ���� N�� ����
			if (N % 2 == 0) {
				N = N / 2;
			}
			else {
				N = (3 * N) + 3;
			}
		}
		if(is_possible)		printf("#%d YES\n", test_case);
	}
	return 0;
}