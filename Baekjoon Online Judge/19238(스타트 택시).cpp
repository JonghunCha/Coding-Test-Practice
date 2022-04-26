/*
���� ��ũ : https://www.acmicpc.net/problem/19238
BFS�� �̿��� ���� Ž������ �ذ��� �� �ִ�.

ũ�� 2�ܰ�� ���� �� ������ �� �� BFS�� �̿��� �ִ� �Ÿ� ã��� �ذ��� �� �ִ�.

1. �°��� ã�� ��
2. ã�� �°��� �������� �̵���Ű�� ��
*/
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, M, fuel;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
bool succeed = true;

void Find_Passenger(int map[21][21], int taxi[2], int passenger[21][21], int destination[401][2], int visit[21][21]);
int Distance_To_Destination(int map[21][21], int destination[401][2], int passenger_num, int _x, int _y);

int main(void) {
	int map[21][21], taxi[2], passenger[21][21], destination[401][2], visit[21][21];
	int passenger_x, passenger_y, destination_x, destination_y;
	//�Է°� ����
	cin >> N; cin >> M; cin >> fuel;
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			cin >> map[a][b];
			passenger[a][b] = 0;
		}
	}
	cin >> taxi[0]; cin >> taxi[1];
	for (int a = 1; a <= M; a++) {
		cin >> passenger_x;
		cin >> passenger_y;
		cin >> destination_x;
		cin >> destination_y;
		passenger[passenger_x][passenger_y] = a;
		destination[a][0] = destination_x;
		destination[a][1] = destination_y;
	}
	//���� ���� ������ �� ���� �ݺ�
	while (1) {
		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= N; b++) {
				visit[a][b] = 0;
			}
		}
		Find_Passenger(map, taxi, passenger, destination, visit);
		if (!succeed) {
			cout << -1;
			break;
		}
		else {
			M--;
		}
		if (M == 0) {
			cout << fuel;
			break;
		}
	}

	return 0;
}
//�°��� ã�� �Լ�(�켱���� : �Ÿ� -> �� �� -> �� ��)
void Find_Passenger(int map[21][21], int taxi[2], int passenger[21][21], int destination[401][2], int visit[21][21]) {
	int nx, ny, distance, fuel_use, x, y, candidate_x = -1, candidate_y = -1, candidate_distance = 10000;
	queue<tuple<int, int, int>> q;

	succeed = true;
	//���� �ýð� ��ġ�� ���� ť�� �ִ´�
	visit[taxi[0]][taxi[1]] = 1;
	q.emplace(make_tuple(taxi[0], taxi[1], 0));
	//ť�� �������� �ݺ�
	while (!q.empty()) {
		x = get<0>(q.front());
		y = get<1>(q.front());
		distance = get<2>(q.front());
		q.pop();
		//���� �°��� �ִ� ������ ��
		if (passenger[x][y] != 0) {
			//�Ÿ��� ���� �ĺ� �°����� ª�� ���(BFS�� �̿��߱⿡ ó������ �°��� �߰����� ���� �ش��)
			if (distance < candidate_distance) {
				candidate_x = x;
				candidate_y = y;
				candidate_distance = distance;
			}
			//�Ÿ��� ���ٸ� ���� ���� ���� �� ������ ���ٸ� ���� ���� ��
			else if (distance == candidate_distance) {
				if (x < candidate_x) {
					candidate_x = x;
					candidate_y = y;
				}
				else if (x == candidate_x && y < candidate_y) {
					candidate_x = x;
					candidate_y = y;
				}
			}
		}
		//�ĺ� �°����� ª�ų� ���� �Ÿ��� ���ؼ��� Ž��
		if (distance <= candidate_distance) {
			for (int a = 0; a < 4; a++) {
				nx = x + dx[a];
				ny = y + dy[a];
				if (nx > 0 && nx <= N && ny > 0 && ny <= N && map[nx][ny] == 0 && visit[nx][ny] == 0) {
					q.emplace(make_tuple(nx, ny, distance + 1));
					visit[nx][ny] = 1;
				}
			}
		}
	}
	//�ĺ� �°��� �������� �̵�
	if (candidate_distance != 10000) {
		x = candidate_x;
		y = candidate_y;
		distance = candidate_distance;
		fuel_use = Distance_To_Destination(map, destination, passenger[x][y], x, y);
		if (fuel < distance + fuel_use || fuel_use == -1) {
			succeed = false;
			return;
		}
		else {
			taxi[0] = destination[passenger[x][y]][0];
			taxi[1] = destination[passenger[x][y]][1];
			fuel = fuel - distance + fuel_use;
			passenger[x][y] = 0;
			return;
		}
	}
	succeed = false;
}

int Distance_To_Destination(int map[21][21], int destination[401][2], int passenger_num, int _x, int _y) {
	int visit[21][21], nx, ny, distance = 1, x, y;
	queue<tuple<int, int, int>> q;

	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			visit[a][b] = 0;
		}
	}
	//�°��� ��ġ�κ��� BFS�� �̿��Ͽ� ���������� �ִ� �Ÿ��� ã�� ���� ��ȯ�Ѵ�.
	visit[_x][_y] = 1;
	q.emplace(make_tuple(_x, _y, 0));
	while (!q.empty()) {
		x = get<0>(q.front());
		y = get<1>(q.front());
		distance = get<2>(q.front());
		q.pop();
		if (x == destination[passenger_num][0] && y == destination[passenger_num][1]) {
			return distance;
		}
		else {
			for (int a = 0; a < 4; a++) {
				nx = x + dx[a];
				ny = y + dy[a];
				if (nx > 0 && nx <= N && ny > 0 && ny <= N && map[nx][ny] == 0 && visit[nx][ny] == 0) {
					q.emplace(make_tuple(nx, ny, distance + 1));
					visit[nx][ny] = 1;
				}
			}
		}
	}
	return -1;
}