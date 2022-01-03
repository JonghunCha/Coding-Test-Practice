/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/1844
BFS�� �ذ��� �� �ִ� ������.

���ؾ� �ϴ� ���� �ִ� �Ÿ��̴�.

���� BFS�� ���� �̵� �Ÿ��� 1�� �÷������� �������� �����ϴ� ��� �̵��� ĭ�� ��ȯ�ϸ� �ȴ�.
*/
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int solution(vector<vector<int>> maps)
{
    int height = maps.size(), width = maps[0].size(), x, y, nx, ny, count;
    bool visited[100][100];
    queue<tuple<int, int, int>> q;
    //�湮 ���θ� ��Ÿ���� ���� �ʱ�ȭ
    for (int a = 0; a < height; a++) {
        for (int b = 0; b < width; b++) {
            visited[a][b] = false;
        }
    }
    //���� ���� ť�� �ֱ�
    visited[0][0] = true;
    q.push(make_tuple(0, 0, 1));
    //�� �̻� �̵��� ������ ���� ������ �ݺ�
    while (!q.empty()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        count = get<2>(q.front());
        q.pop();
        //���� �������� ������ ��� ���� ��ȯ
        if (x == height - 1 && y == width - 1)   return count;
        //������ 4���⿡ ���� �̵��� �� �ִ� �����̸� ť�� �ִ´�
        for (int a = 0; a < 4; a++) {
            nx = x + dx[a];
            ny = y + dy[a];
            if (nx >= 0 && nx < height && ny >= 0 && ny < width && visited[nx][ny] == false && maps[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push(make_tuple(nx, ny, count + 1));
            }
        }
    }

    return -1;
}