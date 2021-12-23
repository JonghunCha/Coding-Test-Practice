/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/87694
단순 구현문제이긴 하나 약간 코드가 좀 복잡해진다.

아이디어는 간단하다. 문제의 조건에 의하면 캐릭터가 이동 가능한 지역은 주어진 사각형들의 모서리 혹은 사각형들끼리 만나는 교차지점이다.

따라서 위에 해당하는 코너 지역을 cross라는 벡터에 저장하였다. 이 때, 코너의 모양에 따라 캐릭터의 이동방향이 달라지기 때문에 코너의 모양도 같이 저장한다.
(ㄱ이 왼쪽아래로 열린 코너라면 0은 왼쪽 위로, 1은 오른쪽 위로, 2는 왼쪽 아래로, 3은 오른쪽 아래로 열린 코너모양)

그런 다음 현재 캐릭터의 위치에서 시작해 2가지 이동 방향에 대해 목적지까지 거리를 계산하고 더 짧은 것을 골랐다.
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    vector<vector<int>> cross;
    //모든 사각형의 모서리 좌표 및 코너 모양을 cross에 저장
    for (int a = 0; a < rectangle.size(); a++) {
        cross.push_back({ rectangle[a][0], rectangle[a][1], 1 });
        cross.push_back({ rectangle[a][2], rectangle[a][1], 0 });
        cross.push_back({ rectangle[a][2], rectangle[a][3], 2 });
        cross.push_back({ rectangle[a][0], rectangle[a][3], 3 });
    }
    //서로 다른 사각형끼리 겹치며 생기는 코너를 cross에 저장
    for (int a = 0; a < rectangle.size(); a++) {
        for (int b = a + 1; b < rectangle.size(); b++) {
            //위로 겹칠 경우
            if (rectangle[b][1] < rectangle[a][3] && rectangle[b][3] > rectangle[a][3]) {
                if (rectangle[b][0] > rectangle[a][0] && rectangle[b][0] < rectangle[a][2]) {
                    cross.push_back({ rectangle[b][0], rectangle[a][3], 0 });
                }
                if (rectangle[b][2] > rectangle[a][0] && rectangle[b][2] < rectangle[a][2]) {
                    cross.push_back({ rectangle[b][2], rectangle[a][3], 1 });
                }
            }
            //오른쪽으로 겹칠 경우
            if (rectangle[b][0] < rectangle[a][2] && rectangle[b][2] > rectangle[a][2]) {
                if (rectangle[b][1] > rectangle[a][1] && rectangle[b][1] < rectangle[a][3]) {
                    cross.push_back({ rectangle[a][2], rectangle[b][1], 3 });
                }
                if (rectangle[b][3] > rectangle[a][1] && rectangle[b][3] < rectangle[a][3]) {
                    cross.push_back({ rectangle[a][2], rectangle[b][3], 1 });
                }
            }
            //아래로 겹칠 경우
            if (rectangle[b][1] < rectangle[a][1] && rectangle[b][3] > rectangle[a][1]) {
                if (rectangle[b][0] > rectangle[a][0] && rectangle[b][0] < rectangle[a][2]) {
                    cross.push_back({ rectangle[b][0], rectangle[a][1], 2 });
                }
                if (rectangle[b][2] > rectangle[a][0] && rectangle[b][2] < rectangle[a][2]) {
                    cross.push_back({ rectangle[b][2], rectangle[a][1], 3 });
                }
            }
            //왼쪽으로 겹칠 경우
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
    //만약 캐릭터의 시작 지점이 코너 구간인 경우 코너 모양에 따라 방향을 정한다(0->북쪽, 1->동쪽, 2->남쪽, 3->서쪽으로 이동을 의미)
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
    //캐릭터의 시작 지점이 코너가 아닌 직선 구역인 경우
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
    //두 개의 방향에 대해 걸리는 거리를 계산하고 작은 값을 answer에 저장
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