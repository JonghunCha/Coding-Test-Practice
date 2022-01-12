/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/1829#
DFS�� �ذ��� �� �ִ� ������.

�������� DFS������ ���� ������ Ž���ϸ� ������ ������ ������ �ľ��ϸ� �ȴ�.
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
    //�湮 ���θ� ��Ÿ���� visited �ʱ�ȭ
    for (int a = 0; a < m; a++) {
        for (int b = 0; b < n; b++) {
            visited[a][b] = 0;
        }
    }
    //���ο� ������ �߰��ϸ� search_nearȣ���ϰ� number_of_area�� 1 �����ָ�, ���� ū ������ ���̸� ����
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

    area_size++;    //������ ũ�� 1 ���Ѵ�
    visited[x][y] = 1;  //�湮�Ͽ����� ǥ��
    for (int a = 0; a < 4; a++) {   //(x,y)�� �����¿쿡 ���� ���� �����̸� search_nearȣ��
        nx = x + dx[a];
        ny = y + dy[a];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny] == 0 && picture[nx][ny] == picture[x][y]) {
            search_near(m, n, picture, area_num, nx, ny);
        }
    }
}