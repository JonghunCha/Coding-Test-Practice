/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/1829#
DFS로 해결할 수 있는 문제다.

전형적인 DFS문제로 같은 영역을 탐색하며 영역의 범위와 갯수를 파악하면 된다.
*/
#include <vector>
using namespace std;

int area_size, visited[100][100];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void search_near(int m, int n, vector<vector<int>>& picture, int& area_num, int x, int y);

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    //방문 여부를 나타내는 visited 초기화
    for (int a = 0; a < m; a++) {
        for (int b = 0; b < n; b++) {
            visited[a][b] = 0;
        }
    }
    //새로운 영역을 발견하면 search_near호출하고 number_of_area를 1 더해주며, 가장 큰 영역의 넓이를 갱신
    for (int a = 0; a < m; a++) {
        for (int b = 0; b < n; b++) {
            if (picture[a][b] != 0 && visited[a][b] == 0) {
                area_size = 0;
                search_near(m, n, picture, ++number_of_area, a, b);
                if (area_size > max_size_of_one_area)    max_size_of_one_area = area_size;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}

void search_near(int m, int n, vector<vector<int>>& picture, int& area_num, int x, int y) {
    int nx, ny;

    area_size++;    //영역의 크기 1 더한다
    visited[x][y] = 1;  //방문하였음을 표시
    for (int a = 0; a < 4; a++) {   //(x,y)의 상하좌우에 대해 같은 영역이면 search_near호출
        nx = x + dx[a];
        ny = y + dy[a];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny] == 0 && picture[nx][ny] == picture[x][y]) {
            search_near(m, n, picture, area_num, nx, ny);
        }
    }
}