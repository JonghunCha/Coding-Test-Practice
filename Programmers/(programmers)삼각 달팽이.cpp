/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/68645
2차원 배열에 달팽이 채우기를 진행한 후 answer를 구하면 쉽게 해결할 수 있다.

삼각형을 채울 때 방향은 총 3가지가 있으며, 각 방향 전환마다 진행해야하는 길이의 수가 1씩 줄어든다.

예를 들어 n이 4일 때 첫 4번은 아래로 이동, 그 다음 3번은 오른쪽으로 이동, 그 다음 2번은 위로, 그 다음 1번은 아래로 이동한다.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int triangle[1001][1001], index = 1, total = (n * (n + 1)) / 2;
    int x = 0, y = 1, direction = 1, length = n;
   
    while (index <= total) {
        for (int a = 1; a <= length; a++) { //length만큼 진행
            if (direction == 1) {   //아래로 이동하는 경우
                x++;
            }
            else if (direction == 2) {  //오른쪽으로 이동하는 경우
                y++;
            }
            else {  //위로 이동하는 경우
                x--;
                y--;
            }
            triangle[x][y] = index++;
        }
        //방향 전환
        if (direction == 1)  direction = 2;
        else if (direction == 2) direction = 3;
        else    direction = 1;
        length--;
    }
    //2차원 배열의 값을 answer에 옮겨준다
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= a; b++) {
            answer.push_back(triangle[a][b]);
        }
    }

    return answer;
}