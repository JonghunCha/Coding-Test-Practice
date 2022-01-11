/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/1832
DP로 해결할 수 있는 쉬운 문제다.
*/
#include <vector>

using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0, dp[500][500], x, y, up, left;
    //dp테이블 초기화
    for (int a = 0; a < m; a++) {
        for (int b = 0; b < n; b++) {
            if (city_map[a][b] == 1) dp[a][b] = 0;
            dp[a][b] = -1;
        }
    }
    dp[0][0] = 1;
    //bottom-up방식으로 dp 테이블 채우기
    for (int a = 0; a < m; a++) {
        for (int b = 0; b < n; b++) {
            if (dp[a][b] == -1) {   //아직 정해지지 않은 경우만 계산(시작지점과 통행 불가 지점은 계산 할 필요 없음)
                up = 0;
                left = 0;
                //위에서 내려오는 경우
                x = a - 1;
                while (x >= 0) {
                    if (city_map[x][b] == 2) {  //표지판이 있는 경우 더 위쪽의 dp값 가져온다
                        x--;
                    }
                    else if (city_map[x][b] == 1) { //통행불가 지역인 경우 해당 경로로 올 수 있는 길이 없음
                        break;
                    }
                    else {  //통행가능 지역이면 해당 지역의 dp값이 현재 지역으로 위에서 들어오는 경우의 수
                        up = dp[x][b];
                        break;
                    }
                }
                //왼쪽에서 오는 경우(위에서 내려오는 경우와 다를 것 없음)
                y = b - 1;
                while (y >= 0) {
                    if (city_map[a][y] == 2) {
                        y--;
                    }
                    else if (city_map[a][y] == 1) {
                        break;
                    }
                    else {
                        left = dp[a][y];
                        break;
                    }
                }

                dp[a][b] = (up + left) % MOD;
            }
        }
    }

    return dp[m - 1][n - 1];
}