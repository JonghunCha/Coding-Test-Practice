/*
���� ��ũ : https://www.acmicpc.net/problem/5430
���ڿ� �Ľ��� �䱸�ϴ� ������.

�������� ���õ� 2���� �Լ� R�� D�� ���� ���� �迭�� ������ �Լ�, �� ���� ���ڸ� ����� �Լ��̴�.

�׷��� R�Լ��� �����ϱ� ���� ������ �迭�� ������ ������ ���� �ſ� ��ȿ�����̴�. �̸� �ذ��ϱ� ���� �迭�� �׷��� �ΰ� �հ� ���� ǥ�ø� �ٲ��־���.

���� ���� ���� ������ �ϸ� D�Լ��� ���� �迭�� �տ����� ������ �Ͼ�� �ڿ����� ������ �Ͼ��.
���� �̷��� ���۹�Ŀ� ������ ��(deque)�� ����Ͽ���.
*/
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void) {
	int T, N, index;
	string funtion, nums, temp;
	deque<string> dq;
	bool reverse, is_end;
	funtion.reserve(100001);
	nums.reserve(100001);
	//�Է°� ����
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> funtion;
		cin >> N;
		cin >> nums;
		while (dq.size() > 0)	dq.pop_back();	//���� ����ش�
		//�Է� string���� ���ڿ� �ش�Ǵ� string�� ���� ä���ش�
		for (int b = 0; b < nums.size(); b++) {
			if (nums[b] == '[' || nums[b] == ',') {
				index = 0;
				while (temp.size() > 0)	temp.pop_back();
				for (int c = b + 1; c < nums.size(); c++) {
					if (nums[c] != ',' && nums[c] != ']')	temp += nums[c];
					else	break;
				}
				if(temp.size() > 0)		dq.emplace_back(temp);
			}
		}
		reverse = false;	//reverse�� R�Լ��� ���� �ٲ�� �ʱ⿡�� false
		is_end = false;		//is_end�� ������ �� ��� true�� �ȴ�
		for (int b = 0; b < funtion.size(); b++) {
			if (funtion[b] == 'R')	reverse = !reverse;
			else {
				if (!reverse && dq.size() > 0) {
					dq.erase(dq.begin());
				}
				else if (reverse && dq.size() > 0) {
					dq.erase(dq.end() - 1);
				}
				else {
					cout << "error" << endl;
					is_end = true;
					break;
				}
			}
		}
		//��Ŀ� ���� ������ ���
		if (!is_end) {
			cout << "[";
			if (!reverse) {
				for (int b = 0; b < dq.size(); b++) {
					cout << dq[b];
					if (b != dq.size() - 1)	cout << ",";
				}
			}
			else {
				for (int b = dq.size() - 1; b >= 0; b--) {
					cout << dq[b];
					if (b != 0)	cout << ",";
				}
			}
			cout << "]" << endl;
		}
	}
	return 0;
}