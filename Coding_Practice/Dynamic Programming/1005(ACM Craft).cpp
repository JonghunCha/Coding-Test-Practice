/*
���� ��ũ : https://www.acmicpc.net/problem/1005
Dynamic Programming�� �̿��Ͽ� �ذ��� �� �ִ� ������.

�켱 target�ǹ��� ���� ���ؼ� ������ϴ� �ǹ����� �����Ѵ�.

�ش� �ǹ��� �� ���� �ʰ� �ϼ��Ǵ� �ǹ��� ���µ� �ɸ��� �ð� + target�ǹ��� ���µ� �ɸ��� �ð��� ���䰪�̴�.
*/
#include <iostream>
using namespace std;

int D[1001], build[1001][1001], dp[1001];

int DP(int N, int num);

int main(void) {
	int T, N, K, x, y, target, temp;

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		//�Է°� ���� �� ���� �ʱ�ȭ
		cin >> N >> K;
		for (int a = 1; a <= N; a++) {	//�ǹ� ���� ������ �����ϴ� build �ʱ�ȭ
			for (int b = 1; b <= N; b++) {
				build[a][b] = 0;
			}
		}
		for (int a = 1; a <= N; a++)	dp[a] = -1;	//a��° �ǹ��� ���µ� �ɸ��� �ּҽð��� �����ϴ� dp �ʱ�ȭ
		for (int a = 1; a <= N; a++)	cin >> D[a];	//�� �ǹ��� ���µ� �ɸ��� �ð� �Է� ����
		for (int a = 1; a <= K; a++) {	//build�Է� ����
			cin >> x >> y;
			build[y][x] = 1;
		}
		cin >> target;	//Ÿ�� �ǹ� �Է� ����

		DP(N, target);
		cout << dp[target] << endl;
	}
	return 0;
}

int DP(int N, int num) {
	if (dp[num] != -1)	return dp[num];

	int ret = D[num], temp;
	for (int a = 1; a <= N; a++) {	//num�� ���� ���ؼ� ������ϴ� �ǹ� �� ���� �ʰ� �������� �ǹ� + D[num]�� num�� ���µ� �ɸ��� �ּ� �ð�
		if (build[num][a] == 1) {
			temp = D[num] + DP(N, a);
			if (temp > ret)	ret = temp;
		}
	}
	dp[num] = ret;
	return ret;
}