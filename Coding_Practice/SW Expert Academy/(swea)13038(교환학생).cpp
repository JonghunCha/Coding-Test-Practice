/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�ܼ� �ùķ��̼� ������.

�ڵ带 ���� ���� ������ �� ���� ���̴�.

N % weekclass�� 0���� �ƴ����� ���� ������ �Ʒ��� ����.

���� �������� ���� ��� N / weekclass�� ������ �������� ���������� ���� ���信 ���Ե��� �ʴ� ������ ���� �� �ִ�. ���� (N - 1) / weekclass�� ���� �׷��� ������ ��Ҵ�.

�ݴ�� �������� �ִ� ��� N / weekclass�� ������ ���信 ���ԵǾ�߸� �ϴ� �Ⱓ�̱⿡ ����� ����.
*/
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int T, N, A[7], remain, weekclass, answer, temp;

	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ���� �ʱ�ȭ
		cin >> N;
		weekclass = 0;
		answer = 1000000;
		for (int a = 0; a < 7; a++) {
			cin >> A[a];
			if (A[a] == 1)	weekclass++;
		}

		if (N % weekclass == 0) {	//�����ϴ� ���� ���� ���ֿ� ���� �� �ִ� ���Ǽ��� ������ ���� ���������� ���
			for (int a = 0; a < 7; a++) {	//�������� �Ͽ��Ϻ���~����ϱ����� ���
				temp = ((N - 1) / weekclass) * 7;
				remain = weekclass;

				for (int b = a; b < a + 7; b++) {
					temp++;
					if (A[b % 7] == 1)	remain--;
					if (remain == 0) {
						if (temp < answer)	answer = temp;
						break;
					}
				}
			}
		}
		else {	//�����ϴ� ���� ���� ���ֿ� ���� �� �ִ� ���Ǽ��� �������� �� �������� �ִ� ���
			for (int a = 0; a < 7; a++) {	
				temp = (N / weekclass) * 7;
				remain = N % weekclass;
				for (int b = a; b < a + 7; b++) {
					temp++;
					if (A[b % 7] == 1)	remain--;
					if (remain == 0) {
						if (temp < answer)	answer = temp;
						break;
					}
				}
			}
		}

		cout << '#' << test_case << ' ' << answer << endl;
	}
	return 0;
}