/*
문제 링크 : https://www.acmicpc.net/problem/14890
단순 구현 문제다.

2N개의 길에 대해서 문제에서 제시한 조건을 통해 연결이 가능한지 불가능한지 확인하면 된다.
*/
#include <iostream>
using namespace std;

int main(void) {
	//seq_length는 현재까지 같은 높이를 가진 연속된 지역의 길이를 의미, cur_height는 현재 탐색중인 지역의 높이를 의미
	int N, L, answer = 0, seq_length, cur_height;
	int** map;
	bool flag;
	//입력값 저장
	cin >> N; cin >> L;
	map = new int* [N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	//모든 길들에 대해 연결되는지 탐색
	for (int i = 0; i < N; i++) {
		//가로 탐색
		seq_length = 1;	//처음 연속된 길의 길이를 1로 초기화
		cur_height = map[i][0];	//현재 높이는 시작 지역의 높이
		flag = true;	//길이 연결되는지 안되는지를 의미
		for (int j = 1; j < N; j++) {
			//현재 지역의 높이가 이전 단계의 높이와 같다면 seq_length길이를 1늘림
			if (map[i][j] == cur_height)	seq_length++;
			//현재 지역의 높이가 이전 단계의 높이보다 1만큼 크다면?
			else if (map[i][j] == cur_height + 1) {
				//이전 단계의 길이가 경사로의 길이보다 크거나 같다면 경사로를 놓을 수 있음
				if (seq_length >= L) {
					//경사로를 놓고, seq_length와 cur_height를 현재 지역부터 다시 시작
					seq_length = 1;
					cur_height = map[i][j];
				}
				//경사로를 놓을 수 없는 경우 탐색 종료
				else {
					flag = false;
					break;
				}
			}
			//현재 지역의 높이가 이전 단계의 높이보다 1만큼 작다면?
			else if (map[i][j] == cur_height - 1) {
				//다음 L - 1개의 지역의 높이가 똑같은지 확인
				for (int k = 1; k < L; k++) {
					if (j + k >= N || map[i][j + k] != cur_height - 1)	flag = false;
				}
				if (!flag)	break;
				//경사로를 높고, seq_length와 cur_height를 경사로 놓은 다음 지역으로 초기화
				j = j + L - 1;
				seq_length = 0;
				cur_height = map[i][j];
			}
			//높이가 2이상 차이나는 경우 연결 불가능
			else {
				flag = false;
				break;
			}
		}
		if (flag)	answer++;
		//세로 탐색
		seq_length = 1;
		cur_height = map[0][i];
		flag = true;
		for (int j = 1; j < N; j++) {
			if (map[j][i] == cur_height)	seq_length++;
			else if (map[j][i] == cur_height + 1) {
				if (seq_length >= L) {
					seq_length = 1;
					cur_height = map[j][i];
				}
				else {
					flag = false;
					break;
				}
			}
			else if (map[j][i] == cur_height - 1) {
				for (int k = 1; k < L; k++) {
					if (j + k >= N || map[j + k][i] != cur_height - 1)	flag = false;
				}
				if (!flag)	break;
				j = j + L - 1;
				seq_length = 0;
				cur_height = map[j][i];
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag)	answer++;
	}
	cout << answer;
	//동적 할당 해제
	for (int i = 0; i < N; i++) {
		delete []map[i];
	}
	delete []map;
	return 0;
}