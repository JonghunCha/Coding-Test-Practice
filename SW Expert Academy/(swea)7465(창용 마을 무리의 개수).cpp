/*
문제 링크 : https://swexpertacademy.com/main/main.do
DFS를 이용하여 해결할 수 있는 문제다.

우선 그룹이 지정되지 않은 사람을 찾고 해당 사람을 새로운 무리에 넣고 연결된 모든 사람을 해당 무리에 집어 넣는다.

위 과정을 모든 사람이 어느 무리에 속하도록 반복하면 된다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

void search_near(int group[101], int group_num, bool know_each_other[101][101], int N, int index);

int main(int argc, char** argv)
{
	int T, N, M, num1, num2, group[101], group_num;
	bool know_each_other[101][101];

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 변수 초기화
		group_num = 0;
		memset(group, 0, sizeof(int) * 101);
		memset(know_each_other, false, sizeof(bool) * 101 * 101);
		scanf("%d %d", &N, &M);
		for (int a = 0; a < M; a++) {
			scanf("%d %d", &num1, &num2);
			know_each_other[num1][num2] = true;
			know_each_other[num2][num1] = true;
		}
		//모든 사람이 무리에 속할 때까지 새로운 무리 만들고 연결된 사람 집어넣기
		for (int a = 1; a <= N; a++) {
			if (group[a] == 0) {
				group[a] = ++group_num;
				search_near(group, group_num, know_each_other, N, a);
			}
		}

		printf("#%d %d\n", test_case, group_num);
	}
	return 0;
}
//index번째 사람과 연결된 모든 사람들을 group_num에 해당하는 무리에 소속시킨다
void search_near(int group[101], int group_num, bool know_each_other[101][101], int N, int index) {
	for (int a = 1; a <= N; a++) {
		if (group[a] == 0 && know_each_other[index][a] == true) {
			group[a] = group_num;
			search_near(group, group_num, know_each_other, N, a);
		}
	}
}