/*
���� ��ũ : https://www.acmicpc.net/problem/15686
���� Ž������ �ذ��� �� �ִ� ������.

��ü ġŲ���� ��� ġŲ������ �����ų���� ���� ��� ������ ����� ġŲ �Ÿ��� �ּڰ��� ���Ž�Ű�� �ȴ�.
*/
#include <iostream>
using namespace std;

int answer = 1000000;
void Select_M(int N, int map[51][51], int remove_num, int selected_num, int x, int y);
void Get_Minimal_Distance(int N, int map[51][51]);
int Search_Nearest(int N, int map[51][51], int x, int y);

int main(void) {
	int N, M, map[51][51], remove_num, store_num = 0;
	//�Է°� ����
	cin >> N; cin >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)	store_num++;
		}
	}
	//remove_num�� �����ų ġŲ���� ����
	remove_num = store_num - M;
	Select_M(N, map, remove_num, 0, 1, 1);
	cout << answer;
	return 0;
}
//selected_num�� �����ų ġŲ���� �� �� ��������� �ǹ�
void Select_M(int N, int map[51][51], int remove_num, int selected_num, int x, int y) {
	//�����ų ġŲ���� ��� ���� ġŲ �Ÿ��� �ּڰ� ���
	if (remove_num == selected_num) {
		Get_Minimal_Distance(N, map);
		return;
	}
	for (int i = x; i <= N; i++) {
		if (i == x) {
			for (int j = y; j <= N; j++) {
				if (map[i][j] == 2) {
					map[i][j] = 3;
					Select_M(N, map, remove_num, selected_num + 1, i, j);
					map[i][j] = 2;
				}
			}
		}
		else {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] == 2) {
					map[i][j] = 3;
					Select_M(N, map, remove_num, selected_num + 1, i, j);
					map[i][j] = 2;
				}
			}
		}
	}
}
//��ü ���� ���� ġŲ �Ÿ��� �ּڰ��� ���Ѵ�
void Get_Minimal_Distance(int N, int map[51][51]) {
	int distance_sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1) {
				distance_sum += Search_Nearest(N, map, i, j);
			}
		}
	}
	if (distance_sum < answer)	answer = distance_sum;
}
//x,y��ġ�� �ִ� ���� ġŲ �Ÿ� �ּڰ� ��ȯ
int Search_Nearest(int N, int map[51][51], int x, int y) {
	int distance = 10000, temp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 2) {
				temp = 0;
				if (x >= i)	temp += x - i;
				else	temp += i - x;
				if (y >= j)	temp += y - j;
				else	temp += j - y;
				if (temp < distance)	distance = temp;
			}
		}
	}
	return distance;
}