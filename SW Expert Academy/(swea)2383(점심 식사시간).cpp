/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���� Ž������ �ذ��� �� �ִ�.

�� ����� � ����� �̿��ϴ����� ���� ��� ������ ����ϰ� �� �� ���� �ִ� �ð��� �ҿ��ϴ� ��츦 ���ϸ� �ȴ�.

�ڵ带 ���� ���� ���� ������ ������ ������.
*/
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int answer = 1000;

void make_combination(int N, int room[10][10], int stair[2][3], int combination[10], int index, int people_num);
void calculate(int N, int room[10][10], int stair[2][3], int combination[10]);
bool compare(int a, int b);

int main(int argc, char** argv)
{
	int T, N, room[10][10], stair[2][3], index, combination[10], people_num;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ���� �� ����
		index = 0;
		people_num = 0;
		scanf("%d", &N);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				scanf("%d", &room[a][b]);
				if (room[a][b] > 1) {
					stair[index][0] = a;
					stair[index][1] = b;
					stair[index++][2] = room[a][b];
				}
				if (room[a][b] == 1)	people_num++;
			}
		}

		answer = 1000;
		make_combination(N, room, stair, combination, 0, people_num);
		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}
//�� ����� ��� ����� �̿��ϴ����� ���� ��� ������ ����ϰ� �ð� ���
void make_combination(int N, int room[10][10], int stair[2][3], int combination[10], int index, int people_num) {
	if (index == people_num) {
		calculate(N, room, stair, combination);
		return;
	}

	combination[index] = 0;
	make_combination(N, room, stair, combination, index + 1, people_num);
	combination[index] = 1;
	make_combination(N, room, stair, combination, index + 1, people_num);
}
//�� ���տ� ���� �ҿ� �ð� ���
void calculate(int N, int room[10][10], int stair[2][3], int combination[10]) {
	int index = 0;
	vector<int> stair1, stair2;
	queue<int> stair1_arrive, stair1_end, stair2_arrive, stair2_end;
	//�� ��ܿ� ����� �����ϴ� �ð��� ����ϰ� ������������ ����
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (room[a][b] == 1) {
				if (combination[index] == 0)	stair1.push_back(abs(a - stair[0][0]) + abs(b - stair[0][1]));
				else	stair2.push_back(abs(a - stair[1][0]) + abs(b - stair[1][1]));
				index++;
			}
		}
	}
	sort(stair1.begin(), stair1.end(), compare);
	sort(stair2.begin(), stair2.end(), compare);
	//stair1_arrive, stair2_arrive ť�� ������� ��ܿ� �����ϴ� �ð��� ����
	for (int a = 0; a < stair1.size(); a++)	stair1_arrive.push(stair1[a]);
	for (int a = 0; a < stair2.size(); a++)	stair2_arrive.push(stair2[a]);
	//��� ����� ����� ����� ������ �ݺ�
	for (int count = 1; count <= 1000; count++) {
		while (1) {	//ù ��° ����� �� ������ ����� ť���� pop
			if (stair1_end.size() > 0 && stair1_end.front() == count)	stair1_end.pop();
			else	break;
		}
		while (1) {	//�� ��° ����� �� ������ ����� ť���� pop
			if (stair2_end.size() > 0 && stair2_end.front() == count)	stair2_end.pop();
			else	break;
		}
		while (1) {	//������ ����� 1���� ��ٷ����� ��� ���� 3�� �̸��� ��� ��� �������� ����
			if (stair1_arrive.size() > 0 && stair1_arrive.front() < count && stair1_end.size() < 3) {
				stair1_end.push(count + stair[0][2]);
				stair1_arrive.pop();
			}
			else {
				break;
			}
		}	
		while (1) {	//������ ����� 1���� ��ٷ����� ��� ���� 3�� �̸��� ��� ��� �������� ����
			if (stair2_arrive.size() > 0 && stair2_arrive.front() < count && stair2_end.size() < 3) {
				stair2_end.push(count + stair[1][2]);
				stair2_arrive.pop();
			}
			else {
				break;
			}
		}
		//��� ����� ����� ������ ��� ������.
		if (stair1_arrive.size() == 0 && stair1_end.size() == 0 && stair2_arrive.size() == 0 && stair2_end.size() == 0) {
			if (count < answer)	answer = count;
			break;
		}
	}
}

bool compare(int a, int b) {
	return a < b;
}