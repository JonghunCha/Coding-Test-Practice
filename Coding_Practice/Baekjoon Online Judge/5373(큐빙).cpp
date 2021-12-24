/*
문제 링크 : https://www.acmicpc.net/problem/5373
단순 구현 문제이다.

풀이법이라고 할 것도 없다. 그냥 큐브를 잘 회전만 시키면 된다. 다만 3차원 큐브를 회전 시킬 때 배열의 인덱스가 뒤죽박죽 되지 않도록 신경을 좀 써야하는 부분이 있다.
*/
#include <iostream>
using namespace std;

void rotate(char cube[6][3][3], char input[3]);

int main(void) {
	int testcase, n;
	char cube[6][3][3];	//index 0->윗면, 1->오른쪽면, 2->앞면, 3->왼쪽면, 4->뒷면, 5->아랫면
	char input[3];
	//입력값 저장
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		//각 테스트케이스별로 큐브 초기화
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				cube[0][a][b] = 'w';
				cube[1][a][b] = 'b';
				cube[2][a][b] = 'r';
				cube[3][a][b] = 'g';
				cube[4][a][b] = 'o';
				cube[5][a][b] = 'y';
			}
		}
		//회전 방식 입력 받고 회전 실시
		cin >> n;
		for (int a = 0; a < n; a++) {
			cin >> input;
			rotate(cube, input);
		}

		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				cout << cube[0][a][b];
			}
			cout << endl;
		}
	}

	return 0;
}
//함수 내부 코드는 길지만 별 내용없다. 그냥 회전 방식에 따라 큐브를 회전해주는 기능 뿐이다.
void rotate(char cube[6][3][3], char input[3]) {
	char temp[3];
	if (input[0] == 'U' && input[1] == '+') {
		temp[0] = cube[4][0][0]; temp[1] = cube[4][0][1]; temp[2] = cube[4][0][2];
		cube[4][0][0] = cube[3][0][0]; cube[4][0][1] = cube[3][0][1]; cube[4][0][2] = cube[3][0][2];
		cube[3][0][0] = cube[2][0][0]; cube[3][0][1] = cube[2][0][1]; cube[3][0][2] = cube[2][0][2];
		cube[2][0][0] = cube[1][0][0]; cube[2][0][1] = cube[1][0][1]; cube[2][0][2] = cube[1][0][2];
		cube[1][0][0] = temp[0]; cube[1][0][1] = temp[1]; cube[1][0][2] = temp[2];
		temp[0] = cube[0][0][0]; temp[1] = cube[0][0][1];
		cube[0][0][0] = cube[0][2][0]; cube[0][2][0] = cube[0][2][2]; cube[0][2][2] = cube[0][0][2]; cube[0][0][2] = temp[0];
		cube[0][0][1] = cube[0][1][0]; cube[0][1][0] = cube[0][2][1]; cube[0][2][1] = cube[0][1][2]; cube[0][1][2] = temp[1];
	}
	else if (input[0] == 'U' && input[1] == '-') {
		temp[0] = cube[1][0][0]; temp[1] = cube[1][0][1]; temp[2] = cube[1][0][2];
		cube[1][0][0] = cube[2][0][0]; cube[1][0][1] = cube[2][0][1]; cube[1][0][2] = cube[2][0][2];
		cube[2][0][0] = cube[3][0][0]; cube[2][0][1] = cube[3][0][1]; cube[2][0][2] = cube[3][0][2];
		cube[3][0][0] = cube[4][0][0]; cube[3][0][1] = cube[4][0][1]; cube[3][0][2] = cube[4][0][2];
		cube[4][0][0] = temp[0]; cube[4][0][1] = temp[1]; cube[4][0][2] = temp[2];
		temp[0] = cube[0][0][0]; temp[1] = cube[0][0][1];
		cube[0][0][0] = cube[0][0][2]; cube[0][0][2] = cube[0][2][2]; cube[0][2][2] = cube[0][2][0]; cube[0][2][0] = temp[0];
		cube[0][0][1] = cube[0][1][2]; cube[0][1][2] = cube[0][2][1]; cube[0][2][1] = cube[0][1][0]; cube[0][1][0] = temp[1];
	}
	else if (input[0] == 'D' && input[1] == '+') {
		temp[0] = cube[1][2][0]; temp[1] = cube[1][2][1]; temp[2] = cube[1][2][2];
		cube[1][2][0] = cube[2][2][0]; cube[1][2][1] = cube[2][2][1]; cube[1][2][2] = cube[2][2][2];
		cube[2][2][0] = cube[3][2][0]; cube[2][2][1] = cube[3][2][1]; cube[2][2][2] = cube[3][2][2];
		cube[3][2][0] = cube[4][2][0]; cube[3][2][1] = cube[4][2][1]; cube[3][2][2] = cube[4][2][2];
		cube[4][2][0] = temp[0]; cube[4][2][1] = temp[1]; cube[4][2][2] = temp[2];
		temp[0] = cube[5][0][0]; temp[1] = cube[5][0][1];
		cube[5][0][0] = cube[5][2][0]; cube[5][2][0] = cube[5][2][2]; cube[5][2][2] = cube[5][0][2]; cube[5][0][2] = temp[0];
		cube[5][0][1] = cube[5][1][0]; cube[5][1][0] = cube[5][2][1]; cube[5][2][1] = cube[5][1][2]; cube[5][1][2] = temp[1];
	}
	else if (input[0] == 'D' && input[1] == '-') {
		temp[0] = cube[4][2][0]; temp[1] = cube[4][2][1]; temp[2] = cube[4][2][2];
		cube[4][2][0] = cube[3][2][0]; cube[4][2][1] = cube[3][2][1]; cube[4][2][2] = cube[3][2][2];
		cube[3][2][0] = cube[2][2][0]; cube[3][2][1] = cube[2][2][1]; cube[3][2][2] = cube[2][2][2];
		cube[2][2][0] = cube[1][2][0]; cube[2][2][1] = cube[1][2][1]; cube[2][2][2] = cube[1][2][2];
		cube[1][2][0] = temp[0]; cube[1][2][1] = temp[1]; cube[1][2][2] = temp[2];
		temp[0] = cube[5][0][0]; temp[1] = cube[5][0][1];
		cube[5][0][0] = cube[5][0][2]; cube[5][0][2] = cube[5][2][2]; cube[5][2][2] = cube[5][2][0]; cube[5][2][0] = temp[0];
		cube[5][0][1] = cube[5][1][2]; cube[5][1][2] = cube[5][2][1]; cube[5][2][1] = cube[5][1][0]; cube[5][1][0] = temp[1];
	}
	else if (input[0] == 'F' && input[1] == '+') {
		temp[0] = cube[0][2][0]; temp[1] = cube[0][2][1]; temp[2] = cube[0][2][2];
		cube[0][2][0] = cube[3][2][2]; cube[0][2][1] = cube[3][1][2]; cube[0][2][2] = cube[3][0][2];
		cube[3][2][2] = cube[5][0][2]; cube[3][1][2] = cube[5][0][1]; cube[3][0][2] = cube[5][0][0];
		cube[5][0][2] = cube[1][0][0]; cube[5][0][1] = cube[1][1][0]; cube[5][0][0] = cube[1][2][0];
		cube[1][0][0] = temp[0]; cube[1][1][0] = temp[1]; cube[1][2][0] = temp[2];
		temp[0] = cube[2][0][0]; temp[1] = cube[2][0][1];
		cube[2][0][0] = cube[2][2][0]; cube[2][2][0] = cube[2][2][2]; cube[2][2][2] = cube[2][0][2]; cube[2][0][2] = temp[0];
		cube[2][0][1] = cube[2][1][0]; cube[2][1][0] = cube[2][2][1]; cube[2][2][1] = cube[2][1][2]; cube[2][1][2] = temp[1];
	}
	else if (input[0] == 'F' && input[1] == '-') {
		temp[0] = cube[3][2][2]; temp[1] = cube[3][1][2]; temp[2] = cube[3][0][2];
		cube[3][2][2] = cube[0][2][0]; cube[3][1][2] = cube[0][2][1]; cube[3][0][2] = cube[0][2][2];
		cube[0][2][0] = cube[1][0][0]; cube[0][2][1] = cube[1][1][0]; cube[0][2][2] = cube[1][2][0];
		cube[1][0][0] = cube[5][0][2]; cube[1][1][0] = cube[5][0][1]; cube[1][2][0] = cube[5][0][0];
		cube[5][0][2] = temp[0]; cube[5][0][1] = temp[1]; cube[5][0][0] = temp[2];
		temp[0] = cube[2][0][0]; temp[1] = cube[2][0][1];
		cube[2][0][0] = cube[2][0][2]; cube[2][0][2] = cube[2][2][2]; cube[2][2][2] = cube[2][2][0]; cube[2][2][0] = temp[0];
		cube[2][0][1] = cube[2][1][2]; cube[2][1][2] = cube[2][2][1]; cube[2][2][1] = cube[2][1][0]; cube[2][1][0] = temp[1];
	}
	else if (input[0] == 'B' && input[1] == '+') {
		temp[0] = cube[0][0][0]; temp[1] = cube[0][0][1]; temp[2] = cube[0][0][2];
		cube[0][0][0] = cube[1][0][2]; cube[0][0][1] = cube[1][1][2]; cube[0][0][2] = cube[1][2][2];
		cube[1][0][2] = cube[5][2][2]; cube[1][1][2] = cube[5][2][1]; cube[1][2][2] = cube[5][2][0];
		cube[5][2][2] = cube[3][2][0]; cube[5][2][1] = cube[3][1][0]; cube[5][2][0] = cube[3][0][0];
		cube[3][2][0] = temp[0]; cube[3][1][0] = temp[1]; cube[3][0][0] = temp[2];
		temp[0] = cube[4][0][0]; temp[1] = cube[4][0][1];
		cube[4][0][0] = cube[4][2][0]; cube[4][2][0] = cube[4][2][2]; cube[4][2][2] = cube[4][0][2]; cube[4][0][2] = temp[0];
		cube[4][0][1] = cube[4][1][0]; cube[4][1][0] = cube[4][2][1]; cube[4][2][1] = cube[4][1][2]; cube[4][1][2] = temp[1];
	}
	else if (input[0] == 'B' && input[1] == '-') {
		temp[0] = cube[0][0][0]; temp[1] = cube[0][0][1]; temp[2] = cube[0][0][2];
		cube[0][0][0] = cube[3][2][0]; cube[0][0][1] = cube[3][1][0]; cube[0][0][2] = cube[3][0][0];
		cube[3][2][0] = cube[5][2][2]; cube[3][1][0] = cube[5][2][1]; cube[3][0][0] = cube[5][2][0];
		cube[5][2][2] = cube[1][0][2]; cube[5][2][1] = cube[1][1][2]; cube[5][2][0] = cube[1][2][2];
		cube[1][0][2] = temp[0]; cube[1][1][2] = temp[1]; cube[1][2][2] = temp[2];
		temp[0] = cube[4][0][0]; temp[1] = cube[4][0][1];
		cube[4][0][0] = cube[4][0][2]; cube[4][0][2] = cube[4][2][2]; cube[4][2][2] = cube[4][2][0]; cube[4][2][0] = temp[0];
		cube[4][0][1] = cube[4][1][2]; cube[4][1][2] = cube[4][2][1]; cube[4][2][1] = cube[4][1][0]; cube[4][1][0] = temp[1];
	}
	else if (input[0] == 'L' && input[1] == '+') {
		temp[0] = cube[0][0][0]; temp[1] = cube[0][1][0]; temp[2] = cube[0][2][0];
		cube[0][0][0] = cube[4][2][2]; cube[0][1][0] = cube[4][1][2]; cube[0][2][0] = cube[4][0][2];
		cube[4][2][2] = cube[5][0][0]; cube[4][1][2] = cube[5][1][0]; cube[4][0][2] = cube[5][2][0];
		cube[5][0][0] = cube[2][0][0]; cube[5][1][0] = cube[2][1][0]; cube[5][2][0] = cube[2][2][0];
		cube[2][0][0] = temp[0]; cube[2][1][0] = temp[1]; cube[2][2][0] = temp[2];
		temp[0] = cube[3][0][0]; temp[1] = cube[3][0][1];
		cube[3][0][0] = cube[3][2][0]; cube[3][2][0] = cube[3][2][2]; cube[3][2][2] = cube[3][0][2]; cube[3][0][2] = temp[0];
		cube[3][0][1] = cube[3][1][0]; cube[3][1][0] = cube[3][2][1]; cube[3][2][1] = cube[3][1][2]; cube[3][1][2] = temp[1];
	}
	else if (input[0] == 'L' && input[1] == '-') {
		temp[0] = cube[0][0][0]; temp[1] = cube[0][1][0]; temp[2] = cube[0][2][0];
		cube[0][0][0] = cube[2][0][0]; cube[0][1][0] = cube[2][1][0]; cube[0][2][0] = cube[2][2][0];
		cube[2][0][0] = cube[5][0][0]; cube[2][1][0] = cube[5][1][0]; cube[2][2][0] = cube[5][2][0];
		cube[5][0][0] = cube[4][2][2]; cube[5][1][0] = cube[4][1][2]; cube[5][2][0] = cube[4][0][2];
		cube[4][2][2] = temp[0]; cube[4][1][2] = temp[1]; cube[4][0][2] = temp[2];
		temp[0] = cube[3][0][0]; temp[1] = cube[3][0][1];
		cube[3][0][0] = cube[3][0][2]; cube[3][0][2] = cube[3][2][2]; cube[3][2][2] = cube[3][2][0]; cube[3][2][0] = temp[0];
		cube[3][0][1] = cube[3][1][2]; cube[3][1][2] = cube[3][2][1]; cube[3][2][1] = cube[3][1][0]; cube[3][1][0] = temp[1];
	}
	else if (input[0] == 'R' && input[1] == '+') {
		temp[0] = cube[0][2][2]; temp[1] = cube[0][1][2]; temp[2] = cube[0][0][2];
		cube[0][2][2] = cube[2][2][2]; cube[0][1][2] = cube[2][1][2]; cube[0][0][2] = cube[2][0][2];
		cube[2][2][2] = cube[5][2][2]; cube[2][1][2] = cube[5][1][2]; cube[2][0][2] = cube[5][0][2];
		cube[5][2][2] = cube[4][0][0]; cube[5][1][2] = cube[4][1][0]; cube[5][0][2] = cube[4][2][0];
		cube[4][0][0] = temp[0]; cube[4][1][0] = temp[1]; cube[4][2][0] = temp[2];
		temp[0] = cube[1][0][0]; temp[1] = cube[1][0][1];
		cube[1][0][0] = cube[1][2][0]; cube[1][2][0] = cube[1][2][2]; cube[1][2][2] = cube[1][0][2]; cube[1][0][2] = temp[0];
		cube[1][0][1] = cube[1][1][0]; cube[1][1][0] = cube[1][2][1]; cube[1][2][1] = cube[1][1][2]; cube[1][1][2] = temp[1];
	}
	else if (input[0] == 'R' && input[1] == '-') {
		temp[0] = cube[0][2][2]; temp[1] = cube[0][1][2]; temp[2] = cube[0][0][2];
		cube[0][2][2] = cube[4][0][0]; cube[0][1][2] = cube[4][1][0]; cube[0][0][2] = cube[4][2][0];
		cube[4][0][0] = cube[5][2][2]; cube[4][1][0] = cube[5][1][2]; cube[4][2][0] = cube[5][0][2];
		cube[5][2][2] = cube[2][2][2]; cube[5][1][2] = cube[2][1][2]; cube[5][0][2] = cube[2][0][2];
		cube[2][2][2] = temp[0]; cube[2][1][2] = temp[1]; cube[2][0][2] = temp[2];
		temp[0] = cube[1][0][0]; temp[1] = cube[1][0][1];
		cube[1][0][0] = cube[1][0][2]; cube[1][0][2] = cube[1][2][2]; cube[1][2][2] = cube[1][2][0]; cube[1][2][0] = temp[0];
		cube[1][0][1] = cube[1][1][2]; cube[1][1][2] = cube[1][2][1]; cube[1][2][1] = cube[1][1][0]; cube[1][1][0] = temp[1];
	}
	else {
		cout << "Invalid Input" << endl;
	}
}