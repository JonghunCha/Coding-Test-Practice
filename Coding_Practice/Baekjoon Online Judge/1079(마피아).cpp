/*
문제 링크 : https://www.acmicpc.net/problem/1079
완전 탐색으로 해결할 수 있는 문제다.

낮에는 선택권이 없이 결과는 정해져있다.

따라서 밤에 어떤 참가자를 죽일지를 완전 탐색으로 정하면 된다.
*/
#include <iostream>
using namespace std;

int N, alive, score[16], R[16][16], me, answer = 0;
bool live[16];

void start_game(int night_count);

int main(void) {
	//입력값 저장 및 변수 초기화
	cin >> N;
	for (int a = 0; a < N; a++)	cin >> score[a];
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			cin >> R[a][b];
		}
	}
	cin >> me;
	for (int a = 0; a < N; a++)	live[a] = true;
	alive = N;
	//완전 탐색 시작
	start_game(0);
	cout << answer << endl;

	return 0;
}

void start_game(int night_count) {
	int max_score = 0, day_victim;
	//만약 마피아가 죽었거나, 마피아가 승리한 경우 현재까지 night_count와 answer를 비교 갱신
	if (alive == 1 || !live[me]) {
		if (night_count > answer)	answer = night_count;
		return;
	}

	if (alive % 2 == 0) {	//밤인 경우 죽일수 있는 모든 경우에 대해 game진행
		for (int a = 0; a < N; a++) {
			if (live[a] && a != me) {
				//a번째 사람을 죽이는 경우
				live[a] = false;
				for (int b = 0; b < N; b++) {
					score[b] += R[a][b];
				}
				alive--;
				start_game(night_count + 1);
				//a번째 사람을 살리고 다음 사람을 죽이는 경우를 진행
				live[a] = true;
				for (int b = 0; b < N; b++) {
					score[b] -= R[a][b];
				}
				alive++;
			}
		}
	}
	else {	//낮인 경우 유죄 지수가 가장 높은 사람을 죽인다
		for (int a = 0; a < N; a++) {	
			if (live[a] && score[a] > max_score) {
				max_score = score[a];
				day_victim = a;
			}
		}
		live[day_victim] = false;
		alive--;
		start_game(night_count);
		alive++;
		live[day_victim] = true;
	}
	return;
}