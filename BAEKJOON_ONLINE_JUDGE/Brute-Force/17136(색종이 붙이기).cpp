/*
문제 링크 : https://www.acmicpc.net/problem/17136
완전탐색을 통해 해결할 수 있는 문제다.
색종이를 최소한으로 사용하기 위해선 큰 색종이를 많이 쓰고 작은 색종이는 적게 쓰는게 유리하다.
따라서 칸을 하나하나 살피며 해당 칸을 왼쪽 위 꼭지점으로 가지는 최대의 정사각형부터 탐색을 하면 된다.
그러나 위의 방법으로 찾아낸 어떠한 칸이 3*3을 가지더라도 3*3을 덮는것이 최선이 아닌 예외 경우도 발생한다.
1 1 1 1
1 1 1 1
1 1 1
1 1
위와 같은 경우 3*3 1장과 1*1 4장을 사용하는 것은 2*2 3장과 1*1 1장을 사용하는 것보다 더 많을 색종이를 사용한다.
이러한 예외를 잡아내기 위해 큰 색종이부터 가능한지 탐색하되, 큰 색종이를 사용하는 경우와 그보다 작은 색종이를 사용하는 경우들을 모두 고려할 수 있도록 하였다.
*/
#include <iostream>
using namespace std;

int answer = 25;

void Get_Answer(int map[10][10], int size1, int size2, int size3, int size4, int size5, int num);
bool Check_Map(const int map[10][10], int size, int row, int col);

int main(void) {
	int map[10][10], num = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)	num++;
		}
	}

	Get_Answer(map, 5, 5, 5, 5, 5, num);

	if (answer == 25)	cout << -1;
	else	cout << answer;

	return 0;
}
//map은 아직 색종이로 덮여있지 않은 부분은 1, 색종이로 덮여진 부분과 덮으면 안되는 부분은 0으로 표시
//size1~5는 각각 크기별로 남은 색종이의 수를, num은 덮어야 할 1칸의 개수를 의미
void Get_Answer(int map[10][10], int size1, int size2, int size3, int size4, int size5, int num) {
	int attached;
	//덮어야 할 칸이 없으면 몇 장의 색종이를 사용했는지 계산하고 answer값과 비교, 최신화 한다
	if (num == 0) {
		attached = 25 - size1 - size2 - size3 - size4 - size5;
		if (attached < answer)	answer = attached;
		return;
	}
	//덮어야 할 칸이 남은 경우
	else {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				//1인 칸을 발견하고 난 뒤
				if (map[i][j] == 1) {
					//5*5색종이를 덮을 수 있는지 확인
					if (size5 > 0 && Check_Map(map, 5, i, j)) {
						//5*5로 덮는 경우
						size5--;
						for (int a = i; a < i + 5; a++) {
							for (int b = j; b < j + 5; b++) {
								map[a][b] = 0;
							}
						}
						Get_Answer(map, size1, size2, size3, size4, size5, num - 25);
						//5*5로 덮을 수 있으나 덮지 않는 경우
						size5++;
						for (int a = i; a < i + 5; a++) {
							for (int b = j; b < j + 5; b++) {
								map[a][b] = 1;
							}
						}
					}
					//4*4색종이를 덮을 수 있는지 확인
					if (size4 > 0 && Check_Map(map, 4, i, j)) {
						//4*4로 덮는 경우
						size4--;
						for (int a = i; a < i + 4; a++) {
							for (int b = j; b < j + 4; b++) {
								map[a][b] = 0;
							}
						}
						Get_Answer(map, size1, size2, size3, size4, size5, num - 16);
						//4*4로 덮을 수 있으나 덮지 않는 경우
						size4++;
						for (int a = i; a < i + 4; a++) {
							for (int b = j; b < j + 4; b++) {
								map[a][b] = 1;
							}
						}
					}
					//3*3색종이를 덮을 수 있는지 확인
					if (size3 > 0 && Check_Map(map, 3, i, j)) {
						//3*3로 덮는 경우
						size3--;
						for (int a = i; a < i + 3; a++) {
							for (int b = j; b < j + 3; b++) {
								map[a][b] = 0;
							}
						}
						Get_Answer(map, size1, size2, size3, size4, size5, num - 9);
						//3*3로 덮을 수 있으나 덮지 않는 경우
						size3++;
						for (int a = i; a < i + 3; a++) {
							for (int b = j; b < j + 3; b++) {
								map[a][b] = 1;
							}
						}
					}
					//2*2색종이를 덮을 수 있는지 확인
					if (size2 > 0 && Check_Map(map, 2, i, j)) {
						//2*2로 덮는 경우
						size2--;
						for (int a = i; a < i + 2; a++) {
							for (int b = j; b < j + 2; b++) {
								map[a][b] = 0;
							}
						}
						Get_Answer(map, size1, size2, size3, size4, size5, num - 4);
						//2*2로 덮을 수 있으나 덮지 않는 경우
						size2++;
						for (int a = i; a < i + 2; a++) {
							for (int b = j; b < j + 2; b++) {
								map[a][b] = 1;
							}
						}
					}
					//1*1색종이를 덮을 수 있는지 확인
					if (size1 > 0) {
						//1*1로 덮는 경우
						size1--;
						map[i][j] = 0;
						Get_Answer(map, size1, size2, size3, size4, size5, num - 1);
						//1*1로 덮을 수 있으나 덮지 않는 경우
						size1++;
						map[i][j] = 1;
					}
					return;
				}
			}
		}
		return;
	}
}
//row, col지점을 가장 왼쪽 위 꼭지점으로 가지는 size크기의 정사각형이 모두 덮어야 할 칸인지 확인하는 함수
bool Check_Map(const int map[10][10], int size, int row, int col) {
	if (size + row > 10 || size + col > 10)	return false;
	else {
		for (int i = row; i < row + size; i++) {
			for (int j = col; j < col + size; j++) {
				if (map[i][j] == 0)	return false;
			}
		}
		return true;
	}
}