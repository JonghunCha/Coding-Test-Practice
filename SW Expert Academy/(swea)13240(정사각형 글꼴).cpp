/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���� Ž������ �ذ��� �� �ִ� ������.

�켱 ������ �۲��� �ִ� ũ��� (W / ���� �� �ܾ��� ����)�̴�.

�� ���� �̿��Ͽ� �۲��� �ִ� ũ����� 1���� ���簡�� ������ ������ �����ϴ� ���� ū �۲��� ũ�⸦ ã���� �ȴ�.

�� ��, �ܾ�� ���� row�� �߰��� �� �ִٸ� ������ �߰��ϴ� ���� ��ü row�� ���� �۰� ����� ����̴�.
*/
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
	int T, H, W, N;
	char input_str[1001];
	vector<string> inputs;
	string temp;
	
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ����
		scanf("%d %d %d", &H, &W, &N);
		getchar();
		scanf("%[^\n]s", input_str);
		//�Է¹��� ���ڿ��� �� �ܾ�� ������ inputs�� ����
		temp.clear();
		inputs.clear();
		for (int a = 0; a < strlen(input_str); a++) {
			if (input_str[a] == ' ') {
				inputs.push_back(temp);
				temp.clear();
			}
			else {
				temp.push_back(input_str[a]);
			}
		}
		inputs.push_back(temp);
		//���� �� �ܾ��� ���� ���
		int longest_len = 0;

		for (int a = 0; a < inputs.size(); a++) {
			if (inputs[a].size() > longest_len) {
				longest_len = inputs[a].size();
			}
		}
		//���� �� �ܾ �������� ������ �ִ��� �۲� ũ����� 1�� ���߾�� ������ ������ �����ϴ� �۲��� ũ�⸦ ã�´�
		int max_row, max_col, row_num, col_num, max_word_size;
		bool ispossible = false;

		max_word_size = W / longest_len;
		for (int a = max_word_size; a >= 1; a--) {
			max_row = H / a;
			max_col = W / a;
			row_num = 1;
			col_num = 0;
			for (int b = 0; b < inputs.size(); b++) {
				if (col_num + inputs[b].size() > max_col) {	//b��° �ܾ �߰��ϸ� max_col�� �Ѿ�� ��� ���� row�� �̵�
					row_num++;
					col_num = inputs[b].size() + 1;
				}
				else {	//b��° �ܾ �߰��ص� �Ǵ� ���
					col_num += inputs[b].size() + 1;
				}
			}
			//���� ����� row���� ��밡���� max_row���� �۰ų� ���ٸ� ������ ������ ����
			if (row_num <= max_row) {
				printf("#%d %d\n", test_case, a);
				ispossible = true;
				break;
			}
		}

		if (!ispossible) {
			printf("#%d 0\n", test_case);
		}
	}
	return 0;
}