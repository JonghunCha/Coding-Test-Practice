/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/1833#
정렬을 하면 해결법이 쉽게 떠오르는 문제다.

(a, b)쐐기와 (a + 2, b + 2)가 가능한 텐트의 쐐기라고 가정하자.

이 경우 x좌표가 a + 2보다 큰 경우 y 좌표는 b + 2보다 크면 안된다.((a + 2, b + 2)가 내부에 들어가기 때문)

이 점을 이용하여 2중 포문을 통해 탐색하며 y좌표에 따라 가능한 쌍인지 아닌지 판단할 수 있다.
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

bool compare(vector<int> v1, vector<int> v2);

int solution(int n, vector<vector<int>> data) {
    int answer = 0, line_above, line_below, line_above_temp, line_below_temp;

    sort(data.begin(), data.end());

    for (int a = 0; a < (n - 1); a++) {
        line_above = INT_MAX;
        line_below = 0;
        line_above_temp = INT_MAX;
        line_below_temp = 0;
        for (int b = a + 1; b < n; b++) {
            if (data[b][0] == data[a][0]) { //x좌표가 같은 경우 무시
                continue;
            }
            
            if (data[b][1] > data[a][1] && data[b][1] <= line_above) {  //b번 쐐기가 a번 쐐기보다 위에 있고 텐트를 설치할 수 있는 경우
                answer++;
                line_above_temp = min(line_above_temp, data[b][1]);
            }
            else if (data[b][1] < data[a][1] && data[b][1] >= line_below) { //b번 쐐기가 a번 쐐기보다 아래에 있고 텐트를 설치할 수 있는 경우
                answer++;
                line_below_temp = max(line_below_temp, data[b][1]);
            }
            //만약 다음 쐐기의 x좌표가 같은 경우 line_above 및 line_below를 갱신하면 안된다
            //x좌표가 같은 경우 텐트를 설치해도 경계선에 쐐기가 들어가는 경우이기에 문제의 텐트 설치 조건에 부합하기 때문
            if (b + 1 < n && data[b + 1][0] > data[b][0]) {
                line_above = line_above_temp;
                line_below = line_below_temp;
            }
        }
    }

    return answer;
}