/*
���� ��ũ : https://www.acmicpc.net/problem/21610
�ܼ� ���� ������.

�������� ������ ��Ģ�� ���� ������ �ϸ� �Ǹ� ũ�� ��ٷο� �κе� ����.
*/
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int main(void) {
	int N, M, water[51][51], cloud[51][51], move_info[100][2], answer = 0;
	vector<tuple<int, int>> removing_cloud;
	removing_cloud.reserve(2500);
	int nx, ny;
	//�Է°� ����
	cin >> N; cin >> M;
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			cin >> water[a][b];
			cloud[a][b] = 0;
		}
	}
	for (int a = 0; a < M; a++) {
		cin >> move_info[a][0];
		cin >> move_info[a][1];
	}
	//�ʱ� ���� ���� �� M���� �̵� �ǽ�
	cloud[N][1] = 1;
	cloud[N][2] = 1;
	cloud[N - 1][1] = 1;
	cloud[N - 1][2] = 1;
	for (int a = 0; a < M; a++) {
		//1�ܰ�(���� �̵�) + 2�ܰ�(�̵��� �ٱ��Ͽ� �� ����)
		for (int b = 1; b <= N; b++) {
			for (int c = 1; c <= N; c++) {
				if (cloud[b][c] == 1) {
					nx = b;
					ny = c;
					for (int d = 1; d <= move_info[a][1]; d++) {
						nx += dx[move_info[a][0]];
						ny += dy[move_info[a][0]];
						if (nx < 1)	nx += N;
						else if (nx > N)	nx -= N;
						if (ny < 1) ny += N;
						else if (ny > N)	ny -= N;
					}
					water[nx][ny] += 1;	
					//5�ܰ迡�� ������ ������ �� ���� �������� ������ �������� ���Ѵٴ� ���� ǥ���ϱ� ���� removing_cloud�� �� ���� ������ ��ǥ �߰�
					removing_cloud.emplace_back(make_tuple(nx, ny));	
				}
			}
		}
		//3�ܰ�(��� ���� �����)
		for (int b = 1; b <= N; b++) {
			for (int c = 1; c <= N; c++) {
				cloud[b][c] = 0;
			}
		}
		//4�ܰ�(2�ܰ迡�� ���� ������ ĭ�� ��������� ���� ����
		for (vector<tuple<int, int>>::iterator itr = removing_cloud.begin(); itr < removing_cloud.end(); itr++) {
			for (int b = 1; b <= 8; b++) {
				if (b % 2 == 0) {
					nx = get<0>(*itr) + dx[b];
					ny = get<1>(*itr) + dy[b];
					if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && water[nx][ny] > 0)	water[get<0>(*itr)][get<1>(*itr)]++;
				}
			}
		}
		//5�ܰ�(3�ܰ迡�� ����� ������ �ƴϰ� ���� ���� 2�̻��� ���� ���� �����ϰ� ���� �� 2����)
		for (int b = removing_cloud.size() - 1; b >= 0; b--) {
			cloud[get<0>(removing_cloud[b])][get<1>(removing_cloud[b])] = -1;
			removing_cloud.erase(removing_cloud.begin() + b);
		}
		for (int b = 1; b <= N; b++) {
			for (int c = 1; c <= N; c++) {
				if (cloud[b][c] == 0 && water[b][c] >= 2) {
					cloud[b][c] = 1;
					water[b][c] -= 2;
				}
			}
		}
	}

	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			answer += water[a][b];
		}
	}
	cout << answer;

	return 0;
}