/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���� Ž������ �ذ��� �� �ִ� ������.

�ܽ����� ������ ������ ���� �ִ� 11^6 = �� 177�����̴�.

���� ��� ���տ� ���� ������ ������ �����ϸ� ���������� ���� �տ����� ������ ����ϸ� �ȴ�.
*/
#include <cstdio>
using namespace std;

bool is_end;
int answer[7], N, X, M, max_hnum;

void DFS(int records[11][3], int nums[7], int index, int hnum);
bool is_correct(int records[11][3], int nums[7]);

int main(int argc, char** argv)
{
	int T, records[10][3], nums[7];

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ���� �ʱ�ȭ
		scanf("%d %d %d", &N, &X, &M);
		for (int a = 1; a <= M; a++) {
			scanf("%d %d %d", &records[a][0], &records[a][1], &records[a][2]);
		}
		max_hnum = 0;
		is_end = false;
		//��� ���տ� ���� Ž��
		DFS(records, nums, 1, 0);

		if (!is_end) {	//���� ������ ��츦 �� ã�Ҵٸ� -1 ���
			printf("#%d -1\n", test_case);
		}
		else {	//���� ���
			printf("#%d ", test_case);
			for (int a = 1; a <= N; a++)	printf("%d ", answer[a]);
			printf("\n");
		}
	}
	return 0;
}

void DFS(int records[11][3], int nums[7], int index, int hnum) {
	bool change = false;
	//N���� �濡 �ܽ����� ���� �� ������ ���
	if (index == N + 1) {
		if (is_correct(records, nums) && hnum >= max_hnum) {	//���� �ش� ��찡 ������ ������ �����ϸ�, ������� �ִ��� �ܽ��͸� �����ϴ� ����� ��
			if (hnum > max_hnum) {	//���� �ܽ��� ���� �� ũ�ٸ� ���� ��ü
				for (int a = 1; a <= N; a++) {
					answer[a] = nums[a];
				}
				max_hnum = hnum;
			}
			else {	//�ܽ��� ���� ���� ��� ���������� �տ� ���� ���� �������� ����
				for (int a = 1; a <= N; a++) {
					if (nums[a] < answer[a]) {
						change = true;
						break;
					}
					else if (nums[a] > answer[a]) {
						break;
					}
				}

				if (change) {
					for (int a = 1; a <= N; a++) {
						answer[a] = nums[a];
					}
				}
			}

			is_end = true;
		}
		return;
	}
	//index��°�� �濡 �ܽ��ͼ� ����
	for (int a = 0; a <= X; a++) {
		nums[index] = a;
		DFS(records, nums, index + 1, hnum + a);
	}
}
//������ �־��� M���� ����� nums������ �����ϴ��� �˻�
bool is_correct(int records[11][3], int nums[7]) {
	int sum;

	for (int a = 1; a <= M; a++) {
		sum = 0;
		for (int b = records[a][0]; b <= records[a][1]; b++) {
			sum += nums[b];
		}
		if (sum != records[a][2])	return false;
	}

	return true;
}