/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�ùķ��̼� �����̴�.

�ùķ��̼� ������ ���ܷ� �׽�Ʈ ���̽��� ���� �����ؾ��� �ʿ䰡 �ִٰ� �Ǵ��� �� �ִ� ��������.

������ ���� ���̵��� ũ�� ����� �ʴ�.

��� ���� �ֿ� ���� �浹�� �� �ִٸ� �ش� ���� (���� ��ȣ1, ���� ��ȣ2, �浹�ð�)�� ���Ϳ� �־��ش�.

�׷� ���� �浹�ð��� ������������ ������ �� ��� �浹�� ���� ������ ���������� ���ϸ� �ȴ�.

�׷��� ���⼭ �̹� �浹�Ͽ� ������ ���ڵ��� �� ó�����־���Ѵ�. (�� �κп��� �ϳ��� ���� �׽�Ʈ ���̽� 49/50���� 30�� �Ѱ� �Һ��Ͽ���..)
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
		//�Է°� ���� �� ���� �ʱ�ȭ
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
		//�浹 ������ ��� ���� �ְ� �浹 �ð��� ����
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
		//�浹 �ð� ������������ ����
		sort(conflict.begin(), conflict.end(), compare);
		//���� �浹 ������ ��찡 ���ٸ� 0�� ����ϰ� continue
		if (conflict.size() == 0) {
			printf("#%d 0\n", test_case);
			continue;
		}
		//�浹 �ð��� ���� ����Ǵ� �������� ���
		answer = 0;
		index = 0;
		compare_time = get<2>(conflict[0]);
		for (int a = 0; a < conflict.size(); a++) {
			atom1 = get<0>(conflict[a]);
			atom2 = get<1>(conflict[a]);
			curr_time = get<2>(conflict[a]);
			
			if (compare_time == curr_time) {	//�ֱ� �̷���� �浹�� ���� �ð��� �Ͼ �浹�� ���
				if (is_live[atom1] && is_live[atom2]) {	//���ο� ���������� �浹
					answer += atoms_info[atom1][3];
					is_live[atom1] = false;
					time_conflict[atom1] = compare_time;
					answer += atoms_info[atom2][3];
					is_live[atom2] = false;
					time_conflict[atom1] = compare_time;
				}
				else if (is_live[atom1] && !is_live[atom2]) {	//�̹� �ϳ��� ���ڴ� �浹�� ���
					if (time_conflict[atom2] == compare_time) {	//�浹�� �ϳ��� ���ڰ� ���� �ð��� �浹�� ���̶�� 3�� �̻��� ���ڰ� ���ÿ� �浹�� ��
						answer += atoms_info[atom1][3];
						is_live[atom1] = false;
					}
				}
				else if (is_live[atom2] && !is_live[atom1]) {	//�̹� �ϳ��� ���ڴ� �浹�� ���
					if (time_conflict[atom1] == compare_time) { //�浹�� �ϳ��� ���ڰ� ���� �ð��� �浹�� ���̶�� 3�� �̻��� ���ڰ� ���ÿ� �浹�� ��
						answer += atoms_info[atom2][3];
						is_live[atom2] = false;
					}
				}
			}
			else {	//���ο� �ð��� ù �浹
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