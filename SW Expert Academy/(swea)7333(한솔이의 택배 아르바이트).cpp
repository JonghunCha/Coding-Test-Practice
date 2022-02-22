/*
���� ��ũ : https://swexpertacademy.com/main/main.do
�� �����ͷ� �ذ��� �� �ִ� ������.

�켱 �ڽ����� ������������ �����Ѵ�.

�׷� ���� ������ �ϳ��� ���� ������ �ڽ�, �ٸ� �ϳ��� ���� ���ſ� �ڽ��� ����Ű���� �Ѵ�.

����ϴ� Ƚ���� �ִ�� �ϱ� ���ؼ� �� ���� ����ϴ� �ڽ��� ���� ������ ����� �Ѵ�.

���� ���� ���ſ� �ڽ� �ϳ��� ����, �ش� �ڽ��� ���� ���� �� �� ������ ���Ը� 50�̻��̶�� �����ϵ��� ���� ������ �ڽ��� ä�� �ִ� �۾��� ��� �ڽ��� �ű� ������ �ݺ��ϸ� �ȴ�.

�Ʒ� �ڵ带 ���� ���ذ� ���� ���̴�.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int T, N, box, ptr1, ptr2, answer, box_needed;
	vector<int> boxes;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ����
		scanf("%d", &N);
		boxes.clear();
		for (int a = 0; a < N; a++) {
			scanf("%d", &box);
			boxes.push_back(box);
		}
		sort(boxes.begin(), boxes.end());
		//������ �� ���� ���� ����, �����ʿ� �д�
		ptr1 = 0;
		ptr2 = N - 1;
		answer = 0;
		while (ptr1 <= ptr2) {
			//���� �ڽ���� 50kg�� ���� �� ���� ����, ������ ������ ��� ���տ� ���Խ��Ѿ� ��
			if (boxes[ptr2] * (ptr2 - ptr1 + 1) < 50)	break;

			if (boxes[ptr2] >= 50) {	//���� ���� ���ſ� �ڽ��� 50kg�̻��� ��� �ش� �ڽ��� ���
				answer++;
				ptr2--;
			}
			else {	//���� ���ſ� �ڽ��� �� ���� �� �� �� ���� �ڽ��� �־�� �ϴ��� ��� + ������ �ڽ��� ������ �����ֱ�
				box_needed = 2;
				while (1) {
					if (boxes[ptr2] * box_needed >= 50)	break;
					box_needed++;
				}

				answer++;
				ptr2--;
				ptr1 += box_needed - 1;
			}
		}

		printf("#%d %d\n", test_case, answer);
	}
	return 0;
}