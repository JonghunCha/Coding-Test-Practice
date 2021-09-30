/*
���� ��ũ : https://www.acmicpc.net/problem/17471
�⺻������ ���� Ž���� ���� �ذ��� �� ������, ���� ó���� ���� �׷��� Ž���� �� �ʿ䰡 �ִ�.

������ �ִ� 10���̸� ���ű��� 2���̹Ƿ� 10���� ������ 2���� ���ű��� ������ ��� ��쿡 ���� ������ ���Ѵ�.

�׷� ���� �������� �������� 2���� ���ű��� ������ ������ �����ϴ��� Ȯ���ؾ� �Ѵ�.

������ ���ű� ������ ���� ������ �Ʒ��� ���� 2������ �ִ�.
1. ���ű��� ������ ��� �ϳ��� �����ؾ� �Ѵ�.
2. �� ���ű��� ���Ե��ִ� ������ ��� ����Ǿ� �־�� �Ѵ�.

���� ��� ���տ��� �� �ΰ��� ��츦 ������ ��, �ο����� ���̰� �ּҰ� �Ǵ� ��츦 ����ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

int answer = 100000000;

void Make_Combination(int N, int population[11], int neighbor[11][11], int zone_one[10], int zone_two[10], int one_index, int two_index, int step);
bool Is_Possible(int N, int neighbor[11][11], int zone_one[10], int zone_two[10], int one_index, int two_index);
bool Find_Path(int neighbor[11][11], int zone[10], int zone_length, int v1, int v2);
void Calculate(int N, int population[11], int zone_one[10], int zone_two[10], int one_index, int two_index);

int main(void) {
	int N, population[11], neighbor[11][11];	//�Է��� �ޱ� ���� �����
	int zone_one[10], zone_two[10];				//���� ���ű�1, 2�� �ǹ��ϸ� ������ ��ȣ�� ����
	int temp1, temp2;
	//�Է°� ����(neighbor�� ��� �̿��� ��� 1��, �ƴ� ��� -1�� ����)
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> population[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			neighbor[i][j] = -1;
		}
	}
	for (int i = 1; i <= N; i++) {
		cin >> temp1;
		for (int j = 1; j <= temp1; j++) {
			cin >> temp2;
			neighbor[i][temp2] = 1;
		}
	}
	//��� ������ ����� �Լ� ȣ��
	Make_Combination(N, population, neighbor, zone_one, zone_two, 0, 0, 1);
	
	if (answer == 100000000)	cout << -1;
	else	cout << answer;

	return 0;
}

void Make_Combination(int N, int population[11], int neighbor[11][11], int zone_one[10], int zone_two[10], int one_index, int two_index, int step) {
	//step�� N+1�̶�� ���� ���ű� ������ �����ٴ� ��
	if (step == N + 1) {
		//Is_Possible�Լ��� ���� ������ ������ �����ϴ��� Ȯ�� �� �� �ο��� ���̸� ���
		if (Is_Possible(N, neighbor, zone_one, zone_two, one_index, two_index))	Calculate(N, population, zone_one, zone_two, one_index, two_index);
		return;
	}
	//�̹� �ܰ��� ������ ���ű� 1�� �ִ� ���
	zone_one[one_index] = step;
	Make_Combination(N, population, neighbor, zone_one, zone_two, one_index + 1, two_index, step + 1);
	//�̹� �ܰ��� ������ ���ű� 2�� �ִ� ���
	zone_two[two_index] = step;
	Make_Combination(N, population, neighbor, zone_one, zone_two, one_index, two_index + 1, step + 1);
}
//������ ������ ������ �����ϴ��� Ȯ���ϴ� �Լ�
bool Is_Possible(int N, int neighbor[11][11], int zone_one[10], int zone_two[10], int one_index, int two_index) {
	bool flag;
	//���ű��� �Ҵ� �� ������ �ϳ��� ���� ��� false ��ȯ
	if (one_index == 0 || two_index == 0)	return false;
	//���ű��� �Ҵ� �� ������ 1����� ���� ���� ���� Ȯ���� �ʿ� ����
	if (one_index != 1) {
		for (int i = 0; i < one_index; i++) {
			for (int j = 0; j < one_index; j++) {
				//1�� ���ű��� ��� ������ ��ȣ ����Ǿ� �ִ��� Ȯ��
				if(!Find_Path(neighbor, zone_one, one_index, zone_one[i], zone_one[j]))		return false;
			}
		}
	}
	if (two_index != 1) {
		for (int i = 0; i < two_index; i++) {
			for (int j = 0; j < two_index; j++) {
				if (!Find_Path(neighbor, zone_two, two_index, zone_two[i], zone_two[j]))	return false;
			}
		}
	}
	return true;
}
//������ �� ���� �ٸ� �� ������ ����Ǿ� �ִ��� Ȯ���ϴ� �Լ�
bool Find_Path(int neighbor[11][11], int zone[10], int zone_length, int v1, int v2) {
	//stack�� �׷��� Ž������ �������� �˻��� node�� ����, memory�� �̹� �˻��� �������� �ƴ����� ����(1�̸� �˻��� ����, 0�̸� ���� �˻����� ���� ����)
	int stack[11], stack_size = 1, memory[11];
	for (int i = 1; i < 11; i++)	memory[i] = 0;
	//v1�� v2�� ���� ��� �ٷ� true ��ȯ
	if (v1 == v2)	return true;
	
	stack[1] = v1;
	memory[v1] = 1;
	int now;
	while (stack_size > 0) {
		now = stack[stack_size--];
		if (neighbor[now][v2] == 1)	return true;
		for (int i = 0; i < zone_length; i++) {
			if (neighbor[now][zone[i]] == 1 && memory[zone[i]] == 0) {
				stack[++stack_size] = zone[i];
				memory[zone[i]] = 1;
			}
		}
	}
	return false;
}
//�� ���������� �ο����̸� Ȯ���ϴ� �Լ�
void Calculate(int N, int population[11], int zone_one[10], int zone_two[10], int one_index, int two_index) {
	int sum1 = 0, sum2 = 0, result;
	for (int i = 0; i < one_index; i++)	sum1 += population[zone_one[i]];
	for (int i = 0; i < two_index; i++)	sum2 += population[zone_two[i]];
	if (sum1 > sum2)	result = sum1 - sum2;
	else	result = sum2 - sum1;
	if (result < answer)	answer = result;
}