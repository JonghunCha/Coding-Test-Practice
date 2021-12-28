/*
���� ��ũ : https://programmers.co.kr/learn/courses/30/lessons/87694
�ܼ� ���������� �����Ѵ�.

���̵��� �����ϴ�. ������ ���ǿ� ���ϸ� ĳ���Ͱ� �̵� ������ ������ �־��� �簢������ �𼭸� Ȥ�� �簢���鳢�� ������ ���������̴�.

���� ���� �ش��ϴ� �ڳ� ������ cross��� ���Ϳ� �����Ͽ���. �� ��, �ڳ��� ��翡 ���� ĳ������ �̵������� �޶����� ������ �ڳ��� ��絵 ���� �����Ѵ�.
(���� ���ʾƷ��� ���� �ڳʶ�� 0�� ���� ����, 1�� ������ ����, 2�� ���� �Ʒ���, 3�� ������ �Ʒ��� ���� �ڳʸ��)

�׷� ���� ���� ĳ������ ��ġ���� ������ 2���� �̵� ���⿡ ���� ���������� �Ÿ��� ����ϰ� �� ª�� ���� �����.
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    vector<vector<int>> cross;
    //��� �簢���� �𼭸� ��ǥ �� �ڳ� ����� cross�� ����
    for (int a = 0; a < rectangle.size(); a++) {
        cross.push_back({ rectangle[a][0], rectangle[a][1], 1 });
        cross.push_back({ rectangle[a][2], rectangle[a][1], 0 });
        cross.push_back({ rectangle[a][2], rectangle[a][3], 2 });
        cross.push_back({ rectangle[a][0], rectangle[a][3], 3 });
    }
    //���� �ٸ� �簢������ ��ġ�� ����� �ڳʸ� cross�� ����
    for (int a = 0; a < rectangle.size(); a++) {
        for (int b = a + 1; b < rectangle.size(); b++) {
            //���� ��ĥ ���
            if (rectangle[b][1] < rectangle[a][3] && rectangle[b][3] > rectangle[a][3]) {
                if (rectangle[b][0] > rectangle[a][0] && rectangle[b][0] < rectangle[a][2]) {
                    cross.push_back({ rectangle[b][0], rectangle[a][3], 0 });
                }
                if (rectangle[b][2] > rectangle[a][0] && rectangle[b][2] < rectangle[a][2]) {
                    cross.push_back({ rectangle[b][2], rectangle[a][3], 1 });
                }
            }
            //���������� ��ĥ ���
            if (rectangle[b][0] < rectangle[a][2] && rectangle[b][2] > rectangle[a][2]) {
                if (rectangle[b][1] > rectangle[a][1] && rectangle[b][1] < rectangle[a][3]) {
                    cross.push_back({ rectangle[a][2], rectangle[b][1], 3 });
                }
                if (rectangle[b][3] > rectangle[a][1] && rectangle[b][3] < rectangle[a][3]) {
                    cross.push_back({ rectangle[a][2], rectangle[b][3], 1 });
                }
            }
            //�Ʒ��� ��ĥ ���
            if (rectangle[b][1] < rectangle[a][1] && rectangle[b][3] > rectangle[a][1]) {
                if (rectangle[b][0] > rectangle[a][0] && rectangle[b][0] < rectangle[a][2]) {
                    cross.push_back({ rectangle[b][0], rectangle[a][1], 2 });
                }
                if (rectangle[b][2] > rectangle[a][0] && rectangle[b][2] < rectangle[a][2]) {
                    cross.push_back({ rectangle[b][2], rectangle[a][1], 3 });
                }
            }
            //�������� ��ĥ ���
            if (rectangle[b][2] > rectangle[a][0] && rectangle[b][0] < rectangle[a][0]) {
                if (rectangle[b][1] > rectangle[a][1] && rectangle[b][1] < rectangle[a][3]) {
                    cross.push_back({ rectangle[a][0], rectangle[b][1], 2 });
                }
                if (rectangle[b][3] > rectangle[a][1] && rectangle[b][3] < rectangle[a][3]) {
                    cross.push_back({ rectangle[a][0], rectangle[b][3], 0 });
                }
            }
        }
    }

    int temp, answer = 500, dir, direction[2], nx, ny;
    bool is_corner = false;
    //���� ĳ������ ���� ������ �ڳ� ������ ��� �ڳ� ��翡 ���� ������ ���Ѵ�(0->����, 1->����, 2->����, 3->�������� �̵��� �ǹ�)
    for (int a = 0; a < cross.size(); a++) {
        if (characterX == cross[a][0] && characterY == cross[a][1]) {   
            if (cross[a][2] == 0) {
                direction[0] = 3;
                direction[1] = 0;
            }
            else if (cross[a][2] == 1) {
                direction[0] = 0;
                direction[1] = 1;
            }
            else if (cross[a][2] == 2) {
                direction[0] = 3;
                direction[1] = 2;
            }
            else {
                direction[0] = 2;
                direction[1] = 1;
            }
            is_corner = true;
            break;
        }
    }
    //ĳ������ ���� ������ �ڳʰ� �ƴ� ���� ������ ���
    if (!is_corner) {
        for (int a = 0; a < rectangle.size(); a++) {
            if ((characterX == rectangle[a][0] || characterX == rectangle[a][2]) && characterY <= rectangle[a][3] && characterY >= rectangle[a][1]) {
                direction[0] = 0;
                direction[1] = 2;
                break;
            }
            else if ((characterY == rectangle[a][1] || characterY == rectangle[a][3]) && characterX <= rectangle[a][2] && characterX >= rectangle[a][0]) {
                direction[0] = 3;
                direction[1] = 1;
                break;
            }
        }
    }
    //�� ���� ���⿡ ���� �ɸ��� �Ÿ��� ����ϰ� ���� ���� answer�� ����
    for (int two_dir = 0; two_dir < 2; two_dir++) {
        temp = 0;
        nx = characterX;
        ny = characterY;
        dir = direction[two_dir];
        while (nx != itemX || ny != itemY) {
            temp++;
            nx += dx[dir];
            ny += dy[dir];
            for (int a = 0; a < cross.size(); a++) {
                if (nx == cross[a][0] && ny == cross[a][1]) {
                    if (cross[a][2] == 0 && dir == 2)  dir = 3;
                    else if (cross[a][2] == 0 && dir == 1)    dir = 0;
                    else if (cross[a][2] == 1 && dir == 2)    dir = 1;
                    else if (cross[a][2] == 1 && dir == 3)    dir = 0;
                    else if (cross[a][2] == 2 && dir == 1)    dir = 2;
                    else if (cross[a][2] == 2 && dir == 0)    dir = 3;
                    else if (cross[a][2] == 3 && dir == 0)    dir = 1;
                    else    dir = 2;
                }
            }
        }

        if (temp < answer)   answer = temp;
    }

    return answer;
}