/*
���� ��ũ : https://www.acmicpc.net/problem/20056
�ܼ� ���� �ùķ��̼� ������.

������ ���ǿ� 2���� �ܰ谡 �ִ�.

1. ��� ���̾�� ������ �������� �̵��ϴ� ��
2. ��� ���̾�� �̵��� �� 2�� �̻��� ���̾�� �ִ� ĭ���� ���̾�� 4���� ������ ��

��� ���̾�� �̵��� �� 2�� �̻��� ���̾�� �ִ� ���� ó���ؾ� �ϱ⿡ N * N ���� ���� ���̾�� ���¸� ��Ÿ���� ������ 2�� ����Ͽ���.
*/
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main(void) {
	int N, M, K, R, C, mm, ss, dd, mass_sum, speed_sum, fireball_num, answer = 0;
	bool direction_odd, direction_even;
	vector<tuple<int, int, int>> msd[51][51];		//ù ��° �ܰ踦 ������ �� ����ϴ� ����
	vector<tuple<int, int, int>> msd_copy[51][51];	//ù ��° �ܰ踦 ������ �����, �� ��° �ܰ踦 �����ϴµ� ����ϴ� ����
	//�Է°� ����
	cin >> N; cin >> M; cin >> K;
	for (int a = 0; a < M; a++) {
		cin >> R;
		cin >> C;
		cin >> mm;
		cin >> ss;
		cin >> dd;
		msd[R][C].emplace_back(make_tuple(mm, ss, dd));
	}

	for (int a = 0; a < K; a++) {
		//��� ���̾ �̵�
		for (int b = 1; b <= N; b++) {
			for (int c = 1; c <= N; c++) {
				//���̾� ���� �ִ� ���̶�� �̵� ����
				while (msd[b][c].size() > 0) {
					mm = get<0>(msd[b][c][msd[b][c].size() - 1]);
					ss = get<1>(msd[b][c][msd[b][c].size() - 1]);
					dd = get<2>(msd[b][c][msd[b][c].size() - 1]);
					msd[b][c].erase(msd[b][c].begin() + msd[b][c].size() - 1);
					//�̵��� �� ���̾�� ��ǥ ���
					R = b;
					C = c;
					for (int d = 1; d <= ss; d++) {
						R += dx[dd];
						C += dy[dd];
						if (R < 1)	R = N;
						else if (R > N)	R = 1;
						if (C < 1)	C = N;
						else if (C > N)	C = 1;
					}
					//msd_copy������ �̵��� ��� ����
					msd_copy[R][C].emplace_back(make_tuple(mm, ss, dd));
				}
			}
		}
		//�̵��� ���� �� 2�� �̻��� ���̾�� �ִ� ĭ ó��
		for (int b = 1; b <= N; b++) {
			for (int c = 1; c <= N; c++) {
				//2�� �̻��� ���̾�� �ִ� ��� 2�� ������ ����
				if (msd_copy[b][c].size() >= 2) {
					direction_odd = false;		//Ȧ�� ���� ���̾�� �ִ� ��� true�� ����
					direction_even = false;		//¦�� ���� ���̾�� �ִ� ��� true�� ����
					mass_sum = 0;
					speed_sum = 0;
					fireball_num = 0;
					while (msd_copy[b][c].size() > 0) {
						mm = get<0>(msd_copy[b][c][msd_copy[b][c].size() - 1]);
						ss = get<1>(msd_copy[b][c][msd_copy[b][c].size() - 1]);
						dd = get<2>(msd_copy[b][c][msd_copy[b][c].size() - 1]);
						msd_copy[b][c].erase(msd_copy[b][c].begin() + msd_copy[b][c].size() - 1);

						mass_sum += mm;	
						speed_sum += ss;
						fireball_num++;
						if (dd % 2 == 0)	direction_even = true;
						else	direction_odd = true;
					}
					
					if (fireball_num != 0) {
						for (int d = 1; d <= 4; d++) {
							//Ȧ�� ¦�� ��� �ִ� ��� ������ 1, 3, 5, 7
							if (direction_odd == direction_even)	dd = 2 * d - 1;
							//Ȧ�� Ȥ�� ¦���� �ִ� ��� ������ 0, 2, 4, 6
							else	dd = 2 * d - 2;
							mm = mass_sum / 5;
							if (mm == 0)	break;
							ss = speed_sum / fireball_num;
							//���̾�� 4���� ���� ����� msd�� ����
							msd[b][c].emplace_back(make_tuple(mm, ss, dd));
						}
					}
				}
				//���̾�� �� ���� ��쿣 ���� �ʿ� ���� msd�� ����
				else if (msd_copy[b][c].size() == 1) {
					mm = get<0>(msd_copy[b][c][msd_copy[b][c].size() - 1]);
					ss = get<1>(msd_copy[b][c][msd_copy[b][c].size() - 1]);
					dd = get<2>(msd_copy[b][c][msd_copy[b][c].size() - 1]);
					msd_copy[b][c].erase(msd_copy[b][c].begin() + msd_copy[b][c].size() - 1);
					msd[b][c].emplace_back(make_tuple(mm, ss, dd));
				}
			}
		}
	}
	//��ü ���� ���ϱ�
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			while (msd[a][b].size() > 0) {
				mm = get<0>(msd[a][b][msd[a][b].size() - 1]);
				msd[a][b].erase(msd[a][b].begin() + msd[a][b].size() - 1);
				answer += mm;
			}
		}
	}
	cout << answer;

	return 0;
}