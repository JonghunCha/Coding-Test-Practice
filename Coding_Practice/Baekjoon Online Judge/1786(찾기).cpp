/*
���� ��ũ : https://www.acmicpc.net/problem/1786
���ڿ� �˻� �˰����� KMP�� �̿��ϴ� ������.

KMP�˰����� ����� �����ϰ� �ִٸ� �ذ��ϴµ� ū ������ ���� ���̴�.

KMP�˰��� ���� �ڼ��� ������ ���ͳݿ� ���� �ڷᰡ �ִ�.

�߰��� ������ �Է¹ޱ� ���� getline�� ����Ͽ���.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> Get_Pi(string P);	//KMP�˰����� prefix == suffix�� �� �� �ִ� �κ� ���ڿ��� ���� �� ���� ���̸� ���
vector<int> KMP(string T, string P);	//KMP�˰����� �̿��Ͽ� ���䵵��

int main(void) {
	string T, P;
	vector<int> answer;
	//�Է°� ����
	getline(cin, T);
	getline(cin, P);
	answer = KMP(T, P);
	cout << answer.size() << endl;
	for (int a = 0; a < answer.size(); a++)	cout << answer[a] << ' ';

	return 0;
}

vector<int> Get_Pi(string P) {
	vector<int> ret(P.size(), 0);
	int index = 0, psize = P.size();
	for (int a = 1; a < psize; a++) {
		while (index > 0 && P[a] != P[index])	index = ret[index - 1];
		if (P[a] == P[index])	ret[a] = ++index;
	}
	return ret;
}

vector<int> KMP(string T, string P) {
	vector<int> ret;
	vector<int> pi = Get_Pi(P);
	int index = 0, tsize = T.size(), psize = P.size();
	for (int a = 0; a < tsize; a++) {
		while (index > 0 && T[a] != P[index])	index = pi[index - 1];
		if (T[a] == P[index]) {
			if (index == psize - 1) {
				ret.emplace_back(a - psize + 2);	//�������� ���ڿ��� index�� 1���� �����ϱ⿡ + 1�� ���ش�
				index = pi[index];
			}
			else	index++;
		}
	}
	return ret;
}