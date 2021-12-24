/*
���� ��ũ : https://www.acmicpc.net/problem/5052
���ڿ� �񱳸� ���� ������.

�ִ� 10000���� ��ȭ��ȣ�� �Է����� �־����� ��ȭ��ȣ ����� �������� ���ϴ� �ϰ����� �ִ����� Ȯ���ؾ� �Ѵ�.

���� �ܼ��� ����� 10000���� ��ȭ��ȣ�� ���� �ڽ��� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 �ִ��� ������ Ȯ���ϸ� �ȴ�.

�׷��� �̷��� ������� ������ Ǯ ��� �ð��ʰ��� �Ͼ��.

�� ��� �񱳸� ���� �ʴ� ����� ����ؾ� �ϴµ� �̴� ������ ���ؼ� �����ϴ�.

���� ��� ��ȣ�� ������������ ������ �Ǿ� �ִٰ� ��������.

�׷��ٸ� n��° ��ȣ�� n+1��° ��ȣ�� �� ������ ��ȣ���Ը� ���ξ �� �� �ִ�. ���� n��° ��ȣ�� n+a��° ��ȣ�� ���ξ��� �ݵ�� n+1��° ��ȣ�� ���ξ��̱⵵ �ϴ�.

���� ������ �� ���¿����� n��°�� n+1��° ��ȣ���� ���ϸ� �ȴ�.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	int T, N;
	string str;
	vector<string> inputs;
	bool is_end;
	inputs.reserve(10000);
	//�Է°� ����
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> N;
		for (int b = 0; b < N; b++) {
			cin >> str;
			inputs.emplace_back(str);
		}
		//��ȣ�� ������������ ����
		sort(inputs.begin(), inputs.end());
		//��� n��°�� n+1��°�� ��ȣ ��
		is_end = false;
		for (int a = 0; a < inputs.size() - 1; a++) {
			if (inputs[a + 1].compare(0, inputs[a].size(), inputs[a]) == 0) {
				cout << "NO" << endl;
				is_end = true;
				break;
			}
		}
		if (!is_end)	cout << "YES" << endl;
		//���� �׽�Ʈ ���̽��� ���� ���� ����
		while (inputs.size() > 0)	inputs.pop_back();
	}
	return 0;
}