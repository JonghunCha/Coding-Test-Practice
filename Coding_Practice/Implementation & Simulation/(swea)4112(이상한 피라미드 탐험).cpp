/*
문제 링크 : https://swexpertacademy.com/main/main.do
단순 구현 문제에 가깝다.

피라미드를 2차원 배열에 담는다고 생각을 한 뒤 출발지와 목적지의 좌표를 비교하며 목적지에 가까워 지는 방향으로 이동시키면 된다.
*/
#include <iostream>
using namespace std;

int cordinate[10001][2];
int dx[6] = { -1, -1, 0, 0, 1, 1 };
int dy[6] = { -1, 0, -1, 1, 0, 1 };

int main(int argc, char** argv)
{
	int T, x = 1, y = 1, x1, x2, y1, y2, answer;
	//a는 방 번호를 의미하며 x, y는 해당 방의 좌표를 의미
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
		//입력값 저장 및 변수 초기화
		cin >> x >> y;
		x1 = cordinate[x][0];
		y1 = cordinate[x][1];
		x2 = cordinate[y][0];
		y2 = cordinate[y][1];
		answer = 0;
		//현재 위치를 의미하는 x1, y1이 목적지인 x2, y2에 도달할 때까지 반복
		//while문 내부는 현재 위치에서 이동할 수 있는 선택지 중 x2, y2에 가까워 지는 방향을 선택
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