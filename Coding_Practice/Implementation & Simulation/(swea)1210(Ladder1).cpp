/*
���� ��ũ : https://swexpertacademy.com/main/main.do
��ٸ� Ÿ�� ���� ������.

��ٸ� Ÿ�⿡�� Ư�� �������� ������ �� �ִ� �������� �ϳ���.

���� ������ �����ϱ� ���ؼ� ���������� ���� �ö󰡸� �������� ã���� �ȴ�.
*/
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int T, ladder[100][100], x, y, direction;
	
	for (int test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> T;
		x = 99;
		direction = 1;	//direction 1 = ��, 2 = ������, 3 = �������� �̵����� �ǹ�
		for (int a = 0; a < 100; a++) {
			for (int b = 0; b < 100; b++) {
				cin >> ladder[a][b];
				if (ladder[a][b] == 2)	y = b;
			}
		}
		//���� ���� ������ ������ �ݺ�
		while (x != 0) {
			if (direction == 1) {	//���� �̵����� ���
				x--;
				if (y < 99 && ladder[x][y + 1] == 1)	direction = 2;	//�����ʿ� ��ٸ��� �ִ� ���
				else if (y > 0 && ladder[x][y - 1] == 1)	direction = 3;	//���ʿ� ��ٸ��� �ִ� ���
			}
			else if (direction == 2) {
				y++;
				if (y == 99 || ladder[x][y + 1] == 0)	direction = 1;	//�� �̻� ���������� �̵��� �� ���� ���
			}
			else {
				y--;
				if (y == 0 || ladder[x][y - 1] == 0)	direction = 1;	//�� �̻� �������� �̵��� �� ���� ���
			}
		}
		cout << '#' << test_case << ' ' << y << endl;
	}
	return 0;
}