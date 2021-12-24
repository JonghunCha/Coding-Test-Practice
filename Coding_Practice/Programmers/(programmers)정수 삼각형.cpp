/*
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43105
DP로 해결할 수 있다.

각 row의 양쪽 끝은 항상 이전 row의 양쪽 끝에서만 접근할 수 있으므로 선택의 여지가 없다.

그러나 row의 양끝이 아닌 지역은 이전 row의 왼쪽 위 오른쪽 위 두 군데서 접근 가능하다.

이 경우 왼쪽 위와 오른쪽 위에 도달하는 경로중 거쳐간 숫자의 합이 더 큰 것을 고르면 된다.

아래 코드를 보면 쉽게 이해할 수 있을 것이다.
*/
#include <string>
#include <vector>
#include <utility>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0, n = triangle.size();
    //삼각형의 크기가 1인 경우 바로 반환
    if (n == 1)  return triangle[0][0];
    //위에서 그리고 왼쪽부터 해당 지점에 도달하는 경로의 최댓값 계산
    for (int a = 1; a < n; a++) {
        for (int b = 0; b <= a; b++) {
            if (b == 0)  triangle[a][b] = triangle[a - 1][b] + triangle[a][b];  //가장 왼쪽의 경우 이전 row의 왼쪽에서만 접근가능
            else if (b == a) triangle[a][b] = triangle[a - 1][b - 1] + triangle[a][b];  //가장 오른쪽의 경우 이전 row의 오른쪽에서만 접근가능
            else triangle[a][b] = max(triangle[a - 1][b - 1], triangle[a - 1][b]) + triangle[a][b]; //가운데 있는 경우
        }
    }
    //가장 큰 값 계산
    for (int a = 0; a < n; a++) {
        if (triangle[n - 1][a] > answer) answer = triangle[n - 1][a];
    }

    return answer;
}