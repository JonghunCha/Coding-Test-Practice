/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�ܼ� ���� ������ ������.

�Ƕ�̵带 2���� �迭�� ��´ٰ� ������ �� �� ������� �������� ��ǥ�� ���ϸ� �������� ����� ���� �������� �̵���Ű�� �ȴ�.
*/
#include <iostream>
using namespace std;

int cordinate[10001][2];
int dx[6] = { -1, -1, 0, 0, 1, 1 };
int dy[6] = { -1, 0, -1, 1, 0, 1 };

int main(int argc, char** argv)
{
	int T, x = 1, y = 1, x1, x2, y1, y2, answer;
	//a�� �� ��ȣ�� �ǹ��ϸ� x, y�� �ش� ���� ��ǥ�� �ǹ�
	for (int a = 1; a <= 10000; a++) {
		cordinate[a][0] = x;
		cordinate[a][1] = y;
		y++;
		if (y > x) {
			x++;
			y = 1;
		}
	}
	
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ���� �ʱ�ȭ
		cin >> x >> y;
		x1 = cordinate[x][0];
		y1 = cordinate[x][1];
		x2 = cordinate[y][0];
		y2 = cordinate[y][1];
		answer = 0;
		//���� ��ġ�� �ǹ��ϴ� x1, y1�� �������� x2, y2�� ������ ������ �ݺ�
		//while�� ���δ� ���� ��ġ���� �̵��� �� �ִ� ������ �� x2, y2�� ����� ���� ������ ����
		while (x1 != x2 || y1 != y2) {
			answer++;
			if (x1 == x2) {	
				if (y1 < y2)	y1++;
				else	y1--;
			}
			else if (x1 < x2) {	
				x1++;
				if (y1 < y2)	y1++;
			}
			else {	
				x1--;
				if (y1 > y2)	y1--;
			}
		}

		cout << '#' << test_case << ' ' << answer << endl;
	}
	return 0;
}