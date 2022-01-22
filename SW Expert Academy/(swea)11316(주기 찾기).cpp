/*
문제 링크 : https://swexpertacademy.com/main/main.do
현재 A의 값이 이전에 A의 값으로 등장했던 값으로 나오는 순간 주기가 새로 시작하는 것이다.

따라서 1,000,000크기의 배열을 이용해 index에 해당하는 수가 몇 번째에 등장하였는지 기록한다. 

이미 기록이 된 수가 다시 나왔을 때의 i값과 기록해둔 값의 차이가 주기의 크기가 된다.
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
		//입력값 저장 및 변수 초기화
		memset(mem, -1, sizeof(int) * 1000000);
		scanf("%lld %lld %lld %lld", &s, &p, &q, &m);
		
		//0번째부터 시작하여 mem에 각 수가 몇 번째에 나왔는지 기록
		mem[s] = 0;
		curr = s;
		count = 0;
		while (1) {
			count++;
			next = ((curr * p) + q) % m;
			if (mem[next] != -1) {	//만약 이미 나왔던 수가 또 나온 경우 주기의 크기를 출력하고 break
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