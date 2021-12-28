/*
문제 링크 : https://www.acmicpc.net/problem/21610
단순 구현 문제다.

문제에서 제시한 규칙을 따라 구현만 하면 되며 크게 까다로운 부분도 없다.
*/
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int main(void) {
	int N, M, water[51][51], cloud[51][51], move_info[100][2], answer = 0;
	vector<tuple<int, int>> removing_cloud;
	removing_cloud.reserve(2500);
	int nx, ny;
	//입력값 저장
	cin >> N; cin >> M;
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			cin >> water[a][b];
			cloud[a][b] = 0;
		}
	}
	for (int a = 0; a < M; a++) {
		cin >> move_info[a][0];
		cin >> move_info[a][1];
	}
	//초기 구름 생성 및 M번의 이동 실시
	cloud[N][1] = 1;
	cloud[N][2] = 1;
	cloud[N - 1][1] = 1;
	cloud[N - 1][2] = 1;
	for (int a = 0; a < M; a++) {
		//1단계(구름 이동) + 2단계(이동한 바구니에 비 내림)
		for (int b = 1; b <= N; b++) {
			for (int c = 1; c <= N; c++) {
				if (cloud[b][c] == 1) {
					nx = b;
					ny = c;
					for (int d = 1; d <= move_info[a][1]; d++) {
						nx += dx[move_info[a][0]];
						ny += dy[move_info[a][0]];
						if (nx < 1)	nx += N;
						else if (nx > N)	nx -= N;
						if (ny < 1) ny += N;
						else if (ny > N)	ny -= N;
					}
					water[nx][ny] += 1;	
					//5단계에서 직전에 구름이 비를 내린 곳에서는 구름이 생성되지 못한다는 것을 표시하기 위해 removing_cloud에 비가 내린 지역의 좌표 추가
					removing_cloud.emplace_back(make_tuple(nx, ny));	
				}
			}
		}
		//3단계(모든 구름 사라짐)
		for (int b = 1; b <= N; b++) {
			for (int c = 1; c <= N; c++) {
				cloud[b][c] = 0;
			}
		}
		//4단계(2단계에서 물이 증가한 칸에 물복사버그 마법 시전
		for (vector<tuple<int, int>>::iterator itr = removing_cloud.begin(); itr < removing_cloud.end(); itr++) {
			for (int b = 1; b <= 8; b++) {
				if (b % 2 == 0) {
					nx = get<0>(*itr) + dx[b];
					ny = get<1>(*itr) + dy[b];
					if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && water[nx][ny] > 0)	water[get<0>(*itr)][get<1>(*itr)]++;
				}
			}
		}
		//5단계(3단계에서 사라진 구름이 아니고 물의 양이 2이상인 곳에 구름 생성하고 물의 양 2감소)
		for (int b = removing_cloud.size() - 1; b >= 0; b--) {
			cloud[get<0>(removing_cloud[b])][get<1>(removing_cloud[b])] = -1;
			removing_cloud.erase(removing_cloud.begin() + b);
		}
		for (int b = 1; b <= N; b++) {
			for (int c = 1; c <= N; c++) {
				if (cloud[b][c] == 0 && water[b][c] >= 2) {
					cloud[b][c] = 1;
					water[b][c] -= 2;
				}
			}
		}
	}

	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			answer += water[a][b];
		}
	}
	cout << answer;

	return 0;
}