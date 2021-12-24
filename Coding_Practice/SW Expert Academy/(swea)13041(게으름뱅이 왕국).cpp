/*
문제 링크 : https://swexpertacademy.com/main/main.do
정렬로 해결해야하는 문제다.

해결 방법은 간단하다. 정답을 도출하기 위해선 설득하는데 가장 적은 시간을 필요로하는 사람부터 설득을 해야하며, 해당 사람이 고른 일을 고른 사람이 2명 이상이어야 한다.
(만약 설득 시간은 짧지만 해당 일을 선택한 사람이 그 사람 혼자라면 설득을 해봤자 빈 일자리의 갯수는 줄어들지 않기 때문)

또한 int형 범위를 넘어갈 수 있기에 정답은 long long으로 출력하여야 한다.

!!이 문제의 경우 그냥 cin으로 입력을 받으면 시간 초과가 났다. 따라서
ios::sync_with_stdio(false);
cin.tie(NULL);
위 두 코드를 추가하였다.
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
	long long T, N, K, need_to_change, answer, picked, time;	//need_to_change는 바꿔야 할 사람의 수를 의미

	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		//입력값 저장 및 변수 초기화
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
		//벡터에 A와 B를 묶은 상태로 저장
		for (int a = 0; a < N; a++)	AB.push_back(make_tuple(A[a], B[a]));
		//벡터의 요소를 B가 오름차순이 되도록 정렬
		sort(AB.begin(), AB.end(), compare);

		answer = 0;
		for (int a = 0; a < N; a++) {
			if (need_to_change == 0)	break;	//더 이상 바꿀 필요가 없으면 종료
			picked = get<0>(AB[a]);	//기존에 고른 일
			time = get<1>(AB[a]);	//설득하는데 걸리는 시간
			if (peoplenum[picked] > 1) {	//기존에 고른 일을 고른 사람이 2명 이상일 경우 설득
				peoplenum[picked]--;
				need_to_change--;
				answer += time;
			}
		}
		cout << '#' << test_case << ' ' << answer << endl;
	}
	return 0;
}
//B가 오름차순이 되도록 정렬
int compare(tuple<long long, long long> arg1, tuple<long long, long long> arg2) {
	long long b1 = get<1>(arg1), b2 = get<1>(arg2);
	return b1 < b2;
}