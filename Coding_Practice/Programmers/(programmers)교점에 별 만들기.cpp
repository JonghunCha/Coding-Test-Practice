/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/87377
단순한 완전 탐색 문제다.

x와 y좌표의 값을 구하는 방법은 문제에 제시되어 있으니 단순히 계산만 하면 된다.(여기서 int형을 넘어갈 수 있기에 long long으로 변환)

이제 좌표가 정수인 모든 교점들 중 x, y좌표의 최소 최대값을 구한다.

x좌표의 최소 최대의 차는 answer의 가로 길이가 되고, y좌표의 최소 최대의 차는 answer의 세로 길이가 된다.

마지막으로 교점의 좌표와 y의 최대값, x의 최소값을 이용하여 answer에 별을 넣어주면 된다.
*/
#include <string>
#include <vector>
#include <utility>
using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<int, int>> stars;
    long long x1, y1, div;
    //서로 다른 두 직선간에 좌표가 둘 다 정수인 교점이 있다면 stars에 추가
    for (int a = 0; a < line.size(); a++) {
        for (int b = a + 1; b < line.size(); b++) {
            x1 = ((long long)line[a][1] * (long long)line[b][2]) - ((long long)line[a][2] * (long long)line[b][1]);
            y1 = ((long long)line[a][2] * (long long)line[b][0]) - ((long long)line[a][0] * (long long)line[b][2]);
            div = ((long long)line[a][0] * (long long)line[b][1]) - ((long long)line[a][1] * (long long)line[b][0]);
            //두 직선이 하나의 교점을 가지고, x와 y좌표가 정수인 경우
            if (div != 0 && x1 % div == 0 && y1 % div == 0) {   
                stars.push_back(make_pair(x1 / div, y1 / div));
            }
        }
    }
   
    int x_max = stars[0].first, x_min = stars[0].first, y_max = stars[0].second, y_min = stars[0].second;
    int width, height;
    string temp;
    //x의 최대 최소값, y의 최대 최소값을 통해 width와 height를 계산
    for (int a = 1; a < stars.size(); a++) {
        if (stars[a].first < x_min)  x_min = stars[a].first;
        if (stars[a].first > x_max)  x_max = stars[a].first;
        if (stars[a].second < y_min) y_min = stars[a].second;
        if (stars[a].second > y_max) y_max = stars[a].second;
    }
    width = x_max - x_min + 1;
    height = y_max - y_min + 1;
    //가로 세로 길이에 따른 answer의 크기 설정
    for (long long a = 0; a < width; a++)  temp.push_back('.');
    for (long long a = 0; a < height; a++) answer.push_back(temp);
    //answer에 별의 위치 저장
    for (int a = 0; a < stars.size(); a++) {
        answer[y_max - stars[a].second][stars[a].first - x_min] = '*';
    }

    return answer;
}