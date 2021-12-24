/*
���� ��ũ : https://www.acmicpc.net/problem/19237
�ܼ� ���� ������.

�־��� ���ǿ� ���� ������ �ϸ� �ȴ�.(���� ���̵��� ����� �ʴ�)
*/
#include <iostream>
using namespace std;

int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };

int main(void) {
	int N, M, k, map[20][20][2], map_copy[20][20][2], shark[401][3], shark_info[401][5][5], count = 0, shark_num;
	int nx, ny, temp;
	bool find_empty;
	//�Է°� ���� + map_copy�� �� �̵��������� ���� ��ƸԴ� ���� �����ϱ� ���� ��
	cin >> N; cin >> M; cin >> k;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			cin >> map[a][b][0];
			map_copy[a][b][0] = map[a][b][0];
			if (map[a][b][0] != 0) {
				shark[map[a][b][0]][0] = a;
				shark[map[a][b][0]][1] = b;
				map[a][b][1] = k;
				map_copy[a][b][1] = k;
			}
			else {
				map[a][b][1] = 0;
				map_copy[a][b][1] = 0;
			}
		}
	}
	for (int a = 1; a <= M; a++)	cin >> shark[a][2];
	for (int a = 1; a <= M; a++) {
		for (int b = 1; b <= 4; b++) {
			for (int c = 1; c <= 4; c++) {
				cin >> shark_info[a][b][c];
			}
		}
	}
	//�ִ� 1000�� �ݺ��ϸ�, ���� ��� ���� 1�� �Ǹ� ����
	shark_num = M;
	while (count <= 1000) {
		if (shark_num == 1)	break;
		for (int a = 1; a <= M; a++) {
			find_empty = false;	//�� �� ������ ã�Ҵ��� ��Ÿ��(��ã�� ��� �ڽ��� ������ �Ѹ� �� Ž��)
			if (shark[a][0] != -1) {	//���� �� �ƴ϶��
				//������ ������ �켱������ ���� �� �������� Ž��
				for (int b = 1; b <= 4; b++) {
					nx = shark[a][0] + dx[shark_info[a][shark[a][2]][b]];
					ny = shark[a][1] + dy[shark_info[a][shark[a][2]][b]];
					if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny][0] == 0) {
						temp = map_copy[nx][ny][0];
						//�̵��������� �̹� �� �ڸ��� �ٸ� �� ���� �ִ� ��� ũ�� ���Ͽ� 1������ �츰��
						if (temp != 0 && a < temp) {
							shark[temp][0] = -1;
							shark_num--;
							map_copy[nx][ny][0] = a;
							shark[a][0] = nx;
							shark[a][1] = ny;
							shark[a][2] = shark_info[a][shark[a][2]][b];
							find_empty = true;
							break;
						}
						else if (temp != 0 && a > temp) {
							shark[a][0] = -1;
							shark_num--;
							find_empty = true;
							break;
						}
						else {
							map_copy[nx][ny][0] = a;
							shark[a][0] = nx;
							shark[a][1] = ny;
							shark[a][2] = shark_info[a][shark[a][2]][b];
							find_empty = true;
							break;
						}
					}
				}
				//������ ���� �� ������ ���� ��� �ڽ��� ������ ã�Ƽ� �̵�
				if (!find_empty) {
					for (int b = 1; b <= 4; b++) {
						nx = shark[a][0] + dx[shark_info[a][shark[a][2]][b]];
						ny = shark[a][1] + dy[shark_info[a][shark[a][2]][b]];
						if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny][0] == a) {
							shark[a][0] = nx;
							shark[a][1] = ny;
							shark[a][2] = shark_info[a][shark[a][2]][b];
							break;
						}
					}
				}
			}
		}
		//k���� ������Ʈ
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (map_copy[a][b][1] == 1) {
					map_copy[a][b][0] = 0;
					map_copy[a][b][1] = 0;
				}
				else if (map_copy[a][b][1] > 1) {
					map_copy[a][b][1]--;
				}
			}
		}
		//�̵��� ��� ��ġ�� ���� ���� ������Ʈ
		for (int a = 1; a <= M; a++) {
			if (shark[a][0] != -1) {
				map_copy[shark[a][0]][shark[a][1]][0] = a;
				map_copy[shark[a][0]][shark[a][1]][1] = k;
			}
		}
		//map���ٰ� map_copy�� ����
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				map[a][b][0] = map_copy[a][b][0];
				map[a][b][1] = map_copy[a][b][1];
			}
		}
		count++;
	}
	if (count > 1000)	cout << -1;
	else	cout << count;

	return 0;
}