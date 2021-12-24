/*
���� ��ũ : https://www.acmicpc.net/problem/3190
�ܼ��� �־��� ���ǿ� ���� �ùķ��̼��� �غ��� ������ ���� ���� �� �ִ�.
*/
#include <iostream>
using namespace std;
//���� ������ ������ �ǹ��ϸ� �� ��ü�� 1X1�� ������ ��Ÿ����. ���� next�� prev�� �ش� ��ü�� ����� �ٸ� ��ü �� ������ ����� �κ�, �Ӹ��� ����� �κ��� �ǹ��Ѵ�.
class Snake {
private:
	int x;
	int y;
	Snake* next;
	Snake* prev;
public:
	Snake(int _x, int _y, Snake* _next, Snake* _prev)
		:x(_x), y(_y), next(_next), prev(_prev) {}
	void Set_next(Snake* _next) { next = _next; }
	void Set_prev(Snake* _prev) { prev = _prev; }
	int Get_x() { return x; }
	int Get_y() { return y; }
	Snake* Get_next() { return next; }
	Snake* Get_prev() { return prev; }
};

int Start_Game(int N, int L, int map[101][101], int rotate_time[100], char rotate_direction[100]);

int main(void) {
	int N, K, L, map[101][101], x, y, rotate_time[100];
	char rotate_direction[100];
	//�Է°� ����
	cin >> N; cin >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = 0;
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> x; cin >> y;
		map[x][y] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> rotate_time[i];
		cin >> rotate_direction[i];
	}

	int result = Start_Game(N, L, map, rotate_time, rotate_direction);
	cout << result;

	return 0;
}

int Start_Game(int N, int L, int map[101][101], int rotate_time[100], char rotate_direction[100]) {
	//direction(1 == ����, 2 == ������, 3 == �Ʒ���, 4 == ����)
	int time = 0, direction = 2;
	Snake* head = new Snake(1, 1, NULL, NULL);
	Snake* tail = head;
	Snake* temp;
	map[1][1] = 2;
	while (1) {
		time++;
		//�������� �̵� �� ���
		if (direction == 1) {
			//������ �����ϴ� �������� Ȯ��
			if (head->Get_x() == 1 || map[head->Get_x() - 1][head->Get_y()] == 2)	break;
			//����� �ִ� ���(�Ӹ��� ���� �Ҵ�޾� �Ӹ��κи� ����)
			else if (map[head->Get_x() - 1][head->Get_y()] == 1) {
				map[head->Get_x() - 1][head->Get_y()] = 2;
				temp = new Snake(head->Get_x() - 1, head->Get_y(), head, NULL);
				head->Set_prev(temp);
				head = temp;
			}
			//�׳� ������� ���(�Ӹ��� ���� �Ҵ�޾� �����ϰ�, ���� �κ��� �ϳ� ���ְ� ����)
			else {
				map[head->Get_x() - 1][head->Get_y()] = 2;
				temp = new Snake(head->Get_x() - 1, head->Get_y(), head, NULL);
				head->Set_prev(temp);
				head = temp;
				map[tail->Get_x()][tail->Get_y()] = 0;
				temp = tail;
				tail = tail->Get_prev();
				tail->Set_next(NULL);
				delete temp;
			}
		}
		//���������� �̵� �� ���
		else if (direction == 2) {
			if (head->Get_y() == N || map[head->Get_x()][head->Get_y() + 1] == 2)	break;
			else if (map[head->Get_x()][head->Get_y() + 1] == 1) {
				map[head->Get_x()][head->Get_y() + 1] = 2;
				temp = new Snake(head->Get_x(), head->Get_y() + 1, head, NULL);
				head->Set_prev(temp);
				head = temp;
			}
			else {
				map[head->Get_x()][head->Get_y() + 1] = 2;
				temp = new Snake(head->Get_x(), head->Get_y() + 1, head, NULL);
				head->Set_prev(temp);
				head = temp;
				map[tail->Get_x()][tail->Get_y()] = 0;
				temp = tail;
				tail = tail->Get_prev();
				tail->Set_next(NULL);
				delete temp;
			}
		}
		//�Ʒ��� �̵� �� ���
		else if (direction == 3) {
			if (head->Get_x() == N || map[head->Get_x() + 1][head->Get_y()] == 2)	break;
			else if (map[head->Get_x() + 1][head->Get_y()] == 1) {
				map[head->Get_x() + 1][head->Get_y()] = 2;
				temp = new Snake(head->Get_x() + 1, head->Get_y(), head, NULL);
				head->Set_prev(temp);
				head = temp;
			}
			else {
				map[head->Get_x() + 1][head->Get_y()] = 2;
				temp = new Snake(head->Get_x() + 1, head->Get_y(), head, NULL);
				head->Set_prev(temp);
				head = temp;
				map[tail->Get_x()][tail->Get_y()] = 0;
				temp = tail;
				tail = tail->Get_prev();
				tail->Set_next(NULL);
				delete temp;
			}
		}
		//�������� �̵� �� ���
		else if (direction == 4) {
			if (head->Get_y() == 1 || map[head->Get_x()][head->Get_y() - 1] == 2)	break;
			else if (map[head->Get_x()][head->Get_y() - 1] == 1) {
				map[head->Get_x()][head->Get_y() - 1] = 2;
				temp = new Snake(head->Get_x(), head->Get_y() - 1, head, NULL);
				head->Set_prev(temp);
				head = temp;
			}
			else {
				map[head->Get_x()][head->Get_y() - 1] = 2;
				temp = new Snake(head->Get_x(), head->Get_y() - 1, head, NULL);
				head->Set_prev(temp);
				head = temp;
				map[tail->Get_x()][tail->Get_y()] = 0;
				temp = tail;
				tail = tail->Get_prev();
				tail->Set_next(NULL);
				delete temp;
			}
		}
		//���� ��ȯ Ȯ��
		for (int i = 0; i < L; i++) {
			if (time == rotate_time[i]) {
				if (rotate_direction[i] == 'L') {
					if (direction == 1)	direction = 4;
					else if (direction == 2)	direction = 1;
					else if (direction == 3)	direction = 2;
					else	direction = 3;
				}
				else {
					if (direction == 1)	direction = 2;
					else if (direction == 2)	direction = 3;
					else if (direction == 3)	direction = 4;
					else	direction = 1;
				}
				break;
			}
		}
	}
	//new�� ���� �Ҵ� ���� SnakeŬ������ ��ü�� �Ҵ� ����
	while (head->Get_next()) {
		temp = head;
		head = head->Get_next();
		delete temp;
	}
	delete head;
	return time;
}