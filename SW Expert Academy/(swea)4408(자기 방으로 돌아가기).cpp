/*
문제 링크 : https://swexpertacademy.com/main/main.do
완전 탐색 문제이다.

우선 입력 데이터를 정리해 줄 필요가 있다. 1번과 2번방은 다른 방이지만, 같은 위치에 있다는 점에서 문제를 풀 때는 같은 방으로 취급하여도 상관이 없다.

따라서 먼저 400개의 방을 위 아래 구분하지 않고 1~200번의 방으로 생각을 하였다.

또한 낮은 번호의 방에서 높은 번호의 방으로 가는 것이나 그 반대의 경우나 다를 것이 없다.

따라서 방의 이동은 항상 낮은 곳에서 높은 곳으로 간다고 가정을 하였다.

마지막으로 같은 단위 시간안에 서로 복도를 공유하지 않는다면 독립적으로 이동이 가능하다. 이 점을 이용하여 완전 탐색을 하기 위해 정렬을 이용하였다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int N, moved[200];
vector<pair<int, int>> room;

int main(int argc, char** argv)
{
	int T, answer, x, y, completed, start;
	
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 변수 초기화
		cin >> N;
		room.clear();
		for (int a = 0; a < N; a++) {
			cin >> x >> y;
			if (x % 2 == 1)	x = (x / 2) + 1;
			else	x = x / 2;
			if (y % 2 == 1)	y = (y / 2) + 1;
			else	y = y / 2;

			if (x < y)	room.push_back(make_pair(x, y));
			else	room.push_back(make_pair(y, x));

			moved[a] = 0;
		}
		//방의 이동을 오름차순으로 정렬
		sort(room.begin(), room.end());

		answer = 0;
		completed = 0;
		while (completed < N) {
			answer++;
			start = 0;	//start는 가장 최근에 이동하기로 결정된 학생의 목적지 의미
			for (int a = 0; a < room.size(); a++) {	
				if (moved[a] == 0 && room[a].first > start) {	//만약 a번 이동이 이루어지지 않았고, 시작하는 방이 start보다 큰 경우 이동 가능
					moved[a] = 1;
					start = room[a].second;
					completed++;
				}
			}
		}

		cout << '#' << test_case << ' ' << answer << endl;
	}
	return 0;
}