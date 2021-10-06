/*
문제 링크 : https://www.acmicpc.net/problem/14891
단순 구현 문제다.

문제 조건에 따라 톱니바퀴를 회전을 수행하고 정답을 계산하면 된다.
*/
#include <iostream>
using namespace std;

void Rotate(char wheels[5][8], int wheel_num, int direction);

int main(void) {
	int K, rotate[100][2], answer = 0;
	char wheels[5][8];
	//인접한 바퀴가 회전함에 따라 연쇄적으로 회전 하는지를 나타내는 변수(true면 회전, false면 회전x)
	bool connect1, connect2, connect3;
	//입력값 저장
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> wheels[i][j];
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> rotate[i][0];
		cin >> rotate[i][1];
	}
	//모든 회전을 수행
	for (int i = 0; i < K; i++) {
		//1번 2번 바퀴의 인접 부분 확인
		if (wheels[1][2] != wheels[2][6])	connect1 = true;
		else	connect1 = false;
		//2번 3번 바퀴의 인접 부분 확인
		if (wheels[2][2] != wheels[3][6])	connect2 = true;
		else	connect2 = false;
		//3번 4번 바퀴의 인접 부분 확인
		if (wheels[3][2] != wheels[4][6])	connect3 = true;
		else	connect3 = false;
		//1번 바퀴를 회전하는 경우
		if (rotate[i][0] == 1) {
			Rotate(wheels, 1, rotate[i][1]);
			if (connect1) {
				Rotate(wheels, 2, -rotate[i][1]);
				if (connect2) {
					Rotate(wheels, 3, rotate[i][1]);
					if (connect3) {
						Rotate(wheels, 4, -rotate[i][1]);
					}
				}
			}
		}
		//2번 바퀴를 회전하는 경우
		else if (rotate[i][0] == 2) {
			if (connect1)	Rotate(wheels, 1, -rotate[i][1]);
			Rotate(wheels, 2, rotate[i][1]);
			if (connect2) {
				Rotate(wheels, 3, -rotate[i][1]);
				if (connect3) {
					Rotate(wheels, 4, rotate[i][1]);
				}
			}
		}
		//3번 바퀴를 회전하는 경우
		else if (rotate[i][0] == 3) {
			if (connect3) Rotate(wheels, 4, -rotate[i][1]);
			Rotate(wheels, 3, rotate[i][1]);
			if (connect2) {
				Rotate(wheels, 2, -rotate[i][1]);
				if (connect1) {
					Rotate(wheels, 1, rotate[i][1]);
				}
			}
		}
		//4번 바퀴를 회전하는 경우
		else {
			Rotate(wheels, 4, rotate[i][1]);
			if (connect3) {
				Rotate(wheels, 3, -rotate[i][1]);
				if (connect2) {
					Rotate(wheels, 2, rotate[i][1]);
					if (connect1) {
						Rotate(wheels, 1, -rotate[i][1]);
					}
				}
			}
		}
	}

	if (wheels[1][0] == '1')	answer++;
	if (wheels[2][0] == '1')	answer += 2;
	if (wheels[3][0] == '1')	answer += 4;
	if (wheels[4][0] == '1')	answer += 8;
	cout << answer;
	return 0;
}

void Rotate(char wheels[5][8], int wheel_num, int direction) {
	char temp;
	//시계방향 회전
	if (direction == 1) {
		temp = wheels[wheel_num][7];
		for (int i = 7; i > 0; i--) {
			wheels[wheel_num][i] = wheels[wheel_num][i - 1];
		}
		wheels[wheel_num][0] = temp;
	}
	//반시계방향 회전
	else {
		temp = wheels[wheel_num][0];
		for (int i = 0; i < 7; i++) {
			wheels[wheel_num][i] = wheels[wheel_num][i + 1];
		}
		wheels[wheel_num][7] = temp;
	}
}