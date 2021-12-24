/*
문제 링크 : https://www.acmicpc.net/problem/1011
수학적 사고를 묻는 문제다.

공간이동 장치 작동 횟수를 최소화 하며 처음과 끝은 무조건 1광년을 이동한다고 한다.

이 말은 2n-1번의 움직임을 통해서 이동할 수 있는 최대 거리는 n*n임을 의미한다.(1, 2, 3 .... n, n-1, n-2 ... 2, 1)

또한 가장 큰 이동이 n이라면 최소 n*n의 거리를 이동한다는 뜻이다.

따라서 거리가 n*n 과 (n+1)*(n+1) 사이에 있다면 최소 2n번 혹은 2n+1의 움직임이 필요하다.

그렇다면 2n인지 2n+1인지는 어떻게 구별할 수 있을까?

예를 들어 우리가 구한 n 값이 3이라고 생각하자.

그렇다면 여기서 우리가 구할 수 있는 정답 값은 거리가 9~15 사이인 값들이다.

9는 1, 2, 3, 2, 1을 통해 최단 이동으로 갈 수 있다.
10은 9의 동선에서 1을 추가, 11은 9의 동선에서 2를 추가, 12는 9의 동선에서 3을 추가하여 갈 수 있다.
그러나 13을 위해서 4를 추가하면 문제의 조건상 13보다 더 멀리 가게 된다.
따라서 13은 3+1을, 14는 3+2를, 15는 3+3을 추가하는 방식으로 갈 수 있다.

즉, 이동하려는 거리가 n*n과 (n+1)*(n+1) 사이에 있고, n*n과의 거리가 n이하면 2n번, n초과면 2n+1번을 통해 도착할 수 있다.
*/
#include <iostream>
using namespace std;

int main(void) {
	long long T, x, y, distance, step;

	cin >> T;

	for (int a = 0; a < T; a++) {
		cin >> x >> y;
		distance = y - x;
		step = 1;
		while (1) {
			//distance가 1, 2...step, step-1...., 2, 1로 갈 수 있는 경우
			if (distance == step * step) {
				cout << 2 * step - 1 << endl;
				break;
			}
			else if (distance > step * step) {
				step++;
			}
			else {
				step--;
				distance -= step * step;
				if (distance > step)	cout << 2 * step + 1 << endl;
				else	cout << 2 * step << endl;
				break;
			}
		}

	}
	return 0;
}