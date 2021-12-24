/*
���� ��ũ : https://www.acmicpc.net/problem/4354
KMP�˰����� �̿��Ͽ� �ذ��� �� �ִ� ������.

���� ��� "abcabc"�� �����Լ� ���� "000123"�̴�. �̴� ���̻�� ���λ簡 3��ŭ �ݺ� �ȴٴ� ���̰�, �ݺ��Ǵ� �κ��� ������ �κ��� ���̴� 6 - 3 = 3�̴�.

�� "abcabc"�� 6 / (6 - 3)��ŭ �ִ�� �ݺ��Ǵ� ���̴�.

�׷��� ���� ��찡 �ִ�. "abcdabc"�� ��� ���λ�� ���̻��� ���̴� 3���� ����. �׷��� ������ s = a^n ������ �����Ѵ�.

�̴� length / (length - pi[length - 1])�� ��Ȯ�ϰ� �������� ���� �׷��� ���� ���� ������ ���� �� �� �ִ�.

���� ���� �������� 0�� ���� s = a^n ������ �����ϴ� ����̰�, �������� 0�� �ƴ� ���� �ݴ��� ����̴�.
*/
#include <cstdio>
#include <cstring>
using namespace std;

char input[1000001];
int pi[1000001];

int main(void) {
	int k, length, answer;

	while (1) {
		scanf("%s", input);
		k = 0;
		length = strlen(input);
		
		if (length == 1 && input[0] == '.')	break;
		//pi�� �ʱ�ȭ
		for (int a = 0; a < length; a++)	pi[a] = 0;
		//pi�� ���
		for (int a = 1; a < length; a++) {
			while (k > 0 && input[a] != input[k])	k = pi[k - 1];
			if (input[a] == input[k])	pi[a] = ++k;
		}

		if (length % (length - pi[length - 1]) != 0)	answer = 1;	//�ݺ��Ǵ� ��찡 ���ٸ� ���� 1
		else	answer = length / (length - pi[length - 1]);	//�ݺ��Ǵ� ��� �ߺ��Ǵ� �κ��� �� ������ �ִ� �ݺ�Ƚ�� ���

		printf("%d\n", answer);
	}

	return 0;
}