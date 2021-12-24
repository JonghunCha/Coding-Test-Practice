/*
문제 링크 : https://www.acmicpc.net/problem/17136
주어진 문제 조건을 얼마나 잘 이해하고 구현하냐가 중요한 문제다.
문제에서 요구한 사항들을 구현하는 것은 크게 어렵지 않다. 그러나 무한 루프에 대해 정확히 이해하지 못한다면 문제의 뜻을 헷갈리기 쉽다.
조건을 보면 명령어를 50,000,000번 이상 수행한 경우 프로그램이 항상 종료되었거나 무한 루프에 빠진다고 하였으며,
한 번의 무한 루프에서 실행되는 명령어의 개수는 50,000,000개 이하라고 한다.

즉, 무한 루프에 빠졌는지 안 빠졌는지 판단하기 위해선 최소 50,000,000번의 명령어 수행부터 100,000,000번의 명령어 수행까지 어떠한 루프들을 거쳤는지 확인하면 된다.
또한, 50,000,000~100,000,000사이에서도 여러 개의 루프를 거칠 수 있다. 그렇다면 어떤 루프가 무한 루프라고 할 수 있을까?
무한 루프는 해당 루프를 빠져 나오지 못한다는 의미이기에 가장 바깥쪽의 루프가 무한 루프인 것이다.(안쪽의 루프를 빠져나왔기에 바깥쪽의 루프가 실행된다)

위와 같은 사항들을 고려하면 나머지는 구현뿐이기에 어렵지 않게 풀 수 있다.
*/
#include <iostream>
#include <string>
using namespace std;

void Get_Answer(int M, int C, int I, unsigned char* arr, string program, string input_str);

int main(void) {
	int t, M, C, I;
	unsigned char* arr;
	string program, input_str;
	//입력값 저장
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> M; cin >> C; cin >> I;
		arr = new unsigned char[M];
		if (arr == NULL)	cout << "dynamic allocation fail" << endl;
		for (int j = 0; j < M; j++)	arr[j] = 0;
		cin >> program; cin >> input_str;

		Get_Answer(M, C, I, arr, program, input_str);
		delete []arr;
	}

	return 0;
}

void Get_Answer(int M, int C, int I, unsigned char* arr, string program, string input_str) {
	int loop_num = 0, loop_index = 0;	//각각 루프의 개수, 루프 짝을 구할 때 사용되는 변수를 의미
	int** loop_start_end_index;			//루프의 짝을 구한 뒤 해당 루프가 프로그램 코드에서 어떤 위치에 있는지를 저장
	//ptr은 메모리상의 현재 위치, index는 프로그램 코드상의 현재 위치, count는 명령어의 실행 횟수, str_index는 입력 문자열상의 현재 위치를 의미
	//outer_loop는 무한 루프를 판별할 때, 가장 바깥쪽 루프를 업데이트 하는데 쓰임. last는 가장 바깥쪽의 루프임을 검증하는데 쓰임)
	int ptr = 0, index = 0, count = 0, str_index = 0, outer_loop = -1, last = 0;
	
	//프로그램에 loop가 몇 개인지 계산
	for (int i = 0; i < program.length(); i++) {
		if (program[i] == '[')	loop_num++;
	}
	//루프의 짝 위치에 대한 정보를 담을 수 있는 2차원 배열 동적 할당
	loop_start_end_index = new int* [loop_num];
	if (loop_start_end_index == NULL)	cout << "dynamic allocation fail" << endl;
	for (int i = 0; i < loop_num; i++) {
		loop_start_end_index[i] = new int[2];
		if (loop_start_end_index[i] == NULL)	cout << "dynamic allocation fail" << endl;
	}
	//루프의 짝을 구한다
	for (int i = 0; i < loop_num; i++) {
		loop_start_end_index[i][0] = -1;
		loop_start_end_index[i][1] = -1;
	}
	for (int i = 0; i < program.length(); i++) {
		if (program[i] == '[') {
			loop_start_end_index[loop_index][0] = i;
			loop_index++;
		}
		else if (program[i] == ']') {
			for (int j = loop_index - 1; j >= 0; j--) {
				if (loop_start_end_index[j][1] == -1) {
					loop_start_end_index[j][1] = i;
					break;
				}
			}
		}
	}
	//프로그램 실행
	while (1) {
		//index가 프로그램 코드 마지막 다음을 가르키는건 프로그램이 끝났음을 의미
		if (index == C) {
			cout << "Terminates" << endl;
			return;
		}
		//100,000,000번의 명령어를 수행하면 무한 루프가 적어도 1번의 루프는 지났다는 의미
		else if (count >= 100000000) {
			cout << "Loops " << loop_start_end_index[outer_loop][0] << ' ' << loop_start_end_index[outer_loop][1] << endl;
			return;
		}
		else {
			if (program[index] == '-') {
				arr[ptr]--;
				index++;
			}
			else if (program[index] == '+') {
				arr[ptr]++;
				index++;
			}
			else if (program[index] == '<') {
				if (ptr != 0)	ptr--;
				else	ptr = M - 1;
				index++;
			}
			else if (program[index] == '>') {
				if (ptr != M - 1)	ptr++;
				else	ptr = 0;
				index++;
			}
			else if (program[index] == '[') {
				if (arr[ptr] == 0) {
					for (int i = 0; i < loop_num; i++) {
						if (loop_start_end_index[i][0] == index) {
							index = loop_start_end_index[i][1] + 1;
							break;
						}
					}
				}
				else	index++;
			}
			else if (program[index] == ']') {
				if (arr[ptr] != 0) {
					for (int i = 0; i < loop_num; i++) {
						if (loop_start_end_index[i][1] == index) {
							//50,000,000이상인 경우 무한 루프에 빠졌을 것이고, index가 last보다 크다면 이번 루프가 현재까지 가장 바깥쪽 루프임을 의미
							if (count >= 50000000 && index > last) {
								outer_loop = i;
								last = index;
							}
							index = loop_start_end_index[i][0] + 1;
							break;
						}
					}
				}
				else	index++;
			}
			else if(program[index] == '.'){
				index++;
			}
			else {
				if (str_index == input_str.length())	arr[ptr] = 255;
				else	arr[ptr] = input_str[str_index++];
				index++;
			}
			count++;
		}
	}
}