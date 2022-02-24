/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���ڿ� �Ľ��� �̿��� �ܼ� ���� ������.

��ȿ���ڿ� ���õ� ���� �������� ������ ���ְ� �츮�� �ؾ��� �� �Է��� �������� �־��� ��ȿ���� �꿡 �°Բ� ��ȯ�� �ϴ� ���̴�.

����� �����̳� �˰����� �ʿ��� ������ �ƴ϶� ���ٸ� ������ ���� �ʰڴ�.
*/
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
	int T, answer_num_index, dot_index, new_dot_index, times;
	char num[1010], prefix[10], unit[10];
	char answer_num[1010];
	bool valid_num, dot_included;
	map<string, int> prefix_val;
	//�� ���λ簡 10�� �� �������� map�� ����
	prefix_val["yotta"] = 24;
	prefix_val["zetta"] = 21;
	prefix_val["exa"] = 18;
	prefix_val["peta"] = 15;
	prefix_val["tera"] = 12;
	prefix_val["giga"] = 9;
	prefix_val["mega"] = 6;
	prefix_val["kilo"] = 3;
	prefix_val["hecto"] = 2;
	prefix_val["deca"] = 1;
	prefix_val["deci"] = -1;
	prefix_val["centi"] = -2;
	prefix_val["milli"] = -3;
	prefix_val["micro"] = -6;
	prefix_val["nano"] = -9;
	prefix_val["pico"] = -12;
	prefix_val["femto"] = -15;
	prefix_val["ato"] = -18;
	prefix_val["zepto"] = -21;
	prefix_val["yocto"] = -24;
	prefix_val["nothing"] = 0;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է��� ��, ���λ�, ������ ����(���λ�� ���� ��쵵 �ֱ⿡ �ش� ��츦 üũ �ؾ� ��)
		scanf("%s", num);
		scanf("%s", prefix);
		if (prefix_val.find(prefix) == prefix_val.end()) {
			strcpy(unit, prefix);
			strcpy(prefix, "nothing");
		}
		else {
			scanf("%s", unit);
		}
		//��ȿ���ڸ� ���� answer_num�� ���Ӱ� ����
		answer_num_index = 0;
		valid_num = false;
		dot_included = false;
		for (int a = 0; a < strlen(num); a++) {
			if (valid_num == false && num[a] != '.' && num[a] > '0') {	//ó������ 0�� �ƴ� ���� ���� ���(ù ��ȿ����)
				valid_num = true;
				answer_num[answer_num_index++] = num[a];
			 }
			else if (valid_num == true && num[a] != '.' && dot_included == false) {	//�� �ٸ� ��ȿ���ڰ� ���Դµ� ���� �Ҽ����� ���Ե��� ���� ���(�Ҽ����� �־��ش�)
				dot_included = true;
				answer_num[answer_num_index++] = '.';
				answer_num[answer_num_index++] = num[a];
			}
			else if (valid_num == true && num[a] != '.' && dot_included == true) {	//�̿��� ���
				answer_num[answer_num_index++] = num[a];
			}
		}
		answer_num[answer_num_index] = 0;
		//���Ӱ� ��ȯ�� answer_num�� ������ num ������ �Ҽ��� �ڸ� ��
		dot_index = strlen(num) - 1;
		new_dot_index = -1;
		dot_included = false;
		for (int a = 0; a < strlen(num); a++) {
			if (num[a] == '.') {
				dot_index = a - 1;
				dot_included = true;
			}
			else if (num[a] != '.' && num[a] > '0' && new_dot_index == -1) {
				if (dot_included)	new_dot_index = a - 1;
				else	new_dot_index = a;
			}
		}
		//���� ����� ���� 10�� �� ������ ���
		times = prefix_val[prefix] + dot_index - new_dot_index;

		printf("#%d %s * 10^%d %s\n", test_case, answer_num, times, unit);
	}
	return 0;
}