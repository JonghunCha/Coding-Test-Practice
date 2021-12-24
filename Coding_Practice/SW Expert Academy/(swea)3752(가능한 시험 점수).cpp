/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�ߺ��� ����� ����Ž������ �ذ��� �� �ִ�.

�켱 �ִ� 100���� �����̰� �� ������ �ִ� 100�� ¥���̴�.

���� �ִ� ������ 10000���̰� �̴� �迭�� ����� �ߺ� ���Ÿ� �� �� ������ �ǹ��Ѵ�.

�ڵ忡�� bool�ڷ��� 10001ũ���� �迭�� �� ������ �����ϴٸ� true, �Ұ��� �ϴٸ� false�� �����Ѵ�.

���� �� ������ ���Ǹ� ������ ���� ������ ���� ������ ���� ���� �̹� ���� ���̶�� ����, ���ο� ���̶�� ť�� �����ص״� �ϰ������� bool�迭�� �����ϴ� ������ �����ϸ� �ȴ�.
*/
#include <cstdio>
#include <queue>
using namespace std;

bool visited[10001];
queue<int> __queue;

int main(int argc, char** argv)
{
	int T, N, score[100], temp, max_score, answer;

	visited[0] = true;	//0���� �׻� ����
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ���� �ʱ�ȭ
		scanf("%d", &N);
		for (int a = 0; a < N; a++)	scanf("%d", &score[a]);
		for (int a = 1; a <= 10000; a++)	visited[a] = false;
		//max_score�� ��������� �ִ� ������ �ǹ��ϸ�, 0���� �׻� �����ϱ⿡ answer�� 1���� ����
		max_score = 0;
		answer = 1;
		for (int a = 0; a < N; a++) {	//��� ������ ����
			for (int b = 0; b <= max_score; b++) {	//��������� �ִ� �������� ���ɴ�
				//���� ������� b������ ���� �� ������ b + score[a]�� ���� ������ ���� ������ ��
				if (visited[b] == true && b + score[a] <= 10000 && visited[b + score[a]] == false) {	
					__queue.push(b + score[a]);
				}
			}
			//���Ӱ� �߰��� ������ �ݿ�
			while (!__queue.empty()) {
				if (__queue.front() > max_score)	max_score = __queue.front();	//max_score ����ؼ� ����
				visited[__queue.front()] = true;	//���ο� ���� true�� ����
				answer++;
				__queue.pop();
			}
		}

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}