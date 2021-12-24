/*
���� ��ũ : https://www.acmicpc.net/problem/10875
���� �����̴�.

�������� ũ�Ⱑ �ִ� 2*10^8 + 1�̱� ������ ���� �̵��� ������ ���� ��ŷ�ϴ� ���� �޸� ���ѿ� �ɸ���.

���� �� �̵��� start��ǥ�� end��ǥ�� �̿��Ͽ� ���� �̵��� ���� �Ǵ��� �� �ֵ��� �Ͽ���.

i��° �̵��� ������ ���� �̵��� ��ο� ������ ������ �ְų� ������ �ۿ� ������ �����ϵ��� �����Ͽ���.
*/
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int L, N;

int main(void) {
	long long answer = 0, min;
	int direction = 0;	//direction 0 -> ������, 1 -> �Ʒ���, 2 -> ����, 3 -> ����
	long long rotate[1001], x1 = 0, y1 = 0, x2, y2;
	char dir[1001];
	vector<tuple<int, int, int, int>> vec;	//i��° �̵��� ���۰� �� ��ǥ�� ����
	//�Է°� ����
	cin >> L;
	cin >> N;
	for (int a = 0; a < N; a++) {
		cin >> rotate[a];
		cin >> dir[a];
	}
	//������ �۵� ���� �̵��� �������� ���
	vec.push_back(make_tuple(-L - 1, L + 1, L + 1, L + 1));
	vec.push_back(make_tuple(L + 1, -L - 1, L + 1, L + 1));
	vec.push_back(make_tuple(-L - 1, -L - 1, L + 1, -L - 1));
	vec.push_back(make_tuple(-L - 1, -L - 1, -L - 1, L + 1));
	
	for (int a = 0; a <= N; a++) {
		if (a == N) {	//���� N���� ȸ���� �ϰ� ���� �ʾҴٸ� �� �̻� ȸ������ ���� ������ ����
			if (direction == 0) {
				x2 = x1 + 1000000000;
				y2 = y1;
			}
			else if (direction == 1) {
				x2 = x1;
				y2 = y1 - 1000000000;
			}
			else if (direction == 2) {
				x2 = x1 - 1000000000;
				y2 = y1;
			}
			else {
				x2 = x1;
				y2 = y1 + 1000000000;
			}
		}
		else {	//���� ������ �� �� ȸ���� �ǽ��ϴ��� start�� end��ǥ ����
			if (direction == 0) {
				x2 = x1 + rotate[a];
				y2 = y1;
			}
			else if (direction == 1) {
				x2 = x1;
				y2 = y1 - rotate[a];
			}
			else if (direction == 2) {
				x2 = x1 - rotate[a];
				y2 = y1;
			}
			else {
				x2 = x1;
				y2 = y1 + rotate[a];
			}
		}

		min = 1000000000;
		for (int b = 0; b < vec.size(); b++) {	//���� ������ ��ο� start~end���̿� ��ġ�� �κ��� �ִ��� �Ǵ�
			if (direction == 0) {
				if (get<0>(vec[b]) == get<2>(vec[b]) && get<1>(vec[b]) <= y2 && get<3>(vec[b]) >= y2 && get<0>(vec[b]) <= x2 && get<0>(vec[b]) > x1) {
					if (get<0>(vec[b]) - x1 < min)	min = get<0>(vec[b]) - x1;
				}
				else if (get<1>(vec[b]) == y2 && get<1>(vec[b]) == get<3>(vec[b]) && get<0>(vec[b]) <= x2 && get<0>(vec[b]) > x1) {
					if (get<0>(vec[b]) - x1 < min)	min = get<0>(vec[b]) - x1;
				}
			}
			else if (direction == 1) {
				if (get<1>(vec[b]) == get<3>(vec[b]) && get<0>(vec[b]) <= x2 && get<2>(vec[b]) >= x2 && get<1>(vec[b]) >= y2 && get<1>(vec[b]) < y1) {
					if (y1 - get<1>(vec[b]) < min)	min = y1 - get<1>(vec[b]);
				}
				else if (get<0>(vec[b]) == x2 && get<0>(vec[b]) == get<2>(vec[b]) && get<3>(vec[b]) >= y2 && get<3>(vec[b]) < y1) {
					if (y1 - get<3>(vec[b]) < min)	min = y1 - get<3>(vec[b]);
				}
			}
			else if (direction == 2) {
				if (get<0>(vec[b]) == get<2>(vec[b]) && get<1>(vec[b]) <= y2 && get<3>(vec[b]) >= y2 && get<0>(vec[b]) >= x2 && get<0>(vec[b]) < x1) {
					if (x1 - get<0>(vec[b]) < min)	min = x1 - get<0>(vec[b]);
				}
				else if (get<1>(vec[b]) == y2 && get<1>(vec[b]) == get<3>(vec[b]) && get<2>(vec[b]) >= x2 && get<2>(vec[b]) < x1) {
					if (x1 - get<2>(vec[b]) < min)	min = x1 - get<2>(vec[b]);
				}
			}
			else {
				if (get<1>(vec[b]) == get<3>(vec[b]) && get<0>(vec[b]) <= x2 && get<2>(vec[b]) >= x2 && get<1>(vec[b]) <= y2 && get<1>(vec[b]) > y1) {
					if (get<1>(vec[b]) - y1 < min)	min = get<1>(vec[b]) - y1;
				}
				else if (get<0>(vec[b]) == x2 && get<0>(vec[b]) == get<2>(vec[b]) && get<1>(vec[b]) <= y2 && get<1>(vec[b]) > y1) {
					if (get<1>(vec[b]) - y1 < min)	min = get<1>(vec[b]) - y1;
				}
			}
		}

		if (min < 1000000000) {	//���� ���� �� �Ǵ� ������ �۰� ��Ƽ� ���� ��� ����
			answer += min;
			break;
		}
		else {	//���� ����ִ� ��� ȸ���� �ǽ��ϰ� ������ ��θ� vec�� �߰�
			answer += rotate[a];
			if (direction == 0) {
				vec.push_back(make_tuple(x1, y1, x2, y2));
				if (dir[a] == 'L')	direction = 3;
				else	direction = 1;
			}
			else if (direction == 1) {
				vec.push_back(make_tuple(x2, y2, x1, y1));
				if (dir[a] == 'L')	direction = 0;
				else	direction = 2;
			}
			else if (direction == 2) {
				vec.push_back(make_tuple(x2, y2, x1, y1));
				if (dir[a] == 'L')	direction = 1;
				else	direction = 3;
			}
			else {
				vec.push_back(make_tuple(x1, y1, x2, y2));
				if (dir[a] == 'L')	direction = 2;
				else	direction = 0;
			}
			x1 = x2;
			y1 = y2;
		}
	}

	cout << answer << endl;
	return 0;
}