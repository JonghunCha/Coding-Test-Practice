/*
���� ��ũ : https://swexpertacademy.com/main/main.do
valid_camera_num�̶� ������ �ξ� ���� ��ġ�� �ִ� ī�޶�� �ϳ��� ���� ������ ���� �ٸ� ��ġ�� �ִ� ī�޶��� ���� �����Ͽ���.

���� valid_camera_num�� ���ű��� ������ K���� ���ų� �۴ٸ� �� ī�޶󸶴� ���ű⸦ �� �� ������ ���� ���� ������ 0�̴�.

�׷��� ���ű��� ������ valid_camera_num���� �۴ٸ� ���� ���� ������ 0�̻��� �ȴ�.

���� ���ű��� ������ valid_camera_num���� 1�� �۴ٰ� ��������.

�׷��ٸ� �ϳ��� ī�޶�� �ٸ� ī�޶� �ִ� ���ű�� ������ �Ǿ�� �ϸ�, �� ��� ī�޶� ������ �Ÿ��� ���� ª�� ������ ���ű��� ���� ���� ������ �ø��� ���� ��ü ���� ���� ������ ���� �ּҰ� �ȴ�.

��, ���ű��� ������ ���� �ٸ� ��ġ�� �����ϴ� ī�޶��� ������ n�� �����ϴٸ�, �� ī�޶� ������ �Ÿ��� ª�� ������� n���� ������ ���� ���� �������� ����� �ָ� ��� ī�޶� ���ű�� ������ �ȴ�.

�̸� ������ ���� �Ʒ� �ڵ��̴�.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int dp(vector<int>& cameras, int valid_camera_num, int receive_num, int start);

int main(int argc, char** argv)
{
	int T, N, K, input[10000], distances[10000], valid_camera_num, answer;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ī�޶� ��ġ ������������ ����
		scanf("%d %d", &N, &K);
		for (int a = 0; a < N; a++)	scanf("%d", &input[a]);
		sort(input, input + N);
		//���� �ٸ� ��ġ�� �����ϴ� ī�޶��� ���� ����ϸ� ���ÿ� ī�޶� ���� ���� ���
		valid_camera_num = 1;
		for (int a = 1; a < N; a++) {
			if (input[a] == input[a - 1])	continue;
			else {
				distances[valid_camera_num - 1] = input[a] - input[a - 1];
				valid_camera_num++;
			}
		}
		//ī�޶� ���� ������ ������������ ����
		sort(distances, distances + valid_camera_num - 1);
		//ī�޶� ���� ������ ª�� ������ (valid_camera_num - K)���� ������ ���� ���� �������� �����
		answer = 0;
		for (int a = 0; a < valid_camera_num - K; a++)	answer += distances[a];
		printf("#%d %d\n", test_case, answer);
	}


	return 0;
} 