/*
문제 링크 : https://www.acmicpc.net/problem/20056
단순 구현 시뮬레이션 문제다.

문제의 조건에 2개의 단계가 있다.

1. 모든 파이어볼이 각자의 방향으로 이동하는 것
2. 모든 파이어볼이 이동한 후 2개 이상의 파이어볼이 있는 칸에서 파이어볼을 4개로 나누는 것

모든 파이어볼이 이동한 후 2개 이상의 파이어볼이 있는 것을 처리해야 하기에 N * N 격자 위에 파이어볼의 상태를 나타내는 변수를 2개 사용하였다.
*/
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main(void) {
	int N, M, K, R, C, mm, ss, dd, mass_sum, speed_sum, fireball_num, answer = 0;
	bool direction_odd, direction_even;
	vector<tuple<int, int, int>> msd[51][51];		//첫 번째 단계를 실행할 때 사용하는 변수
	vector<tuple<int, int, int>> msd_copy[51][51];	//첫 번째 단계를 실행한 결과로, 두 번째 단계를 실행하는데 사용하는 변수
	//입력값 저장
	cin >> N; cin >> M; cin >> K;
	for (int a = 0; a < M; a++) {
		cin >> R;
		cin >> C;
		cin >> mm;
		cin >> ss;
		cin >> dd;
		msd[R][C].emplace_back(make_tuple(mm, ss, dd));
	}

	for (int a = 0; a < K; a++) {
		//모든 파이어볼 이동
		for (int b = 1; b <= N; b++) {
			for (int c = 1; c <= N; c++) {
				//파이어 볼이 있는 곳이라면 이동 시작
				while (msd[b][c].size() > 0) {
					mm = get<0>(msd[b][c][msd[b][c].size() - 1]);
					ss = get<1>(msd[b][c][msd[b][c].size() - 1]);
					dd = get<2>(msd[b][c][msd[b][c].size() - 1]);
					msd[b][c].erase(msd[b][c].begin() + msd[b][c].size() - 1);
					//이동한 후 파이어볼의 좌표 계산
					R = b;
					C = c;
					for (int d = 1; d <= ss; d++) {
						R += dx[dd];
						C += dy[dd];
						if (R < 1)	R = N;
						else if (R > N)	R = 1;
						if (C < 1)	C = N;
						else if (C > N)	C = 1;
					}
					//msd_copy변수에 이동한 결과 저장
					msd_copy[R][C].emplace_back(make_tuple(mm, ss, dd));
				}
			}
		}
		//이동이 끝난 후 2개 이상의 파이어볼이 있는 칸 처리
		for (int b = 1; b <= N; b++) {
			for (int c = 1; c <= N; c++) {
				//2개 이상의 파이어볼이 있는 경우 2번 조건을 수행
				if (msd_copy[b][c].size() >= 2) {
					direction_odd = false;		//홀수 방향 파이어볼이 있는 경우 true로 설정
					direction_even = false;		//짝수 방향 파이어볼이 있는 경우 true로 설정
					mass_sum = 0;
					speed_sum = 0;
					fireball_num = 0;
					while (msd_copy[b][c].size() > 0) {
						mm = get<0>(msd_copy[b][c][msd_copy[b][c].size() - 1]);
						ss = get<1>(msd_copy[b][c][msd_copy[b][c].size() - 1]);
						dd = get<2>(msd_copy[b][c][msd_copy[b][c].size() - 1]);
						msd_copy[b][c].erase(msd_copy[b][c].begin() + msd_copy[b][c].size() - 1);

						mass_sum += mm;	
						speed_sum += ss;
						fireball_num++;
						if (dd % 2 == 0)	direction_even = true;
						else	direction_odd = true;
					}
					
					if (fireball_num != 0) {
						for (int d = 1; d <= 4; d++) {
							//홀수 짝수 모두 있는 경우 방향은 1, 3, 5, 7
							if (direction_odd == direction_even)	dd = 2 * d - 1;
							//홀수 혹은 짝수만 있는 경우 방향은 0, 2, 4, 6
							else	dd = 2 * d - 2;
							mm = mass_sum / 5;
							if (mm == 0)	break;
							ss = speed_sum / fireball_num;
							//파이어볼을 4개로 나눈 결과를 msd에 저장
							msd[b][c].emplace_back(make_tuple(mm, ss, dd));
						}
					}
				}
				//파이어볼이 한 개인 경우엔 나눌 필요 없이 msd로 저장
				else if (msd_copy[b][c].size() == 1) {
					mm = get<0>(msd_copy[b][c][msd_copy[b][c].size() - 1]);
					ss = get<1>(msd_copy[b][c][msd_copy[b][c].size() - 1]);
					dd = get<2>(msd_copy[b][c][msd_copy[b][c].size() - 1]);
					msd_copy[b][c].erase(msd_copy[b][c].begin() + msd_copy[b][c].size() - 1);
					msd[b][c].emplace_back(make_tuple(mm, ss, dd));
				}
			}
		}
	}
	//전체 질량 구하기
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			while (msd[a][b].size() > 0) {
				mm = get<0>(msd[a][b][msd[a][b].size() - 1]);
				msd[a][b].erase(msd[a][b].begin() + msd[a][b].size() - 1);
				answer += mm;
			}
		}
	}
	cout << answer;

	return 0;
}