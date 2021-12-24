/*
���� ��ũ : https://www.acmicpc.net/problem/21611
����/�ùķ��̼� ������.

������ ������ ���� ������ �ı� �� ������ �������� �����ϴµ� �����δ� �׷� �ʿ䰡 ����.

������ ĭ�� ��ȣ�� ���� ������ list�� �����Ѵٰ� ���� ��, �ı��Ǵ� �������� list���� ���Ÿ� ���ָ� �ȴ�.

�ı��� �� ���� board���� ����� �������� �̵���Ű�� ���� �ð� �����.

�������� �����ϴ� ���� ������ ���� ��ȭ�� ����Ű�� �� �� �� ���� �ű�� �ȴ�.
*/
#include <iostream>
#include <list>
using namespace std;

int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };
int bead_1 = 0, bead_2 = 0, bead_3 = 0;

void Make_List(int N, int board[50][50], list<int>& __list);
void Remove_Beads(int N, list<int>& __list);
void Make_Beads_Group(int N, int board[50][50], list<int>& __list, list<int>& bead_order);

int main(void) {
	int N, M, board[50][50], magic[100][2];
	int shark_x, shark_y;
	list<int> __list;
	list<int> bead_order;
	//�Է°� ����
	cin >> N; cin >> M;
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			cin >> board[a][b];
		}
	}
	for (int a = 0; a < M; a++) {
		cin >> magic[a][0];
		cin >> magic[a][1];
	}

	shark_x = (N + 1) / 2;
	shark_y = (N + 1) / 2;
	for (int a = 0; a < M; a++) {
		//���ڵ� ���� ����
		for (int b = 1; b <= magic[a][1]; b++) {
			board[shark_x + b * dx[magic[a][0]]][shark_y + b * dy[magic[a][0]]] = -1;
		}
		Make_List(N, board, __list);	//���� ������ ����Ʈ ����
		Remove_Beads(N, __list);	//����Ʈ���� 4�� �̻� ���ӵ� ���� ����
		Make_Beads_Group(N, board, __list, bead_order);	//���� ������ �ǽ��ϰ� ����� board�� �ű�
		//���� ���ڵ带 ���� __list �� bead_order ����
		while (__list.size() > 0)	__list.erase(__list.begin());
		while (bead_order.size() > 0)	bead_order.erase(bead_order.begin());
	}
	cout << bead_1 + 2 * bead_2 + 3 * bead_3;

	return 0;
}

void Make_List(int N, int board[50][50], list<int>& __list) {
	int x = (N + 1) / 2, y = (N + 1) / 2;
	int step = 1, direction = 3;
	bool search_end = false;
	while (!search_end) {
		//ĭ�� ��ȣ�� ���󰡸� ������ ��ȣ�� __list�� �߰�
		for (int a = 1; a <= step; a++) {
			x = x + dx[direction];
			y = y + dy[direction];
			if (x >= 1 && x <= N && y >= 1 && y <= N) {
				//�� �����̸� Ž�� ����
				if (board[x][y] == 0) {
					search_end = true;
					break;
				}
				//������ ��� __list�� �߰�
				else if (board[x][y] > 0)	__list.emplace_back(board[x][y]);
			}
			else {
				search_end = true;
				break;
			}
		}
		if (direction == 1) {
			direction = 3;
			step++;
		}
		else if (direction == 2) {
			direction = 4;
			step++;
		}
		else if (direction == 3)	direction = 2;
		else	direction = 1;
	}
}

void Remove_Beads(int N, list<int>& __list) {
	int cur_bead, cur_bead_num;
	bool is_bead_removed = true;
	while (is_bead_removed) {
		cur_bead = 0;
		cur_bead_num = 0;
		is_bead_removed = false;
		for (list<int>::iterator itr = __list.begin(); itr != __list.end();) {
			//���� ������ ��ȣ�� ���� ������ ��ȣ�� �ٸ��ٸ� cur_bead�� cur_bead_num����
			if (*itr != cur_bead) {
				cur_bead = *itr;
				cur_bead_num = 1;
				itr++;
			}
			//���� ������ ��ȣ�� ������ ������ ���� ���
			else {
				//���� �������� ���� ��ȣ�� ������ 3������ ��� ���� ������ ���ӵǴ� ���� �� 4��°�� �Ǵ� ��
				if (cur_bead_num == 3) {
					itr = __list.erase(itr);	//���� ���� ����
					for (int a = 0; a < 3; a++) {	//������ ���� 3�� ����
						itr--;
						itr = __list.erase(itr);
					}
					cur_bead_num++;
					is_bead_removed = true;
					if (cur_bead == 1)	bead_1 += 4;
					else if (cur_bead == 2)	bead_2 += 4;
					else	bead_3 += 4;
				}
				//�������� ���� ������ 4������ �� ���� ��� �ռ� 4���� ������ �����̱⿡ ���� ������ ����
				else if (cur_bead_num >= 4) {
					itr = __list.erase(itr);
					if (cur_bead == 1)	bead_1++;
					else if (cur_bead == 2)	bead_2++;
					else	bead_3++;
				}
				//���� ���� 4���� �ƴ� ���
				else {
					cur_bead_num++;
					itr++;
				}
			}
		}
	}
}

void Make_Beads_Group(int N, int board[50][50], list<int>& __list, list<int>& bead_order) {
	int cur_bead = 0, cur_bead_num = 0;
	int x = (N + 1) / 2, y = (N + 1) / 2;
	int step, direction;
	bool search_end;
	//������ ��ȭ�� ���� bead_order ����Ʈ�� �ִ´�
	__list.emplace_back(0);
	for (list<int>::iterator itr = __list.begin(); itr != __list.end(); itr++) {
		if (itr == __list.begin()) {
			cur_bead = (*itr);
			cur_bead_num = 1;
			continue;
		}
		if (*itr != cur_bead) {
			bead_order.emplace_back(cur_bead_num);
			bead_order.emplace_back(cur_bead);
			cur_bead = *itr;
			cur_bead_num = 1;
		}
		else {
			cur_bead_num++;
		}
	}
	//bead_order������ ���� board�� ���ʴ�� ����
	for (int b = 1; b <= N; b++) {
		for (int c = 1; c <= N; c++) {
			board[b][c] = 0;
		}
	}
	step = 1;
	direction = 3;
	search_end = false;
	while (!search_end) {
		for (int b = 1; b <= step; b++) {
			x = x + dx[direction];
			y = y + dy[direction];
			if (x >= 1 && x <= N && y >= 1 && y <= N) {
				if (bead_order.size() > 0) {
					cur_bead = *bead_order.begin();
					board[x][y] = cur_bead;
					bead_order.erase(bead_order.begin());
				}
				else {
					search_end = true;
					break;
				}
			}
			else {
				search_end = true;
				break;
			}
		}
		if (direction == 1) {
			direction = 3;
			step++;
		}
		else if (direction == 2) {
			direction = 4;
			step++;
		}
		else if (direction == 3)	direction = 2;
		else	direction = 1;
	}
}