/*
���� ��ũ : https://www.acmicpc.net/problem/1701
kmp�� �ذ��� �� �ִ� ������.

�ٸ� ���λ�� ���̻縸 ����ϴ� ���� �ƴϱ⿡ ���ڿ��� ������ 0��°�� �ͺ��� end - 1��°�� �ͱ����� fail���� ��� ���� �� ���� ū ���� ���� �ȴ�.
*/
#include <iostream>
using namespace std;

int fail[5000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//�Է°� ���� �� ���� �ʱ�ȭ
	string str;
	int start = 0, end, answer = 0, k;

	cin >> str;
	end = str.size() - 1;
	//start�� 0���� end - 1������ ��� ��츦 ���
	while (start < end) {
		//fail�� �ʱ�ȭ �� ����κ��� ������ �ǹ��ϴ� ���� k�� 0���� ����
		for (int a = start; a <= end; a++)	fail[a] = 0;
		k = 0;
		//start + 1���� end���� fail�� ���
		for (int a = start + 1; a <= end; a++) {
			while (k > 0 && str[a] != str[k + start])	k = fail[k + start - 1];
			if (str[a] == str[k + start])	fail[a] = ++k;
		}
		//��� fail���� ���� ū ���� answer�� ����
		for (int a = start; a <= end; a++) {
			if (fail[a] > answer)	answer = fail[a];
		}
		start++;
	}
	cout << answer << endl;

	return 0;
}