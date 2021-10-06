/*
문제 링크 : https://www.acmicpc.net/problem/3190
단순히 주어진 조건에 따라 시뮬레이션을 해보면 정답을 쉽게 구할 수 있다.
*/
#include <iostream>
using namespace std;
//뱀이 차지한 공간을 의미하며 각 객체는 1X1의 공간을 나타낸다. 또한 next와 prev는 해당 객체와 연결된 다른 객체 중 꼬리에 가까운 부분, 머리에 가까운 부분을 의미한다.
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
	//입력값 저장
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
	//direction(1 == 위쪽, 2 == 오른쪽, 3 == 아래쪽, 4 == 왼쪽)
	int time = 0, direction = 2;
	Snake* head = new Snake(1, 1, NULL, NULL);
	Snake* tail = head;
	Snake* temp;
	map[1][1] = 2;
	while (1) {
		time++;
		//위쪽으로 이동 할 경우
		if (direction == 1) {
			//게임이 종료하는 조건인지 확인
			if (head->Get_x() == 1 || map[head->Get_x() - 1][head->Get_y()] == 2)	break;
			//사과가 있는 경우(머리를 새로 할당받아 머리부분만 갱신)
			else if (map[head->Get_x() - 1][head->Get_y()] == 1) {
				map[head->Get_x() - 1][head->Get_y()] = 2;
				temp = new Snake(head->Get_x() - 1, head->Get_y(), head, NULL);
				head->Set_prev(temp);
				head = temp;
			}
			//그냥 빈공간인 경우(머리를 새로 할당받아 갱신하고, 꼬리 부분은 하나 없애고 갱신)
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
		//오른쪽으로 이동 할 경우
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
		//아래로 이동 할 경우
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
		//왼쪽으로 이동 할 경우
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
		//방향 전환 확인
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
	//new로 동적 할당 받은 Snake클래스의 객체들 할당 해제
	while (head->Get_next()) {
		temp = head;
		head = head->Get_next();
		delete temp;
	}
	delete head;
	return time;
}