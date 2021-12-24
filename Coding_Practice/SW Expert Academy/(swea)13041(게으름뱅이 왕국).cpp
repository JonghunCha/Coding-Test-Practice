/*
���� ��ũ : https://swexpertacademy.com/main/main.do
���ķ� �ذ��ؾ��ϴ� ������.

�ذ� ����� �����ϴ�. ������ �����ϱ� ���ؼ� �����ϴµ� ���� ���� �ð��� �ʿ���ϴ� ������� ������ �ؾ��ϸ�, �ش� ����� �� ���� �� ����� 2�� �̻��̾�� �Ѵ�.
(���� ���� �ð��� ª���� �ش� ���� ������ ����� �� ��� ȥ�ڶ�� ������ �غ��� �� ���ڸ��� ������ �پ���� �ʱ� ����)

���� int�� ������ �Ѿ �� �ֱ⿡ ������ long long���� ����Ͽ��� �Ѵ�.

!!�� ������ ��� �׳� cin���� �Է��� ������ �ð� �ʰ��� ����. ����
ios::sync_with_stdio(false);
cin.tie(NULL);
�� �� �ڵ带 �߰��Ͽ���.
*/
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

long long A[100000], B[100000], peoplenum[100001];
vector<tuple<long long, long long>> AB;

int compare(tuple<long long, long long>, tuple<long long, long long>);

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long T, N, K, need_to_change, answer, picked, time;	//need_to_change�� �ٲ�� �� ����� ���� �ǹ�

	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//�Է°� ���� �� ���� �ʱ�ȭ
		cin >> N >> K;
		for (int a = 1; a <= K; a++)	peoplenum[a] = 0;
		AB.clear();
		need_to_change = 0;
		for (int a = 0; a < N; a++) {
			cin >> A[a];
			peoplenum[A[a]]++;
		}
		for (int a = 0; a < N; a++)	cin >> B[a];
		for (int a = 1; a <= K; a++) {
			if (peoplenum[a] == 0)	need_to_change++;
		}
		//���Ϳ� A�� B�� ���� ���·� ����
		for (int a = 0; a < N; a++)	AB.push_back(make_tuple(A[a], B[a]));
		//������ ��Ҹ� B�� ���������� �ǵ��� ����
		sort(AB.begin(), AB.end(), compare);

		answer = 0;
		for (int a = 0; a < N; a++) {
			if (need_to_change == 0)	break;	//�� �̻� �ٲ� �ʿ䰡 ������ ����
			picked = get<0>(AB[a]);	//������ �� ��
			time = get<1>(AB[a]);	//�����ϴµ� �ɸ��� �ð�
			if (peoplenum[picked] > 1) {	//������ �� ���� �� ����� 2�� �̻��� ��� ����
				peoplenum[picked]--;
				need_to_change--;
				answer += time;
			}
		}
		cout << '#' << test_case << ' ' << answer << endl;
	}
	return 0;
}
//B�� ���������� �ǵ��� ����
int compare(tuple<long long, long long> arg1, tuple<long long, long long> arg2) {
	long long b1 = get<1>(arg1), b2 = get<1>(arg2);
	return b1 < b2;
}