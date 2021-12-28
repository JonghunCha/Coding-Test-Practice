/*
���� ��ũ : https://www.acmicpc.net/problem/1013
�ܼ� ���� ������ ������.

�������� ���ϴ� ���ĵ��� ������ (100+1+ | 01+)�̴�.

���ĵ��� ó������ ������ ���Ǹ� �������� ��� ���������� ������ ������ �ذ��� �� �ִ�.

�Ʒ� �ڵ忡�� mode�� �� ���¸� ��Ÿ���µ� ���� ���� ���´� �Ʒ��� ����.
0 : ���� ���°� �������� �ʾ����� ���� �Է°��� ���� ���°� �ٲ��.
1 : 100+1+ ���� ù ��° 1�� �Է¹��� ����
2 : 01 ���� 0�� �Է¹��� ����
3 : 100+1+ ���� ù ��° 0�� �Է¹��� ����
4 : 100+1+ ���� 0+�κп� ������ ����
5 : 100+1+ ���� 1+�κп� ������ ����
*/
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int T, mode = 0;
	string input;
	bool correct;
	//�Է°� ����
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> input;
		if (input.size() < 2) {
			cout << "NO" << endl;
			continue;
		}
		if (input[0] == '1')	mode = 1;	//ù ���ڰ� 1�̸� mode�� 1
		else	mode = 2;	//ù ���ڰ� 0�̸� mode�� 2
		correct = true;
		for (int b = 1; b < input.size(); b++) {
			//mode�� 0�� �� ���� ������ ���� ���� mode�� 1�Ǵ� 2�� �ٲ�
			if (mode == 0) {	
				if (input[b] == '1')	mode = 1;
				else	mode = 2;
			}
			//������ 100+1+�� ù ��° 1�� ������ ������ ���� ���ڴ� 0�� ���;� �ùٸ� ���̰�, mode�� 3���� �ٲ�
			else if (mode == 1) {
				if (input[b] == '1') {
					correct = false;
					break;
				}
				else	mode = 3;
			}
			//������ 01�� ������ ������ ���� ���ڴ� 1�� ���;߸� �ùٸ� ���̰�, 01������ ���������� mode�� 0���� �ٲ�
			else if (mode == 2) {
				if (input[b] == '0') {
					correct = false;
					break;
				}
				else	mode = 0;
			}
			//������ 100+1+�� 0�� ���� ������ ���� ���ڴ� 0�� ���;߸� �ùٸ� ���̰�, 0+�� �����Ͽ��⿡ mode�� 4�� �ٲ�
			else if (mode == 3) {
				if (input[b] == '1') {
					correct = false;
					break;
				}
				else	mode = 4;
			}
			//0+�� ������ ���·� 0�� 1��� �͵� �ȴ�. �׷��� 1�� �� ��� �ش� 1�� 1+�� ������ 1������ Ȯ���Ͽ��� �Ѵ�
			//1+�� ������ 1�̶�� mode�� 0���� �ٲٰ� �׷��� �ʴٸ� 1+�� ����Ǿ�� �ϱ⿡ mode�� 5�� �ٲ�
			else if (mode == 4) {
				if (input[b] == '1') {
					if (b + 1 == input.size() || input[b + 1] == '0')	mode = 0;
					else	mode = 5;
				}
			}
			//mode5������ 4���� ��찡 ���� �� �ִ�.
			//1. 0�� �ԷµǾ� 01�� ������ ���
			//2. 1�� �ԷµǾ��� �ش� 1�� 100+1+�� ù ��° 1�� ���
			//3. 1�� �ԷµǾ��� ���ڿ��� ������ ������ ���(��, 100+1+�� ������ ����)
			//4. 1�� �ԷµǾ��� 1+�� �������� ���
			else if (mode == 5) {
				if (input[b] == '1') {
					if (b + 2 < input.size() && input[b + 1] == '0' && input[b + 2] == '0')	mode = 1;
					else if (b + 1 == input.size())	mode = 0;
				}
				else	mode = 2;
			}
		}
		//�߰��� correct�� �ٲ����� �ʾ����� ���İ� �ùٸ� ǥ������ ������ ���� ��찡 ���� �� �ִ�.
		//�� ��쿣 mode�� 0�� �ƴ� ���̴�.
		if (correct) {
			if (mode == 0)	cout << "YES" << endl;
			else	cout << "NO" << endl;	
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}