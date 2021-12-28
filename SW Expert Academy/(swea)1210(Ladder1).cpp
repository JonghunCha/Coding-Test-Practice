/*
문제 링크 : https://swexpertacademy.com/main/main.do
사다리 타기 구현 문제다.

사다리 타기에서 특정 도착점에 도달할 수 있는 시작점은 하나다.

따라서 정답을 도출하기 위해선 도착점에서 위로 올라가며 시작점을 찾으면 된다.
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
		direction = 1;	//direction 1 = 위, 2 = 오른쪽, 3 = 왼쪽으로 이동함을 의미
		for (int a = 0; a < 100; a++) {
			for (int b = 0; b < 100; b++) {
				cin >> ladder[a][b];
				if (ladder[a][b] == 2)	y = b;
			}
		}
		//가장 위에 도달할 때까지 반복
		while (x != 0) {
			if (direction == 1) {	//위로 이동중인 경우
				x--;
				if (y < 99 && ladder[x][y + 1] == 1)	direction = 2;	//오른쪽에 사다리가 있는 경우
				else if (y > 0 && ladder[x][y - 1] == 1)	direction = 3;	//왼쪽에 사다리가 있는 경우
			}
			else if (direction == 2) {
				y++;
				if (y == 99 || ladder[x][y + 1] == 0)	direction = 1;	//더 이상 오른쪽으로 이동할 수 없는 경우
			}
			else {
				y--;
				if (y == 0 || ladder[x][y - 1] == 0)	direction = 1;	//더 이상 왼쪽으로 이동할 수 없는 경우
			}
		}
		cout << '#' << test_case << ' ' << y << endl;
	}
	return 0;
}