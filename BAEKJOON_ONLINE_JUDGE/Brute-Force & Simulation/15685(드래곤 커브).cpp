/*
���� ��ũ : https://www.acmicpc.net/problem/15685
�ùķ��̼��� �����ϸ� �ذ��� �� �ִ�.

ȸ���ϴ� �κ��� ��� ó�������� �����̴�. �������� �Ʒ��� ���� ��Ģ�� �����ش�.

"K(K > 1)���� �巡�� Ŀ��� K-1���� �巡�� Ŀ�긦 �� ���� �������� 90�� �ð� ���� ȸ�� ��Ų ����, �װ��� �� ���� ���� ���̴�."

�̰��� ���� �̾߱� �ϸ� K����� K-1������ �巡�� Ŀ���� �̵� ������ �������� ȸ���� ����� ���̴�. ���� �� �����ϱ� ���� ������ ������ ���캸�ڴ�.

0���� : 0
1���� : 0 / 1
2���� : 0 1 / 2 1
3���� : 0 1 2 1 / 2 3 2 1
4���� : 0 1 2 1 2 3 2 1 / 2 3 0 3 2 3 2 1

������ 0~3�� ���� �������� ������ ���� �� ���� ������ �ǹ��Ѵ�. ��, 0����� ���������� 0���� �̵��� �׸��̰� ..., 3����� 0 1 2 1 2 3 2 1���� �̵��ߴٴ� �ǹ��̴�.

���� "/"�� �������� ���� ��Ī�Ǵ� ���� �� �� �ִ�. 0->3, 1->2, 2->3, 3->0���� ���� ��Ī�� �Ǿ� ��Ī�� �ȴ�.(���� ���ڷ� ��Ī���� �ʴ� ������ �ð�������� 90�� ȸ���߱� ����)

���� ������ ���� �־��� N���� �巡�� Ŀ�긦 ���ϰ� ���簢���� �� �������� ��� �巡�� Ŀ���� ���� ������ ���ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

void Get_Dragon_Curve(int map[101][101], int x, int y, int d, int g);
int get_2pow(int times);

int main(void) {
	int N, info[20][4], map[101][101], answer = 0;;
	//�Է°� ����
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> info[i][0];
		cin >> info[i][1];
		cin >> info[i][2];
		cin >> info[i][3];
	}
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			map[i][j] = 0;
		}
	}
	//N���� �巡�� Ŀ�긦 ���Ѵ�
	for (int i = 0; i < N; i++) {
		Get_Dragon_Curve(map, info[i][0], info[i][1], info[i][2], info[i][3]);
	}
	//�� �������� ��� �巡�� Ŀ���� ���簢�� ������ ���Ѵ�
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)	answer++;
		}
	}
	
	cout << answer;
	return 0;
}

void Get_Dragon_Curve(int map[101][101], int x, int y, int d, int g) {
	//direction�� ���������� �ش� �巡�� Ŀ���� �̵������ ������ �ǹ�
	char direction[1025];
	int index = 1, pivot;
	//���� �Ҵ� �� ���� �ʱ�ȭ
	int** single_map;
	single_map = new int* [101];
	for (int i = 0; i < 101; i++)	single_map[i] = new int[101];
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			single_map[i][j] = 0;
		}
	}
	for (int i = 0; i < 1025; i++)	direction[i] = 0;
	direction[0] = d + 48;
	//���� �ּ����� ������ ��Ī�� �̿��Ͽ� g������ �巡�� Ŀ�� ���ϱ�
	for (int i = 1; i <= g; i++) {
		pivot = get_2pow(i - 1) - 1;
		for (int j = 0; j < get_2pow(i - 1); j++) {
			if (direction[pivot] == '3') {
				direction[index++] = '0';
				pivot--;
			}
			else {
				direction[index++] = direction[pivot--] + 1;
			}
		}
	}
	//�̵���δ�� �巡�� Ŀ�긦 ���ϰ� ���� 1�� ����
	single_map[y][x] = 1;
	for (int i = 0; i < get_2pow(g); i++) {
		if (direction[i] == '0')	single_map[y][++x] = 1;
		else if (direction[i] == '1')	single_map[--y][x] = 1;
		else if (direction[i] == '2')	single_map[y][--x] = 1;
		else	single_map[++y][x] = 1;
	}
	//��ü �ʿ� �̹� �巡�� Ŀ�긦 ǥ��
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (single_map[i][j] == 1)	map[i][j] = 1;
		}
	}
	//���� �Ҵ� ����
	for (int i = 0; i < 101; i++)	delete []single_map[i];
	delete []single_map;
}

int get_2pow(int times) {
	if (times == 0)	return 1;
	int ret = 1;
	for (int i = 0; i < times; i++) {
		ret *= 2;
	}
	return ret;
}