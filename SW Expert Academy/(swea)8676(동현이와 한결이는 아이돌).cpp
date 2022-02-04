/*
���� ��ũ : https://swexpertacademy.com/main/main.do
dp�� �ذ��� �� �ִ� ������.

�޸������ü��� 10001 * 8ũ�� ��ŭ �ξ���. memo[a][b]�� a��° ���ڱ��� ������ ��, "SAMSUNG"�� b��° ���ڱ����� �κ� ���ڿ��� �Ǵ� ������ �����Ѵ�.

�Ʒ� �ڵ带 ���� ��� ��ȭ���� �����Ǵ��� ���� ������ �� �ִ�.
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
		//�Է°� ���� �� �ʱ�ȭ
		scanf("%s", input);
		memset(memo, -1, 70008);
		
		for (int a = 1; a <= 7; a++)	memo[0][a] = 0;	//�Է� ���ڿ��� ������� ���� �� memo���� 0
		for (int a = 0; a <= 10000; a++)	memo[a][0] = 1;	//"SAMSUNG"���ڿ����� �ƹ��͵� ������� ���� �� memo���� 1
		for (int a = 1; a <= 7; a++) {	
			for (int b = 1; b <= strlen(input); b++) {
				if (input[b - 1] == samsung[a]) {	//���� b��° ���ڰ� samsung�� a��° ������ ��
					memo[b][a] = memo[b - 1][a - 1] + memo[b - 1][a];	
					memo[b][a] = memo[b][a] % 1000000007;
				}
				else {	//b��° ���ڰ� ���� ã�� ���ڰ� �ƴ� ��� 
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