/*
���� ��ũ : https://www.acmicpc.net/problem/17472
�����̿� ���� �� �ִ� �ٸ����� ��� ������ ���� Ž���� ���� ���Ѵ�. �׷� ���� ������� �ٸ� ������ ��� ���� ���� ������ �� �ִ��� Ȯ���Ѵ�(DFS�� �̿��� �׷��� Ž��).

��� ������ ���� ���� ���� �ϴٸ� �ٸ� ���� ���� �ּҰ��� ����ؼ� ������Ʈ �ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int answer = 100;

void Check_Near(int N, int M, int map[10][10], int temp, int row, int col);
void Get_All_Bridge(int N, int M, int map[10][10], int bridge_length[7][7]);
void Make_Combination(int bridge_length[7][7], int connect[7][7], int islands_num, int bridge_num, int step);
bool Is_Connected(int connect[7][7], int islands_num, int island1, int island2);

int main(void) {
	int N, M, map[10][10], islands_num = 0, temp, bridge_length[7][7], connect[7][7], bridge_num = 0;
	//�Է°� ����
	cin >> N; cin >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	//temp�� ���� ��ȣ�� �ο��ϱ� ���� ���(ó���� 2�� ����ϴ� ������ �⺻������ ��� ������ 1�� �Է� �ޱ⿡ �����ϱ� ����)
	temp = 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				map[i][j] = temp;
				//���� ������ �߰��Ѵٸ� ��, ��, ��, �Ͽ� ���� ���� ������ �ִ��� Ȯ��
				Check_Near(N, M, map, temp, i, j);
				temp++;
			}
		}
	}
	//���� ������ �ľ��Ѵ� + �������� ���̱� ���� ���� ��ȣ�� 1���� �ű�
	temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > 0)	map[i][j]--;
			if (map[i][j] > islands_num)	islands_num = map[i][j];
		}
	}
	//�� �������� �ٸ� ���̸� �����ϴ� �迭 �ʱ�ȭ(100�̸� �ٸ��� ���� �� ���� ��)
	for (int i = 1; i <= islands_num; i++) {
		for (int j = 1; j <= islands_num; j++) {
			bridge_length[i][j] = 100;
		}
	}
	//�� ���� �ٸ����̸� ���ϴ� �Լ� ȣ��
	Get_All_Bridge(N, M, map, bridge_length);
	//connect�� �ٸ��� ���� �� ���� ��쿣 -1, ���� �� �ִ� ��쿣 0���� �ʱ�ȭ
	for (int i = 1; i <= islands_num; i++) {
		for (int j = 1; j <= islands_num; j++) {
			if (bridge_length[i][j] == 100)	connect[i][j] = -1;
			else {
				connect[i][j] = 0;
				bridge_num++;
			}
		}
	}
	bridge_num /= 2;
	//�ٸ��� ��� ������ ���ϰ� ������� ���
	Make_Combination(bridge_length, connect, islands_num, bridge_num, 1);
	if (answer == 100) cout << -1;
	else	cout << answer;

	return 0;
}
//�Է°����� ���� ������ �߰� ������ ������ ������ ���� ���� ������ �ִ��� Ž��
void Check_Near(int N, int M, int map[10][10], int temp, int row, int col) {
	if (row > 0 && map[row - 1][col] == 1){
		map[row - 1][col] = temp;
		Check_Near(N, M, map, temp, row - 1, col);
	}
	if (col < M - 1 && map[row][col + 1] == 1) {
		map[row][col + 1] = temp;
		Check_Near(N, M, map, temp, row, col + 1);
	}
	if (col > 0 && map[row][col - 1] == 1) {
		map[row][col - 1] = temp;
		Check_Near(N, M, map, temp, row, col - 1);
	}
	if (row < N - 1 && map[row + 1][col] == 1) {
		map[row + 1][col] = temp;
		Check_Near(N, M, map, temp, row + 1, col);
	}
}
//�μ� ���̿� ���� �� �ִ� ���� ª�� �ٸ��� ����
void Get_All_Bridge(int N, int M, int map[10][10], int bridge_length[7][7]) {
	int island1 = 0, island2 = 0, length, flag;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//���� ������ �߰�
			if (map[i][j] > 0) {
				island1 = map[i][j];
				//���� Ž��
				length = 0;
				flag = 0;
				for (int k = i - 1; k >= 0; k--) {
					//���� ���� �����̸� Ž�� ��
					if (map[k][j] == map[i][j])	break;
					//�ٴ� �����̸� �ٸ� ����++
					else if (map[k][j] == 0)	length++;
					//�ٸ� �� �߰��� ���
					else {
						island2 = map[k][j];
						flag = 1;
						break;
					}
				}
				if (length >= 2 && bridge_length[island1][island2] > length && flag == 1)	bridge_length[island1][island2] = length;
				//������ Ž��
				length = 0;
				flag = 0;
				for (int k = j + 1; k < M; k++) {
					if (map[i][k] == map[i][j])	break;
					else if (map[i][k] == 0)	length++;
					else {
						island2 = map[i][k];
						flag = 1;
						break;
					}
				}
				if (length >= 2 && bridge_length[island1][island2] > length && flag == 1)	bridge_length[island1][island2] = length;
				//�Ʒ��� Ž��
				length = 0;
				flag = 0;
				for (int k = i + 1; k < N; k++) {
					if (map[k][j] == map[i][j])	break;
					else if (map[k][j] == 0)	length++;
					else {
						island2 = map[k][j];
						flag = 1;
						break;
					}
				}
				if (length >= 2 && bridge_length[island1][island2] > length && flag == 1)	bridge_length[island1][island2] = length;
				//���� Ž��
				length = 0;
				flag = 0;
				for (int k = j - 1; k >= 0; k--) {
					if (map[i][k] == map[i][j])	break;
					else if (map[i][k] == 0)	length++;
					else {
						island2 = map[i][k];
						flag = 1;
						break;
					}
				}
				if (length >= 2 && bridge_length[island1][island2] > length && flag == 1)	bridge_length[island1][island2] = length;
			}
		}
	}
}
//��� �ٸ��� ������ ����� ��� ���� ���
void Make_Combination(int bridge_length[7][7], int connect[7][7], int islands_num, int bridge_num, int step) {
	//��� �ٸ��� ���� ������ ���� ���� ������ ���� �� ��
	if (step == bridge_num + 1) {
		//��� ������ ���� ����Ǿ����� Ȯ��
		for (int i = 1; i <= islands_num; i++) {
			for (int j = i + 1; j <= islands_num; j++) {
				if (!Is_Connected(connect, islands_num, i, j))	return;
			}
		}
		//������ �ٸ��� ���̸� ���ϰ� answer����
		int length = 0;
		for (int i = 1; i <= islands_num; i++) {
			for (int j = i + 1; j <= islands_num; j++) {
				if (connect[i][j] == 1)	length += bridge_length[i][j];
			}
		}
		if (length < answer)	answer = length;
	}
	for (int i = 1; i <= islands_num; i++) {
		for (int j = i + 1; j <= islands_num; j++) {
			//�ٸ��� ���� �� �ִ� ��� �߰�
			if (connect[i][j] == 0) {
				//���� �ʱ�� ���� �� ��
				connect[i][j] = -1;
				connect[j][i] = -1;
				Make_Combination(bridge_length, connect, islands_num, bridge_num, step + 1);
				//����� ���� �� ��
				connect[i][j] = 1;
				connect[j][i] = 1;
				Make_Combination(bridge_length, connect, islands_num, bridge_num, step + 1);
				connect[i][j] = 0;
				connect[j][i] = 0;
				return;
			}
		}
	}
}
//�� ���� ���� ����Ǿ� �ִ��� Ȯ���ϴ� �Լ�
bool Is_Connected(int connect[7][7], int islands_num, int island1, int island2) {
	int stack[7], stack_size = 0, memory[7], now;

	for (int i = 1; i <= islands_num; i++)	memory[i] = 0;
	stack[1] = island1;
	stack_size = 1;
	while (stack_size > 0) {
		now = stack[stack_size--];
		if (connect[now][island2] == 1)	return true;
		for (int i = 1; i <= islands_num; i++) {
			if (connect[now][i] == 1 && memory[i] == 0) {
				memory[i] = 1;
				stack[++stack_size] = i;
			}
		}
	}
	return false;
}