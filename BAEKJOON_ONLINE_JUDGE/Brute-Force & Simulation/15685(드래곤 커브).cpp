/*
문제 링크 : https://www.acmicpc.net/problem/15685
시뮬레이션을 구현하면 해결할 수 있다.

회전하는 부분을 어떻게 처리할지가 관건이다. 문제에서 아래와 같은 규칙을 말해준다.

"K(K > 1)세대 드래곤 커브는 K-1세대 드래곤 커브를 끝 점을 기준으로 90도 시계 방향 회전 시킨 다음, 그것을 끝 점에 붙인 것이다."

이것을 쉽게 이야기 하면 K세대는 K-1세대의 드래곤 커브의 이동 순서를 역순으로 회전한 결과인 것이다. 조금 더 이해하기 쉽게 문제의 예제를 살펴보겠다.

0세대 : 0
1세대 : 0 / 1
2세대 : 0 1 / 2 1
3세대 : 0 1 2 1 / 2 3 2 1
4세대 : 0 1 2 1 2 3 2 1 / 2 3 0 3 2 3 2 1

위에서 0~3은 각각 문제에서 제시한 증가 및 감소 방향을 의미한다. 즉, 0세대는 시작점에서 0으로 이동한 그림이고 ..., 3세대는 0 1 2 1 2 3 2 1으로 이동했다는 의미이다.

또한 "/"를 기준으로 서로 대칭되는 것을 알 수 있다. 0->3, 1->2, 2->3, 3->0으로 서로 매칭이 되어 대칭이 된다.(같은 숫자로 매칭되지 않는 이유는 시계방향으로 90도 회전했기 때문)

위의 조건을 통해 주어진 N개의 드래곤 커브를 구하고 정사각형의 네 꼭짓점이 모두 드래곤 커브인 것의 개수를 구하면 된다.
*/
#include <iostream>
using namespace std;

void Get_Dragon_Curve(int map[101][101], int x, int y, int d, int g);
int get_2pow(int times);

int main(void) {
	int N, info[20][4], map[101][101], answer = 0;;
	//입력값 저장
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> info[i][0];
		cin >> info[i][1];
		cin >> info[i][2];
		cin >> info[i][3];
	}
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			map[i][j] = 0;
		}
	}
	//N개의 드래곤 커브를 구한다
	for (int i = 0; i < N; i++) {
		Get_Dragon_Curve(map, info[i][0], info[i][1], info[i][2], info[i][3]);
	}
	//네 꼭짓점이 모두 드래곤 커브인 정사각형 개수를 구한다
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)	answer++;
		}
	}
	
	cout << answer;
	return 0;
}

void Get_Dragon_Curve(int map[101][101], int x, int y, int d, int g) {
	//direction은 시작점에서 해당 드래곤 커브의 이동경로의 방향을 의미
	char direction[1025];
	int index = 1, pivot;
	//동적 할당 및 변수 초기화
	int** single_map;
	single_map = new int* [101];
	for (int i = 0; i < 101; i++)	single_map[i] = new int[101];
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			single_map[i][j] = 0;
		}
	}
	for (int i = 0; i < 1025; i++)	direction[i] = 0;
	direction[0] = d + 48;
	//위의 주석에서 설명한 대칭을 이용하여 g세대의 드래곤 커브 구하기
	for (int i = 1; i <= g; i++) {
		pivot = get_2pow(i - 1) - 1;
		for (int j = 0; j < get_2pow(i - 1); j++) {
			if (direction[pivot] == '3') {
				direction[index++] = '0';
				pivot--;
			}
			else {
				direction[index++] = direction[pivot--] + 1;
			}
		}
	}
	//이동경로대로 드래곤 커브를 구하고 값을 1로 구별
	single_map[y][x] = 1;
	for (int i = 0; i < get_2pow(g); i++) {
		if (direction[i] == '0')	single_map[y][++x] = 1;
		else if (direction[i] == '1')	single_map[--y][x] = 1;
		else if (direction[i] == '2')	single_map[y][--x] = 1;
		else	single_map[++y][x] = 1;
	}
	//전체 맵에 이번 드래곤 커브를 표시
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (single_map[i][j] == 1)	map[i][j] = 1;
		}
	}
	//동적 할당 해제
	for (int i = 0; i < 101; i++)	delete []single_map[i];
	delete []single_map;
}

int get_2pow(int times) {
	if (times == 0)	return 1;
	int ret = 1;
	for (int i = 0; i < times; i++) {
		ret *= 2;
	}
	return ret;
}