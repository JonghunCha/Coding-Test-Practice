/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���� ���̵��� ����� �ʾҴ�. 

�׷��� �ùķ��̼� �ڵ�� �׻� ������� ������� ����� ������ �׻� ��ɺ��� ���ȭ ���� ������� �����ϰ� �ؾ߰ڴ�.
*/
#include <cstdio>
using namespace std;

int main(void) {
	int T, N, X, board[20][20], answer = 0, height, num;
	bool flag;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		//�Է°� ����
		scanf("%d %d", &N, &X);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				scanf("%d", &board[a][b]);
			}
		}
		//���� ����� �� üũ
		answer = 0;
		for (int a = 0; a < N; a++) {
			height = board[a][0];
			num = 1;
			for (int b = 1; b < N;) {	
				flag = true;
				if (board[a][b] == height) {	//���̰� ���ٸ� ���̸� �����ϸ� ���� ī��Ʈ�� �÷��ش�
					num++;
					b++;
				}
				else if (board[a][b] == height + 1) {	//��������� ���̺��� 1 ū ���
					if (num >= X) {	//�������� ���ӵ� ������ X���� ũ���� ���� ����
						height = board[a][b];
						num = 1;
						b++;
					}
					else {	//�׷��� ���� ��� 
						flag = false;
						break;
					}
				}
				else if (board[a][b] == height - 1) {	//��������� ���̺��� 1 ���� ���
					if (b + X > N) {	//���� ���� ������ X���� �۴ٸ� ���� �Ұ�
						flag = false;
						break;
					}
					for (int c = b; c < b + X; c++) {	//���� X���� ������ ���� �������� �˻�
						if (board[a][c] != height - 1) {
							flag = false;
							break;
						}
					}
					if (!flag)	break;	
					height = board[a][b];
					num = 0;
					b += X;
				}
				else {	//�������̰� 2 �̻��� ��� �׻� �Ұ���
					flag = false;
					break;
				}
			}
			if (flag)	answer++;
		}
		//���� ����� �� üũ
		for (int a = 0; a < N; a++) {
			height = board[0][a];
			num = 1;
			flag = true;
			for (int b = 1; b < N;) {
				if (board[b][a] == height) {
					num++;
					b++;
				}
				else if (board[b][a] == height + 1) {
					if (num >= X) {
						height = board[b][a];
						num = 1;
						b++;
					}
					else {
						flag = false;
						break;
					}
				}
				else if (board[b][a] == height - 1) {
					if (b + X > N) {
						flag = false;
						break;
					}
					for (int c = b; c < b + X; c++) {
						if (board[c][a] != height - 1) {
							flag = false;
							break;
						}
					}
					if (!flag)	break;
					height = board[b][a];
					num = 0;
					b += X;
				}
				else {
					flag = false;
					break;
				}
			}
			if (flag)	answer++;
		}

		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}