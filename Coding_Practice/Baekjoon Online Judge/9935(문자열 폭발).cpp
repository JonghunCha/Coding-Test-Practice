/*
���� ��ũ : https://www.acmicpc.net/problem/9935
���ڿ� ó�� �����̱� �ϳ� string�� ����ó�� ����Ѵٴ� ������ ���ù����� �з��Ͽ���.

�־��� ���ڿ��� answer�� �ϳ��� ���� �ִ´�.

���� ����ִ� ���ڰ� ���� ���ڿ��� ������ ���ڶ��, answer�� �� �κ�(���� ���ڿ� ���̸�ŭ)�� ���� ���ڿ��� ���Ѵ�.

���� ���� ���ٸ� ���� ���ڿ��� answer���� pop()�ϰ� �׷��� �ʴٸ� ��� ������ �Ѵ�.
*/
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(void) {
	string input, boom, answer;
	int n;
	//�Է°� ���� �� ���� �ʱ�ȭ
	answer.reserve(1000000);
	cin >> input >> boom;
	n = boom.size();

	for (int a = 0; a < input.size(); a++) {
		//answer�� ���ڸ� �ϳ��� �ִ´�
		answer.push_back(input[a]);
		//���� �ش� �������� ���� ���ڰ� ���� ���ڿ��� �� ������ �����̰� answer�� ���̰� ���� ���ڿ��� ���ų� ũ�� ���� ���ڿ��� ����������� ��
		if (input[a] == boom[n - 1] && answer.size() >= n && answer.substr(answer.size() - n, n).compare(boom) == 0) {
			for (int a = 0; a < n; a++)	answer.pop_back();
		}
	}

	if (answer.size() == 0)	cout << "FRULA" << endl;
	else	cout << answer << endl;

	return 0;
}