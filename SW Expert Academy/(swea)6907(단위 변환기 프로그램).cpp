/*
문제 링크 : https://swexpertacademy.com/main/main.do
문자열 파싱을 이용한 단순 구현 문제다.

유효숫자와 관련된 룰은 문제에서 제공을 해주고 우리가 해야할 건 입력을 문제에서 주어진 유효숫자 룰에 맞게끔 변환을 하는 것이다.

어려운 개념이나 알고리즘이 필요한 문제는 아니라 별다른 설명은 하지 않겠다.
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
	//각 접두사가 10의 몇 승인지를 map에 저장
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
		//입력의 수, 접두사, 유닛을 저장(접두사는 없는 경우도 있기에 해당 경우를 체크 해야 함)
		scanf("%s", num);
		scanf("%s", prefix);
		if (prefix_val.find(prefix) == prefix_val.end()) {
			strcpy(unit, prefix);
			strcpy(prefix, "nothing");
		}
		else {
			scanf("%s", unit);
		}
		//유효숫자만 남겨 answer_num에 새롭게 저장
		answer_num_index = 0;
		valid_num = false;
		dot_included = false;
		for (int a = 0; a < strlen(num); a++) {
			if (valid_num == false && num[a] != '.' && num[a] > '0') {	//처음으로 0이 아닌 수가 들어온 경우(첫 유효숫자)
				valid_num = true;
				answer_num[answer_num_index++] = num[a];
			 }
			else if (valid_num == true && num[a] != '.' && dot_included == false) {	//또 다른 유효숫자가 들어왔는데 아직 소수점이 포함되지 않은 경우(소수점을 넣어준다)
				dot_included = true;
				answer_num[answer_num_index++] = '.';
				answer_num[answer_num_index++] = num[a];
			}
			else if (valid_num == true && num[a] != '.' && dot_included == true) {	//이외의 경우
				answer_num[answer_num_index++] = num[a];
			}
		}
		answer_num[answer_num_index] = 0;
		//새롭게 변환한 answer_num과 기존의 num 사이의 소수점 자리 비교
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
		//최종 출력의 값이 10의 몇 승인지 계산
		times = prefix_val[prefix] + dot_index - new_dot_index;

		printf("#%d %s * 10^%d %s\n", test_case, answer_num, times, unit);
	}
	return 0;
}