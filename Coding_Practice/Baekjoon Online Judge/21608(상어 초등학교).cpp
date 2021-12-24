/*
문제 링크 : https://www.acmicpc.net/problem/21608
단순 구현 문제다.

주어진 조건대로 학생을 배치하고 만족도를 계산하면 된다.
*/
#include <iostream>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	int N, room[22][22], student[401][5], x, y, answer = 0, index;
	int candidate_x, candidate_y, candidate_friend, candidate_empty, friend_num, empty_num;
	//입력값 저장
	cin >> N;
	for (int a = 1; a <= N * N; a++) {
		cin >> student[a][0];
		cin >> student[a][1];
		cin >> student[a][2];
		cin >> student[a][3];
		cin >> student[a][4];
	}
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			room[a][b] = 0;
		}
	}
	//모든 학생들의 자리 배치
	for (int a = 1; a <= N * N; a++) {
		candidate_x = 21;
		candidate_y = 21;
		candidate_friend = 0;
		candidate_empty = 0;
		for (int b = 1; b <= N; b++) {
			for (int c = 1; c <= N; c++) {
				//빈 공간일 때 해당 공간이 현재 후보 자리보다 더 나은 조건인지 확인
				if (room[b][c] == 0) {
					friend_num = 0;
					empty_num = 0;
					for (int d = 0; d < 4; d++) {
						x = b + dx[d];
						y = c + dy[d];
						if (x > 0 && x <= N && y > 0 && y <= N) {
							if (room[x][y] == 0)	empty_num++;
							else if (room[x][y] == student[a][1] || room[x][y] == student[a][2] || room[x][y] == student[a][3] || room[x][y] == student[a][4]) {
								friend_num++;
							}
						}
					}
					//문제의 1, 2, 3조건을 비교하여 현재 후보보다 이번 자리가 더 좋은 자리라면 후보를 바꾼다
					if ((friend_num > candidate_friend)
						||(friend_num == candidate_friend && empty_num > candidate_empty)
						||(friend_num == candidate_friend && empty_num == candidate_empty && b < candidate_x)
						||(friend_num == candidate_friend && empty_num == candidate_empty && b == candidate_x && c < candidate_y)) {
						candidate_x = b;
						candidate_y = c;
						candidate_friend = friend_num;
						candidate_empty = empty_num;
					}
				}
			}
		}
		room[candidate_x][candidate_y] = student[a][0];
	}
	//각 학생들의 만족도 계산
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			for (int c = 1; c <= N * N; c++) {
				if (student[c][0] == room[a][b]) {
					index = c;
					break;
				}
			}
			friend_num = 0;
			for (int c = 0; c < 4; c++) {
				x = a + dx[c];
				y = b + dy[c];
				if (x > 0 && x <= N && y > 0 && y <= N &&
					(room[x][y] == student[index][1] || room[x][y] == student[index][2] || room[x][y] == student[index][3] || room[x][y] == student[index][4])) {
					friend_num++;
				}
			}
			if (friend_num == 1)	answer += 1;
			else if (friend_num == 2)	answer += 10;
			else if (friend_num == 3)	answer += 100;
			else if (friend_num == 4)	answer += 1000;
		}
	}

	cout << answer;
	return 0;
}