/*
���� ��ũ : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRUN9KfZ8DFAUo
�ܼ��� ����Ž�� ������.

ȸ���� ���� ���� �� �ִ� ��� ���� ���Ѵ�. ���⼭ �ߺ��� �����ؾ��ϱ� ������ set�� �̿��Ͽ���.

��� ���� ���ϰ� ���� K��°�� ū ���� ����ϸ� �ȴ�.
*/
#include <iostream>
#include <set>
#include <string>

using namespace std;

int convert16to10(string str);

int main(int argc, char** argv)
{
	int T, N, K, count = 0, answer;
	set<string> __set;
	string input;
	string temp;
	
	cin >> T;
	
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� set�ʱ�ȭ
		cin >> N >> K;
		cin >> input;
		while (!__set.empty())	__set.erase(__set.begin());
		//���������� ���� ���� �� set�� �ִ´�
		for (int a = 0; a < input.size(); a++) {
			while (!temp.empty())	temp.pop_back();
			for (int b = 0; b < (N / 4); b++) {
				temp.push_back(input[(a + b) % N]);
			}
			if (__set.find(temp) == __set.end()) {	
				__set.insert(temp);
			}
		}
		//K��° ū ���� 10������ ��ȯ�� �� ���
		count = 0;
		for (set<string>::iterator itr = __set.begin(); itr != __set.end(); itr++) {
			if (count == __set.size() - K) {
				answer = convert16to10(*itr);
				cout << '#' << test_case << ' ' << answer << endl;
				break;
			}
			else	count++;
		}
	}
	return 0;
}
//16���� string�� 10���� int�� ��ȯ
int convert16to10(string str) {
	int ret = 0, temp = 1;

	for (int a = str.size() - 1; a >= 0; a--) {
		if (str[a] >= '0' && str[a] <= '9') {
			ret += temp * (int)(str[a] - '0');
		}
		else {
			ret += temp * (int)(str[a] - 'A' + 10);
		}
		temp *= 16;
	}
	return ret;
}