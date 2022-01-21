/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�ܼ��� ���� Ž�� ������.

board�� ���¸� ������ Ȯ���ϰ� ���¿� �´� ����� ���ָ� �ȴ�.
*/
#include <cstdio>

using namespace std;

bool is_A_won(char board[4][4], char A);
bool is_draw(char board[4][4]);

int main(int argc, char** argv)
{
	int T;
	char board[4][4];
	
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ����
		getchar();
		for (int a = 0; a < 4; a++) {
			for (int b = 0; b < 4; b++) {
				scanf("%c", &board[a][b]);
			}
			getchar();
		}
		//�� ���̽��� ���� ���
		if (is_A_won(board, 'X')) {
			printf("#%d X won\n", test_case);
		}
		else if (is_A_won(board, 'O')) {
			printf("#%d O won\n", test_case);
		}
		else if (is_draw(board)) {
			printf("#%d Draw\n", test_case);
		}
		else {
			printf("#%d Game has not completed\n", test_case);
		}
	}
	return 0;
}
//���� board�� ���°� A�� �̱� ������ Ȯ��
bool is_A_won(char board[4][4], char A) {
	bool is_end;
	//���η� �����ؼ� AȤ�� 'T'�θ� �̷�� ������ Ȯ��
	for (int a = 0; a < 4; a++) {
		is_end = true;
		for (int b = 0; b < 4; b++) {
			if (board[a][b] != A && board[a][b] != 'T') {
				is_end = false;
				break;
			}
		}
		if (is_end)		return true;
	}
	//���η� �����ؼ� AȤ�� 'T'�θ� �̷�� ������ Ȯ��
	for (int a = 0; a < 4; a++) {
		is_end = true;
		for (int b = 0; b < 4; b++) {
			if (board[b][a] != A && board[b][a] != 'T') {
				is_end = false;
				break;
			}
		}
		if (is_end)		return true;
	}
	//������ �Ʒ��� ���ϴ� �밢������ �����ؼ� AȤ�� 'T'�θ� �̷�� ������ Ȯ��
	is_end = true;
	for (int a = 0; a < 4; a++) {
		if (board[a][a] != A && board[a][a] != 'T') {
			is_end = false;
			break;
		}
	}
	if (is_end)	return true;
	//������ ���� ���ϴ� �밢������ �����ؼ� AȤ�� 'T'�θ� �̷�� ������ Ȯ��
	is_end = true;
	for (int a = 0; a < 4; a++) {
		if (board[a][3 - a] != A && board[a][3 - a] != 'T') {
			is_end = false;
			break;
		}
	}
	if (is_end)	return true;

	return false;
}
//X�� O�� ��� �������� Ȯ��
bool is_draw(char board[4][4]) {
	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 4; b++) {
			if (board[a][b] == '.') {
				return false;
			}
		}
	}

	return true;
}