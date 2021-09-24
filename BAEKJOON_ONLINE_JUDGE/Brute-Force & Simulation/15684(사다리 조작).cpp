/*
���� ��ũ : https://www.acmicpc.net/problem/15684
���� Ž������ �ذ��� �� �ִ�.

�߰��ϴ� ���μ��� �ִ� ������ 3���̴�. ���� ���μ��� �߰����� �ʴ� ���, 1�� �߰��ϴ� ���, 2�� �߰��ϴ� ���, 3�� �߰��ϴ� ���, �� 4���� ��츦 ������� ���� Ž���ϸ� ������ ������
�����ϴ� ����� �ִ��� Ȯ���ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int Get_Answer(int N, int H, int connected[31][11], int step, int select);
bool Simulate(int N, int H, int connected[31][11]);

int main(void) {
	int N, M, H, connected[31][11], x, y, temp;
	//�Է°� ����
	cin >> N; cin >> M; cin >> H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			connected[i][j] = 0;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> x; cin >> y;
		connected[x][y] = 1;
	}
	//���μ��� 0��~3������ �߰��ϸ� ������ �����ϴ� ����� �ִ��� Ȯ��
	for (int i = 0; i <= 3; i++) {
		temp = Get_Answer(N, H, connected, i, 0);
		if (temp != -1) {
			cout << temp;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
//step�� ���μ��� �� �� �߰��ϱ�� �ߴ����� �ǹ�, select�� ������� �� ���� ���μ��� �߰��ߴ����� �ǹ�
int Get_Answer(int N, int H, int connected[31][11], int step, int select) {
	//���μ��� 4�� �̻� ����ϴ� ���� ����
	if (step > 3)	return -1;
	//������ ������ ������ ��� step ��ȯ
	if (step == select && Simulate(N, H, connected))	return step; 
	//���μ��� �� �߰������� ������ ������ �������� ���� ���
	if (step == select && !Simulate(N, H, connected))	return -1;
	//���μ��� �߰��� �� �ִ� ��� ���� ����
	int ret = -1, temp;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (connected[i][j] == 0) {
				if (j == 1 && connected[i][j + 1] == 0) {
					connected[i][j] = 1;
					temp = Get_Answer(N, H, connected, step, select + 1);
					if (temp > ret)	ret = temp;
					connected[i][j] = 0;
				}
				else if (j != 1 && connected[i][j - 1] == 0 && connected[i][j + 1] == 0) {
					connected[i][j] = 1;
					temp = Get_Answer(N, H, connected, step, select + 1);
					if (temp > ret)	ret = temp;
					connected[i][j] = 0;
				}
			}
		}
	}
	return ret;
}
//i�� ���μ��� ����� i���� �������� Ȯ��
bool Simulate(int N, int H, int connected[31][11]) {
	int row, col;
	//��� ���μ��� ���� �ùķ��̼�
	for (int i = 1; i <= N; i++) {
		col = i;
		row = 1;
		while (1) {
			//��ٸ� ������ �������� ���� col�� i���� ��� ���
			if (row == H + 1 && col == i)	break;
			//�׷��� ���� ��� false ��ȯ
			if (row == H + 1 && col != i)	return false;
			//�ֺ��� ��ٸ��� ���� col �̵�
			if (col == 1) {
				if (connected[row][1] == 1)		col = 2;
			}
			else {
				if (connected[row][col - 1] == 1)	col = col - 1;
				else if (connected[row][col] == 1)	col = col + 1;
			}
			row++;
		}
	}
	return true;
}