/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/49994
��ǥ ����� ũ�Ⱑ �۱⿡ ��� ��ο� ���� ���������� �ִ��� ��Ÿ���� ������ �θ� ���� �ذ��� �� �ִ�.

���� ���Ǹ� ���� ��� x, y��ǥ�� 5�� �����־���.(ex. -5, -5 -> 0, 0)
*/
#include <string>
#include <cstring>
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int visited[11][11][11][11];

int solution(string dirs) {
    int answer = 0, x = 5, y = 5, nx, ny;
    //visited�ʱ�ȭ
    memset(visited, 0, 14641);

    for (int a = 0; a < dirs.size(); a++) {
        //�� ���⿡ ���� ���� ��ǥ nx, ny ���
        if (dirs[a] == 'U') {
            nx = x + dx[0];
            ny = y + dy[0];
        }
        else if (dirs[a] == 'D') {
            nx = x + dx[1];
            ny = y + dy[1];
        }
        else if (dirs[a] == 'R') {
            nx = x + dx[2];
            ny = y + dy[2];
        }
        else {
            nx = x + dx[3];
            ny = y + dy[3];
        }
        //���� ��ȿ���� ���� ��ǥ��� ���� ��ɾ� ����
        if (nx < 0 || nx > 10 || ny < 0 || ny > 10)  continue;
        //(x, y)�� (nx, ny)������ ��θ� ������ ���� ���ٸ� answer++�ϰ�, �ش� ��θ� ������ ������ ǥ��
        if (visited[x][y][nx][ny] == 0) {
            answer++;
            visited[x][y][nx][ny] = 1;
            visited[nx][ny][x][y] = 1;
        }
        //x, y ����
        x = nx;
        y = ny;
    }

    return answer;
}