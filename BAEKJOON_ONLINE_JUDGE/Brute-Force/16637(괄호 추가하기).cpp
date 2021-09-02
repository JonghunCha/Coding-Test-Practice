/*
���� ��ũ : https://www.acmicpc.net/problem/16637
����Ž���� ���� �ذ��� �� �ִ� �����̴�.
��� ��ȣ�� ������ ���� �� �ϳ��ϳ� ����غ��� �ִ��� ���ϸ� �ȴ�.
*/
#include <iostream>
using namespace std;

long long answer = -999999999999;

void Get_Answer(const int N, const int nums[10], const char operators[9], int flag[9], int step);	//������ �����ϴ� �Լ�
void Calculate(const int N, const int nums[10], const char operators[9], int flag[9]);	//��ȣ�� ������ ��ģ �� ���������� ����ϰ� answer���� ���ϴ� �Լ�

int main(void) {
	int N, nums[10];	//nums���� �Է°��� �������� ����
	char operators[9];	//operators���� �Է°��� �����ڵ��� ����

	cin >> N;

	//�Է� ���ڿ��� �����ڿ� �������� ���� ����
	for (int i = 0; i < N / 2; i++) {
		cin >> nums[i];
		cin >> operators[i];
	}
	cin >> nums[(N / 2)];

	//N�� ���̰� 1�� ��� ����ó��
	if (N == 1) {
		cout << nums[0];
		return 0;
	}

	//N�� ���̰� 3�� ��� ����ó��
	if (N == 3) {
		if (operators[0] == '+')	cout << nums[0] + nums[1];
		else if (operators[0] == '-')	cout << nums[0] - nums[1];
		else cout << nums[0] * nums[1];
		return 0;
	}

	//flag�� �� �����ڰ� ��ȣ �ȿ� �ִ��� �������� ��Ÿ����(1�̸� ��ȣ ��, 0�̸� ��ȣ ���� �ǹ�)
	int flag[9];
	for (int i = 0; i < N / 2; i++)	flag[i] = 0;

	Get_Answer(N, nums, operators, flag, 0);
	cout << answer;

	return 0;
}

void Get_Answer(const int N, const int nums[10], const char operators[9], int flag[9], int step) {
	if (step == 0) {
		Get_Answer(N, nums, operators, flag, step + 1);
		flag[0] = 1;
		Get_Answer(N, nums, operators, flag, step + 1);
	}
	else if (step == N / 2) {
		Calculate(N, nums, operators, flag);
		return;
	}
	else {
		if (flag[step - 1] == 0) {
			Get_Answer(N, nums, operators, flag, step + 1);
			flag[step] = 1;
			Get_Answer(N, nums, operators, flag, step + 1);
			flag[step] = 0;
		}
		else {
			Get_Answer(N, nums, operators, flag, step + 1);
		}
	}
}

void Calculate(const int N, const int nums[10], const char operators[9], int flag[9]) {
	int new_nums[10];	//new_nums���� ��ȣ ������ ���� �� �� ���Ӱ� ������� ���� ������ ����
	char new_operators[9];	//new_operators���� ��ȣ ������ ���� �� �� ���� �����ڵ��� ������� ����
	int nums_index = 0, operators_index = 0, temp;	//���� new_nums�� new_operators�� ���ǹ��� ���� ������ ������ ��Ҹ� ����Ŵ
	int ret = 0;

	//�����ڵ��� �տ��� ���� ���Ǹ� ��ȣ ������ ���� ó���ϰ� ��ȣ�� ���� ���ο� ������� �����Ѵ�
	for (int i = 0; i < N / 2; i++) {
		if (flag[i] == 0) {
			if (i == (N / 2) - 1) {
				new_nums[nums_index++] = nums[i];
				new_nums[nums_index++] = nums[i + 1];
				new_operators[operators_index++] = operators[i];
				break;
			}
			new_nums[nums_index++] = nums[i];
			new_operators[operators_index++] = operators[i];
		}
		else {
			if (operators[i] == '+')	temp = nums[i] + nums[i + 1];
			else if (operators[i] == '-')	temp = nums[i] - nums[i + 1];
			else	temp = nums[i] * nums[i + 1];
			if (i == (N / 2) - 1) {
				new_nums[nums_index++] = temp;
				break;
			}
			new_nums[nums_index++] = temp;
			new_operators[operators_index++] = operators[i + 1];
			i++;
			if (i == (N / 2) - 1)	new_nums[nums_index++] = nums[i + 1];
		}
	}
	//���Ӱ� ������� ������� �տ������� ����Ѵ�
	for (int i = 0; i < operators_index; i++) {
		if (i == 0) {
			if (new_operators[i] == '+')	ret = new_nums[i] + new_nums[i + 1];
			else if (new_operators[i] == '-')	ret = new_nums[i] - new_nums[i + 1];
			else	ret = new_nums[i] * new_nums[i + 1];
		}
		else {
			if (new_operators[i] == '+')	ret = ret + new_nums[i + 1];
			else if (new_operators[i] == '-')	ret = ret - new_nums[i + 1];
			else ret = ret * new_nums[i + 1];
		}
	}
	//�ִ��� ����ؼ� ������Ʈ �Ѵ�
	if (ret > answer)	answer = ret;
}