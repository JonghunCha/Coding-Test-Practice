/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/1832
DP�� �ذ��� �� �ִ� ���� ������.
*/
#include <vector>

using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0, dp[500][500], x, y, up, left;
    //dp���̺� �ʱ�ȭ
    for (int a = 0; a < m; a++) {
        for (int b = 0; b < n; b++) {
            if (city_map[a][b] == 1) dp[a][b] = 0;
            dp[a][b] = -1;
        }
    }
    dp[0][0] = 1;
    //bottom-up������� dp ���̺� ä���
    for (int a = 0; a < m; a++) {
        for (int b = 0; b < n; b++) {
            if (dp[a][b] == -1) {   //���� �������� ���� ��츸 ���(���������� ���� �Ұ� ������ ��� �� �ʿ� ����)
                up = 0;
                left = 0;
                //������ �������� ���
                x = a - 1;
                while (x >= 0) {
                    if (city_map[x][b] == 2) {  //ǥ������ �ִ� ��� �� ������ dp�� �����´�
                        x--;
                    }
                    else if (city_map[x][b] == 1) { //����Ұ� ������ ��� �ش� ��η� �� �� �ִ� ���� ����
                        break;
                    }
                    else {  //���డ�� �����̸� �ش� ������ dp���� ���� �������� ������ ������ ����� ��
                        up = dp[x][b];
                        break;
                    }
                }
                //���ʿ��� ���� ���(������ �������� ���� �ٸ� �� ����)
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