/*
문제 링크 : https://swexpertacademy.com/main/main.do
시뮬레이션 문제이다.

시뮬레이션 문제는 예외로 테스트 케이스에 더욱 주의해야할 필요가 있다고 판단할 수 있는 문제였다.

문제에 대한 아이디어는 크게 어렵지 않다.

모든 원자 쌍에 대해 충돌할 수 있다면 해당 값을 (원자 번호1, 원자 번호2, 충돌시간)의 벡터에 넣어준다.

그런 다음 충돌시간의 오름차순으로 정렬한 뒤 모든 충돌에 대해 방출한 에너지량을 구하면 된다.

그러나 여기서 이미 충돌하여 없어진 원자들을 잘 처리해주어야한다. (이 부분에서 하나를 놓쳐 테스트 케이스 49/50에서 30분 넘게 소비하였음..)
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 0, -1, 1 }, dy[4] = { 1, -1, 0, 0 };
int atoms_info[1010][4], time_conflict[1010];
bool is_live[1010];

bool compare(tuple<int, int, int>& t1, tuple<int, int, int>& t2) {
	return get<2>(t1) < get<2>(t2);
}

int main(void) {
	int T, N, x, y, direction, K, answer, atom1, atom2, curr_time, compare_time, index;
	vector<tuple<int, int, int>> conflict;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		//입력값 저장 및 변수 초기화
		memset(atoms_info, -1, sizeof(int) * 4040);
		memset(time_conflict, -1, sizeof(int) * 1010);
		memset(is_live, true, sizeof(bool) * 1010);
		scanf("%d", &N);
		for (int a = 0; a < N; a++) {
			scanf("%d %d %d %d", &x, &y, &direction, &K);
			atoms_info[a][0] = 2 * x;
			atoms_info[a][1] = 2 * y;
			atoms_info[a][2] = direction;
			atoms_info[a][3] = K;
		}
		//충돌 가능한 모든 원자 쌍과 충돌 시간을 저장
		conflict.clear();
		for (int a = 0; a < N; a++) {
			for (int b = a + 1; b < N; b++) {
				if (atoms_info[a][2] == 0 && atoms_info[b][2] == 1 && atoms_info[a][0] == atoms_info[b][0] && atoms_info[a][1] < atoms_info[b][1]) {
					conflict.push_back(make_tuple(a, b, abs(atoms_info[a][1] - atoms_info[b][1]) / 2));
				}
				else if (atoms_info[a][2] == 1 && atoms_info[b][2] == 0 && atoms_info[a][0] == atoms_info[b][0] && atoms_info[a][1] > atoms_info[b][1]) {
					conflict.push_back(make_tuple(a, b, abs(atoms_info[a][1] - atoms_info[b][1]) / 2));
				}
				else if (atoms_info[a][2] == 2 && atoms_info[b][2] == 3 && atoms_info[a][1] == atoms_info[b][1] && atoms_info[a][0] > atoms_info[b][0]) {
					conflict.push_back(make_tuple(a, b, abs(atoms_info[a][0] - atoms_info[b][0]) / 2));
				}
				else if (atoms_info[a][2] == 3 && atoms_info[b][2] == 2 && atoms_info[a][1] == atoms_info[b][1] && atoms_info[a][0] < atoms_info[b][0]) {
					conflict.push_back(make_tuple(a, b, abs(atoms_info[a][0] - atoms_info[b][0]) / 2));
				}
				else if (abs(atoms_info[a][0] - atoms_info[b][0]) == abs(atoms_info[a][1] - atoms_info[b][1])) {
					if (atoms_info[a][0] < atoms_info[b][0] && atoms_info[a][1] < atoms_info[b][1]) {
						if ((atoms_info[a][2] == 0 && atoms_info[b][2] == 2) || (atoms_info[a][2] == 3 && atoms_info[b][2] == 1)) {
							conflict.push_back(make_tuple(a, b, abs(atoms_info[a][0] - atoms_info[b][0])));
						}
					}
					else if (atoms_info[a][0] < atoms_info[b][0] && atoms_info[a][1] > atoms_info[b][1]) {
						if ((atoms_info[a][2] == 1 && atoms_info[b][2] == 2) || (atoms_info[a][2] == 3 && atoms_info[b][2] == 0)) {
							conflict.push_back(make_tuple(a, b, abs(atoms_info[a][0] - atoms_info[b][0])));
						}
					}
					else if (atoms_info[a][0] > atoms_info[b][0] && atoms_info[a][1] < atoms_info[b][1]) {
						if ((atoms_info[a][2] == 2 && atoms_info[b][2] == 1) || (atoms_info[a][2] == 0 && atoms_info[b][2] == 3)) {
							conflict.push_back(make_tuple(a, b, abs(atoms_info[a][0] - atoms_info[b][0])));
						}
					}
					else if (atoms_info[a][0] > atoms_info[b][0] && atoms_info[a][1] > atoms_info[b][1]) {
						if ((atoms_info[a][2] == 2 && atoms_info[b][2] == 0) || (atoms_info[a][2] == 1 && atoms_info[b][2] == 3)) {
							conflict.push_back(make_tuple(a, b, abs(atoms_info[a][0] - atoms_info[b][0])));
						}
					}
				}
			}
		}
		//충돌 시간 오름차순으로 정렬
		sort(conflict.begin(), conflict.end(), compare);
		//만약 충돌 가능한 경우가 없다면 0을 출력하고 continue
		if (conflict.size() == 0) {
			printf("#%d 0\n", test_case);
			continue;
		}
		//충돌 시간에 따라 방출되는 에너지량 계산
		answer = 0;
		index = 0;
		compare_time = get<2>(conflict[0]);
		for (int a = 0; a < conflict.size(); a++) {
			atom1 = get<0>(conflict[a]);
			atom2 = get<1>(conflict[a]);
			curr_time = get<2>(conflict[a]);
			
			if (compare_time == curr_time) {	//최근 이루어진 충돌과 같은 시간에 일어난 충돌의 경우
				if (is_live[atom1] && is_live[atom2]) {	//새로운 지점에서의 충돌
					answer += atoms_info[atom1][3];
					is_live[atom1] = false;
					time_conflict[atom1] = compare_time;
					answer += atoms_info[atom2][3];
					is_live[atom2] = false;
					time_conflict[atom1] = compare_time;
				}
				else if (is_live[atom1] && !is_live[atom2]) {	//이미 하나의 원자는 충돌한 경우
					if (time_conflict[atom2] == compare_time) {	//충돌한 하나의 원자가 같은 시각에 충돌한 것이라면 3개 이상의 원자가 동시에 충돌한 것
						answer += atoms_info[atom1][3];
						is_live[atom1] = false;
					}
				}
				else if (is_live[atom2] && !is_live[atom1]) {	//이미 하나의 원자는 충돌한 경우
					if (time_conflict[atom1] == compare_time) { //충돌한 하나의 원자가 같은 시각에 충돌한 것이라면 3개 이상의 원자가 동시에 충돌한 것
						answer += atoms_info[atom2][3];
						is_live[atom2] = false;
					}
				}
			}
			else {	//새로운 시각의 첫 충돌
				if (is_live[atom1] && is_live[atom2]) {
					compare_time = curr_time;
					answer += atoms_info[atom1][3];
					is_live[atom1] = false;
					time_conflict[atom1] = compare_time;
					answer += atoms_info[atom2][3];
					is_live[atom2] = false;
					time_conflict[atom1] = compare_time;
				}
			}
		}

		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}