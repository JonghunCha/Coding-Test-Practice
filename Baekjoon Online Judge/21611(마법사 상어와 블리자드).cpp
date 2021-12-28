/*
문제 링크 : https://www.acmicpc.net/problem/21611
구현/시뮬레이션 문제다.

문제의 설명을 보면 구슬이 파괴 될 때마다 격자판을 갱신하는데 실제로는 그럴 필요가 없다.

구슬을 칸의 번호에 따른 순서로 list에 보관한다고 했을 때, 파괴되는 구슬들은 list에서 제거만 해주면 된다.

파괴될 때 마다 board에서 지우고 격자판을 이동시키는 것은 시간 낭비다.

격자판을 갱신하는 것은 마지막 구슬 변화를 일으키고 난 뒤 한 번만 옮기면 된다.
*/
#include <iostream>
#include <list>
using namespace std;

int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };
int bead_1 = 0, bead_2 = 0, bead_3 = 0;

void Make_List(int N, int board[50][50], list<int>& __list);
void Remove_Beads(int N, list<int>& __list);
void Make_Beads_Group(int N, int board[50][50], list<int>& __list, list<int>& bead_order);

int main(void) {
	int N, M, board[50][50], magic[100][2];
	int shark_x, shark_y;
	list<int> __list;
	list<int> bead_order;
	//입력값 저장
	cin >> N; cin >> M;
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			cin >> board[a][b];
		}
	}
	for (int a = 0; a < M; a++) {
		cin >> magic[a][0];
		cin >> magic[a][1];
	}

	shark_x = (N + 1) / 2;
	shark_y = (N + 1) / 2;
	for (int a = 0; a < M; a++) {
		//블리자드 마법 시전
		for (int b = 1; b <= magic[a][1]; b++) {
			board[shark_x + b * dx[magic[a][0]]][shark_y + b * dy[magic[a][0]]] = -1;
		}
		Make_List(N, board, __list);	//남은 구슬로 리스트 구성
		Remove_Beads(N, __list);	//리스트에서 4개 이상 연속된 원소 삭제
		Make_Beads_Group(N, board, __list, bead_order);	//구슬 변형을 실시하고 결과를 board에 옮김
		//다음 블리자드를 위해 __list 와 bead_order 비우기
		while (__list.size() > 0)	__list.erase(__list.begin());
		while (bead_order.size() > 0)	bead_order.erase(bead_order.begin());
	}
	cout << bead_1 + 2 * bead_2 + 3 * bead_3;

	return 0;
}

void Make_List(int N, int board[50][50], list<int>& __list) {
	int x = (N + 1) / 2, y = (N + 1) / 2;
	int step = 1, direction = 3;
	bool search_end = false;
	while (!search_end) {
		//칸의 번호를 따라가며 구슬의 번호를 __list에 추가
		for (int a = 1; a <= step; a++) {
			x = x + dx[direction];
			y = y + dy[direction];
			if (x >= 1 && x <= N && y >= 1 && y <= N) {
				//빈 공간이면 탐색 중지
				if (board[x][y] == 0) {
					search_end = true;
					break;
				}
				//구슬인 경우 __list에 추가
				else if (board[x][y] > 0)	__list.emplace_back(board[x][y]);
			}
			else {
				search_end = true;
				break;
			}
		}
		if (direction == 1) {
			direction = 3;
			step++;
		}
		else if (direction == 2) {
			direction = 4;
			step++;
		}
		else if (direction == 3)	direction = 2;
		else	direction = 1;
	}
}

void Remove_Beads(int N, list<int>& __list) {
	int cur_bead, cur_bead_num;
	bool is_bead_removed = true;
	while (is_bead_removed) {
		cur_bead = 0;
		cur_bead_num = 0;
		is_bead_removed = false;
		for (list<int>::iterator itr = __list.begin(); itr != __list.end();) {
			//현재 구슬의 번호가 이전 구슬의 번호와 다르다면 cur_bead와 cur_bead_num갱신
			if (*itr != cur_bead) {
				cur_bead = *itr;
				cur_bead_num = 1;
				itr++;
			}
			//현재 구슬의 번호가 이전의 구슬과 같을 경우
			else {
				//만약 이전까지 같은 번호의 구슬이 3개나온 경우 현재 구슬은 연속되는 구슬 중 4번째가 되는 것
				if (cur_bead_num == 3) {
					itr = __list.erase(itr);	//현재 구슬 제거
					for (int a = 0; a < 3; a++) {	//이전의 구슬 3개 제거
						itr--;
						itr = __list.erase(itr);
					}
					cur_bead_num++;
					is_bead_removed = true;
					if (cur_bead == 1)	bead_1 += 4;
					else if (cur_bead == 2)	bead_2 += 4;
					else	bead_3 += 4;
				}
				//연속으로 같은 구슬이 4개보다 더 많은 경우 앞선 4개는 지워진 상태이기에 현재 구슬만 제거
				else if (cur_bead_num >= 4) {
					itr = __list.erase(itr);
					if (cur_bead == 1)	bead_1++;
					else if (cur_bead == 2)	bead_2++;
					else	bead_3++;
				}
				//아직 연속 4개가 아닌 경우
				else {
					cur_bead_num++;
					itr++;
				}
			}
		}
	}
}

void Make_Beads_Group(int N, int board[50][50], list<int>& __list, list<int>& bead_order) {
	int cur_bead = 0, cur_bead_num = 0;
	int x = (N + 1) / 2, y = (N + 1) / 2;
	int step, direction;
	bool search_end;
	//구슬이 변화한 값을 bead_order 리스트에 넣는다
	__list.emplace_back(0);
	for (list<int>::iterator itr = __list.begin(); itr != __list.end(); itr++) {
		if (itr == __list.begin()) {
			cur_bead = (*itr);
			cur_bead_num = 1;
			continue;
		}
		if (*itr != cur_bead) {
			bead_order.emplace_back(cur_bead_num);
			bead_order.emplace_back(cur_bead);
			cur_bead = *itr;
			cur_bead_num = 1;
		}
		else {
			cur_bead_num++;
		}
	}
	//bead_order벡터의 값을 board에 차례대로 복사
	for (int b = 1; b <= N; b++) {
		for (int c = 1; c <= N; c++) {
			board[b][c] = 0;
		}
	}
	step = 1;
	direction = 3;
	search_end = false;
	while (!search_end) {
		for (int b = 1; b <= step; b++) {
			x = x + dx[direction];
			y = y + dy[direction];
			if (x >= 1 && x <= N && y >= 1 && y <= N) {
				if (bead_order.size() > 0) {
					cur_bead = *bead_order.begin();
					board[x][y] = cur_bead;
					bead_order.erase(bead_order.begin());
				}
				else {
					search_end = true;
					break;
				}
			}
			else {
				search_end = true;
				break;
			}
		}
		if (direction == 1) {
			direction = 3;
			step++;
		}
		else if (direction == 2) {
			direction = 4;
			step++;
		}
		else if (direction == 3)	direction = 2;
		else	direction = 1;
	}
}