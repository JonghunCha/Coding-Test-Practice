/*
���� ��ũ : https://www.acmicpc.net/problem/14890
�ܼ� ���� ������.

2N���� �濡 ���ؼ� �������� ������ ������ ���� ������ �������� �Ұ������� Ȯ���ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int main(void) {
	//seq_length�� ������� ���� ���̸� ���� ���ӵ� ������ ���̸� �ǹ�, cur_height�� ���� Ž������ ������ ���̸� �ǹ�
	int N, L, answer = 0, seq_length, cur_height;
	int** map;
	bool flag;
	//�Է°� ����
	cin >> N; cin >> L;
	map = new int* [N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	//��� ��鿡 ���� ����Ǵ��� Ž��
	for (int i = 0; i < N; i++) {
		//���� Ž��
		seq_length = 1;	//ó�� ���ӵ� ���� ���̸� 1�� �ʱ�ȭ
		cur_height = map[i][0];	//���� ���̴� ���� ������ ����
		flag = true;	//���� ����Ǵ��� �ȵǴ����� �ǹ�
		for (int j = 1; j < N; j++) {
			//���� ������ ���̰� ���� �ܰ��� ���̿� ���ٸ� seq_length���̸� 1�ø�
			if (map[i][j] == cur_height)	seq_length++;
			//���� ������ ���̰� ���� �ܰ��� ���̺��� 1��ŭ ũ�ٸ�?
			else if (map[i][j] == cur_height + 1) {
				//���� �ܰ��� ���̰� ������ ���̺��� ũ�ų� ���ٸ� ���θ� ���� �� ����
				if (seq_length >= L) {
					//���θ� ����, seq_length�� cur_height�� ���� �������� �ٽ� ����
					seq_length = 1;
					cur_height = map[i][j];
				}
				//���θ� ���� �� ���� ��� Ž�� ����
				else {
					flag = false;
					break;
				}
			}
			//���� ������ ���̰� ���� �ܰ��� ���̺��� 1��ŭ �۴ٸ�?
			else if (map[i][j] == cur_height - 1) {
				//���� L - 1���� ������ ���̰� �Ȱ����� Ȯ��
				for (int k = 1; k < L; k++) {
					if (j + k >= N || map[i][j + k] != cur_height - 1)	flag = false;
				}
				if (!flag)	break;
				//���θ� ����, seq_length�� cur_height�� ���� ���� ���� �������� �ʱ�ȭ
				j = j + L - 1;
				seq_length = 0;
				cur_height = map[i][j];
			}
			//���̰� 2�̻� ���̳��� ��� ���� �Ұ���
			else {
				flag = false;
				break;
			}
		}
		if (flag)	answer++;
		//���� Ž��
		seq_length = 1;
		cur_height = map[0][i];
		flag = true;
		for (int j = 1; j < N; j++) {
			if (map[j][i] == cur_height)	seq_length++;
			else if (map[j][i] == cur_height + 1) {
				if (seq_length >= L) {
					seq_length = 1;
					cur_height = map[j][i];
				}
				else {
					flag = false;
					break;
				}
			}
			else if (map[j][i] == cur_height - 1) {
				for (int k = 1; k < L; k++) {
					if (j + k >= N || map[j + k][i] != cur_height - 1)	flag = false;
				}
				if (!flag)	break;
				j = j + L - 1;
				seq_length = 0;
				cur_height = map[j][i];
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag)	answer++;
	}
	cout << answer;
	//���� �Ҵ� ����
	for (int i = 0; i < N; i++) {
		delete []map[i];
	}
	delete []map;
	return 0;
}