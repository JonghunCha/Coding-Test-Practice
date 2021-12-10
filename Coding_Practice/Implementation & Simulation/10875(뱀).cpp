/*
문제 링크 : https://www.acmicpc.net/problem/10875
구현 문제이다.

격자판의 크기가 최대 2*10^8 + 1이기 때문에 뱀이 이동한 공간을 전부 마킹하는 것은 메모리 제한에 걸린다.

따라서 각 이동의 start좌표와 end좌표를 이용하여 뱀이 이동한 길을 판단할 수 있도록 하였다.

i번째 이동이 기존에 뱀이 이동한 경로와 만나는 지점이 있거나 격자판 밖에 닿으면 종료하도록 구현하였다.
*/
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int L, N;

int main(void) {
	long long answer = 0, min;
	int direction = 0;	//direction 0 -> 오른쪽, 1 -> 아래쪽, 2 -> 왼쪽, 3 -> 위쪽
	long long rotate[1001], x1 = 0, y1 = 0, x2, y2;
	char dir[1001];
	vector<tuple<int, int, int, int>> vec;	//i번째 이동의 시작과 끝 좌표를 저장
	//입력값 저장
	cin >> L;
	cin >> N;
	for (int a = 0; a < N; a++) {
		cin >> rotate[a];
		cin >> dir[a];
	}
	//격자판 밖도 뱀이 이동한 공간으로 취급
	vec.push_back(make_tuple(-L - 1, L + 1, L + 1, L + 1));
	vec.push_back(make_tuple(L + 1, -L - 1, L + 1, L + 1));
	vec.push_back(make_tuple(-L - 1, -L - 1, L + 1, -L - 1));
	vec.push_back(make_tuple(-L - 1, -L - 1, -L - 1, L + 1));
	
	for (int a = 0; a <= N; a++) {
		if (a == N) {	//만약 N개의 회전을 하고도 죽지 않았다면 더 이상 회전없이 죽을 때까지 직진
			if (direction == 0) {
				x2 = x1 + 1000000000;
				y2 = y1;
			}
			else if (direction == 1) {
				x2 = x1;
				y2 = y1 - 1000000000;
			}
			else if (direction == 2) {
				x2 = x1 - 1000000000;
				y2 = y1;
			}
			else {
				x2 = x1;
				y2 = y1 + 1000000000;
			}
		}
		else {	//뱀이 어디까지 간 후 회전을 실시하는지 start와 end좌표 설정
			if (direction == 0) {
				x2 = x1 + rotate[a];
				y2 = y1;
			}
			else if (direction == 1) {
				x2 = x1;
				y2 = y1 - rotate[a];
			}
			else if (direction == 2) {
				x2 = x1 - rotate[a];
				y2 = y1;
			}
			else {
				x2 = x1;
				y2 = y1 + rotate[a];
			}
		}

		min = 1000000000;
		for (int b = 0; b < vec.size(); b++) {	//뱀이 지나간 경로와 start~end사이에 겹치는 부분이 있는지 판단
			if (direction == 0) {
				if (get<0>(vec[b]) == get<2>(vec[b]) && get<1>(vec[b]) <= y2 && get<3>(vec[b]) >= y2 && get<0>(vec[b]) <= x2 && get<0>(vec[b]) > x1) {
					if (get<0>(vec[b]) - x1 < min)	min = get<0>(vec[b]) - x1;
				}
				else if (get<1>(vec[b]) == y2 && get<1>(vec[b]) == get<3>(vec[b]) && get<0>(vec[b]) <= x2 && get<0>(vec[b]) > x1) {
					if (get<0>(vec[b]) - x1 < min)	min = get<0>(vec[b]) - x1;
				}
			}
			else if (direction == 1) {
				if (get<1>(vec[b]) == get<3>(vec[b]) && get<0>(vec[b]) <= x2 && get<2>(vec[b]) >= x2 && get<1>(vec[b]) >= y2 && get<1>(vec[b]) < y1) {
					if (y1 - get<1>(vec[b]) < min)	min = y1 - get<1>(vec[b]);
				}
				else if (get<0>(vec[b]) == x2 && get<0>(vec[b]) == get<2>(vec[b]) && get<3>(vec[b]) >= y2 && get<3>(vec[b]) < y1) {
					if (y1 - get<3>(vec[b]) < min)	min = y1 - get<3>(vec[b]);
				}
			}
			else if (direction == 2) {
				if (get<0>(vec[b]) == get<2>(vec[b]) && get<1>(vec[b]) <= y2 && get<3>(vec[b]) >= y2 && get<0>(vec[b]) >= x2 && get<0>(vec[b]) < x1) {
					if (x1 - get<0>(vec[b]) < min)	min = x1 - get<0>(vec[b]);
				}
				else if (get<1>(vec[b]) == y2 && get<1>(vec[b]) == get<3>(vec[b]) && get<2>(vec[b]) >= x2 && get<2>(vec[b]) < x1) {
					if (x1 - get<2>(vec[b]) < min)	min = x1 - get<2>(vec[b]);
				}
			}
			else {
				if (get<1>(vec[b]) == get<3>(vec[b]) && get<0>(vec[b]) <= x2 && get<2>(vec[b]) >= x2 && get<1>(vec[b]) <= y2 && get<1>(vec[b]) > y1) {
					if (get<1>(vec[b]) - y1 < min)	min = get<1>(vec[b]) - y1;
				}
				else if (get<0>(vec[b]) == x2 && get<0>(vec[b]) == get<2>(vec[b]) && get<1>(vec[b]) <= y2 && get<1>(vec[b]) > y1) {
					if (get<1>(vec[b]) - y1 < min)	min = get<1>(vec[b]) - y1;
				}
			}
		}

		if (min < 1000000000) {	//만약 뱀이 몸 또는 격자판 밖과 닿아서 죽은 경우 종료
			answer += min;
			break;
		}
		else {	//뱀이 살아있는 경우 회전을 실시하고 지나온 경로를 vec에 추가
			answer += rotate[a];
			if (direction == 0) {
				vec.push_back(make_tuple(x1, y1, x2, y2));
				if (dir[a] == 'L')	direction = 3;
				else	direction = 1;
			}
			else if (direction == 1) {
				vec.push_back(make_tuple(x2, y2, x1, y1));
				if (dir[a] == 'L')	direction = 0;
				else	direction = 2;
			}
			else if (direction == 2) {
				vec.push_back(make_tuple(x2, y2, x1, y1));
				if (dir[a] == 'L')	direction = 1;
				else	direction = 3;
			}
			else {
				vec.push_back(make_tuple(x1, y1, x2, y2));
				if (dir[a] == 'L')	direction = 2;
				else	direction = 0;
			}
			x1 = x2;
			y1 = y2;
		}
	}

	cout << answer << endl;
	return 0;
}