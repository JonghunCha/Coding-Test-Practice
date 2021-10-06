/*
���� ��ũ : https://www.acmicpc.net/problem/17136
�־��� ���� ������ �󸶳� �� �����ϰ� �����ϳİ� �߿��� ������.
�������� �䱸�� ���׵��� �����ϴ� ���� ũ�� ����� �ʴ�. �׷��� ���� ������ ���� ��Ȯ�� �������� ���Ѵٸ� ������ ���� �򰥸��� ����.
������ ���� ��ɾ 50,000,000�� �̻� ������ ��� ���α׷��� �׻� ����Ǿ��ų� ���� ������ �����ٰ� �Ͽ�����,
�� ���� ���� �������� ����Ǵ� ��ɾ��� ������ 50,000,000�� ���϶�� �Ѵ�.

��, ���� ������ �������� �� �������� �Ǵ��ϱ� ���ؼ� �ּ� 50,000,000���� ��ɾ� ������� 100,000,000���� ��ɾ� ������� ��� �������� ���ƴ��� Ȯ���ϸ� �ȴ�.
����, 50,000,000~100,000,000���̿����� ���� ���� ������ ��ĥ �� �ִ�. �׷��ٸ� � ������ ���� ������� �� �� ������?
���� ������ �ش� ������ ���� ������ ���Ѵٴ� �ǹ��̱⿡ ���� �ٱ����� ������ ���� ������ ���̴�.(������ ������ �������Ա⿡ �ٱ����� ������ ����ȴ�)

���� ���� ���׵��� ����ϸ� �������� �������̱⿡ ����� �ʰ� Ǯ �� �ִ�.
*/
#include <iostream>
#include <string>
using namespace std;

void Get_Answer(int M, int C, int I, unsigned char* arr, string program, string input_str);

int main(void) {
	int t, M, C, I;
	unsigned char* arr;
	string program, input_str;
	//�Է°� ����
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> M; cin >> C; cin >> I;
		arr = new unsigned char[M];
		if (arr == NULL)	cout << "dynamic allocation fail" << endl;
		for (int j = 0; j < M; j++)	arr[j] = 0;
		cin >> program; cin >> input_str;

		Get_Answer(M, C, I, arr, program, input_str);
		delete []arr;
	}

	return 0;
}

void Get_Answer(int M, int C, int I, unsigned char* arr, string program, string input_str) {
	int loop_num = 0, loop_index = 0;	//���� ������ ����, ���� ¦�� ���� �� ���Ǵ� ������ �ǹ�
	int** loop_start_end_index;			//������ ¦�� ���� �� �ش� ������ ���α׷� �ڵ忡�� � ��ġ�� �ִ����� ����
	//ptr�� �޸𸮻��� ���� ��ġ, index�� ���α׷� �ڵ���� ���� ��ġ, count�� ��ɾ��� ���� Ƚ��, str_index�� �Է� ���ڿ����� ���� ��ġ�� �ǹ�
	//outer_loop�� ���� ������ �Ǻ��� ��, ���� �ٱ��� ������ ������Ʈ �ϴµ� ����. last�� ���� �ٱ����� �������� �����ϴµ� ����)
	int ptr = 0, index = 0, count = 0, str_index = 0, outer_loop = -1, last = 0;
	
	//���α׷��� loop�� �� ������ ���
	for (int i = 0; i < program.length(); i++) {
		if (program[i] == '[')	loop_num++;
	}
	//������ ¦ ��ġ�� ���� ������ ���� �� �ִ� 2���� �迭 ���� �Ҵ�
	loop_start_end_index = new int* [loop_num];
	if (loop_start_end_index == NULL)	cout << "dynamic allocation fail" << endl;
	for (int i = 0; i < loop_num; i++) {
		loop_start_end_index[i] = new int[2];
		if (loop_start_end_index[i] == NULL)	cout << "dynamic allocation fail" << endl;
	}
	//������ ¦�� ���Ѵ�
	for (int i = 0; i < loop_num; i++) {
		loop_start_end_index[i][0] = -1;
		loop_start_end_index[i][1] = -1;
	}
	for (int i = 0; i < program.length(); i++) {
		if (program[i] == '[') {
			loop_start_end_index[loop_index][0] = i;
			loop_index++;
		}
		else if (program[i] == ']') {
			for (int j = loop_index - 1; j >= 0; j--) {
				if (loop_start_end_index[j][1] == -1) {
					loop_start_end_index[j][1] = i;
					break;
				}
			}
		}
	}
	//���α׷� ����
	while (1) {
		//index�� ���α׷� �ڵ� ������ ������ ����Ű�°� ���α׷��� �������� �ǹ�
		if (index == C) {
			cout << "Terminates" << endl;
			return;
		}
		//100,000,000���� ��ɾ �����ϸ� ���� ������ ��� 1���� ������ �����ٴ� �ǹ�
		else if (count >= 100000000) {
			cout << "Loops " << loop_start_end_index[outer_loop][0] << ' ' << loop_start_end_index[outer_loop][1] << endl;
			return;
		}
		else {
			if (program[index] == '-') {
				arr[ptr]--;
				index++;
			}
			else if (program[index] == '+') {
				arr[ptr]++;
				index++;
			}
			else if (program[index] == '<') {
				if (ptr != 0)	ptr--;
				else	ptr = M - 1;
				index++;
			}
			else if (program[index] == '>') {
				if (ptr != M - 1)	ptr++;
				else	ptr = 0;
				index++;
			}
			else if (program[index] == '[') {
				if (arr[ptr] == 0) {
					for (int i = 0; i < loop_num; i++) {
						if (loop_start_end_index[i][0] == index) {
							index = loop_start_end_index[i][1] + 1;
							break;
						}
					}
				}
				else	index++;
			}
			else if (program[index] == ']') {
				if (arr[ptr] != 0) {
					for (int i = 0; i < loop_num; i++) {
						if (loop_start_end_index[i][1] == index) {
							//50,000,000�̻��� ��� ���� ������ ������ ���̰�, index�� last���� ũ�ٸ� �̹� ������ ������� ���� �ٱ��� �������� �ǹ�
							if (count >= 50000000 && index > last) {
								outer_loop = i;
								last = index;
							}
							index = loop_start_end_index[i][0] + 1;
							break;
						}
					}
				}
				else	index++;
			}
			else if(program[index] == '.'){
				index++;
			}
			else {
				if (str_index == input_str.length())	arr[ptr] = 255;
				else	arr[ptr] = input_str[str_index++];
				index++;
			}
			count++;
		}
	}
}