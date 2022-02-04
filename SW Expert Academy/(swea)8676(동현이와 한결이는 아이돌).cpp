/*
문제 링크 : https://swexpertacademy.com/main/main.do
dp로 해결할 수 있는 문제다.

메모이제시션을 10001 * 8크기 만큼 두었다. memo[a][b]는 a번째 문자까지 보았을 때, "SAMSUNG"의 b번째 문자까지가 부분 문자열이 되는 갯수를 저장한다.

아래 코드를 보면 어떠한 점화식이 성립되는지 쉽게 이해할 수 있다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int memo[10001][8];
char samsung[8] = { '0', 'S', 'A', 'M', 'S', 'U', 'N', 'G' };

int main(int argc, char** argv)
{
	int T;
	char input[10001];

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 초기화
		scanf("%s", input);
		memset(memo, -1, 70008);
		
		for (int a = 1; a <= 7; a++)	memo[0][a] = 0;	//입력 문자열을 사용하지 않을 때 memo값은 0
		for (int a = 0; a <= 10000; a++)	memo[a][0] = 1;	//"SAMSUNG"문자열에서 아무것도 사용하지 않을 때 memo값은 1
		for (int a = 1; a <= 7; a++) {	
			for (int b = 1; b <= strlen(input); b++) {
				if (input[b - 1] == samsung[a]) {	//만약 b번째 문자가 samsung의 a번째 문자일 때
					memo[b][a] = memo[b - 1][a - 1] + memo[b - 1][a];	
					memo[b][a] = memo[b][a] % 1000000007;
				}
				else {	//b번째 문자가 현재 찾는 문자가 아닐 경우 
					memo[b][a] = memo[b - 1][a];
				}
			}
		}

		printf("#%d %d\n", test_case, memo[strlen(input)][7]);
	}
	return 0;
}

int DP(char input[10001], int index1, int index2) {
}