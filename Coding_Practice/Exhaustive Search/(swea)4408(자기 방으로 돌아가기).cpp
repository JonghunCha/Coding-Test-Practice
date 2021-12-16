/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���� Ž�� �����̴�.

�켱 �Է� �����͸� ������ �� �ʿ䰡 �ִ�. 1���� 2������ �ٸ� ��������, ���� ��ġ�� �ִٴ� ������ ������ Ǯ ���� ���� ������ ����Ͽ��� ����� ����.

���� ���� 400���� ���� �� �Ʒ� �������� �ʰ� 1~200���� ������ ������ �Ͽ���.

���� ���� ��ȣ�� �濡�� ���� ��ȣ�� ������ ���� ���̳� �� �ݴ��� ��쳪 �ٸ� ���� ����.

���� ���� �̵��� �׻� ���� ������ ���� ������ ���ٰ� ������ �Ͽ���.

���������� ���� ���� �ð��ȿ� ���� ������ �������� �ʴ´ٸ� ���������� �̵��� �����ϴ�. �� ���� �̿��Ͽ� ���� Ž���� �ϱ� ���� ������ �̿��Ͽ���.
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
		//�Է°� ���� �� ���� �ʱ�ȭ
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
		//���� �̵��� ������������ ����
		sort(room.begin(), room.end());

		answer = 0;
		completed = 0;
		while (completed < N) {
			answer++;
			start = 0;	//start�� ���� �ֱٿ� �̵��ϱ�� ������ �л��� ������ �ǹ�
			for (int a = 0; a < room.size(); a++) {	
				if (moved[a] == 0 && room[a].first > start) {	//���� a�� �̵��� �̷������ �ʾҰ�, �����ϴ� ���� start���� ū ��� �̵� ����
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