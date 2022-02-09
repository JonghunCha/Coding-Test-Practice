/*
���� ��ũ : https://www.acmicpc.net/problem/2437
�׸��� �˰��� ������.

���� ��ü�� ���� ������ �����ϰڴ�.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
	int N, inputs[1000], answer;
	//�Է°� ���� �� ����
	scanf("%d", &N);
	for (int a = 0; a < N; a++)	scanf("%d", &inputs[a]);
	sort(inputs, inputs + N);
	//���԰� 1�� �߰� ���� ���� ó��
	if (inputs[0] > 1) {
		printf("1\n");
		return 0;
	}
	
	answer = 1;
	for (int a = 1; a < N; a++) {
		if (answer < inputs[a] - 1) {
			break;
		}
		else {
			answer += inputs[a];
		}
	}

	printf("%d\n", answer + 1);

	return 0;
}