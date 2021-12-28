/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/86052
���� Ž���� ���� �ذ��� �� �ִ� ������.

�� ���ڿ����� 4�������� ���� �̵��� �� �ִ�.

���� �� ���ڴ� ���� ���� ���⿡ ���� ���� �̵��ϴ� ��δ� �����Ǿ� �ִ�.

�� ���� �̿��ϸ� �������� ����Ŭ�� ã�� �� �ִ�.

�� ���ڸ��� 4���� ���⿡ ���� �̵��� ���� �ִ����� ��ŷ�ϴ� ������ �ΰ�, ���� �̹� �������� ��ζ�� �ش� ��θ� ���ϴ� ����Ŭ�� ����� �Ǿ����� �� �� �ִ�.

���� ��� ������ 4���� ������ ��� ���������� �ִٸ� ��� ����Ŭ�� ã�Ҵٰ� �� �� �ִ�.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//index�� ������ ���� �� �� �� ��
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int visited[500][500][4], row = grid.size(), col = grid[0].size();
    int x, y, direction, count;
    //visited[a][b][c]�� a, b���ڿ��� c�������� ���� �̵����� �ִ����� ����
    for (int a = 0; a < row; a++) {
        for (int b = 0; b < col; b++) {
            for (int c = 0; c < 4; c++) {
                visited[a][b][c] = 0;
            }
        }
    }
    //������ ��� ���� �̵� ��θ� Ž��
    for (int a = 0; a < row; a++) {
        for (int b = 0; b < col; b++) {
            for (int c = 0; c < 4; c++) {
                if (visited[a][b][c] == 0) {    //���� ���� �������� ���� ��θ� ���ο� ����Ŭ�� �ĺ��� �� �� ����
                    count = 0;
                    x = a;
                    y = b;
                    direction = c;
                    while (visited[x][y][direction] == 0) {
                        count++;
                        visited[x][y][direction] = 1;   //���� ������ ������� ��ŷ
                        //���� ������ x, y��ǥ ���
                        x = x + dx[direction];  
                        if (x < 0)   x = row - 1;
                        if (x >= row)    x = 0;
                        if (y < 0)   y = col - 1;
                        if (y >= col)    y = 0;
                        //���� ���ڿ����� �̵����� ���
                        if (grid[x][y] == 'L') {
                            if (direction == 0)  direction = 3;
                            else    direction = direction - 1;
                        }
                        else if (grid[x][y] == 'R')  direction = (direction + 1) % 4;
                        //���� ���� ������ ��η� ���ƿ´ٸ� ����Ŭ�� �ϼ��Ǿ����� �ǹ�
                        if (x == a && y == b && direction == c) {
                            answer.push_back(count);
                            break;
                        }
                    }
                }
            }
        }
    }
    //������������ ����
    sort(answer.begin(), answer.end());

    return answer;
}