/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���� Ž���� ���� ���� ����� ������ ������ �ľ��ϴ� ������.

���� ������ ������ DFS�� ����Ͽ� ã�Ҵ�.

����� ���� ������ �ڵ常 ���� ���� ������ �� ���� ���̴�.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void search_near(int cheese[100][100], bool visited[100][100], int N, int x, int y, int day);

int main(int argc, char** argv)
{
	int T, N, cheese[100][100], answer, group_num;
	bool visited[100][100];

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ����
		scanf("%d", &N);
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				scanf("%d", &cheese[a][b]);
			}
		}

		answer = 0;
		//0�Ϻ��� 100�� ���� �� ��� ������ ���� ���� ���� ����
		for (int a = 0; a <= 100; a++) {
			group_num = 0;	//����� ����
			memset(visited, false, sizeof(bool) * 100 * 100);
			//��� ��ǥ�� �ش� ������ ���� ��¥���� ũ�� �湮���� ���� �����̸� ���ο� ���
			for (int b = 0; b < N; b++) {
				for (int c = 0; c < N; c++) {
					if (cheese[b][c] > a && visited[b][c] == false) {
						visited[b][c] = true;
						search_near(cheese, visited, N, b, c, a);
						group_num++;
					}
				}
			}
			//���� ��¥�� ��� ������ �� ���� ��� answer ����
			if (group_num > answer)	answer = group_num;
		}

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}
//x, y�� ���� ����� ���ϴ� ������ ��� �湮�Ͽ��ٰ� ǥ��
void search_near(int cheese[100][100], bool visited[100][100], int N, int x, int y, int day) {
	int nx, ny;

	for (int a = 0; a < 4; a++) {
		nx = x + dx[a];
		ny = y + dy[a];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && cheese[nx][ny] > day && visited[nx][ny] == false) {
			visited[nx][ny] = true;
			search_near(cheese, visited, N, nx, ny, day);
		}
	}
}