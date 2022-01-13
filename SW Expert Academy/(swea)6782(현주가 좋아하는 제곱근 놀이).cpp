/*
문제 링크 : https://swexpertacademy.com/main/main.do
실수형과 정수형 사이의 캐스팅을 이해하면 쉽게 해결할 수 있다.

최소한의 조작으로 N을 2로 만들기 위해선, 기회가 될 때마다 루트를 씌워야 한다.

루트를 씌운 결과가 정수일 때만 루트를 씌울 수 있는데 이에 대한 판단은 캐스팅을 통해서 알 수 있다.

실수형을 정수형으로 형변환 할때는 소숫점 부분이 버려진다.

즉, 루트(5)를 실수형에 저장을 하고 이를 다시 정수형으로 변환하면 2라는 값을 가지게 된다.(루트(5)는 2.xxx이기 때문)

만약 루트(9)를 실수형에 저장하면 3.0000이 되고 이를 정수형으로 변환해도 3이 된다.

따라서 형 변환을 한 뒤 제곱한 값이 원래 N과 같으면 루트를 씌울 수 있는 상황이고, N보다 작은 경우 루트를 씌울 수 없는 상황이다.
*/
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
	int T, answer;
	long long N, temp_ll;
	double temp_d;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%lld", &N);
		
		answer = 0;
		while (N > 2) {
			temp_d = sqrt(N);
			temp_ll = (long long)temp_d;

			if (temp_ll * temp_ll == N) {	//N에 루트를 씌웠을 때 정수인 경우
				answer++;
				N = temp_ll;
			}
			else {	//N에 루트를 씌울 수 없는 경우
				answer += (temp_ll + 1) * (temp_ll + 1) - N;	//루트를 씌울 수 있을 때까지 +1작업을 반복
				answer++;	//루트를 씌운다
				N = temp_ll + 1;
			}
		}

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}