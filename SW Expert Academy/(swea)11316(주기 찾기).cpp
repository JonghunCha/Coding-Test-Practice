/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���� A�� ���� ������ A�� ������ �����ߴ� ������ ������ ���� �ֱⰡ ���� �����ϴ� ���̴�.

���� 1,000,000ũ���� �迭�� �̿��� index�� �ش��ϴ� ���� �� ��°�� �����Ͽ����� ����Ѵ�. 

�̹� ����� �� ���� �ٽ� ������ ���� i���� ����ص� ���� ���̰� �ֱ��� ũ�Ⱑ �ȴ�.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int mem[1000000];

int main(int argc, char** argv)
{
	long long T, s, p, q, m, curr, next, count;

	scanf("%lld", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ���� �ʱ�ȭ
		memset(mem, -1, sizeof(int) * 1000000);
		scanf("%lld %lld %lld %lld", &s, &p, &q, &m);
		
		//0��°���� �����Ͽ� mem�� �� ���� �� ��°�� ���Դ��� ���
		mem[s] = 0;
		curr = s;
		count = 0;
		while (1) {
			count++;
			next = ((curr * p) + q) % m;
			if (mem[next] != -1) {	//���� �̹� ���Դ� ���� �� ���� ��� �ֱ��� ũ�⸦ ����ϰ� break
				printf("#%d %d\n", test_case, count - mem[next]);
				break;
			}
			else {
				mem[next] = count;
				curr = next;
			}
		}
	}
	return 0;
}