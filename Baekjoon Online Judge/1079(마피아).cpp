/*
���� ��ũ : https://www.acmicpc.net/problem/1079
���� Ž������ �ذ��� �� �ִ� ������.

������ ���ñ��� ���� ����� �������ִ�.

���� �㿡 � �����ڸ� �������� ���� Ž������ ���ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int N, alive, score[16], R[16][16], me, answer = 0;
bool live[16];

void start_game(int night_count);

int main(void) {
	//�Է°� ���� �� ���� �ʱ�ȭ
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
	//���� Ž�� ����
	start_game(0);
	cout << answer << endl;

	return 0;
}

void start_game(int night_count) {
	int max_score = 0, day_victim;
	//���� ���Ǿư� �׾��ų�, ���Ǿư� �¸��� ��� ������� night_count�� answer�� �� ����
	if (alive == 1 || !live[me]) {
		if (night_count > answer)	answer = night_count;
		return;
	}

	if (alive % 2 == 0) {	//���� ��� ���ϼ� �ִ� ��� ��쿡 ���� game����
		for (int a = 0; a < N; a++) {
			if (live[a] && a != me) {
				//a��° ����� ���̴� ���
				live[a] = false;
				for (int b = 0; b < N; b++) {
					score[b] += R[a][b];
				}
				alive--;
				start_game(night_count + 1);
				//a��° ����� �츮�� ���� ����� ���̴� ��츦 ����
				live[a] = true;
				for (int b = 0; b < N; b++) {
					score[b] -= R[a][b];
				}
				alive++;
			}
		}
	}
	else {	//���� ��� ���� ������ ���� ���� ����� ���δ�
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