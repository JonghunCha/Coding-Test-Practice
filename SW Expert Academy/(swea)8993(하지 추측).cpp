/*
문제 링크 : https://swexpertacademy.com/main/main.do
중복 체크를 하면 해결할 수 있는 문제다.

N을 조건에 따라 변형하다 이미 나왔던 값이 또 나오면 영원히 루프를 벗어나지 못하는 상황에 걸린 것이다.

따라서 set을 이용해 중복된 N값이 들어온다면 NO를, while문을 정상적으로 벗어난다면 YES를 출력하면 된다.
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
			if (s.find(N) != s.end()) {	//중복된 값이 나타나면 NO를 출력하고 while 종료
				printf("#%d NO\n", test_case);
				is_possible = false;
				break;
			}
			else {	//중복된 값이 아닌 경우 set에 추가
				s.insert(N); 
			}
			//문제의 조건에 따라 다음 N값 지정
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